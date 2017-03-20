#pragma once
#include <iostream>
#include <new>
#include <string>

#include "chainlist.h"

using std::string;
using namespace std;
struct StudentRecord
{
	int score_;
	string name_;

	StudentRecord(int score =0,string name="abc") : score_{score }, name_{ name } { }

	int operator !=(const StudentRecord& x) const { return (score_ != x.score_); }
	operator int() const { return score_; }
};

ostream& operator<<(ostream& out, const StudentRecord& x)
{
	out << x.score_ << '  ' << x.name_ << endl;
	return out;
}

void bin_sort(ChainList<StudentRecord>& theChain, int range)
{
	ChainList<StudentRecord>* bin;
	bin = new ChainList<StudentRecord>[range + 1];


	int numberofElement = theChain.size();
	for (int i = 0; i < numberofElement; ++i)
	{
		StudentRecord x = theChain.get(0);
		theChain.erase(0);
		bin[x.score_].insert(0, x);
	}

	for (int j = range; j >= 0; --j)
	{
		while (!bin[j].empty())//在这里加个分号简直是个灾难啊！
		{
			StudentRecord x = bin[j].get(0);
			bin[j].erase(0);
			theChain.insert(0, x);
		}
	}
	delete[] bin;
}