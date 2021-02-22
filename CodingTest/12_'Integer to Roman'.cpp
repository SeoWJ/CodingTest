#include <iostream>

using namespace std;

class Solution {
public:
	string convert(int num) {
		string result = "";
		
		if (num == 0)
			return "";

		if (num >= 1000) {            
			for (int i = 0; i < num / 1000; i++)
				result += "M";
			return result;
		}
		else if (num >= 100) {
			if (num < 400) {
				for (int i = 0; i < num / 100; i++)
					result += "C";
				return result;
			}
			else {
				if (num == 400)
					return "CD";
				else if (num == 900)
					return "CM";
				else {
					num -= 500;
					result += "D";
					for (int i = 0; i < num / 100; i++)
						result += "C";
					return result;
				}
			}
		}
		else if (num >= 10) {
			if (num < 40) {
				for (int i = 0; i < num / 10; i++)
					result += "X";
				return result;
			}
			else {
				if (num == 40)
					return "XL";
				else if (num == 90)
					return "XC";
				else {
					num -= 50;
					result += "L";
					for (int i = 0; i < num / 10; i++)
						result += "X";
					return result;
				}
			}
		}
		else {
			if (num < 4) {
				for (int i = 0; i < num; i++)
					result += "I";
				return result;
			}
			else {
				if (num == 4)
					return "IV";
				else if (num == 9)
					return "IX";
				else {
					num -= 5;
					result += "V";
					for (int i = 0; i < num; i++)
						result += "I";
					return result;
				}
			}
		}
	}
	string intToRoman(int num) {
		int thousand = (num / 1000) * 1000;
		num %= 1000;
		int hundred = (num / 100) * 100;
		num %= 100;
		int ten = (num / 10) * 10;
		num %= 10;
		int one = num;

		string result = convert(thousand) + convert(hundred) + convert(ten) + convert(one);
		
		return result;
	}
};