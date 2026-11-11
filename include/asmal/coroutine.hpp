// .hpp
// ASMAL Coroutine
// by Kyle Furey

#pragma once
#include <vector>
#include <array>
#include <asmal/types.hpp>

/** The size of a coroutine stack. */
#define ASMAL_STACK_SIZE (8 * 1024 * 1024) // 8MB

/** The number of registers in a coroutine. */
#define ASMAL_REGISTER_COUNT 8

namespace asmal {
    /** A placeholder for an external coroutine's return value. */
    struct future final {
        /** Is this return value valid? */
        boolean valid;
        union {
            /** valid = true - The first byte of the return value. */
            byte data;
            struct {
                /**
                 * valid = false - The index of the external coroutine.
                 * This is checked before writing the return value.
                 */
                coro_index index;
                /**
                 * valid = false - The id of the external coroutine.
                 * This is checked before writing the return value.
                 */
                coro_id id;
            };
        };
    };

    /** Where a coroutine will write its return value. */
    struct promise final {
        /** The index of the promised coroutine. */
        coro_index index;
        /**
         * The future's bottom-up offset in the promised coroutine's stack.
         * This + sizeof(asmal::boolean) is where the return value is written to.
         */
        offset_stack offset;
    };

    /** A virtual thread of execution and its stack. */
    class coroutine final {
        /** The index of this coroutine. */
        coro_index _index;
        /** The unique id of this coroutine. */
        coro_id _id;
        /** The global offset of this coroutine's next instruction. */
        offset_global _next_instruction;
        /** The earliest time to execute this coroutine again. */
        coro_time _execution_time;
        /** Each promised coroutine to dispatch this coroutine's return value to. */
        std::vector<promise> _promises;
        /** This coroutine's stack. */
        std::array<byte, ASMAL_STACK_SIZE> _stack;
        /** This coroutine's registers. */
        std::array<dword, ASMAL_REGISTER_COUNT> _registers;
        /** The current offset of this coroutine's stack. */
        offset_stack _offset;
        /**
         * The external coroutine that is blocking this coroutine.
         * Index 0 is NULL.
         */
        coro_index _await;

    public:
    };
}
