// .hpp
// ASMAL Library
// by Kyle Furey

#pragma once
#include <vector>
#include <unordered_map>
#include <dylib.hpp>
#include <ffi.h>
#include <asmal/types.hpp>

namespace asmal {
    /** A handle to a dynamic library. */
    class library final {
        /** A cached FFI call. */
        class ffi final {
            /** The call signature of this foreign function. */
            ffi_cif _cif;
            /** The address of the called function. */
            void *_func;
        };

        /** The loaded dynamic library. */
        dylib::library _library;
        /** Each custom type used in the library. */
        std::vector<ffi_type> _types;
        /** Each cached FFI call by its global offset in memory. */
        std::unordered_map<global_offset, ffi> _cache;

    public:
    };
}
