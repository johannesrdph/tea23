#include <fmt/chrono.h>
#include <fmt/format.h>
#include "graveyard.h"
/* .bss Segment */
int foo;
int foo2 = 0;

/* .data Segment */
int data = 45;
int data2 = 43;

/* .rodata Segment */
const int rodata = 45;
const int rodata2 = 43;



void doSomething(int value)
{
    value = value + 1;
    fmt::print("doSomething, value {}\n", value);
}

void doSomethingPtr(int* ptr)
{
    *ptr = *ptr + 1;
    fmt::print("doSomethingPtr, value {}\n", *ptr);
}

int* doReturnAPtr()
{
    int value = 4711;
    fmt::print("doReturnAPtr, value {}\n", value);
    return &value;
}

void doSomethingStatic()
{
    static int value = 56;
    value = value + 1;
    fmt::print("doSomethingStatic, value {}\n", value);
}
   
/*
auto main(int argc, char** argv) -> int
{
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */



     /* 
     Antworten Aufgabe 1:
     1: a, 2: b, 3:a , 4: a; 
     
     
     Aufgabe 2: siehe zudem Readme (Eigene Lösung gibt hinzugefügten Code an),
     
        Bsp:1
        In der Funktion Cursed fehlt die Funktion free. 
        Durch Malloc wird jedes mal neuer Speicher im Stack belegt, 
        der ohne free nicht wieder freigegeben wird.

        Bsp:2
        Da nach dem freigeben des Speicher nochmal auf die Variable zugegriffen wird,
        kommt es zu undefinierten Verhalten.
        Wird danach nochmal Speicher allokiert, wird der Speicher der alten Variable überschrieben.

        Bsp:3
        Durch das andauernde Aufrufen der malloc Funktion, ohne die Verwendung von free wird immer
        mehr Speicher belegt. Das wird zu einem Stackoverflow führen, der das Programm beendet. 

    Aufgabe 4:
        - Wann tritt ein Stack Overflow auf? 
        Wenn viel dynamischer Speicher allokiert wird, ohne ihn wieder freizugeben.
        Das passiert insbesondere bei rekursivem Aufruf von malloc

        - Warum entstehen Memory Leaks?
        Wenn Speicher belegt, aber nicht wieder freigegeben wird

        - Was ist gefährlicher: Ein Zombie-Pointer oder ein Leak?
        Ein Zombie-Pointer, da dieser undefiniertes Verhalten verursachen kann

        - Wie kann man solche Fehler frühzeitig erkennen?


     Aufgabe 5:   
     
    1. Wie unterscheiden sich die Adressen der drei `undead`-Variablen? 
    Globale: Adresse Bleibt gleich, liegt im data-Segment 
    Lokale: Adresse Ändert sich bei jedem Aufruf, liegt im Stack
    Static: Adresse bleibt gleich, liegt im data-Segment
    2. Warum bleibt der Wert in `persistent()` zwischen Aufrufen erhalten?  
    Weil die static im data-Segment liegt und nach Ende der Funktion nicht gelöscht wird
    3. Was passiert, wenn man `extern int undead;` in `graveyard.c` verwendet? 
    Beide Greifen auf den selben Speicher zu, es wird keine neue variable angelegt
    4. In welchem Speicherbereich liegen:
    - die globale Variable `undead`?
    data
    - die lokale Variable in `awaken()`?
    Stack
    - die statische Variable in `persistent()`?
    data
*/


    

    
/*Aufgabe 5*/
int undead = 7;
int main() {
    fmt::println("🪦 Globale Variable sagt: {}", undead);
    awaken();
    persistent();
    persistent();
    fmt::println("🪦 Globale Variable nach Aufruf: {}", undead);
}

/*
    fmt::print("Hello, {}!\n", argv[0]);

    doSomething(42);
    int bar = 42;
    doSomething(bar);
    fmt::print("The value of bar is: {}\n", bar);

    doSomethingPtr(&bar);
    fmt::print("The value of bar after doSomethingPtr is: {}\n", bar);

    int* returnedPtr = doReturnAPtr();
    fmt::print("The value of returnedPtr content  after doReturnAPtr is: {}\n", *returnedPtr);
    doSomething(42);
    fmt::print("The value of returnedPtr content  after doReturnAPtr is: {}\n", *returnedPtr);

    doSomethingStatic();
    doSomethingStatic();
    doSomethingStatic();
    doSomethingStatic();

    fmt::print("Value of foo {} address of foo {}\n", foo, fmt::ptr(&foo));
    fmt::print("Value of foo2 {} address of foo2 {}\n", foo2, fmt::ptr(&foo2));
    fmt::print("Value of data {} address of data {}\n", data, fmt::ptr(&data));
    fmt::print("Value of data2 {} address of data2 {}\n", data2, fmt::ptr(&data2));
    fmt::print("Value of rodata {} address of rodata {}\n", rodata, fmt::ptr(&rodata));
    fmt::print("Value of rodata2 {} address of rodata2 {}\n", rodata2, fmt::ptr(&rodata2));

    int var;
    static int var2;
    fmt::print("Value of var {} address of var {}\n", var, fmt::ptr(&var));
    fmt::print("Value of var2 {} address of var2 {}\n", var2, fmt::ptr(&var2));

    return 0; /* exit gracefully*/


