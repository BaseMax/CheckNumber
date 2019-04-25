#include <iostream>
// using namespace std;
using std::cin;
using std::cout;

// Recursion
int gcd(int a, int b) {
	if(a == 0 || b == 0) {
		return 0;
	}
	if(a == b) {
		return a;
	}
	if(a > b) {
		return gcd(a-b, b);
	}
	return gcd(a, b-a);
}

// Loop
int gcd2(int a, int b) {
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

int lcm2(int a, int b, int gc) {
	int n = gc;
	if(n != 0) {
		return a / n * b;
	}
	return 0;
}

int main() {
	int a, b;
	/////////////////////////////////
	cin >> a;
	cin >> b;
	/////////////////////////////////
	int _gsd=gcd(a, b);
	int _lcm=lcm2(a, b, _gsd);
	/////////////////////////////////
	cout << "GCD : " << _gsd << "\n";
	cout << "LCM : " << _lcm << "\n";
	/////////////////////////////////
	return 0;
}
