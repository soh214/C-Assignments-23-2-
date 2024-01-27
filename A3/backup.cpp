#include <iostream>

using namespace std;
int gcd(int a, int b);

class fraction {
	int p, q;	// p: numerator, q:denominator		p/q
public:
	void show();
	fraction(int n = 0, int m = 1) {
		if (m < 0)						// 분모가 음수일 때 분자를 음수로 변환하는 과정
		{
			n = -n;
			m = -m;
		}
		p = n, q = m;

		int n1 = gcd(p, q);
		p /= n1;
		q /= n1;
	}
	fraction operator+(fraction ob);
	fraction operator-(fraction ob);
	fraction operator*(fraction ob);
	fraction operator/(fraction ob);

	fraction operator+(int a);  // ob +-*/ int a
	fraction operator-(int a);
	fraction operator*(int a);
	fraction operator/(int a);


	friend fraction operator+(int a, fraction ob);	// friend 함수 int a +-*/ ob
	friend fraction operator-(int a, fraction ob);
	friend fraction operator*(int a, fraction ob);
	friend fraction operator/(int a, fraction ob);

	friend fraction operator+(double a, fraction ob);	// friend function double a +-*/ ob

};

void fraction::show() {
	cout << p << "/" << q << endl;
}
fraction fraction::operator+(fraction ob) {
	fraction temp;
	temp.p = p * ob.q + q * ob.p;
	temp.q = q * ob.q;

	int n = gcd(temp.p, temp.q);			// 결과값 약분
	temp.p /= n;
	temp.q /= n;

	return temp;
}
fraction fraction::operator-(fraction ob) {
	fraction temp;
	temp.p = p * ob.q - q * ob.p;
	temp.q = q * ob.q;

	int n = gcd(temp.p, temp.q);
	temp.p /= n;
	temp.q /= n;

	return temp;
}

fraction fraction::operator*(fraction ob) {
	fraction temp;
	temp.p = p * ob.p;
	temp.q = q * ob.q;

	int n = gcd(temp.p, temp.q);
	temp.p /= n;
	temp.q /= n;

	return temp;
}

fraction fraction::operator/(fraction ob) {
	fraction temp;
	temp.p = p * ob.q;
	temp.q = q * ob.p;

	int n = gcd(temp.p, temp.q);
	temp.p /= n;
	temp.q /= n;

	return temp;
}
fraction fraction::operator+(int a) {		// ob + int a
	fraction temp;
	temp.p = p + a * q;
	temp.q = q;

	int n = gcd(temp.p, temp.q);
	temp.p /= n;
	temp.q /= n;

	return temp;
}

fraction fraction::operator-(int a) {		// ob - int a
	fraction temp;
	temp.p = p - a * q;
	temp.q = q;

	int n = gcd(temp.p, temp.q);
	temp.p /= n;
	temp.q /= n;

	return temp;
}

fraction fraction::operator*(int a) {		// ob * int a
	fraction temp;
	temp.p = p * a;
	temp.q = q;

	int n = gcd(temp.p, temp.q);
	temp.p /= n;
	temp.q /= n;

	return temp;
}

fraction fraction::operator/(int a) {		// ob / int a
	fraction temp;
	temp.p = p;
	temp.q = q * a;

	int n = gcd(temp.p, temp.q);
	temp.p /= n;
	temp.q /= n;

	return temp;
}

fraction operator+(int a, fraction ob) {		// friend 함수: int a + ob
	fraction temp;
	temp.p = ob.p + a * ob.q;
	temp.q = ob.q;

	int n = gcd(temp.p, temp.q);
	temp.p /= n;
	temp.q /= n;

	return temp;
}

fraction operator-(int a, fraction ob) {		// friend 함수: int a - ob
	fraction temp;
	temp.p = a * ob.q - ob.p;
	temp.q = ob.q;

	int n = gcd(temp.p, temp.q);
	temp.p /= n;
	temp.q /= n;

	return temp;
}

fraction operator*(int a, fraction ob) {		// friend 함수: int a * ob
	fraction temp;
	temp.p = a * ob.p;
	temp.q = ob.q;

	int n = gcd(temp.p, temp.q);
	temp.p /= n;
	temp.q /= n;

	return temp;
}

fraction operator/(int a, fraction ob) {		// friend 함수: int a / ob
	fraction temp;
	temp.p = a * ob.q;
	temp.q = ob.p;

	int n = gcd(temp.p, temp.q);
	temp.p /= n;
	temp.q /= n;

	return temp;
}

fraction operator+(double a, fraction ob) {		// friend 함수: double a + ob
	fraction temp;

	double numerator = a;
	int denominator = 1;
	while (numerator - (int)numerator != 0)		// 소수 형태의 숫자를 분수 형태로 변환
	{
		numerator *= 10;
		denominator *= 10;
	}
	temp.p = denominator * ob.p + numerator * ob.q;
	temp.q = denominator * ob.q;

	int n = gcd(temp.p, temp.q);
	temp.p /= n;
	temp.q /= n;

	return temp;
}


int gcd(int a, int b) {
	int R;
	if (a < 0)
		a = -a;
	else if (b < 0)
		b = -b;

	while ((a % b) > 0) {
		R = a % b;
		a = b;
		b = R;
	}
	return b;
}

int main()
{
	fraction obtest(7, 3), ob0(2, 4), ob1(5, 8), ob2(2, 7), ob3, ob4, ob5, ob6, ob7, ob8, ob9, ob10, ob11, ob12, ob13, ob14, ob15;
	//fraction ob[20] = { fraction(7,3), fraction(2,4),fraction(5, 8), fraction(2, 7),fraction() };

	ob0.show();	// 약분 작동 검사

	ob3 = ob1 + ob2;	// ob1 + ob2
	ob3.show();

	ob4 = ob1 - ob2;	// ob1 - ob2
	ob4.show();

	ob5 = ob1 * ob2;
	ob5.show();

	ob6 = ob1 / ob2;
	ob6.show();

	ob7 = ob1 + 5;		// ob + int a
	ob7.show();

	ob8 = ob1 - 2;		// ob - int a
	cout << "ob - int a: ";
	ob8.show();

	ob9 = ob1 * 5;		// ob * int a
	ob9.show();

	ob10 = ob1 / 5;		// ob / int a
	ob10.show();

	ob11 = 3 + ob1;		// int a + ob 
	ob11.show();

	ob12 = 1 - obtest;		// int a - ob 
	cout << "int a - ob: ";
	ob12.show();

	ob13 = 5 * ob1;		// int a * ob 
	ob13.show();

	ob14 = 5 / ob1;		// int a / ob 
	ob14.show();

	ob15 = 3.14 + ob1;	// double a + ob
	ob15.show();

	//////
	//////

	//ob[4] = ob[1] + ob[2];	// ob1 + ob2
	//ob[4].show();

	//ob4 = ob1 - ob2;	// ob1 - ob2
	//ob4.show();

	//ob5 = ob1 * ob2;
	//ob5.show();

	//ob6 = ob1 / ob2;
	//ob6.show();

	//ob7 = ob1 + 5;		// ob + int a
	//ob7.show();

	//ob8 = ob1 - 2;		// ob - int a
	//cout << "ob - int a: ";
	//ob8.show();

	//ob9 = ob1 * 5;		// ob * int a
	//ob9.show();

	//ob10 = ob1 / 5;		// ob / int a
	//ob10.show();

	//ob11 = 3 + ob1;		// int a + ob 
	//ob11.show();

	//ob12 = 1 - obtest;		// int a - ob 
	//cout << "int a - ob: ";
	//ob12.show();

	//ob13 = 5 * ob1;		// int a * ob 
	//ob13.show();

	//ob14 = 5 / ob1;		// int a / ob 
	//ob14.show();

	//ob15 = 3.14 + ob1;	// double a + ob
	//ob15.show();



}