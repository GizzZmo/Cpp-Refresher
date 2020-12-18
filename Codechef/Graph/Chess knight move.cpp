#include<bits/stdc++.h>
using namespace std;

char graph[9][9];
bool visited[9][9];
int n=9;

#define REP_I(i,n) for(int i=1;i<=n;i++)
#define REP_J(j,n) for(int j=1;j<=n;j++)

int bfs(int srcX, int srcY, int endX, int endY) {
	int dirX[] = {-2,-1,1,2,-2,-1,1,2};
	int dirY[] = {1,2,2,1,-1,-2,-2,-1};

    queue<pair<int,int>> q;
    q.push(make_pair(srcX, srcY));

    int result = 1;

    while(!q.empty())   {
        int size = q.size();
        while(size--) {
            auto p = q.front();
            visited[p.first][p.second] = true;
            q.pop();
            for(int k=0;k<8;k++) {
                int x = p.first + dirX[k];
                int y = p.second + dirY[k];

                if(x<1 || x>n || y<1 || y>n || visited[x][y])
                    continue;
                else if(x==endX && y==endY)
                    return result;
                else {
                    if(!visited[x][y]) {
                        q.push(make_pair(x,y));
                    }
                }
            }
        }
        result++;
    }

}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string start, stop;
        cin >> start >> stop;
        REP_I(i,n) {
            REP_J(j,n) {
                visited[i][j] = false;
            }
        }
        int startX = start[0]-'a'+1;
        int startY = start[1]-'1'+1;
        int endX = stop[0]-'a'+1;
        int endY = stop[1]-'1'+1;
        int result = bfs(startX, startY, endX, endY);
        cout << result << endl;
    }
    return 0;
}
