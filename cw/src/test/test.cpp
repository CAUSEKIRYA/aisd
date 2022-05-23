#include "pch.h"
#include "EdmonsKarp.h"

TEST(EdmonsKarp, read_file) {
	EdmonsKarp test;
	test.read_file("input.txt");

	Vertex* it_v = test.network.head;
	
	char a[] = { 'S', 'O', 'P', 'Q', 'R', 'T' };

	int pos_a = 0;


	while (it_v)
	{
		ASSERT_EQ(it_v->name, a[pos_a]);
		it_v = it_v->next;
		pos_a++;
	}
}

TEST(EdmonsKarp, max_flow) {
	EdmonsKarp test;
	test.read_file("input.txt");

	ASSERT_EQ(test.max_flow(), 5);
}

TEST(Graph, add_vertex) {
	Graph test;

	test.add_vertex('a');
	test.add_vertex('b');
	test.add_vertex('c');
	test.add_vertex('d');

	Vertex* it_v = test.head;

	ASSERT_EQ(it_v->name, 'a');

	it_v = it_v->next;

	ASSERT_EQ(it_v->name, 'b');

	it_v = it_v->next;

	ASSERT_EQ(it_v->name, 'c');

	it_v = it_v->next;

	ASSERT_EQ(it_v->name, 'd');
}

TEST(Graph, add_edge) {
	Graph test;

	test.add_edge('a', 'b', 0);
	test.add_edge('a', 'c', 0);
	test.add_edge('b', 'c', 0);

	Vertex* it_v = test.head;

	ASSERT_EQ(test.head->edgies->name, 'b');
	ASSERT_EQ(test.head->edgies->next->name, 'c');
	ASSERT_EQ(test.head->next->edgies->name, 'c');
}

TEST(Graph, get_vertex) {
	Graph test;

	test.add_vertex('a');
	test.add_vertex('b');
	test.add_vertex('c');
	test.add_vertex('d');

	ASSERT_EQ(test.get_vertex('a')->name, 'a');

	ASSERT_EQ(test.get_vertex('b')->name, 'b');

	ASSERT_EQ(test.get_vertex('c')->name, 'c');

	ASSERT_EQ(test.get_vertex('d')->name, 'd');
}

TEST(Graph, get_edge) {
	Graph test;

	test.add_edge('a', 'b', 0);
	test.add_edge('a', 'c', 0);
	test.add_edge('b', 'c', 0);

	Vertex* it_v = test.head;

	ASSERT_EQ(test.get_edge('a', 'b')->name, 'b');
	ASSERT_EQ(test.get_edge('a', 'c')->name, 'c');
	ASSERT_EQ(test.get_edge('b', 'c')->name, 'c');
}

TEST(Graph, find_path) {
	Graph test;

	test.add_edge('S', 'O', 1);
	test.add_edge('S', 'P', 1);
	test.add_edge('O', 'Q', 1);
	test.add_edge('O', 'P', 1);
	test.add_edge('P', 'R', 1);
	test.add_edge('Q', 'R', 1);
	test.add_edge('Q', 'T', 1);
	test.add_edge('R', 'T', 1);

	ASSERT_STREQ(test.find_path().c_str(), "SOQT");

}