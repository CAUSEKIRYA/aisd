#include "List.h"

void List::push(char c)
{
	if (this->head == nullptr) {
		this->head = new Node(c);
		this->tail = this->head;
		this->size++;
		return;
	}

	Node* buff = this->head;
	while (buff)
	{
		if (buff->symb == c) {
			buff->freq++;
			return;
		}
		buff = buff->next;
	}

	buff = this->tail;
	Node* add = new Node(c);
	add->prev = buff;
	buff->next = add;
	this->tail = add;
	this->size++;
}

void List::sort()
{
	for (int i = 0; i < this->size; i++) {
		Node* left = this->head;
		Node* right = this->head->next;
		for (int j = 0; j < this->size - 1; j++) {
			if (left->freq < right->freq) {
				swap(left, right);
				left = right->next;
				right = left->next;
				continue;
			}
			left = left->next;
			right = right->next;
		}
	}
}

void List::swap(Node* l, Node* r)
{
	Node* buff = r->next;
	r->next = l;
	l->next = buff;

	buff = l->prev;
	l->prev = r;
	r->prev = buff;

	if (r->prev)
		r->prev->next = r;
	else
		this->head = r;

	if (l->next)
		l->next->prev = l;
	else
		this->tail = l;
}

string List::search(char c)
{
	Node* buff = this->head;
	while (buff)
	{
		if (buff->symb == c) {
			return buff->code;
		}
		buff = buff->next;
	}
	return "_";
}