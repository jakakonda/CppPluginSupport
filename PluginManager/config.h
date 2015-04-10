#ifndef KPL_CONFIG_H
#define KPL_CONFIG_H


#define KPL_BEGIN_NAMESPACE namespace plugin_manager {
#define KPL_END_NAMESPACE }


#if defined(WIN32) || defined(_WIN32)
	#define KPL_WINDOWS 1
#else
	#define KPL_LINUX 1
	#error Linux support not (yet) implemented
#endif

#endif	// KPL_CONFIG_H