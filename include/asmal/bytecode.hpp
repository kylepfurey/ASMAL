// .hpp
// ASMAL Opcodes
// by Kyle Furey

#pragma once
#include <asmal/types.hpp>

namespace asmal {
    /** Every operation in ASMAL. */
    enum class opcode : hword {
        EXIT      = 'X',
        MAP       = 'M',
        LIBRARY   = 'L',
        LOAD      = '{',
        STORE     = '}',
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
        ASHIFT    = '\\',
        HASH      = '#',
        UINT      = 'u',
        SINT      = 's',
        FLOAT     = 'f',
        ADDRESS   = '@',
    };

    /** Flags for a bytecode argument. */
    enum class flags : hword {
        //                 __FS##
        TYPE_MASK      = 0b001111,
        U8             = 0b000000,
        U16            = 0b000001,
        U32            = 0b000010,
        U64            = 0b000011,
        I8             = 0b000100,
        I16            = 0b000101,
        I32            = 0b000110,
        I64            = 0b000111,
        F32            = 0b001100,
        F64            = 0b001101,
        F128           = 0b001110,
        ADDRESS        = 0b001111,
        //                 ##____
        VALUE_MASK     = 0b110000,
        LITERAL        = 0b000000,
        OFFSET_STACK   = 0b010000,
        OFFSET_LOCAL   = 0b100000,
    };

    /** Data for an executed ASMAL instruction. */
    struct bytecode final {
        /** The instruction to execute. */
        const opcode instruction;
        /** The type of argument for this instruction. */
        const flags type;
        /** The array of words storing the instruction's argument. */
        const word args[];
    };
}
