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
    string *save = new string[1000];
public:
    void openfile(){inpt.open("main.cpp");}
    void showclass(){
        openfile();
        int count = 0;
        while(getline(inpt, line)){
            if((line[0] == 'c' && line[1] == 'l'))count++;
            
        }
        cout << count << " classes in main.cpp" << endl;
        inpt.close();
        openfile();
        while(getline(inpt, line)){
            if((line[0] == 'c' && line[1] == 'l'))cout << line << endl;
        }
        inpt.close();
    }
};
int main() {
    ReadClass rfile;
    rfile.showclass();
    return 0;
}
