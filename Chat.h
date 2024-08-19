#pragma once
#include "SHA1.h"
#include <string.h>
#include <iostream>
#define NAMELOGIN 10 // ����������� ����� ������
#define PASSWORDLENGTH 10 // ����������� ����� ������
typedef char LoginName[NAMELOGIN]; // ��� �����
typedef char Password[PASSWORDLENGTH];

class Chat
{
private:
	enum enPairStatus //��������� ������
	{
		free, // ��������
		engaged, //�����
		deleted //������
	};
	struct Pair
	{
		LoginName login;
		uint* password;
		enPairStatus status; // ��������� ������	
		Pair() :
			login(""),
			password(0),
			status(enPairStatus::free) {}
		Pair(char _login[NAMELOGIN], uint* sh1) {
			strcpy_s(login, _login);
			password = sh1;
			status = enPairStatus::engaged;
		}
	};
	int hash_func(LoginName log, int offset);
	int hf_multiply(int val);
	Pair* array;
	int mem_size;
	int count;
public:
	Chat();
	~Chat();
	void reg(char _login[NAMELOGIN], char _pass[]);
	bool login(char _login[NAMELOGIN], char _pass[]);
	void print();
	int find(LoginName log);
	void del(LoginName log);
};