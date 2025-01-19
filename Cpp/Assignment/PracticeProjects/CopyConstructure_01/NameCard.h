#pragma once
class NameCard
{
public:
	NameCard(const char* name, const char* phoneNumber, const char* email, const char* job);
	~NameCard();
	NameCard(const NameCard& nameCard);

	void ShowData();

private:
	char* data[4];
};