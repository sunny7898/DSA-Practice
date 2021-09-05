#include<bits/stdc++.h>
using namespace std; 

class Node {
public:
    int data;
    vector<Node*> children;

    Node(int data){
        this->data = data;
    }
};
Node* buildTree(vector<int> arr){
    stack<Node*> st;
    Node *root;
    for(int it: arr){
        if (st.empty()){
            root = new Node(it);
            st.push(root);
        }
        else {
            if (it != -1){
                Node *child = new Node(it);
                st.top()->children.push_back(child);
                st.push(child);
            }
            else if (it == -1){
                st.pop();
            }
        }
    }
    return root;
}

void removeLeaves(Node *node){

  for(Node *child: node->children){
    removeLeaves(child);
  }

  for(int i=0; i<node->children.size(); i++){
    if ((node->children[i])->children.size() == 0){
        node->children.erase(node->children.begin()+ i);
    }
  }
}

void display(Node *root){
   
   cout << root->data <<" -> ";
   for(Node *child: root->children){
       cout << child -> data << ", ";
   }
   cout << ".\n";
   for(Node *child: root->children){
       display(child);
   }
}

int main(){
    int n; cin >> n;
    vector<int> arr;
    for(int i=0; i<n; i++){
        int ele; cin >> ele;
        arr.push_back(ele);
    }

    Node *root = buildTree(arr);
    removeLeaves(root);
}