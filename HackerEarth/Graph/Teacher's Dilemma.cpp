#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define REP(i,n) for(int i=1;i<=n;i++)
#define MOD 1000000007

vi arr(100001,-1);

int find(int node) {
    if(arr[node]<0)
        return node;
    return arr[node] = find(arr[node]);
}

void un(int node1, int node2) {
    arr[node1] += arr[node2] ;
    arr[node2] = node1;
}

int main() {
    int n, m;
    cin >> n >> m;

    long long int result=1;

    while(m--) {
        int u, v;
        cin >> u >> v;
        int b = find(v);
        int a = find(u);

        if(a!=b) {
            un(a,b);
        }
    }

    REP(i,n) {
        if(arr[i]<0) {
            result = (result * abs(arr[i]))%MOD ;
        }
    }

    cout << result;
        return 0;
}
