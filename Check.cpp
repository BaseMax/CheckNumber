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

int lcm3(int a, int b) {
	int max = (a > b) ? a : b;
	// It require to improve the loop...
	while(1) {
		if((max % a == 0) && (max % b == 0)) {
			return max;
			break;
		}
		++max;
	}
	return 0;
}

bool isPerfect(int value) {
	int sum=0;
	for(int index=1; index < value; index++) {
		if(value % index ==0) {
			sum+=y;
		}
	}
	if(value == sum) {
		return true;
	}
	return false;
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
