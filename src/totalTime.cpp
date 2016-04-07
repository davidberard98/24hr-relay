#include "totalTime.h"

totalTime::totalTime(QWidget *parent) : QFrame(parent)
{
	theight = 200;
	this->setStyleSheet("background-color:green;font-size:80px;font-weight:bold;color:yellow;text-align:center");
	label = new QLabel("00:01:20.5", this);
	this->setMinimumHeight(200);
	this->setMaximumHeight(200);
	
	startTime = std::chrono::high_resolution_clock::now();
	
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(updater()));
	timer->start(100);
}


void totalTime::updater()
{
	std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
	std::chrono::duration<int, std::ratio<1, 1000>> time_span = std::chrono::duration_cast<std::chrono::duration<int, std::ratio<1, 1000>>> (now-startTime);
	int timePassed = time_span.count()/100;
	setTime(timePassed);
	
}
void totalTime::setTime()
{
	setTime(tthseconds);
}
std::string totalTime::toChar(int input, int minLength)
{
	std::string output;
	while(input > 0)
	{
		output = ((char) (input%10+48)) + output;
		input /= 10;
	}
	while(output.length() < minLength)
	{
		output = "0" + output;
	}
	return output;
}
void totalTime::setTime(int tenthseconds)
{
	tthseconds = tenthseconds;
	int tenth = tthseconds%10;
	int second = (tthseconds/10)%60;
	int minute = (tthseconds/600)%60;
	int hour = tthseconds/36000;
	// 00:00:00.0
	
	
	std::string timeLabel = toChar(hour, 1) + ":";
	timeLabel += toChar(minute, 2) + ":";
	timeLabel += toChar(second, 2) + ".";
	timeLabel += toChar(tenth, 1);
	label->setText(timeLabel.c_str());
}
