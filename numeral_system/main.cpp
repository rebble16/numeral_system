#include"numeral.h"
int main()
{
	setlocale(LC_ALL,"ru");
	//èç äåñÿòè÷íîé â 2,8,16-ðè÷íûå ñèñòåìû
	numeral a(1000001);
	//a.decimal_to_binary();
	a.decimal_to_hex();
	cout << a;
	//èç äâîè÷íîé â 8,10,16-ðè÷íûå ñèñòåìû
	numeral b("1111111111111");
	//b.binary_to_decimal();
	b.binary_to_octal();
	cout << b;
	//èç âîñüìåðè÷íîé â 2,10,16-ðè÷íûå ñèñòåìû
	numeral c(123);
	//c.octal_to_hex();
	c.octal_to_binary();
	cout << c;
	//èç øåñòíàäöàòèðè÷íîé â 2,8,10-ðè÷íûå ñèñòåìû
	numeral d("9ABCDEF");
	//d.hex_to_decimal();
	d.hex_to_binary();
	cout << d;
	return 0;
}
