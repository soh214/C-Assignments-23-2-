// 과제3 (팀원: 오승수)

#include <iostream>

using namespace std;
int gcd(int a, int b);

class fraction {
	int p, q;	// p: numerator, q:denominator		p/q
public:
	void show();
	void doubleshow();

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
	fraction operator+(fraction ob);	// ob1 + ob2
	fraction operator-(fraction ob);
	fraction operator*(fraction ob);
	fraction operator/(fraction ob);

	fraction operator+(int a);  // ob +-*/ int a
	fraction operator-(int a);
	fraction operator*(int a);
	fraction operator/(int a);
	
	
	friend fraction operator+(int a, fraction ob);	// friend 함수     int a +-*/ ob
	friend fraction operator-(int a, fraction ob);	
	friend fraction operator*(int a, fraction ob);	
	friend fraction operator/(int a, fraction ob);	

	friend fraction operator+(double a, fraction ob);	// friend function    double a +-*/ ob
	friend fraction operator-(double a, fraction ob);	
	friend fraction operator*(double a, fraction ob);	
	friend fraction operator/(double a, fraction ob);	


	friend fraction operator+(fraction ob, double a);	// friend function     ob + double a
	friend fraction operator-(fraction ob, double a);
	friend fraction operator*(fraction ob, double a);
	friend fraction operator/(fraction ob, double a);

	fraction& operator+=(fraction ob);	// ob1 += ob2 
	fraction& operator-=(fraction ob);
	fraction& operator*=(fraction ob);
	fraction& operator/=(fraction ob);


	fraction& operator+=(int a);		// ob1 += int a
	fraction& operator-=(int a);		
	fraction& operator*=(int a);		
	fraction& operator/=(int a);	

	fraction& operator+=(double a);		// ob1 += double a
	fraction& operator-=(double a);		
	fraction& operator*=(double a);		
	fraction& operator/=(double a);		



};

void fraction::show() {					// 값을 분수 형태로 표시
	if (q == 1)					
		cout << p << endl;				// 분모가 1이면 분자만 표시 (정수 형태로 표시)
	else
		cout << p << "/" << q << endl;
}
void fraction::doubleshow() {			// 분수를 소수형태로 표시
	cout << (double)p / q << endl;
}

fraction fraction::operator+(fraction ob) {		// ob1 + ob2
	fraction temp;
	temp.p = p * ob.q + q * ob.p;
	temp.q = q * ob.q;

	int n = gcd(temp.p, temp.q);			// 결과값 약분
	temp.p /= n;
	temp.q /= n;

	return temp;
}
fraction fraction::operator-(fraction ob) {		// ob1 - ob2
	fraction temp;
	temp.p = p * ob.q - q* ob.p;
	temp.q = q * ob.q;

	int n = gcd(temp.p, temp.q);			
	temp.p /= n;
	temp.q /= n;

	return temp;
}

fraction fraction::operator*(fraction ob) {		// ob1 * ob2
	fraction temp;
	temp.p = p * ob.p;
	temp.q = q * ob.q;

	int n = gcd(temp.p, temp.q);
	temp.p /= n;
	temp.q /= n;

	return temp;
}

fraction fraction::operator/(fraction ob) {		// ob1 / ob2
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

fraction operator-(double a, fraction ob) {		// friend 함수: double a - ob
	fraction temp;

	double numerator = a;
	int denominator = 1;
	while (numerator - (int)numerator != 0)		// 소수 형태의 숫자를 분수 형태로 변환
	{
		numerator *= 10;
		denominator *= 10;
	}
	temp.p = numerator * ob.q - denominator * ob.p;
	temp.q = denominator * ob.q;

	int n = gcd(temp.p, temp.q);
	temp.p /= n;
	temp.q /= n;

	return temp;
}

fraction operator*(double a, fraction ob) {		// friend 함수: double a * ob
	fraction temp;

	double numerator = a;
	int denominator = 1;
	while (numerator - (int)numerator != 0)		// 소수 형태의 숫자를 분수 형태로 변환
	{
		numerator *= 10;
		denominator *= 10;
	}
	temp.p = numerator * ob.p;
	temp.q = denominator * ob.q;

	int n = gcd(temp.p, temp.q);
	temp.p /= n;
	temp.q /= n;

	return temp;
}

fraction operator/(double a, fraction ob) {		// friend 함수: double a / ob
	fraction temp;

	double numerator = a;
	int denominator = 1;
	while (numerator - (int)numerator != 0)		// 소수 형태의 숫자를 분수 형태로 변환
	{
		numerator *= 10;
		denominator *= 10;
	}
	temp.p = numerator * ob.q;
	temp.q = denominator * ob.p;

	int n = gcd(temp.p, temp.q);
	temp.p /= n;
	temp.q /= n;

	return temp;
}

fraction operator+(fraction ob, double a) {		// friend 함수: ob + double a
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
fraction operator-(fraction ob, double a) {		// friend 함수: ob - double a
	fraction temp;

	double numerator = a;
	int denominator = 1;
	while (numerator - (int)numerator != 0)		// 소수 형태의 숫자를 분수 형태로 변환
	{
		numerator *= 10;
		denominator *= 10;
	}
	temp.p = denominator * ob.p - numerator * ob.q;
	temp.q = denominator * ob.q;

	int n = gcd(temp.p, temp.q);
	temp.p /= n;
	temp.q /= n;

	return temp;
}
fraction operator*(fraction ob, double a) {		// friend 함수: ob * double a
	fraction temp;

	double numerator = a;
	int denominator = 1;
	while (numerator - (int)numerator != 0)		// 소수 형태의 숫자를 분수 형태로 변환
	{
		numerator *= 10;
		denominator *= 10;
	}
	temp.p = numerator * ob.p;
	temp.q = denominator * ob.q;

	int n = gcd(temp.p, temp.q);
	temp.p /= n;
	temp.q /= n;

	return temp;
}
fraction operator/(fraction ob, double a) {		// friend 함수: ob / double a
	fraction temp;

	double numerator = a;
	int denominator = 1;
	while (numerator - (int)numerator != 0)		// 소수 형태의 숫자를 분수 형태로 변환
	{
		numerator *= 10;
		denominator *= 10;
	}
	temp.p = denominator * ob.p;
	temp.q = numerator * ob.q;

	int n = gcd(temp.p, temp.q);
	temp.p /= n;
	temp.q /= n;

	return temp;
}
fraction& fraction::operator+=(fraction ob) {	// ob1 += ob2 
	
	p = p * ob.q + q * ob.p;
	q = q * ob.q;

	int n = gcd(p, q);
	p /= n;
	q /= n;

	return *this;
}
fraction& fraction::operator-=(fraction ob) {	// ob1 -= ob2 

	p = p * ob.q - q * ob.p;
	q = q * ob.q;

	int n = gcd(p, q);
	p /= n;
	q /= n;

	return *this;
}

fraction& fraction::operator*=(fraction ob) {	// ob1 *= ob2 

	p = p * ob.p;
	q = q * ob.q;

	int n = gcd(p, q);
	p /= n;
	q /= n;

	return *this;
}
fraction& fraction::operator/=(fraction ob) {	// ob1 /= ob2 

	p = p * ob.q;
	q = q * ob.p;

	int n = gcd(p, q);
	p /= n;
	q /= n;

	return *this;
}

fraction& fraction::operator+=(int a) {		// ob1 += int a

	p = p + q * a;
	q = q;

	int n = gcd(p, q);
	p /= n;
	q /= n;

	return *this;
}

fraction& fraction::operator-=(int a) {		// ob1 -= int a

	p = p - q * a;
	q = q;

	int n = gcd(p, q);
	p /= n;
	q /= n;

	return *this;
}

fraction& fraction::operator*=(int a) {		// ob1 *= int a

	p = p*a;
	q = q;

	int n = gcd(p, q);
	p /= n;
	q /= n;

	return *this;
}

fraction& fraction::operator/=(int a) {		// ob1 /= int a

	p = p;
	q = q*a;

	int n = gcd(p, q);
	p /= n;
	q /= n;

	return *this;
}

fraction& fraction::operator+=(double a) {		// ob1 += double a

	double numerator = a;
	int denominator = 1;
	while (numerator - (int)numerator != 0)		// 소수 형태의 숫자를 분수 형태로 변환
	{
		numerator *= 10;
		denominator *= 10;
	}
	p = denominator * p + numerator * q;
	q = denominator * q;

	int n = gcd(p, q);
	p /= n;
	q /= n;

	return *this;
}

fraction& fraction::operator-=(double a) {		// ob1 -= double a

	double numerator = a;
	int denominator = 1;
	while (numerator - (int)numerator != 0)		// 소수 형태의 숫자를 분수 형태로 변환
	{
		numerator *= 10;
		denominator *= 10;
	}
	p = denominator * p - numerator * q;
	q = denominator * q;

	int n = gcd(p, q);
	p /= n;
	q /= n;

	return *this;
}

fraction& fraction::operator*=(double a) {		// ob1 *= double a

	double numerator = a;
	int denominator = 1;
	while (numerator - (int)numerator != 0)		// 소수 형태의 숫자를 분수 형태로 변환
	{
		numerator *= 10;
		denominator *= 10;
	}
	p = numerator * p;
	q = denominator * q;

	int n = gcd(p, q);
	p /= n;
	q /= n;

	return *this;
}

fraction& fraction::operator/=(double a) {		// ob1 /= double a

	int numerator = 1;
	double denominator = a;
	while (denominator - (int)denominator != 0)		// 소수 형태의 숫자를 분수 형태로 변환
	{
		numerator *= 10;
		denominator *= 10;
	}
	p = numerator * p;
	q = denominator * q;

	int n = gcd(p, q);
	p /= n;
	q /= n;

	return *this;
}


int gcd(int a, int b) {		// 최대 공약수
	int R;
	if (a < 0)			// 음수 대응
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
	fraction ob[25] = { fraction (7,3), fraction (5,8),fraction(2,7), fraction() };


	ob[4] = ob[1] + ob[2];	// ob1 + ob2
	ob[4].show();

	ob[5] = ob[1] - ob[2];	// ob1 - ob2
	ob[5].show();

	ob[6] = ob[1] * ob[2];
	ob[6].show();

	ob[7] = ob[1] / ob[2];
	ob[7].show();

	ob[8] = ob[1] + 5;		// ob + int a
	ob[8].show();

	ob[9] = ob[1] - 2;		// ob - int a
	cout << "ob - int a: ";
	ob[9].show();

	ob[10] = ob[1] * 5;		// ob * int a
	ob[10].show();

	ob[11] = ob[1] / 5;		// ob / int a
	ob[11].show();

	ob[12] = 3 + ob[1];		// int a + ob 
	ob[12].show();

	ob[13] = 1 - ob[0];		// int a - ob 
	cout << "int a - ob: ";
	ob[13].show();

	ob[14] = 5 * ob[1];		// int a * ob 
	ob[14].show();

	ob[15] = 5 / ob[1];		// int a / ob 
	ob[15].show();

	ob[16] = 3.14 + ob[1];	// double a + ob
	ob[16].show();

	ob[17] = 3.14 - ob[1];	// double a - ob
	ob[17].show();
	cout << "위의 분수를 소수 형태로 나타내면: "; ob[17].doubleshow();

	ob[18] = 3.14 * ob[1];	// double a * ob
	ob[18].show();
	cout << "위의 분수를 소수 형태로 나타내면: "; ob[18].doubleshow();

	ob[19] = 3.14 / ob[1];	// double a / ob
	ob[19].show();
	cout << "위의 분수를 소수 형태로 나타내면: "; ob[19].doubleshow();

	ob[20] = ob[1] + 3.14;	// ob + double a
	ob[20].show();
	cout << "위의 분수를 소수 형태로 나타내면: "; ob[20].doubleshow();

	ob[21] = ob[1] - 3.14;	// ob - double a
	ob[21].show();
	cout << "위의 분수를 소수 형태로 나타내면: "; ob[21].doubleshow();

	ob[22] = ob[1] * 3.14;	// ob * double a
	ob[22].show();
	cout << "위의 분수를 소수 형태로 나타내면: "; ob[22].doubleshow();

	ob[23] = ob[1] / 3.14;	// ob / double a
	ob[23].show();
	cout << "위의 분수를 소수 형태로 나타내면: "; ob[23].doubleshow();

	fraction ob0(13,15);			// 연산자 중복함수 / 프렌드 함수 작성을 검증하기 위해 계산되는 분수(ob)를 매번 다른 값으로 초기화
	ob0 += ob[1];	// ob1 += ob2
	ob0.show();
	cout << "위의 분수를 소수 형태로 나타내면: "; ob0.doubleshow();

	fraction ob1(14, 15);
	ob1 -= ob[1];	// ob1 -= ob2
	ob1.show();
	cout << "위의 분수를 소수 형태로 나타내면: "; ob1.doubleshow();

	fraction ob2(16, 15);
	ob2 *= ob[1];	// ob1 *= ob2
	ob2.show();
	cout << "위의 분수를 소수 형태로 나타내면: "; ob2.doubleshow();

	fraction ob3(17, 15);
	ob3 /= ob[1];	// ob1 /= ob2
	ob3.show();
	cout << "위의 분수를 소수 형태로 나타내면: "; ob3.doubleshow();

	fraction ob4(18, 15);
	ob4 += 3;		// ob1 += int a
	ob4.show();
	cout << "위의 분수(ob4)를 소수 형태로 나타내면: "; ob4.doubleshow();

	fraction ob5(19, 15);
	ob5 -= 3;		// ob1 -= int a
	ob5.show();
	cout << "위의 분수(ob5)를 소수 형태로 나타내면: "; ob5.doubleshow();

	fraction ob6(20, 15);
	ob6 *= 3;		// ob1 *= int a
	ob6.show();
	cout << "위의 분수(ob6)를 소수 형태로 나타내면: "; ob6.doubleshow();

	fraction ob7(21, 15);
	ob7 /= 3;		// ob1 /= int a
	ob7.show();
	cout << "위의 분수(ob7)를 소수 형태로 나타내면: "; ob7.doubleshow();

	fraction ob8(21, 15);
	ob8 += 3.4;		// ob1 += double a
	ob8.show();
	cout << "위의 분수(ob8)를 소수 형태로 나타내면: "; ob8.doubleshow();

	fraction ob9(22, 15);
	ob9 -= 3.4;		// ob1 -= double a
	ob9.show();
	cout << "위의 분수(ob9)를 소수 형태로 나타내면: "; ob9.doubleshow();

	fraction ob10(23, 15);
	ob10 *= 3.4;		// ob1 *= double a
	ob10.show();
	cout << "위의 분수(ob10)를 소수 형태로 나타내면: "; ob10.doubleshow();

	fraction ob11(24, 15);
	ob11 /= 3.4;		// ob1 /= double a
	ob11.show();
	cout << "위의 분수(ob11)를 소수 형태로 나타내면: "; ob11.doubleshow();


}