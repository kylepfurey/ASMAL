// .hpp
// ASMAL Library
// by Kyle Furey

#pragma once
#include<unordered_map>
#include <dylib.hpp>
#include <ffi.h>
#include <asmal/types.hpp>

namespace asmal {
    /** A handle to a dynamic library. */
    class library final {
        /** A cached FFI call. */
        class ffi final {
        };

        /** The dynamic library. */
        dylib::library _library;
        /** Each cached FFI call by its global offset in memory. */
        std::unordered_map<global_offset, ffi> _cache;

    public:
    };
}
