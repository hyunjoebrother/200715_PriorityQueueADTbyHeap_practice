//Priority Queue 우선순위 큐
//구현 by List (linear)

//data (key, value) 값을 저장하기 위함.
//key가 우선순위를 결정

//PQ로 선택정렬 (selection-sort, unsorted sequence) & 삽입정렬 (insertion-sort, sorted sequence)


#include <iostream>
using namespace std;
#include <list>

//예외처리

//다른 함수

//메인
template <typename E, typename C>
class ListPriorityQueue
{
private:
	std::list<E> L; //PQ 내용 -> list STL 함수 사용 ㄱㄴ
	C isLess; //less-than 비교자

public:
	int size() const;
	bool empty() const;
	void insert(const E& e);
	const E& min() const;
	void removeMin();
};