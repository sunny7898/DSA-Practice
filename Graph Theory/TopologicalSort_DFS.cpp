#include<iostream>
#include<vector>
#include<stack>
#include<cstring>
using namespace std;

class Solution {
private:
    void dfs(int vertex, vector<int> adjList[], int *visited, stack<int> &res){
        visited[vertex] = 1;

        for(int it: adjList[vertex]){
            if (!visited[it]){
                dfs(it, adjList, visited, res);
            }
        }
        res.push(vertex);
        return;
    }
public: 
    stack<int> topologicalSort(int N, vector<int> adjList[]){
        
        int visited[N+1] = {0};
        stack<int> res;
        
        for(int i=1; i<=N; i++){
            if (!visited[i]){
                dfs(i, adjList, visited, res);
            }
        }
        return res;
    }

    void addEdge(int node1, int node2, vector<int> adjList[]){
        adjList[node1].push_back(node2);
    }
    void print(vector<int> adjList[], int N){
        for(int i = 1; i<=N; i++){
            cout << i <<": ";
            for(int it: adjList[i]){
                cout << it <<"-> ";
            }
            cout <<"\n";
        }
    }

};

int main(){
    int T; cin >> T;
    while(T--){
        int num_of_nodes, num_of_edges;
        cin >> num_of_nodes >> num_of_edges;

        Solution obj;
        
        vector<int> adjList[num_of_nodes+1];
        int node1, node2;       
        for(int i=1; i<=num_of_edges; i++){
            cin >> node1 >> node2;
            obj.addEdge(node1, node2, adjList);
        }

        //obj.print(adjList, num_of_nodes);
        
        stack<int> res = obj.topologicalSort(num_of_nodes, adjList);
          
        while (res.size()){
            cout << res.top() <<" ";
            res.pop();       
        }
    }
}
/*
1
6 6
6 1
5 1
6 3
3 4
4 2
5 2
*/