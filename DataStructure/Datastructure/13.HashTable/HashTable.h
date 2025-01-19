#pragma once
#include <vector>
#include <string>
#include "Pair.h"

class HashTable
{
public:
	using Entry = Pair<std::string, std::string>;
	HashTable() = default;
	~HashTable() = default;

	void Add(std::string key, std::string value);
	void Delete(std::string key);
	bool Find(std::string key, Entry& outValue);
	void Print();

private:
	// ���� ������� ũ�� (�Ҽ� (Prime Numebr)�� ����ϴ� ���� ����). ���� ���� Ŭ���� ����
	// ��� �۾��� ������ ���� �Ҽ��� �浹 �� Ȯ�� ����
	static const int bucketCount = 19;
	//std::vector<Pair<std::string, const char&>> table[bucketCount];
	std::vector<Entry> table[bucketCount];
};