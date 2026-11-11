// .cpp
// ASMAL Entry Point
// by Kyle Furey

#include <asmal/program.hpp>

/** Executes an ASMAL program. */
int main(int argc, char *argv[]) {
    if (argc > 1) {
        return static_cast<int>(
            asmal::program(argv[1]).run(
                static_cast<asmal::u32>(argc - 2),
                reinterpret_cast<asmal::byte *const*>(argv + 2)
            )
        );
    }
    return static_cast<int>(
        asmal::program(nullptr).run(
            0,
            nullptr
        )
    );
}
