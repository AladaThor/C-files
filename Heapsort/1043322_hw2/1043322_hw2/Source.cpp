#include<iostream>

using namespace std;

void heapify(int heap[], int i, int &n);
void heapsort(int heap[], int &n);

int main(){
	int heap[1000] = {};
	int a;
	cout << "How many input you want: ";
	cin >> a;
	int size = a;
	cout << "A sequence of unsorted numbers: ";
	for (int i = 1; i <= a; i++)
	{
		cin >> heap[i];
	}
	for (int i = size / 2; i >= 1; i--)
	{
		heapify(heap, i, size);
	}
	int b = 1;
	cout << "The construction of max-heap tree: " << endl;
	for (int h = 1; h <= size; h++)
	{
		cout << heap[h] << "  ";
		if ((h == ((int)pow(2, b) - 1)) && (b != 0)){ cout << endl; b++; }
	}
	cout << endl;
	heapsort(heap, size);

	system("pause");
	return 0;
}

void heapify(int heap[], int i, int &n)
{
	int j, tmp;
	tmp = heap[i];
	j = 2 * i;
	while (j <= n)
	{
		if (j < n && heap[j + 1] > heap[j])
			j = j + 1;
		if (tmp > heap[j])
			break;
		else if (tmp <= heap[j])
		{
			heap[j / 2] = heap[j];
			j = 2 * j;
		}
	}
	heap[j / 2] = tmp;
}


void heapsort(int heap[], int &n)
{
	int temp, j, a;
	a = 0;
	for (int i = n; i >= 1; i--)
	{
		j = i - 1;
		if (i >= 2)
		{
			temp = heap[i];
			heap[i] = heap[1];
			heap[1] = temp;
			heapify(heap, 1, j);
		}
		cout << "Sorted numbers: ";
		for (int h = n; h >= n - a; h--)
		{
			cout << heap[h] << " ";
		}
		cout << endl;
		a++;
		int b = 1;
		for (int h = 1; h <= i - 1; h++)
		{
			cout << heap[h] << "  ";
			if ((h == ((int)pow(2, b) - 1)) && (b != 0)){ cout << endl; b++; }
		}
		cout << endl;
	}
}
