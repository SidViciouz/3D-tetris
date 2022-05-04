#include <GLFW/glfw3.h>

class window{
public:
	window();
	~window();
	GLFWwindow* getWindow();
private:
	GLFWwindow* w;	
};
