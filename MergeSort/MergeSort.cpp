#include<iostream>
using namespace std;

void merge(int numbers[], int temp[], int left, int mid, int right)
{
	int i, left_end, num_elements, tmp_pos;
	left_end = mid - 1;
	tmp_pos = left;
	num_elements = right - left + 1;
	while ((left <= left_end) && (mid <= right))
	{
		if (numbers[left] <= numbers[mid])
		{
			temp[tmp_pos] = numbers[left];
			tmp_pos = tmp_pos + 1;
			left = left + 1;
		}
		else
		{
			temp[tmp_pos] = numbers[mid];
			tmp_pos = tmp_pos + 1;
			mid = mid + 1;
		}
	}
	while (left <= left_end)
	{
		temp[tmp_pos] = numbers[left];
		left = left + 1;
		tmp_pos = tmp_pos + 1; 
	}
	while (mid <= right)
	{
		temp[tmp_pos] = numbers[mid];
		mid = mid + 1;
		tmp_pos = tmp_pos + 1;
	}
	for (i = 0; i < num_elements; i++)
	{
		numbers[right] = temp[right];
		right = right - 1;
	}
}

void m_sort(int numbers[], int temp[], int left, int right)
{
	int  mid;
	if (right > left)
	{
		mid = (right + left) / 2;
		m_sort(numbers, temp, left, mid);
		m_sort(numbers, temp, mid + 1, right);
		merge(numbers, temp, left, mid + 1, right);
	}
}
int main()
{
	int numbers[50], temp[50];
	int i, n;
	cout << "Enter the size of arrays: ";
	cin >> n;
	cout << "Enter the elements: " << endl;
	for (i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}
	cout << "The elements after sorting" << endl;
	m_sort(numbers,temp,0,n-1);
	for (i = 0; i < n; i++)
	{
		cout << numbers[i] << endl;
	}
}