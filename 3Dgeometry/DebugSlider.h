#ifndef DEBUG_SLIDER_H
#define DEBUG_SLIDER_H
#include <QtGui\qwidget>
class QSlider;
class QLabel;

class DebugSlider : public QWidget
{
	Q_OBJECT

	QSlider* slider;
	QLabel* label;
	float sliderGranularity;
	float min;
	float max;

	private slots:
	void sliderValueChanged();

signals:
	void valueChanged(float newValue);

public:
	DebugSlider(float value = 0.0f, float min = -20.0f, float max = 20.0f, bool textOnLeft = true, float granularity = 80.0);
	float value() const;
	void setValue(float newValue);
};

#endif

