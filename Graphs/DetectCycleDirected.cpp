// Detect cycle in a directed graph
#include"Generic.cpp"
#include<bits/stdc++.h>

bool isCyclicUtil(unordered_map<int,list<int>> &umap, vector<bool> &isVisited, int secondVertex) {
    if(isVisited[secondVertex])
        return true;
    isVisited[secondVertex] = true;
    for(auto edge:umap[secondVertex]) {
        if(isCyclicUtil(umap, isVisited, edge)) {
            return true;
        }
    }
    isVisited[secondVertex] = false;
    return false;

}

bool isCyclic(unordered_map<int,list<int>> umap) {
    vector<bool> isVisited(umap.size(),false);
    for(auto pairVertexEdge : umap) {
        isVisited[pairVertexEdge.first] = true;
        for(auto edge:pairVertexEdge.second) {
            if(isCyclicUtil(umap, isVisited, edge))
                return true;
        }
        isVisited[pairVertexEdge.first] = false;
    }
    return false;
}

int main() {
    GraphAdjList <int> graph;
    graph.AddEdge(1,0,false);
    graph.AddEdge(2,6,false);
    graph.AddEdge(1,7,false);
    graph.AddEdge(6,4,false);
    graph.AddEdge(7,0,false);
    graph.AddEdge(0,5,false);

    graph.Print();

    bool cyclic = isCyclic(graph.getAdjList()) ;
    cout << (cyclic ? "Cyclic" : "Acyclic");

    return 0;

}
