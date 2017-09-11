#include <Qt\qapplication.h>
#include <GLwindow.h>
#include <iostream>
#include "ShapeData.h"
#include "ShapeGenerator.h"
using namespace std;

int main(int argc, char* argv[])
{
	//ShapeData kocka = ShapeGenerator::makeBlenderCube("kocka.obj");
	//cout << "numVertices: " << kocka.numVertices << endl;


	QApplication app(argc, argv);
	GLwindow meWindow;
	meWindow.show();
	return app.exec();
}