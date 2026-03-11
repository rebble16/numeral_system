#pragma once
#include<string>
#include<iostream>
using std::string;
using std::cout;
using std::endl;
using std::ostream;
const int hex_base = 16;
const int binary_base = 2;
const int octal_base = 8;
const int decimal_base = 10;
class numeral
{
private:
	int input;
	string s_input;
	string output;
	string from;
	string into;
public:
	numeral(int in = 0, string s_in = "",string f="",string i="") :input(in), s_input(s_in),from(f),into(i) {}
	numeral(string s_in = "",int in = 0, string f = "", string i = "") :input(in), s_input(s_in), from(f), into(i) {}
	void decimal_to_binary();
	void decimal_to_hex();
	void decimal_to_octal();
	void binary_to_decimal();
	void binary_to_octal();
	void binary_to_hex();
	void octal_to_binary();
	void octal_to_decimal();
	void octal_to_hex();
	void hex_to_binary();
	void hex_to_octal();
	void hex_to_decimal();
	int convert_string_to_int(string& s);//конвертировать переменную string в int
	friend ostream& operator<<(ostream& os, numeral& obj);
};
