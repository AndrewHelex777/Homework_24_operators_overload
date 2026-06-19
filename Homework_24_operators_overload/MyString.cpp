#include "MyString.h"

int MyString::createdObjects = 0;

MyString::MyString()
{
	length = 80;
	str = new char[length + 1];
	str[0] = '\0';
	createdObjects++;
}

MyString::MyString(const int size)
{
	length = size;
	str = new char[length + 1];
	str[0] = '\0';
	createdObjects++;
}

MyString::MyString(const char* s)
{
	length = strlen(s);
	str = new char[length + 1];
	strcpy_s(str, length + 1, s);
	createdObjects++;
}

MyString::MyString(const MyString& obj)
{
	length = obj.length;
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj.str);
	createdObjects++;
}

MyString::MyString(MyString&& obj)
{
	length = obj.length;
	obj.length = 0;
	str = obj.str;
	obj.str = nullptr;
	createdObjects++;
}

MyString::~MyString()
{
	delete[] str;
	createdObjects--;
}

const char* MyString::GetStr() const
{
	return str;
}

int MyString::GetLength() const
{
	return length;
}

int MyString::GetCreatedObjects()
{
	return createdObjects;
}

void MyString::Input()
{
	char buff[100];
	cin.getline(buff, 100);

	delete[] str;
	length = strlen(buff);
	str = new char[length + 1];
	strcpy_s(str, length + 1, buff);
}

void MyString::Print()
{
	cout << str << endl;
}

void MyString::MyStrcpy(MyString& obj)
{
	delete[] str;
	length = obj.length;
	str = new char[length + 1];
	for (int i = 0; i <= length; i++)
	{
		str[i] = obj.str[i];
	}
}

bool MyString::MyStrStr(const char* str)
{
	int i = 0;
	while (this->str[i] != '\0')
	{
		int j = 0;

		while (this->str[i + j] == str[j] && str[j] != '\0')
		{
			j++;
		}
		if (str[j] == '\0')
		{
			return true;
		}
		i++;
	}
	return false;
}

int MyString::MyChr(char c)
{
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c)
		{
			return i;
		}
	}
	return -1;
}

int MyString::MyStrLen()
{
	return length;
}

void MyString::MyStrCat(MyString& b)
{
	int newLength = length + b.length;
	char* newStr = new char[newLength + 1];

	strcpy_s(newStr, newLength + 1, str);
	strcat_s(newStr, newLength + 1, b.str);

	delete[] str;
	str = newStr;
	length = newLength;
}

void MyString::MyDelChr(char c)
{
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c)
		{
			count++;
		}
	}

	if (count != 0)
	{
		int newLength = length - count;
		char* newStr = new char[newLength + 1];
		int index = 0;

		for (int i = 0; i < length; i++)
		{
			if (str[i] != c)
			{
				newStr[index++] = str[i];
			}
		}
		newStr[newLength] = '\0';

		delete[] str;
		str = newStr;
		length = newLength;
	}
}

int MyString::MyStrCmp(MyString& b)
{
	int i = 0;

	while (str[i] != '\0' && b.str[i] != '\0')
	{
		if (str[i] > b.str[i])
		{
			return 1;
		}
		else if (str[i] < b.str[i])
		{
			return -1;
		}
		i++;
	}

	if (str[i] == '\0' && b.str[i] == '\0')
	{
		return 0;
	}
	else if (str[i] == '\0')
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

char& MyString::operator[](const int index)
{
	if (index >= 0 && index < length)
	{
		return str[index];
	}
	return str[0];
}

void MyString::operator() ()
{
	Input();
}

MyString MyString::operator+(char c) const
{	
	MyString temp(length + 1);
	strcpy_s(temp.str, temp.length + 1, str);
	temp.str[length] = c;
	temp.str[length + 1] = '\0';
	return temp;
}

MyString MyString::operator+(int count) const
{
	MyString temp(length + count);
	strcpy_s(temp.str, temp.length + 1, str);
	for (int i = 0; i < count; i++)
	{
		temp.str[length + i] = '*';
	}
	temp.str[length + count] = '\0';
	return temp;
}

MyString& MyString::operator++()
{
	int newLength = length + 1;
	char* newStr = new char[newLength + 1];
	newStr[0] = '*';
	strcpy_s(newStr + 1, newLength, str);
	
	delete[] str;
	str = newStr;
	length = newLength;
	return *this;
}

MyString MyString::operator++(int)
{
	MyString temp(*this);

	int newLength = length + 1;
	char* newStr = new char[newLength + 1];
	strcpy_s(newStr, newLength + 1, str);
	newStr[length] = '*';
	newStr[newLength] = '\0';

	delete[] str;
	str = newStr;
	length = newLength;

	return temp;
}

MyString& MyString::operator=(const MyString& obj)
{
	if (this == &obj)
	{
		return *this;
	}
	
	delete[] str;

	length = obj.length;
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj.str);

	return *this;
}

MyString& MyString::operator=(MyString&& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	delete[] str;

	length = obj.length;
	obj.length = 0;
	str = obj.str;
	obj.str = nullptr;

	return *this;
}

MyString operator+(char c, const MyString& obj)
{
	int newLength = obj.GetLength() + 1;
	char* buff = new char[newLength + 1];

	buff[0] = c;
	for (int i = 0; i < obj.GetLength(); i++)
	{
		buff[i + 1] = obj.GetStr()[i];
	}
	buff[newLength] = '\0';
	
	MyString temp(buff);
	delete[] buff;
	return temp;
}

MyString operator+(int count, const MyString& obj) // в задании написано в конец строки, но obj + 10 уже это делает, поэтому для 10 + obj логичнее добавлять в начало строки
{
	int newLength = obj.GetLength() + count;
	char* buff = new char[newLength + 1];

	for (int i = 0; i < count; i++)
	{
		buff[i] = '*';
	}

	for (int i = 0; i < obj.GetLength(); i++)
	{
		buff[count + i] = obj.GetStr()[i];
	}
	buff[newLength] = '\0';
	
	MyString temp(buff);
	delete[] buff;
	return temp;
}

ostream& operator<<(ostream& os, const MyString& obj)
{
	os << obj.GetStr();
	return os;
}

istream& operator>>(istream& is, MyString& obj)
{
	char buff[100];
	is.getline(buff, 100);
	MyString temp(buff);
	obj = temp;
	return is;
}
