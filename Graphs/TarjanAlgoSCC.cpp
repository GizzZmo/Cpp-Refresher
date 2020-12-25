#include<bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define REP(i,n) for(int i=1;i<=n;i++)

vi graph[101];
vi in(101);
vi low(101);
int timer=1;
vi inStack(101);
vi visited(101);
stack<int> st;
int SCC;

void dfs(int node) {
    visited[node] = 1;
    in[node] = low[node] = timer++;
    inStack[node] = 1;
    st.push(node);

    for(auto child:graph[node]) {

        if(visited[child] && inStack[child]) {
            low[node] = min(low[child], in[child]);
        }
        else if(!visited[child]) {
            dfs(child);
            if(inStack[child])
                low[node] = min(low[node], low[child]);
        }
    }

    if(low[node]==in[node]) {
        bool flag = true;
        cout << "SCC #" << ++SCC << endl;
        while(flag) {
            int top = st.top();
            cout << top << "\t";
            st.pop();
            inStack[top] = 0;
            if(top == node) {
                flag = false;
            }
        }
        cout << endl;
    }

    return;
}

int main() {
    int n,m;
    cin >> n >> m;
    while(m--) {
        int edgeA,edgeB;
        cin >> edgeA >> edgeB;
        graph[edgeA].push_back(edgeB);
    }
    REP(i,n) {
        visited[i] = inStack[i] = 0;
    }
    REP(i,n) {
        if(!visited[i])
            dfs(i);
    }
}

