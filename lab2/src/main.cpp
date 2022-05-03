#include <iostream>
#include "ShenonFano.h"

using namespace std;

int main() 
{
	string str = "";
	getline(cin, str);

	ShenonFano test(str);
	test.create_table();
	test.print_table();

	cout << "code - " << test.code() << endl;
	cout << "decode - " << test.decode() << endl;

	cout << "size code string = " << test.take_code().size() << endl;
	cout << "size string = " << test.take_decode().size() * 8 << endl;

	cout << "compression ratio = " << float(test.take_decode().size() * 8) / float(test.take_code().size()) << endl;
}