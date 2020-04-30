#include<iostream>
#define SIZE 10
#define BubbleSort
#define SelctionSort
#define InsertionSort
#define ShellSort
#define Quicksort
using namespace std;
void print(int *a) {
	for (size_t i = 0; i < SIZE; i++)
	{
		cout << a[i]<<" ";
	}
}

void quickSort(int left, int right, int* arr)
{
	if (left >= right)
		return;
	int i, j, base, temp;
	i = left, j = right;
	base = arr[left];  //取最左边的数为基准数
	while (i < j)
	{
		while (arr[j] >= base && i < j)
			j--;
		while (arr[i] <= base && i < j)
			i++;
		if (i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	//基准数归位
	arr[left] = arr[i];
	arr[i] = base;
	quickSort(left, i - 1, arr);//递归左边
	quickSort(i + 1, right, arr);//递归右边
}

int main() {
	int arr[SIZE] = { 2,1,0,3,4,5,6,8,10,7 };
	//冒泡排序
	//思路：比较相邻的两个数据，如果第二个数小，就交换位置。
	/*从后向前两两比较，一直到比较最前两个数据。最终最小数被交换到起始的位置，这样第一个最小数的位置就排好了。
		继续重复上述过程，依次将第2.3...n - 1个最小数排好位置。*/
#ifdef BubbleSort
	bool flag;
	int temp;
	//从小到大排序
	for (size_t i = 0; i < SIZE; i++)
	{
		flag = false;
		for (size_t j = SIZE - 1; j > i; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
				flag = true;
			}
		}
		if (!flag)
		{
			break;
		}
	}

#endif // BubbleSort

//选择排序
	/*在长度为N的无序数组中，第一次遍历n - 1个数，找到最小的数值与第一个元素交换；
		第二次遍历n - 2个数，找到最小的数值与第二个元素交换；
		。。。
		第n - 1次遍历，找到最小的数值与第n - 1个元素交换，排序完成。*/
#ifdef SelctionSort

	for (size_t i = 0; i < SIZE - 1; i++)
	{
		int minindex = i;
		for (size_t j = i + 1; j < SIZE; j++)
		{
			//从小到大排序
			if (arr[j] > arr[minindex])
			{
				minindex = j;
			}
		}
		if (minindex != i)
		{
			int temp = arr[i];
			arr[i] = arr[minindex];
			arr[minindex] = temp;
		}
	}
#endif // SelctionSort



//插入排序
//在要排序的一组数中，假定前n-1个数已经排好序，现在将第n个数插到前面的有序数列中，
	//使得这n个数也是排好顺序的。如此反复循环，直到全部排好顺序。
#ifdef InsertionSort
	int temp;
	for (int i = 0; i < SIZE-1; i++)
	{
		for (int j = i+1; j >0 ; j--)
		{
			//从小到大排序
			if (arr[j]<arr[j-1]) {
				temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
			else {
				break;
			}
		}

	}
#endif // InsertionSort

//希尔排序--可以设置步长，一般 为len/2。
//在要排序的一组数中，根据某一增量分为若干子序列，并对子序列分别进行插入排序。
	//然后逐渐将增量减小, 并重复上述过程。直至增量为1, 此时数据序列基本有序, 最后进行插入排序。
#ifdef ShellSort
	int lenth = SIZE;
	int temp = 0;
	int incre = lenth;

	while (true) {
		incre = incre / 2;

		for (int k = 0; k < incre; k++) {    //根据增量分为若干子序列

			for (int i = k + incre; i < lenth; i += incre) {

				for (int j = i; j > k; j -= incre) {
					if (arr[j] < arr[j - incre]) {
						temp = arr[j - incre];
						arr[j - incre] = arr[j];
						arr[j] = temp;
					}
					else {
						break;
					}
				}
			}
		}

		if (incre == 1) {
			break;
		}
	}
#endif // ShellSort

#ifdef Quicksort
	//快速排序
	//先从数列中取出一个数作为key值；
	//将比这个数小的数全部放在它的左边，大于或等于它的数全部放在它的右边；
	//对左右两个小数列重复第二步，直至各区间只有1个数。
	//当基准数选择最左边的数字时，那么就应该先从右边开始搜索；当基准数选择最右边的数字时，
	//那么就应该先从左边开始搜索。不论是从小到大排序还是从大到小排序

	quickSort(0,9,arr);
#endif // Quicksort











}