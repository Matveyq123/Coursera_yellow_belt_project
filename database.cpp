#include"database.h"

void Database::Add(const Date& date, const std::string& event) {
	const size_t size = AllData[date].size();
	AllData[date].insert(event);
	if (size < AllData[date].size()) {
		StorageData[date].push_back(event);
	}
}
void Database::Print(std::ostream& os) const {
	for (const auto& item : StorageData) {
		for (const auto& s : item.second) {
			os << item.first << " " << s << std::endl;
		}
	}
}
std::pair<Date, std::string> Database::Last(const Date& date) const{
	if (StorageData.empty()) {
		throw std::invalid_argument("Database is empty");
	}
	auto result = StorageData.upper_bound(date);
	if (result == StorageData.begin()) {
		throw std::invalid_argument("No dates lower");
	}
	--result;
	return std::make_pair(result->first, result->second.back());
}
std::ostream& operator << (std::ostream& os, const std::pair<Date, std::string>& p) {
	os << p.first << " " << p.second;
	return os;
}
std::ostream& operator << (std::ostream& os, const std::map<Date, std::vector<std::string>>& d) {
	for (const auto& item : d) {
		os << item.first;
		for (const std::string& s : item.second) {
			os << s;
		}
	}
	return os;
}
std::ostream& operator << (std::ostream& os, const std::pair<Date, std::vector<std::string>>& str_p) {
	for (const auto& item : str_p.second) {
		os << str_p.first << " " << item;
	}
	
	return os;
}
