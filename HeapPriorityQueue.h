//Priority Queue �켱���� ť
//���� by Heap (��������)

//Heap = Complete Binary Tree + Heap-Order (�� ���� ���� ���� key ��)


#include <iostream>
using namespace std;
#include <list>
#include <vector> //vector STL

//����ó��

//�ٸ� Ŭ����

//Complete Binary Tree ����
template <typename E>
class VectorCompleteTree
{
private:
	std::vector<E> V; //Tree ����

public:
	typedef typename std::vector<E>::iterator Position; //Tree ��ġ

protected:
	Position pos(int i) //�ε����� position���� ����
	{
		return V.begin() + i;
	}
	int idx(const Position& p) const //position�� �ε����� ����
	{
		return p - V.begin();
	}


	//������
	VectorCompleteTree()
		:V(1) { }

	int size() const //���� ����
	{
		return V.size() - 1;
	}

	Position left(const Position& p) //���� �ڽ��� ���϶�
	{
		return pos(2 * idx(p));
	}

	Position right(const Position& p)
	{
		return pos(2 * idx(p) + 1);
	}

	Position parent(const Position& p) //�θ� ���϶�
	{
		return pos(idx(p) / 2);
	}

	bool hasLeft(const Position& p) const //���� �ڽ��� �����°�?
	{
		return 2 * idx(p) <= size();
	}

	bool hasRight(const Position& p) const
	{
		return 2 * idx(p) + 1 <= size();
	}

	bool isRoot(const Position& p) const //�̰��� root�ΰ�?
	{
		return idx(p) == 1;
	}

	Position root() //root ��ġ�� ���϶�
	{
		return pos(1);
	}

	Position last() //������ node�� ���϶�
	{
		return pos(size());
	}

	void addLast(const E& e) //���ο� ������ node �߰�
	{
		V.push_back(e);
	}

	void removeLast() //������ node ����
	{
		V.pop_back();
	}

	void swap(const Position& p, const Position& q) //node ������ ���� ��ȯ
	{
		E e = *q;
		*q = *p;
		*p = e;
	}
};


//����
template <typename E, typename C>
class HeapPriorityQueue
{
private:
	VectorCompleteTree<E> T; //PQ ����
	C isLess; //less-than ����

	typedef typename VectorCompleteTree<E>::Position Position;

public:
	int size() const;
	bool empty() const;
	void insert(const E& e);
	const E& min() const;
	void removeMin();
};