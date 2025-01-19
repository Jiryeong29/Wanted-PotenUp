#pragma once
#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

#include "Node.h"

// 노드를 사용해 자료를 저장하는 링크드 리스트
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void AddToHead(int data);

	void Insert(int data);;

	void Delete(int data);

	void Print();
	
	__forceinline int Count() const; // 언리얼은 __forceinline을 좀 더 많이 씀



private:
	Node* head = nullptr;
	int count = 0;
};