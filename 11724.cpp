#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
using namespace std;

void bfs(bool *chk, vector<vector<int>> graph, queue<int> q) {
	
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0; i < graph[node].size(); i++)
		{
			if (chk[graph[node][i]] == false)
			{
				chk[graph[node][i]] = true;
				q.push(graph[node][i]);
			}
		}
	}
}

int main() {
	int N, M;
	bool chk[1000];
	scanf("%d %d", &N, &M);
	vector<vector<int>> graph;
	graph.resize(N);
	for (int i = 0; i < M; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		graph[x - 1].push_back(y - 1);
		graph[y - 1].push_back(x - 1);
	}
	memset(chk, false, sizeof(bool)*(N));
	queue<int> q;
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		if (chk[i] == false)
		{
			chk[i] = true;
			q.push(i);
			cnt++;
			bfs(chk, graph, q);
		}
	}
	printf("%d\n", cnt);

	return 0;
}