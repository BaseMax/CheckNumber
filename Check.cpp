#include <iostream>
// using namespace std;
using std::cin;
using std::cout;

float maximum(float a, float b) {
	return a > b ? a : b;
}

void repeat(char ch, int repeat) {
	for(int index=0; index< repeat; index++) {
		cout << ch;
	}
}

void draw_s(int s) {
	for(int i=0; i<s;i++) {
		repeat('*', i*2+1);
		cout << "\n";
	}
}

void draw_n(int n) {
	for(int r=1;r<=n;r++) {
		for(int c=1;c<=n;c++) {
			if(r==1 || r==n || c==1 || c==n) {
				cout<< "*" ;
			}
			else {
				cout<< " ";
			}
		}
		cout << "\n";
	}
}

void draw_n_m(int n, int m) {
	for(int r=1;r<=n;r++) {
		for(int c=1;c<=m;c++) {
			// No problem?
			if(r==1 || r==n || c==1 || c==m) {
				cout<< "*" ;
			}
			else {
				cout<< " ";
			}
		}
		cout << "\n";
	}
}

float biggestValue() {
	// We can improve it...
	float result;
	float number1;
	float number2;
	float number3;
	cin >> number1;
	cin >> number2;
	cin >> number3;
	result=maximum(number1, number2);
	result=maximum(result, number3);
	return result;
}

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

// Recursion
int gcd3(int n, int m) {
	// It's correct?
	if(n == 0)
		return m;
	if(m == 0)
		return n;
	int max=n>m ? n : m;
	int min=n>m ? m : n;
	return gcd3(max-min, min);
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
			// Improve...
			if(sum > value) {
				// break;
				return false;
			}
		}
	}
	if(value == sum) {
		return true;
	}
	return false;
}

int main() {
	/////////////////////////////////
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
	float number=biggestValue();
	cout << number << "\n";
	/////////////////////////////////
	return 0;
}
