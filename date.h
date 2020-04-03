#pragma once
#include <string>
#include <sstream>
#include <set>
#include <iostream>
#include <vector>

using namespace std;

class Date
{
public:
	Date() {
	}
	Date(const string& data);
	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;
	string GetFull() const;
private:
	int year, month, day;
};

ostream& operator<<(ostream& stream, const Date& dat);
bool operator<(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);
Date ParseDate(istream& stream);

