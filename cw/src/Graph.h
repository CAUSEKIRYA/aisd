#pragma once
#include <string>

using namespace std;

class Vertex;

class Queue {
public:
	Queue() : vert(nullptr), next(nullptr) {};
	Vertex* vert;
	string way;
	Queue* next;
};

class Edge {
public:
	Edge(char c) : name(c), visited(false), flow(0), vert(nullptr), next(nullptr) {};

	char name;
	int flow;
	bool visited;

	Vertex* vert;
	Edge* next;
};

class Vertex {
public:
	Vertex(char c) : name(c), visited(false), next(nullptr), edgies(nullptr) {};

	char name;
	bool visited;

	Edge* edgies;
	Vertex* next;
};

class Graph {
public:
	Graph() : queue(nullptr), head(nullptr) {};

	Vertex* add_vertex(char c);
	Edge* add_edge(char a, char b, int flow);

	Vertex* get_vertex(char c);
	Edge* get_edge(char a, char b);

	string find_path();

	Vertex* head;
private:
	void push_queue(Vertex* vert, string way);
	Queue* pop();

	Queue* queue;
};
