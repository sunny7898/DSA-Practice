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

int getMidElement(Node *head){
    // Case 1: When the length of linkedlist is odd.
    Node *lazy = head;
    Node *fast = head->next;
    while(fast){
        if (fast -> next == NULL)
            break;
        lazy = lazy -> next;
        fast = (fast -> next) -> next; 
    }

    return lazy->data;
}


int main() {
    Node *head = takeInput();
    print(head);
    int mid = getMidElement(head);
    cout << mid;
}