#include "ShapeGenerator.h"
#include <glm\glm.hpp>
#include <Vertex.h>
#include "obj_loader.h"
#include "vector"
#include <iostream>
using glm::vec3;
using namespace std;
#define NUM_ARRAY_ELEMENTS(a) sizeof(a) / sizeof(*a)

ShapeData ShapeGenerator::makeTriangle()
{
	ShapeData ret;

	Vertex myTri[] =
	{
		glm::vec3(+0.0f, +1.0f, +0.0f),
		glm::vec3(+1.0f, +0.0f, +0.0f),

		glm::vec3(-1.0f, -1.0f, +0.0f),
		glm::vec3(+0.0f, +1.0f, +0.0f),

		glm::vec3(+1.0f, -1.0f, +0.0f),
		glm::vec3(+0.0f, +0.0f, +1.0f),
	};
	ret.numVertices = NUM_ARRAY_ELEMENTS(myTri);
	ret.vertices = new Vertex[ret.numVertices];
	memcpy(ret.vertices, myTri, sizeof(myTri));

	GLushort indices[] = { 0, 1, 2 };
	ret.numIndices = NUM_ARRAY_ELEMENTS(indices);
	ret.indices = new GLushort[ret.numIndices];
	memcpy(ret.indices, indices, sizeof(indices));

	return ret;
}

ShapeData ShapeGenerator::makeCube() {
	ShapeData ret;
	Vertex stackVerts[] = {
		vec3(-1.0f, +1.0f, +1.0f), // 0
		vec3(+1.0f, +0.0f, +0.0f), // Color
		vec3(+1.0f, +1.0f, +1.0f), // 1
		vec3(+0.0f, +1.0f, +0.0f), // Color
		vec3(+1.0f, +1.0f, -1.0f), // 2
		vec3(+0.0f, +0.0f, +1.0f), // Color
		vec3(-1.0f, +1.0f, -1.0f), // 3
		vec3(+1.0f, +1.0f, +1.0f), // Color

		vec3(-1.0f, +1.0f, -1.0f), // 4
		vec3(+1.0f, +0.0f, +1.0f), // Color
		vec3(+1.0f, +1.0f, -1.0f), // 5
		vec3(+0.0f, +0.5f, +0.2f), // Color
		vec3(+1.0f, -1.0f, -1.0f), // 6
		vec3(+0.8f, +0.6f, +0.4f), // Color
		vec3(-1.0f, -1.0f, -1.0f), // 7
		vec3(+0.3f, +1.0f, +0.5f), // Color

		vec3(+1.0f, +1.0f, -1.0f), // 8
		vec3(+0.2f, +0.5f, +0.2f), // Color
		vec3(+1.0f, +1.0f, +1.0f), // 9
		vec3(+0.9f, +0.3f, +0.7f), // Color
		vec3(+1.0f, -1.0f, +1.0f), // 10
		vec3(+0.3f, +0.7f, +0.5f), // Color
		vec3(+1.0f, -1.0f, -1.0f), // 11
		vec3(+0.5f, +0.7f, +0.5f), // Color

		vec3(-1.0f, +1.0f, +1.0f), // 12
		vec3(+0.7f, +0.8f, +0.2f), // Color
		vec3(-1.0f, +1.0f, -1.0f), // 13
		vec3(+0.5f, +0.7f, +0.3f), // Color
		vec3(-1.0f, -1.0f, -1.0f), // 14
		vec3(+0.4f, +0.7f, +0.7f), // Color
		vec3(-1.0f, -1.0f, +1.0f), // 15
		vec3(+0.2f, +0.5f, +1.0f), // Color

		vec3(+1.0f, +1.0f, +1.0f), // 16
		vec3(+0.6f, +1.0f, +0.7f), // Color
		vec3(-1.0f, +1.0f, +1.0f), // 17
		vec3(+0.6f, +0.4f, +0.8f), // Color
		vec3(-1.0f, -1.0f, +1.0f), // 18
		vec3(+0.2f, +0.8f, +0.7f), // Color
		vec3(+1.0f, -1.0f, +1.0f), // 19
		vec3(+0.2f, +0.7f, +1.0f), // Color

		vec3(+1.0f, -1.0f, -1.0f), // 20
		vec3(+0.8f, +0.3f, +0.7f), // Color
		vec3(-1.0f, -1.0f, -1.0f), // 21
		vec3(+0.8f, +0.9f, +0.5f), // Color
		vec3(-1.0f, -1.0f, +1.0f), // 22
		vec3(+0.5f, +0.8f, +0.5f), // Color
		vec3(+1.0f, -1.0f, +1.0f), // 23
		vec3(+0.9f, +1.0f, +0.2f), // Color
	};

	ret.numVertices = NUM_ARRAY_ELEMENTS(stackVerts);
	ret.vertices = new Vertex[ret.numVertices];
	memcpy(ret.vertices, stackVerts, sizeof(stackVerts));

	unsigned short stackIndices[] = {
		0,   1,  2,  0,  2,  3, // Top
		4,   5,  6,  4,  6,  7, // Front
		8,   9, 10,  8, 10, 11, // Right
		12, 13, 14, 12, 14, 15, // Left
		16, 17, 18, 16, 18, 19, // Back
		20, 22, 21, 20, 23, 22, // Bottom
	};
	ret.numIndices = NUM_ARRAY_ELEMENTS(stackIndices);
	ret.indices = new GLushort[ret.numIndices];
	memcpy(ret.indices, stackIndices, sizeof(stackIndices));

	return ret;
}

ShapeData ShapeGenerator::makeArrow()
{
	ShapeData ret;
	Vertex stackVerts[] =
	{
		// Top side of arrow head
		vec3(+0.00f, +0.25f, -0.25f),         // 0
		vec3(+1.00f, +0.00f, +0.00f),		  // Color
		vec3(+0.50f, +0.25f, -0.25f),         // 1
		vec3(+1.00f, +0.00f, +0.00f),		  // Color
		vec3(+0.00f, +0.25f, -1.00f),         // 2
		vec3(+1.00f, +0.00f, +0.00f),		  // Color
		vec3(-0.50f, +0.25f, -0.25f),         // 3
		vec3(+1.00f, +0.00f, +0.00f),		  // Color
											  // Bottom side of arrow head
		vec3(+0.00f, -0.25f, -0.25f),         // 4
		vec3(+0.00f, +0.00f, +1.00f),		  // Color
		vec3(+0.50f, -0.25f, -0.25f),         // 5
		vec3(+0.00f, +0.00f, +1.00f),		  // Color
		vec3(+0.00f, -0.25f, -1.00f),         // 6
		vec3(+0.00f, +0.00f, +1.00f),		  // Color
		vec3(-0.50f, -0.25f, -0.25f),         // 7
		vec3(+0.00f, +0.00f, +1.00f),		  // Color
											  // Right side of arrow tip
		vec3(+0.50f, +0.25f, -0.25f),         // 8
		vec3(+0.60f, +1.00f, +0.00f),		  // Color
		vec3(+0.00f, +0.25f, -1.00f),         // 9
		vec3(+0.60f, +1.00f, +0.00f),		  // Color
		vec3(+0.00f, -0.25f, -1.00f),         // 10
		vec3(+0.60f, +1.00f, +0.00f),		  // Color
		vec3(+0.50f, -0.25f, -0.25f),         // 11
		vec3(+0.60f, +1.00f, +0.00f),		  // Color
											  // Left side of arrow tip
		vec3(+0.00f, +0.25f, -1.00f),         // 12
		vec3(+0.00f, +1.00f, +0.00f),		  // Color
		vec3(-0.50f, +0.25f, -0.25f),         // 13
		vec3(+0.00f, +1.00f, +0.00f),		  // Color
		vec3(+0.00f, -0.25f, -1.00f),         // 14
		vec3(+0.00f, +1.00f, +0.00f),		  // Color
		vec3(-0.50f, -0.25f, -0.25f),         // 15
		vec3(+0.00f, +1.00f, +0.00f),		  // Color
											  // Back side of arrow tip
		vec3(-0.50f, +0.25f, -0.25f),         // 16
		vec3(+0.50f, +0.50f, +0.50f),		  // Color
		vec3(+0.50f, +0.25f, -0.25f),         // 17
		vec3(+0.50f, +0.50f, +0.50f),		  // Color
		vec3(-0.50f, -0.25f, -0.25f),         // 18
		vec3(+0.50f, +0.50f, +0.50f),		  // Color
		vec3(+0.50f, -0.25f, -0.25f),         // 19
		vec3(+0.50f, +0.50f, +0.50f),		  // Color
											  // Top side of back of arrow
		vec3(+0.25f, +0.25f, -0.25f),         // 20
		vec3(+1.00f, +0.00f, +0.00f),		  // Color
		vec3(+0.25f, +0.25f, +1.00f),         // 21
		vec3(+1.00f, +0.00f, +0.00f),		  // Color
		vec3(-0.25f, +0.25f, +1.00f),         // 22
		vec3(+1.00f, +0.00f, +0.00f),		  // Color
		vec3(-0.25f, +0.25f, -0.25f),         // 23
		vec3(+1.00f, +0.00f, +0.00f),		  // Color
											  // Bottom side of back of arrow
		vec3(+0.25f, -0.25f, -0.25f),         // 24
		vec3(+0.00f, +0.00f, +1.00f),		  // Color
		vec3(+0.25f, -0.25f, +1.00f),         // 25
		vec3(+0.00f, +0.00f, +1.00f),		  // Color
		vec3(-0.25f, -0.25f, +1.00f),         // 26
		vec3(+0.00f, +0.00f, +1.00f),		  // Color
		vec3(-0.25f, -0.25f, -0.25f),         // 27
		vec3(+0.00f, +0.00f, +1.00f),		  // Color
											  // Right side of back of arrow
		vec3(+0.25f, +0.25f, -0.25f),         // 28
		vec3(+0.60f, +1.00f, +0.00f),		  // Color
		vec3(+0.25f, -0.25f, -0.25f),         // 29
		vec3(+0.60f, +1.00f, +0.00f),		  // Color
		vec3(+0.25f, -0.25f, +1.00f),         // 30
		vec3(+0.60f, +1.00f, +0.00f),		  // Color
		vec3(+0.25f, +0.25f, +1.00f),         // 31
		vec3(+0.60f, +1.00f, +0.00f),		  // Color
											  // Left side of back of arrow
		vec3(-0.25f, +0.25f, -0.25f),         // 32
		vec3(+0.00f, +1.00f, +0.00f),		  // Color
		vec3(-0.25f, -0.25f, -0.25f),         // 33
		vec3(+0.00f, +1.00f, +0.00f),		  // Color
		vec3(-0.25f, -0.25f, +1.00f),         // 34
		vec3(+0.00f, +1.00f, +0.00f),		  // Color
		vec3(-0.25f, +0.25f, +1.00f),         // 35
		vec3(+0.00f, +1.00f, +0.00f),		  // Color
											  // Back side of back of arrow
		vec3(-0.25f, +0.25f, +1.00f),         // 36
		vec3(+0.50f, +0.50f, +0.50f),		  // Color
		vec3(+0.25f, +0.25f, +1.00f),         // 37
		vec3(+0.50f, +0.50f, +0.50f),		  // Color
		vec3(-0.25f, -0.25f, +1.00f),         // 38
		vec3(+0.50f, +0.50f, +0.50f),		  // Color
		vec3(+0.25f, -0.25f, +1.00f),         // 39
		vec3(+0.50f, +0.50f, +0.50f),		  // Color
	};

	GLushort stackIndices[] = {
		0, 1, 2, // Top
		0, 2, 3,
		4, 6, 5, // Bottom
		4, 7, 6,
		8, 10, 9, // Right side of arrow tip
		8, 11, 10,
		12, 15, 13, // Left side of arrow tip
		12, 14, 15,
		16, 19, 17, // Back side of arrow tip
		16, 18, 19,
		20, 22, 21, // Top side of back of arrow
		20, 23, 22,
		24, 25, 26, // Bottom side of back of arrow
		24, 26, 27,
		28, 30, 29, // Right side of back of arrow
		28, 31, 30,
		32, 33, 34, // Left side of back of arrow
		32, 34, 35,
		36, 39, 37, // Back side of back of arrow
		36, 38, 39,
	};

	ret.numVertices = sizeof(stackVerts) / sizeof(*stackVerts);
	ret.vertices = new Vertex[ret.numVertices];
	memcpy(ret.vertices, stackVerts, sizeof(stackVerts));

	ret.numIndices = sizeof(stackIndices) / sizeof(*stackIndices);
	ret.indices = new GLushort[ret.numIndices];
	memcpy(ret.indices, stackIndices, sizeof(stackIndices));
	return ret;
}

// RADI
/*ShapeData ShapeGenerator::makeBlenderCube(const std::string& fileName)
{
	ShapeData ret;
	IndexedModel model = OBJModel(fileName).ToIndexedModel();

	ret.numVertices = model.positions.size();
	ret.positions = new glm::vec3[ret.numVertices];
	//ret.vertices = new Vertex[ret.numVertices];
	std::copy(model.positions.begin(), model.positions.end(), ret.positions);

	for (int i = 0; i < ret.numVertices; i++){
		std::cout << "{"<< ret.positions[i].x << " " << ret.positions[i].y << " " << ret.positions[i].z << "}" << endl;
	}

	ret.numIndices = model.indices.size();
	ret.indices = new GLushort[ret.numIndices];
	std::copy(model.indices.begin(), model.indices.end(), ret.indices);
	return ret;
}*/

// NE RADI 
/*ShapeData ShapeGenerator::makeBlenderCube(const std::string& fileName)
{
	ShapeData ret;
	IndexedModel model = OBJModel(fileName).ToIndexedModel();

	glm::vec3* pozicije = new glm::vec3[model.positions.size()];
	std::copy(model.positions.begin(), model.positions.end(), pozicije);
	ret.numVertices = model.positions.size();
	ret.vertices = new Vertex[ret.numVertices];

	for (int i = 0; i < ret.numVertices; i++) 
	{
		std::cout << "{" << pozicije[i].x << " " << pozicije[i].y << " " << pozicije[i].z << "}" << endl;
	}
	cout << endl;

	for (int j = 0; j < ret.numVertices; j++) 
	{
		Vertex& v = ret.vertices[j];
		v.position = pozicije[j];
		v.color = glm::vec3(0, 1, 0);
	}

	for (int k = 0; k < ret.numVertices; k++)
	{
		std::cout << "{" << ret.vertices[k].position.x << " " << ret.vertices[k].position.y << " " << ret.vertices[k].position.z << "}" << endl;
	}

	cout << "BOJE: " << endl;
	for (int k = 0; k < ret.numVertices*2; k++)
	{
		std::cout << "{" << ret.vertices[k].color.x << " " << ret.vertices[k].color.y << " " << ret.vertices[k].color.z << "}" << endl;
	}

	ret.numIndices = model.indices.size();
	ret.indices = new GLushort[ret.numIndices];
	std::copy(model.indices.begin(), model.indices.end(), ret.indices);
	return ret;
}*/

// RADI !!!!!!!!!!
ShapeData ShapeGenerator::makeBlenderCube(const std::string& fileName)
{
	ShapeData ret;
	IndexedModel model = OBJModel(fileName).ToIndexedModel();

	ret.numVertices = model.positions.size();
	glm::vec3* Pozicije = new glm::vec3[ret.numVertices];
	ret.vertices = new Vertex[ret.numVertices];
	std::copy(model.positions.begin(), model.positions.end(), Pozicije);

	for (int i = 0; i < ret.numVertices; i++) {
		//std::cout << "{" << Pozicije[i].x << " " << Pozicije[i].y << " " << Pozicije[i].z << "}" << endl;
		cout << i << endl;

		Vertex& v = ret.vertices[i];
		v.position.x = Pozicije[i].x;
		v.position.y = Pozicije[i].y;
		v.position.z = Pozicije[i].z;

		if (i >= 0  && i <= 5)
		{
			v.color = glm::vec3(1, 0, 1);
		}
		else if (i >= 6 && i <= 11 )
		{
			v.color = glm::vec3(0, 1, 1);
		}
		else if (i >= 12 && i <= 17)
		{
			v.color = glm::vec3(0, 1, 0);
		}
		else if (i >= 18 && i <= 23)
		{
			v.color = glm::vec3(1, 0, 0);
		}
		else if (i >= 24 && i <= 29)
		{
			v.color = glm::vec3(0, 0, 0.5);
		}
		else
		{
			v.color = glm::vec3(1, 1, 0);
		}
	}

	//cout << endl;

	/*for (int j = 0; j < ret.numVertices; j++) {
		std::cout << "{" << ret.vertices[j].position.x << " " << ret.vertices[j].position.y << " " << ret.vertices[j].position.z << "}" << endl;
	}*/


	ret.numIndices = model.indices.size();
	ret.indices = new GLushort[ret.numIndices];
	std::copy(model.indices.begin(), model.indices.end(), ret.indices);
	return ret;
}


ShapeData ShapeGenerator::makeBlenderPlane(const std::string& fileName)
{
	ShapeData ret;
	IndexedModel model = OBJModel(fileName).ToIndexedModel();

	ret.numVertices = model.positions.size();
	glm::vec3* Pozicije = new glm::vec3[ret.numVertices];
	ret.vertices = new Vertex[ret.numVertices];
	std::copy(model.positions.begin(), model.positions.end(), Pozicije);

	for (int i = 0; i < ret.numVertices; i++) {
		cout << i << endl;

		Vertex& v = ret.vertices[i];
		v.position.x = Pozicije[i].x;
		v.position.y = Pozicije[i].y;
		v.position.z = Pozicije[i].z;

		v.color = glm::vec3(0, 1, 0);
	}

	ret.numIndices = model.indices.size();
	ret.indices = new GLushort[ret.numIndices];
	std::copy(model.indices.begin(), model.indices.end(), ret.indices);
	return ret;
}


ShapeData ShapeGenerator::makeBlenderSphere(const std::string& fileName)
{
	ShapeData ret;
	IndexedModel model = OBJModel(fileName).ToIndexedModel();

	ret.numVertices = model.positions.size();
	glm::vec3* Pozicije = new glm::vec3[ret.numVertices];
	ret.vertices = new Vertex[ret.numVertices];
	std::copy(model.positions.begin(), model.positions.end(), Pozicije);

	for (int i = 0; i < ret.numVertices; i++) {
		//cout << i << endl;

		Vertex& v = ret.vertices[i];
		v.position.x = Pozicije[i].x;
		v.position.y = Pozicije[i].y;
		v.position.z = Pozicije[i].z;

		if (i % 2 == 0)
			v.color = glm::vec3(0, 0, 1);
		else
			v.color = glm::vec3(0, 1, 0);
	}

	ret.numIndices = model.indices.size();
	ret.indices = new GLushort[ret.numIndices];
	std::copy(model.indices.begin(), model.indices.end(), ret.indices);
	return ret;
}


ShapeData ShapeGenerator::makeBlenderCone(const std::string& fileName)
{
	ShapeData ret;
	IndexedModel model = OBJModel(fileName).ToIndexedModel();

	ret.numVertices = model.positions.size();
	glm::vec3* Pozicije = new glm::vec3[ret.numVertices];
	ret.vertices = new Vertex[ret.numVertices];
	std::copy(model.positions.begin(), model.positions.end(), Pozicije);

	int a1 = 0;
	int a2 = 0;

	for (int i = 0; i < ret.numVertices; i++) {
		cout << i << endl;

		Vertex& v = ret.vertices[i];
		v.position.x = Pozicije[i].x;
		v.position.y = Pozicije[i].y;
		v.position.z = Pozicije[i].z;

		if (i < 95)
		{
			if (a1 < 3 && a2 < 3)
			{
				v.color = glm::vec3(0, 0, 1);
				a1++;
				a2++;
			}
			else if ((a1>=3 && a1<6) && (a2>=3 && a2<=6))
			{
				v.color = glm::vec3(1, 1, 0);
				a1++;
				a2++;
			}
			else
			{
				v.color = glm::vec3(0, 0, 1);
				a1 = 1;
				a2 = 1;
			}
		}
		else
			v.color = glm::vec3(0, 0, 1);
	}

	ret.numIndices = model.indices.size();
	ret.indices = new GLushort[ret.numIndices];
	std::copy(model.indices.begin(), model.indices.end(), ret.indices);
	return ret;
}


ShapeData ShapeGenerator::makeBlenderCylinder(const std::string& fileName)
{
	ShapeData ret;
	IndexedModel model = OBJModel(fileName).ToIndexedModel();

	ret.numVertices = model.positions.size();
	glm::vec3* Pozicije = new glm::vec3[ret.numVertices];
	ret.vertices = new Vertex[ret.numVertices];
	std::copy(model.positions.begin(), model.positions.end(), Pozicije);

	int a1 = 0;
	int a2 = 0;

	for (int i = 0; i < ret.numVertices; i++) {
		cout << i << endl;

		Vertex& v = ret.vertices[i];
		v.position.x = Pozicije[i].x;
		v.position.y = Pozicije[i].y;
		v.position.z = Pozicije[i].z;

		if (i < 190)
			if (a1 < 3 && a2 < 3)
			{
				v.color = glm::vec3(1, 0, 0);
				a1++;
				a2++;
			}
			else if ((a1 >= 3 && a1<6) && (a2 >= 3 && a2 <= 6))
			{
				v.color = glm::vec3(1, 1, 0);
				a1++;
				a2++;
			}
			else
			{
				v.color = glm::vec3(1, 0, 0);
				a1 = 1;
				a2 = 1;
			}
		else
			v.color = glm::vec3(1, 1, 0);
	}

	ret.numIndices = model.indices.size();
	ret.indices = new GLushort[ret.numIndices];
	std::copy(model.indices.begin(), model.indices.end(), ret.indices);
	return ret;
}


ShapeData ShapeGenerator::makeBlenderAxis(const std::string& fileName)
{
	ShapeData ret;
	IndexedModel model = OBJModel(fileName).ToIndexedModel();

	ret.numVertices = model.positions.size();
	glm::vec3* Pozicije = new glm::vec3[ret.numVertices];
	ret.vertices = new Vertex[ret.numVertices];
	std::copy(model.positions.begin(), model.positions.end(), Pozicije);

	for (int i = 0; i < ret.numVertices; i++) {
		//cout << i << endl;

		Vertex& v = ret.vertices[i];
		v.position.x = Pozicije[i].x;
		v.position.y = Pozicije[i].y;
		v.position.z = Pozicije[i].z;

		v.color = glm::vec3(1, 0, 0);
	}

	ret.numIndices = model.indices.size();
	ret.indices = new GLushort[ret.numIndices];
	std::copy(model.indices.begin(), model.indices.end(), ret.indices);
	return ret;
}