// .hpp
// ASMAL Types
// by Kyle Furey

#pragma once
#include <cstdint>
#include <stdexcept>

/** Asynchronous Stack Machine Assembly Language */
namespace asmal {
    /** Signed Integer */
    using i8  = int8_t;
    using i16 = int16_t;
    using i32 = int32_t;
    using i64 = int64_t;

    /** Unsigned Integer */
    using u8  = uint8_t;
    using u16 = uint16_t;
    using u32 = uint32_t;
    using u64 = uint64_t;

    /** Floating-Point */
    using f32  = float;
    using f64  = double;
    using f128 = long double;

    /** ASMAL */
    using byte          = u8;
    using hword         = u16;
    using word          = u32;
    using dword         = u64;
    using boolean       = word;
    using pointer       = dword;
    using size          = word;
    using offset_local  = word;
    using offset_global = dword;
    using offset_stack  = word;
    using coro_index    = word;
    using coro_id       = word;
    using coro_time     = u64;
    using error         = std::runtime_error;
}
