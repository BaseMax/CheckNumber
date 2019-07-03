/**
*
* @Name : CheckNumber/check.cpp
* @Version : 1.0
* @Programmer : Max
* @Date : 2019-03 - 2019-07
* @Released under : https://github.com/BaseMax/CheckNumber/blob/master/LICENSE
* @Repository : https://github.com/BaseMax/CheckNumber
*
**/
#include <iostream>
// using namespace std;
using std::cin;
using std::cout;

float maximum(float a, float b) {
	return a > b ? a : b;
}

void fibUntil(int n) {
	int z;
	int g=1;
	int x=1;
	int k;
	cout << x << " " << g << " " ;
	z = x + g;
	cout << z << " " ;
	for (k = 1 ; k <= n -1 ; k++ ) {
		x = g ;
		g = z ;
		z = x + g ;
		cout << z << " " ;
	}
}

void repeat(char ch, int repeat) {
	for(int index=0; index< repeat; index++) {
		cout << ch;
	}
}

int fibonacci(int number) {
	if(number <= 1)
		return 1;
	else
		return fibonacci(number-1) + fibonacci(number-2);
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

int checks(int number) {
    int index=1,x=0,y=1,z=1;
    int result=1;
    do {
        result=z;
        cout << z << "\t";
        z=x+y;
        x=y;
        y=z;
        index++;
    } while(index<=number);
    // cout << "\n==> " << result;
    return result;
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
			sum+=index;
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

int min(int a, int b)  { 
	return b ^ ((a ^ b) & -(a < b));
} 

int max(int a, int b)  { 
	return a ^ ((a ^ b) & -(a < b));
}

// MIN <= (a - b) <= MAX
int min2(int a, int b) {  
	return ((a - b) & ((a - b) >> (sizeof(int) * 8 - 1))) + b;
}

int max2(int a, int b) {  
	return a - ((a - b) & ((a - b) >> (sizeof(int) * 8 - 1)));
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
	cout << "fibonacci(30) = " << fibonacci(30) << "\n";
	/////////////////////////////////
	int n;
	cout << "How many number for fibonachi?\n";
	cin >> n;
	// n -= 2;
	fibUntil(n-2);
	/////////////////////////////////
	return 0;
}
