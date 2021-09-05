#include<iostream>
#include <string>
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

Node *takeInput(){
    Node *head = NULL;
    Node *tail = NULL;
    string str = "";
    while (str != "quit"){
        getline(cin, str);
        if (str == "quit")
            break;

        string res = str.substr(str.find(" ")+1);
        int data = (stoi(res));
        Node *node = new Node(data);
        if (head == NULL)
            head = node ;
        else 
            tail -> next = node;
        tail = node;
    }
    return head;
}

void print(Node *head){
    while(head){
        cout << head -> data << "\n";
        head = head -> next;
    }
}

int count(Node *head){
    int cnt = 0;
    while(head){
        head = head->next;
        cnt++;
    }
    return cnt;
}

int main() {
    Node *head = takeInput();
    print(head);
    int cnt = count(head);
    cout << cnt <<"\n";
    Node *temp = head;
    if (head == NULL)
        return 0;
    while(temp->next){   // first check temp if it is not null
        temp = temp->next;
    }
    if (temp)
        cout << temp -> data;
}