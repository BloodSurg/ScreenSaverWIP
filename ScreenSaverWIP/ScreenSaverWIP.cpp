#include "ScreenSaverWIP.h"
#include <QtMath>

ScreenSaverWIP::ScreenSaverWIP(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	ui.comboBoxShapes->addItem("Rectangle");
	ui.comboBoxShapes->addItem("Ellipse");
	ui.comboBoxShapes->addItem("X");
	ui.comboBoxShapes->addItem("+");

	connect(ui.comboBoxShapes, &QComboBox::currentTextChanged, this, &ScreenSaverWIP::shapeChanged);

	goWindowed();

	painter = new QPainter;

	//center = QPointF(canvasWidth / 2, canvasHeight / 2);

	/*numberOfMainOrbs = 4;
	for (int i = 0; i < numberOfMainOrbs; i++)
	{
		pointsMainOrbs += QPointF((center.x()+4)*qCos(i/360), (center.y()+4)*qSin(i/360));
	}

	numberOfSubOrbs = 4;
	for (int i = 0; i < pointsMainOrbs.length(); i++)
	{
		for (int j = 0; j < numberOfSubOrbs; j++)
		{
			pointsSubOrbs += QPointF((pointsMainOrbs[i].x()+1)*qCos(j/360), (pointsMainOrbs[i].y()+1)*qSin(j/360));
		}
	}*/
	for (int i = 0; i <= 1; i++)
	{
		for (int j = 0; j <= 1; j++)
		{
			pointsMainOrbs += QPointF(center.x() -40+i, center.y() -40+j);
		}
	}

	for (int mainOrbIndex = 0; mainOrbIndex < pointsMainOrbs.length(); mainOrbIndex++)
	{
		for (int i = 0; i <= 1; i++)
		{
			for (int j = 0; j <= 1; j++)
			{
				pointsSubOrbs += QPointF(pointsMainOrbs[mainOrbIndex].x() -10+i, pointsMainOrbs[mainOrbIndex].y() -10+j);
			}
		}
	}



	//for (int j = -numPoint; j < numPoint; j++)
	//{
	//	for (int i = -numPoint; i < numPoint; i++)
	//	{
	//		points += QPointF(i * distance, j * distance);
	//	}
	//}


	QTimer* timer = new QTimer(this);
	timer->setTimerType(Qt::PreciseTimer);
	timer->start(timerInterval);

	// timers
	QTimer* radiusTimer = new QTimer(this);
	radiusTimer->setTimerType(Qt::TimerType::PreciseTimer);
	radiusTimer->start(radiusTimerInterval);
	connect(radiusTimer, &QTimer::timeout, this, [=]()
		{
			radius += dRadius;
			if (radius > maxRadius || radius < minRadius)
			{
				dRadius = -dRadius;
			}
		});

	QTimer* distanceTimer = new QTimer(this);
	distanceTimer->setTimerType(Qt::PreciseTimer);
	distanceTimer->start(radiusTimerInterval);
	connect(distanceTimer, &QTimer::timeout, this, [=]()
		{
			distance += dDistance;
			if (distance > maxDistance || distance < minDistance)
			{
				dDistance = -dDistance;
			}

			/*points.clear();
			for (int j = -numPoint; j <= numPoint; j++)
			{
				for (int i = -numPoint; i <= numPoint; i++)
				{
					points += QPointF(i * distance, j * distance);
				}
			}*/
			pointsMainOrbs.clear();
			for (int i = 0; i <= 1; i++)
			{
				for (int j = 0; j <= 1; j++)
				{
					pointsMainOrbs += QPointF(center.x() - 4 + i * distance, center.y() - 4 + j * distance);
				}
			}
			pointsSubOrbs.clear();
			for (int mainOrbIndex = 0; mainOrbIndex < pointsMainOrbs.length(); mainOrbIndex++)
			{
				for (int i = 0; i <= 1; i++)
				{
					for (int j = 0; j <= 1; j++)
					{
						pointsSubOrbs += QPointF(pointsMainOrbs[mainOrbIndex].x() - 1 + i, pointsMainOrbs[mainOrbIndex].y() - 1 + j);
					}
				}
			}
		});

	QTimer* angleTimer = new QTimer(this);
	angleTimer->setTimerType(Qt::PreciseTimer);
	angleTimer->start(angleTimerInterval);
	connect(angleTimer, &QTimer::timeout, this, [=]()
		{
			angle += dAngle;
		});

	connect(timer, &QTimer::timeout, this, &ScreenSaverWIP::drawScreenClassic);
}

void ScreenSaverWIP::goFullscreen()
{
	if (image != nullptr)
	{
		delete image;
	}
	image = new QImage(canvasWidth, canvasHeight, QImage::Format_RGB888);
	image->fill(Qt::gray);

	this->showFullScreen();
	ui.canvas->setGeometry(10, 10, canvasWidth, canvasHeight);

	center = QPointF(canvasWidth / 2, canvasHeight / 2);
}

void ScreenSaverWIP::goWindowed()
{
	if (image != nullptr)
	{
		delete image;
	}
	image = new QImage(canvasWidth, canvasHeight, QImage::Format_RGB888);
	image->fill(Qt::gray);

	this->showNormal();
	ui.canvas->setGeometry(10, 10, canvasWidth, canvasHeight);

	center = QPointF(canvasWidth / 2, canvasHeight / 2);
}

void ScreenSaverWIP::shapeChanged()
{
	currentShape = ui.comboBoxShapes->currentText();
}

void ScreenSaverWIP::drawScreenClassic()
{
	{
		painter->begin(image);
		painter->setRenderHint(QPainter::Antialiasing);

		QTransform transform;
		transform.translate(center.x(), center.y());
		transform.rotate(angle);
		painter->setTransform(transform);

		if (currentShape == "Rectangle") {
			/*for (int k = 0; k < radius; k++)
			{
				painter->setPen(QPen(QColor(qrand() % 256, qrand() % 256, qrand() % 256), 1));
				for (int i = 0; i < points.size(); i++)
				{
					painter->drawRect(points[i].x() - k, points[i].y() - k, k * 2, k * 2);
				}
			}
			painter->end();
			ui.canvas->setPixmap(QPixmap::fromImage(*image));
			frameCounter++;*/

			for (int k = 0; k < radius; k++)
			{
				painter->setPen(QPen(QColor(qrand() % 256, qrand() % 256, qrand() % 256), 1));
				painter->drawRect(center.x() - k, center.y() - k, k * 2, k * 2);
				for (int i = 0; i < pointsMainOrbs.size(); i++)
				{

					painter->drawEllipse(pointsMainOrbs[i].x() - k*4, pointsMainOrbs[i].y() - k*4, k * 2, k * 2);
				}
				for (int i = 0; i < pointsSubOrbs.size(); i++)
				{

					painter->drawRect(pointsSubOrbs[i].x() - k*2, pointsSubOrbs[i].y() - k*2, k * 4, k * 4);
				}
			}
			painter->end();
			ui.canvas->setPixmap(QPixmap::fromImage(*image));
			frameCounter++;
		}
		else if (currentShape == "Ellipse") {
			for (int k = 0; k < radius; k++)
			{
				painter->setPen(QPen(QColor(qrand() % 256, qrand() % 256, qrand() % 256), 1));
				for (int i = 0; i < points.size(); i++)
				{
					painter->drawEllipse(points[i].x() - k, points[i].y() - k, k * 2, k * 2);
				}
			}
			painter->end();
			//ui.m_drawingWidget->setImage( *image );
			ui.canvas->setPixmap(QPixmap::fromImage(*image));
			frameCounter++;
		}
	}
}
