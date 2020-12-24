#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define REP(i,n) for(int i=1;i<=n;i++)
vi graph[1000001];
vi visited(1000001);
vi val(1000001);
vi transpose[1000001];
vi order, scc;
int res;

void dfs(int node) {
    visited[node] = 1;
    for(auto child: graph[node]) {
        if(!visited[child]) {
            dfs(child);
        }
    }
    order.push_back(node);
}

void dfs1(int node)
{
	visited[node] = 1;
	
	for(int adj : transpose[node])
	if(visited[adj] == 0)
	dfs1(adj);
	
	scc.push_back(node);
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
	    cin>>n;
		order.clear() , res = 0;
		REP(i , n)	graph[i-1].clear() , transpose[i-1].clear() , visited[i-1] = 0 , cin>>val[i-1];
		
		
		//graph construction section
		REP(i , n)
		{
			int a = i - 1;
			int b = (i - 1 + val[i-1] + 1) % n;
			
			graph[a].push_back(b);
			transpose[b].push_back(a);
		}
	    
	    REP(i , n) {
	    	if(!visited[i-1])
	    		dfs(i-1);
	    }
		REP(i , n) {
			visited[i-1] = 0;
		} 
		
		reverse(order.begin() , order.end());
		res=0;
	
		for(int i : order) {
			if(visited[i] == 0) {
				scc.clear();
				dfs1(i);
				
				if(scc.size() == 1 && (scc[0] != graph[scc[0]][0])) continue;
				res += scc.size();
			}
		}
		
	   cout << res << endl;
	}
	return 0;
}
