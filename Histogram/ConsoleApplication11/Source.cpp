//#include <vector>
//using namespace std;
//
//int area(vector<int> histogram, int begin, int end)
//{
//	if (begin >= end)
//		return 0;
//	int minimum = min(histogram[begin], histogram[end]);
//	int length = (end - begin) - 1;
//	return minimum * length;
//}
//
//int max(vector<int> histogram, int begin, int end)
//{
//	if (begin >= end)
//		return 0;
//
//	int middle = (begin + end) / 2;
//	int max1 = max(histogram, begin, middle);
//	int max2 = max(histogram, middle + 1, end);
//
//	int i = middle;
//	int j = middle;
//	int maxi = 0;
//
//	while (true)
//	{
//		int c = 0;
//		if (i > begin && area(histogram, i - 1, j) >= maxi)
//		{
//			maxi = area(histogram, i - 1, j);
//			i -= 1;
//			c++;
//		}
//		if (j < end && area(histogram, i, j + 1) >= maxi)
//		{
//			maxi = area(histogram, i, j + 1);
//			j += 1;
//			c++;
//		}
//		if (c == 0)
//			break;
//	}
//	return max(maxi, max(max1, max2));
//}
//
//int solution(vector<int> histogram)
//{
//	if (histogram.size() < 3)
//		return 0;
//
//	int answer = max(histogram, 0, histogram.size() - 1);
//	return answer;
//}