//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//#include <cstring>
//
//using namespace std;
//
//int main()
//{
//	// baekjoon 1005
//
//	ios_base::sync_with_stdio(false);
//	int T, N, K;
//	int X, Y;
//	int W;
//
//	cin >> T;
//
//	for (int t = 0; t < T; t++)
//	{
//		int delay[1001] = { 0, };
//		int indegree[1001] = { 0, };
//		int DP[1001] = { 0, };
//		vector<int> relation[1001];
//		queue<int> q;
//
//		memset(delay, 0, sizeof(delay));
//		memset(indegree, 0, sizeof(indegree));
//		memset(DP, 0, sizeof(DP));
//		memset(relation, 0, sizeof(relation));
//
//		cin >> N >> K;
//
//		for (int n = 1; n <= N; n++)
//		{
//			cin >> delay[n];
//		}
//
//		for (int k = 0; k < K; k++)
//		{
//			cin >> X >> Y;
//			relation[X].push_back(Y);
//			indegree[Y]++;
//		}
//
//		cin >> W;
//
//		for (int i = 1; i <= N; i++)
//		{
//			if (indegree[i] == 0) q.push(i);
//			DP[i] = delay[i];
//		}
//
//		while (!q.empty())
//		{
//			int now = q.front();
//			q.pop();
//
//			for (int i = 0; i < relation[now].size(); i++)
//			{
//				int next = relation[now][i];
//				DP[next] = max(DP[next], DP[now] + delay[next]);
//				indegree[next]--;
//				if (indegree[next] == 0) q.push(next);
//			}
//		}
//
//		cout << DP[W] << endl;
//	}
//
//	return 0;
//}
//
//
////#include <iostream>
////#include <vector>
////#include <queue>
////using namespace std;
////
////vector<vector<int>> graph;
////queue<pair<int, int>> q;
////int weights[1000];
////int innode[1000];
////int step;
////int finish;
////int max_w[1000];
////
////void bfs() {
////	while (!q.empty())
////	{
////		int node = q.front().first;
////		int cur_step = q.front().second;
////		//cout <<" node : " <<  node+1 << ", " << "step : " << cur_step << ", " <<"innode : " << innode[node] << endl;
////		step = cur_step;
////		if (max_w[cur_step] < weights[node])
////			max_w[cur_step] = weights[node];
////		q.pop();
////		if (node == finish-1 && innode[node] == -1)
////			return;
////		for (int i = 0; i < graph[node].size(); i++)
////		{
////			if (innode[graph[node][i]] == 1)
////			{
////				innode[graph[node][i]] = -1;
////				q.push(make_pair(graph[node][i], cur_step+1));
////			}
////			else if (innode[graph[node][i]] != -1)
////			{
////				innode[graph[node][i]]--;
////			}
////		}
////	}
////}
////
////int main() {
////	int num;
////	scanf("%d", &num);
////	while (num--) {
////		int total = 0;
////		step = 1;
////		int N, M;
////		scanf("%d %d", &N, &M);
////		graph.resize(N);
////		for (int i = 0; i < N; i++)
////		{
////			int weight;
////			scanf("%d", &weight);
////			weights[i] = weight;
////			innode[i] = 0;
////			max_w[i] = 0;
////			graph[i].clear();
////		}
////		for (int i = 0; i < M; i++)
////		{
////			int in, out;
////			scanf("%d %d", &in, &out);
////			graph[in-1].push_back(out-1);
////			innode[out - 1]++;
////		}
////		
////		scanf("%d", &finish);
////		for (int i = 0; i < N; i++)
////		{
////			if(innode[i]==0)
////				q.push(make_pair(i, step));
////		}
////
////		bfs();
////		//cout << step << endl;
////		for (int i = 1; i <= step; i++)
////		{
////			//cout << max_w[i] << " ";
////			total += max_w[i];
////		}
////		//cout << endl;
////		printf("%d\n", total);
////	}
////
////	return 0;
////}