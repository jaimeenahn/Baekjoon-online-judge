#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <memory.h>

using namespace std;
//bool chk[236197];
int main() {
	int A, P;
	//memset(chk, false, sizeof(bool) * 236197);
	scanf("%d %d", &A, &P);
	vector<int> v;
	int node = A;
	//cout << pow(A / 10, P) << endl;
	vector<int>::iterator iter;
	do
	{
		v.push_back(node);
		//chk[node] = true;
		int x = 0;
		do {
			x += pow(node % 10, P);
			node = node / 10;
		} while (node != 0);
		node = x;
		iter = find(v.begin(), v.end(), node);

	} while (iter == v.end());
	int cnt = 0;
	for (vector<int>::iterator iteriter = v.begin(); iteriter < iter; iteriter++)
	{
		cnt++;
	}
	printf("%d\n", cnt);

	return 0;
}
