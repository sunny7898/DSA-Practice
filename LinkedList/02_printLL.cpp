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
        cout << head->data << " ";
        head = head->next;
    }
}
int main() {
    Node n1(1);
    Node n2(2);
    n1.next = &n2;
    Node *head = &n1;
    Node *tail = &n2;
    print(head);
    print(head);
}
