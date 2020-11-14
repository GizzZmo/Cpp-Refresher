// Fire Escape Routes
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define MOD 1000000007
#define REP(i,n) for(int i=1;i<=n;i++)

int visited [100001];
vi graph[100001];
int drill;

void dfs(int node) {
    drill++;
    visited[node] = 1;
    for(int i=0;i<graph[node].size();i++) {
        if(!visited[graph[node][i]]) {
            dfs(graph[node][i]);
        }
    }
}

int main() {
    int testCases;
    cin >> testCases;
    while(testCases--) {
        int emp, relations;
        cin >> emp >> relations;
        REP(i,emp) {
            visited[i]=0;
            graph[i].clear();
        }
        REP(i,relations) {
            int edgeA,edgeB;
            cin >> edgeA >> edgeB;
            graph[edgeA].push_back(edgeB);
            graph[edgeB].push_back(edgeA);
        }
        int conn = 0;
        int result = 1;

        REP(i,emp) {
            if(!visited[i]) {
                drill = 0;
                conn++;
                dfs(i);
                result = (result*drill) % MOD;
            }
        }
        cout << conn << " " << result << endl;
    }
	return 0;
}

