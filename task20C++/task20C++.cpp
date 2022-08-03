// task20C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;
class WrongLoginException : public exception
{
private:
	
public:
	WrongLoginException()
	{

	}
	WrongLoginException(const char* msg) :exception(msg)
	{
		cout << "WrongLoginException" << endl;
		
	}
	
};
class WrongPasswordException : public exception
{
private:
	
public:
	WrongPasswordException()
	{

	}
	WrongPasswordException(const char* msg) :exception(msg)
	{
		
		cout << "WrongPasswordException" << endl;
	}
	
};
class User
{
private:
    string login;
    string pass;
public:
    User()
    {

    }
    static void Register(string login, string pass, string confirmPassword) throw (WrongLoginException, exception,WrongPasswordException) 
    {
		for (int i = 0; i < login.length(); i++)
		{
			if ((login[i] >= 'a' && login[i] <= 'z' || login[i] >= 'A' && login[i] <= 'Z' || login[i] >= '0' && login[i] <= '9' || login[i] == '_'))
				continue;
			else throw WrongLoginException("wrong symbol in Login");
		}
		for (int i = 0; i < pass.length(); i++)
		{
			if ((pass[i] >= 'a' && pass[i] <= 'z' || pass[i] >= 'A' && pass[i] <= 'Z' || pass[i] >= '0' && pass[i] <= '9' || pass[i] == '_'))
				continue;
			else throw WrongPasswordException("wrong symbol in Password");
		}
		if (login.length() < 20 && pass.length() < 20 && pass==confirmPassword)
			cout << "Login and Password correct" << endl;
		else
		{
			if (login.length() >= 20)
			{
				throw WrongLoginException("login length > 20");
			}
			else
			{
				if (pass.length() >= 20)
				{
					throw WrongPasswordException("Password length > 20");
				}
			    else
				{
					if (pass != confirmPassword)
					{
						throw WrongPasswordException("Password != confirmPassword");
					}
				}
			}
		}
		
    }

};



int main()
{
	User u;
	//u.Register("Aghg", "1234h","1234h");
	try
	{
		u.Register("Ag123_+", "123i","123i");
	}
	catch (WrongLoginException ex)
	{
		cout << ex.what() << endl;
	}
	catch (WrongPasswordException ex)
	{
		cout << ex.what() << endl;
	}
}
