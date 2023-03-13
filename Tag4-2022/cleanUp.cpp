#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Pair {      
  public:            
    unsigned int sectionID1min;
    unsigned int sectionID1max;
    unsigned int sectionID2min;
    unsigned int sectionID2max;

    Pair(int min1, int max1, int min2, int max2){
        this->sectionID1min = min1;
        this->sectionID1max = max1;
        this->sectionID2min = min2;
        this->sectionID2max = max2;
    }

    bool compareEncapsulation(){// does one contain the other -> count
        if(sectionID1min >= sectionID2min && sectionID1max <= sectionID2max || sectionID1min <= sectionID2min && sectionID1max >= sectionID2max){
            return true;
        }
        return false;
    }

    bool compareOverlap(){// does one overlap the other -> count
        if(!(sectionID1min > sectionID2max || sectionID1max < sectionID2min)){
            return true;
        }
        return false;
    }
};

std::ostream& operator<<(std::ostream &s, const Pair &pair) {
    s <<"Paar: "<<pair.sectionID1min << " " << pair. sectionID1max << " " << pair.sectionID2min << " " << pair.sectionID2max << " ";//std::endl;
    return s;
}

int main()
{
    std::vector<Pair> paare;
    int containEncapsulation = 0;
    int containOverlap = 0;

    std::ifstream fileread ( "List.txt" );
    if(!fileread){std::cout<<"\nFehler. Datei wird nicht gelesen.\n";}

    if(fileread.is_open()){
        while(!fileread.eof()){ 
            unsigned int min1,max1,min2,max2;

            fileread >> min1;
            fileread.ignore(1,'-');
            fileread >> max1;
            fileread.ignore(1,',');
            fileread >> min2;
            fileread.ignore(1,'-');
            fileread >> max2;

            Pair paar = Pair(min1,max1,min2,max2);
            paare.push_back(paar);
        }
        fileread.close();
    }

    for(int i = 0; i < paare.size(); i++){   
        std::cout<<paare[i]<<" - Einkapselung - "<< paare[i].compareEncapsulation()<<" - Overlap - "<< paare[i].compareOverlap()<< std::endl;
        if(paare[i].compareEncapsulation()){ // bool Vergleich
            containEncapsulation++;
        }
        if(paare[i].compareOverlap()){ // bool Vergleich
            containOverlap++;
        }
    } 
    std::cout << "Einkapselung bei " << containEncapsulation << " Paaren. ";
    std::cout << "Overlap bei " << containOverlap << " Paaren.";


    return 0;

}//In how many assignment pairs does one range fully contain the other?