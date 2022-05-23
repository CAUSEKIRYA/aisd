#include "Graph.h"

Vertex* Graph::add_vertex(char c)
{
	Vertex* buff = get_vertex(c);
	if (buff)
		return buff;

	if (head == nullptr)
	{
		head = new Vertex(c);
		return head;
	}

	Vertex* iter = head;
	while (iter->next)
	{
		iter = iter->next;
	}
	iter->next = new Vertex(c);
	return iter->next;
}

Vertex* Graph::get_vertex(char c)
{
	Vertex* buff = head;
	while (buff)
	{
		if (buff->name == c)
			return buff;
		buff = buff->next;
	}
	return nullptr;
}

Edge* Graph::get_edge(char a, char b)
{
	Edge* buff = get_vertex(a)->edgies;
	while (buff)
	{
		if (buff->name == b)
			return buff;
		buff = buff->next;
	}
	return nullptr;
}

Edge* Graph::add_edge(char a, char b, int flow)
{
	Vertex* vert_a = add_vertex(a);
	Vertex* vert_b = add_vertex(b);

	if (vert_a->edgies == nullptr)
	{
		vert_a->edgies = new Edge(b);
		vert_a->edgies->vert = vert_b;
		vert_a->edgies->flow = flow;
		return vert_a->edgies;
	}

	Edge* iter = vert_a->edgies;

	while (iter->next)
	{
		iter = iter->next;
	}
	iter->next = new Edge(b);
	iter->next->flow = flow;
	iter->next->vert = vert_b;
	return iter->next;
}

string Graph::find_path()
{
	Vertex* node = head;
	while (node)
	{
		node->visited = false;
		Edge* edge = node->edgies;
		while (edge)
		{
			edge->visited = false;
			edge = edge->next;
		}
		node = node->next;
	}

	delete queue;
	queue = nullptr;

	push_queue(get_vertex('S'), "S");

	Queue* curent = pop();
	curent->vert->visited = true;
	while (curent) {
		if (curent->vert->name == 'T')
			break;
		Edge* edge = curent->vert->edgies;
		while (edge)
		{
			edge->visited = true;
			if ((edge->vert->visited == false) && (edge->flow > 0)) {
				push_queue(edge->vert, curent->way + edge->name);
				edge->vert->visited == true;
			}
			edge = edge->next;
		}

		curent = pop();
	}
	if (curent)
		return curent->way;
	return "";
}

void Graph::push_queue(Vertex* vert, string way)
{
	if (queue == nullptr) {
		queue = new Queue();
		queue->vert = vert;
		queue->way = way;
		return;
	}

	Queue* iter = queue;
	while (iter->next)
	{
		iter = iter->next;
	}

	iter->next = new Queue();
	iter->next->vert = vert;
	iter->next->way = way;
}

Queue* Graph::pop()
{
	if (queue == nullptr)
		return nullptr;
	Queue* buff = queue;

	if (queue->next)
		queue = queue->next;
	else
		queue = nullptr;

	return buff;
}