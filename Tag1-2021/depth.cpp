#include <iostream>
#include <fstream>

int main()
{
    unsigned int liste[10] = {0,0,0,0,0,0,0,0,0,0};
    unsigned int higher = 0;
	std::ifstream fileread ( "Werte.txt" );

	if(!fileread){std::cout<<"\nFehler. Datei wird nicht gelesen.\n";}

    for (int i = 0; i < 10; i++)
    {
        fileread >> liste[i];
        std::cout << liste[i] << " ";
    }

    std::cout << "\n\nThe value increases ";
    for (int i = 1; i < 10; i++) {
        if(liste[i]>liste[i-1]){
            higher++;
        }
    }
    
std::cout << higher << " times";

    return 0;
}
