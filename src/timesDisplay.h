#pragma once
#include <QFrame>
#include <QGridLayout>
#include <QLabel>
#include <QVector>
#include <QPushButton>
#include <QSignalMapper>
#include <QDesktopWidget>
#include <iostream>
#include <string>

class timesDisplay : public QFrame
{
	Q_OBJECT
	
	private:
	QVector<QLabel*> labels;
	QGridLayout *grid;
	int infopass;
	int columnCount;
	int entryCount;
	int rowCount; // differs from entryCount depending how many rows can fit.
	int rowHeight;
	int sortByDefault;
	
	public:
	timesDisplay(QWidget *parent = 0);
	void bringToTop();
	
	public slots:
	int readHeight();
	void sortBy(int);
	void recentSort();
	void testingpurposes();
	
};
