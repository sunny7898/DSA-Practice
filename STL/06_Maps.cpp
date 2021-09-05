#include<iostream>
#include<map>
#include<string>
using namespace  std;

int main() {

    map<int, int> m1{ {1,2}, {2,3}, {3,4} };
   
    map<string, int> m2;
    m2["Harrx"] = 98;
    m2["Harry"] = 87;
    m2["Harrz"] = 97;

    map<char, int> m3 (m1.begin(), m1.end());

    map<char, int> m4 (m1);
    
    map<string, int> :: iterator itr;
    for(itr = m2.begin(); itr != m2.end(); itr++){
        cout << (*itr).first << ": " << (*itr).second <<"\n";
    }

    cout <<m2.size(); 
    cout <<m2.max_size(); 

    return 0;
}