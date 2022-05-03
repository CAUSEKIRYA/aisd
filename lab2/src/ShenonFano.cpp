#include "ShenonFano.h"

void ShenonFano::create_table()
{
	this->table = new List();
	for (int i = 0; i < str.size(); i++) {
		this->table->push(str[i]);
	}
	this->table->sort();
	this->root = new NodeTree();
	if (this->table->take_size() == 1) {
		this->root->left = new NodeTree();
		this->root->left->code = "0";
		this->root->left->symb = table->take_head()->symb;
		this->root->left->freq = table->take_head()->freq;
		table->take_head()->code = "0";
		return;
	}
	create_code("", this->root, 1, this->table->take_size());
}

void ShenonFano::create_code(string code, NodeTree* node, int start, int end)
{
	if (node == nullptr) {
		node = new NodeTree();
	}

	
	Node* buff = this->table->take_head();
	for (int i = 1; i < start; i++) {
		buff = buff->next;
	}

	if (start == end) {
		node->code = code;
		node->symb = buff->symb;
		node->freq = buff->freq;
		buff->code = code;
		return;
	}

	Node* cur = buff;
	string str = "";
	int ds = 0;

	for (int i = start; i < end; i++) {
		ds += buff->freq;
		str = str + buff->symb;
		buff = buff->next;
	}

	ds /= 2;

	int S = 0;
	int it = start;
	int m = start;
	buff = cur;
	while ((S + buff->freq < ds) && (it < end)) {
		S += buff->freq;
		
		it++; m = it;
		buff = buff->next;
	}

	node->symb = str;
	node->left = new NodeTree();
	node->right = new NodeTree();

	
	create_code(code + '0', node->left, start, m);
	create_code(code + '1', node->right, m+1 , end);
}

void ShenonFano::print_table()
{
	Node* buff = this->table->take_head();
	while (buff)
	{
		cout << buff->symb << " - " << buff->code
			<< " frequency = " << buff->freq << endl;
		buff = buff->next;
	}
}

string ShenonFano::code()
{
	this->code_str = "";
	for (int i = 0; i < this->str.size(); i++) {
		this->code_str = this->code_str + this->table->search(str[i]);
	}
	return this->code_str;
}

string ShenonFano::decode()
{
	this->decode_str = "";
	if (root == nullptr)
		return decode_str;
	NodeTree* buff = this->root;
	for (int i = 0; i < this->code_str.size(); i++) {
		if (this->code_str[i] == '0') {
			buff = buff->left;
		}
		else {
			buff = buff->right;
		}
		if ((buff->left == nullptr) && (buff->right == nullptr)) {
			this->decode_str = this->decode_str + buff->symb;
			buff = this->root;
		}
	}

	return decode_str;
}