#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n;
	cin >> m;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i) {
		arr[i] = i + 1;
	}
	int temp = 0;
	do {
		cout << arr[temp] << " "s;
		temp = (temp + m - 1) % n;
	} while (temp != 0);
	delete[] arr;
	return 0;
}