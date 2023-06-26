#ifndef PLANE_H
#define PLANE_H

#include "Model.h"

extern Model *plane;
extern GLuint texPlane;
extern GLuint texPlane1;

void drawPlane(Shader& object_shader,glm::mat4 P, glm::mat4 V, glm::mat4 M);
void planeInit();
void planeFree();
glm::mat4 GetPlaneMatrix(glm::mat4 M, float roll_angle, float yaw_angle, float pitch_angle, float movement, bool &ground);
glm::mat4 getV(glm::mat4 M);


#endif