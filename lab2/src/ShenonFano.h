#pragma once
#include "List.h"
#include <iostream>

using namespace std;

class NodeTree {
public:
	string symb;
	string code;
	int freq;

	NodeTree* left;
	NodeTree* right;

	NodeTree() : symb(""), code(""), freq(0), left(nullptr), right(nullptr) {};
};

class ShenonFano {
public:
	ShenonFano(string s) : str(s), decode_str(""), root(nullptr), code_str(""), table(nullptr) {};
	void create_table();

	void print_table();

	string code();
	string decode();

	string take_decode() { return decode_str; };
	string take_code() { return code_str; };
	List* take_table() { return table; };

private:
	void create_code(string code, NodeTree* node, int start, int end);
	string str;
	string decode_str;
	string code_str;
	List* table;
	NodeTree* root;
};
