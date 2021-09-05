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

void levelOrderLineWiseAlternating(Node *root){
    stack<Node*> ms;
    stack<Node*> cs;
    int level = 1; 
    ms.push(root);


    while (!ms.empty()){
        
        Node *top = ms.top();
        ms.pop();
        cout << top->data <<" ";

        if (level & 1){
            for(int i=0; i<top->children.size(); i++){
                cs.push(top->children[i]);
            }
        }
        else {
            for(int i=top->children.size()-1; i>=0; i--){
                cs.push(top->children[i]);
            }
        }

        if (ms.empty()){
            ms = cs;
            cs = stack<Node*>();
            level++;
            cout << "\n";
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
    levelOrderLineWiseAlternating(root);
}