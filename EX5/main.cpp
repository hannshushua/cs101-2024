#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class myString{

private:
    string my_str;
public:
    myString(string s){
        my_str = s;
    }
};

class ReadClass{

private:
    ifstream inpt;
    string line;
    int count = 0;
    string save[1000];
public:
    void openfile(){inpt.open("main.cpp");}
    void closefile(){inpt.close();}
    void showclass(){
        openfile();
        int count = 0;
        while(getline(inpt, line)){
            if((line[0] == 'c' && line[1] == 'l')){
                save[count] = line;
                count++;
            }
        }
        cout << count << " classes in main.cpp" << endl;
        closefile();
        for(int i = 0 ; i < count ; i++){cout << save[i] << endl;}
        
    }
};
int main() {
    ReadClass rfile;
    rfile.showclass();
    return 0;
}
