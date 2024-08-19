#include "Chat.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	Chat chat;
	chat.reg((char*)"Olya", (char*)"Olya123");
	chat.reg((char*)"Masha", (char*)"Masha123");
	chat.reg((char*)"Vanya", (char*)"Vanya123");
	chat.find((char*)"Masha");
	chat.print();
	if (chat.login((char*)"Vanya", (char*)"Vanya123"))
	{
		cout << "Login completed" << endl;
	}
	else
	{
		cout << "Login failed" << endl;
	}
	cout << endl;
	chat.del((char*)"Vanya");
	chat.print();
	if (chat.login((char*)"Vanya", (char*)"Vanya123"))
	{
		cout << "Login completed" << endl;
	}
	else
	{
		cout << "Login failed" << endl;
	}
	cout << endl;
}