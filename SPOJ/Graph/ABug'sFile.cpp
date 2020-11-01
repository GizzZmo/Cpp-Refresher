#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool dfsUtil(map<int,vector<int>> &graph, vector<int> &visited, vector<int> &color, int index, int init) {
	visited[index] = 1;
	color[index] = init;
	for(auto child:graph[index]) {
		if(!visited[child]) {
			if(!dfsUtil(graph, visited, color, child, 1^init)) {
				return false;
			}
				
		}
		else {
			if(color[child]==color[index]) {
				return false;
			}
		}
	}
	return true;
}

bool dfs(map<int,vector<int>> &graph, vector<int> &visited, vector<int> &color) {
	for(auto itr=graph.begin();itr!=graph.end();itr++) {
		if(!visited[itr->first]) {
			if(!dfsUtil(graph, visited, color, itr->first, 1))
				return false;
		}
	}
	return true;
}

int main() {
	int t;
	cin>> t;
	int round = 1;
	while(t--) {
		int bugs, interactions;
		cin >> bugs >> interactions;
		vector<int> visited(bugs+1), color(bugs+1);
		map<int,vector<int>> graph;
		while(interactions--) {
			int a,b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		bool flag = dfs(graph, visited, color);
		cout << "Scenario #"<< to_string(round) <<":" << endl;
		if(!flag)
			cout << "Suspicious bugs found!" << endl;
		else
			cout << "No suspicious bugs found!" << endl;
		round++;	
	}
	return 0;
}