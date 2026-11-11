// .hpp
// ASMAL Filestream
// by Kyle Furey

#pragma once
#include <vector>
#include <mio/mmap.hpp>
#include <asmal/types.hpp>

namespace asmal {
    /** Read-only data stored in a file. */
    struct rodata final {
        /** The number of bytes in this data string. */
        const size length;
        /** The null-terminated array of data. */
        const byte data[];
    };

    /** Maps files into memory for random access and iteration. */
    class filestream final {
        /** Each file mapped in memory. */
        std::vector<mio::mmap_source> _files;

    public:
    };
}
