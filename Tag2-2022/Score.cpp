#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    std::vector<char> me;
    std::vector<char> opponent;
    char mein;
    char sein;
    int count = 0;
    int ichPunkte = 0;

    std::ifstream fileread ( "Guide.txt" );
    if(!fileread){std::cout<<"\nFehler. Datei wird nicht gelesen.\n";}

    while(fileread >> sein >> mein){
        opponent.push_back(sein);
        me.push_back(mein);
    }
  
    for(int i = 0 ; i < opponent.size(); i++){   
        std::cout <<opponent[i]<< " " << me[i] << " ";
//Result 1
    /*
        if(opponent[i] == 'A' && me[i] == 'X' || opponent[i] == 'B' && me[i] == 'Y' || opponent[i] == 'C' && me[i] == 'Z'){ //Draw
            ichPunkte += 3;
            std::cout <<"It's a Draw! ";
        }
        if(opponent[i] == 'A' && me[i] == 'Y' || opponent[i] == 'B' && me[i] == 'Z' || opponent[i] == 'C' && me[i] == 'X'){ //Win
            ichPunkte += 6;
            std::cout <<"Win! ";
        }
        if(opponent[i] == 'A' && me[i] == 'Z' || opponent[i] == 'B' && me[i] == 'X' || opponent[i] == 'C' && me[i] == 'Y'){ //Lose for me
            std::cout <<"Lose! ";
        }
    */
//Result 1
        if(me[i] == 'Y'){ //Draw
            ichPunkte += 3;
            std::cout <<"It's a Draw! ";
            if(opponent[i] == 'A'){
                ichPunkte += 1;
                std::cout <<"Rock +1 ";
            }
            if(opponent[i] == 'B'){
                ichPunkte += 2;
                std::cout <<"Paper +2";
            }
            if(opponent[i] == 'C'){
                ichPunkte += 3;
                std::cout <<"Scissors +3";
            }
        }
        if(me[i] == 'Z' ){ //Win
            ichPunkte += 6;
            std::cout <<"Win! ";
            if(opponent[i] == 'A'){
                ichPunkte += 2;
                std::cout <<"Paper +2"; 
            }
            if(opponent[i] == 'B'){
                ichPunkte += 3;
                std::cout <<"Scissors +3";
            }
            if(opponent[i] == 'C'){
                ichPunkte += 1;
                std::cout <<"Rock +1 ";
            }
        }
        if(me[i] == 'X'){ //Lose for me
            std::cout <<"Lose! ";
            if(opponent[i] == 'A'){
                ichPunkte += 3;
                std::cout <<"Scissors +3";
            }
            if(opponent[i] == 'B'){
                ichPunkte += 1;
                std::cout <<"Rock +1 ";
            }
            if(opponent[i] == 'C'){
                ichPunkte += 2;
                std::cout <<"Paper +2";
            }
        }
        std::cout <<"\n";
    }    
    std::cout<<"\nPunkte ich: "<<ichPunkte;
}