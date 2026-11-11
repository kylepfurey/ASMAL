// .hpp
// ASMAL Opcodes
// by Kyle Furey

#pragma once
#include <asmal/types.hpp>

namespace asmal {
    /** Every operation in ASMAL. */
    enum class bytecode : byte {
    };

    /** Flags for an opcode argument. */
    enum class flags : byte {
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
