#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>

using namespace std;

int n, l, r;
int map[51][51];
bool chk[51][51];
int total_head[2500];
queue<pair<pair<int, int>, int>> open;
queue<pair<int, int>> q;
int number_node = 0;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1, 1, 0,0 };
bool flag = false;
/*
1. �̵��ϸ鼭 ������ �������ϴ��� üũ(bfs)
2. ������ �̵� (�ش� ��� queue�� ����)
3. 1�� goto �ٽ�üũ
4. ���ٸ� ����

*/
void bfs(int cnt)
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		open.push(make_pair(make_pair(x, y), cnt));
		number_node++;
		total_head[cnt] += map[x][y];
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int xx = x + dx[k];
			int yy = y + dy[k];
			if (xx >= 0 && xx < n && yy >= 0 && yy < n)
			{
				if (chk[xx][yy] == false && (abs(map[xx][yy]-map[x][y]) >= l && abs(map[xx][yy] - map[x][y]) <= r))
				{
					chk[xx][yy] = true;
					if (!flag)
						flag = true;
					q.push(make_pair(xx, yy));

				}
			}
		}
	}
}
void move()
{
	while (!open.empty())
	{
		int x = open.front().first.first;
		int y = open.front().first.second;
		int ally = open.front().second;
		open.pop();
		map[x][y] = total_head[ally];
	}
}

int main()
{
	
	scanf("%d %d %d", &n, &l, &r);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	int count = 0;
	while(1)
	{
		for (int i = 0; i < n; i++)
		{
			memset(chk[i], false, sizeof(bool)*(n));
		}
		int cnt = 0;
		//Ž��
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (chk[i][j] == false)
				{
					q.push(make_pair(i, j));
					chk[i][j] = true;
					bfs(cnt);
					total_head[cnt] = total_head[cnt] / number_node;
					cnt++;
					number_node = 0;
				}
			}
		}
		//�α��̵�
		if (flag)
			move();		
		else
			break;
		/*cout << "==================================" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << map[i][j] << " ";
			}
			cout << endl;
		}*/
		memset(total_head, 0, sizeof(int)*(cnt));
		count++;
		flag = false;
	}
	cout << count << endl;
	return 0;

}