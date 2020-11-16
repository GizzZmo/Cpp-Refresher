// Subtree size
#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int i=1;i<=n;i++)
#define vi vector<int>

int visited[1001];
vi graph[1001];

void dfs(int node, vector<int> &subSize) {
    visited[node] = 1;
    for(auto child:graph[node]) {
        if(!visited[child]) {
            dfs(child,subSize);
            subSize[node] += subSize[child];
        }
    }
    subSize[node]+=1;
}

int main () {
    int N;
    cin >> N;
    vector<int> subSize(N+1);
    int root;
    REP(i,N-1) {
        int edgeA, edgeB;
        cin >> edgeA >> edgeB;
        if(i==1)
            root = edgeA;
        graph[edgeA].push_back(edgeB);
        graph[edgeB].push_back(edgeA);
    }
    dfs(root,subSize);
    REP(i,N) {
        cout << subSize[i] << "\t";
    }
    return 0;
}
