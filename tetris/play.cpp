#include <iostream>
#include <play.h>
#include <cstdlib>
#include <mach/mach_time.h>
#include <input.h>

using namespace std;

play::play(GLFWwindow* w,ranking& r) : myGraphic{w,myField,blocks,size}, myRanking{r}{
	srand(time(NULL));
	this->size = 0;
	this->lastTime = mach_absolute_time();
	this->lastQuarterTime = mach_absolute_time();
	this->window = w;
	this->score = 0;
}

void play::start(){
	bool gameOver = false;

	while(!gameOver){
		blocks[size++] = new block(myField);
		bool isEnd = false;
		while(!gameOver && !isEnd){
			if(this->isOneSecPassed()){
				isEnd = blocks[size-1]->update();
			}
			if(this->isQuarterSecPassed()){
				myField.check();
				int dX = 0,dY = 0,dR = 0,dP = 0, dYaw = 0;
				gameOver = input::get(dX,dY,dR,dP,dYaw,this->window);
				if(gameOver)
					break;
				blocks[size-1]->move(dX,dY,dR,dP,dYaw);
				myGraphic.draw();
				gameOver = myField.isGameOver();
			}
		}
	}
	
	myRanking.inputRanking(getScore());
}

bool play::isOneSecPassed(){
	uint64_t curTime = mach_absolute_time();

	if(curTime - this->lastTime > 5000000){
		this->lastTime = curTime;
		return true;
	}
	return false;
}

bool play::isQuarterSecPassed(){
	uint64_t curTime = mach_absolute_time();

	if(curTime - this->lastQuarterTime > 1250000){
		this->lastQuarterTime = curTime;
		score += 10;
		return true;
	}
	return false;

}

int play::getScore(){
	return this->score;
}
