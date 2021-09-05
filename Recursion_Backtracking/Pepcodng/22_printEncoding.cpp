#include<bits/stdc++.h>
using namespace std;

void printEncoding(string str, string asf){
    
    if (str.length() == 0){
        cout << asf << "\n";
        return;
    }
    else if (str.length() == 1){
        char ch = str[0];
        if (ch == '0')
            return ;
        else{
            int codeIdx = (ch - '0') - 1 ;
            asf += char('a' + codeIdx);
            cout << asf << "\n";
            return; 
        } 
    }
    else {
        // One character at a time
        char ch = str[0];
        string roq = str.substr(1);
        if (ch == '0')
            return;
        else {
            int ch1v = (ch - '0') - 1;
            char code = char('a' + ch1v);
            printEncoding(roq, asf + code);
        }

        // Two characters at a time: 
        string ch12 = str.substr(0, 2);
        string roq12 = str.substr(2);
        
        int ch12v = stoi(ch12) - 1 ;
        if (ch12v <=26){
            char code = char('a' + ch12v);
            printEncoding(roq12, asf + code);
        }
    }
}

int main(){
    string str;
    cin>>str;
    printEncoding(str,"");
    
}