#include<iostream>
#include<list>
#include<queue>

using namespace std;

class AdjacencyList
{
private:
    int V;
    list<int> *adjList;
public:
    AdjacencyList(int v);
    void AddNode(int u, int v, bool bidir);
    void PrintEdges();
    void BFS(int src);
};

AdjacencyList::AdjacencyList(int v)
{   
    V = v;
    adjList = new list<int>[V];
}

void AdjacencyList::AddNode(int u, int v, bool bidir=true) {
    adjList[u].push_back(v);
    if(bidir) {
        adjList[v].push_back(u);
    }
}

void AdjacencyList::PrintEdges() {
    for(int i=0;i<V;i++) {
        cout << i << " -> " ;
        for(auto node:adjList[i]) {
            cout << node << ",";
        }
        cout << endl;
    }
}

void AdjacencyList::BFS(int src) {
    bool *visited = new bool[V+1]{false};
    int *dist  = new int[V+1]{0};
    int *parent = new int[V+1]{-1};
    queue<int>q;
    q.push(src);

    visited[src] = true;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int neighbor: adjList[node]) {
            if(!visited[neighbor]) {
                q.push(neighbor);
                dist[neighbor] = dist[node]+1;
                parent[neighbor] = node;
            }
            visited[neighbor] = true;
        }
    }

    cout <<endl;
    for(int i=0;i<V;i++) {
        cout << i << " at " << dist[i] << endl;
    }

    cout << "Shortest path for node 5" <<endl;
    int temp = 5;
    while(temp!=-1) {
        cout << temp << "<-" << "\t";
        temp = parent[temp];
    }
}

int main() {
    AdjacencyList adjacencyList(6);
    adjacencyList.AddNode(0,1);
    adjacencyList.AddNode(1,2);
    adjacencyList.AddNode(0,4);
    adjacencyList.AddNode(2,4);
    adjacencyList.AddNode(3,4);
    adjacencyList.AddNode(3,2);
    adjacencyList.AddNode(3,5);
    adjacencyList.PrintEdges();
    adjacencyList.BFS(0);
    return 0;
}

