#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
	cout << "Created objects: " << MyString::GetCreatedObjects() << endl;

	MyString str1;
	cout << "Str 1 (str1.Print()): ";
	str1.Print();

	MyString str2(12);
	cout << "Str 2 with length " << str2.GetLength() << endl;
	cout << "Created objects: " << MyString::GetCreatedObjects() << endl;

	MyString str3("Hello world!");
	cout << "Str 3: " << str3 << endl;

	MyString str4(str3);
	cout << "Str 4 (copy str3): " << str4 << endl;

	MyString str5(move(str4));
	cout << "Str 5 (move str4): " << str5 << endl;
	cout << "Length of Str 4 after move: " << str4.GetLength() << endl;
	cout << "Created objects: " << MyString::GetCreatedObjects() << endl;

	MyString str6("Nice day!");
	cout << "Str 6: " << str6 << endl;
	str5.MyStrcpy(str6);
	cout << "Str 5 after Mystrcpy(str6): " << str5 << endl;

	MyString str7("Good night!");
	cout << "Str 7: " << str7 << endl;
	
	cout << "MyStrStr: " << endl;
	cout << "Find night: " << str7.MyStrStr("night") << endl;
	cout << "Find nice: " << str7.MyStrStr("nice") << endl;

	cout << "MyChr:" << endl;
	cout << "Index of 'i': " << str7.MyChr('i') << endl;
	cout << "Index of 'a': " << str7.MyChr('a') << endl;

	cout << "MyStrLen: " << endl;
	cout << "Length of Str 7: " << str7.GetLength() << endl;

	MyString str8(" Bye!");
	cout << "Str 8: " << str8 << endl;
	str7.MyStrCat(str8);
	cout << "Str 7 after MyStrCat(str8): " << str7 << endl;

	MyString str9("Hello");
	cout << "Str 9: " << str9 << endl;
	str9.MyDelChr('l');
	cout << "Str 9 after MyDelChr('l'): " << str9 << endl;

	MyString strc1("Phone");
	MyString strc2("Laptop");
	MyString strc3("Phone");
	cout << "MyStrCmp - Phone and Laptop: " << strc1.MyStrCmp(strc2) << endl;
	cout << "MyStrCmp - Laptop and Phone: " << strc2.MyStrCmp(strc1) << endl;
	cout << "MyStrCmp - Phone and Phone: " << strc1.MyStrCmp(strc3) << endl;
	cout << endl;

	MyString ostr("World!");
	cout << "ostr: " << ostr << endl;
	cout << "ostr[2]: " << ostr[2] << endl;
	cout << "Input ostr(): ";
	ostr();
	cout << "New str: " << ostr << endl;

	MyString pstr1("Apple");
	cout << "pstr1: " << pstr1 << endl;
	cout << "pstr1 + '?': ";
	MyString pstr2 = pstr1 + '?';
	cout << pstr2 << endl;

	cout << "'a' + pstr1: ";
	MyString pstr3 = 'a' + pstr1;
	cout << pstr3 << endl;

	MyString pstr4("Key");
	cout << "pstr4: " << pstr4 << endl;
	cout << "pstr4 + 10: " << pstr4 + 10 << endl;
	cout << "3 + pstr4: " << 3 + pstr4 << endl;

	cout << "++pstr4: " << ++pstr4 << endl;
	cout << "pstr4++: " << pstr4++ << " after pstr4++: " << pstr4 << endl;

	MyString estr1("First");
	cout << "estr1: " << estr1 << endl;
	MyString estr2 = estr1;
	cout << "estr2 = estr1 (copy): " << estr2 << endl;
	MyString estr3 = move(estr1);
	cout << "estr3 = estr1 (move): " << estr2 << endl;
	cout << "Length of estr1 after move: " << estr1.GetLength() << endl;

	MyString ustr;
	cout << "cin >> ustr: ";
	cin >> ustr;
	cout << "cout << ustr: " << ustr << endl;
}