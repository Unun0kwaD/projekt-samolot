#include "buildings.h"
#include "readtexture.h"
#include <object_vertices.h>
#include "lights.h"
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

GLuint texBuilding1;

GLuint texBuilding2;

GLuint texBuilding3;

GLuint texBuilding4;

GLuint texBuilding5;

glm::mat4 MBuildings[BUILDING_COUNT];

void buildingsInit(glm::mat4 M)
{

    // read buildings textures
    texBuilding1 = readTexture("textures/Facade014_1K-PNG/Facade014_1K_Color.png");
    texBuilding2 = readTexture("textures/Facade017_1K-PNG/Facade017_1K_Color.png");
    texBuilding3 = readTexture("textures/Bricks066_1K-PNG/Bricks066_1K_Color.png");
    texBuilding4 = readTexture("textures/Bricks074_1K-PNG/Bricks074_1K_Color.png");
    texBuilding5= readTexture("textures/Concrete042A_1K-PNG/Concrete042A_1K_Color.png");

    float x_shift;
    float z_shift;
    for (int i = 0; i < BUILDING_COUNT; i++)
    {

        glm::mat4 Building = M;
        Building = glm::translate(Building, buildings_pos[i]);
        MBuildings[i] = glm::scale(Building, buildings_scale[i]);
    
    }
}

void buildingsFree()
{

    // free buildings textures
    glDeleteTextures(1, &texBuilding1);
    glDeleteTextures(1, &texBuilding2);
    glDeleteTextures(1, &texBuilding3);
    glDeleteTextures(1, &texBuilding4);
    glDeleteTextures(1, &texBuilding5);
}

void drawBuildings(Shader &object_shader, glm::mat4 V, glm::mat4 P, unsigned int VAO)
{
    object_shader.use();

    object_shader.setMat4("P", P);
    object_shader.setMat4("V", V);

    GLuint buildingTextures[BUILDING_COUNT] = {
        texBuilding4, texBuilding3, texBuilding1, texBuilding2, texBuilding5,texBuilding5};

    for (int i = 0; i < BUILDING_COUNT; i++)
    {
        object_shader.setInt("texture1", i);
        glBindTexture(GL_TEXTURE_2D, buildingTextures[i]);
        glBindVertexArray(VAO);
        object_shader.setMat4("M", MBuildings[i]);
        glDrawArrays(GL_TRIANGLES, 0, 36);

    }
}
