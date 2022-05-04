#include <GLFW/glfw3.h>

class input{
public:
	input(){};
	~input(){};
	static bool get(int& dX,int& dY,int& dR,int& dP,int& dYaw,GLFWwindow* window);
};
