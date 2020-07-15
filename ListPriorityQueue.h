//Priority Queue �켱���� ť
//���� by List (linear)

//data (key, value) ���� �����ϱ� ����.
//key�� �켱������ ����

//PQ�� �������� (selection-sort, unsorted sequence) & �������� (insertion-sort, sorted sequence)


#include <iostream>
using namespace std;
#include <list>

//����ó��

//�ٸ� �Լ�

//����
template <typename E, typename C>
class ListPriorityQueue
{
private:
	std::list<E> L; //PQ ���� -> list STL �Լ� ��� ����
	C isLess; //less-than ����

public:
	int size() const;
	bool empty() const;
	void insert(const E& e);
	const E& min() const;
	void removeMin();
};