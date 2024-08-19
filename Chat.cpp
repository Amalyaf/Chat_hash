#include "Chat.h"

int Chat::hash_func(LoginName log, int offset)
{
	// вычисляем индекс
	int sum = 0, i = 0;
	for (; i < strlen(log); i++) {
		sum += log[i];
	}
	// квадратичные пробы
	return (sum % mem_size + offset * offset) % mem_size;
}

void Chat::resize()
{
	Pair* save_array = array; // запоминаем старый массив
	int old_size = mem_size;

	mem_size *= 2; // увеличиваем размер в два раза  
	count = 0; // обнуляем количество элементов
	array = new Pair[mem_size]; // выделяем новую память

	for (int i = 0; i < old_size; i++)
	{// перебираем все старые цепочки
		Pair current = save_array[i];
		if (current.status == enPairStatus::engaged)
		{// пересчитываем хеши и добавляем в новый массив
			
		}
	}
	// чистим за собой
	delete[]save_array;
}


Chat::Chat()
{
	count = 0;
	mem_size = 10;
	array = new Pair[mem_size];
}

Chat::~Chat()
{
	delete[]array;
}

void Chat::reg(char _login[NAMELOGIN], char _pass[])
{
	int index = -1, i = 0;
	for (; i < mem_size; i++)
	{
		index = hash_func(_login,i);
		if (array[index].status != enPairStatus::engaged)
		{
			break;
		}
	}
	if (i >= mem_size)
		return;
	array[index] = Pair(_login, sha1(_pass, PASSWORDLENGTH));
	count++;
}

bool Chat::login(char _login[NAMELOGIN], char _pass[])
{
	int i = 0;
	for (; i < mem_size; i++)
	{
		if (strcmp(_login, array[i].login) == 0 && array[i].status==enPairStatus::engaged)
			break;
	}
	if (i == mem_size)
	{
		return false;
	}
	uint* digest = sha1(_pass, PASSWORDLENGTH);
	bool cmpHashes = !memcmp(array[i].password,	digest,	SHA1HASHLENGTHBYTES);
	delete[] digest;
	return cmpHashes;
}

void Chat::print()
{
	for (int i = 0; i < mem_size; i++)
	{
		if (array[i].status == enPairStatus::engaged)
			std::cout << array[i].login << ": " << array[i].password << std::endl;
	}
	std::cout << std::endl << std::endl;
}

int Chat::find(LoginName log)
{
	for (int i = 0; i < mem_size; i++)
	{
		int index = hash_func(log, i);
		if (strcmp(array[index].login, log) == 0 && array[index].status==enPairStatus::engaged)
		{
			//std::cout << array[index].login << ": " << array[index].password << std::endl;
			return 0;
		}
	}
	std::cout << "Not found" << std::endl;
	return -1;
}

void Chat::del(LoginName log)
{
	for (int i = 0; i < mem_size; i++)
	{
		int index = hash_func(log, i);
		if (find(array[index].login) == -1) //если элемента нет, выходим
			return;
		if (strcmp(array[index].login, log) == 0 && array[index].status == enPairStatus::engaged) //если есть и статус - занято, то меняем статус на удалено
		{
			array[index].status = enPairStatus::deleted;
			count--;
			return;
		}
	}
}
