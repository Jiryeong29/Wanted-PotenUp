#include <iostream>
#include <vector>		// 동적 배열
#include <list>			// 연결 리스트.
// 수학 라이브러리
//Vector2/ Vector3 / Vector4


// 반복자.(Iterator)클래스. 
template<typename List>
class VectorIterator
{
public:
	// 타입 지정.
	using ValueType = typename List::ValueType;
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;

public:
	VectorIterator(PointerType pointer)
		: pointer(pointer)
	{

	}
	 // 전위 증가 연산자.
	// 포인터 증감 연산자 오버로딩.
	VectorIterator& operator++()
	{
		++pointer;
		return *this;
	}
	

	// 포인터 후위 증가 연산자 오버로딩.
	VectorIterator& operator++(int)
	{
		VectorIterator iterator = *this;
		++(*this);
		return iterator;
	}

	// 전위 감소 연산자 오버로딩.
	VectorIterator& operator--()
	{
		--pointer;
		return *this;
	}
	

	// 포인터 후위 감소 연산자 오버로딩.
	VectorIterator& operator--(int)
	{
		VectorIterator iterator = *this;
		--(*this);
		return iterator;
	}


	// 인덱스 연산자 오버로딩.
	ReferenceType operator[](int index)
	{
		return *(pointer + index);
	}

	// 포인터 연산자 오버로딩.
	PointerType operator->() {
		return pointer;
	}

	// 값 반환 연산자.
	ReferenceType operator*() {
		return *pointer;
	}

	// 비교 연산자 오버로딩
	bool operator==(const VectorIterator& other) const
	{
		return pointer == other.pointer;
	}
	// 비교 연산자 오버로딩
	bool operator!=(const VectorIterator& other) const
	{
		//return pointer != other.pointer;
		return !(*this == other); // 위에서 만든 비교 연산자 오버로딩을 이용한 코드
	}

private:
	PointerType pointer;
};

// 동적 배열()
// 템플릿.
template<typename T>
class List
{
public:
	using ValueType = T;
	using Iterator = VectorIterator<List<T>>;

public:
	List()
		:count(0)
	{
		// 초기 데이터 공간 설정.
		data = new T[capacity];
	}
	~List()
	{
		// 포인터가 가리키는 힙 배열 변수 삭제.
		if (data != nullptr)
		{
			delete[] data;
		}
	}

	// 원소 추가.
	void PushBack(const T& value)
	{
		// 자료를 추가할 수 있는 충분한 공간이 있는지 확인.
		if (count == capacity)
		{
			ReAllocate(capacity * 2);
			//ReAllocate(capacity * 2 / 2);
		}
		// 현재 배열의 마지막 요소에 전달받은 데이터 설정.
		data[count] = value;

		// 저장된 요소의 수 증가 처리.
		++count;
	}
	// Move 추가.
	void PuchBack(T&& value)
	{
		// 자료를 추가할 수 있는 충분한 공간이 있는지 확인.
		if (count == capacity)
		{
			ReAllocate(capacity * 2);
			//ReAllocate(capacity * 2 / 2);
		}
		// 현재 배열의 마지막 요소에 전달받은 데이터 설정.
		data[count] = std::move(value);

		// 저장된 요소의 수 증가 처리.
		++count;
	}

	// 접근 함수.
	T& At(int index)
	{
		if (index >= count)
		{
			__debugbreak();
		}
		return data[index];
	}
	// 접근 함수.
	const T& At(int index)const
	{
		if (index >= count)
		{
			__debugbreak();
		}
		return data[index];
	}

	// 연산자 오버로딩.
	 T& operator[](int index)
	{
		if (index >= count)
		{
			__debugbreak();
		}
		return data[index];
	}
	 // 연산자 오버로딩.
	const T& operator[](int index)const
	{
		if (index >= count)
		{
			__debugbreak();
		}
		return data[index];
	}
	// Iterator 관련 함수.
	Iterator begin()
	{
		return Iterator(data);
	}
	Iterator end()
	{
		return Iterator(data + count);
	}

	// Getter.
	// 요소 수 반환.
	int Count() const { return count; }

	// 저장 용량 반환.
	 int Capacity() const {return capacity;}

	 // 배열 주소 반환.
	 T* Data() const { return data; }

	// 배열 주소 반환.
private:
	// 저장할 공간이 부족할 떄 공간을 늘리는 함수.
	void ReAllocate(int newCapacity)
	{
		// 1. 자료를 추가할 수 있는 충분한 공간이 있는지 확인.
		// 2. 기존 데이터 복사.
		// 3. 기존 데이터 및 임시 데이터 삭제.
		T* newBlock = new T[newCapacity];
		memset(newBlock, 0, sizeof(T) * newCapacity);
		//복사.
		//for (int ix = 0; ix < count; ++ix)
		//{
		//	newBlock[ix] = std::move(data[ix]);
		//	//newBlock[ix] = data[ix];
		//}
		// 메모리 복사. 주소와 크기를 다루므로 주의하기
		memcpy(newBlock, data, sizeof(T) * count);

		delete[] data;

		data = newBlock;

		capacity = newCapacity;
	}

private:
	// 데이터 선언.(힙에 할당할 배열 변수)
	T* data = nullptr;

	// 용량.
	int capacity = 2;

	// 배열 원소의 수.
	int count = 0;
};

int main()
{
	// 동적 배열 객체 생성.
	List<int> list;
	
	List<int>::ValueType;

	// 원소 추가.
	for (int ix = 0;ix < 100; ++ix)
	{
		list.PushBack(10);
	}

	char buffer[256];
	snprintf(buffer, 256, "%d %d\n", list.Count(), list.Capacity());

	// const int& value = list[1000]; 호출스택에서 디버깅
	std::cout << buffer;
	//std::cout << list.Count() << ", " << list.Capacity() << '\n';

	// Standard Template Library(STL) 동적 배열.
	std::vector<int> vector;
	/*{
		1, 2, 3, 4, 5
	};*/
	for (int ix = 0;ix < 100; ++ix)
	{
		vector.push_back(ix);
		//vector.emplace_back(10); // c최근은 성능적 차이가 없음
	}

	// 읽기
	// Range - Based Loop / Ranged Loop.  순서대로 나오는 걸 보장하지 않지만 아마 순서대로 나옴
	// forEach /Foreach
	for (const auto& item : vector)
	{
		std::cout << item << " ";
	}


	for (const auto& item : list)
	{

	}
	for (auto iterator = list.begin(); iterator != list.end(); ++iterator)
	{
		std::cout << *iterator << " " << std::endl;
	}
	std::cout << "\n";
	snprintf(buffer, 256, "%d, %d", static_cast<int>(vector.size()),static_cast<int>( vector.capacity()));

	std::cout << buffer;
}