#include <iostream>

using namespace std;

int mat[500][500];
int hdx2[] = {-1, -1, 1, 1};
int hdy2[] = {0, 1, 0, 1};
int vdx2[] = { 0, 1, 0, 1 };
int vdy2[] = { -1, -1, 1, 1 };
int hdx3[] = { -1,-1,-1,0,1,1,1 };
int hdy3[] = { 0, 1, 2, 3, 0, 1, 2 };
int vdx3[] = { 0, 1, 2, 3, 0, 1, 2 };
int vdy3[] = { -1, -1, -1, 0, 1, 1, 1 };

// 3개 최댓값 1개
// 2개 최댓값 2개

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}
	int max_tet = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			
			//가로 2개
			if (j < m - 1)
			{
				int h2 = mat[i][j] + mat[i][j + 1];
				int hnum2 = 0;
				for (int x = 0; x < 4; x++)
				{
					int xx = i + hdx2[x];
					int yy = j + hdy2[x];
					if (xx >= 0 && xx < n && yy >= 0 && yy < m && yy+1<m)
					{
						if (hnum2 < mat[xx][yy] + mat[xx][yy + 1])

						{
							hnum2 = mat[xx][yy] + mat[xx][yy + 1];
						}
					}
				}
				if (max_tet < h2 + hnum2)
				{
					max_tet = h2 + hnum2;
				}
				if (j < m - 2)
				{
					int h3 = h2 + mat[i][j + 2];
					int hnum3 = 0;
					for (int x = 0; x < 7; x++)
					{
						int xx = i + hdx3[x];
						int yy = j + hdy3[x];
						if (xx >= 0 && xx < n && yy >= 0 && yy < m)
						{
							if (hnum3 < mat[xx][yy])
								hnum3 = mat[xx][yy];
						}
					}
					if (max_tet < h3 + hnum3)
						max_tet = h3 + hnum3;
				}
			}
			//세로 2개
			if (i < n - 1)
			{
				int v2 = mat[i][j] + mat[i+1][j];
				int num2 = 0;
				for (int x = 0; x < 4; x++)
				{
					int xx = i + vdx2[x];
					int yy = j + vdy2[x];
					if (xx >= 0 && xx < n && yy >= 0 && yy < m && xx + 1<n)
					{
						if (num2 < mat[xx][yy] + mat[xx+1][yy])
							num2 = mat[xx][yy] + mat[xx+1][yy];
					}
				}
				if (max_tet < v2 + num2)
					max_tet = v2 + num2;
				if (i < n - 2)
				{
					int v3 = v2 + mat[i+2][j];
					int num3 = 0;
					for (int x = 0; x < 7; x++)
					{
						int xx = i + vdx3[x];
						int yy = j + vdy3[x];
						if (xx >= 0 && xx < n && yy >= 0 && yy < m)
						{
							if (num3 < mat[xx][yy])
								num3 = mat[xx][yy];
						}
					}
					if (max_tet < v3 + num3)
						max_tet = v3 + num3;
				}
			}
		}
	}
	printf("%d\n", max_tet);
	return 0;
}