#include "pch.h"
#include "ListAdjacency.h"

TEST(ListAdjacency, input) {
	ListAdjacency test;

	test.input("input.txt");

	List* iter = test.all_elements;
	
	ASSERT_STREQ(iter->node->name.c_str(), "�����-���������");

	iter = iter->next;

	ASSERT_STREQ(iter->node->name.c_str(), "������");

	iter = iter->next;

	ASSERT_STREQ(iter->node->name.c_str(), "���������");

	iter = iter->next;

	ASSERT_STREQ(iter->node->name.c_str(), "�����������");
}

TEST(ListAdjacency, Dijkstra) {
	ListAdjacency test;

	test.input("input.txt");

	ASSERT_STREQ(test.Dijkstra("������", "���������").c_str(), "������ �����-��������� ���������");
	ASSERT_STREQ(test.Dijkstra("������", "�����-���������").c_str(), "������ �����-���������");
	ASSERT_STREQ(test.Dijkstra("������", "�����������").c_str(), "������ �����-��������� �����������");
}
