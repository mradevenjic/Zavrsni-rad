#include <Qt\qapplication.h>
#include <GLwindow.h>
#include <MyWidget.h>

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	MyWidget widg;
	widg.show();
	return app.exec();

	/*QApplication app(argc, argv);
	GLwindow meWindow;
	meWindow.show();
	return app.exec();*/
}