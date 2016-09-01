#include <Qt\qapplication.h>
#include <GLwindow.h>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	GLwindow meWindow;
	meWindow.show();
	return app.exec();
}