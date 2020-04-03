#pragma once

#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
	
#include "date.h"


using namespace std;

class Database
{
public:
	void Add(const Date& data, const string& event);
	void Print (ostream& stream) const;
	template<class IT>
	int RemoveIf(IT Func) { // удаление из базы по условию
	auto count = 0;
		auto it = base.begin();
		while (it != base.end()) {
			auto new_it = stable_partition(it->second.begin(), it->second.end(),
				[&count, &it, &Func](string even) {
					if (Func(it->first, even)) {
						++count;
						return false;
					}
					else
						return true;
				});
			if (new_it != it->second.end()) {
				for (auto i = new_it; i != it->second.end(); ++i) {
					base_set[it->first].erase(*i);
				}
				it->second.erase(new_it, it->second.end());
			}
			if (base_set[it->first].size() == 0) {
				++it;
				base_set.erase(prev(it)->first);
				base.erase(prev(it)->first);
			}
			else {
				++it;
			}
		}
		return count;
	}
	template<class ITERATOR>
		vector<pair<const Date*, const string*>>FindIf(ITERATOR fun) const {
		vector<pair<const Date*, const string*>> fin;

		for (auto i = base.begin(); i != base.end(); i++) {
			const Date &space = i->first;
			find_if(i->second.begin(), i->second.end(),
				[&space, &fin, fun](const string &str) {
					if (fun(space, str)) {
						fin.push_back(make_pair(&space, &str));
					}
					return false;
				});
		}

		return fin;
	}
	string Last(const Date& data) const;
private:
	 //map< Date, set<string>> base;
	map< Date, vector<string>> base;
	map<Date, set<string>> base_set;
};

ostream &operator <<(ostream &ostr, const pair<const Date*, const string*> &pr);