#include <iostream>
using namespace std;

//Include GLEW
#define GLEW_STATIC
#include <opengl\include\GL\glew.h>

//Include GLFW
#include <opengl\include\GLFW\glfw3.h>

//Function Prototype
void key_callback(GLFWwindow);

const GLchar* vertexShaderSource = "#version 330 core\n"
"layout (location =0 ) in vec3 position;\n"
"void main()\n"
"{\n"
"gl_Position= vec4(position.x, position.y, position.z, 1.0);\n"
"}\0";

const GLchar* fragmentShaderSource = "#version 330 core\n"
"out vec4 color;\n"
"void main()\n"
"{\n"
"color = vec4 (1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";

void main()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	//create a GLFWWindow object
	GLFWwindow* window = glfwCreateWindow(800, 600, "Tutorial Hello Triangle", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	//set callback function
	glfwSetKeyCallback(window, key_callback);

	//Set TRUE for glew retreving function and pointers
	glewExperimental = GL_TRUE;

	//Initate GLEW
	glewInit();

	//create viewport
	glViewport(0, 0, 800, 600);

	//Vertex shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	//Check for compilation error
	GLint success;
	GLchar infoLog[512];

	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) 
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << endl;
	}
}
