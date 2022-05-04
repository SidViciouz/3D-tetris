#include <graphic.h>

extern int shape[3][3][3][3];
static const GLfloat vertices[] = {
	-1.0f,-1.0f,-1.0f,
	-1.0f,-1.0f, 1.0f,
	-1.0f, 1.0f, 1.0f,
	 1.0f, 1.0f,-1.0f,
	-1.0f,-1.0f,-1.0f,
	-1.0f, 1.0f,-1.0f,
	 1.0f,-1.0f, 1.0f,
	-1.0f,-1.0f,-1.0f,
	 1.0f,-1.0f,-1.0f,
	 1.0f, 1.0f,-1.0f,
	 1.0f,-1.0f,-1.0f,
	-1.0f,-1.0f,-1.0f,
	-1.0f,-1.0f,-1.0f,
	-1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f,-1.0f,
	 1.0f,-1.0f, 1.0f,
	-1.0f,-1.0f, 1.0f,
	-1.0f,-1.0f,-1.0f,
	-1.0f, 1.0f, 1.0f,
	-1.0f,-1.0f, 1.0f,
	 1.0f,-1.0f, 1.0f,
	 1.0f, 1.0f, 1.0f,
	 1.0f,-1.0f,-1.0f,
	 1.0f, 1.0f,-1.0f,
	 1.0f,-1.0f,-1.0f,
	 1.0f, 1.0f, 1.0f,
	 1.0f,-1.0f, 1.0f,
	 1.0f, 1.0f, 1.0f,
	 1.0f, 1.0f,-1.0f,
	-1.0f, 1.0f,-1.0f,
	 1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f,-1.0f,
	-1.0f, 1.0f, 1.0f,
	 1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f, 1.0f,
	 1.0f,-1.0f, 1.0f	
};

static const GLfloat color[] = {
	0.583f,  0.771f,  0.014f,
	0.609f,  0.115f,  0.436f,
	0.327f,  0.483f,  0.844f,
	0.822f,  0.569f,  0.201f,
	0.435f,  0.602f,  0.223f,
	0.310f,  0.747f,  0.185f,
	0.597f,  0.770f,  0.761f,
	0.559f,  0.436f,  0.730f,
	0.359f,  0.583f,  0.152f,
	0.483f,  0.596f,  0.789f,
	0.559f,  0.861f,  0.639f,
	0.195f,  0.548f,  0.859f,
	0.014f,  0.184f,  0.576f,
	0.771f,  0.328f,  0.970f,
	0.406f,  0.615f,  0.116f,
	0.676f,  0.977f,  0.133f,
	0.971f,  0.572f,  0.833f,
	0.140f,  0.616f,  0.489f,
	0.997f,  0.513f,  0.064f,
	0.945f,  0.719f,  0.592f,
	0.543f,  0.021f,  0.978f,
	0.279f,  0.317f,  0.505f,
	0.167f,  0.620f,  0.077f,
	0.347f,  0.857f,  0.137f,
	0.055f,  0.953f,  0.042f,
	0.714f,  0.505f,  0.345f,
	0.783f,  0.290f,  0.734f,
	0.722f,  0.645f,  0.174f,
	0.302f,  0.455f,  0.848f,
	0.225f,  0.587f,  0.040f,
	0.517f,  0.713f,  0.338f,
	0.053f,  0.959f,  0.120f,
	0.393f,  0.621f,  0.362f,
	0.673f,  0.211f,  0.457f,
	0.820f,  0.883f,  0.371f,
	0.982f,  0.099f,  0.879f
};

graphic::graphic(GLFWwindow* w,field& f,block** b,int& s): window{w}, myField{f}, blocks{b}, size{s}{

	glfwMakeContextCurrent(window);
	glewExperimental = true;
	
	if(glewInit() != GLEW_OK){
		throw std::runtime_error("glew init error.");
	}

	glClearColor(0.0f,0.0f,0.5f,0.0f);	
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glfwSwapBuffers(window);

	this->program = LoadShaders("shaders/shader.vert","shaders/shader.frag");
	this->matrix = glGetUniformLocation(program,"MVP");

	glGenVertexArrays(1,&this->VAO);
	glBindVertexArray(this->VAO);
	
	glGenBuffers(1,&this->VBO);
	glBindBuffer(GL_ARRAY_BUFFER,this->VBO);
	glBufferData(GL_ARRAY_BUFFER,sizeof vertices,vertices,GL_STATIC_DRAW);

	glGenBuffers(1,&this->colorBuffer);
	glBindBuffer(GL_ARRAY_BUFFER,this->colorBuffer);
	glBufferData(GL_ARRAY_BUFFER,sizeof color,color,GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER,this->VBO);
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);
	
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER,this->colorBuffer);
	glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,0,(void*)0);	
}

void graphic::draw(){

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glUseProgram(program);

	glm::mat4 projection = glm::perspective(glm::radians(45.0f),4.0f/3.0f,0.1f,100.0f);
	glm::mat4 view = glm::lookAt(glm::vec3(10,10,10),glm::vec3(0,3,0),glm::vec3(0,1,0));
	glm::mat4 VP = projection*view;
	glm::mat4 translate = glm::translate(mat4(1.0f), vec3(0.8f,-0.2f,0.8f));
	glm::mat4 scale = glm::scale(mat4(1.0f), vec3(0.9f, 0.05f, 0.9f));
	glm::mat4 MVP = VP*translate*scale;	

	glUniformMatrix4fv(this->matrix,1,GL_FALSE,&MVP[0][0]);
	glDrawArrays(GL_TRIANGLES,0,12*3);	
		
	for(int i=0; i<15; ++i)
	for(int j=0; j<9; ++j)
	for(int k=0; k<9; ++k){
		if(this->myField.fieldfilled[i][j][k] == 1){
			vector<int> position = {j,k,i};
			glm::mat4 translate = glm::translate(mat4(1.0f), vec3((position[0])*0.2f,(position[2])*0.2f,(position[1])*0.2f));
			glm::mat4 scale = glm::scale(mat4(1.0f), vec3(0.1f, 0.1f, 0.1f));
			glm::mat4 MVP = VP*translate*scale;	

			glUniformMatrix4fv(this->matrix,1,GL_FALSE,&MVP[0][0]);
		
			glDrawArrays(GL_TRIANGLES,0,12*3);	
			
		}
	}

	
	for(int k=0;k<3;++k)
	for(int l=0;l<3;++l)
	for(int j=0;j<3;++j)
	if(blocks[this->size-1]->blockShape[j][k][l] == 1){
		
		vector<int> position = blocks[this->size-1]->getPosition();
		glm::mat4 translate = glm::translate(mat4(1.0f), vec3((position[0] +k)*0.2f,(position[2]+j)*0.2f,(position[1]+l)*0.2f));
		glm::mat4 scale = glm::scale(mat4(1.0f), vec3(0.1f, 0.1f, 0.1f));
		glm::mat4 MVP = VP*translate*scale;	

		glUniformMatrix4fv(this->matrix,1,GL_FALSE,&MVP[0][0]);
	
		glDrawArrays(GL_TRIANGLES,0,12*3);	
	}

	glfwSwapBuffers(window);
	glfwPollEvents();
}
