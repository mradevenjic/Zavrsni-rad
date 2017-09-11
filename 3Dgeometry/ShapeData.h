#pragma once
#include <GL\glew.h>
#include <Vertex.h>
#include <glm\glm.hpp>
#include "vector"
#include <GL\glew.h>
#include <Vertex.h>

struct ShapeData
{
	ShapeData() :
		vertices(0), numVertices(0),
		indices(0), numIndices(0) {}
	Vertex* vertices;
	//glm::vec3* positions;
	GLuint numVertices;
	GLushort* indices;
	GLuint numIndices;
	GLsizeiptr vertexBufferSize() const
	{
		return numVertices * sizeof(Vertex);
	}
	/*GLsizeiptr positionsBufferSize() const
	{
		//return numVertices * sizeof(std::vector<glm::vec3>);
		return numVertices * sizeof(glm::vec3);
	}*/
	GLsizeiptr indexBufferSize() const
	{
		return numIndices * sizeof(GLushort);
	}
	void cleanup()
	{
		delete[] vertices;
		delete[] indices;
		numVertices = numIndices = 0;
	}
};
