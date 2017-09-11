#pragma once
#include <ShapeData.h>
#include <string>

class ShapeGenerator
{
public:
	static ShapeData makeTriangle();
	static ShapeData makeCube();
	static ShapeData makeArrow();
	static ShapeData makeBlenderCube(const std::string& fileName);
	static ShapeData makeBlenderPlane(const std::string& fileName);
	static ShapeData makeBlenderSphere(const std::string& fileName);
	static ShapeData makeBlenderCone(const std::string& fileName);
	static ShapeData makeBlenderCylinder(const std::string& fileName);
	static ShapeData makeBlenderAxis(const std::string& fileName);
};

