// .cpp
// ASMAL Entry Point
// by Kyle Furey

#include <asmal/program.hpp>

/** Executes a ASMAL program. */
int main(int argc, char *argv[]) {
    return asmal::program(argc > 0 ? argv[1] : nullptr).run();
}
