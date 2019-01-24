#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
	int num;
	scanf("%d", &num);

	int max_imp = 0;
	while (num--)
	{
		int cnt = 0;
		queue<pair<int, int>> q;
		vector<int> v;
		int N, M;
		scanf("%d %d", &N, &M);
		for (int i = 0; i<N; i++)
		{
			int important;
			scanf("%d", &important);
			q.push(make_pair(i, important));
			v.push_back(important);
		}
		sort(v.begin(), v.end());
		int l = v.size();
		while (!q.empty())
		{
			int x = q.front().first;
			int imp = q.front().second;
			if (imp < v[l - 1 - cnt])
			{
				q.pop();
				q.push(make_pair(x, imp));
			}
			else if (x == M)
			{
				q.pop();
				string filePath = "test.txt";

				// write File
				ofstream writeFile(filePath.data());
				//if (writeFile.is_open()) {
				printf("%d\n", cnt + 1);
				//	writeFile << cnt + 1;
				//	writeFile << "\n";
				//	writeFile.close();
				//}
				break;

			}
			else
			{
				q.pop();
				cnt++;
			}
		}
	}
	return 0;
}