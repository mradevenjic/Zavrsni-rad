#ifndef GL_WINDOW
#define GL_WINDOW
#include <gl\glew.h>
#include <QtOpenGL\qglwidget>
#include <string>

class GLwindow : public QGLWidget
{
	void sendDataToOpenGL();
	bool checkShaderStatus(GLuint shaderID);
	bool checkProgramStatus(GLuint programID);
	bool checkStatus(
		GLuint objectID,
		PFNGLGETSHADERIVPROC objectPropertyGetterFunc,
		PFNGLGETSHADERINFOLOGPROC getInfoLogFunc,
		GLenum statusType);
	std::string readShaderCode(const char* fileName);
	void installShaders();
protected:
	void initializeGL();
	void paintGL();
	void mouseMoveEvent(QMouseEvent*);
	void keyPressEvent(QKeyEvent*);
public:
	~GLwindow();
};

#endif
