#include "collisions.h"

#include <glm/gtc/matrix_transform.hpp>
#include "object_vertices.h"
#include <cstdio>
// map

bool collisionOnX(glm::vec3 corner)
{
	return (corner.x <= -300 || corner.x >= 300);
}

bool collisionOnY(glm::vec3 corner)
{
	return (corner.y <= 0.2f);
}

bool collisionOnZ(glm::vec3 corner)
{
	return (corner.z <= -400 || corner.z >= 200);
}

glm::vec3 mattopos(glm::mat4 M)
{
	return glm::vec3(M[3][0], M[3][1], M[3][2]);
}

glm::bvec3 collisionDetect(glm::mat4 futurePlaneM)
{
	glm::vec3 futurePosition = mattopos(futurePlaneM);
	glm::vec3 futureLeftUpperCorner = mattopos(glm::translate(futurePlaneM, glm::vec3(-6, 1.6, 1.5f)));
	glm::vec3 futureLeftBottomCorner = mattopos(glm::translate(futurePlaneM, glm::vec3(-6, 0.5, 1.5f)));
	glm::vec3 futureRightUpperCorner = mattopos(glm::translate(futurePlaneM, glm::vec3(6, 1.6, 1.5f)));
	glm::vec3 futureRightBottomCorner = mattopos(glm::translate(futurePlaneM, glm::vec3(6, 0.5, 1.5f)));
	glm::vec3 futureMiddle = mattopos(glm::translate(futurePlaneM, glm::vec3(0, 0.9, 1.5f)));
	glm::vec3 corners[5] = {futureLeftUpperCorner, futureRightBottomCorner, futureLeftBottomCorner, futureRightUpperCorner, futureMiddle};

	
	bool collisionX;
	bool collisionY;
	bool collisionZ;

	if (futurePosition.x < 93 && futurePosition.x > -93)
		collisionX = false;
	else
	{
		for (int i = 0; i < 5; i++)
		{
			collisionX = collisionOnX(corners[i]);
			if (collisionX == true)
				break;
		}
	}

	if (futurePosition.y < 93 && futurePosition.y > 8)
		collisionY = false;
	else
	{
		for (int i = 0; i < 5; i++)
		{
			collisionY = collisionOnY(corners[i]);
			if (collisionY == true)
				break;
		}
	}

	if (futurePosition.z < 93 && futurePosition.z > -93)
		collisionZ = false;
	else
	{
		for (int i = 0; i < 5; i++)
		{
			collisionZ = collisionOnZ(corners[i]);
			if (collisionZ == true)
				break;
		}
	}
	glm::bvec3 collision = glm::bvec3(collisionX, collisionY, collisionZ);

	return collision;

	

}

// buildings

bool cornerCollisionWithBuilding(glm::vec3 corner)
{
	//printf("Corner position: %f %f %f\n", corner.x, corner.y, corner.z);
	//printf("Building corner min: %f %f %f\n", buildings_corners_min[0].x, buildings_corners_min[0].y, buildings_corners_min[0].z);
	//printf("Building corner max: %f %f %f\n", buildings_corners_max[0].x, buildings_corners_max[0].y, buildings_corners_max[0].z);

	for (int i = 0; i < BUILDING_COUNT; i++)
	{
		if (corner.x >= buildings_corners_min[i].x && corner.x <= buildings_corners_max[i].x)
		{
			if (corner.z >= buildings_corners_min[i].z && corner.z <= buildings_corners_max[i].z)
			{
				if (corner.y >= buildings_corners_min[i].y && corner.y <= buildings_corners_max[i].y)
				{
					return true;
				}
			}
		}
	}

	return false;
}


bool CollisionWithBuilding(glm::mat4 planeM)
{
	// glm::mat3 rotation = glm::mat3(planeM);
	glm::vec3 position = mattopos(planeM);
	// //print position
	//printf("Plane position: %f %f %f\n", position.x, position.y, position.z);
	glm::vec3 leftUpperCorner = mattopos(glm::translate(planeM, glm::vec3(-6, 1.6, 1.5f)));
	glm::vec3 leftBottomCorner = mattopos(glm::translate(planeM, glm::vec3(-6, 0.5, 1.5f)));
	glm::vec3 rightUpperCorner = mattopos(glm::translate(planeM, glm::vec3(6, 1.6, 1.5f)));
	glm::vec3 rightBottomCorner = mattopos(glm::translate(planeM, glm::vec3(6, 0.5, 1.5f)));
	glm::vec3 middle = mattopos(glm::translate(planeM, glm::vec3(0, 0.9, 1.5f)));
	glm::vec3 corners[5] = {leftUpperCorner, middle, rightBottomCorner, leftBottomCorner, rightUpperCorner};

	// string cornersNames[5]= { "leftUpperCorner", "middle", "rightBottomCorner","leftBottomCorner", "rightUpperCorner" };
	// printf("Plane position: %f %f %f\n", position.x, position.y, position.z);
	// print the corners
	// for (int i = 0; i < 5; i++) {	std::cout << cornersNames[i]<<"\t : " << corners[i].x << " " << corners[i].y << " " << corners[i].z << std::endl;}


	for (int i = 0; i < 5; i++)
	{
		if(cornerCollisionWithBuilding(corners[i]))
			return true;
	}

	return false;
}
