#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
    std::ifstream fileread ( "directory.txt" );
    if(!fileread){std::cerr<<"\nFehler. Datei wird nicht gelesen.\n";}

    if(fileread.is_open()){

        while(!fileread.eof()){ 

        }
        
    }


}