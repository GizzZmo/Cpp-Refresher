#include"Generic.cpp"
#include<bits/stdc++.h>

bool isCyclic(unordered_map<int,list<int>> um,vector<bool> &isVisited, int node, int parent) {
    isVisited[node] = true;
    for(auto edge:um[node]) {
        if(!isVisited[edge]) {
            if(isCyclic(um,isVisited,edge,node))
                return true;
        }
        else if(edge!=parent) {
            return true;
        }
    }
    return false;
}


int main() {
    GraphAdjList<int> graph;
    int numberVertices = 6;
    vector<bool> isVisited(numberVertices+1);
    graph.AddEdge(1,6,true);
    graph.AddEdge(1,2,true);
    graph.AddEdge(2,3,true);
    graph.AddEdge(3,4,true);
    graph.AddEdge(4,5,true);
    graph.AddEdge(5,2,true);
    
    graph.Print();

    bool isGraphCyclic = isCyclic(graph.getAdjList(),isVisited,1,0);
    if(isGraphCyclic)
        cout << "Cyclic";
    else
        cout << "Acyclic";

    return 0;
}