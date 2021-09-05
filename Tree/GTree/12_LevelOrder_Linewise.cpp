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

void levelOrderLineWise(Node *root){
    queue<Node*> parentq;
    queue<Node*> childq;
    
    parentq.push(root);

    while (!parentq.empty() || !childq.empty()){
        Node *front = parentq.front();
        parentq.pop();
        
        cout << front->data <<" ";
        for(int i=0; i<front->children.size(); i++){
            childq.push(front->children[i]);
        }

        if (parentq.empty()){
            cout << "\n";
            parentq = childq;
            childq = queue<Node*>();
        }
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
    levelOrderLineWise(root);
}