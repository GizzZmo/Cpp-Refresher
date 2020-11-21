// Social Networking Graph

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define REP(i,n) for(int i=0;i<n;i++)

vi graph[1000001];
vi visited(1000001);

int bfs(int sourceNode, int dist) {
    queue<int> q;
    q.push(sourceNode);
    visited[q.front()] = 1;
    REP(i,dist) {
        int size = q.size();
        while(size--) {
            int top = q.front();
            for(auto child:graph[top]) {
                if(!visited[child]) {
                    q.push(child);
                    visited[child] = 1;
                }
            }
            q.pop();
        }
    }
    return q.size();
}

int main() {
    int n,e;
    cin >> n >> e;
    REP(i,n) {
        graph[i].clear();
        visited[i] = 0;
    }
    REP(i,e) {
        int edgeA, edgeB;
        cin >> edgeA >> edgeB;
        graph[edgeA].push_back(edgeB);
        graph[edgeB].push_back(edgeA);
    }
    int m;
    cin >> m;
    REP(i,m) {
        REP(i,n) {
            visited[i] = 0;
        }
        int edge, dist;
        cin >> edge >> dist;
        int nodes = bfs(edge,dist);
        cout << nodes << endl;
    }
    return 0;
}
