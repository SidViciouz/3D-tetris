#include <iostream>
#include <ranking.h>

using namespace std;

bool compare(pair<int,string> a, pair<int,string> b){
	return a.first > b.first;
}

void ranking::show(){
	if(this->rank.size() == 0)
		cout << "there is no rank yet.\n";
	else{
		int i=1;
		for(pair<int,string> r : this->rank){
			cout << i++ << "\t";
			cout << r.second << "\t:\t" << r.first << "\n";
		}
	}
}
void ranking::inputRanking(int score){

	string name;
	cout << "type your name : ";
	cin >> name;
	this->rank.push_back({score,name});
	sort(this->rank.begin(),this->rank.end(),compare);	
}
