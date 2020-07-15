//Priority Queue 우선순위 큐
//구현 by Heap (계층구조)

//Heap = Complete Binary Tree + Heap-Order (맨 위가 가장 작은 key 값)


#include <iostream>
using namespace std;
#include <list>
#include <vector> //vector STL

//예외처리

//다른 클래스

//Complete Binary Tree 구현
template <typename E>
class VectorCompleteTree
{
private:
	std::vector<E> V; //Tree 내용

public:
	typedef typename std::vector<E>::iterator Position; //Tree 위치

protected:
	Position pos(int i) //인덱스를 position으로 매핑
	{
		return V.begin() + i;
	}
	int idx(const Position& p) const //position을 인덱스로 매핑
	{
		return p - V.begin();
	}


	//생성자
	VectorCompleteTree()
		:V(1) { }

	int size() const //원소 개수
	{
		return V.size() - 1;
	}

	Position left(const Position& p) //왼쪽 자식을 구하라
	{
		return pos(2 * idx(p));
	}

	Position right(const Position& p)
	{
		return pos(2 * idx(p) + 1);
	}

	Position parent(const Position& p) //부모를 구하라
	{
		return pos(idx(p) / 2);
	}

	bool hasLeft(const Position& p) const //왼쪽 자식을 가졌는가?
	{
		return 2 * idx(p) <= size();
	}

	bool hasRight(const Position& p) const
	{
		return 2 * idx(p) + 1 <= size();
	}

	bool isRoot(const Position& p) const //이것이 root인가?
	{
		return idx(p) == 1;
	}

	Position root() //root 위치를 구하라
	{
		return pos(1);
	}

	Position last() //마지막 node를 구하라
	{
		return pos(size());
	}

	void addLast(const E& e) //새로운 마지막 node 추가
	{
		V.push_back(e);
	}

	void removeLast() //마지막 node 삭제
	{
		V.pop_back();
	}

	void swap(const Position& p, const Position& q) //node 내용을 서로 교환
	{
		E e = *q;
		*q = *p;
		*p = e;
	}
};


//메인
template <typename E, typename C>
class HeapPriorityQueue
{
private:
	VectorCompleteTree<E> T; //PQ 내용
	C isLess; //less-than 비교자

	typedef typename VectorCompleteTree<E>::Position Position;

public:
	int size() const;
	bool empty() const;
	void insert(const E& e);
	const E& min() const;
	void removeMin();
};