#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

char findSharedValue(std::string s1,std::string s2){
    //std::cout<<"SizeCom1: "<<s1.size()<<"\n";
    for(int i = 0; i < s1.size(); i++){   
        char compare1 = s1.at(i);
        for(int j = 0; j < s2.size(); j++){
            char compare2 = s2.at(j);
            if(compare1 == compare2){
                return compare1;
            }
        }
    }
    return 0;
}
char findSharedValue(std::string s1,std::string s2,std::string s3){
    for(int i = 0; i < s1.size(); i++){   //1
        char compare1 = s1.at(i);
        for(int j = 0; j < s2.size(); j++){ //2
            char compare2 = s2.at(j);
            if(compare1 == compare2){
                for(int k = 0; k < s3.size(); k++){ //3
                    char compare3 = s3.at(k);
                    if(compare1 == compare3){
                        std::cout<<"Treffer Wert: "<< compare1 <<"\n\n";
                        return compare1;
                    }
                }
            }
        }
    }
    return '0';
}
int sumOfValues(std::vector<char> values){
    //abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ
    const std::unordered_map<char, int> alphabet = {
    {'a',1},{'b',2},{'c',3},{'d',4},{'e',5},{'f',6},{'g',7},{'h',8},{'i',9},{'j',10},{'k',11},{'l',12},{'m',13},{'n',14},{'o',15},{'p',16},{'q',17},{'r',18},{'s',19},{'t',20},{'u',21},{'v',22},{'w',23},{'x',24},{'y',25},{'z',26},
    {'A',27},{'B',28},{'C',29},{'D',30},{'E',31},{'F',32},{'G',33},{'H',34},{'I',35},{'J',36},{'K',37},{'L',38},{'M',39},{'N',40},{'O',41},{'P',42},{'Q',43},{'R',44},{'S',45},{'T',46},{'U',47},{'V',48},{'W',49},{'X',50},{'Y',51},{'Z',52}
    };
    int sum = 0;

    for(int i = 0; i < values.size(); i++){   
        // std::cout<<values[i]<<"\t"<<alphabet.at(values[i])<<"\t";;                 //Prio in Hashmap finden
        sum += alphabet.at(values[i]);                                              //PrioWerte zusammenrechnen
    } 
    return sum;
}

std::vector<char> getGroupValues(std::vector<std::string> elfRucksack){
    std::array<std::string, 3> group;//alle drei Rucksäcke
    std::vector<char> sharedValue;// geteilter Buchstabe
    

    if(elfRucksack.size()%3 != 0){
        std::cout<<"Dreiergruppen gehen nicht auf!";
    }
    for(int i = 0; i < elfRucksack.size(); i=i+3){ 
        
        group = {elfRucksack[i],elfRucksack[i+1],elfRucksack[i+2]}; //neue 3Gruppe
        std::cout<<"Gruppe: "<<elfRucksack[i]<<" "<<elfRucksack[i+1]<<" "<<elfRucksack[i+2]<<"\n";

        sharedValue.push_back(findSharedValue(group[0],group[1],group[2])); //GruppenWert 
    }

    return sharedValue;
}


int main()
{
    std::vector<std::string> rucksaecke;
    std::vector<std::string> com1;
    std::vector<std::string> com2;
    std::vector<char> values;//Buchstaben, die beide Compartments besitzen
    std::vector<char> badges;

    std::ifstream fileread ( "rucksack.txt" );
    if(!fileread){std::cout<<"Fehler. Datei wird nicht gelesen.\n";}

    if(fileread.is_open()){
        std::string ruckSack;
        std::string half1;
        std::string half2;
        int rucksackSize;
        while(getline(fileread, ruckSack)){
            rucksaecke.push_back(ruckSack);
            rucksackSize = ruckSack.size();
            half1 = ruckSack.substr (0,(rucksackSize/2)); //(start,lenght)
            com1.push_back(half1);
            half2 = ruckSack.substr ((rucksackSize/2),(rucksackSize/2)); 
            com2.push_back(half2);
        }
    }
    for(int i = 0; i < rucksaecke.size(); i++){   
        // std::cout<<rucksaecke[i]<<"\t"<<com1[i]<<"\t"<<com2[i]<<"\t";    
        // std::cout<<rucksaecke[i]<<"\n";
        values.push_back(findSharedValue(com1[i],com2[i]));                         //Buchstabe in Liste
    }
    
    badges = getGroupValues(rucksaecke);
    std::cout<<"Fertig";
    
    std::cout<<"Anzahl Rucksäcke: "<<rucksaecke.size()<<"\n";
    std::cout<<"Summe Priowerte Compartments: "<<sumOfValues(values)<<"\n";
    std::cout<<"Summe Priowerte Gruppe: "<<sumOfValues(badges)<<"\n";

    return 0;
}
