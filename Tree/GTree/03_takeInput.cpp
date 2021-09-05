#include<bits/stdc++.h>
using namespace std;

template <class T>
class  Node {
public: 
  T data;
  vector<Node<T> *> children;

  Node (T data){
    this -> data = data;
  }
};

void printTree(Node<int> *node){
  cout << node->data <<": ";
  for(Node<int> *child: node->children){
    cout << child->data <<", " ;
  }
  cout << ".\n";

  for(Node<int> *child: node->children){
    printTree(child);    
  }
}
Node<int>* takeInput(){
  
  int rootData;
  cout << "Enter root data: ";
  cin >> rootData;
  Node<int> *root = new Node<int> (rootData);

  int numChild;
  cout << "Number of children: ";
  cin >> numChild;
  for(int i=0; i<numChild; i++){
    Node<int> *child = takeInput();
    root->children.push_back(child);
  }
  return root;
}

int main() {
    Node<int> *root = takeInput();
    printTree(root);
    return 0;
}