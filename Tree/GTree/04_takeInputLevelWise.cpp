#include<bits/stdc++.h>
using namespace std;

template<class T>
class Node {
  public:
    T data;
    vector<Node<T>*> children;

    Node(T data){
      this -> data = data;
    }
};

void printTree(Node<int> *node){
  cout << node->data << ": ";
  for(Node<int> *n : node->children)
    cout << n->data <<", ";
  cout << ".\n";
  
  for(Node<int> *child: node->children)
    printTree(child);
}

Node<int>* takeInputLevelWise(){
  int rootData;
  cout << "Enter root data: ";
  cin >> rootData;
  Node<int> *root = new Node<int>(rootData);
  
  queue<Node<int>*> q;
  q.push(root);

  while(!q.empty()){
    Node<int> *front = q.front();
    q.pop();

    int numChild; 
    cout << "Enter num of children of " << front ->data << ": ";
    cin >> numChild;
    for(int i=0; i<numChild; i++){
      
      cout << "Enter " << i+1 <<"th child of " << front->data <<": ";
      int childData; cin >> childData;
      // Child node creation
      Node<int> *child = new Node<int>(childData);
      // Connecting the children to their parent
      front->children.push_back(child);
      // Pushing in the queue.
      q.push(child);
    }
  }

  return root;
}

int main() {
    Node<int> *root = takeInputLevelWise();
    printTree(root);
    return 0;
}