#include "pch.h"
#include "ShenonFano.h"
#include <iostream>
#include <windows.h>

void PrintTabs(HANDLE hStdOut) {
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "[          ] ";
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_BLUE
		| FOREGROUND_RED | FOREGROUND_INTENSITY);
}

void TreeOut(ShenonFano test, HANDLE hStdOut) {
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "[    String] ";
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_BLUE
		| FOREGROUND_RED | FOREGROUND_INTENSITY);

	cout << test.take_decode() << endl;

	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "[      Code] ";
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_BLUE
		| FOREGROUND_RED | FOREGROUND_INTENSITY);

	cout << test.take_code() << endl;
}

void ListOut(List test, HANDLE hStdOut) {
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "[    Symbols] ";
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_BLUE
		| FOREGROUND_RED | FOREGROUND_INTENSITY);

	Node* buff = test.take_head();
	while (buff)
	{
		cout << buff->symb << " ";
		buff = buff->next;
	}
	cout << endl;

	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "[      Freq] ";
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_BLUE
		| FOREGROUND_RED | FOREGROUND_INTENSITY);

	buff = test.take_head();
	while (buff)
	{
		cout << buff->freq << " ";
		buff = buff->next;
	}
	cout << endl;
}


TEST(ShenonFanoTest, create_table) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_BLUE
		| FOREGROUND_RED | FOREGROUND_INTENSITY);

	ShenonFano test("asdfsagasdklasfasaasfdaafas");
	char symb[] = { 'a', 's', 'f', 'd', 'g', 'k', 'l' };
	string code[] = { "00", "01", "10", "110", "1110", "11110", "11111" };
	int freq[] = { 10,7,4,3,1,1,1 };
	test.create_table();
	test.code();
	test.decode();

	TreeOut(test, hStdOut);

	List* table = test.take_table();
	Node* buff = table->take_head();

	for (int i = 0; i < 7; i++) {
		ASSERT_EQ(buff->symb, symb[i]);
		ASSERT_EQ(buff->freq, freq[i]);
		ASSERT_STREQ(buff->code.c_str(), code[i].c_str());
		buff = buff->next;
	}

}


TEST(ShenonFanoTest, code) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_BLUE
		| FOREGROUND_RED | FOREGROUND_INTENSITY);

	ShenonFano test("asdfsagasdklasfasaasfdaafas");
	char str[] = "00011101001001110000111011110111110001100001000001101100000100001";
	test.create_table();
	test.code();
	test.decode();

	TreeOut(test, hStdOut);

	ASSERT_STREQ(test.take_code().c_str(), str);
}

TEST(ShenonFanoTest, decode) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_BLUE
		| FOREGROUND_RED | FOREGROUND_INTENSITY);

	ShenonFano test("asdfsagasdklasfasaasfdaafas");
	char str[] = "asdfsagasdklasfasaasfdaafas";
	test.create_table();
	test.code();
	test.decode();

	TreeOut(test, hStdOut);

	ASSERT_STREQ(test.take_decode().c_str(), str);
}

TEST(ListTest, push) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_BLUE
		| FOREGROUND_RED | FOREGROUND_INTENSITY);

	List test;
	string str = "1234444456";
	char arr[] = { '1','2','3','4','5','6' };
	int freq[] = { 1,1,1,5,1,1 };
	for (int i = 0; i < str.size(); i++) {
		test.push(str[i]);
	}

	ListOut(test, hStdOut);

	Node* buff = test.take_head();
	for (int i = 0; i < 6; i++) {
		ASSERT_EQ(buff->symb, arr[i]);
		ASSERT_EQ(buff->freq, freq[i]);
		buff = buff->next;
	}
}

TEST(ListTest, sort) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_BLUE
		| FOREGROUND_RED | FOREGROUND_INTENSITY);

	List test;
	string str = "1234444456";
	char arr[] = { '4','1','2','3','5','6' };
	int freq[] = { 5,1,1,1,1,1 };
	for (int i = 0; i < str.size(); i++) {
		test.push(str[i]);
	}

	test.sort();

	ListOut(test, hStdOut);



	Node* buff = test.take_head();
	for (int i = 0; i < 6; i++) {
		ASSERT_EQ(buff->symb, arr[i]);
		ASSERT_EQ(buff->freq, freq[i]);
		buff = buff->next;
	}
}

TEST(ListTest, search) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_BLUE
		| FOREGROUND_RED | FOREGROUND_INTENSITY);

	ShenonFano table("1234444456");
	table.create_table();
	List* test = table.take_table();
	string code[] = { "0","100","101","110","1110","1111" };

	ListOut(*test, hStdOut);

	Node* buff = test->take_head();
	for (int i = 0; i < 6; i++) {
		ASSERT_STREQ(buff->code.c_str(), code[i].c_str());
		buff = buff->next;
	}
}