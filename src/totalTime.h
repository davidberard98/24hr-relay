#pragma once
#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <ctime>
#include <chrono>

class totalTime : public QFrame
{
	Q_OBJECT
	
	private:
	int theight;
	int tthseconds;
	
	public:
	totalTime(QWidget *parent = 0);
	void increment();
	
	
	
};
