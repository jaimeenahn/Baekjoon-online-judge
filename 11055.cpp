#include <iostream>
#include <algorithm>

using namespace std;
int c[1001];
int d[1001];
int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		c[i + 1] = tmp;
	}
	int max_s = c[1];
	for (int i = 1; i <= num; i++)
	{
		int x = c[i];
		d[x] = c[i];
		for (int j = i; j >= 1; j--)
		{
			if (c[i] > c[j])
			{
				d[c[i]] = max(d[c[i]], d[c[j]] + c[i]);
				if (max_s < d[c[i]])
					max_s = d[c[i]];
			}
		}
	}
	printf("%d\n", max_s);

	return 0;
}