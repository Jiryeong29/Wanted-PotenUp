#pragma once

#include <iostream>

// ���� �����غ��� ���ڿ� Ŭ����
// MFC - UI.
class String
{
public:

	// �Ϲ� ������.
	String(const char* string = nullptr);

	// ���� ������.
	String(const String& other);
	
	// �Ҹ���.
	~String();

	//  ������ �����ε�
	friend std::ostream& operator<<( std::ostream& os, const String& string); // ����� ���� ������ �����ε�

	// ���� ������
	String& operator= (const String& other);

	bool operator ==(const String& other);
	bool operator !=(const String& other);

	// Getter.
	const int Length() const;
	const char* Data() const;

	// Setter


private:
	int length; // ���ڿ� ����
	char* data; // ���ڿ� �����ϴ� ����(�����/�����̳�/Container). ����Ҹ� �����̳ʶ�� ���� �Ҹ�

};

