
#include "Node.h"

// ��带 ����� �ڷḦ �����ϴ� ��ũ�� ����Ʈ
template<typename T>
class LinkedList
{
public:
	LinkedList();

	~LinkedList()
	{
		// ���� ���..��.
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
		// �� ��� ����
		Node<T>* newNode = new Node<T>(data);

		// Case 1: ���� ��尡 ���� ���
		if (head == nullptr)
		{
			// ��� ��带 newNode�� ����
			head = newNode;
		}
		// Case 2: ��尡 �ִ� ���
		else
		{
			// �� ����� ���� ��带 ������ ��� ���� ����
			newNode->next = head;

			// ��� ��带 �� ���� ��ü
			head = newNode;
		}

		// ����� ��� �� ���� ó��
		++count;
	}


	void Insert(const T& data)
	{

		// �� ��� ����.
		Node<T>* newNode = new Node<T>(data);

		// ������ ��ġ ã��.
		if (head == nullptr)
		{
			head = newNode;
		}
		else
		{
			Node<T>* current = head;
			Node<T>* trail = nullptr;
			// ��ġ �˻�
			while (current != nullptr)
			{
				if (current->data >= data)
				{
					break;
				}
				trail = current;
				current = current->next;
			}
			// �˻��� ��尡 ����� ���
			if (current == head)
			{
				newNode->next = head;
				head = newNode;
			}
			// �˻��� ��尡 �߰��� ���
			else
			{
				newNode->next = current;
				trail->next = newNode;
			}

		}

		// ��� �� ���� ó��
		++count;
	}

	void Delete(const T& data)
	{
		// ���� ���..��.
		// ������ ��� ã��.
		if (head == nullptr)
		{
			std::cout << "����Ʈ�� ����־� ������ �Ұ��� �մϴ�.\n";
			return;
		}

		// �˻� ����.
		Node<T>* current = head;
		Node<T>* trail = nullptr;

		while (current != nullptr)
		{
			// �� ��
			if (current->data == data)
			{
				break;
			}

			// ��� �̵�
			trail = current;
			current = current->next;
		}
		// �˻��� ��� 2����
		// ##1 �� ã�� ���
		if (current == nullptr)
		{

			std::cout << "��" << data << "�� ã�� ���߽��ϴ�.\n";
			return;
		}

		// #2 ã�� ���
		if (current == head)
		{
			// ��� ��� ��ü.
			head = head->next;
		}
		else
		{
			trail->next = current->next;
		}

		// ��� ����.
		delete current;

		// ����� ����� �� ���� ó��.
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
	
	__forceinline int Count() const // �𸮾��� __forceinline�� �� �� ���� ��
	{
		return count;
	}



private:
	Node<T>* head = nullptr;
	int count = 0;
};