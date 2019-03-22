#include <iostream>
#include <algorithm>

using namespace std;
int c[1001];
int d[1001];
int main() {
	int num;
	scanf("%d", &num);
	int max_s = 0;
	for (int i = 0; i < num; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		c[i + 1] = tmp;
	}
	for (int i = 1; i <= num; i++)
	{
		int x = c[i];
		for (int j = i; j >= 1; j--)
		{
			if (c[i] < c[j])
			{
				d[c[i]] = max(d[c[i]], d[c[j]] + 1);
				if (max_s < d[c[i]])
					max_s = d[c[i]];
			}
		}
	}
	printf("%d", max_s + 1);

	return 0;
}