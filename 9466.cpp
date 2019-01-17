#include <iostream>
#include <vector>

using namespace std;

bool chk[100000];
vector<int> graph[100000];
vector<int> cur;
int cnt;
void dfs(int node) {
	for (int i = 0; i < graph[node].size(); i++)
	{
		int x = graph[node][i];
		if (chk[x] != false)
		{
			for (int i = 0; i < cur.size() ; i++)
			{
				if (cur[i] == x)
					break;
				//chk[cur[i]] = false;
				cnt++;
				//cout << cur[i] << "===>";
			}
			return;
		}
		else
		{
			cur.push_back(x);
			chk[x] = true;
			//cnt--;
			dfs(x);

		}
	}
}
int main() {
	int num;
	scanf("%d", &num);
	while (num--) {
		int n;
		
		scanf("%d", &n);
		cnt = 0;
		int ss = 0;
		for (int i = 0; i < n; i++)
		{
			graph[i].clear();
			chk[i] = false;
		}
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			graph[i].push_back(x - 1);
		}
		for (int i = 0; i < n; i++)
		{
			cur.clear();
			if (chk[i] == false)
			{
				chk[i] = true;
				//ss++;
				//cout << ss << endl;
				cur.push_back(i);
				dfs(i);
			}
		}
		/*for (int i = 0; i < n; i++)
		{
			if (chk[n] == false)
				cnt++;
		}*/
		cout << cnt << endl;
	}
	return 0;
}