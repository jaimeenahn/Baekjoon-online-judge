//#include <iostream>
//#include <vector>
//#include <map>
//#include <string>
//
//using namespace std;
//
//map<char, char> m;
//
//bool SameOrNot(string s1, string s2)
//{
//	if (s1.length() != s2.length())
//		return false;
//	else
//	{
//		for (int i = 0; i < s1.length(); i++)
//		{
//			if (s1[i] == 'B')
//				s1[i] = '2';
//			else if (s1[i] == 'A' || s1[i] == 'D' || s1[i] == 'O' || s1[i] == 'P' || s1[i] == 'Q' || s1[i] == 'R')
//				s1[i] = '1';
//			else
//				s1[i] = '0';
//
//			if (s2[i] == 'B')
//				s2[i] = '2';
//			else if (s2[i] == 'A' || s2[i] == 'D' || s2[i] == 'O' || s2[i] == 'P' || s2[i] == 'Q' || s2[i] == 'R')
//				s2[i] = '1';
//			else
//				s2[i] = '0';
//			if (s1[i] != s2[i])
//				return false;
//		}
//	}
//	return true;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	vector<pair<string, string>> v;
//	
//	for (int i = 0; i < n; i++)
//	{
//		string tmp1, tmp2;
//		cin >> tmp1 >> tmp2;
//		v.push_back(make_pair(tmp1, tmp2));
//	}
//	for (int i = 0; i < n; i++)
//	{
//		if (SameOrNot(v[i].first, v[i].second))
//			printf("#%d SAME\n", i + 1);
//		else
//			printf("#%d DIFF\n", i + 1);
//	}
//	return 0;
//}
