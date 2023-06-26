#ifndef COLLISIONS_H
#define COLLISIONS_H
#include <glm/glm.hpp>

//map

bool collisionOnX(glm::vec3 corner);
bool collisionOnY(glm::vec3 corner);
bool collisionOnZ(glm::vec3 corner);
glm::bvec3 collisionDetect(glm::mat4 futurePlaneM);

//buildings
bool cornerCollisionWithBuilding(glm::vec3 corner);
bool CollisionWithBuilding(glm::mat4 planeM);
#endif
