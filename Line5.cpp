//#include <iostream>
//#include <memory.h>
//#include <queue>
//using namespace std;
//int c;
//int b;
//queue<pair<int, int>> q;
//int step[200000];
//bool chk[200000];
//
//void bfs()
//{
//	while (!q.empty())
//	{
//		int cony = q.front().first;
//		int brown = q.front().second;
//		if (cony + step[brown] + 1 > 200000)
//		{
//			cout << "-1" << endl;
//			return;
//		}
//		q.pop();
//		if (chk[brown - 1] == false && brown -1 >=0)
//		{
//			if (cony + step[brown]+1 == brown - 1)
//			{
//				cout << step[brown]+1<< endl;
//				return;
//			}
//			else
//			{
//				step[brown - 1] = step[brown] + 1;
//				chk[brown - 1] = true;
//				q.push(make_pair(cony + step[brown]+1, brown - 1));
//				//cout << cony + step[brown] << " " << brown - 1 << endl;
//			}
//		}
//		if (chk[brown + 1] == false && brown + 1 <= 200000)
//		{
//			if (cony + step[brown]+1 == brown + 1)
//			{
//				cout << step[brown]+1<< endl;
//				return;
//			}
//			else
//			{
//				step[brown + 1] = step[brown] + 1;
//				chk[brown + 1] = true;
//				q.push(make_pair(cony + step[brown]+1, brown + 1));
//				//cout << cony + step[brown] << " " << brown + 1 << endl;
//			}
//		}
//		if (chk[brown * 2] == false && brown * 2 <= 200000)
//		{
//			if (cony + step[brown]+1 == brown * 2)
//			{
//				cout << step[brown]+1<< endl;
//				return;
//			}
//			else
//			{
//				step[brown * 2] = step[brown] + 1;
//				chk[brown * 2] = true;
//				q.push(make_pair(cony + step[brown]+1, brown * 2));
//				//cout << cony + step[brown] << " " << brown *2 << endl;
//			}
//		}
//	}
//}
//
//
//int main(void) {
//	
//	scanf("%d %d", &c, &b);
//	if (c == b)
//	{
//		printf("0\n");
//		return 0;
//	}
//	memset(chk, false, sizeof(bool) * 200000);
//	chk[b] = true;
//	step[b] = 0;
//	q.push(make_pair(c, b));
//	bfs();
//
//	return 0;
//}