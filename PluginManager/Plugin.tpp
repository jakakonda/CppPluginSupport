#ifndef KPL_PLUGIN_IMPL_H
#define KPL_PLUGIN_IMPL_H

#include "Plugin.h"

KPL_BEGIN_NAMESPACE

#if defined(KPL_WINDOWS)

template<typename T>
Plugin<T>::Plugin(std::string library_path, 
				  std::string entry_symbol, 
				  std::string exit_symbol)
{
	_library = nullptr;
	_target = nullptr;
	_isLoaded = false;

	_library = ::LoadLibraryA(std::string(library_path + ".dll").c_str());

	if (_library == nullptr)
		return;

	FARPROC funcEntryAddr = ::GetProcAddress(_library, entry_symbol.c_str());
	FARPROC funcExitAddr  = ::GetProcAddress(_library, exit_symbol.c_str());

	if (funcEntryAddr == nullptr || funcExitAddr == nullptr)
		return;

	instanciate_fptr = reinterpret_cast<instanciate_plugin *>(funcEntryAddr);
	deallocate_fptr  = reinterpret_cast<deallocate_plugin *>(funcExitAddr);

	_isLoaded = true;
}


template<typename T>
Plugin<T>::~Plugin()
{
	if (_library == nullptr)
		return;

	::FreeLibrary(_library);
}

#endif

//
// Platform independent code
//
template <typename T>
typename Plugin<T>::plugin_type* Plugin<T>::Load()
{
	if (!_target)
		_target = instanciate_fptr();

	return _target;
}


template <typename T>
void Plugin<T>::Unload()
{
	if (_target != nullptr)
		deallocate_fptr(_target);
}


template <typename T>
bool Plugin<T>::isLoaded()
{
	return _isLoaded;
}

KPL_END_NAMESPACE

#endif // KPL_PLUGIN_IMPL_H

