#ifndef KPL_PLUGIN_H
#define KPL_PLUGIN_H

#include <iostream>
#include <string>

#include "config.h"

#if KPL_WINDOWS
	#include <Windows.h>
#else // KPL_LINUX
	#include <dlfcn.h>
#endif

KPL_BEGIN_NAMESPACE

template<typename T>
class Plugin 
{
#if KPL_WINDOWS
	typedef HMODULE library_handle;
#else
	typedef void * library_handle;
#endif

	typedef T plugin_type;
	typedef T *instanciate_plugin();
	typedef void deallocate_plugin(plugin_type *pl);

	public:
		Plugin(std::string library_path, std::string entry_symbol, std::string exit_symbol);
		~Plugin();

		plugin_type* Load();
		void Unload();

		bool isLoaded();

	private:
		bool _isLoaded;
		library_handle _library;
		plugin_type *_target;

	private:
		// Function pointer to init and destroy objects
		instanciate_plugin *instanciate_fptr;
		deallocate_plugin  *deallocate_fptr;
};


KPL_END_NAMESPACE

#endif // KPL_PLUGIN_H

#include "Plugin.tpp"