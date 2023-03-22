#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/**Ist substring der Marker?
 * @return true wenn Marker
*/
bool isMarker(std::string sub){
    for (int i = 0; i < sub.size(); i++){
        for (int j = i + 1; j < sub.size(); j++){
            if(sub[i]==sub[j]){
                return false;
            }
        }
    }
    return true;
}
/**Vierstellige substrings durchgehen
 * @return Marker
*/
std::string viererSuchen(std::string input){
    std::string sub;
    int count = 4;

    for (int i = 0; i < input.size(); i++) {
       sub = input.substr (i,4); 
       if(sub.size()<4){
           break;
       }else{
           if(isMarker(sub)){
               std::cout << "\nDer Marker endet bei ";
               std::cout << count<<"\n";
               break;  
           }
           std::cout << sub << " - " << count<<"\n";
       }
        count++;
    }
    return sub;
}

int main()
{
    std::string input;
    std::string marker;

    std::ifstream fileread ( "Signal.txt" );
    if(!fileread){std::cout<<"\nFehler. Datei wird nicht gelesen.\n";}

    fileread >> input;

    std::cout<<"\n";
    marker = viererSuchen(input);
    std::cout << "Marker: " << marker;
    
    //Ende des vierstelligen Puffers finden, alle Buchstaben unterschiedlich
}
