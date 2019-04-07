//#include <iostream>
//
//using namespace std;
//
//int map[100][100];
//int cnt;
//int n, l;
///*
//앞으로 L을 탐색하는데 
//*/
//void hbacktrack(pair<int, int> node, bool prev_down)
//{
//	int x = node.first;
//	int y = node.second;
//	if (y + l < n)
//	{
//		bool down = false;
//		if (map[x][y] - 1 == map[x][y + 1])
//			down = true;
//		else if (map[x][y] > map[x][y + 1])
//		{
//			cnt--;
//			return;
//		}
//		for (int i = 1; i <= l; i++)
//		{
//			if (down)
//			{
//				if (map[x][y] - 1 == map[x][y + i] && i == l)
//					hbacktrack(make_pair(x, y + l), true);
//				else if (map[x][y] - 1 == map[x][y + i])
//					continue;
//				else if (map[x][y] - 1 != map[x][y + i])
//				{
//					cnt--;
//					return;
//				}
//			}
//			else if ((i != l && map[x][y] < map[x][y + i]) || (i==1  && map[x][y] + 1 < map[x][y+i]))
//			{
//				cnt--;
//				return;
//			}
//			else if (i == l && map[x][y] + 1 == map[x][y + l])
//			{
//				if (y + l < n)
//				{
//					if (prev_down)
//					{
//						cnt--;
//						break;
//					}
//					else
//						hbacktrack(make_pair(x, y + l), false);
//				}
//					
//			}
//			else
//			{
//				if (i == l)
//					hbacktrack(make_pair(x, y + 1),false);
//			}
//			
//		}
//	}
//	else
//	{
//		for (int i = 1; i < n - y; i++)
//		{
//			if (map[x][y] != map[x][y + i])
//			{
//				cnt--;
//				return;
//			}
//		}
//	}
//}
//void vbacktrack(pair<int, int> node, bool prev_down)
//{
//	int x = node.first;
//	int y = node.second;
//	if (x + l < n)
//	{
//		bool down = false;
//		if (map[x][y] - 1 == map[x+1][y])
//			down = true;
//		else if (map[x][y] > map[x + 1][y])
//		{
//			cnt--;
//			return;
//		}
//		for (int i = 1; i <= l; i++)
//		{
//			if (down)
//			{
//				if (map[x][y] - 1 == map[x+i][y] && i == l)
//					vbacktrack(make_pair(x+l, y), true);
//				else if (map[x][y] - 1 == map[x+i][y])
//					continue;
//				else if (map[x][y] - 1 != map[x+i][y])
//				{
//					cnt--;
//					return;
//				}
//			}
//			else if ((i != l && map[x][y] < map[x+i][y]) || (i == 1 && map[x][y] + 1 < map[x+i][y]))
//			{
//				cnt--;
//				return;
//			}
//			else if (i == l && map[x][y] + 1 == map[x+i][y])
//			{
//				if (x + l< n)
//				{
//					if (prev_down)
//					{
//						cnt--;
//						break;
//					}
//					else
//					{
//						vbacktrack(make_pair(x+l, y), false);
//						//cout << x << " " << y << " " << x+1+l << endl;
//					}
//						
//				}
//			}
//			else
//			{
//				if (i == l)
//					vbacktrack(make_pair(x +1 , y), false);
//			}
//
//		}
//	}
//	else
//	{
//		for (int i = 1; i < n - x; i++)
//		{
//			if (map[x][y] != map[x+i][y])
//			{
//				cnt--;
//				return;
//			}
//		}
//	}
//}
//
//
//int main()
//{
//	
//	scanf("%d %d", &n, &l);
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			scanf("%d", &map[i][j]);
//		}
//	}
//	cnt = 2 * n;
//	for (int i = 0; i < n; i++)
//	{
//		int prev = cnt;
//		hbacktrack(make_pair(i, 0), false);
//		//if (prev != cnt)
//		//	cout << "h : " << i << endl;
//		//prev = cnt;
//		vbacktrack(make_pair(0, i), false);
//		//if (prev != cnt)
//		//	cout << "v : " << i << endl;
//	}
//
//	cout << cnt << endl;
//	return 0;
//
//}
////cout << x << " " << y << " " << i << " " << map[x][y] << " " << map[x][y + i] << endl;