#pragma once
#include"date.h"
#include<string>
#include<vector>
#include<set>
#include<map>
#include<unordered_set>
#include<iterator>
#include <algorithm>


class Database {
public:
	void Add(const Date& date, const std::string& event);
	void Print(std::ostream& os) const;
	template<typename It>
	int RemoveIf(const It& predicate) {
		std::map<Date, std::unordered_set <std::string>> new_data;
		std::map<Date, std::vector <std::string>> new_storage_data;
		int result = 0;
		for (auto& p : StorageData) {
			const auto border = stable_partition(p.second.begin(), p.second.end(), [predicate, p](const auto& item) {
				return predicate(p.first, item);
				});
			size_t counter = p.second.size();
			if (border == p.second.end()) {
				result += counter;
			}
			else {
				new_data[p.first] = std::unordered_set <std::string>(border, p.second.end());
				new_storage_data[p.first] = std::vector<std::string>(border, p.second.end());
				result += counter - new_storage_data.at(p.first).size();
			}
		}
		StorageData = new_storage_data;
		AllData = new_data;
		return result;
	}
	template<typename It>
	std::vector<std::pair<Date, std::string>> FindIf(const It& predicate) const{
		std::map<Date, std::vector <std::string>> new_storage_data;
		std::vector<std::pair<Date, std::string>> result_pair;
		for (auto& p : StorageData) {
			std::vector<std::string> result;
			std::copy_if(p.second.begin(), p.second.end(), std::back_inserter(result), [predicate, p](const auto& item) {
				return predicate(p.first, item);
				});
			if (result.size() != 0) {
				new_storage_data[p.first] = result;
			}
		}
		for (const auto& p : new_storage_data) {
			for (const auto& item : p.second) {
				result_pair.push_back(std::make_pair(p.first, item));
			}
		}
		return result_pair;
	}
	std::pair<Date, std::string> Last(const Date& date) const;
private:
	std::map<Date, std::unordered_set <std::string>> AllData;
	std::map<Date, std::vector <std::string>> StorageData;
};
std::ostream& operator << (std::ostream& os, const std::pair<Date, std::vector<std::string>>& str_p);
std::ostream& operator << (std::ostream& os, const std::pair<Date, std::string>& p);
std::ostream& operator << (std::ostream& os, const std::map<Date, std::vector<std::string>>& d);
