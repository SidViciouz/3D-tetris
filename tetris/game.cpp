#include <game.h>

using namespace std;

game::game(GLFWwindow* w,ranking& r): myPlay{w,r}, myRanking{r}{
	this->window = w;
}

bool game::show(){

	int input = 0;
	int success = false;
	
	cout << "1.Play\n";
	cout << "2.Ranking\n";
	cout << "3.Quit\n";

	while(!success){
		cin >> input;

		if(input != 1 && input != 2 && input != 3)
			cout << "input 1 or 2\n";
		else
			success = true;
	}
	
	system("clear");

	return this->execute(input);
}

bool game::execute(int input){
	if(input == 1)
		this->myPlay.start();
	else if(input == 2)
		this->myRanking.show();
	else if(input == 3)
		return true;
	else
		throw runtime_error("can't execute.");
	
	return false;
}
