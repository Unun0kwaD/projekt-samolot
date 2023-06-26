
#define GLM_FORCE_RADIANS
#define GLM_FORCE_SWIZZLE

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_access.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "constants.h"
#include "shader.h"
#include "object_vertices.h"
#include "Model.h"
#include "skybox.h"
#include "collisions.h"
#include "lights.h"
#include "buildings.h"
#include "readtexture.h"
#include "plane.h"

unsigned int VBO, VAO;

float roll_speed = 0;
float pitch_speed = 0;
float yaw_speed = 0;
float speed = 0;
float acceleration = 0;
float ratio = 2; // = width/height window

Shader *object_shader;
// Shader *light_shader;
Shader *skybox_shader;
Skybox *skybox;

bool spacebar = false;
bool ground = false;

GLuint texGround;
GLuint texGround1;

GLuint texRunway;

void error_callback(int error, const char *description)
{
	fputs(description, stderr);
}

void key_callback(
	GLFWwindow *window,
	int key,
	int scancode,
	int action,
	int mod)
{
	if (action == GLFW_PRESS)
	{
		if (key == GLFW_KEY_LEFT)
			roll_speed = -1;
		if (key == GLFW_KEY_RIGHT)
			roll_speed = 1;
		if (key == GLFW_KEY_UP)
			pitch_speed = 1;
		if (key == GLFW_KEY_DOWN)
			pitch_speed = -1;
		if (key == GLFW_KEY_A)
			yaw_speed = 1;
		if (key == GLFW_KEY_D)
			yaw_speed = -1;
		if (key == GLFW_KEY_W)
			acceleration = 0.5;
		if (key == GLFW_KEY_S)
			acceleration = -0.25;
		if (key == GLFW_KEY_ESCAPE)
			glfwSetWindowShouldClose(window, GL_TRUE);
	}
	if (action == GLFW_RELEASE)
	{
		if (key == GLFW_KEY_LEFT)
			roll_speed = 0;
		if (key == GLFW_KEY_RIGHT)
			roll_speed = 0;
		if (key == GLFW_KEY_UP)
			pitch_speed = 0;
		if (key == GLFW_KEY_DOWN)
			pitch_speed = 0;
		if (key == GLFW_KEY_A)
			yaw_speed = 0;
		if (key == GLFW_KEY_D)
			yaw_speed = 0;
		if (key == GLFW_KEY_SPACE)
			spacebar = true;
		if (key == GLFW_KEY_W)
			acceleration = 0;
		if (key == GLFW_KEY_S)
			acceleration = 0;
	}
}

void windowResizeCallback(GLFWwindow *window, int width, int height)
{
	if (height == 0)
		return;
	ratio = (float)width / (float)height;
	glViewport(0, 0, width, height);
}

void initOpenGLProgram(GLFWwindow *window)
{
	glClearColor(0, 0,0, 1);
	glEnable(GL_DEPTH_TEST);
	glfwSetWindowSizeCallback(window, windowResizeCallback);
	glfwSetKeyCallback(window, key_callback);

	// init shaders
	object_shader = new Shader("shaders/v_object.glsl", "shaders/f_object.glsl");
	lightdir(*object_shader);
	RunwayLight1(*object_shader, runway[0], runway[11]);
	RunwayLight2(*object_shader, runway[0]+glm::vec3(0.0f, 0.0f, -400.0f), runway[11]+glm::vec3(0.0f, 0.0f, -400.0f));

	skybox_shader = new Shader("shaders/v_skybox.glsl", "shaders/f_skybox.glsl");

	// init skybox
	skybox = new Skybox;

	// read ground texture
	texGround = readTexture("textures/Grass001_1K-PNG/Grass001_1K_Color.png");
	// read runway texture
	texRunway = readTexture("textures/Road007_1K-PNG/Road007_1K_Color.png");

	buildingsInit(glm::mat4(1.0f));
	planeInit();

	generate_min_max_corners();
}

void freeOpenGLProgram(GLFWwindow *window)
{
	delete object_shader;
	// delete light_shader;
	delete skybox_shader;
	delete skybox;
	glDeleteTextures(1, &texGround);
	glDeleteTextures(1, &texGround1);
	glDeleteTextures(1, &texRunway);

	planeFree();
	buildingsFree();
}

// setup to draw cube
void setupBuffersCube()
{
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);



	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
}

// draw
void drawGround(glm::mat4 V, glm::mat4 P)
{
	
	object_shader->use();
	object_shader->setMat4("P", P);
	object_shader->setMat4("V", V);

	
	glm::mat4 Ms = glm::scale(glm::mat4(1.0f), glm::vec3(100.0f, 0.2f, 100.0f));	
	int x[] = { 0, 0, 0, 1, 1, 1, -1, -1, -1,0,0,1,1,-1,-1 };
	int z[] = { 0, 1, -1, 0, 1, -1, 0, 1, -1,-2,-3,-2,-3,-2,-3 };
	for (int i = 0; i < 15; i++)
	{
		glm::mat4 M = glm::translate(Ms, glm::vec3( 2.0f*x[i], 0.0f,  2.0f*z[i]));
	

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texGround);
		

		object_shader->setMat4("M", M);

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, cubeVertexCount);
		glBindVertexArray(0);
	}
}

void drawRunway(glm::mat4 V, glm::mat4 P, glm::mat4 M)
{
	for (int i = 0; i < 12; i++)
	{
		object_shader->use();
		glm::mat4 Runway = M;
		Runway = glm::translate(Runway, runway[i]);
		Runway = glm::scale(Runway, glm::vec3(5.0f, 0.23f, 5.0f));

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texRunway);

		object_shader->setMat4("P", P);
		object_shader->setMat4("V", V);
		object_shader->setMat4("M", Runway);

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, cubeVertexCount);
		glBindVertexArray(0);
	}
}

glm::mat4 drawScene(GLFWwindow *window, glm::mat4 planeModel, float roll_angle, float yaw_angle, float pitch_angle, float movement)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::mat4 P = glm::perspective(50.0f * PI / 180.0f, ratio, 0.1f, 300.0f);

	glm::mat4 planeM = GetPlaneMatrix(planeModel, roll_angle, yaw_angle, pitch_angle, movement, ground);
	// planeM = glm::scale(planeM, glm::vec3(1.2f,1.2f, 1.2f));

	glm::mat4 V = getV(planeM);

	drawPlane(*object_shader, P, V, planeM);


	drawRunway(V, P,glm::mat4(1.0f));
	drawRunway(V, P, glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -400.0f)));
	drawGround(V, P);

	drawBuildings(*object_shader, V, P, VAO);

	skybox->draw(*skybox_shader, V, P);
	glfwSwapBuffers(window);

	return planeM;
}

float calculateSpeed(float speed, glm::mat4 planeM)
{

	float max = 15;
	float min = 8;
	float newSpeed = speed + acceleration;
	if (acceleration > 0)
	{

		if (newSpeed > max)
			newSpeed = max;
	}
	else
	{
		if (planeM[3][1] < 1)
		{
			if (newSpeed < 0)
				newSpeed = 0;
		}
		else
		{
			if (newSpeed < min)
				newSpeed = min;
		}
	}

	return newSpeed;
}

// main
int main(void)
{
	GLFWwindow *window;

	glfwSetErrorCallback(error_callback);

	if (!glfwInit())
	{
		fprintf(stderr, "Nie można zainicjować GLFW.\n");
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow(1920, 1080, "Lot Samolotem", NULL, NULL);

	if (!window)
	{
		fprintf(stderr, "Nie można utworzyć okna.\n");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	initOpenGLProgram(window);

	float angle_x;
	float angle_y;
	float angle_z;
	float movement = 0;
	glm::mat4 planeM = glm::mat4(1.0f);

	// plane start
	planeM = glm::translate(planeM, glm::vec3(25.0f, 0.9f, 80.0f));
	planeM = glm::rotate(planeM, PI, glm::vec3(0.0f, 1.0f, 0.0f));

	// planeM = glm::scale(planeM, glm::vec3(3.0f, 3.0f, 3.0f));
	bool reset;
	glfwSetTime(0);
	setupBuffersCube(); // we already draw only cube so placed this function here
	while (!glfwWindowShouldClose(window))
	{

		// printf("%f\n", glfwGetTime());

		reset = CollisionWithBuilding(planeM);
		if (reset || spacebar || ground)
		{

			planeM = glm::mat4(1.0f);

			// plane start

			planeM = translate(planeM, glm::vec3(25.0f, 0.9f, 80.0f));
			planeM = rotate(planeM, PI, glm::vec3(0.0f, 1.0f, 0.0f));
			// planeM = glm::scale(planeM, glm::vec3(3.0f, 3.0f, 3.0f));
			speed = 0;
			acceleration = 0;
		}
		
		reset = spacebar = ground = false;
		angle_x = roll_speed * glfwGetTime();
		angle_y = yaw_speed * glfwGetTime();
		angle_z = pitch_speed * glfwGetTime();
		speed = calculateSpeed(speed, planeM);
		movement = speed * glfwGetTime();
		glfwSetTime(0);
		planeM = drawScene(window, planeM, angle_x, angle_y, angle_z, movement);
		glfwPollEvents();
	}

	freeOpenGLProgram(window);
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
	return 0;
}
