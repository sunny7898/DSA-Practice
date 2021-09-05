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

int main() {
    // Static
    Node n1(1);
    Node n2(2);
    n1.next = &n2;
    Node *head = &n1;
    Node *tail = &n2;
    cout << (head -> data) << " " << (tail -> data);

    //Dynamically
    Node *n3 = new Node(1);
    Node *n4 = new Node(2);
    n3 -> next = n4;
    Node *head1 = n3;
    Node *tail1 = n4;
    cout << (head -> data) << " " << (tail -> data);
}
