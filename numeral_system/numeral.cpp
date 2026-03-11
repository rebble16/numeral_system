#include "numeral.h"

void numeral::decimal_to_binary()
{
	output = "";
	from = "decimal";
	into = "binary";
	int original_input = input;
	s_input = std::to_string(input);
	int out = input;
	int save = 0;
	string ans;
	while (out / binary_base != 0)
	{
		save = out % binary_base;
		if (save == 1)output += "1";
		else output += "0";
		out = out / binary_base;
	}
	save = out % binary_base;
	if (save == 1)output += "1";
	else output += "0";
	for (int i=output.length()-1; i>=0; i--)
	{
		ans +=output[i];
	}
	output = ans;
	s_input = original_input;
}

void numeral::decimal_to_hex()
{
	output = "";
	from = "decimal";
	into = "hex";
	int original_input = input;
	s_input = std::to_string(input);
	output = "";
	int out = input;
	int save = 0;
	string ans;
	while (out / hex_base != 0)
	{
		save = out % hex_base;
		if (save == 0)output += "0";
		else if (save == 1)output += "1";
		else if (save == 2)output += "2";
		else if (save == 3)output += "3";
		else if (save == 4)output += "4";
		else if (save == 5)output += "5";
		else if (save == 6)output += "6";
		else if (save == 7)output += "7";
		else if (save == 8)output += "8";
		else if (save == 9)output += "9";
		else if (save == 10)output += "A";
		else if (save == 11)output += "B";
		else if (save == 12)output += "C";
		else if (save == 13)output += "D";
		else if (save == 14)output += "E";
		else output += "F";
		out = out / hex_base;
	}
	save = out % hex_base;
	if (save == 0)output += "0";
	else if (save == 1)output += "1";
	else if (save == 2)output += "2";
	else if (save == 3)output += "3";
	else if (save == 4)output += "4";
	else if (save == 5)output += "5";
	else if (save == 6)output += "6";
	else if (save == 7)output += "7";
	else if (save == 8)output += "8";
	else if (save == 9)output += "9";
	else if (save == 10)output += "A";
	else if (save == 11)output += "B";
	else if (save == 12)output += "C";
	else if (save == 13)output += "D";
	else if (save == 14)output += "E";
	else output += "F";
	for (int i = output.length() - 1; i >= 0; i--)
	{
		ans += output[i];
	}
	output = ans;
	s_input = std::to_string(original_input);
}

void numeral::decimal_to_octal()
{
	output = "";
	from = "decimal";
	into = "octal";
	int original_input = input;
	s_input = std::to_string(input);
	if (input == 0) {
		output = "0";
		cout << "octal: " << output << endl;
		return;
	}
	int save = 0;
	int ans=0;
	int in = input;
	string temp="";
	while (in / octal_base != 0)
	{
		save = in % octal_base;
		if (save == 0)temp += "0";
		else if (save == 1)temp += "1";
		else if (save == 2)temp += "2";
		else if (save == 3)temp += "3";
		else if (save == 4)temp += "4";
		else if (save == 5)temp += "5";
		else if (save == 6)temp += "6";
		else temp += "7";
		in = in / octal_base;
	}
	save = in % octal_base;
	if (save == 0)temp += "0";
	else if (save == 1)temp += "1";
	else if (save == 2)temp += "2";
	else if (save == 3)temp += "3";
	else if (save == 4)temp += "4";
	else if (save == 5)temp += "5";
	else if (save == 6)temp += "6";
	else temp += "7";
	for (int i = temp.length() - 1; i >= 0; i--)
	{
		output += temp[i];
	}
	s_input = std::to_string(original_input);
}

void numeral::binary_to_decimal()
{
	output = "";
	string original_input = s_input;
	from = "binary";
	into = "decimal";
	if (s_input.empty())
	{
		cout << "Empty input!" << endl;
		return;
	}
	int ans = 0;
	int temp = 0;
	int counter = 0;
	for (int i = s_input.length()-1; i >= 0; i--)
	{
		if (s_input[i] == '1')temp = 1;
		else temp = 0;
		ans += temp*pow(binary_base, counter);
		counter++;
	}
	output = std::to_string(ans);
	s_input = original_input;
}

void numeral::binary_to_octal()
{
	output = "";
	string original_input = s_input;
	if (s_input.empty())
	{
		cout << "Empty input!" << endl;
		return;
	}
	binary_to_decimal();
	string s = output;
	int ans = 0;
	input=convert_string_to_int(s);
	decimal_to_octal();
	from = "binary";
	into = "octal";
	s_input = original_input;
}

void numeral::binary_to_hex()
{
	output = "";
	string original_input = s_input;
	if (s_input.empty())
	{
		cout << "Empty input!" << endl;
		return;
	}
	binary_to_decimal();
	string s = output;
	int ans = 0;
	input = convert_string_to_int(s);
	decimal_to_hex();
	from = "binary";
	into = "hex";
	s_input = original_input;
}

void numeral::octal_to_binary()//преобразовать в десятичную,а потом в двоичную
{
	output = "";
	s_input = std::to_string(input);
	int original_input = input;
	octal_to_decimal();
	int temp = convert_string_to_int(output);
	input = temp;
	decimal_to_binary();
	from = "octal";
	into = "binary";
	input = original_input;
	s_input = std::to_string(original_input);
}

void numeral::octal_to_decimal()
{
	output = "";
	from = "octal";
	into = "decimal";
	int original_input = input;
	s_input = std::to_string(input);
	int n = input;
	int temp = 0;
	int ans = 0;
	int counter = 0;
	while (n / decimal_base != 0)
	{
		temp = n % decimal_base;
		n = n / decimal_base;
		ans += temp * pow(octal_base, counter);
		counter++;
	}
	temp = n % decimal_base;
	ans += temp * pow(octal_base, counter);
	output = std::to_string(ans);
	s_input = std::to_string(original_input);
}

void numeral::octal_to_hex()
{
	output = "";
	s_input = std::to_string(input);
	int original_input = input;
	octal_to_decimal();
	int temp = convert_string_to_int(output);
	input = temp;
	decimal_to_hex();
	from = "octal";
	into = "hex";
	input = original_input;
	s_input = std::to_string(original_input);

}

void numeral::hex_to_binary()
{
	output = "";
	string original_input = s_input;
	hex_to_decimal();
	int temp= convert_string_to_int(output);
	input = temp;
	decimal_to_binary();
	from = "hex";
	into = "binary";
	input = convert_string_to_int(original_input);
	s_input= original_input;
}

void numeral::hex_to_octal()
{
	output = "";
	string original_input = s_input;
	hex_to_decimal();
	int temp = convert_string_to_int(output);
	input = temp;
	decimal_to_octal();
	from = "hex";
	into = "octal";
	input = convert_string_to_int(original_input);
	s_input = original_input;
}

void numeral::hex_to_decimal()
{
	output = "";
	from = "hex";
	into = "decimal";
	string original_input = s_input;
	int temp = 0;
	int ans = 0;
	int counter = 0;
	for (int i = s_input.length() - 1; i >= 0; i--)
	{
		if (s_input[i] == '0')temp = 0;
		else if (s_input[i] == '1')temp = 1;
		else if (s_input[i] == '2')temp = 2;
		else if (s_input[i] == '3')temp = 3;
		else if (s_input[i] == '4')temp = 4;
		else if (s_input[i] == '5')temp = 5;
		else if (s_input[i] == '6')temp = 6;
		else if (s_input[i] == '7')temp = 7;
		else if (s_input[i] == '8')temp = 8;
		else if (s_input[i] == '9')temp = 9;
		else if (s_input[i] == 'A')temp = 10;
		else if (s_input[i] == 'B')temp = 11;
		else if (s_input[i] == 'C')temp = 12;
		else if (s_input[i] == 'D')temp = 13;
		else if (s_input[i] == 'E')temp = 14;
		else temp = 15;
		ans += temp * pow(hex_base, counter);
		counter++;
	}
	output = std::to_string(ans);
	s_input = original_input;
}

int numeral::convert_string_to_int(string& s)
{
	int ans = 0;
	int temp = 0;
	int power = 1;//степень(единицы,десятки и т.д.)
	for (int i = s.length() - 1; i >= 0; i--)
	{
		if (s[i] == '0')temp = 0;
		else if (s[i] == '1')temp = 1;
		else if (s[i] == '2')temp = 2;
		else if (s[i] == '3')temp = 3;
		else if (s[i] == '4')temp = 4;
		else if (s[i] == '5')temp = 5;
		else if (s[i] == '6')temp = 6;
		else if (s[i] == '7')temp = 7;
		else if (s[i] == '8')temp = 8;
		else temp = 9;
		ans += temp * power;
		power *= 10;
	}
	return ans;
}

ostream& operator<<(ostream& os, numeral& obj)
{
	os << "From " << obj.from << ":" << obj.s_input << '\t' << " into " << obj.into << ":" << obj.output  << endl << endl;;
	return os;
}
