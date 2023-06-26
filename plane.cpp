
#include "plane.h"
#include "Model.h"
#include "readtexture.h"
#include "collisions.h"


Model *plane;
GLuint texPlane;
GLuint texPlane1;

void planeInit(){
	plane = new Model("models/piper/piper_pa18.obj");

	texPlane = readTexture("models/piper/textures/piper_diffuse.jpg");
	texPlane1 = readTexture("models/piper/textures/piper_refl.jpg");

}


glm::mat4 GetPlaneMatrix(glm::mat4 M, float roll_angle, float yaw_angle, float pitch_angle, float movement, bool &ground)
{
	//glm::mat4 M = model;

	glm::mat4 testM = glm::rotate(M, pitch_angle, glm::vec3(1.0f, 0.0f, 0.0f));
	glm::bvec3 collision = collisionDetect(testM);
	if (!(collision.x || collision.y || collision.z))
		M = testM;

	testM = glm::rotate(M, yaw_angle, glm::vec3(0.0f, 1.0f, 0.0f));
	collision = collisionDetect(testM);
	if (!(collision.x || collision.y || collision.z))
		M = testM;

	testM = glm::rotate(M, roll_angle, glm::vec3(0.0f, 0.0f, 1.0f));
	collision = collisionDetect(testM);
	if (!(collision.x || collision.y || collision.z))
		M = testM;

	glm::mat3 rotation = glm::mat3(M);

	glm::vec3 shift = rotation * glm::vec3(0, 0, movement);

	testM = glm::translate(M, glm::vec3(0, 0, movement));
	collision = collisionDetect(testM);

	if (rotation[1][1] < 0.85 && collision.y) ground = true;

	if (collision.x == false)
		M[3][0] += shift.x;
	if (collision.y == false)
		M[3][1] += shift.y;
	if (collision.z == false)
		M[3][2] += shift.z;

	return M;
}
void planeFree(){
	
	delete plane;
	glDeleteTextures(1, &texPlane);
	glDeleteTextures(1, &texPlane1);
}
void drawPlane(Shader& object_shader,glm::mat4 P, glm::mat4 V, glm::mat4 M)
{
	object_shader.use();

	object_shader.setMat4("P", P);
	object_shader.setMat4("V", V);
	object_shader.setMat4("M", M);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texPlane);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texPlane1);

	plane->Draw(object_shader);
}

glm::mat4 getV(glm::mat4 M)
{
	glm::vec3 planePosition = glm::vec3(M[3][0], M[3][1], M[3][2]);
	
	glm::vec3 cameraDistance = glm::vec3(0, 6, -20);
	glm::mat3 planeRotation = glm::mat3(M);

	cameraDistance = planeRotation * cameraDistance;
	glm::vec3 cameraPosition = cameraDistance + planePosition;
	glm::vec3 cameraUp = planeRotation * glm::vec3(0, 1, 0);

	if (cameraPosition.y <= 0.2f)
		cameraPosition.y = 0.3f;

	return glm::lookAt(cameraPosition, planePosition, cameraUp);
}



