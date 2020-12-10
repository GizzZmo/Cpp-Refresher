#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define REP(i,n) for(int i=0;i<n;i++)
vi graph[100001];
vi in(100001);
vi low(100001);
int timer;
vi visited(100001);
bool hasBridge;
vector<pair<int, int>> edgeList;

void dfs(int node, int parent) {
    visited[node]=1;
    in[node] = low[node] = timer++;

    for(auto child:graph[node]) {
        if(child==parent)
            continue;
        else if(visited[child]) {
            low[node] = min(low[node],low[child]);
            if(in[node]>in[child])
                edgeList.push_back(make_pair(node,child));
        }
        else {
            dfs(child,node);
            if(low[child]>in[node]) {
                hasBridge=true;
                return;
            }
            low[node] = min(low[node],low[child]);
            edgeList.push_back(make_pair(node,child));
        }
    }  
}

int main() {
    int n,m;
    cin >> n >> m;
    
    REP(i,m) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1,-1);
    if(hasBridge) {
        cout << "0" << endl;
        return 0;        
    }
    for(auto p:edgeList) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}