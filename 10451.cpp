#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

vector<int> graph[1000];
bool chk[1000];

void dfs(int node) {
	for (int i = 0; i < graph[node].size(); i++)
	{
		int x = graph[node][i];
		if (chk[x] == false)
		{
			chk[x] = true;
			dfs(x);
		}
	}
}

int main()
{
	int num;
	scanf("%d", &num);
	while (num--) {
		int n;
		int cnt = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			graph[i].clear();
			memset(chk, false, sizeof(bool)*n);
		}
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			graph[i].push_back(x - 1);
		}
		for (int i = 0; i <n; i++)
		{
			if (chk[i] == false)
			{
				dfs(i);
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}	
	return 0;
}