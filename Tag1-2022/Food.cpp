#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
    std::vector<unsigned int> calories;
    std::vector<unsigned int> werteListe;
    unsigned int gesamt;
    unsigned int maxWert = 0;
    std::vector<unsigned int> maxWerteListe;

    std::ifstream fileread ( "Kalorien.txt" );
    if(!fileread){std::cout<<"\nFehler. Datei wird nicht gelesen.\n";}

    if(fileread.is_open()){
        std::string calString;
        while(getline(fileread, calString)){
            if (calString.empty()){
                       
                gesamt = 0;
                for(int i = 0; i < calories.size(); i++){   
                    gesamt += calories[i];                  //Gesamtwert
                }       
                calories.clear();                           //calories leeren für nächste Portion           
                werteListe.push_back(gesamt);               //Gesamtwerte in WerteListe
            }
            else{     
                calories.push_back(stoi(calString));        //sammelt Werte in calories 
            }  
    }

    /*Größten Wert finden*/
    for(int i = 0 ; i < werteListe.size(); i++){   
        if(werteListe[i] > maxWert){
            maxWert = werteListe[i];
            maxWerteListe.push_back(maxWert);
            std::cout << "\nneues Max: " << maxWert <<" bei " << i ;
        }
    }
    std::cout << "\n\nGroesste Kalorienmenge: "  << maxWerteListe.back() << "\n";
    std::cout << "Zweitgroesste Kalorienmenge: " << maxWerteListe.at(maxWerteListe.size()-2) << "\n";
    std::cout << "Drittgroesste Kalorienmenge: " << maxWerteListe.at(maxWerteListe.size()-3) << "\n";
    std::cout << "Zusammen: " << maxWerteListe.at(maxWerteListe.size()-3)+maxWerteListe.at(maxWerteListe.size()-2)+maxWerteListe.back()  << "\n";

    return 0;
}


}