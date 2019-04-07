#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;
int i;
int main()
{
	int t;
	scanf("%d", &t);
	int cnt = 0;
	for (i = 0; i < t; i++)
	{
		char password[29];
		vector<int> passwords;
		int n, k;
		scanf("%d %d", &n, &k);
		int pass_length = n / 4;
		scanf("%s", password);
		for (int x = 0; x < n; x++)
		{
			for (int j = 0; j < 4; j++)
			{
				char temp[8];
				char *stop;
				strncpy(temp, password + (pass_length*j), pass_length);
				temp[pass_length] = '\0';
				passwords.push_back(strtol(temp, &stop, 16));
			}
			char tmp[29];
			strncpy(tmp, password + 1, n - 1);
			strncpy(tmp + n - 1, password, 1);
			strncpy(password, tmp, n);
		}
		sort(passwords.begin(), passwords.end(), greater<int>());
		unique(passwords.begin(), passwords.end());

		cnt++;
		cout <<"#" << cnt << " " <<passwords[k-1] << endl;
	}
	return 0;
}