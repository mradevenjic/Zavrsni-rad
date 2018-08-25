#pragma once
#include <glm\glm.hpp>

struct MyModel
{
	glm::vec3 lightPosition;
	glm::vec3 cubePosition;
	glm::vec3 planePosition;
	glm::vec3 spherePosition;
	glm::vec3 conePosition;

	glm::vec3 axisCylinder;
	glm::vec3 axisCube;
	glm::vec3 axisPlane;
	glm::vec3 axisSphere;
	glm::vec3 axisCone;
	float degreesCylinder;
	float degreesCube;
	float degreesPlane;
	float degreesSphere;
	float degreesCone;

	glm::vec3 scaling;
	glm::vec3 scaleCube;
	glm::vec3 scalePlane;
	glm::vec3 scaleSphere;
	glm::vec3 scaleCone;

	bool checkVisibilityCylinder;
	bool checkVisibilityCube;
	bool checkVisibilityPlane;
	bool checkVisibilitySphere;
	bool checkVisibilityCone;
};
