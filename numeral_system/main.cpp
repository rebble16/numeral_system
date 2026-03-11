#include"numeral.h"
int main()
{
	//из десятичной в 2,8,16-ричные системы
	numeral a(1000001);
	//a.decimal_to_binary();
	a.decimal_to_hex();
	cout << a;
	//из двоичной в 8,10,16-ричные системы
	numeral b("1111111111111");
	//b.binary_to_decimal();
	b.binary_to_octal();
	cout << b;
	//из восьмеричной в 2,10,16-ричные системы
	numeral c(123);
	//c.octal_to_hex();
	c.octal_to_binary();
	cout << c;
	//из шестнадцатиричной в 2,8,10-ричные системы
	numeral d("9ABCDEF");
	//d.hex_to_decimal();
	d.hex_to_binary();
	cout << d;
	return 0;
}