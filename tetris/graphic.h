#include <iostream>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <shaders/shader.hpp>
#include <field.h>
#include <block.h>

using namespace glm;

class graphic{
public:
	graphic() = delete;
	graphic(GLFWwindow* w,field& f,block** b,int& s);
	~graphic(){};
	void draw();
private:
	GLFWwindow* window;
	field& myField;
	block** blocks;
	int& size;
	GLuint program;
	GLuint matrix;
	GLuint VBO;
	GLuint VAO;
	GLuint colorBuffer;
};
