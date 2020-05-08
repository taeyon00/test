#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Coord {
private:
	char* name;
	int x;
	int y;

public:
	Coord() {};
	Coord(int x, int y) :x(x), y(y) {
		name = new char[10];
	};
	Coord(Coord& c)
	{

		name = new char[strlen(c.name) + 1];
		strcpy(name, c.name);
	}
	~Coord()
	{
		delete[] name;
	}
	Coord operator+(Coord& other);
	Coord operator-(Coord& other);

	friend Coord operator+(int ref, Coord& other);
	friend Coord operator*(Coord c1, Coord c2);
	friend ostream& operator<<(ostream os, Coord ref);
	friend istream& operator<<(istream is, Coord ref);

	void operator+= (Coord& other);
	bool operator==(Coord& other);
	bool operator!=(Coord& other);

	void operator++();
	void operator++(int);


	void operator=(Coord& ref);

	void showInfo();
};

//cout is within class "ostream"
ostream& operator<<(ostream os, Coord ref) {
	os << "[" << ref.x << "," << ref.y << "]";
	return os;
}
istream& operator<<(istream is, Coord ref) {
	is>>ref.x>>ref.y; //is==cin
	return is;
}

void Coord::operator++()
{
	this->x++;
	this->y++;
}

void Coord::operator++(int)
{

}

Coord operator+(int ref, Coord& other)
{
	Coord temp(ref + other.x, ref + other.y);
	return temp;
}


Coord operator*(Coord c1, Coord c2)
{
	return Coord(c1.x * c2.x, c1.y * c2.y);
}

void Coord::showInfo()
{
	cout << "[ " << x << " , " << y << " ]" << endl;
}

Coord Coord::operator+(Coord& other)
{
	Coord temp(x + other.x, y + other.y);
	return temp;
}

Coord Coord::operator-(Coord& other)
{
	Coord temp(x - other.x, y - other.y);
	return temp;
}

void Coord::operator+= (Coord& other)
{
	this->x += other.x;
	this->y += other.y;
}

bool Coord::operator==(Coord& other)
{
	return (x == other.x && y == other.y);
}

bool Coord::operator!=(Coord& other)
{
	return !(*this == other);
}

class Person {
private:
	char* name;
public:
	Person()
	{

	}
	Person(char* str)
	{
		name = new char[strlen(str) + 1];
		strcpy(name, str);
	}
	Person(Person& p)
	{
		name = new char[strlen(p.name) + 1];
		strcpy(name, p.name);
	}
	void operator=(Person& p)
	{
		name = new char[strlen(p.name) + 1];
		strcpy(name, p.name);
	}
};

int main(void)
{
	Person p("bin");
	Person p2(p);
	Person p3;
	p3 = p2;

	int x(3);

	Coord c1(5, 3);
	Coord c2(7, 1);
	c1.showInfo();
	c2.showInfo();
	Coord c3 = c1;
	//c3 = c1.operator+(c2);
	c3 = c1 + c2;
	c1 += c2;
	c3.showInfo();

	Coord c4 = c3;
	if (c3 == c4)
		cout << "same" << endl;
	Coord c5 = c3*c4;

	c5 = 10 + c3;
	c5.showInfo();

	++c5;
	c5++;

	cout << c5;

}
