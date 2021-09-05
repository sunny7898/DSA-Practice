#include<bits/stdc++.h>
using namespace std;

template <class T>
class Node {
  public:
    int data;
    vector<Node<T>*> children;

    Node(T data){
      this -> data = data;
    }
};

Node<int>* takeInputLevelWise(){
  cout << "Enter root data: ";
  int rootData; cin >> rootData;
  Node<int> *root = new Node<int>(rootData);

  queue<Node<int>*> pendingNodes;
  pendingNodes.push(root);

  while(!pendingNodes.empty()){

    Node<int> *front = pendingNodes.front();
    pendingNodes.pop();

    cout << "Enter num of children of " << front->data <<": ";
    int numChild; cin >> numChild;
    
    for(int i=0; i<numChild; i++){
      cout << "Enter the " << i+1 << "th child of " << front->data <<": ";
      int childData; cin >> childData;
      
      Node<int> *child = new Node<int> (childData);
      front->children.push_back(child);

      pendingNodes.push(child);
    }   
  }
  return root;
}

void printTreeLevelWise(Node<int> *root){
  queue<Node<int>*> pendingNodes;
  pendingNodes.push(root);

  while(!pendingNodes.empty()){

    Node<int> *front = pendingNodes.front();
    pendingNodes.pop();
    cout << front->data << ": ";

    for(Node<int> *child: front->children){
      cout << child -> data << ", ";
      pendingNodes.push(child);
    }
    cout << "\n";
  }
}


int main() {
    Node<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    return 0;
}