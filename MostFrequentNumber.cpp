	//#include <iostream>
	//#include <map>

	//using namespace std;

	//int main()
	//{
	//	int t;
	//	scanf("%d", &t);
	//	while (t--)
	//	{
	//		int n;
	//		scanf("%d", &n);
	//		map<int, int> m;
	//		for (int i = 0; i < 1000; i++)
	//		{
	//			int score;
	//			scanf("%d", &score);
	//			if (m.find(score) == m.end())
	//				m.insert(make_pair(score, 1));
	//			else
	//				m[score] += 1;
	//		}
	//		int max_freq=0;
	//		int idx;
	//		for (auto it = m.begin(); it != m.end(); it++) {
	//			if (it->second >= max_freq)
	//			{
	//				idx = it->first;
	//				max_freq = it->second;
	//			}
	//		}
	//		printf("#%d %d\n", n, idx);
	//	}
	//	return 0;
	//}