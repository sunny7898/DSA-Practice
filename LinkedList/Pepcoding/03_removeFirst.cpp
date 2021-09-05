#include<iostream>
#include<string>
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
    int size = 0;

    int listSize(){
        return size;
    }
    void addLast(int data){
        Node *node = new Node(data);
        if (head == NULL)
            head = node;
        else 
            tail -> next = node;
        tail = node;
        size++;
    }

    void display(){
        Node *temp = head ;
        while (temp){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << "\n";
    }

    void removeFirst(){
        if (head == NULL)
            cout << "List is empty\n";
        else if (head == tail){
            delete(head);
            head = NULL;
            tail = NULL;
        }
        else {
            Node *temp = head;
            head = head -> next;
            delete(temp);
        }
        size--;
    }
};

int main(){
    Linkedlist *list = new Linkedlist();
    string str; getline(cin, str);
    while (str != "quit"){
        if (str.find("addLast") != string::npos){
            string res = str.substr(str.find(" ") + 1);
            int data = stoi(res);
            list -> addLast(data);
        } 
         if (str == "display")
            list -> display();
        else if (str == "size")
            cout << list -> listSize() <<"\n";
        else if (str == "removeFirst")
            list -> removeFirst();
        getline(cin, str);
    }
}