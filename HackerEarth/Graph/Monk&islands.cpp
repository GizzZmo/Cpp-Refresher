// Monk and the Islands

#include<bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define REP(i,N) for(int i=1;i<=N;i++)

vi graph[10001];
int visited[10001];

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N,M;
        cin >> N >> M;
        REP(i,N) {
            graph[i].clear();
        }
        REP(i,M) {
            int edgeA,edgeB;
            cin >> edgeA >> edgeB;
            graph[edgeA].push_back(edgeB);
            graph[edgeB].push_back(edgeA);
        }
        queue<int> queueNode;
        queueNode.push(1);
        int minSteps = 0;
        REP(i,N) {
            visited[i] = 0;
        }
        bool reached = false;
        while(!queueNode.empty()) {
            int size = queueNode.size();
            while(size--) {
                if(queueNode.front()==N) {
                    reached = true;
                    break;
                }
                visited[queueNode.front()] = 1;
                for(auto child:graph[queueNode.front()]) {
                    if(!visited[child]) {
                        queueNode.push(child);
                    }
                }
                queueNode.pop();
            }
            if(reached)
                break;
            minSteps++;
        }
        cout << minSteps << endl;
    }
    
}