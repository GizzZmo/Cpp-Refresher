// Prime Path
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define REP(a,b) for(int i=a;i<=b;i++)
#define REP_PRIME(i) for(int i=1000;i<=9999;i++)

vi graph[10000];
vector<int> visited(10000);
vi prime(10000,1);

void generatePrime(vector<int> &primes) {
	primes[0] = primes[1] = 0;
	for(int i=2;i<=9999;i++) {
		if(prime[i] && i*i<=9999) {
			for(int j=i*i;j<=9999;j+=i) {
				primes[j] = 0;
			}
		}
	}
}

void formGraph() {
	for(int i=1000;i<=9999;i++) {
		if(prime[i]) {
			int index1 = i;
			vector<int> init(4);
			for(int k=0;k<4;k++) {
				int digit = index1%10;
				index1 /= 10;
				init[k] = digit;
			}
			for(int j=1000;j<=9999;j++) {
				if(prime[j] && i!=j) {
					int nc = 0;
					int index2 = j;
					for(int k=0;k<4;k++) {
						int digit = index2%10;
						index2 /= 10;
						if(init[k] != digit) {
							nc++;
							if(nc==2)
								break;
						}
					}
					if(nc==1) {
						graph[i].push_back(j);
					}
				}
			}
		}
	}
}

void bfs(int edgeA, int edgeB, int &minSteps) {

	queue<int> q ;
	q.push(edgeA);
    while(!q.empty()) {
		int size = q.size();
		while(size--) {
			int top = q.front();
			visited[top] = 1;
			if(top==edgeB)
				return;
			for(int i=0;i<graph[top].size();i++) {
				if(!visited[graph[top][i]]) {
					q.push(graph[top][i]);
				}
			}
			q.pop();
		}
		minSteps++;
	}

	return;

}

int main() {
	int t;
	cin >> t;
	generatePrime(prime);
	while(t--) {
		int edgeA, edgeB;
		cin >> edgeA >> edgeB;
		REP_PRIME(i) {
			graph[i].clear();
			visited[i] = 0;
		}
		formGraph();
		int minSteps = 0;
		bfs(edgeA,edgeB,minSteps);
		cout << minSteps << endl;
	}
	return 0;
}
