// .hpp
// ASMAL Coroutine
// by Kyle Furey

#pragma once
#include <vector>
#include <array>
#include <asmal/types.hpp>

/** The size of a coroutine stack. */
#define ASMAL_STACK_SIZE (8 * 1024 * 1024) // 8MB

namespace asmal {
    /** A virtual thread of execution and its stack. */
    struct coroutine final {
        /** A placeholder for an external coroutine's return value. */
        struct future final {
            /** Is this return value valid? */
            boolean _valid;
            union {
                /** valid = true - The first byte of the return value. */
                byte _data;
                struct {
                    /**
                     * valid = false - The index of the external coroutine.
                     * This is checked before writing the return value.
                     */
                    index _index;
                    /**
                     * valid = false - The id of the external coroutine.
                     * This is checked before writing the return value.
                     */
                    id _id;
                };
            };
        };

        /** Where a coroutine will write its return value. */
        struct promise final {
            /** The index of the promised coroutine. */
            index _index;
            /**
             * The future's bottom-up offset in the promised coroutine's stack.
             * This + sizeof(asmal::boolean) is where the return value is written to.
             */
            stack_offset _offset;
        };

        /** The index of this coroutine. */
        index _index;
        /** The unique id of this coroutine. */
        id _id;
        /** The global offset of this coroutine's next instruction. */
        global_offset _next_instruction;
        /** The earliest time to execute this coroutine again. */
        time _execution_time;
        /** Each promised coroutine to dispatch this coroutine's return value to. */
        std::vector<promise> _promises;
        /** This coroutine's stack. */
        std::array<byte, ASMAL_STACK_SIZE> _stack;
        /** The current offset of this coroutine's stack. */
        stack_offset _offset;
        /**
         * The external coroutine that is blocking this coroutine.
         * Index 0 is NULL.
         */
        id await;

    public:
    };
}
