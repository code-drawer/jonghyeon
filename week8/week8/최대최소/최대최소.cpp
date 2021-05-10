#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::sort;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i += 1) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	cout << a[0] << "  " << a[n-1];
	return 0;
}