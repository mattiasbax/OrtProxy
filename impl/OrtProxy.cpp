#include "../include/OrtProxy.h"
#include <fstream>
#include <string>
#include <windows.h>

extern "C" ORT_PROXY_EXPORT const void* __stdcall OrtGetApiBase( void ) noexcept;

static char g_path[ 1024 ];

bool SetOrtDllPath( const char* dllPath )
{
    std::ifstream f( dllPath );
    if ( !f.good( ) )
        return false;
    strcpy_s( g_path, dllPath );
    return true;
}

const void* __stdcall OrtGetApiBase( void ) noexcept
{
    auto h = LoadLibraryA( g_path );
    if ( !h )
        return nullptr;

    using fn = const void*( __stdcall* ) ( void );
    return ( ( fn ) GetProcAddress( h, "OrtGetApiBase" ) )( );
}
