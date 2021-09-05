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
    int data; cin >> data;
    
    while  (data != -1) {
        Node *node = new Node(data);
        if (head == NULL)
            head = node; 
        else 
            tail -> next = node ;
        tail = node;
        cin >> data;
    }
   
    return head;
}

Node* deleteNode(Node *head, int pos) {
    Node *temp = head;
    if (pos == 1){
        head = head -> next;
        delete(temp);
    }
    else {
        int i = 1; 
        while (i < pos-1){
            temp = temp -> next;
            i++;
        }
        Node *deletednode = temp -> next;
        temp -> next = deletednode -> next;
        delete deletednode;
    }
    return head;
}

int main() {
    Node *head = takeInput();
    print(head);
    head = deleteNode(head, 1);
    print(head);
}