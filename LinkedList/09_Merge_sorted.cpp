#include<iostream>
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

Node* takeInput(){
    Node *head = NULL;
    Node *tail = NULL; 

    int data; cin >> data;
    while (data != -1){
        Node *node = new Node(data);
        if (head == NULL)
            head = node;
        else 
            tail -> next = node;
        tail = node;
        cin >> data;
    }
    return head;
}
void print(Node *head){
    while (head){
        cout << head -> data <<" ";
        head = head -> next;
    }
    cout << "\n";
}

Node* mergeLL(Node *head1, Node *head2){
    Node *temp1 = head1;
    Node *temp2 = head2;
    
    Node *head3 = NULL;
    Node *tail3 = NULL;
    
    while(temp1 && temp2){
        Node *node; 
        if (temp1->data < temp2->data){
            node = new Node(temp1->data);
            temp1 = temp1 -> next;
        }
        else {
            node = new Node(temp2->data);
            temp2 = temp2 -> next;
        }
        
        if (head3 == NULL)
            head3 = node;
        else 
            tail3 -> next = node;
        tail3 = node;
    }

    if (temp1 != NULL){
        while (temp1){
            Node *node = new Node(temp1->data); 
            tail3 -> next = node;
            tail3 = node;
            temp1 = temp1->next;
        }
    }
    else if (temp2 != NULL){
        while (temp2){
            Node *node = new Node(temp2->data);
            tail3 -> next = node;
            tail3 = node;
            temp2 = temp2->next;
        }
    }
    return head3;
}


int main() {
    Node *head1 = takeInput();
    Node *head2 = takeInput();

    Node *head3 = mergeLL(head1, head2);
    print(head3);
}