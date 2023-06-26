#ifndef BUILDINGS_H
#define BUILDINGS_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <shader.h>

extern GLuint texBuilding1;

extern GLuint texBuilding2;

extern GLuint texBuilding3;

extern GLuint texBuilding4;

extern glm::mat4 MRoofs[4][4];



void buildingsInit(glm::mat4 M);
void buildingsFree();
void drawBuildings(Shader& object_shader,glm::mat4 V, glm::mat4 P,unsigned int VAO);

#endif