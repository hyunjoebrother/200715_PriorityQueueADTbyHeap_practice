#include "ListPriorityQueue.h"

#include <iostream>
using namespace std;
#include <list>

//Array나 LinkedList 구현 함수


//메인 함수

//생성자

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
void ListPriorityQueue<E, C>::insert(const E& e) //원소 삽입
{
	typename std::list<E>::iterator p;
	p = L.begin();
	while (p != L.end() && !isLess(e, *p)) //더 큰 원소 검색
		++p;
	L.insert(p, e); //p 앞에 e 삽입
}

template <typename E, typename C>
const E& ListPriorityQueue<E, C>::min() const //최소 원소
{
	return L.front(); //최소 원소가 맨 앞에 있다
}

template <typename E, typename C>
void ListPriorityQueue<E, C>::removeMin() //최소 원소 삭제
{
	L.pop_front();
}