#include<bits/stdc++.h>
using namespace std;

char graph[31][31];
bool visited[31][31];
int n;

#define REP_I(i,n) for(int i=1;i<=n;i++)
#define REP_J(j,n) for(int j=1;j<=n;j++)

int bfs(int srcX, int srcY) {
	int dirX[] = {-1,0,1,0};
	int dirY[] = {0,1,0,-1};

    queue<pair<int,int>> q;
    q.push(make_pair(srcX, srcY));

    int result = 1;

    while(!q.empty())   {
        int size = q.size();
        while(size--) {
            auto p = q.front();
            visited[p.first][p.second] = true;
            q.pop();
            for(int k=0;k<4;k++) {
                int x = p.first + dirX[k];
                int y = p.second + dirY[k];

                if(x<1 || x>n || y<1 || y>n || visited[x][y])
                    continue;
                else if(graph[x][y]=='T')
                    continue;
                else if(graph[x][y]=='E')
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
	cin >> n;
	int x,y;
	REP_I(i,n) {
		REP_J(j,n) {
			visited[i][j] = false;
			cin >> graph[i][j];
			if(graph[i][j]=='S') {
				x = i;
				y = j;
			}
		}
	}

	int steps = bfs(x,y);
	cout << steps << endl;

	return 0;
}
