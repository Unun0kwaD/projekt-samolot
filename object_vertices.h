
#include <glm/glm.hpp>
#ifndef OBJECTS_VERTICES
#define OBJECTS_VERTICES

#define BUILDING_COUNT 6
//-------------------------FILE WITH POSITIONS AND INFORMATION TO DRAW CUBE --------------------

extern int cubeVertexCount;

extern float cubeVertices[36 * 8];

extern glm::vec3 runway[];


extern glm::vec3 buildings_pos[BUILDING_COUNT];

extern glm::vec3 buildings_scale[BUILDING_COUNT];

extern glm::vec3 buildings_corners_min[BUILDING_COUNT];

extern glm::vec3 buildings_corners_max[BUILDING_COUNT];

void generate_min_max_corners();
#endif
