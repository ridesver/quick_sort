#include <iostream>
#include <sstream>

using namespace std;

bool read(int * a, int & b)
{
	cout << "Enter the elements: \n";
	string str;
	getline(cin, str);
	istringstream stream(str);
	for (int i = 0; i < b; ++i)
	{
		if (!(stream >> a[i]))
		{
			cout << "An error has occured while reading input data." << endl;
			return false;
		}
	}
	return true;
}


void quick_sort(int * a, int first, int last)
{
	int i = first, j = last, n = a[j], m = last - first + 1;
	if (m > 1)
	{
		while (i < j)
		{
			if (a[i] > n && i < j)
			{
				if (i == j - 1)
				{
					swap(a[i], a[j]);
					j--;
				}
				else
				{
					swap(a[j], a[j - 1]);
					swap(a[i], a[j]);
					j--;
				}
			}
			else 
				i++;
		}
		quick_sort(a, first, j - 1);
		quick_sort(a, j + 1, last);
	}
}

int main()
{
	int b;
	string k;
	cout << "Enter the number of elements: \n";
	getline(cin, k);
	istringstream stream(k);
	if (!(stream >> b))
	{
		cout << "An error has occured while reading input data." << endl;
		return -1;
	}
	int * a = new int[b];
	if (read(a, b))
	{
		cout << "Result: \n";
		quick_sort(a, 0, b - 1);
		for (int i = 0; i < b; i++)
		{
			cout << a[i] << " ";
		}

		delete[] a;
		return 0;
	}
}
