#pragma once
#include <iostream>
#include <string>

using namespace std;

class Exception : public  exception
{
private:
    const string m_msg;
public:
    Exception(const string& msg) : m_msg(msg) {
        cout << "MyException::MyException - set m_msg to:" << m_msg << endl;
    }
    ~Exception() {}

    virtual const char* what() const throw () {
        cout << "Exception::what" << endl;
        return m_msg.c_str();
    }
};

