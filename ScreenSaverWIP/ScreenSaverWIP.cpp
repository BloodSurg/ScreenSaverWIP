#include "ScreenSaverWIP.h"

ScreenSaverWIP::ScreenSaverWIP(QWidget *parent)
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

    numPoint = 5;

	for (int j = -numPoint; j <= numPoint; j++)
	{
		for (int i = -numPoint; i <= numPoint; i++)
		{
			points += QPointF(i * distance, j * distance);
		}
	}
    

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

			points.clear();
			for (int j = -numPoint; j <= numPoint; j++)
			{
				for (int i = -numPoint; i <= numPoint; i++)
				{
					points += QPointF(i * distance, j * distance);
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

	connect(timer, &QTimer::timeout, this, [=]()
		{
			painter->begin(image);
			painter->setRenderHint(QPainter::Antialiasing);

			QTransform transform;
			transform.translate(center.x(), center.y());
			transform.rotate(angle);
			painter->setTransform(transform);

			if (currentShape == "Rectangle") {
				for (int k = 0; k < radius; k++)
				{
					painter->setPen(QPen(QColor(qrand() % 256, qrand() % 256, qrand() % 256), 1));
					for (int i = 0; i < points.size(); i++)
					{
						painter->drawRect(points[i].x() - k, points[i].y() - k, k * 2, k * 2);
					}
				}
				painter->end();
				//ui.m_drawingWidget->setImage( *image );
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
		});
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

void ScreenSaverWIP::drawScreen()
{
   
}
