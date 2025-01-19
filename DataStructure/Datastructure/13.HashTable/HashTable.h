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
	// 내장 저장소의 크기 (소수 (Prime Numebr)를 사용하는 것이 유리). 수가 많이 클수록 유리
	// 모듈 작업시 나누는 수가 소수면 충돌 날 확률 적음
	static const int bucketCount = 19;
	//std::vector<Pair<std::string, const char&>> table[bucketCount];
	std::vector<Entry> table[bucketCount];
};