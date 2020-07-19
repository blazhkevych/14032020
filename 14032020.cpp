#include <iostream>
#include <time.h>
using namespace std;
#define N 100

int RandInt(int max, int min = 0) {
	if (max < min)
		swap(max, min);
	return min + rand() % (max - min + 1);
}
void ShowArray1D(int arr[], int n) {
	for (size_t i = 0; i < n; i++)
		cout << arr[i] << '\t';
	cout << '\n';
}
void SetArray1D(int arr[], int n) {
	for (size_t i = 0; i < n; i++) {
		cout << "Enter arr[" << i << "]=";
		cin >> arr[i];
	}
}
void SetRndArray1D(int arr[], int n, int max, int min = 0) {
	for (size_t i = 0; i < n; i++)
		arr[i] = RandInt(max, min);
}
//функція сортування масиву
void SortArray1D(int arr[], int n) {
	bool f;
	int j = 0;
	do {
		f = false;
		for (size_t i = 0; i < n - 1 - j; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				f = true;
			}
		}
		j++;
	} while (f);
}
//функція пошуку мінімального
//int MinArray1D(int arr[], int n) {
//    int min = arr[0];
//    for (size_t i = 1; i < n; i++) 
//        if (arr[i] < min)
//            min = arr[i];
//    return min;
//}
int MinArray1D(int arr[], int n) {
	int pmin = 0;
	for (size_t i = 1; i < n; i++)
		if (arr[i] < arr[pmin])
			pmin = i;
	return pmin;
}
//функція пошуку максимального
int MaxArray1D(int arr[], int n) {
	int pmin = 0;
	for (size_t i = 1; i < n; i++)
		if (arr[i] > arr[pmin])
			pmin = i;
	return pmin;
}
//функція пошуку мінімального додатнього
int MinPosArray1D(int arr[], int n) {
	int pmin = -1;
	for (size_t i = 0; i < n; i++)
		if (arr[i] > 0) {
			pmin = i;
			break;
		}
	if (pmin >= 0)
		for (size_t i = pmin + 1; i < n; i++)
			if (arr[i] < arr[pmin] && arr[i]>0)
				pmin = i;
	return pmin;
}


//функція пошуку максимального від'ємного
//суму між мінімальним та максимальним

int main()
{
	int const size = 100;
	srand(time(0));
	int mas[N]{};
	int n;
	do {
		cout << "Enter size = ";
		cin >> n;
	} while (n<1 || n>N);
	//SetArray1D(mas, n);
	SetRndArray1D(mas, n, 20, -10);
	ShowArray1D(mas, n);
	//SortArray1D(mas, n);
	//ShowArray1D(mas, n);
	cout << "Min= " << mas[MinArray1D(mas, n)] << " pos=" << MinArray1D(mas, n);
	cout << endl;
	cout << "Max= " << mas[MaxArray1D(mas, n)] << " pos=" << MaxArray1D(mas, n);

	if (MinPosArray1D(mas, n) >= 0)
		cout << "\nMinPos= " << mas[MinPosArray1D(mas, n)] << " pos=" << MinPosArray1D(mas, n);
	else

		cout << "\nIn array not positive";

}