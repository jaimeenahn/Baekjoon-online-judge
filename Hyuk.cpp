//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <memory.h>
//using namespace std;
//
//int main()
//{
//	for (int i = 0; i < 10; i++)
//	{
//		int chk[1000];
//		vector<int> v;
//		int num;
//		scanf("%d ", &num);
//		memset(chk, 0, sizeof(int)*num);
//		for (int j = 0; j < num; j++)
//		{
//			int tmp;
//			scanf("%d", &tmp);
//			v.push_back(tmp);
//		}
//		for (int j = 2; j < num-2; j++)
//		{
//			for (int x = 1; x <= 2; x++)
//			{
//				if (chk[j + x] != -1) {
//					if (v[j] > v[j + x]) //���� �ǹ��� �������� ������ ���� �ǹ����� �������� ����
//					{
//						chk[j + x] = -1;
//						
//						if(chk[j]==0 && chk[j]!=-1)
//							chk[j] = v[j] - v[j + x];
//						else
//							chk[j] = min(chk[j], v[j] - v[j + x]);
//					}
//					else if (v[j] == v[j + x]) //���� �ǹ� ���� �ǹ����� �������� ����
//					{
//						chk[j + x] = -1;
//						chk[j] = -1;
//						
//						break;
//					}
//					else //���� �ǹ��� �������� ������ ���� �ǹ����� �������� ���� ����
//					{
//						//cout << j << " " <<j + x << " " <<chk[j+x] <<  endl;
//						chk[j] = -1;
//						if(chk[j+x]==0) 
//							chk[j + x] = v[j + x] - v[j];
//						else
//							chk[j + x] = min(chk[j+x], v[j + x] - v[j]);
//						//cout << j << " " << j + x << " " << chk[j + x] << endl;
//						break;
//					}
//				}
//			}
//		}
//		long long int cnt = 0;
//		for (int j = 2; j < num-2; j++)
//		{
//			if (chk[j] != -1)
//				cnt += chk[j];
//
//		}
//		/*for (int x = 0; x < num; x++)
//		{
//			cout << chk[x] << " ";
//		}
//		cout << endl;*/
//		printf("#%d %lld\n", i+1, cnt);
//
//	}
//}