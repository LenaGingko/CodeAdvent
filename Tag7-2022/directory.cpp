#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> zeile;

    std::ifstream fileread ( "directory.txt" );
    if(!fileread){std::cerr<<"\nFehler. Datei wird nicht gelesen.\n";}


    if(fileread.is_open()){
        std::string line;

        while(getline(fileread, line)){
            zeile.push_back(line);
        }
        
    }

    for(int i = 0; i < zeile.size(); i++){     
        std::cout<<zeile[i]<<"\n";
    }
}