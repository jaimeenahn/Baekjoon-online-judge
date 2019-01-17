#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	queue<int> q;
	for (int i = 0; i < n; i++)
	{
		q.push(i + 1);
	}
	printf("<");
	while (!q.empty())
	{
		for (int i = 0; i < m; i++)
		{
			if (i == m - 1)
			{
				printf("%d", q.front());
				if (q.size() != 1)
					printf(", ");
				else
					printf(">");
				q.pop();
			}
			else
			{
				q.push(q.front());
				q.pop();
			}
		}
	}
	return 0;
}