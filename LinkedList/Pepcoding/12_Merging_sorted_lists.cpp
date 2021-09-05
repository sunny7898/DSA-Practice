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

    int mid () {
        Node *slow = head;
        Node *fast = head;

        while (fast -> next){
            if ((fast -> next) -> next == NULL)
                break;
            slow = slow -> next;
            fast = (fast -> next)-> next;

        }
        return slow -> data;
    }

    LinkedList* mergeTwoSortedLists(LinkedList l1, LinkedList l2) {
        Node *temp1 = l1.head;
        Node *temp2 = l2.head;
        LinkedList *res = new LinkedList();
        
        while (temp1 && temp2){
            if (temp1 -> data > temp2 -> data){
                res -> addLast(temp1->data);
                temp1 = temp1 -> next;
            }
            else {
                res -> addLast(temp2 -> data);
                temp2 = temp2 -> next;
            }
        }   

        if (temp1){
            while (temp1){
                res -> addLast(temp1->data);
                temp1 = temp1 -> next;
            }
        }
        else if (temp2){
            while (temp2){
                res -> addLast(temp2 -> data);
                temp2 = temp2 -> next;
            }
        }
        return res;    
    }
    
};

int main(){
    LinkedList *l1 = new LinkedList();
    LinkedList *l2 = new LinkedList();

    int num1; cin >> num1;
    while (num1--){
        int data; cin >> data;
        l1 -> addLast(data);
    }
    int num2; cin >> num2;
    while (num2--){
        int data; cin >> data;
        l2 -> addLast(data);
    }
    LinkedList *merged = 
}