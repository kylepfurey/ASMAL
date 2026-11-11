// .hpp
// ASMAL Program
// by Kyle Furey

#pragma once
#include <vector>
#include <memory>
#include <unordered_map>
#include <asmal/filestream.hpp>
#include <asmal/coroutine.hpp>
#include <asmal/library.hpp>

namespace asmal {
    /** Stores program arguments on the stack. */
    struct args final {
        /** The number of program arguments. */
        const size argc;
        /** A pointer to the program arguments. */
        const pointer argv;
    };

    /** Stores all data within one instance of ASMAL. */
    class program final {
        /** A growing stack of memory mapped files. */
        filestream _filestream;
        /** Each executing coroutine. */
        std::vector<std::unique_ptr<coroutine> > _coroutines;
        /** Each active dynamic library by the global offset of its name. */
        std::unordered_map<offset_global, library> _libraries;

    public:
        /** Initializes the program at the given path. */
        explicit program(const char *path);
        /** Executes the ASMAL program and returns its result code. */
        i32 run(size argc, byte *const*argv);
    };
}
