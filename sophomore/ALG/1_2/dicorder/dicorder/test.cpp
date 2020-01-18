/*
Basic Idea: 
		字母表中共有二十六个字母，同时此题中只要求输出字符串对应升序编码，再借助进制转换的思想，
		可以将每个字母转换成二十六进制中某一位数，再将整个字符串转成十进制对应编码，从而可得出
		该字符串的升序编码。
*/

#include<iostream>
#include<string>
#include<math.h>
using namespace std;

void chTonum(char &);

int main()
{
	string s;
	int i = 0, count, sum;
	// 设置一个循环，可不断输入新的字符串
	while (getline(cin, s))
	{
		// 确定字符串长度
		int count = s.length();
		// 用于得出字符串的编码
		sum = 0;
		for (i = count - 1; i >= 0; i--) // 从二十六进制个位开始，每位都转换成十进制
		{
			
			if (s[i] >= 'a'&&s[i] <= 'z')
			{
				chTonum(s[i]);
				sum += (s[i])*pow(26, count - i - 1);
			}
		}
		cout << sum;
	}
}


// 将每个字符转成二十六进制中的一位数
void chTonum(char &ch)
{
	switch (ch)
	{
	case 'a':
		ch = 1;
		break;
	case 'b':
		ch = 2;
		break;
	case 'c':
		ch = 3;
		break;
	case 'd':
		ch = 4;
		break;
	case 'e':
		ch = 5;
		break;
	case 'f':
		ch = 6;
		break;
	case 'g':
		ch = 7;
		break;
	case 'h':
		ch = 8;
		break;
	case 'i':
		ch = 9;
		break;
	case 'j':
		ch = 10;
		break;
	case 'k':
		ch = 11;
		break;
	case 'l':
		ch = 12;
		break;
	case 'm':
		ch = 13;
		break;
	case 'n':
		ch = 14;
		break;
	case 'o':
		ch = 15;
		break;
	case 'p':
		ch = 16;
		break;
	case 'q':
		ch = 17;
		break;
	case 'r':
		ch = 18;
		break;
	case 's':
		ch = 19;
		break;
	case 't':
		ch = 20;
		break;
	case 'u':
		ch = 21;
		break;
	case 'v':
		ch = 22;
		break;
	case 'w':
		ch = 23;
		break;
	case 'x':
		ch = 24;
		break;
	case 'y':
		ch = 25;
		break;
	case 'z':
		ch = 26;
		break;
	default:
		cout << "error" << endl;
		break;
	}
}
