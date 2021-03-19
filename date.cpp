#include"date.h"
Date::Date(const int& new_year, const int& new_month, const int& new_day) : year(new_year), month(new_month), day(new_day) {}
int Date::GetYear() const {
    return year;
}
int Date::GetMonth() const {
    return month;
}
int Date::GetDay() const {
    return day;
}
bool operator<(const Date& lhs, const Date& rhs) {
    return std::vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
        std::vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}
bool operator==(const Date& lhs, const Date& rhs) {
    return std::vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} ==
        std::vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}
bool operator!=(const Date& lhs, const Date& rhs) {
    return std::vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} !=
        std::vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}
bool operator<=(const Date& lhs, const Date& rhs) {
    return std::vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <=
        std::vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}
bool operator>(const Date& lhs, const Date& rhs) {
    return std::vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} >
        std::vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}
bool operator>=(const Date& lhs, const Date& rhs) {
    return std::vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} >=
        std::vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}
Date ParseDate(std::istream& date_stream) {
    bool ok = true;

    int year, month, day;
    date_stream >> year;
    date_stream.ignore(1);
    date_stream >> month;
    date_stream.ignore(1);
    date_stream >> day;
    return Date(year, month, day);
}
std::ostream& operator<<(std::ostream& stream, const Date& date) {
    stream << std::setw(4) << std::setfill('0') << date.GetYear() <<
        "-" << std::setw(2) << std::setfill('0') << date.GetMonth() <<
        "-" << std::setw(2) << std::setfill('0') << date.GetDay();
    return stream;
}
