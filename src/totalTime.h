#pragma once
#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QTimer>
#include <ctime>
#include <chrono>
#include <string>
#include <iostream>

class totalTime : public QFrame
{
	Q_OBJECT
	
	private:
	int theight;
	int tthseconds;
	QLabel *label;
	QTimer *timer;

	std::chrono::high_resolution_clock::time_point startTime;
	
	public:
	totalTime(QWidget *parent = 0);
	void setTime(int);
	void setTime();
	
	public slots:
	void updater();
	
	private:
	std::string toChar(int, int);
	
};
