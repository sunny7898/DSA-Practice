#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

class  Solution {
    bool bipartiteBFS(int vertex, vector<int> adjList[], int color[]){
        queue<int> q;
        q.push(vertex);
        color[vertex] = 1;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(auto it: adjList[curr]){
                if (color[it] == -1){
                    color[it] = 1 - color[curr];
                    q.push(it);
                }
                else if (color[it] == color[curr])
                    return false;
            }
        }
        return true;
    }
public:
    bool checkBipartite(vector<int> adjList[], int N){
        int color[N+1];
        memset(color, -1, sizeof(color));

        for(int i=1; i<=N; i++){
            if (color[i] == -1){
                if (!bipartiteBFS(i, adjList, color))
                    return false;
            }
        }
        return true;
    }
};

int main(){
    int num_of_nodes, num_of_edges;
    cin >> num_of_nodes >> num_of_edges;

    vector<int> adjList[num_of_nodes+1];
    for(int i = 1; i <= num_of_edges; i++){
        int node1, node2; 
        cin >> node1 >> node2;
        adjList[node1].push_back(node2);
        adjList[node2].push_back(node1);
    }

    Solution obj;
    if (obj.checkBipartite(adjList, num_of_nodes)) 
        cout << "yes";
    else 
        cout << "no";

}