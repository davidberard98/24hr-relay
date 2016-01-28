#pragma once
#include <QFrame>
#include <QGridLayout>
#include <QLabel>
#include <QVector>
#include <QPushButton>
#include <iostream>
#include <string>

class timesDisplay : public QFrame
{
	//Q_OBJECT
	
	private:
	QVector<QLabel*> labels;
	int infopass;
	int columnCount;
	int rowCount;
	
	public:
	timesDisplay(QWidget *parent = 0);
	void bringToTop();
	void sortBy(int);
	
};
