/*
Basic Idea: 
		��ĸ���й��ж�ʮ������ĸ��ͬʱ������ֻҪ������ַ�����Ӧ������룬�ٽ�������ת����˼�룬
		���Խ�ÿ����ĸת���ɶ�ʮ��������ĳһλ�����ٽ������ַ���ת��ʮ���ƶ�Ӧ���룬�Ӷ��ɵó�
		���ַ�����������롣
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
	// ����һ��ѭ�����ɲ��������µ��ַ���
	while (getline(cin, s))
	{
		// ȷ���ַ�������
		int count = s.length();
		// ���ڵó��ַ����ı���
		sum = 0;
		for (i = count - 1; i >= 0; i--) // �Ӷ�ʮ�����Ƹ�λ��ʼ��ÿλ��ת����ʮ����
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


// ��ÿ���ַ�ת�ɶ�ʮ�������е�һλ��
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
