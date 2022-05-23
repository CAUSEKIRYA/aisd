#include "EdmonsKarp.h"

void EdmonsKarp::read_file(string path)
{
	ifstream file(path);
	if (!file.is_open())
	{
		cout << "ERORR: FILE" << endl;
		return;
	}

	string str;

	char a, b;
	int flow;

	while (file >> a >> b >> flow)
	{
		network.add_edge(a, b, flow);
		residual_network.add_edge(a, b, flow);
	}

	file.close();
}

int EdmonsKarp::max_flow()
{
	string path;
	path = residual_network.find_path();

	while (!path.empty())
	{
		int min = residual_network.get_edge(path[0], path[1])->flow;
		for (int i = 0; i < path.size() - 1; i++) {
			int a = residual_network.get_edge(path[i], path[i + 1])->flow;
			if (a < min)
				min = a;
		}

		for (int u = 0, v = 1; u < path.size() - 1; u++, v++)
		{
			residual_network.get_edge(path[u], path[v])->flow -= min;
			if (residual_network.get_edge(path[v], path[u]))
				residual_network.get_edge(path[v], path[u])->flow += min;
			else
				residual_network.add_edge(path[v], path[u], min);
		}

		path = residual_network.find_path();
	}

	Edge* a = network.get_vertex('S')->edgies;

	int flow = 0;

	while (a)
	{
		flow += a->flow - residual_network.get_edge('S', a->name)->flow;
		a = a->next;
	}

	return flow;
}

void EdmonsKarp::print_graphs()
{
	cout << "Начальный граф:" << endl;

	Vertex* vert = network.head;

	while (vert)
	{
		Edge* edge = vert->edgies;
		while (edge)
		{
			cout << vert->name << " " << edge->name << " " << edge->flow << endl;
			edge = edge->next;
		}
		vert = vert->next;
	}

	cout << endl << "Модифицированный граф:" << endl;

	vert = network.head;

	while (vert)
	{
		Edge* edge = vert->edgies;
		while (edge)
		{
			cout << vert->name << " " << edge->name << " "
				<< edge->flow - residual_network.get_edge(vert->name, edge->name)->flow << endl;
			edge = edge->next;
		}
		vert = vert->next;
	}
}