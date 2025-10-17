#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

/* Aufgabe 1*/
int globalVar = 1;
int globalVar0 = 2;
static int staticVar = 3;
const int constVar = 4;

int main(int argc, char **argv) {

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", tea::PROJECT_NAME);
    
    /* INSERT YOUR CODE HERE */
    /* Aufgabe 1*/
    fmt::println("Wert Global 1: {}",globalVar);
    fmt::println("Adresse Global 1: {}",fmt::ptr(&globalVar));

    fmt::println("Wert Global 2: {}",globalVar0);
    fmt::println("Adresse Global 2: {}",fmt::ptr(&globalVar0));

    fmt::println("Wert Static: {}",staticVar);
    fmt::println("Adresse: Static {}",fmt::ptr(&staticVar));

    fmt::println("Wert Const: {}",constVar);
    fmt::println("Adresse Const: {}",fmt::ptr(&constVar));
    
    /* Aufgabe 2*/
    int localVar = 2;
    static int localVarStatic = 2;
    const int localVarConst = 2;

    fmt::println("Wert Local : {}",localVar);
    fmt::println("Adresse Local : {}",fmt::ptr(&localVar));

    fmt::println("Wert StaticLocal : {}",localVarStatic);
    fmt::println("Adresse StaticLocal : {}",fmt::ptr(&localVarStatic));

    fmt::println("Wert ConstLocal : {}",localVarConst);
    fmt::println("Adresse ConstLocal : {}",fmt::ptr(&localVarConst));

    

    return 0; /* exit gracefully*/
}
