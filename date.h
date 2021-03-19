#pragma once
#include<stdexcept>
#include<string>
#include<sstream>
#include<iostream>
#include <iomanip>
#include<vector>
class Date {
public:
    Date(const int& new_year, const int& new_month, const int& new_day);

    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;

private:
   const int year;
   const int month;
   const int day;
};

bool operator<(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);
std::ostream& operator<<(std::ostream& stream, const Date& date);
Date ParseDate(std::istream& date_stream);
