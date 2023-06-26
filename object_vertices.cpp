#include "object_vertices.h"
#include <glm/glm.hpp>
#include <cstdio>

int cubeVertexCount = 36;

float cubeVertices[36 * 8] = {
    // positions          // normals           // texture coords
    1.0f,-1.0f,-1.0f,   0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
    -1.0f,-1.0f,-1.0f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
    1.0f,-1.0f,-1.0f,   0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
    1.0f, 1.0f,-1.0f,   0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
    -1.0f, 1.0f,-1.0f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

    -1.0f,-1.0f, 1.0f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,   0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
     1.0f,-1.0f, 1.0f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
    1.0f, 1.0f, 1.0f,   0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

    -1.0f,-1.0f,-1.0f,  0.0f,  -1.0f,  0.0f,  1.0f, 1.0f,
   1.0f,-1.0f, 1.0f,    0.0f,  -1.0f,  0.0f,  0.0f, 0.0f,
    1.0f,-1.0f,-1.0f,   0.0f,  -1.0f,  0.0f,  0.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,  0.0f,  -1.0f,  0.0f,  1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,  0.0f,  -1.0f,  0.0f,  1.0f, 0.0f,
    1.0f,-1.0f, 1.0f,   0.0f,  -1.0f,  0.0f,  0.0f, 0.0f,

     -1.0f, 1.0f, 1.0f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
   1.0f, 1.0f,-1.0f,     0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
     1.0f, 1.0f, 1.0f,   0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
     -1.0f, 1.0f, 1.0f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,   0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
     1.0f, 1.0f,-1.0f,   0.0f,  1.0f,  0.0f,  0.0f, 0.0f,

    -1.0f,-1.0f,-1.0f,  -1.0f, 0.0f,  0.0f,  1.0f, 1.0f,
     -1.0f, 1.0f, 1.0f, -1.0f, 0.0f,  0.0f,  0.0f, 0.0f,
     -1.0f,-1.0f, 1.0f, -1.0f, 0.0f,  0.0f,  0.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,  -1.0f, 0.0f,  0.0f,  1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,  -1.0f, 0.0f,  0.0f,  1.0f, 0.0f,
    -1.0f, 1.0f, 1.0f,  -1.0f, 0.0f,  0.0f,  0.0f, 0.0f,

    1.0f,-1.0f, 1.0f,   1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
    1.0f, 1.0f,-1.0f,   1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
     1.0f,-1.0f,-1.0f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
     1.0f,-1.0f, 1.0f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,   1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
    1.0f, 1.0f,-1.0f,   1.0f,  0.0f,  0.0f,  0.0f, 0.0f
};

glm::vec3 runway[] = {

    glm::vec3(25.0f, 0.0f, -30.0f),
    glm::vec3(25.0f, 0.0f, -20.0f),
    glm::vec3(25.0f, 0.0f, -10.0f),
    glm::vec3(25.0f, 0.0f, 0.0f),
    glm::vec3(25.0f, 0.0f, 10.0f),
    glm::vec3(25.0f, 0.0f, 20.0f),
    glm::vec3(25.0f, 0.0f, 30.0f),
    glm::vec3(25.0f, 0.0f, 40.0f),
    glm::vec3(25.0f, 0.0f, 50.0f),
    glm::vec3(25.0f, 0.0f, 60.0f),
    glm::vec3(25.0f, 0.0f, 70.0f),
    glm::vec3(25.0f, 0.0f, 80.0f),
};


glm::vec3 buildings_pos[] = {
    glm::vec3(25, 5.0f, -50.0f),
    glm::vec3(25, 5.0f, -250.0f),
    glm::vec3(0, 25.0f, -100.0f),
    glm::vec3(30, 10.0f, -150.0f),
    glm::vec3(0, 50.5f, -100.0f),
    glm::vec3(30, 20.25f, -150.0f),
    };

glm::vec3 buildings_scale[] = {
    glm::vec3(10.0f, 5.0f, 1.0f),
    glm::vec3(10.0f, 5.0f, 1.0f),
    glm::vec3(10.0f, 25.0f, 10.0f),
    glm::vec3(7.0f, 10.0f, 10.0f),
    glm::vec3(10.0f, 0.5f, 10.0f),
    glm::vec3(7.0f, 0.25f, 10.0f),
};

glm::vec3 buildings_corners_min[BUILDING_COUNT]= {
   glm::vec3(15.0f, 0.0f, -51.0f),
   glm::vec3(15.0f, 0.0f, -251.0f),
   glm::vec3(-10.0f, 0.0f, -110.0f),
   glm::vec3(23.0f, 0.0f, -160.0f),
   glm::vec3(-10.0f, 0.0f, -110.0f),
   glm::vec3(23.0f, 0.0f, -160.0f)
};

glm::vec3 buildings_corners_max[BUILDING_COUNT]={
    glm::vec3(35.0f, 10.0f, -49.0f),
    glm::vec3(35.0f, 10.0f, -249.0f),
    glm::vec3(10.0f, 50.0f, -90.0f),
    glm::vec3(37.0f, 20.0f, -140.0f),
    glm::vec3(10.0f, 51.0f, -90.0f),
    glm::vec3(37.0f, 20.5f, -140.0f)
 };

void generate_min_max_corners()
{
    for (int i=0; i<BUILDING_COUNT; i++)
    {
        buildings_corners_min[i] = buildings_pos[i] - buildings_scale[i];
        buildings_corners_max[i] = buildings_pos[i] + buildings_scale[i];
        printf("Building %d min: %.1ff, %.1ff, %.1ff\n", i, buildings_corners_min[i].x, buildings_corners_min[i].y, buildings_corners_min[i].z);
        printf("Building %d max: %.1ff, %.1ff, %.1ff\n", i, buildings_corners_max[i].x, buildings_corners_max[i].y, buildings_corners_max[i].z);
    }
}