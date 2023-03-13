#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Stack {      

  public: 
    std::vector<char>stapel[9];

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
};

std::ostream& operator<<(std::ostream &s, const Stack &stack) {
    s <<"Stack: ";
    int i = 0;
    while(i < 9){
        s <<i<<": ";
        for(int n = 0; n < stack.stapel[i].size(); n++){
            s <<stack.stapel[i].at(n)<< " ";
        }
        s <<"\n";
        i++;
    }
    return s;
}

int main()
{
    /*std::vector<char> stack1 = {'R','G','J','B','T','V','Z'};std::vector<char> stack2 = {'J','R','V','L'};
    std::vector<char> stack3 = {'S','Q','F'};std::vector<char> stack4 = {'Z','H','N','L','F','V','Q','G'};
    std::vector<char> stack5 = {'R','Q','T','J','C','S','M','W'};std::vector<char> stack6 = {'S','W','T','C','H','F'};
    std::vector<char> stack7 = {'D','Z','C','V','F','N','J'};std::vector<char> stack8 = {'L','G','Z','D','W','R','F','Q'};
    std::vector<char> stack9 = {'J','B','W','V','P'};*/
    int menge; int from; int to;
    std::vector<int> mengeBefehl;
    std::vector<int> fromBefehl;
    std::vector<int> toBefehl;

    Stack stapel = Stack();

    std::ifstream fileread ( "Kisten.txt" );
    if(!fileread){std::cerr<<"\nFehler. Datei wird nicht gelesen.\n";}

    if(fileread.is_open()){
        int i = 1;
        int zeile = 11;
        std::cout << "File geoeffnet ... ";
        while(i != zeile){
            fileread.ignore(1000, '\n');
            ++i;
        }

        std::cout << "zu Zeile 11"<<std::endl;
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

            //std::cout <<"Zeile: "<<zeile<<" eingelesen " <<menge<<" "<<from<<" "<<to<<std::endl;
            zeile++;
        } 
        std::cout << "Fertig eingelesen: "<<std::endl;
    }
    std::cout << stapel;
    /*
    for(int i = 0; i < mengeBefehl.size(); i++){  
        std::cout << " Move " << mengeBefehl[i] << " from " << fromBefehl[i] << " to " << toBefehl[i];
    }
    */
    return 0;
}