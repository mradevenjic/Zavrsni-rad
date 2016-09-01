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
};

