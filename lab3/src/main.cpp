#include <iostream>
#include "ListAdjacency.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	ListAdjacency test;

	test.input("input.txt");

	fstream file("input.txt");

	if (!file.is_open())
		return 0;

	string out;

	while (getline(file, out)) {
		cout << out << endl;
	}

	cout << endl;

	cout << test.Dijkstra("�����������", "�����-���������") << endl;
	cout << test.Dijkstra("�����������", "���������") << endl;
	cout << test.Dijkstra("�����������", "������") << endl;

	cout << endl;

	cout << test.Dijkstra("������", "�����-���������") << endl;
	cout << test.Dijkstra("������", "���������") << endl;
	cout << test.Dijkstra("������", "�����������") << endl;

	cout << endl;

	cout << test.Dijkstra("�����-���������", "������") << endl;
	cout << test.Dijkstra("�����-���������", "���������") << endl;
	cout << test.Dijkstra("�����-���������", "�����������") << endl;

	cout << endl;

	cout << test.Dijkstra("���������", "�����-���������") << endl;
	cout << test.Dijkstra("���������", "������") << endl;
	cout << test.Dijkstra("���������", "�����������") << endl;
	return 0;
}