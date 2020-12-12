#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define REP(i,n) for(int i=1;i<=n;i++)

vi graph[10001];
vi low(10001);
vi in(10001);
vi visited(10001);
set<int> s;
int timer;

void dfs(int node, int parent) {
    low[node] = in[node] = timer++;
    visited[node] = 1;
    int children = 0;
    for(auto child:graph[node]) {
        if(child==parent) {
            continue;
        }
        else if(visited[child]){
            low[node] = min(low[node], in[child]);
        }
        else {
            dfs(child,node);
            children++;
            low[node] = min(low[node],low[child]);
        	if(low[child]>=in[node] && parent!=-1) {
                s.insert(node);
            }
        }
    }
    if(parent==-1 && children>1) {
        s.insert(node);
    }
}

int main()
{
    int n , m ;
    bool flagInput = true;
    while(flagInput) {
        cin >> n >> m;
        if(!n && !m) {
            break;
        }

        timer=0;
        s.clear();
        REP(i,n) {
            graph[i].clear();
            visited[i] = 0;
        }

        while(m--) {
            int edgeA, edgeB;
            cin >> edgeA >> edgeB;
            graph[edgeA].push_back(edgeB);
            graph[edgeB].push_back(edgeA);
        }
        REP(i,n) {
            if(!visited[i])
                dfs(i,-1);
        }
        
        cout << s.size() << endl;
    }
    return 0;
}
