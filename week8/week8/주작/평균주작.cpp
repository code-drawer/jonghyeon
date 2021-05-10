#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
int main() {
	int n;
	cin >> n;
	if (n < 1 || n > 1000) return 0;
	vector<int> a(n);
	for (int i = 0; i < n; i += 1) {
		cin >> a[i];
		if (a[i] > 100 || a[i] < 0) return 0;
	}
	sort(a.begin(), a.end());
	if (a[n - 1] == 0) return 0;
	double Mul = 100.0 / double(a[n - 1]);
	int sum = 0;
	for (int i = 0; i < n; i += 1) {
		a[i] *= Mul;
		sum += a[i];
	}
	cout << sum / n;
	return 0;
}