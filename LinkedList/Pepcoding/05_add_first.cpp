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
    void addFirst(int data){
        Node *node = new Node(data);
        if (head == NULL){
            head = tail = node;
        }
        else {
            node -> next = head;
            head = node;
        }
        size++;
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
    void addAt(int idx, int val){
        Node *node = new Node(val);
        if (idx < 0 || idx > size)
            cout << "Invalid arguments\n";
        
        Node *temp;
        if (idx == 0){
            addFirst(val);
        }else {
            temp = head;
            int pos = 0;
            while(pos < idx-1){
                pos++;
                temp = temp -> next;
            }
            Node *t = temp -> next;
            node -> next = t;
            temp = node;
        }
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

    int getFirst(){
        if (head == NULL){
            return -1;
        }
        return head -> data;
    }

    int getLast(){
        if (head == NULL){
            return -1;
        }
        return tail -> data;
    }

    int getAt(int idx){
        if (idx < 0 || idx > size-1){
            cout << "Invalid arguments\n";
            return -1;
        }else if (head == NULL){
            cout << "List is empty\n";
            return -1;
        }

        Node *temp = head;
        while (idx){
            idx--;
            temp = temp->next;
        }
        return temp->data;
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
        
        else if (str == "getFirst"){
            int res = list -> getFirst();
            res == -1 ? cout << "List is empty" : cout << res; 
            cout << "\n";
        }
        
        else if (str == "getLast"){
            int res = list -> getLast();
            res == -1 ? cout << "List is empty" : cout << res; 
            cout << "\n";
        }
        
        else if (str == "removeFirst")
            list -> removeFirst();
        
        else if (str.find("getAt") == 0){
            string temp = str.substr(str.find(" ") + 1);
            int idx = stoi(temp);
            int res = list -> getAt(idx);
            if (res != -1)
                cout << res << "\n";
        }
        
        else if (str == "size")
            cout << list -> listSize() << "\n";
        
        else if (str == "display")
            list -> display();
        
        else if (str.find("addFirst") == 0){
            string res = str.substr(str.find(" ") + 1);
            int data = stoi(res);
            list->addFirst(data);
        }
        else if (str.find("addAt") == 0){
            string st1 = str.substr(str.find(" ")+1);
            int idx = stoi(""+st1[0]);
            string st2 = st1.substr(str.find(" ") + 1);
            int val = stoi(st2);
            list -> addAt(idx, val);
        }
        getline(cin, str);
    }
}