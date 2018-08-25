#include <gl\glew.h>
#include <iostream>
#include <fstream>
#include <QtGui\qmouseevent>
#include <QtGui\qkeyevent>
#include <GLwindow.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtx\transform.hpp>
#include <Vertex.h>
#include <ShapeGenerator.h>
#include <Camera.h>
#include <MyModel.h>
#include "vector"
using namespace std;
using glm::vec3;
using glm::mat4;

const uint NUM_VERTICES_PER_TRI = 3;
const uint NUM_FLOATS_PER_VERTICE = 6;
const uint VERTEX_BYTE_SIZE = NUM_FLOATS_PER_VERTICE * sizeof(float);
GLuint programID;

GLuint cubeNumIndices;
GLuint arrowNumIndices;
GLuint planeNumIndices;
GLuint sphereNumIndices;
GLuint coneNumIndices;
GLuint axisNumIndices;

Camera camera;
GLuint fullTransformationUniformLocation;

GLuint theBufferID;

GLuint cubeVertexArrayObjectID;
GLuint arrowVertexArrayObjectID;
GLuint planeVertexArrayObjectID;
GLuint sphereVertexArrayObjectID;
GLuint coneVertexArrayObjectID;
GLuint axisVertexArrayObjectID;

GLuint cubeIndexByteOffset;
GLuint arrowIndexByteOffset;
GLuint planeIndexByteOffset;
GLuint sphereIndexByteOffset;
GLuint coneIndexByteOffset;
GLuint axisIndexByteOffset;

GLwindow::GLwindow(MyModel* theModel) : theModel(theModel)
{
}

void GLwindow::sendDataToOpenGL()
{
	//ShapeData cube = ShapeGenerator::makeCube();
	ShapeData cube = ShapeGenerator::makeBlenderCylinder("valjak6.obj");
	ShapeData arrow = ShapeGenerator::makeBlenderCube("kocka_bez_trokuta.obj");
	//ShapeData arrow = ShapeGenerator::makeBlenderCone("stozac2.obj");
	ShapeData plane = ShapeGenerator::makeBlenderPlane("ravnina.obj");
	ShapeData sphere = ShapeGenerator::makeBlenderSphere("kugla_bez_trokuta.obj");
	ShapeData cone = ShapeGenerator::makeBlenderCone("stozac2.obj");
	ShapeData axis = ShapeGenerator::makeBlenderAxis("valjak6.obj");
	//ShapeData arrow = ShapeGenerator::makeArrow();

	glGenBuffers(1, &theBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, theBufferID);
	/*glBufferData(GL_ARRAY_BUFFER,
		cube.vertexBufferSize() + cube.indexBufferSize() +
		arrow.positionsBufferSize() + arrow.indexBufferSize(), 0, GL_STATIC_DRAW);*/
	glBufferData(GL_ARRAY_BUFFER,
		cube.vertexBufferSize() + cube.indexBufferSize() +
		arrow.vertexBufferSize() + arrow.indexBufferSize() +
		plane.vertexBufferSize() + plane.indexBufferSize() +
		sphere.vertexBufferSize() + sphere.indexBufferSize() +
		cone.vertexBufferSize() + cone.indexBufferSize() +
		axis.vertexBufferSize() + axis.indexBufferSize(), 0, GL_STATIC_DRAW);
	GLsizeiptr currentOffset = 0;
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset, cube.vertexBufferSize(), cube.vertices);
	currentOffset += cube.vertexBufferSize();
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset, cube.indexBufferSize(), cube.indices);
	currentOffset += cube.indexBufferSize();
	/*glBufferSubData(GL_ARRAY_BUFFER, currentOffset, arrow.positionsBufferSize(), arrow.positions);
	currentOffset += arrow.positionsBufferSize();*/
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset, arrow.vertexBufferSize(), arrow.vertices);
	currentOffset += arrow.vertexBufferSize();
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset, arrow.indexBufferSize(), arrow.indices);


	currentOffset += arrow.indexBufferSize();
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset, plane.vertexBufferSize(), plane.vertices);
	currentOffset += plane.vertexBufferSize();
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset, plane.indexBufferSize(), plane.indices);

	currentOffset += plane.indexBufferSize();
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset, sphere.vertexBufferSize(), sphere.vertices);
	currentOffset += sphere.vertexBufferSize();
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset, sphere.indexBufferSize(), sphere.indices);

	currentOffset += sphere.indexBufferSize();
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset, cone.vertexBufferSize(), cone.vertices);
	currentOffset += cone.vertexBufferSize();
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset, cone.indexBufferSize(), cone.indices);

	currentOffset += cone.indexBufferSize();
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset, axis.vertexBufferSize(), axis.vertices);
	currentOffset += axis.vertexBufferSize();
	glBufferSubData(GL_ARRAY_BUFFER, currentOffset, axis.indexBufferSize(), axis.indices);

	cubeNumIndices = cube.numIndices;
	arrowNumIndices = arrow.numIndices;
	planeNumIndices = plane.numIndices;
	sphereNumIndices = sphere.numIndices;
	coneNumIndices = cone.numIndices;
	axisNumIndices = axis.numIndices;

	glGenVertexArrays(1, &cubeVertexArrayObjectID);
	glGenVertexArrays(1, &arrowVertexArrayObjectID);
	glGenVertexArrays(1, &planeVertexArrayObjectID);
	glGenVertexArrays(1, &sphereVertexArrayObjectID);
	glGenVertexArrays(1, &coneVertexArrayObjectID);
	glGenVertexArrays(1, &axisVertexArrayObjectID);

	glBindVertexArray(cubeVertexArrayObjectID);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, theBufferID);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(sizeof(float) * 3));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, theBufferID);

	glBindVertexArray(arrowVertexArrayObjectID);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, theBufferID);
	GLuint arrowByteOffset = cube.vertexBufferSize() + cube.indexBufferSize();
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)arrowByteOffset);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(arrowByteOffset + sizeof(float) * 3));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, theBufferID);

	glBindVertexArray(planeVertexArrayObjectID);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, theBufferID);
	GLuint planeByteOffset = arrowByteOffset + arrow.vertexBufferSize() + arrow.indexBufferSize();
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)planeByteOffset);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(planeByteOffset + sizeof(float) * 3));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, theBufferID);

	glBindVertexArray(sphereVertexArrayObjectID);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, theBufferID);
	GLuint sphereByteOffset = planeByteOffset + plane.vertexBufferSize() + plane.indexBufferSize();
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)sphereByteOffset);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(sphereByteOffset + sizeof(float) * 3));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, theBufferID);

	glBindVertexArray(coneVertexArrayObjectID);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, theBufferID);
	GLuint coneByteOffset = sphereByteOffset + sphere.vertexBufferSize() + sphere.indexBufferSize();
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)coneByteOffset);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(coneByteOffset + sizeof(float) * 3));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, theBufferID);

	glBindVertexArray(axisVertexArrayObjectID);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, theBufferID);
	GLuint axisByteOffset = coneByteOffset + cone.vertexBufferSize() + cone.indexBufferSize();
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)axisByteOffset);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(axisByteOffset + sizeof(float) * 3));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, theBufferID);

	// ISPRAVNO
	/*glBindVertexArray(arrowVertexArrayObjectID);
	glEnableVertexAttribArray(0);
	//glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, theBufferID);
	GLuint arrowByteOffset = cube.vertexBufferSize() + cube.indexBufferSize();
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)arrowByteOffset);
	//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(arrowByteOffset + sizeof(float) * 3));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, theBufferID);*/

	cubeIndexByteOffset = cube.vertexBufferSize();
	//arrowIndexByteOffset = arrowByteOffset + arrow.positionsBufferSize();
	arrowIndexByteOffset = arrowByteOffset + arrow.vertexBufferSize();
	planeIndexByteOffset = planeByteOffset + plane.vertexBufferSize();
	sphereIndexByteOffset = sphereByteOffset + sphere.vertexBufferSize();
	coneIndexByteOffset = coneByteOffset + cone.vertexBufferSize();
	axisIndexByteOffset = axisByteOffset + axis.vertexBufferSize();

	cube.cleanup();
	arrow.cleanup();
	plane.cleanup();
	sphere.cleanup();
	cone.cleanup();
	axis.cleanup();
}

void GLwindow::paintGL()
{
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, width(), height());

	mat4 fullTransformMatrix;
	mat4 viewToProjectionMatrix = glm::perspective(60.0f, ((float)width()) / height(), 0.1f, 40.0f);
	mat4 worldToViewMatrix = camera.getWorldToViewMatrix();
	mat4 worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	// Cube
	float a = 1.0;
	GLuint valjakNumIndices = 0;

	if (theModel->checkVisibilityCylinder == false)
	{
		valjakNumIndices = 0;
	}
	else if (theModel->checkVisibilityCylinder == true)
	{
		valjakNumIndices = cubeNumIndices;
	}

	glBindVertexArray(cubeVertexArrayObjectID);
	mat4 cube1ModelToWorldMatrix =
		glm::translate(vec3(theModel->lightPosition)) *
		//glm::translate(vec3(-3.0f, 0.0f, -3.0f)) *
		glm::rotate(theModel->degreesCylinder, vec3(theModel->axisCylinder)) *
		//glm::rotate(0.0f, vec3(1.0f, 0.0f, 0.0f)) *
		glm::scale(vec3(theModel->scaling));
		//glm::scale(vec3(a, 1.0f, 1.0f));
	fullTransformMatrix = worldToProjectionMatrix * cube1ModelToWorldMatrix;
	glUniformMatrix4fv(fullTransformationUniformLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, valjakNumIndices, GL_UNSIGNED_SHORT, (void*)cubeIndexByteOffset);

	/*mat4 cube2ModelToWorldMatrix =
		glm::translate(vec3(4.0f, 0.0f, -3.75f)) *
		glm::rotate(126.0f, vec3(0.0f, 1.0f, 0.0f));
	fullTransformMatrix = worldToProjectionMatrix * cube2ModelToWorldMatrix;
	glUniformMatrix4fv(fullTransformationUniformLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, cubeNumIndices, GL_UNSIGNED_SHORT, (void*)cubeIndexByteOffset);*/

	// Arrow
	GLuint kockaNumIndices = 0;

	if (theModel->checkVisibilityCube == false)
	{
		kockaNumIndices = 0;
	}
	else if (theModel->checkVisibilityCube == true)
	{
		kockaNumIndices = arrowNumIndices;
	}

	glBindVertexArray(arrowVertexArrayObjectID);
	mat4 arrowModelToWorldMatrix =
		glm::translate(theModel->cubePosition) *
		glm::rotate(theModel->degreesCube, theModel->axisCube) *
		glm::scale(theModel->scaleCube);
		//glm::scale(vec3(theModel->scaleCube));
	//mat4 arrowModelToWorldMatrix = glm::translate(0.0f, 0.0f, -3.0f);
	fullTransformMatrix = worldToProjectionMatrix * arrowModelToWorldMatrix;
	glUniformMatrix4fv(fullTransformationUniformLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, kockaNumIndices, GL_UNSIGNED_SHORT, (void*)arrowIndexByteOffset);

	// Plane
	GLuint ravninaNumIndices = 0;

	if (theModel->checkVisibilityPlane == false)
	{
		ravninaNumIndices = 0;
	}
	else if (theModel->checkVisibilityPlane == true)
	{
		ravninaNumIndices = planeNumIndices;
	}

	glBindVertexArray(planeVertexArrayObjectID);
	mat4 planeModelToWorldMatrix = 
		glm::translate(theModel->planePosition) *
		glm::rotate(theModel->degreesPlane, theModel->axisPlane) *
		glm::scale(theModel->scalePlane);
	//mat4 planeModelToWorldMatrix = glm::translate(0.0f, 2.0f, -3.0f);
	fullTransformMatrix = worldToProjectionMatrix * planeModelToWorldMatrix;
	glUniformMatrix4fv(fullTransformationUniformLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, ravninaNumIndices, GL_UNSIGNED_SHORT, (void*)planeIndexByteOffset);

	// Sphere
	GLuint kuglaNumIndices = 0;

	if (theModel->checkVisibilitySphere == false)
	{
		kuglaNumIndices = 0;
	}
	else if (theModel->checkVisibilitySphere == true)
	{
		kuglaNumIndices = sphereNumIndices;
	}

	glBindVertexArray(sphereVertexArrayObjectID);
	mat4 sphereModelToWorldMatrix = 
		glm::translate(theModel->spherePosition) *
		glm::rotate(theModel->degreesSphere, theModel->axisSphere) *
		glm::scale(theModel->scaleSphere);
	//mat4 sphereModelToWorldMatrix = glm::translate(0.0f, -2.0f, -5.0f);
	fullTransformMatrix = worldToProjectionMatrix * sphereModelToWorldMatrix;
	glUniformMatrix4fv(fullTransformationUniformLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, kuglaNumIndices, GL_UNSIGNED_SHORT, (void*)sphereIndexByteOffset);

	// Cone
	GLuint stozacNumIndices = 0;

	if (theModel->checkVisibilityCone == false)
	{
		stozacNumIndices = 0;
	}
	else if (theModel->checkVisibilityCone == true)
	{
		stozacNumIndices = coneNumIndices;
	}

	glBindVertexArray(coneVertexArrayObjectID);
	mat4 coneModelToWorldMatrix = 
		glm::translate(theModel->conePosition) *
		glm::rotate(theModel->degreesCone, theModel->axisCone) *
		glm::scale(theModel->scaleCone);
	//mat4 coneModelToWorldMatrix = glm::translate(4.0f, 0.0f, -3.75f);
	fullTransformMatrix = worldToProjectionMatrix * coneModelToWorldMatrix;
	glUniformMatrix4fv(fullTransformationUniformLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, stozacNumIndices, GL_UNSIGNED_SHORT, (void*)coneIndexByteOffset);

	// Axis
	glBindVertexArray(axisVertexArrayObjectID);

	mat4 axisxModelToWorldMatrix =
		glm::translate(vec3(0.0f, 0.0f, 0.0f)) *
		glm::rotate(90.0f, vec3(0.0f, 0.0f, 1.0f)) *
		glm::scale(vec3(0.01f, 20.0f, 0.01f));
	fullTransformMatrix = worldToProjectionMatrix * axisxModelToWorldMatrix;
	glUniformMatrix4fv(fullTransformationUniformLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, axisNumIndices, GL_UNSIGNED_SHORT, (void*)axisIndexByteOffset);

	mat4 axisyModelToWorldMatrix =
		glm::translate(vec3(0.0f, 0.0f, 0.0f)) *
		glm::rotate(90.0f, vec3(1.0f, 0.0f, 0.0f)) *
		glm::scale(vec3(0.01f, 20.0f, 0.01f));
	fullTransformMatrix = worldToProjectionMatrix * axisyModelToWorldMatrix;
	glUniformMatrix4fv(fullTransformationUniformLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, axisNumIndices, GL_UNSIGNED_SHORT, (void*)axisIndexByteOffset);

	mat4 axiszModelToWorldMatrix =
		glm::translate(vec3(0.0f, 0.0f, 0.0f)) *
		glm::rotate(0.0f, vec3(1.0f, 0.0f, 0.0f)) *
		glm::scale(vec3(0.01f, 20.0f, 0.01f));
	fullTransformMatrix = worldToProjectionMatrix * axiszModelToWorldMatrix;
	glUniformMatrix4fv(fullTransformationUniformLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, axisNumIndices, GL_UNSIGNED_SHORT, (void*)axisIndexByteOffset);
}

void GLwindow::mouseMoveEvent(QMouseEvent* e)
{
	setFocus();
	camera.mouseUpdate(glm::vec2(e->x(), e->y()));
	repaint();
}

void GLwindow::keyPressEvent(QKeyEvent* e)
{
	switch (e->key())
	{
	case Qt::Key::Key_W:
		camera.moveForward();
		break;
	case Qt::Key::Key_S:
		camera.moveBackward();
		break;
	case Qt::Key::Key_A:
		camera.strafeLeft();
		break;
	case Qt::Key::Key_D:
		camera.strafeRight();
		break;
	case Qt::Key::Key_R:
		camera.moveUp();
		break;
	case Qt::Key::Key_F:
		camera.moveDown();
		break;
	}
	repaint();
}

bool GLwindow::checkStatus(
	GLuint objectID,
	PFNGLGETSHADERIVPROC objectPropertyGetterFunc,
	PFNGLGETSHADERINFOLOGPROC getInfoLogFunc,
	GLenum statusType)
{
	GLint status;
	objectPropertyGetterFunc(objectID, statusType, &status);
	if (status != GL_TRUE)
	{
		GLint infoLogLength;
		objectPropertyGetterFunc(objectID, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* buffer = new GLchar[infoLogLength];

		GLsizei bufferSize;
		getInfoLogFunc(objectID, infoLogLength, &bufferSize, buffer);
		cout << buffer << endl;
		delete[] buffer;
		return false;
	}
	return true;
}

bool GLwindow::checkShaderStatus(GLuint shaderID)
{
	return checkStatus(shaderID, glGetShaderiv, glGetShaderInfoLog, GL_COMPILE_STATUS);
}

bool GLwindow::checkProgramStatus(GLuint programID)
{
	return checkStatus(programID, glGetProgramiv, glGetProgramInfoLog, GL_LINK_STATUS);
}

string GLwindow::readShaderCode(const char* fileName)
{
	ifstream meInput(fileName);
	if (!meInput.good())
	{
		cout << "File failed to load..." << fileName;
		exit(1);
	}
	return std::string(
		std::istreambuf_iterator<char>(meInput),
		std::istreambuf_iterator<char>());
}

void GLwindow::installShaders()
{
	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	const GLchar* adapter[1];
	string temp = readShaderCode("VertexShaderCode.glsl");
	adapter[0] = temp.c_str();
	glShaderSource(vertexShaderID, 1, adapter, 0);
	temp = readShaderCode("FragmentShaderCode.glsl");
	adapter[0] = temp.c_str();
	glShaderSource(fragmentShaderID, 1, adapter, 0);

	glCompileShader(vertexShaderID);
	glCompileShader(fragmentShaderID);

	if (!checkShaderStatus(vertexShaderID) || !checkShaderStatus(fragmentShaderID))
		return;

	programID = glCreateProgram();
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);

	glLinkProgram(programID);

	if (!checkProgramStatus(programID))
		return;

	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);

	glUseProgram(programID);
}

void GLwindow::initializeGL()
{
	setMinimumSize(1200, 600);
	setMouseTracking(false);
	glewInit();
	glEnable(GL_DEPTH_TEST);
	sendDataToOpenGL();
	installShaders();
	fullTransformationUniformLocation = glGetUniformLocation(programID, "fullTransformMatrix");
}

GLwindow::~GLwindow()
{
	glDeleteBuffers(1, &theBufferID);
	glUseProgram(0);
	glDeleteProgram(programID);
}
