#include<iostream>
#include<vector>
using namespace std;

template <class T>
class Node {
public:
  T data;
  vector<Node<T>*> children;

  Node (T data){
    this -> data = data;
  }
};

void display(Node<int>* node){
  cout << node->data << " ";
  for(Node<int> *n: node->children){
    display(n);
  }
}

int main(){
  Node <int> *root = new Node<int> (1);
  Node <int> *child1 = new Node<int> (2);
  Node <int> *child2 = new Node<int> (3);

  root->children.push_back(child1);
  root->children.push_back(child2);

  display(root);
}