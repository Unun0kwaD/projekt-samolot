
#ifndef LIGHTS_H
#define LIGHTS_H
#include <shader.h>
// #include <objects_vertices.h>

void lightdir(Shader& object_shader);
void RunwayLight1(Shader& object_shader,glm::vec3 start,glm::vec3 end);
void RunwayLight2(Shader& object_shader,glm::vec3 start,glm::vec3 end);

#endif