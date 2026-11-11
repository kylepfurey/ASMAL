// .hpp
// ASMAL Types
// by Kyle Furey

#pragma once
#include <cstdint>
#include <stdexcept>

/** Asynchronous Stack Machine Assembly Language */
namespace asmal {
    /** Byte */
    using byte = uint8_t;

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
    using f32 = float;
    using f64 = double;
    using f128 = long double;

    /** ASMAL */
    using boolean = u32;
    using size = u32;
    using local_offset = u32;
    using global_offset = u64;
    using stack_offset = u32;
    using pointer = u64;
    using index = u32;
    using id = u32;
    using time = u64;
    using error = std::runtime_error;
}
