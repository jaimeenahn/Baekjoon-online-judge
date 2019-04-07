/*
1 : 한방향 : 4개 위 오 아 왼
2 : 앞 뒤 : 2개 오왼, 위아
3 : 직각 : 4개 위, 오, 아, 왼
4 : 세 방향 : 4개 위 ,오 , 아 , 왼
5 : 네 방향 : 1개
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0,1,0, -1 };
int max_cnt = 100;
int map[8][8];
int new_map[8][8];
int direction_cam[8] = { 0, };
int n, m;
vector<pair<pair<int, int>, int>> v1;
vector<pair<pair<int, int>, int>> v2;
vector<pair<pair<int, int>, int>> v3;
vector<pair<pair<int, int>, int>> v4;
vector<pair<pair<int, int>, int>> v5;

void search(pair<int, int> cctv, int direction)
{
	int xx = cctv.first + dx[direction];
	int yy = cctv.second + dy[direction];
	if (xx >= 0 && xx < n && yy >= 0 && yy < m)
	{
		if (map[xx][yy] != 6)
		{
			if (map[xx][yy] == 0)
				map[xx][yy] = -1;
			search(make_pair(xx, yy), direction);
		}
		else
			return;
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &map[i][j]);
			new_map[i][j] = map[i][j];
			if (map[i][j] == 1)
				v1.push_back(make_pair(make_pair(i, j), 0));
			else if (map[i][j] == 2)
				v2.push_back(make_pair(make_pair(i, j), 0));
			else if (map[i][j] == 3)
				v3.push_back(make_pair(make_pair(i, j), 0));
			else if (map[i][j] == 4)
				v4.push_back(make_pair(make_pair(i, j), 0));
			else if (map[i][j] == 5)
				v5.push_back(make_pair(make_pair(i, j), 0));

		}
	}
	int cam_size = v5.size() + v4.size() + v3.size() + v2.size() + v1.size();
	for (int x = 0; x < pow(4, cam_size); x++)
	{

		int cnt = 0;
		int new_x = x;
		for (int k = 0; k < cam_size; k++)
		{
			
			direction_cam[k] = new_x % 4;
			new_x = new_x / 4;

		}
		//for (int a = 0; a < cam_size; a++)
		//{
		//	cout << direction_cam[a] << " ";
		//}
		//cout << endl;
		for (int i5 = 0; i5 < v5.size(); i5++)
		{
			for (int x5 = 0; x5 < 4; x5++)
			{
				search(v5[i5].first, x5);
			}
		}
		for (int i4 = 0; i4 < v4.size(); i4++)
		{
			int dir = direction_cam[v5.size() + i4];
			for (int x4 = dir; x4 < dir + 3; x4++)
			{
				int new_x4 = x4 % 4;
				search(v4[i4].first, new_x4);
			}
		}
		for (int i3 = 0; i3 < v3.size(); i3++)
		{
			int dir = direction_cam[v5.size() + v4.size() + i3];
			for (int x3 = dir; x3 < dir + 2; x3++)
			{
				int new_x3 = x3 % 4;
				search(v3[i3].first, new_x3);
			}
		}
		for (int i2 = 0; i2 < v2.size(); i2++)
		{
			int dir = direction_cam[v5.size() + v4.size() + v3.size() + i2];
			search(v2[i2].first, dir);
			
			search(v2[i2].first, (dir+2)%4);
			
		}
		for (int i1 = 0; i1 < v1.size(); i1++)
		{
			int dir = direction_cam[v5.size() + v4.size() + v3.size() + v2.size() + i1];
			search(v1[i1].first, dir);
		}
		for (int a = 0; a < n; a++)
		{
			for (int b = 0; b < m; b++)
			{
				if (map[a][b] == 0)
					cnt++;
				map[a][b] = new_map[a][b];
			}
		}
		if (cnt < max_cnt)

		{
			max_cnt = cnt;
			/*for (int a = 0; a < n; a++)
			{
				for (int b = 0; b < m; b++)
				{
					printf("%3d ", map[a][b]);
				}
				cout << endl;
			}*/
		}

		//for (int a = 0; a < n; a++)
		//{
		//	for (int b = 0; b < m; b++)
		//	{
		//		map[a][b] = new_map[a][b];
		//	}
		////}
		//cout << cam_size << endl;
		
	}
	cout << max_cnt << endl;
	return 0;
}