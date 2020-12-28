#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=1;i<=n;i++)
#define vi vector<int>

vi lands(100001);

int find(int node) {
    if(lands[node]<0)
        return node;
    return lands[node] = find(lands[node]);
}

void disjointUnion(int nodeA, int nodeB) {
    int a = find(nodeA);
    int b = find(nodeB);

    if(a!=b) {
        lands[a] += lands[b];
        lands[b] = a ;
    }
}

int main() {
    int n,k;
    cin >> n >> k;
    REP(i,n) {
        lands[i] = -1;
    }
    while(k--) {
        int u,v;
        cin >> u >> v;
        disjointUnion(u,v);
    }
    int result = 0;
    REP(i,n) {
        if(lands[i]<0)
            result++;
    }
    cout << result;
    return 0;
}