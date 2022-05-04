#include <iostream>
#include <game.h>
#include <window.h>

using namespace std;

int main(){	

	try{	
		bool quit = false;
		ranking myRanking;
	
		while(!quit){
			window myWindow;
			game myGame(myWindow.getWindow(),myRanking);
			quit = myGame.show();
		}
			
	}
	catch(const exception& e){
		cout << e.what() << "\n";
	}	
	return 0;
}
