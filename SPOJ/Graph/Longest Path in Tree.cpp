// PT07Z - Longest path in a tree

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define MOD 1000000007
#define REP(i,n) for(int i=1;i<=n;i++)

int visited [10001];
vi graph[10001];
int N;

void dfs(int &tempNode,int depth, int node, int &maxDepth) {
    visited[node] = 1;
    for(int i=0;i<graph[node].size();i++) {
        if(!visited[graph[node][i]]) {
            visited[graph[node][i]] = 1;
            if(depth+1 > maxDepth) {
                maxDepth = depth+1;
                tempNode = graph[node][i];
            }
            dfs(tempNode,depth+1,graph[node][i],maxDepth);
        }
    }
}

int main() {
    cin >> N;
    int edgeA, edgeB;
    int root=0;
    REP(i,N-1) {
        cin >> edgeA >> edgeB;
        if(i==1)
            root = edgeA;
        graph[edgeA].push_back(edgeB);
        graph[edgeB].push_back(edgeA);
    }
    int tempNode = 0;
    int diaMeter = INT_MIN;
    dfs(tempNode,0,root,diaMeter);
    diaMeter = INT_MIN;
	REP(i,N) {
        visited[i] = 0;
	}
	dfs(tempNode,0,tempNode,diaMeter);
	cout << diaMeter;
	return 0;
}

