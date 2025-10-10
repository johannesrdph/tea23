#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

void changeValueByParameter(int value) {
        value=99;
        fmt::println("y in Funktion: {}",value);
    }
void changeValueByPointer(int* ptr){
    *ptr = 77;
    fmt::println("y in Funktion:{}",*ptr);
}

int main(int argc, char **argv) {

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}! in version {} !\n", tea::PROJECT_NAME,tea::PROJECT_VER);

    /* INSERT YOUR CODE HERE */
    fmt::println("Teil O\n");
    fmt::print("argc: {}\n",argc);
    for (int i = 0; i < argc; i++)
        fmt::print("argv[{}]:{} Adresse: {}\n",i,argv[i],fmt::ptr(argv[i]));

    fmt::println("Tafelanschrieb siehe OneNote\n");
    int foo = 10;
    int* ptr = &foo;
    *ptr =42;
    int bar= 4711;
    ptr=&bar;
    *ptr=foo;
    fmt::print("bar:{}\n",bar);

    fmt::println("Teil 1\n");
    int x = 10;
    int* p = &x;
    fmt::println("x: {} (Adresse: {})\np: {} (Adresse: {})", x, fmt::ptr(&x),*p,fmt::ptr(p));
    *p = 42;
    fmt::println("x: {} (Adresse: {})\np: {} (Adresse: {})", x, fmt::ptr(&x),*p,fmt::ptr(p));

    fmt::println("Teil 2\n");
    double* d = new double(3.1415);   // Speicher im Heap reservieren
    fmt::println("Wert: {}", *d);    // Zugriff über Dereferenzierung  
    fmt::println("Adresse: {}", fmt::ptr(d));
    delete d;

    fmt::println("Teil 3\n");
    int y =0;
    fmt::println("Change by Parameter:");
    changeValueByParameter(y);
    fmt::println("y außerhalb Funktion:{}",y);
    fmt::println("Change by Pointer:");
    changeValueByPointer(&y);    
    fmt::println("y außerhalb Funktion:{}",y);
    return 0; /* exit gracefully*/
}
