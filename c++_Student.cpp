class Student {
public:
	Student() = default;
	Student(const std::string &s) : nameNo(s) { }
	Student(const std::string &s, int chi, int ma) :
			nameNo(s), chinese(chi), math(ma), sumgrade (chi * ma) { }
	Student&(const Student&);       //拷贝构造函数 
	
	
	std::string name() const {return nameNo;}
	std::int grade() const {return sungrade;}
	double avg_grade() const;
	
	Student& operator =(const Student&);
	Student& operator +=(const Student&);
	istream& operator >>(istream &is, Student &item);
	ostream& operator <<(ostream &os, Student &item);
	bool operator ==(const Student &lhs, const Student &rhs);
	bool operator !=(const Student &lhs, const Student &rhs);
	Student operator +(const Student &lhs, const Student &rhs);
	bool operator <(const Student &lhs, const Student &rhs);
	bool operator >(const Student &lhs, const Student &rhs);
	
	~Student() = default;     //析构函数 
	
private:
	std::string nameNo;
	int chinese = 0;
	int math = 0;
	int sumgrade = 0;
};
Student::Student&(const Student &item) :
	nameNo(item.nameNo);
	chinese(item.chinese);
	math(item.math);
	sumgrade(item.sumgrade);
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

istream& Student::operator <<(istream &is, Student &item) {
	is >> item.nameNo >> item.chinese >> item.math;
	if (is)
		item.sumgrade = item.chinese + item.math;
	else
		item = Student();
	return is;
}

ostream& Student::operator <<(ostream &os, Student &item) {
	os << item.name() << " " <<  item.chinese << " "
		<< item.math << " " << item.sumgrade;
	return os;
}

bool Student::operator ==(const Student &lhs, const Student &rhs) {
	return lhs.sumgrade == rhs.sumgrade;
}

bool Student::operator !=(const Student &lhs, const Student &rhs) {
	return !(lhs == rhs);
}

Student Student::operator +(const Student &lhs, const Student &rhs) {
	Student sum = lhs;
	sum += rhs;
	return sum;
}

bool Student::operator <(const Student &lhs, const Student &rhs) {
	return lhs.sumgrade < rhs.sumgrade;
}

bool Student::operator >(const Student &lhs, const Student &rhs) {
	return lhs.sumgrade > rhs.sumgrade;
}
