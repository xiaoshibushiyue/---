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
	base = arr[left];  //ȡ����ߵ���Ϊ��׼��
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
	//��׼����λ
	arr[left] = arr[i];
	arr[i] = base;
	quickSort(left, i - 1, arr);//�ݹ����
	quickSort(i + 1, right, arr);//�ݹ��ұ�
}

int main() {
	int arr[SIZE] = { 2,1,0,3,4,5,6,8,10,7 };
	//ð������
	//˼·���Ƚ����ڵ��������ݣ�����ڶ�����С���ͽ���λ�á�
	/*�Ӻ���ǰ�����Ƚϣ�һֱ���Ƚ���ǰ�������ݡ�������С������������ʼ��λ�ã�������һ����С����λ�þ��ź��ˡ�
		�����ظ��������̣����ν���2.3...n - 1����С���ź�λ�á�*/
#ifdef BubbleSort
	bool flag;
	int temp;
	//��С��������
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

//ѡ������
	/*�ڳ���ΪN�����������У���һ�α���n - 1�������ҵ���С����ֵ���һ��Ԫ�ؽ�����
		�ڶ��α���n - 2�������ҵ���С����ֵ��ڶ���Ԫ�ؽ�����
		������
		��n - 1�α������ҵ���С����ֵ���n - 1��Ԫ�ؽ�����������ɡ�*/
#ifdef SelctionSort

	for (size_t i = 0; i < SIZE - 1; i++)
	{
		int minindex = i;
		for (size_t j = i + 1; j < SIZE; j++)
		{
			//��С��������
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



//��������
//��Ҫ�����һ�����У��ٶ�ǰn-1�����Ѿ��ź������ڽ���n�����嵽ǰ������������У�
	//ʹ����n����Ҳ���ź�˳��ġ���˷���ѭ����ֱ��ȫ���ź�˳��
#ifdef InsertionSort
	int temp;
	for (int i = 0; i < SIZE-1; i++)
	{
		for (int j = i+1; j >0 ; j--)
		{
			//��С��������
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

//ϣ������--�������ò�����һ�� Ϊlen/2��
//��Ҫ�����һ�����У�����ĳһ������Ϊ���������У����������зֱ���в�������
	//Ȼ���𽥽�������С, ���ظ��������̡�ֱ������Ϊ1, ��ʱ�������л�������, �����в�������
#ifdef ShellSort
	int lenth = SIZE;
	int temp = 0;
	int incre = lenth;

	while (true) {
		incre = incre / 2;

		for (int k = 0; k < incre; k++) {    //����������Ϊ����������

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
	//��������
	//�ȴ�������ȡ��һ������Ϊkeyֵ��
	//���������С����ȫ������������ߣ����ڻ����������ȫ�����������ұߣ�
	//����������С�����ظ��ڶ�����ֱ��������ֻ��1������
	//����׼��ѡ������ߵ�����ʱ����ô��Ӧ���ȴ��ұ߿�ʼ����������׼��ѡ�����ұߵ�����ʱ��
	//��ô��Ӧ���ȴ���߿�ʼ�����������Ǵ�С���������ǴӴ�С����

	quickSort(0,9,arr);
#endif // Quicksort











}