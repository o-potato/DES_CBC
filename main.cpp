#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "des.h"
using namespace std;

int main()
{
	int mode;
	cout << "��ѡ�����ģʽ or ����ģʽ��" << endl << "0 - ����" << endl << "1 - ����" << endl;
	cin >> mode;

	string file_path;
	cout << "��������Կ�ļ�(.txt�ļ�)·����" << endl;
	cin >> file_path;

	//����һ���ļ�������,���򿪴洢��Կ��.txt�ļ�
	ifstream keyfile(file_path);
	if (!keyfile) {
		cout << "Unable to open the file!" << endl;
		exit(1);
	}
	//��ȡ��Կ
	string key;
	keyfile >> key;

	cout << "�����������/�����ļ�(.txt�ļ�)��·����" << endl;
	cin >> file_path;

	//�򿪴洢�����/���ܵ��ļ�
	ifstream datafile(file_path);
	if (!datafile) {
		cout << "Unable to open the file!" << endl;
		exit(1);
	}
	//���ļ����뵽ostringstream�ַ���������buf��
	ostringstream buf;
	buf << datafile.rdbuf(); // ���ļ����е��ַ����뵽�ַ�������
	//������������buf�������ַ���
	string text = buf.str();
	//cout << "data: ";
	//cout << text << endl << endl;

	//char c = '0';
	//cout << text.length() << endl;
	//cout << text << endl;
	while (text.length() % 64 != 0)	//���Ĳ���64λ�Զ���0
		text = text + '0';
	//cout << text.length() << endl;
	//cout << text << endl;

	string cipher;
	string plaintext;
	ofstream result_file("result.txt");

	//ʹ�÷�������ģʽ
	string init_vector = key;	//�趨�������ӵĳ�ʼ����Ϊ��Կ
	if (mode == 0) {
		cipher = CBC(text, key, init_vector, en);
		result_file << cipher;
	}
	if (mode == 1) {
		plaintext = CBC(text, key, init_vector, de);
		result_file << plaintext;
	}

	cout << "Your result is saved in result.txt!" << endl;

	keyfile.close();
	datafile.close();
	result_file.close();

	system("pause");
	return 0;
}


//string byte2bit(string byte)
//{//�ַ���ת���ش�
//	int length = byte.length();
//	string bit(length * 8, 0);
//	for (int i = 0; i < length; i++) {
//		for (int j = 0; j < 8; j++) {
//			bit[i * 8 + j] = (byte[i] >> (7 - j)) & 1;
//		}
//	}
//	return bit;
//}

//string bit2byte(string bit)
//{//���ش�ת�ַ���
//	int length = bit.length() / 8;
//	string byte(length, 0);
//	for (int i = 0; i < length; i++)
//	{
//		byte[i] = 0;
//		for (int j = 0; j < 8; j++)
//			byte[i] = (byte[i] << 1) + bit[i * 8 + j];
//	}
//	return byte;
//}

//string hex2bit(string hex)
//{//ʮ�������ַ���ת���ش�
//	int length = hex.length();
//	string bit(length * 4, 0);
//	for (int i = 0; i < length; i++)
//	{
//		hex[i] -= 48;
//		if (hex[i] > 9)
//			hex[i] -= 7;
//		for (int j = 0; j < 4; j++)
//			bit[i * 4 + j] = (hex[i] >> (3 - j)) & 1;
//	}
//	return bit;
//}

//string bit2hex(string bit)
//{//���ش�תʮ�������ַ���
//	int length = bit.length() / 4;
//	string hex(length, 0);
//	for (int i = 0; i < length; i++)
//	{
//		hex[i] = 0;
//		for (int j = 0; j < 4; j++)
//			hex[i] = (hex[i] << 1) + bit[i * 4 + j];
//		hex[i] += 48;
//		if (hex[i] > 57)
//			hex[i] += 7;
//	}
//	return hex;
//}

//void output(string s)
//{//����������ַ���
//	cout << s.length() << "\t";
//	for (int i = 0; i < s.length(); i++)
//	{
//		if (s[i] == 1)
//			cout << 1;
//		else
//			cout << 0;
//	}
//	cout << endl;
//}

