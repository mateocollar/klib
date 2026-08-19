cmake_minimum_required(VERSION 3.15)
project(klib VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_C_FLAGS_RELEASE "-O3 -march=native -flto -fvisibility=hidden")

find_package(PkgConfig REQUIRED)
pkg_check_modules(ZLIB_NG REQUIRED zlib-ng)

add_library(klib SHARED
    src/klib.c
    src/compression.c
)

target_include_directories(klib PRIVATE include ${ZLIB_NG_INCLUDE_DIRS})
target_link_libraries(klib PRIVATE ${ZLIB_NG_LIBRARIES})
target_link_directories(klib PRIVATE ${ZLIB_NG_LIBRARY_DIRS})

set_target_properties(klib PROPERTIES
    C_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN YES
)

install(TARGETS klib LIBRARY DESTINATION lib)
install(FILES include/klib.h include/compression.h DESTINATION include/klib)

enable_testing()
add_executable(test_compression tests/test_compression.c)
target_link_libraries(test_compression klib)
add_test(NAME compression COMMAND test_compression)
