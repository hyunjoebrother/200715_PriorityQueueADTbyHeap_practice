#include "HeapPriorityQueue.h"

#include <iostream>
using namespace std;
#include <list>

//Array나 LinkedList 구현 함수


//메인 함수

//생성자

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
void HeapPriorityQueue<E, C>::insert(const E& e) //원소 삽입
{
	T.addLast(e); //e를 Heap에 추가
	Position v = T.last(); //e의 위피
	while (!T.isRoot(v)) //Up-Heap Bubbling
	{
		Position u = T.parent(v);
		if (!isLess(*v, *u)) //v의 순서가 맞으면 loop 탈출
			break;
		T.swap(v, u); //순서 틀리면 부모와 원소 swap
		v = u;
	}
}

template <typename E, typename C>
const E& HeapPriorityQueue<E, C>::min() const //최소 원소
{
	return *(T.root()); //root 원소에 대해 ref 반환
}

template <typename E, typename C>
void HeapPriorityQueue<E, C>::removeMin() //최소 원소 삭제
{
	if (size() == 1) //단 하나의 node?
		T.removeLast(); //그 node는 삭제한다
	else
	{
		Position u = T.root(); //root 위치
		T.swap(u, T.last()); //마지막 node와 root를 swap
		T.removeLast(); //마지막 node 삭제

		while (T.hasLeft(u)) //Down-Heap Bubbling
		{
			Position v = T.left(u);
			if (T.hasRight(u) && isLess(*(T.right(u)), *v))
				v = T.right(u); //v는 u의 더 작은 자식
			if (isLess(*v, *u)) //u의 key가 v보다 큰가?
			{
				T.swap(u, v); //swap
				u = v;
			}
			else
				break;
		}
	}
}