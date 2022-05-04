#pragma once
#include <iostream>
#include <play.h>
#include <ranking.h>
#include <GLFW/glfw3.h>

class game{
public:
	game() = delete;
	game(GLFWwindow* w,ranking& r);
	~game(){};
	bool show();	

private:
	bool execute(int input);
	play myPlay;
	ranking myRanking;
	GLFWwindow* window;
};
