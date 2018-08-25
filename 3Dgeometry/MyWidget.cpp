#include "MyWidget.h"
#include <Qt\qdebug.h>
#include <QtGui\qvboxlayout>
#include <QtGui\qhboxlayout>
#include <QtGui\qcheckbox.h>
#include <QtGui\qprogressbar.h>
#include <QtGui\qlabel.h>
#include <QtGui\qradiobutton.h>
#include <QtGui\qgroupbox.h>
#include <QtGui\qbuttongroup.h>
#include <GLwindow.h>
#include <DebugSlider.h>


MyWidget::MyWidget()
{
	QVBoxLayout* mainLayout;
	setLayout(mainLayout = new QVBoxLayout);

	QVBoxLayout* controlsLayout;
	mainLayout->addLayout(controlsLayout = new QVBoxLayout);
	mainLayout->addWidget(glWindow = new GLwindow(&theModel));

	QHBoxLayout* lightPositionLayout;
	controlsLayout->addLayout(lightPositionLayout = new QHBoxLayout);
	QHBoxLayout* rotationLayout;
	controlsLayout->addLayout(rotationLayout = new QHBoxLayout);
	QHBoxLayout* scalingLayout;
	controlsLayout->addLayout(scalingLayout = new QHBoxLayout);
	QHBoxLayout* manageLayout;
	controlsLayout->addLayout(manageLayout = new QHBoxLayout);
	QHBoxLayout *visibilityLayout;
	controlsLayout->addLayout(visibilityLayout = new QHBoxLayout);
	/*QHBoxLayout *testLayout;
	controlsLayout->addLayout(testLayout = new QHBoxLayout);*/


	lightPositionLayout->addWidget(translateText = new QLabel("Translate:"));
	lightPositionLayout->addWidget(lightXSlider = new DebugSlider);
	lightPositionLayout->addWidget(lightYSlider = new DebugSlider);
	lightPositionLayout->addWidget(lightZSlider = new DebugSlider);

	rotationLayout->addWidget(rotationText = new QLabel("Rotate:          "));
	rotationLayout->addWidget(axisX = new QRadioButton("X"));
	rotationLayout->addWidget(axisY = new QRadioButton("Y"));
	rotationLayout->addWidget(axisZ = new QRadioButton("Z"));
	rotationLayout->addWidget(degreeSlider = new DebugSlider(0, 0, 360, false, 360));
	QButtonGroup *rotateGroup = new QButtonGroup();
	rotateGroup->addButton(axisX);
	rotateGroup->addButton(axisY);
	rotateGroup->addButton(axisZ);
	axisX->setChecked(true);
	//rotationLayout->addWidget(rotationYSlider = new DebugSlider);
	//rotationLayout->addWidget(rotationZSlider = new DebugSlider);
	//QGroupBox *groupBox = new QGroupBox(tr("Exclusive radio buttons"), this);
	//groupBox->setLayout(rotationLayout);

	scalingLayout->addWidget(scalingText = new QLabel("Scale:      "));
	scalingLayout->addWidget(scalingXSlider = new DebugSlider(1, 0, 10, true, 400));
	scalingLayout->addWidget(scalingYSlider = new DebugSlider(1, 0, 10, true, 400));
	scalingLayout->addWidget(scalingZSlider = new DebugSlider(1, 0, 10, true, 400));

	manageLayout->addWidget(manageCylinder = new QRadioButton("Cylinder"));
	manageLayout->addWidget(manageCube = new QRadioButton("Cube"));
	manageLayout->addWidget(managePlane = new QRadioButton("Plane"));
	manageLayout->addWidget(manageSphere = new QRadioButton("Sphere"));
	manageLayout->addWidget(manageCone = new QRadioButton("Cone"));
	manageCylinder->setChecked(true);

	visibilityLayout->addWidget(visibilityCylinder = new QCheckBox("Cylinder"));
	visibilityLayout->addWidget(visibilityCube = new QCheckBox("Cube"));
	visibilityLayout->addWidget(visibilityPlane = new QCheckBox("Plane"));
	visibilityLayout->addWidget(visibilitySphere = new QCheckBox("Sphere"));
	visibilityLayout->addWidget(visibilityCone = new QCheckBox("Cone"));
	/*visibilityLayout->addWidget(progressBar = new QProgressBar);
	progressBar->setValue(40);*/

	//QGroupBox *groupBox = new QGroupBox(tr("Exclusive radio buttons"), this);
	//testLayout->addWidget(groupBox = new QGroupBox("bla bla bla"));
	/*testLayout->addWidget(rb1 = new QRadioButton("1"));
	testLayout->addWidget(rb2 = new QRadioButton("2"));
	testLayout->addWidget(rb3 = new QRadioButton("3"));
	//groupBox->setLayout(testLayout);
	QButtonGroup *grupaBotuna = new QButtonGroup();
	grupaBotuna->addButton(rb1);
	grupaBotuna->addButton(rb2);
	grupaBotuna->addButton(rb3);
	rb1->setChecked(true);*/

	theModel.axisCylinder.x = 1;
	theModel.axisCube.x = 1;
	theModel.axisPlane.x = 1;
	theModel.axisSphere.x = 1;
	theModel.axisCone.x = 1;
	theModel.degreesCylinder = degreeSlider->value();
	theModel.degreesCube = degreeSlider->value();
	theModel.degreesPlane = degreeSlider->value();
	theModel.degreesSphere = degreeSlider->value();
	theModel.degreesCone = degreeSlider->value();

	theModel.scaling.x = scalingXSlider->value();
	theModel.scaling.y = scalingYSlider->value();
	theModel.scaling.z = scalingZSlider->value();

	theModel.scaleCube.x = scalingXSlider->value();
	theModel.scaleCube.y = scalingXSlider->value();
	theModel.scaleCube.z = scalingXSlider->value();

	theModel.scalePlane.x = scalingXSlider->value();
	theModel.scalePlane.y = scalingXSlider->value();
	theModel.scalePlane.z = scalingXSlider->value();

	theModel.scaleSphere.x = scalingXSlider->value();
	theModel.scaleSphere.y = scalingXSlider->value();
	theModel.scaleSphere.z = scalingXSlider->value();

	theModel.scaleCone.x = scalingXSlider->value();
	theModel.scaleCone.y = scalingXSlider->value();
	theModel.scaleCone.z = scalingXSlider->value();


	connect(lightXSlider, SIGNAL(valueChanged(float)), this, SLOT(positionXChanged()));
	connect(lightYSlider, SIGNAL(valueChanged(float)), this, SLOT(positionYChanged()));
	connect(lightZSlider, SIGNAL(valueChanged(float)), this, SLOT(positionZChanged()));
	//connect(lightZSlider, SIGNAL(valueChanged(float)), progressBar, SLOT(setValue(int)));
	//connect(lightZSlider, SIGNAL(valueChanged(float)), this, SLOT(setProgressValue()));

	connect(degreeSlider, SIGNAL(valueChanged(float)), this, SLOT(degreeValueChanged()));
	//connect(rotationYSlider, SIGNAL(valueChanged(float)), this, SLOT(sliderValueChanged()));
	//connect(rotationZSlider, SIGNAL(valueChanged(float)), this, SLOT(sliderValueChanged()));

	connect(scalingXSlider, SIGNAL(valueChanged(float)), this, SLOT(scaleValueXChanged()));
	connect(scalingYSlider, SIGNAL(valueChanged(float)), this, SLOT(scaleValueYChanged()));
	connect(scalingZSlider, SIGNAL(valueChanged(float)), this, SLOT(scaleValueZChanged()));
	
	//visibilityCylinder->setChecked(false);
	//theModel.checkVisibilityCylinder = false;
	connect(visibilityCylinder, SIGNAL(clicked()), this, SLOT(clickedCheckBox()));
	connect(visibilityCube, SIGNAL(clicked()), this, SLOT(clickedCheckBox()));
	connect(visibilityPlane, SIGNAL(clicked()), this, SLOT(clickedCheckBox()));
	connect(visibilitySphere, SIGNAL(clicked()), this, SLOT(clickedCheckBox()));
	connect(visibilityCone, SIGNAL(clicked()), this, SLOT(clickedCheckBox()));
}

void MyWidget::positionXChanged()
{
	if (manageCylinder->isChecked())
	{
		theModel.lightPosition.x = lightXSlider->value();
	}
	if (manageCube->isChecked())
	{
		theModel.cubePosition.x = lightXSlider->value();
	}
	if (managePlane->isChecked())
	{
		theModel.planePosition.x = lightXSlider->value();
	}
	if (manageSphere->isChecked())
	{
		theModel.spherePosition.x = lightXSlider->value();
	}
	if (manageCone->isChecked())
	{
		theModel.conePosition.x = lightXSlider->value();
	}

	glWindow->repaint();

	qDebug() << "slider value changed";
}

void MyWidget::positionYChanged()
{
	if (manageCylinder->isChecked())
	{
		theModel.lightPosition.y = lightYSlider->value();
	}
	if (manageCube->isChecked())
	{
		theModel.cubePosition.y = lightYSlider->value();
	}
	if (managePlane->isChecked())
	{
		theModel.planePosition.y = lightYSlider->value();
	}
	if (manageSphere->isChecked())
	{
		theModel.spherePosition.y = lightYSlider->value();
	}
	if (manageCone->isChecked())
	{
		theModel.conePosition.y = lightYSlider->value();
	}

	glWindow->repaint();

	qDebug() << "slider value changed";
}

void MyWidget::positionZChanged()
{
	if (manageCylinder->isChecked())
	{
		theModel.lightPosition.z = lightZSlider->value();
	}
	if (manageCube->isChecked())
	{
		theModel.cubePosition.z = lightZSlider->value();
	}
	if (managePlane->isChecked())
	{
		theModel.planePosition.z = lightZSlider->value();
	}
	if (manageSphere->isChecked())
	{
		theModel.spherePosition.z = lightZSlider->value();
	}
	if (manageCone->isChecked())
	{
		theModel.conePosition.z = lightZSlider->value();
	}

	glWindow->repaint();

	qDebug() << "slider value changed";
}

void MyWidget::degreeValueChanged()
{
	if (manageCylinder->isChecked())
	{
		if (axisX->isChecked())
		{
			theModel.axisCylinder.x = 1;
			theModel.axisCylinder.y = 0;
			theModel.axisCylinder.z = 0;
			theModel.degreesCylinder = degreeSlider->value();
		}
		if (axisY->isChecked())
		{
			theModel.axisCylinder.x = 0;
			theModel.axisCylinder.y = 1;
			theModel.axisCylinder.z = 0;
			theModel.degreesCylinder = degreeSlider->value();
		}
		if (axisZ->isChecked())
		{
			theModel.axisCylinder.x = 0;
			theModel.axisCylinder.y = 0;
			theModel.axisCylinder.z = 1;
			theModel.degreesCylinder = degreeSlider->value();
		}
	}

	if (manageCube->isChecked())
	{
		if (axisX->isChecked())
		{
			theModel.axisCube.x = 1;
			theModel.axisCube.y = 0;
			theModel.axisCube.z = 0;
			theModel.degreesCube = degreeSlider->value();
		}
		if (axisY->isChecked())
		{
			theModel.axisCube.x = 0;
			theModel.axisCube.y = 1;
			theModel.axisCube.z = 0;
			theModel.degreesCube = degreeSlider->value();
		}
		if (axisZ->isChecked())
		{
			theModel.axisCube.x = 0;
			theModel.axisCube.y = 0;
			theModel.axisCube.z = 1;
			theModel.degreesCube = degreeSlider->value();
		}
	}

	if (managePlane->isChecked())
	{
		if (axisX->isChecked())
		{
			theModel.axisPlane.x = 1;
			theModel.axisPlane.y = 0;
			theModel.axisPlane.z = 0;
			theModel.degreesPlane = degreeSlider->value();
		}
		if (axisY->isChecked())
		{
			theModel.axisPlane.x = 0;
			theModel.axisPlane.y = 1;
			theModel.axisPlane.z = 0;
			theModel.degreesPlane = degreeSlider->value();
		}
		if (axisZ->isChecked())
		{
			theModel.axisPlane.x = 0;
			theModel.axisPlane.y = 0;
			theModel.axisPlane.z = 1;
			theModel.degreesPlane = degreeSlider->value();
		}
	}

	if (manageSphere->isChecked())
	{
		if (axisX->isChecked())
		{
			theModel.axisSphere.x = 1;
			theModel.axisSphere.y = 0;
			theModel.axisSphere.z = 0;
			theModel.degreesSphere = degreeSlider->value();
		}
		if (axisY->isChecked())
		{
			theModel.axisSphere.x = 0;
			theModel.axisSphere.y = 1;
			theModel.axisSphere.z = 0;
			theModel.degreesSphere = degreeSlider->value();
		}
		if (axisZ->isChecked())
		{
			theModel.axisSphere.x = 0;
			theModel.axisSphere.y = 0;
			theModel.axisSphere.z = 1;
			theModel.degreesSphere = degreeSlider->value();
		}
	}

	if (manageCone->isChecked())
	{
		if (axisX->isChecked())
		{
			theModel.axisCone.x = 1;
			theModel.axisCone.y = 0;
			theModel.axisCone.z = 0;
			theModel.degreesCone = degreeSlider->value();
		}
		if (axisY->isChecked())
		{
			theModel.axisCone.x = 0;
			theModel.axisCone.y = 1;
			theModel.axisCone.z = 0;
			theModel.degreesCone = degreeSlider->value();
		}
		if (axisZ->isChecked())
		{
			theModel.axisCone.x = 0;
			theModel.axisCone.y = 0;
			theModel.axisCone.z = 1;
			theModel.degreesCone = degreeSlider->value();
		}
	}

	glWindow->repaint();

	qDebug() << "slider value changed";
}

void MyWidget::scaleValueXChanged()
{
	if (manageCylinder->isChecked())
	{
		theModel.scaling.x = scalingXSlider->value();
	}
	if (manageCube->isChecked())
	{
		theModel.scaleCube.x = scalingXSlider->value();
	}
	if (managePlane->isChecked())
	{
		theModel.scalePlane.x = scalingXSlider->value();
	}
	if (manageSphere->isChecked())
	{
		theModel.scaleSphere.x = scalingXSlider->value();
	}
	if (manageCone->isChecked())
	{
		theModel.scaleCone.x = scalingXSlider->value();
	}

	glWindow->repaint();

	qDebug() << "slider value changed";
}

void MyWidget::scaleValueYChanged()
{
	if (manageCylinder->isChecked())
	{
		theModel.scaling.y = scalingYSlider->value();
	}
	if (manageCube->isChecked())
	{
		theModel.scaleCube.y = scalingYSlider->value();
	}
	if (managePlane->isChecked())
	{
		theModel.scalePlane.y = scalingYSlider->value();
	}
	if (manageSphere->isChecked())
	{
		theModel.scaleSphere.y = scalingYSlider->value();
	}
	if (manageCone->isChecked())
	{
		theModel.scaleCone.y = scalingYSlider->value();
	}

	glWindow->repaint();

	qDebug() << "slider value changed";
}

void MyWidget::scaleValueZChanged()
{
	if (manageCylinder->isChecked())
	{
		theModel.scaling.z = scalingZSlider->value();
	}
	if (manageCube->isChecked())
	{
		theModel.scaleCube.z = scalingZSlider->value();
	}
	if (managePlane->isChecked())
	{
		theModel.scalePlane.z = scalingZSlider->value();
	}
	if (manageSphere->isChecked())
	{
		theModel.scaleSphere.z = scalingZSlider->value();
	}
	if (manageCone->isChecked())
	{
		theModel.scaleCone.z = scalingZSlider->value();
	}

	glWindow->repaint();

	qDebug() << "slider value changed";
}

void MyWidget::sliderValueChanged()
{
	if (manageCylinder->isChecked())
	{ 
		theModel.lightPosition.x = lightXSlider->value();
		theModel.lightPosition.y = lightYSlider->value();
		theModel.lightPosition.z = lightZSlider->value();

		theModel.scaling.x = scalingXSlider->value();
		theModel.scaling.y = scalingYSlider->value();
		theModel.scaling.z = scalingZSlider->value();

		if (axisX->isChecked())
		{
			theModel.axisCylinder.x = 1;
			theModel.axisCylinder.y = 0;
			theModel.axisCylinder.z = 0;
			theModel.degreesCylinder = degreeSlider->value();
		}
		if (axisY->isChecked())
		{
			theModel.axisCylinder.x = 0;
			theModel.axisCylinder.y = 1;
			theModel.axisCylinder.z = 0;
			theModel.degreesCylinder = degreeSlider->value();
		}
		if (axisZ->isChecked())
		{
			theModel.axisCylinder.x = 0;
			theModel.axisCylinder.y = 0;
			theModel.axisCylinder.z = 1;
			theModel.degreesCylinder = degreeSlider->value();
		}
	}
	/*theModel.lightPosition.x = lightXSlider->value();
	theModel.lightPosition.y = lightYSlider->value();
	theModel.lightPosition.z = lightZSlider->value();*/
	if (manageCube->isChecked())
	{
		theModel.cubePosition.x = lightXSlider->value();
		theModel.cubePosition.y = lightYSlider->value();
		theModel.cubePosition.z = lightZSlider->value();

		theModel.scaleCube.x = scalingXSlider->value();
		theModel.scaleCube.y = scalingYSlider->value();
		theModel.scaleCube.z = scalingZSlider->value();

		if (axisX->isChecked())
		{
			theModel.axisCube.x = 1;
			theModel.axisCube.y = 0;
			theModel.axisCube.z = 0;
			theModel.degreesCube = degreeSlider->value();
		}
		if (axisY->isChecked())
		{
			theModel.axisCube.x = 0;
			theModel.axisCube.y = 1;
			theModel.axisCube.z = 0;
			theModel.degreesCube = degreeSlider->value();
		}
		if (axisZ->isChecked())
		{
			theModel.axisCube.x = 0;
			theModel.axisCube.y = 0;
			theModel.axisCube.z = 1;
			theModel.degreesCube = degreeSlider->value();
		}	
	}

	if (managePlane->isChecked())
	{
		theModel.planePosition.x = lightXSlider->value();
		theModel.planePosition.y = lightYSlider->value();
		theModel.planePosition.z = lightZSlider->value();

		theModel.scalePlane.x = scalingXSlider->value();
		theModel.scalePlane.y = scalingXSlider->value();
		theModel.scalePlane.z = scalingXSlider->value();

		if (axisX->isChecked())
		{
			theModel.axisPlane.x = 1;
			theModel.axisPlane.y = 0;
			theModel.axisPlane.z = 0;
			theModel.degreesPlane = degreeSlider->value();
		}
		if (axisY->isChecked())
		{
			theModel.axisPlane.x = 0;
			theModel.axisPlane.y = 1;
			theModel.axisPlane.z = 0;
			theModel.degreesPlane = degreeSlider->value();
		}
		if (axisZ->isChecked())
		{
			theModel.axisPlane.x = 0;
			theModel.axisPlane.y = 0;
			theModel.axisPlane.z = 1;
			theModel.degreesPlane = degreeSlider->value();
		}
	}

	if (manageSphere->isChecked())
	{
		theModel.spherePosition.x = lightXSlider->value();
		theModel.spherePosition.y = lightYSlider->value();
		theModel.spherePosition.z = lightZSlider->value();

		theModel.scaleSphere.x = scalingXSlider->value();
		theModel.scaleSphere.y = scalingXSlider->value();
		theModel.scaleSphere.z = scalingXSlider->value();

		if (axisX->isChecked())
		{
			theModel.axisSphere.x = 1;
			theModel.axisSphere.y = 0;
			theModel.axisSphere.z = 0;
			theModel.degreesSphere = degreeSlider->value();
		}
		if (axisY->isChecked())
		{
			theModel.axisSphere.x = 0;
			theModel.axisSphere.y = 1;
			theModel.axisSphere.z = 0;
			theModel.degreesSphere = degreeSlider->value();
		}
		if (axisZ->isChecked())
		{
			theModel.axisSphere.x = 0;
			theModel.axisSphere.y = 0;
			theModel.axisSphere.z = 1;
			theModel.degreesSphere = degreeSlider->value();
		}
	}

	if (manageCone->isChecked())
	{
		theModel.conePosition.x = lightXSlider->value();
		theModel.conePosition.y = lightYSlider->value();
		theModel.conePosition.z = lightZSlider->value();

		theModel.scaleCone.x = scalingXSlider->value();
		theModel.scaleCone.y = scalingXSlider->value();
		theModel.scaleCone.z = scalingXSlider->value();

		if (axisX->isChecked())
		{
			theModel.axisCone.x = 1;
			theModel.axisCone.y = 0;
			theModel.axisCone.z = 0;
			theModel.degreesCone = degreeSlider->value();
		}
		if (axisY->isChecked())
		{
			theModel.axisCone.x = 0;
			theModel.axisCone.y = 1;
			theModel.axisCone.z = 0;
			theModel.degreesCone = degreeSlider->value();
		}
		if (axisZ->isChecked())
		{
			theModel.axisCone.x = 0;
			theModel.axisCone.y = 0;
			theModel.axisCone.z = 1;
			theModel.degreesCone = degreeSlider->value();
		}
	}

	//theModel.degreesCylinder = degreeSlider->value();
	//theModel.rotation.x = rotationXSlider->value();
	//theModel.rotation.y = rotationYSlider->value();
	//theModel.rotation.z = rotationZSlider->value();

	/*theModel.scaling.x = scalingXSlider->value();
	theModel.scaling.y = scalingYSlider->value();
	theModel.scaling.z = scalingZSlider->value();*/

	glWindow->repaint();

	qDebug() << "slider value changed";
}

void MyWidget::clickedCheckBox()
{
	theModel.checkVisibilityCylinder = false;
	theModel.checkVisibilityCube = false;
	theModel.checkVisibilityPlane = false;
	theModel.checkVisibilitySphere = false;
	theModel.checkVisibilityCone = false;

	if (visibilityCylinder->isChecked())
	{
		theModel.checkVisibilityCylinder = true;
	}
	/*else if (visibilityCylinder->)
	{
		theModel.checkVisibilityCylinder = false;
	}*/
	if (visibilityCube->isChecked())
	{
		theModel.checkVisibilityCube = true;
	}
	if (visibilityPlane->isChecked())
	{
		theModel.checkVisibilityPlane = true;
	}
	if (visibilitySphere->isChecked())
	{
		theModel.checkVisibilitySphere = true;
	}
	if (visibilityCone->isChecked())
	{
		theModel.checkVisibilityCone = true;
	}

	glWindow->repaint();

	qDebug() << "checkbox value changed";
}

void MyWidget::setProgressValue()
{
	progressBar->setValue(lightZSlider->value());
	glWindow->repaint();

	qDebug() << "slider value changed";
}
