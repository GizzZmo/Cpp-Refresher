#include<bits/stdc++.h>
using namespace std;

#define REP(i,m) for(int i=1;i<=m;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
#define vi vector<int>

vi graph[100001];
vi transpose[100001];
vi order, scc;
vi visited(100001);
vi result(100001);

void dfs(int node) {
    visited[node]=1;
    for(auto child:graph[node]) {
        if(!visited[child]) {
            dfs(child);
        }
    }
    order.push_back(node);
}

void dfs1(int node) {
    visited[node]=1;
    for(auto child:transpose[node]) {
        if(!visited[child])
            dfs1(child);
    }
    scc.push_back(node);
}

int main() {
    int n,m;
    cin >> n >> m;
    REP(i,n) {
        graph[i].clear();
        transpose[i].clear();
        visited[i]=0;
    }
    REP(i,m) {
        int edgeA, edgeB;
        cin >> edgeA >> edgeB;
        graph[edgeA].push_back(edgeB);
        transpose[edgeB].push_back(edgeA);
    }
    order.clear();
    REP(i,n) {
        if(!visited[i])
            dfs(i);
    }
    REP(i,n) {
        visited[i]=0;
        result[i]=0;
    }

    reverse(order.begin(), order.end());
    for(auto node:order) {
        scc.clear();
        if(!visited[node]) {
            dfs1(node);
        }
        if(scc.size()>1) {
            for(int j=0;j<scc.size();j++) {
                result[scc[j]]=1;
            }
        }
    }
    REP(i,n) {
        cout << result[i] << " ";
    }
    return 0;
}
