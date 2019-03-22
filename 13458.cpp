//#include <iostream>	
//#include <memory>
//using namespace std;
//
//int room[1000000];
//
//int main()
//{
//	
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		int tmp;
//		scanf("%d ", &tmp);
//		room[i] = tmp;
//	}
//	int supervisor, sub_supervisor;
//	scanf("%d %d", &supervisor, &sub_supervisor);
//	long long int count = 0;
//	for (int i = 0; i < n; i++)
//	{
//		room[i] = room[i] - supervisor;
//		count+=1;
//		if (room[i] > 0)
//		{
//			
//			int num_sub;
//			if(room[i]%sub_supervisor==0)
//				num_sub = (room[i] / sub_supervisor);
//			else
//				num_sub = (room[i] / sub_supervisor) + 1;
//			count += num_sub;
//		}
//	}
//	printf("%lld\n", count);
//
//	return 0;
//}