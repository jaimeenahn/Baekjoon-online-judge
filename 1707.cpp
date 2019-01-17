#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>	

using namespace std;
/*
void bfs(int *set, vector<vector<int>> graph, queue<int> q) {
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		int mark = !set[node];
		for (int i = 0; i < graph[node].size(); i++)
		{
			int x = graph[node][i];
			
			if (set[x] == -1)
			{
				q.push(x);
				set[x] = mark;
			}
		}
	}
}*/
vector<int> graph[20000];
int chk[20000];
bool flag;

void dfs(int node) {

		for (int i = 0; i < graph[node].size(); i++)
		{
			int x = graph[node][i];
			int a = 3-chk[node];
			if (chk[x] == 0)
			{
				chk[x] = a;
				dfs(x);
			}
			else if(chk[x]==chk[node])
			{
				flag = false;
				return;
			}
		}
}
int main() {
	int num;
	
	scanf("%d", &num);
	
	while (num--)
	{
		flag =true;
		int V, E;
		scanf("%d %d", &V, &E);
		for (int i = 0; i < V; i++)
		{
			graph[i].clear();
			chk[i] = 0;
		}
		for (int i = 0; i < E; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			graph[x - 1].push_back(y - 1);
			graph[y - 1].push_back(x - 1);
		}
		//queue<int> q;
		
		for (int i = 0; i < V; i++)
		{
			if (chk[i] == 0)
			{
				//q.push(i);
				chk[i] = 1;
				dfs(i);
			}
		}

		printf("%s\n", flag ? "YES" : "NO");

	}
	return 0;
}