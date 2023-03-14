#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Stack {      
  private:
    std::vector<char>stapel[9];
  public: 
    
    Stack(){
        stapel[0] = {'R','G','J','B','T','V','Z'};
        stapel[1] = {'J','R','V','L'};
        stapel[2] = {'S','Q','F'};
        stapel[3] = {'Z','H','N','L','F','V','Q','G'};
        stapel[4] = {'R','Q','T','J','C','S','M','W'};
        stapel[5] = {'S','W','T','C','H','F'};
        stapel[6] = {'D','Z','C','V','F','N','J'};
        stapel[7] = {'L','G','Z','D','W','R','F','Q'};
        stapel[8] = {'J','B','W','V','P'};
    }
    void addCrater(int i, char newCrater){
        stapel[i].push_back(newCrater);
    }
    void removeTopCrater(int i){
        stapel[i].pop_back();
    }
    char getTopCrater(int i){
        return stapel[i].back();
    }
    std::vector<char> get1Stapel(int welchenStapel){
        return stapel[welchenStapel];
    }
    void move9000(int menge, int from, int to){
        int n = 0;
        while(n < menge){
        char kiste = getTopCrater(from-1);
        removeTopCrater(from-1);
        addCrater(to-1, kiste);
        n++;
        }
    }
    void move9001(int menge, int from, int to){
        std::vector<char>kisten;
        int n = 0;
        while(n < menge){
            kisten.push_back(getTopCrater(from-1));
            removeTopCrater(from-1);
            n++;
        }
        int j = kisten.size()-1;
        while(j >= 0){
            addCrater(to-1, kisten.at(j));
            j--;
        }
    }
};

std::ostream& operator<<(std::ostream &s, Stack &stack) {
    s <<"\n\nStack: ";
    int i = 0;
    while(i < 9){
        s <<i+1<<": ";
        for(int n = 0; n < stack.get1Stapel(i).size(); n++){
            s <<stack.get1Stapel(i).at(n)<< " ";
        }
        s <<"\n";
        i++;
    }
    return s;
}

int main()
{
    int menge; int from; int to;
    std::vector<int> mengeBefehl;
    std::vector<int> fromBefehl;
    std::vector<int> toBefehl;

    Stack stapel = Stack();

    std::ifstream fileread ( "Kisten.txt" );
    if(!fileread){std::cerr<<"\nFehler. Datei wird nicht gelesen.\n";}

    if(fileread.is_open()){
        int n = 1;
        int zeile = 11;
        while(n != zeile){
            fileread.ignore(1000, '\n');
            ++n;
        }

        while(!fileread.eof()){ 
            fileread.ignore(10,'e');
            fileread >> menge;
            fileread.ignore(10,'m');
            fileread >> from;
            fileread.ignore(10,'o');
            fileread >> to;

            mengeBefehl.push_back(menge);
            fromBefehl.push_back(from);
            toBefehl.push_back(to);
            zeile++;
        } 
    }
    std::cout << stapel << "\nberechnen...";
    
    for(int i = 0; i < mengeBefehl.size(); i++){  
        //9000 1 Kiste pro Aktion - 9001 mehrere Kisten pro Aktion bewegen 

        //stapel.move9000(mengeBefehl[i],fromBefehl[i],toBefehl[i]);
        stapel.move9001(mengeBefehl[i],fromBefehl[i],toBefehl[i]);
    }
    std::cout << stapel;
}   