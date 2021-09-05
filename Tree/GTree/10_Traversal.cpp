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

void traversal(Node *root){
    /* This line runs when we pass the left side
       of the node.
    */
    cout << "Node Pre " << root->data <<"\n";  
    
    for(Node *child: root->children){
        
        /* This line runs when we pass the left 
           side edge between two nodes.
        */
        cout << "Edge Pre " << root->data <<"--" << child->data <<"\n";

        traversal(child);


        /* This line runs when we pass the right 
           side edge between two nodes.
        */
        cout << "Edge Post " << root->data <<"--" << child->data <<"\n";
    }

    /* This line runs when we pass the right  
       side of the node
    */
    cout << "Node Post " << root->data <<"\n";  
}

void preOrder(Node *root){
    cout << root->data <<" "; 
    for(Node *child: root->children){
        preOrder(child);
    }
}

void postOrder(Node *root){
    for(Node *child: root->children){
        postOrder(child);
    }
    cout << root->data <<" "; 
}


int main(){
    int n; cin >> n;
    vector<int> arr;
    for(int i=0; i<n; i++){
        int ele; cin >> ele;
        arr.push_back(ele);
    }

    Node *root = buildTree(arr);
   // traversal(root);
    cout << "\n";
    preOrder(root);
    cout << "\n";
    postOrder(root);
}