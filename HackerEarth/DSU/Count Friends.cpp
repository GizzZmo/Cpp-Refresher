#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define REP(i,n) for(int i=1;i<=n;i++)

vi parent(100001);

int find(int node) {
    if(parent[node]<0)
        return node;
    return parent[node] = find(parent[node]);
}

void disjointUnion(int nodeA, int nodeB) {
    int a = find(nodeA);
    int b = find(nodeB);

    if(a!=b) {
        parent[b] += parent[a];
        parent[a] = b;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    REP(i,n) {
        parent[i] = -1;
    }
    while(m--) {
        int u, v;
        cin >> u >> v;
        disjointUnion(u,v);
    }
    REP(i,n) {
        if(parent[i]==-1) {
            cout << 0 << " ";
            continue;
        }
        cout <<  abs(parent[find(i)])-1 << " ";
    }
    return 0;
}
