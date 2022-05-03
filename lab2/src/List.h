#pragma once
#include <string>

using namespace std;

class Node {
public:
	int freq;
	char symb;
	string code;

	Node* next;
	Node* prev;

	Node(char c) : freq(1), code(""), symb(c), next(nullptr), prev(nullptr) {};
};

class List{
public:
	List() : size(0), head(nullptr), tail(nullptr) {};

	void push(char c);
	void sort();
	Node* take_head() { return this->head; };
	Node* take_tail() { return this->tail; };
	int take_size() { return this->size; };
	string search(char c);

private:
	void swap(Node* l, Node* r);
	int size;
	Node* head;
	Node* tail;
};
