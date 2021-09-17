#include <iostream>
#include <bitset>

using namespace std;

void ex1_1()
{
	unsigned int x;
	cout << "Vvedite x: " << endl;
	cin >> x;
	unsigned maska = 0x80;
	cout << "maska = " << maska << endl;
	x = x | maska;
	cout << "izmenen perviy bit: " << x << endl;
}

void ex1_2()
{
	unsigned int x;
	cout << "Vvedite x: " << endl;
	cin >> x;
	unsigned maska = 0x40;
	cout << "maska = " << maska << endl;
	x = x | maska;
	cout << "izmenen vtoroi bit: " << x << endl;
}

void ex1_3()
{
	unsigned int x;
	cout << "Vvedite x: " << endl;
	cin >> x;
	unsigned maska = 0x02;
	cout << "maska = " << maska << endl;
	x = x | maska;
	cout << "izmenen sed'moi bit: " << x;
}

void ex2() 
{
	unsigned int x;
	cout << "Vvedite x: " << endl;
	cin >> x;
	unsigned maska = 0xF1;
	cout << "maska = " << maska << endl;
	cout << x << endl;
	x = x & maska;
	cout << x;
}

void ex3() 
{
	unsigned int x;
	cout << "Vvedite x: " << endl;
	cin >> x;
	unsigned maska = 0x03;
	cout << "maska = " << maska << endl;
	cout << x << endl;
	x = x << maska;
	cout << x;
}

void ex4()
{
	unsigned int x;
	cout << "Vvedite x: " << endl;
	cin >> x;
	unsigned maska = 0x03;
	cout << "maska = " << maska << endl;
	cout << x << endl;
	x = x >> maska;
	cout << x;
}

void ex5()
{
	unsigned int x, check;
	cout << "Vvedite x: ";
	cin >> x;
	unsigned int n;
	cout << "Vvedite n: ";
	cin >> n;
	unsigned maska = 0x01;
	x = x & ((~maska << n - 1) | ((~(~maska << n - 1)) >> 1));
	cout << x << endl;
}

int main() 
{
	int a;
	bool b = 1;
	unsigned short int x;
	while (b == true) {
		cout << "Vvedite nomer zadaniya: " << endl << "1) 1_1" << endl << "2) 1_2" << endl << "3) 1_3" << endl << "4) 2" << endl << "5) 3" << endl << "6) 4" << endl << "7) 5" << endl << "0) exit" << endl;
		cin >> a;
		switch (a)
		{
		case 0:
			b = false;
			break;
		case 1:
			ex1_1();
			break;
		case 2:
			ex1_2();
			break;
		case 3:
			ex1_3();
			break;
		case 4:
			ex2();
			break;
		case 5:
			ex3();
			break;
		case 6:
			ex4();
			break;
		case 7:
			ex5();
			break;
		}
	}
}