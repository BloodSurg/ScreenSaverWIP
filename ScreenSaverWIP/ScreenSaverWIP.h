#pragma once

#include <QtWidgets>
#include "ui_ScreenSaverWIP.h"

class ScreenSaverWIP : public QMainWindow
{
	Q_OBJECT
		

public:
	ScreenSaverWIP(QWidget* parent = Q_NULLPTR);

private:
	Ui::ScreenSaverWIPClass ui;


	void goFullscreen();
	void goWindowed();
	void shapeChanged();
	void drawScreen();

	

	QImage* image=nullptr;
	QPainter* painter=nullptr;
	QList<QPointF> points;
	QPointF center;

	QString currentShape="Rectangle";
	
	
	int numPoint;

	int canvasWidth = 501;
	int canvasHeight = 501;

	int timerInterval = 0;
	int radiusTimerInterval = 0;
	int distanceTimerInterval = 0;
	int angleTimerInterval = 0;

	double radius = 15.0;
	double minRadius = 10.0;
	double maxRadius = 20.0;
	double dRadius = 1.0;

	double distance = 0.0;
	double minDistance = 0.0;
	double maxDistance = 200.0;
	double dDistance = 0.1;

	double angle = 0.0;
	double dAngle = 1.0;

	int frameCounter = 0;
};
