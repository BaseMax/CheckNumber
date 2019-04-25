#include <iostream>
using namespace std;

int b_m_m(int a, int b) {
	for(;;) {
		if(a == 0) {
			return b;
		}
		b %= a;
		if(b == 0) {
			return a;
		}
		a %= b;
	}
}

int k_m_m(int a, int b) {
	int n = b_m_m(a, b);
	if(n != 0) {
		return a / n * b;
	}
	return 0;
}

int main() {
	int a, b;
	cin >> a;
	cin >> b;
	cout << "K.M.M : " << k_m_m(a, b) << "\n";
	return 0;
}
