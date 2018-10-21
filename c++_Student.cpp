#include<stdio.h>
#include<iostream>
#include<string>
#include<cassert>
//#define NDUBUGE
using namespace std;
class Student {
public:
	Student() = default;
	Student(const string &s) : nameNo(s) { }
	Student(const string &s, int chi, int ma) :
			nameNo(s), chinese(chi), math(ma), sumgrade (chi + ma) { }
	Student(const Student&);       //拷贝构造函数 
	
	
	string name() const {return nameNo;}
	int grade() const {return sumgrade;}
	double avg_grade() const;
	
	Student& operator =(const Student&);
	Student& operator +=(const Student&);
	friend istream& operator >>(istream &is, Student &item);
	friend ostream& operator <<(ostream &os, Student &item);
	friend bool operator ==(const Student &lhs, const Student &rhs);
	friend bool operator !=(const Student &lhs, const Student &rhs);
	friend Student operator +(const Student &lhs, const Student &rhs);
	friend bool operator <(const Student &lhs, const Student &rhs);
	friend bool operator >(const Student &lhs, const Student &rhs);
	
	~Student() = default;     //析构函数 
	
private:
	string nameNo;
	int chinese = 0;
	int math = 0;
	int sumgrade = 0;
};

Student::Student(const Student &item) :
	nameNo(item.nameNo),
	chinese(item.chinese),
	math(item.math),
	sumgrade(item.sumgrade)
	{ }

double Student::avg_grade() const {
	if (sumgrade)
		return sumgrade / 2.0;
	else
		return 0;
}

Student& Student::operator =(const Student &item) {
	nameNo = item.nameNo;
	chinese = item.chinese;
	math = item.math;
	sumgrade = item.sumgrade;
	return *this;
}

Student& Student::operator +=(const Student &item) {
	chinese += item.chinese;
	math += item.math;
	sumgrade += item.sumgrade;
	return *this;
}

istream& operator >>(istream &is, Student &item) {
	is >> item.nameNo >> item.chinese >> item.math;
	if (is)
		item.sumgrade = item.chinese + item.math;
	else
		item = Student();
	return is;
}

ostream& operator <<(ostream &os, Student &item) {
	os << item.name() << " " <<  item.chinese << " "
		<< item.math << " " << item.sumgrade;
	return os;
}

bool operator ==(const Student &lhs, const Student &rhs) {
	return lhs.name() == rhs.name();
}

bool operator !=(const Student &lhs, const Student &rhs) {
	return !(lhs == rhs);
}

Student operator +(const Student &lhs, const Student &rhs) {
	Student sum = lhs;
	sum += rhs;
	return sum;
}

bool operator <(const Student &lhs, const Student &rhs) {
	return lhs.sumgrade < rhs.sumgrade;
}

bool operator >(const Student &lhs, const Student &rhs) {
	return lhs.sumgrade > rhs.sumgrade;
}

int main()
{
	string sa = "liang";
	Student temp(sa,20,30);
	assert(temp.name() == sa);      //#1 assert
	assert(temp.grade() == 50);     //#2 assert
	cout << "temp is :" << endl;
	cout <<  temp << endl;
	cout << "avg_grade = " << temp.avg_grade() << endl;
	cout << "temp.name is :" << temp.name() << endl;
	cout << "temp.grade = " << temp.grade() << endl;
	cout << endl;
	
	Student buff(temp);     //拷贝构造
	assert(buff.name() == sa);     //#3 assert
	assert(buff.grade() == 50);    //#4 assert
	cout << "buff is :" << endl;
	cout << buff << endl;
	cout << endl;
	
	Student M;
	assert(M.name() == "");     //#5 assert
	assert(M.grade() == 0);     //#6 assert
	cout << "M is " << M << endl;
	cout << endl;

	Student N("zhang");
	assert(N.name() == "zhang");    //#7 assert
	assert(N.grade() == 0);         //#8 assert
	cout << "N is " << N << endl;
	cout << endl;
	
	M = temp;
	assert(M.name() == sa);     //#9 assert
	assert(M.grade() == 50);    //#10 assert
	cout << "M is " << M << endl;
	cout << endl;
	
	Student Stu("liang",25,25);
	assert(Stu.name() == "liang");     //#11 assert
	assert(Stu.grade() == 50);       //#12 assert
	if (Stu == temp){
		Stu += temp;
		cout << "Stu is " << Stu << endl;
		cout << endl;
	}
	if (N != temp){
		cout << "student " << N.name() << " NOT " << temp.name() << endl;
		cout << endl;
	}
	
	Student A;
	assert(cin >> A);      //#13 assert
	cout << "A is " << A << endl;
	cout << endl;
	
	Student sum = temp + A;
	assert(sum.grade() == temp.grade() + A.grade());      //#14 assert
	cout << sum << endl;
	cout << endl;
	
	if (A < temp){
		cout << A.name() << " less than " << temp.name() << endl;
		cout << endl;
	}
	if (A > temp){
		cout << A.name() << " more than " << temp.name() << endl;
		cout << endl;
	}
	return 0;
}
