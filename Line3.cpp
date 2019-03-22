//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//using namespace std;
//vector<string> split(string s)
//{
//	int x = 0;
//	vector<string> v;
//	for (int i = 0; i < s.length(); i++)
//	{
//		//cout << i << " " << s[i] << endl;
//		if (s[i] == ' ')
//		{
//			v.push_back(s.substr(x, i - x));
//			//cout << s.substr(x, i - x) << endl;
//			x = i + 1;
//		}
//		else if (i == s.length() - 1)
//		{
//			v.push_back(s.substr(x, i - x+1));
//			//cout << s.substr(x, i - x+1) << endl;
//		}
//
//	}
//	return v;
//}
//
//int main(void) {
//	int n;
//	scanf("%d\n", &n);
//
//	char head1[100];
//	scanf("%[^\n]\n", head1);
//	vector<string> head_1 = split(head1);
//	vector<map<int, map<string, string>>> data1;
//	for (int i = 1; i < n; i++)
//	{
//		char str[100] = "a";
//		scanf("%[^\n]\n", str);
//		//cout << str << endl;
//		map<int, map<string, string>> m;
//		vector<string> elem = split(str);
//		for (int x = 0; x < elem.size(); x++)
//		{
//			cout << elem[i] << endl;
//		}
//		map<string, string> tmp;
//		int id = stoi(elem[0]);
//		for (int j = 1; j < head_1.size(); j++)
//		{
//			tmp.insert(make_pair(head_1[j], elem[j]));
//		}
//		m.insert(make_pair(id, tmp));
//		data1.push_back(m);
//	}
//
//	return 0;
//}