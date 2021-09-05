#include<bits/stdc++.h>
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
void print(Node *head){
    while(head){
        cout << head -> data << " ";
        head = head -> next; 
    }
}

Node* takeInput(){
    Node *head = NULL; 
    Node *tail = NULL; 
    char ch = 'y';
    
    do {
        cout << "Enter data: ";
        int data; cin >> data;
        Node *node = new Node(data);
        
        if (head == NULL)
            head = node; 
        else 
            tail -> next = node ;
        tail = node;
        
        cout << "Do you want to continue(Y/N) : ";
        cin >> ch;
    }while(ch == 'Y' || ch == 'y');
   
    return head;
}

int main() {
    Node *head = takeInput();
    print(head);
}