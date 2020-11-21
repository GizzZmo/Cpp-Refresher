// Feasible Relations

#include<bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define REP(i,n) for(int i=1;i<=n;i++) 

vi graph[1000001];
vector<int> visited(1000001);
int cc[1000001];
int curr_cc;

void dfs(int node) {
    visited[node] = 1;
    cc[node] = curr_cc;

    for(auto child:graph[node]) {
        if(!visited[child]) {
            dfs(child);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    string op;
    while(t--) {
        vector<pair<int,int>> edgeList;
        int n,k;
        cin >> n >> k;
        curr_cc = 0;
        REP(i,n) {
            graph[i].clear();
            visited[i] = 0;
        }

        REP(i,k) {
            int edgeA, edgeB;
            cin>> edgeA >> op >> edgeB;

            if(op == "=") {
                graph[edgeA].push_back(edgeB);
                graph[edgeB].push_back(edgeA);
            } 
            else {
                edgeList.push_back(make_pair(edgeA,edgeB));
            }
        }

        REP(i,n) {
            if(!visited[i]) {
                curr_cc++;
                dfs(i);
            }
        }

        bool flag = true;
        for(int i=0;i<edgeList.size();i++) {
            int edgeA = edgeList[i].first;
            int edgeB = edgeList[i].second;

            if(cc[edgeA]==cc[edgeB]) {
                flag = false;
                break;
            }
        }

        if(!flag) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
}