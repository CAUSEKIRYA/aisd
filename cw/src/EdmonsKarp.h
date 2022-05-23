#pragma once
#include <fstream>
#include <iostream>
#include "Graph.h"

using namespace std;

class EdmonsKarp
{
public:
	void read_file(string path);
	int max_flow();

	Graph network;
	Graph residual_network;

	void print_graphs();
};
