#include<iostream>
#include<string>
using namespace std;

class Node {
    public:
    int data; 
    Node *next;
    Node (int data){
        this -> data = data;
        next = NULL;
    }
};

class LinkedList {
    public:
    Node *head; 
    Node *tail;
    int size;

    LinkedList (){
        head = tail = NULL;
        size = 0;
    }

    void display(){
        Node *temp = head;
        while(temp){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << "\n";
    }

    int listSize(){
        return size;
    }  
    void addFirst(int data){
        Node *node = new Node(data);
        if (head == NULL){
            head = tail = node ;
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
    void addAt(int idx, int data){
        if (idx < 0 || idx > size)
            cout << "Invalid arguments\n";
        else if (head == NULL || idx == 0){
            addFirst(data);
        }
        else if (idx == size)
            addLast(data);
        else {
            Node *node = new Node(data);
            int pos = 0; 
            Node *temp = head;
            while (pos < idx - 1){
                pos++;
                temp = temp -> next;
            }
            node -> next = temp -> next;
            temp -> next = node;
            size++;
        }
    }


    int getFirst(){
        if (head == NULL){
            cout << "List is empty\n";
            return -1;    
        }
        else {
            return head -> data;
        }
    }
    int getLast(){
        if (head == NULL){
            cout << "List is empty\n";
            return -1; 
        }
        else {
            return tail -> data;
        }
    }
    int getAt(int idx){
        if (head == NULL){
            cout << "List is empty\n";
            return -1;
        }
        if (idx < 0 || idx >= size){
            cout << "Invalid arguments\n";
            return -1; 
        }
        else if (idx == 0){
            int res = getFirst();
            return res;
        }
    
        Node *temp = head;
        while (idx--){
            temp = temp -> next;
        }
        return temp -> data;
    }

    void removeFirst(){
        if (head == NULL){
            cout << "List is empty\n";
        }
        else if (head == tail){
            delete(head);
            head = tail = NULL;
        }
        else {
            Node *temp = head;
            head = head -> next;
            delete(temp);
        }
        size--;
    }
    void removeLast(){
        if (head == NULL)
            cout << "List is empty\n";
        else if (head == tail){
            delete(head);
            head = tail = NULL;
        }
        else {
            Node *temp = head;
            while (temp -> next != tail){
                temp = temp -> next;
            }
            delete(tail);
            tail = temp;
        }
        size--;
    }

    void removeAt(int idx){
        if (head == NULL)
            cout << "List is empty\n";
        else if (idx < 0 || idx >= size)
            cout << "Invalid arguments\n";
        else if (idx == 0) 
            removeFirst();
        else {
            Node *temp = head;
            while (idx > 1){
                temp = temp -> next;
                idx--;
            }
            Node *t = temp -> next;
            temp -> next = t -> next;
            delete(t);
            size--;
            if (temp -> next == NULL)
                tail = temp;
        }
    }
// Reverses by changing the next property of a node: 
    void reversePI(){
        Node *prev = NULL;
        Node *curr = head;
        
        while (curr){
            Node *next = curr -> next;
            
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        Node *temp = head;
        head = tail;
        tail = temp;
    }

    int kthFromEnd(int k){
        Node *slow = head;
        Node *fast = head;

        while (k--){
            fast = fast -> next;
        }
        while (fast -> next){
            slow = slow -> next;
            fast = fast -> next;
        }
        return slow -> data;
    }
};

int main(){
    LinkedList *list = new LinkedList();
    string inp; getline(cin, inp);
    while (inp != "quit"){

        if (inp.find("addFirst") != string::npos){
            int data = stoi(inp.substr(inp.find(" ") + 1));
            list -> addFirst(data);
        }
        else if (inp.find("addLast") != string::npos){
            int data = stoi(inp.substr(inp.find(" ") + 1));
            list -> addLast(data);
        }
        else if (inp.find("addAt") != string::npos){
            string str = inp.substr(inp.find(" ") + 1);
            int idx = stoi(str);
            int data = stoi(str.substr(str.find(" ") + 1));
            list -> addAt(idx, data);
        }
        
        else if (inp == "display"){
            list -> display();
        }
        else if (inp == "size"){
            cout << list -> listSize() << "\n";
        }

        else if (inp.find("removeFirst") != string::npos){
            list -> removeFirst();
        }
        else if (inp.find("removeLast") != string::npos){
            list -> removeLast();
        }
        else if (inp.find("removeAt") != string::npos){
            int idx = stoi(inp.substr(inp.find(" ") + 1));
            list -> removeAt(idx);
        }

        else if (inp.find("getFirst") != string::npos){
            int res = list -> getFirst();
            if (res != -1)
                cout << res << "\n";
        }
        else if (inp.find("getLast") != string::npos){
            int res = list -> getLast();
            if (res != -1)
                cout << res << "\n";

        }
        else if (inp.find("getAt") != string::npos){
            int idx = stoi(inp.substr(inp.find(" ") + 1));
            int res = list -> getAt(idx);
            if (res != -1)
                cout << res << "\n";
            
        }
        else if (inp == "reversePI"){
            list -> reversePI();
        }
        else if (inp.find("kthFromEnd") != string::npos){
            int k = stoi(inp.substr(inp.find(" ") + 1));
            cout << list -> kthFromEnd(k) << "\n";
        }
        getline(cin, inp);
    }
}