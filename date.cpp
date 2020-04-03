#include "date.h"
#include <iomanip>

Date::Date(const string& data) {
	int y, m, d;
	istringstream ss(data);
	ss >> y;
	ss.ignore(1);
	ss >> m;
	ss.ignore(1);
	ss >> d;
	year = y;
	month = m;
	day = d;
}
int Date::GetDay() const{

	return day;
}

int Date::GetYear() const {

	return year;
}

int Date::GetMonth() const {

	return month;
}

Date ParseDate(istream& stream) {
	string format_date;
	stream >> format_date;
	return Date(format_date);
//	return (to_string(date.GetYear()) + "-" + to_string(date.GetMonth()) +
//		"-" + to_string(date.GetDay()));
}

string Date::GetFull() const {

	stringstream ss;
	ss << setfill('0');
	ss << setw(4) << year << "-"
		<< setw(2) << month << "-"
		<< setw(2) << day;
	return ss.str();
}


bool operator<(const Date& lhs, const Date& rhs) {

	return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
		vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator==(const Date& lhs, const Date& rhs) {

	return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} ==
		vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator>(const Date& lhs, const Date& rhs) {
	return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} >
		vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator>=(const Date& lhs, const Date& rhs) {
	return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} >=
		vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator<=(const Date& lhs, const Date& rhs) {
	return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <=
		vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator!=(const Date& lhs, const Date& rhs) {
	return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} !=
		vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

ostream& operator<<(ostream& stream, const Date& dat) {

	stream << dat.GetFull();
	return stream;
}