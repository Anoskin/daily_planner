#include "database.h"
#include <iomanip>
#include <iostream>

void Database::Add(const Date& data, const string& event) {

auto insert_set = base_set[data].insert(event);
	if (insert_set.second == false)
		return;
	else 
		base[data].push_back(event);
}

void Database::Print(ostream& stream) const{

	for (auto i = base.begin(); i != base.end(); ++i) {
		auto it = i->second.begin();
		while (it != i->second.end()) {
			stream << i->first.GetFull() << " " << *it << endl;
			++it;
		}
	}	
}

string Database::Last(const Date& data) const{

	if (base.begin() == base.end() || data < base.begin()->first) {
		throw invalid_argument("Do not last");
	}
	else {
		auto it = prev(base.upper_bound(data));
		return it->first.GetFull() + " " + it->second.back();
	}
}

ostream &operator <<(ostream &ostr, const pair<const Date*, const string*> &pr) {

	ostr << pr.first->GetFull() << " "
		 << *pr.second;
	return ostr;
}