#include<bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  vector<Node*> children;

  Node (int data){
    this -> data = data;
  }
};

void printTree(Node *node){

  if (node == NULL) // not a base case. 
    return;
  cout << node -> data << "-> ";
  for(Node *n: node->children){
    cout << n->data << ", ";
  }
  cout << ".\n";

  for(Node *n: node->children)
    printTree(n);
}

int main() {
  Node *root = new Node(1);
  Node *child1 = new Node(2);
  Node *child2 = new Node(3);

  root->children.push_back(child1);
  root->children.push_back(child2);
  printTree(root);
  return 0;
}