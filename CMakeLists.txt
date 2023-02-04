project(ORTPROXY)

cmake_minimum_required(VERSION 3.8)

set(SRC_FILES impl/OrtProxy.cpp
	include/OrtProxy.h)

add_library(OrtProxy SHARED ${SRC_FILES})
set_target_properties(OrtProxy PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)
target_compile_definitions(OrtProxy PRIVATE $<$<BOOL:WIN32>:ORT_PROXY_EXPORTS>>)
target_include_directories(OrtProxy PUBLIC include)
