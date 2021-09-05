#include<iostream>
#include<vector>
using namespace  std;

vector<int> visited;

void addEdge(vector<int> adjList[], int node1, int node2){
    adjList[node1].push_back(node2);
    adjList[node2].push_back(node1);
}

void dfs(vector<int> adjList[], int vertex){    
    visited[vertex] = 1;
    cout << vertex <<"-> ";
    for(auto it: adjList[vertex]){
        if (!visited[it])
            dfs(adjList, it);
    }
}
    
int main(){
    int num_of_nodes, num_of_edges;
    cin >> num_of_nodes >> num_of_edges;
    
    for(int i=1; i<=num_of_nodes; i++)
        visited.push_back(0);
    
    vector<int> adjList[num_of_nodes + 1];
    int node1, node2;

    for(int i=1; i<=num_of_edges; i++){
        cin >> node1 >> node2;
        addEdge(adjList, node1, node2);
    }
    for(int i=1; i<=num_of_nodes; i++){
        if(!visited[i])
            dfs(adjList, i);
    }
}