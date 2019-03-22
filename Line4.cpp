//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main(void) {
//	int n;
//	scanf("%d", &n);
//	int rope=0;
//	vector<pair<int, bool>> buildings;
//	for (int i = 0; i < n; i++)
//	{
//		int height;
//		scanf("%d", &height);
//		for (int i = 0; i < buildings.size(); i++)
//		{
//			if (buildings[i].second == true)
//			{
//				if (buildings[i].first <= height)
//				{
//					if (buildings.size() - i > rope)
//						rope = buildings.size() - i;
//					buildings[i].second = false;
//				}
//			}
//		}
//		buildings.push_back(make_pair(height, true));
//	}
//
//	cout << rope << endl;
//}