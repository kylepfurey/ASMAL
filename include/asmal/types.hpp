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
    using i32 = int32_t;
    using i64 = int64_t;

    /** Unsigned Integer */
    using u32 = uint32_t;
    using u64 = uint64_t;

    /** Floating-Point */
    using f32 = float;
    using f64 = double;

    /** ASMAL */
    using size = u32;
    using local_offset = u32;
    using global_offset = u32;
    using stack_offset = u32;
    using pointer = u64;
    using index = u32;
    using id = u32;
    using time = u64;
    class program;
    class filestream;
    struct opcode;
    struct rodata;
    class coroutine;
    class stack;
    class library;
    using error = std::runtime_error;
}
