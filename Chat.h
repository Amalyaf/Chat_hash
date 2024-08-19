#pragma once
#include "SHA1.h"
#include <string.h>
#include <iostream>
#define NAMELOGIN 10 // зафиксируем длину логина
#define PASSWORDLENGTH 10 // зафиксируем длину парол€
typedef char LoginName[NAMELOGIN]; // тип логин
typedef char Password[PASSWORDLENGTH];

class Chat
{
private:
	enum enPairStatus //зан€тость €чейки
	{
		free, // свободен
		engaged, //зан€т
		deleted //удален
	};
	struct Pair
	{
		LoginName login;
		uint* password;
		enPairStatus status; // состо€ние €чейки	
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