//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int map[51][51];
//
//vector<pair<int, int>> bbq;
//vector<pair<int, int>> home;
//
//vector<int> dist;
//int min_dist = 2500;
//void calculate(pair<int, int> chicken)
//{
//	int bbq_x = chicken.first;
//	int bbq_y = chicken.second;
//
//	for (int i = 0; i < home.size(); i++)
//	{
//		int home_x = home[i].first;
//		int home_y = home[i].second;
//		int distance = abs(bbq_x - home_x) + abs(bbq_y - home_y);
//		dist.push_back(distance);
//	}
//}
//
//int main()
//{
//	int n, m;
//	scanf("%d %d", &n, &m);
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			scanf("%d", &map[i][j]);
//			if (map[i][j] == 2)
//				bbq.push_back(make_pair(i, j));
//			else if (map[i][j] == 1)
//				home.push_back(make_pair(i, j));
//		}
//	}
//	vector<int> idx;
//	for (int i = 0; i < m; i++)
//	{
//		idx.push_back(0);
//	}
//	for (int i = 0; i < bbq.size()-m; i++)
//	{
//		idx.push_back(1);
//	}
//	sort(idx.begin(), idx.end());
//	do
//	{
//		for (int i = 0; i < bbq.size(); i++)
//		{
//			if (idx[i] == 0)
//			{
//				calculate(bbq[i]);
//				//cout << bbq[i].first << " " << bbq[i].second << endl;
//			}
//		}
//		int total = 0;
//		int v_size = dist.size();
//		//cout << "=================" << endl;
//		if (m > 1)
//		{
//			for (int i = 0; i < v_size / m; i++)
//			{
//				int add = dist[i];
//				for (int j = 0; j < m; j++)
//				{
//					add = min(add, dist[i + ((v_size / m)*j)]);
//				}
//				total += add;
//			}
//			//cout << endl;
//		}
//		else
//		{
//			for (int i = 0; i < v_size; i++)
//			{
//				total += dist[i];
//			}
//		}
//		if (total < min_dist)
//			min_dist = total;
//		dist.clear();
//	} while (next_permutation(idx.begin(), idx.end()));
//
//	cout << min_dist << endl;
//	return 0;
//
//}