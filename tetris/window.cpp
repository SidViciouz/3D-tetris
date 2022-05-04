#include <window.h>

window::window(){	
	glfwInit();
	glfwWindowHint(GLFW_SAMPLES,4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);	
	this->w = glfwCreateWindow(640,480,"TETRIS",NULL,NULL);
	glfwSetWindowPos(this->w,0,0);
	glfwPollEvents();
}

window::~window(){
	glfwDestroyWindow(this->w);
	glfwTerminate();
}

GLFWwindow* window::getWindow(){
	return this->w;
}
