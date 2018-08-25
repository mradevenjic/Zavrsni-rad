#pragma once
#include <QtGui\qwidget.h>
#include <QtGui\qcheckbox.h>
#include <QtGui\qprogressbar.h>
#include <QtGui\qlabel.h>
#include <QtGui\qradiobutton.h>
#include <QtGui\qgroupbox.h>
#include <MyModel.h>
class DebugSlider;
class GLwindow;

class MyWidget : public QWidget
{
	Q_OBJECT

	DebugSlider* lightXSlider;
	DebugSlider* lightYSlider;
	DebugSlider* lightZSlider;

	DebugSlider* degreeSlider;
	//DebugSlider* rotationYSlider;
	//DebugSlider* rotationZSlider;

	DebugSlider* scalingXSlider;
	DebugSlider* scalingYSlider;
	DebugSlider* scalingZSlider;

	QRadioButton *manageCylinder;
	QRadioButton *manageCube;
	QRadioButton *managePlane;
	QRadioButton *manageSphere;
	QRadioButton *manageCone;

	QRadioButton *axisX;
	QRadioButton *axisY;
	QRadioButton *axisZ;

	/*QRadioButton *rb1;
	QRadioButton *rb2;
	QRadioButton *rb3;*/

	QCheckBox *visibilityCylinder;
	QCheckBox *visibilityCube;
	QCheckBox *visibilityPlane;
	QCheckBox *visibilitySphere;
	QCheckBox *visibilityCone;

	QProgressBar *progressBar;

	QLabel* translateText;
	QLabel* rotationText;
	QLabel* scalingText;

	QGroupBox *groupBox;

	GLwindow* glWindow;

	MyModel theModel;

	private slots:
		void sliderValueChanged();
		void clickedCheckBox();
		void setProgressValue();
		void positionXChanged();
		void positionYChanged();
		void positionZChanged();
		void degreeValueChanged();
		void scaleValueXChanged();
		void scaleValueYChanged();
		void scaleValueZChanged();

public:
	MyWidget();
};

