//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//char map[11][11];
//int N, M; //N 세로, M 가로
//queue<pair<pair<int, int>, int>> q;
//int dx[] = { -1, 1, 0, 0 };
//int dy[] = { 0, 0, -1, 1 };
//
//pair<pair<int, int>, int> left(pair<int, int> hall)
//{
//	while (map[hall.first][hall.second - 1] != '#' )
//	{
//		if (map[hall.first][hall.second - 1] == '.')
//		{
//			map[hall.first][hall.second - 1] = 'O';
//			hall = make_pair(hall.first, hall.second - 1);
//		}
//		else if (map[hall.first][hall.second - 1] == 'R')
//			return make_pair(hall, 1);
//		else if (map[hall.first][hall.second - 1] == 'B')
//			return make_pair(hall, 0);
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < M; j++)
//			{
//				cout << map[i + 1][j + 1];
//			}
//			cout << endl;
//		}
//	}
//	return make_pair(hall, 2);
//}
//pair<pair<int, int>, int> right(pair<int, int> hall)
//{
//	
//	while (map[hall.first][hall.second + 1] != '#')
//	{
//		if (map[hall.first][hall.second + 1] == '.')
//		{
//			map[hall.first][hall.second + 1] = 'O';
//			hall = make_pair(hall.first, hall.second + 1);
//			
//		}
//		else if (map[hall.first][hall.second + 1] == 'R')
//			return make_pair(hall, 1);
//		else if (map[hall.first][hall.second + 1] == 'B')
//			return make_pair(hall, 0);
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < M; j++)
//			{
//				cout << map[i + 1][j + 1];
//			}
//			cout << endl;
//		}
//	}
//	return make_pair(hall, 2);
//}
//pair<pair<int, int>, int> up(pair<int, int> hall)
//{
//	while (map[hall.first-1][hall.second] != '#')
//	{
//		if (map[hall.first-1][hall.second] == '.')
//		{
//			map[hall.first-1][hall.second] = 'O';
//			hall = make_pair(hall.first-1, hall.second);
//		}
//		else if (map[hall.first-1][hall.second] == 'R')
//			return make_pair(hall, 1);
//		else if (map[hall.first-1][hall.second] == 'B')
//			return make_pair(hall, 0);
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < M; j++)
//			{
//				cout << map[i + 1][j + 1];
//			}
//			cout << endl;
//		}
//	}
//	return make_pair(hall, 2);
//}
//pair<pair<int, int>, int> down(pair<int, int> hall)
//{
//	while (map[hall.first + 1][hall.second] != '#')
//	{
//		if (map[hall.first + 1][hall.second] == '.')
//		{
//			map[hall.first + 1][hall.second] = 'O';
//			hall = make_pair(hall.first + 1, hall.second);
//		}
//		else if (map[hall.first + 1][hall.second] == 'R')
//			return make_pair(hall, 1);
//		else if (map[hall.first + 1][hall.second] == 'B')
//			return make_pair(hall, 0);
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < M; j++)
//			{
//				cout << map[i + 1][j + 1];
//			}
//			cout << endl;
//		}
//	}
//	return make_pair(hall, 2);
//}
//void bfs() {
//	while (!q.empty())
//	{
//		pair<int, int> node = q.front().first;
//		int cnt = q.front().second;
//		q.pop();
//		pair<pair<int, int> ,int> flag;
//		for (int i = 0; i < 4; i++)
//		{
//			int xx = node.first + dx[i];
//			int yy = node.second + dy[i];
//			if (map[xx][yy] == '.')
//			{
//				if (i == 0)
//					flag = up(node);
//				else if (i == 1)
//					flag = down(node);
//				else if (i == 2)
//					flag = left(node);
//				else
//					flag = right(node);
//				/*for (int i = 0; i < N; i++)
//				{
//					for (int j = 0; j < M; j++)
//					{
//						cout << map[i + 1][j + 1];
//					}
//					cout << endl;
//				}*/
//				if (flag.second == 2)
//					q.push(make_pair(flag.first, cnt + 1));
//				else if (flag.second == 1)
//					cout << cnt + 1 << endl;
//			}
//
//		}
//	}
//}
//
//int main() {
//	
//	scanf("%d %d", &N, &M);
//	pair<int, int> hall;
//	cout << N << " " << M << endl;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			char tmp;
//			scanf(" %c", &tmp);
//			//cout <<i  <<" , " << j << " : " << tmp << endl;
//			if (tmp == 'O')
//				hall = make_pair(i + 1, j + 1);
//			map[i + 1][j + 1] = tmp;
//		}
//	}
//	
//	q.push(make_pair(hall, 0));
//	bfs();
//
//
//}