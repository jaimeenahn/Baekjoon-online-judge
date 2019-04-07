#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

int p[15];
int t[15];
int e[15];
int done[15];
int ans[15];

/*
i를 포함할 때 안할 때 나눠서
최적해를 증명하려면 i전까지의 최고값 + 나의 현재 값
*/
int main(){

	int n;
	scanf("%d", &n);
	//memset(ans, 0, sizeof(int)*(n + 1));
	memset(done, 0, sizeof(int)*(n + 1));
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &t[i], &p[i]);
		e[i] = i + t[i] - 1;
	}
	int start = 0;
	int end = 0;
	int max_pay = 0;
	for (int i = 1; i <= n; i++)
	{
		if (e[i] <= n)
		{
			done[e[i]] = max(done[e[i]], done[i - 1] + p[i]);
			
		}
		done[i] = max(done[i - 1], done[i]);
	}
	cout << done[n] << endl;

	return 0;

}