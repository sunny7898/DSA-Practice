#include<iostream>
#include <string>
using namespace std;
class Node {
    public: 
    int data;
    Node *next;

    Node (int data) {
        this -> data = data; 
        next = NULL;
    }
};
class Linkedlist {
    public:
    Node *head = NULL;
    Node *tail = NULL;
    int sze = 0; 

    void addLast(int data){
        Node *node = new Node(data);
        if (head == NULL)
            head = node ;
        else 
            tail -> next = node;
        tail = node;
        sze++;
    }

    void display(){
        Node *temp = head;
        while(temp){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << "\n";
    }
    int size(){
        return sze;    
    }
};

int main() {
    Linkedlist *list = new Linkedlist();
    string str = ""; getline(cin, str);
    while (str != "quit"){
        
        if (str.find("addLast") == 0){
            string res = str.substr(str.find(" ")+1);
            int data = (stoi(res));
            list->addLast(data);
        }
        else if (str == "display")
            list->display();
        else if (str == "size"){
            int sze = list->size(); 
            cout << sze << "\n";
        }
        getline(cin, str);
    }
}