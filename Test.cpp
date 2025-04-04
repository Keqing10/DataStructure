#include "Test.h"

#include <cstdio>
#include <iostream>

#include "list.hpp"
#include "queue.hpp"
#include "sort.h"
#include "stack.hpp"
#include "string.hpp"
#include "tree.hpp"
#include "utils.h"
#include "vector.hpp"

void ms::Test::run()
{
	//test_vector();
	//test_list();
	//test_stack();
	//test_queue();
	//test_string();
	//test_tree();
	//test_sort();
}

void ms::Test::test_vector()
{
	TestPrint("���캯��");
	ms::vector<int> v0;
	std::cout << "v0: size = " << v0.size() << ", maxSize = " << v0.maxSize() << std::endl;
	ms::vector<int> v1(10, 2);
	ms::vector<int> v2(v1);
	std::cout << "v2: size = " << v2.size() << ", maxSize = " << v2.maxSize() << std::endl;
	for (int i = 0; i < 10; ++i) {
		std::cout << "v2[" << i << "] = " << v2[i] << std::endl;
	}
	ms::vector<stu> v3(5, stu(0, true, "test"));
	std::cout << "v3:\n";
	for (int i = 0; i < 5; ++i) {
		std::cout << "v3[" << i << "] : ";
		v3[i].print();
	}

	TestPrint("assign()");
	v2.assign(100, 3);
	std::cout << "v2: size = " << v2.size() << ", maxSize = " << v2.maxSize() << std::endl;
	for (int i = 0; i < 100; ++i) {
		if (v2[i] != 3) std::cout << "There is an elem != 3 after assign()!\n";
	}

	TestPrint("operator=");
	ms::vector<stu> v4 = v3;
	std::cout << "v4:\n";
	for (int i = 0; i < 5; ++i) {
		std::cout << "v4[" << i << "] : ";
		v4[i].print();
	}

	TestPrint("push_back(), pop_back(), insert(), erase()");
	v4.clear();
	v4.push_back(stu(1, true, "alpha"));
	v4.push_back(stu(3, false, "gamma"));
	v4.insert(1, stu(2, true, "beta"));
	v4.push_back(stu(4, false, "delta"));
	printf("size:%d\n", v4.size());
	v4.insert(3, stu());
	v4.erase(3);
	std::cout << "v4:\n";
	for (int i = 0; i < v4.size(); ++i) {
		std::cout << "v4[" << i << "] : ";
		v4[i].print();
	}

	TestPrint("get_ptr()");
	stu* p = v4.get_ptr();
	p->print();
}

void ms::Test::test_list()
{
	TestPrint("LNode ~ reverse()");
	ms::LNode<int> a(1), * p = &a;
	for (int i = 2; i < 11; ++i) {
		p->next = new LNode<int>(i);
		p = p->next;
	}
	ms::LNode<int>* h = ms::reverse(&a);
	while (h) {
		std::cout << "=>" << h->val;
		h = h->next;
	}

	TestPrint("DLNode ~ reverse()");
	ms::DLNode<int> b(1), * q = &b;
	for (int i = 2; i < 11; ++i) {
		q->next = new DLNode<int>(i);
		q->next->prev = q;
		q = q->next;
	}
	ms::DLNode<int>* head = ms::reverse(&b), * tail = nullptr;
	while (head) {
		std::cout << " => " << head->val;
		tail = head;
		head = head->next;
	}
	std::cout << std::endl;
	while (tail) {
		std::cout << " => " << tail->val;
		tail = tail->prev;
	}
}

void ms::Test::test_stack()
{
}

void ms::Test::test_queue()
{
}

void ms::Test::test_string()
{
}

void ms::Test::test_tree()
{
}

void ms::Test::test_sort()
{
}
