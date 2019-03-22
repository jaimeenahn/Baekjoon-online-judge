//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int n, m;
//	scanf("%d %d", &n, &m);
//	int x, y;
//	scanf("%d %d", &x, &y);
//	int k;
//	scanf("%d", &k);
//	int map[20][20];
//	int dice[6] = { 0, };
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			int tmp;
//			scanf("%d ", &tmp);
//			map[i][j] = tmp;
//		}
//	}
//	for (int i = 0; i < k; i++)
//	{
//		int cmd;
//		scanf("%d", &cmd);
//		if (cmd == 1)
//		{
//			if (y+1 < m)
//			{	
//				y += 1;
//				int tmp = dice[0];
//				dice[0] = dice[2];
//				dice[2] = dice[5];
//				dice[5] = dice[3];
//				dice[3] = tmp;
//				if (map[x][y] == 0)
//				{
//					map[x][y] = dice[0];
//					
//				}
//				else
//				{
//					dice[0] = map[x][y];
//					map[x][y] = 0;
//				}
//				printf("%d\n", dice[5]);
//			}
//			
//		}
//		else if (cmd == 2)
//		{
//			if (y-1 >= 0)
//			{
//				y -= 1;
//				int tmp = dice[0];
//				dice[0] = dice[3];
//				dice[3] = dice[5];
//				dice[5] = dice[2];
//				dice[2] = tmp;
//				if (map[x][y] == 0)
//				{
//					map[x][y] = dice[0];
//					
//				}
//				else
//				{
//					dice[0] = map[x][y];
//					map[x][y] = 0;
//				}
//				printf("%d\n", dice[5]);
//			}
//
//		}
//		else if (cmd == 3)
//		{
//			
//			if (x-1 >= 0)
//			{
//				x -= 1;
//				int tmp = dice[0];
//				dice[0] = dice[4];
//				dice[4] = dice[5];
//				dice[5] = dice[1];
//				dice[1] = tmp;
//				if (map[x][y] == 0)
//				{
//					map[x][y] = dice[0];
//					
//				}
//				else
//				{
//					dice[0] = map[x][y];
//					map[x][y] = 0;
//				}
//				printf("%d\n", dice[5]);
//			}
//		}
//		else
//		{
//			if (x+1 < n)
//			{
//				x += 1;
//				int tmp = dice[0];
//				dice[0] = dice[1];
//				dice[1] = dice[5];
//				dice[5] = dice[4];
//				dice[4] = tmp;
//				if (map[x][y] == 0)
//				{
//					map[x][y] = dice[0];
//					
//				}
//				else
//				{
//					dice[0] = map[x][y];
//					map[x][y] = 0;
//				}
//				printf("%d\n", dice[5]);
//			}
//		}
//
//
//	}
//	return 0;
//
//
//}