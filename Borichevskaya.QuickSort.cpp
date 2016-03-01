#include <iostream>
using namespace std;

void QuickSort(int *, int);
void QuickSort(int *, int, int);
void DisplayArray(int a[], int n);
int* RandomArray(int n);
void Swap(int *a, int *b);

int main()
{
	int n;
	cout << endl << " The number of digits in the array = " << endl;
	cin >> n;
	int*a = RandomArray(n);

	cout << "Source arrays before sort: " << endl;
	DisplayArray(a, n);
	cout << endl;
	QuickSort(a, 0, n - 1);
	cout << "Source arrays after sort: " << endl;
	DisplayArray(a, n);
	system("pause");
	return 0;
}


void QuickSort(int *a, int n)
{
	QuickSort(a, 0, n - 1);
}

void QuickSort(int * a, int left, int right)
{
	int i = left, j = right;
	int h = a[(i + j) / 2];
	while (i <= j)
	{
		while (a[i] < h) i++;
		while (a[j]> h) j--;
		if (i <= j)
		{
			Swap(a + i, a + j);
			i++;
			j--;
		}
		if (left < j) QuickSort(a, left, j);
		if (i < right) QuickSort(a, i, right);
	}
}

void DisplayArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ; ";
}

int* RandomArray(int n)
{
	int  *a = new int[n];
	for (int* p = a; p < a + n; p++)
		*p = rand() % 200 - 100;
	return a;
}

void Swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
