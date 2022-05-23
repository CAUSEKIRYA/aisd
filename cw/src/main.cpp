#include <iostream>
#include "EdmonsKarp.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	EdmonsKarp test;
	test.read_file("input.txt");

	cout << "Максимальный поток:" << test.max_flow() << endl;

	test.print_graphs();
}