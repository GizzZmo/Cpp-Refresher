#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define REP(i,n) for(int i=1;i<=n;i++)

vi graph[10001];
vi in(10001);
vi result;

int main()
{
    int n , m ;
    cin >> n >> m;

    REP(i,n) {
        graph[i].clear();
        in[i] = 0;
    }
    REP(i,m) {
        int edgeA, edgeB;
        cin >> edgeA >> edgeB;
        graph[edgeA].push_back(edgeB);
        in[edgeB]++;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    REP(i,n) {
        if(!in[i]) {
            pq.push(i);
        }
    }
    if(pq.empty()) {
        cout << "Sandro fails.";
        return 0;
    }
    result.clear();
    while(!pq.empty()) {
        int primary = pq.top();
        result.push_back(primary);
        pq.pop();
        for(auto dependent:graph[primary]) {
            in[dependent]--;
            if(!in[dependent]) {
                pq.push(dependent);
            }
        }
    }
    for(auto node:result) {
        cout << node << " ";
    }
    return 0;
}
