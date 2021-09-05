#include <iostream>
using namespace std;

void printPermutations(string str, string asf){

    if (str.length() == 0){
        cout << asf << "\n";
        return;
    }

    for(int i=0; i<str.length(); i++){
        char ch = str[i];
        string rstr = str;
        rstr.erase(i, 1);

        printPermutations(rstr, asf + ch);
    }
}

int main(){
    string str;
    cin>>str;
    printPermutations(str,"");
    
}