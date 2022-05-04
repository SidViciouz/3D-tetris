#include <input.h>
#include <GLFW/glfw3.h>
#include <iostream>

bool input::get(int& dX,int& dY,int& dR,int& dP,int& dYaw,GLFWwindow* window){
	//glfwPollEvents();

	if(glfwGetKey(window,GLFW_KEY_ESCAPE) == GLFW_PRESS)
		return true;

	int minusX = glfwGetKey(window,GLFW_KEY_A);
	int plusX = glfwGetKey(window,GLFW_KEY_D);
	int minusY = glfwGetKey(window,GLFW_KEY_S);
	int plusY = glfwGetKey(window,GLFW_KEY_W);
	int roll = glfwGetKey(window,GLFW_KEY_J);
	int pitch = glfwGetKey(window,GLFW_KEY_K);
	int yaw = glfwGetKey(window,GLFW_KEY_L);

	if(minusX == GLFW_PRESS)
		--dX;
	if(plusX == GLFW_PRESS)
		++dX;
	if(minusY == GLFW_PRESS)
		--dY;
	if(plusY == GLFW_PRESS)
		++dY;
	if(roll == GLFW_PRESS)
		++dR;
	if(pitch == GLFW_PRESS)
		++dP;
	if(yaw == GLFW_PRESS)
		++dYaw;
	
	return false;	
}
