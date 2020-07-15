#include "ListPriorityQueue.h"

#include <iostream>
using namespace std;
#include <list>

//Array�� LinkedList ���� �Լ�


//���� �Լ�

//������

template <typename E,typename C>
int ListPriorityQueue<E,C>::size() const
{
	return L.size();
}

template <typename E,typename C>
bool ListPriorityQueue<E, C>::empty() const
{
	return L.empty();
}

template <typename E,typename C>
void ListPriorityQueue<E, C>::insert(const E& e) //���� ����
{
	typename std::list<E>::iterator p;
	p = L.begin();
	while (p != L.end() && !isLess(e, *p)) //�� ū ���� �˻�
		++p;
	L.insert(p, e); //p �տ� e ����
}

template <typename E, typename C>
const E& ListPriorityQueue<E, C>::min() const //�ּ� ����
{
	return L.front(); //�ּ� ���Ұ� �� �տ� �ִ�
}

template <typename E, typename C>
void ListPriorityQueue<E, C>::removeMin() //�ּ� ���� ����
{
	L.pop_front();
}