#include<iostream>
#include<list>
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

int main() {
    AdjacencyList adjacencyList(3);
    adjacencyList.AddNode(0,1);
    adjacencyList.AddNode(0,2);
    adjacencyList.AddNode(1,2);
    adjacencyList.PrintEdges();
    return 0;
}

