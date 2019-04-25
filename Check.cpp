#include <iostream>
// using namespace std;
using std::cin;
using std::cout;

int gcd(int a, int b) {
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

int lcm(int a, int b) {
	int n = gcd(a, b);
	if(n != 0) {
		return a / n * b;
	}
	return 0;
}

int main() {
	int a, b;
	cin >> a;
	cin >> b;
	cout << "LCM : " << lcm(a, b) << "\n";
	return 0;
}
