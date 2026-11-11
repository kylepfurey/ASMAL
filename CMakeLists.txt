# .txt
# ASMAL CMake Configuration
# by Kyle Furey

# Initialize CMake
cmake_minimum_required(VERSION 4.3)
if (NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    if (DEFINED ENV{HOME})
        set(CMAKE_TOOLCHAIN_FILE
                "$ENV{HOME}/vcpkg/scripts/buildsystems/vcpkg.cmake"
                CACHE STRING "vcpkg toolchain file"
        )
    elseif (DEFINED ENV{USERPROFILE})
        set(CMAKE_TOOLCHAIN_FILE
                "$ENV{USERPROFILE}/vcpkg/scripts/buildsystems/vcpkg.cmake"
                CACHE STRING "vcpkg toolchain file"
        )
    endif ()
endif ()
project(ASMAL CXX)

# Set C++ compiler version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/bin)

# Build ASMAL
file(GLOB_RECURSE SOURCE CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_executable(ASMAL ${SOURCE})

# Set include directory and build macros
target_include_directories(ASMAL PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_compile_definitions(ASMAL PUBLIC $<$<CONFIG:Debug>:_DEBUG>)
target_compile_definitions(ASMAL PUBLIC
        FFI_BUILDING
)

# Find external libraries
find_package(mio CONFIG REQUIRED)
find_package(dylib CONFIG REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBFFI REQUIRED IMPORTED_TARGET libffi)

# Link external libraries to ASMAL
target_link_libraries(ASMAL PUBLIC
        mio::mio
        dylib::dylib
        PkgConfig::LIBFFI
)
