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
std::string markerSuchen(std::string input, int size){
    std::string sub;
    int count = size;

    for (int i = 0; i < input.size(); i++) {
       sub = input.substr (i,size); 
       if(sub.size()<size){
           break;
       }else{
           if(isMarker(sub)){
               std::cout << "\nMarker size "<<size<<" endet bei ";
               std::cout << count<<"\n";
               break;  
           }
           //std::cout << sub << " - " << count<<"\n";
       }
        count++;
    }
    return sub;
}

int main()
{
    std::string input;
    std::string marker;
    std::string message;

    std::ifstream fileread ( "Signal.txt" );
    if(!fileread){std::cout<<"\nFehler. Datei wird nicht gelesen.\n";}

    fileread >> input;

    marker = markerSuchen(input, 4);
    message = markerSuchen(input, 14);

    std::cout << "Marker: " << marker << " - Message: " << message;
    
    //Ende des vierstelligen Puffers finden, alle Buchstaben unterschiedlich
}
