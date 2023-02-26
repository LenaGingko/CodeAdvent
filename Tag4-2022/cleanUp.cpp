#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Pair {      
  public:            
    std::vector<unsigned int> sectionID1;
    std::vector<unsigned int> sectionID2;
    unsigned int sectionID1min;
    unsigned int sectionID1max;
    unsigned int sectionID2min;
    unsigned int sectionID2max;

    Pair(int min1, int max1, int min2, int max2){
        sectionID1min = min1;
        sectionID1max = max1;
        sectionID2min = min2;
        sectionID2max = max2;

        sectionID1.push_back(min1);
        sectionID1.push_back(max1);
        sectionID2.push_back(min2);
        sectionID2.push_back(max2);
    }

};

std::ostream& operator<<(std::ostream &s, const Pair &pair) {
    s <<"Paar: "<<pair.sectionID1min << " " << pair. sectionID1max << " " << pair.sectionID2min << " " << pair.sectionID2max << std::endl;
    return s;
}

int main()
{
    std::vector<Pair> paare;
    std::vector<unsigned int> maxWerteListe;

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
            //std::cout << min1 << " " << max1 << " " << min2 << " " << max2 << "\n";

            Pair paar = Pair(min1,max1,min2,max2);
            paare.push_back(paar);
        }
        fileread.close();
    }

    for(int i = 0; i < paare.size(); i++){   
        std::cout<<paare[i];
    } 
    return 0;

}