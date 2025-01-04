#include "Account.h"
#include <iostream>
Account::Account()
    : _id(0), _name(nullptr), _balance(0)
{
}

Account::Account(int id, const char* name, int balance)
    : _id(id), _balance(balance)
{
    // name ���� �Ҵ�, ���ڿ� ���̸�ŭ �迭 ���� ����
    size_t len = strlen(name)+1;
    _name = new char[len];
    strcpy_s(_name, len, name);
}

void Account::deposit(int depositAmount)
{
    _balance += depositAmount;
}

Account::Account(const Account& other)
    :Account(other._id,other._name, other._balance )
{

}

Account& Account::operator=(const Account& other)
{
    if (this != &other)
    {
        this->_id = other._id;
        if (_name != nullptr) {
            size_t len = strlen(other._name) + 1;
            _name = new char[len];
            strcpy_s(_name, len, other._name);
        }
        this->_balance = other._balance;
    }
    return *this;
}

void Account::setName(const char* name)
{
    if (_name != nullptr) {
        delete[] _name;
        _name = nullptr;
    }
    size_t len = strlen(name)+1;
    _name = new char[len];
    strcpy_s(_name, len, name);
};

void Account::DonationInfo()
{
}

Account::~Account()
{

    std::cout << _name;
    std::cout  << " : Account �Ҹ��� ȣ��" << std::endl;
    delete[] _name;
}
