#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define REP(i,n) (int i=1;i<=n;i++)

vi parent(100001, -1);

int find(int node) {
    if(parent[node]<0)
        return node;
    return find(parent[node]);
}

void disjointUnion(int node1, int node2) {
    int a = find(node1);
    int b = find(node2);

    if(a!=b) {
        if(a<b) {
            parent[b] += parent[a];
            parent[a] = b;
        }
        else {
            parent[a] += parent[b];
            parent[b] = a;
        }
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    while(m--) {
        int u,v;
        cin >> u >> v;
        disjointUnion(u,v);
    }
    int q;
    cin >> q;
    while(q--) {
        int u,v;
        cin >> u >> v;
        if(find(u)==find(v)) {
            cout << "TIE";
        }
        else if(find(u)<find(v)) {
            cout << v;
        }
        else {
            cout << u;
        }
        cout << endl;
    }
    return 0;
}
