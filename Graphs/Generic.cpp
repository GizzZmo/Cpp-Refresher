#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template <typename T>
class GraphAdjList {
    private:
        unordered_map<T, list<T>> adjList;

    public:
        GraphAdjList(){
        }
        
        unordered_map<T, list<T>> getAdjList() {
            return adjList;
        }

        void AddEdge(T u, T v, bool bidir=true) {
            adjList[u].push_back(v);
            if(bidir) {
                adjList[v].push_back(u);
            }
        }
        void Print() {
            for(auto itr:adjList) {
                cout << itr.first << "->" ;
                for(auto value: itr.second) {
                    cout << value << "," ;
                }
                cout << endl;
            }
        }
};