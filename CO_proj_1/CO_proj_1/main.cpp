#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include "Registers.h"
#include "Hex_Bin.h"


using namespace std;

int main()
{
	ifstream in;
	in.open("test_case1.obj");
	string hex;
	getline(in, hex,'\n');
	Hex_Bin a;
	string bin = a.bin(hex);
	std::string fina = a.split(bin);
	cout << hex << endl;
	cout << fina << endl;
	cout << bin << endl;
	cout << "Hello World" << endl;
	
	return 0;

}