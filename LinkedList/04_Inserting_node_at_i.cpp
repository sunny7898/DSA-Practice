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

Node* insertNode(Node *head, int data, int pos){
    Node *node = new Node(data);
    if (pos == 1){
        node -> next = head;
        head = node;
    }
    else if (pos > 1){
        Node *temp = head;
        while (pos > 2){
            temp = temp -> next;
            pos--;
        }
        node -> next = temp -> next;
        temp -> next = node;
    }
    return head;
}


int main() {
    Node *head = takeInput();
    print(head);
    head = insertNode(head, 5, 1);
    print(head);

}