#include <iostream>
using namespace std;

class String
{
private:
	char* str;
	int length;
	static int objectCount;
public:
	String()
		: str{ new char[80] },
		length{ 80 } {
		objectCount++;
	}
	String(int size)
		: str{ new char[size] },
		length{ size } {
		objectCount++;
	}
	String(const char* istr)
		: str{ new char[strlen(istr) + 1] },
		length(strlen(istr))
	{
		strcpy_s(str, length + 1, istr);
		objectCount++;
	}
	//copy
	String(const String& string):
	str{new char [string.length + 1]},
		length {string.length}
	{
		strcpy_s(str, length + 1, string.str);
		objectCount++;
	}
	~String()
	{
		delete[] str;
		objectCount--;
	}

	void cinstr() {
		cout << "Vvedite string: ";
		cin.getline(str, length);
	}

	void coutstr() {				// void showStr() const {
		cout << str << endl;
	}

	static int obj() {
		return objectCount;
	}
};
int String::objectCount = 0;

int main() {
    
}
