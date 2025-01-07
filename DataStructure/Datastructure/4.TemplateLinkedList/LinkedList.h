
#include "Node.h"

// 노드를 사용해 자료를 저장하는 링크드 리스트
template<typename T>
class LinkedList
{
public:
	LinkedList();

	~LinkedList()
	{
		// 조금 어렵..습.
		if (head != nullptr)
		{
			Node<T>* current = head;
			Node<T>* deleteNode = nullptr;
			while (current != nullptr)
			{
				deleteNode = current;
				current = current->next;

				delete deleteNode;
			}
		}
	}

	void AddToFirst(const T& data)
	{
		// 새 노드 생성
		Node<T>* newNode = new Node<T>(data);

		// Case 1: 현재 헤드가 없는 경우
		if (head == nullptr)
		{
			// 헤드 노드를 newNode로 설정
			head = newNode;
		}
		// Case 2: 헤드가 있는 경우
		else
		{
			// 새 노드의 다음 노드를 기존의 헤드 노드로 설정
			newNode->next = head;

			// 헤드 노드를 새 노드로 교체
			head = newNode;
		}

		// 저장된 노드 수 증가 처리
		++count;
	}


	void Insert(const T& data)
	{

		// 새 노드 생성.
		Node<T>* newNode = new Node<T>(data);

		// 삽입할 위치 찾기.
		if (head == nullptr)
		{
			head = newNode;
		}
		else
		{
			Node<T>* current = head;
			Node<T>* trail = nullptr;
			// 위치 검색
			while (current != nullptr)
			{
				if (current->data >= data)
				{
					break;
				}
				trail = current;
				current = current->next;
			}
			// 검색된 노드가 헤드일 경우
			if (current == head)
			{
				newNode->next = head;
				head = newNode;
			}
			// 검색된 노드가 중간일 경우
			else
			{
				newNode->next = current;
				trail->next = newNode;
			}

		}

		// 요소 수 증가 처리
		++count;
	}

	void Delete(const T& data)
	{
		// 조금 어렵..습.
		// 삭제할 노드 찾기.
		if (head == nullptr)
		{
			std::cout << "리스트가 비어있어 삭제가 불가능 합니다.\n";
			return;
		}

		// 검색 진행.
		Node<T>* current = head;
		Node<T>* trail = nullptr;

		while (current != nullptr)
		{
			// 값 비교
			if (current->data == data)
			{
				break;
			}

			// 노드 이동
			trail = current;
			current = current->next;
		}
		// 검색의 결과 2가지
		// ##1 못 찾은 경우
		if (current == nullptr)
		{

			std::cout << "값" << data << "를 찾지 못했습니다.\n";
			return;
		}

		// #2 찾은 경우
		if (current == head)
		{
			// 헤드 노드 교체.
			head = head->next;
		}
		else
		{
			trail->next = current->next;
		}

		// 노드 삭제.
		delete current;

		// 저장된 요소의 수 감소 처리.
		--count;

	}

	void Print()
	{
		Node<T>* current = head;
		while (current != nullptr)
		{
			std::cout << "Data : "<< current->data << '\n';
			current = current->next;
		}
	}
	
	__forceinline int Count() const // 언리얼은 __forceinline을 좀 더 많이 씀
	{
		return count;
	}



private:
	Node<T>* head = nullptr;
	int count = 0;
};