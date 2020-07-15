#include "HeapPriorityQueue.h"

#include <iostream>
using namespace std;
#include <list>

//Array�� LinkedList ���� �Լ�


//���� �Լ�

//������

template <typename E, typename C>
int HeapPriorityQueue<E, C>::size() const
{
	return T.size();
}

template <typename E, typename C>
bool HeapPriorityQueue<E, C>::empty() const
{
	return size() == 0;
}

template <typename E, typename C>
void HeapPriorityQueue<E, C>::insert(const E& e) //���� ����
{
	T.addLast(e); //e�� Heap�� �߰�
	Position v = T.last(); //e�� ����
	while (!T.isRoot(v)) //Up-Heap Bubbling
	{
		Position u = T.parent(v);
		if (!isLess(*v, *u)) //v�� ������ ������ loop Ż��
			break;
		T.swap(v, u); //���� Ʋ���� �θ�� ���� swap
		v = u;
	}
}

template <typename E, typename C>
const E& HeapPriorityQueue<E, C>::min() const //�ּ� ����
{
	return *(T.root()); //root ���ҿ� ���� ref ��ȯ
}

template <typename E, typename C>
void HeapPriorityQueue<E, C>::removeMin() //�ּ� ���� ����
{
	if (size() == 1) //�� �ϳ��� node?
		T.removeLast(); //�� node�� �����Ѵ�
	else
	{
		Position u = T.root(); //root ��ġ
		T.swap(u, T.last()); //������ node�� root�� swap
		T.removeLast(); //������ node ����

		while (T.hasLeft(u)) //Down-Heap Bubbling
		{
			Position v = T.left(u);
			if (T.hasRight(u) && isLess(*(T.right(u)), *v))
				v = T.right(u); //v�� u�� �� ���� �ڽ�
			if (isLess(*v, *u)) //u�� key�� v���� ū��?
			{
				T.swap(u, v); //swap
				u = v;
			}
			else
				break;
		}
	}
}