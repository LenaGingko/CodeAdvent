#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string input;

    std::ifstream fileread ( "Signal.txt" );
    if(!fileread){std::cout<<"\nFehler. Datei wird nicht gelesen.\n";}

    fileread >> input;

    std::cout<<std::endl<<input<<std::endl;
    //Ende des vierstelligen Puffers finden, alle Buchstaben unterschiedlich
}
