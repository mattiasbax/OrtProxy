#pragma once
#ifdef ORT_PROXY_EXPORTS
#define ORT_PROXY_EXPORT __declspec( dllexport )
#else
#define ORT_PROXY_EXPORT
#endif

extern "C" ORT_PROXY_EXPORT bool SetOrtDllPath( const char* dllPath );