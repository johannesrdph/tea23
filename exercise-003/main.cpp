#include <fmt/chrono.h>
#include <fmt/format.h>

/*
Fahre hoch =1
Stop auf Weg nach oben =2
Fahre runter=3
Garagentor zu=4
Stop auf dem Weg nach unten=5
Garagentor offen=6;
*/

bool Taste;
bool EndschalterUnten ;
bool EndschalterOben;
int state= 1;
const int input_size=6;
bool input[input_size];

void SwitchCaseStateDiagram(bool Taste, bool EndschalterUnten, bool EndschalterOben)
{
    switch (state)
    {
    case 1: /*Fahre hoch*/
        fmt::println("Fahre hoch");
        if (Taste)
        {
            state=2;/*Stop auf Weg nach oben*/            
        }
        else if (EndschalterOben)
        {
            state=6; /*Garagentor offen*/
        }    
        break;
    case 2: /*Stop auf Weg nach oben*/
        fmt::println("Stop auf Weg nach oben");
        if (Taste)
        {
            state=3;/*Fahre runter*/
        }
        break;
    case 3: /*Fahre runter*/
        fmt::println("Fahre runter");
        if (Taste)
        {
            state=5;/*Stop auf Weg nach unten*/
        }
        else if (EndschalterUnten)
        {
            state=4; /*Garagentor zu*/
        }        
        break;
    case 4: /*Garagentor zu*/
        fmt::println("Garagentor zu");
        if (Taste)
        {
            state=1;/*Fahre hoch*/
        }
        break;
    case 5: /*Stop auf Weg nach unten*/
        fmt::println("Stop auf Weg nach unten");
        if (Taste)
        {
            state=1;/*Fahre hoch*/
        }
        break;
    case 6: /*Garagentor offen*/
        fmt::println("Garagentor offen");
        if (Taste)
        {
            state=3; /*Fahre runter*/
        }
        break;
    default:
        break;
    }
}

auto main(int argc, char** argv) -> int
{
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", argv[0]);    
    bool Taste=false;
    bool EndschalterUnten = false;
    bool EndschalterOben = false;
    
    int input[input_size]={1,1,1,1,1,1};
    int n = input_size;
    for (int i=0; i<n;i++){
        switch (input[i])
        {
        case 1:
            Taste=true;
            EndschalterUnten = false;
            EndschalterOben = false;

            break;
        case 2:
            Taste=false;
            EndschalterUnten = true;
            EndschalterOben = false;
            break;
        case 3:
            Taste=false;
            EndschalterUnten = false;
            EndschalterOben = true;
            break;
        }
        SwitchCaseStateDiagram(Taste,EndschalterUnten,EndschalterOben);
    }
    return 0; /* exit gracefully*/
}
