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
	void drawScreenClassic();

	

	QImage* image=nullptr;
	QPainter* painter=nullptr;
	QList<QPointF> points;
	
	QList<QPointF> pointsMainOrbs;
	QList<QPointF> pointsSubOrbs;
	
	QPointF center;

	int distance_centerToMain;
	int distance_mainToSub;

	int sizeCenter;
	int sizeMain;
	int sizeSub;

	int numberOfMainOrbs;
	int numberOfSubOrbs;

	QString currentShape="Rectangle";
	
	
	int numPoint;

	int canvasWidth = 500;
	int canvasHeight = 500;

	int timerInterval = 0;
	int radiusTimerInterval = 0;
	int distanceTimerInterval = 0;
	int angleTimerInterval = 0;

	double radius = 10.0;
	double minRadius = 5.0;
	double maxRadius = 150.0;
	double dRadius = 1.0;

	double distance = 0.0;
	double minDistance = 0.0;
	double maxDistance = 200.0;
	double dDistance = 0.1;

	double angle = 0.0;
	double dAngle = 1.0;

	int frameCounter = 0;
};
