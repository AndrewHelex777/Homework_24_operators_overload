#pragma once
#include <iostream>
using namespace std;

class MyString
{
	char* str;
	int length;
	static int createdObjects;
public:
	MyString();
	MyString(const int size);
	MyString(const char* s);
	MyString(const MyString& obj);
	MyString(MyString&& obj);
	~MyString();

	const char* GetStr() const;
	int GetLength() const;
	static int GetCreatedObjects();
	
	void Input();
	void Print();

	void MyStrcpy(MyString& obj);
	bool MyStrStr(const char* str);
	int MyChr(char c);
	int MyStrLen();
	void MyStrCat(MyString& b);
	void MyDelChr(char c);
	int MyStrCmp(MyString& b);

	char& operator[](const int index);
	void operator()();
	MyString operator+(char c) const;
	MyString operator+(int count) const;
	MyString& operator++();
	MyString operator++(int);
	MyString& operator=(const MyString& obj);
	MyString& operator=(MyString&& obj);
};

MyString operator+(char c, const MyString& obj);
MyString operator+(int count, const MyString& obj);

ostream& operator<<(ostream& os, const MyString& obj);
istream& operator>>(istream& is, MyString& obj);