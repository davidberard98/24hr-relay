#include "totalTime.h"

totalTime::totalTime(QWidget *parent) : QFrame(parent)
{
	theight = 200;
	this->setStyleSheet("background-color:green;font-size:80px;font-weight:bold;color:yellow;text-align:center");
	QLabel *lbl = new QLabel("00:01:20.5", this);
	this->setMinimumHeight(200);
	this->setMaximumHeight(200);
	
	
	
}
