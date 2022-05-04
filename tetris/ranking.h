#pragma once
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

class ranking{
public:
	ranking(){};
	~ranking(){};
	void show();
	void inputRanking(int score);

private:
	vector<pair<int,string>> rank;
};
