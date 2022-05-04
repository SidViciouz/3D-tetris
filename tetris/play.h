#pragma once
#include <vector>
#include <block.h>
#include <field.h>
#include <graphic.h>
#include <ranking.h>
#include <GLFW/glfw3.h>
#define MAX_BLOCKS 100

class play{
public:
	play() = delete;
	play(GLFWwindow* w,ranking& r);
	~play(){};
	void start();
	bool isOneSecPassed();
	bool isQuarterSecPassed();
	int getScore();
private:
	block* blocks[MAX_BLOCKS];
	field myField;
	graphic myGraphic;
	int size; // size of blocks
	uint64_t lastTime;
	uint64_t lastQuarterTime;
	GLFWwindow* window;
	ranking& myRanking;
	int score;
};
