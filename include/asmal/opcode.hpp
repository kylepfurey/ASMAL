// .hpp
// ASMAL Opcodes
// by Kyle Furey

#pragma once
#include <asmal/types.hpp>

namespace asmal {
    /** Every operation in ASMAL. */
    enum class bytecode : byte {
        EXIT      = 'X',
        MAP       = 'M',
        LIBRARY   = 'L',
        LOAD      = '{',
        STORE     = '}',
        ADDRESS   = '@',
        PRINT     = 'O',
        READ      = 'I',
        ALLOCATE  = '$',
        FREE      = '_',
        PUSH      = ']',
        POP       = '[',
        COPY      = 'C',
        MOVE      = 'c',
        SET       = 'S',
        EQUAL     = 'E',
        GREATER   = 'G',
        NEGATE    = '!',
        IF        = '?',
        ELSE      = ':',
        SWITCH    = ';',
        JUMP      = 'J',
        HOP       = 'j',
        CALL      = '(',
        RETURN    = ')',
        FFI       = 'F',
        NIL       = '0',
        ASYNC     = 'A',
        AWAIT     = 'a',
        BIND      = 'B',
        YIELD     = 'Y',
        SLEEP     = 'Z',
        CANCEL    = 'k',
        KILL      = 'K',
        INCREMENT = 'i',
        DECREMENT = 'd',
        ADD       = '+',
        SUBTRACT  = '-',
        MULTIPLY  = '*',
        DIVIDE    = '/',
        MODULO    = '%',
        AND       = '&',
        OR        = '|',
        NOT       = '~',
        XOR       = '^',
        LSHIFT    = '<',
        RSHIFT    = '>',
        HASH      = '#',
        SINT      = 's',
        UINT      = 'u',
        FLOAT     = 'f',
    };

    /** Flags for an opcode argument. */
    enum class flags : byte {
        BITS_MASK      = 0b00000011,
        BITS_8         = 0b00000000,
        BITS_16        = 0b00000001,
        BITS_32        = 0b00000010,
        BITS_64        = 0b00000011,
        BITS_128       = 0b00000000, // float only

        OFFSET_MASK    = 0b00001100,
        OFFSET_LITERAL = 0b00000000,
        OFFSET_STACK   = 0b00000100,
        OFFSET_LOCAL   = 0b00001000,
        OFFSET_ADDRESS = 0b00001100, // stack offset to pointer

        TYPE_MASK      = 0b00110000,
        TYPE_BINARY    = 0b00000000,
        TYPE_UNSIGNED  = 0b00010000,
        TYPE_SIGNED    = 0b00100000,
        TYPE_FLOAT     = 0b00110000,
    };

    /** Stores one ASMAL instruction. */
    struct opcode final {
        /** The instruction to execute. */
        bytecode instruction;
        /** Flags for the size argument. */
        flags size_flags;
        /** Flags for the read argument. */
        flags read_flags;
        /** Flags for the write argument. */
        flags write_flags;
        /** The size argument. */
        size size_arg;
        /** The read argument. */
        pointer read_arg;
        /** The write argument. */
        pointer write_arg;
    };
}
