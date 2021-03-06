#include "timesDisplay.h"

timesDisplay::timesDisplay(QWidget *parent) : QFrame(parent)
{
	this->setStyleSheet("background-color:blue;color:yellow;font-size:20px;font-weight:bold");
	this->setMaximumWidth(500);
	
	//How many columns of info?
	columnCount = 3;
	entryCount = 10;
	
	grid = new QGridLayout(this);
	
	this->setMaximumHeight(readHeight()-200);
	
	
	QVector<QString> labelnames;
	labelnames.append(QString("Team Name"));
	labelnames.append(QString("Laps"));
	labelnames.append(QString("Lap Time"));
	
	QSignalMapper *mapper = new QSignalMapper(this);
	
	for(int i=0;i<labelnames.length();++i)
	{ // set the sort-labels.
		QPushButton *btn = new QPushButton(labelnames[i], this);
		
		connect(btn, SIGNAL(clicked()), mapper, SLOT(map()));
		mapper->setMapping(btn, i);
		
		grid->addWidget(btn, 1, i);
	}
	connect(mapper, SIGNAL(mapped(int)), this, SLOT(sortBy(int)));
	
	QPushButton *btn = new QPushButton("Recent Runner Sort");
	grid->addWidget(btn, 0, 0);
	connect(btn, &QPushButton::clicked, this, &timesDisplay::recentSort);
	
	for(int i=0;i<entryCount*columnCount;++i)
	{
		labels.append((QLabel *) NULL);
	}
	
	for(int i=0;i<entryCount;++i)
	{
		QString tvalue("Team Number ");
		
		QString nvalue = QString::number(i+1);

		tvalue.append(nvalue);
		QLabel *lbl = new QLabel(tvalue, this);
		labels[i*3] = lbl;
		//labels[i] -> setStyleSheet("background-color:blue;color:yellow" );
	}
	for(int i=0;i<entryCount;++i)
	{
		QString tvalue = QString::number(7*((i+1)%3)+12);
		QLabel *lbl = new QLabel(tvalue, this);
		lbl->setMaximumWidth(50);
		labels[i*3+1] = lbl;
	}
	for(int i=0;i<entryCount;++i)
	{
		QString tvalue = QString::number(9.2*i+78);
		QLabel *lbl = new QLabel(tvalue, this);
		labels[i*3+2] = lbl;
		lbl->setMaximumWidth(50);
	}
	
	//QPushButton *button = new QPushButton("Switch", this);
	
	//grid->addWidget(button, 0,0);
	
	for(int i=0;i<labels.length();++i)
	{
		grid->addWidget(labels[i], i/(columnCount)+2, i%3);
	} 
	/*
	for(int i=2;i<grid->rowCount();++i)
	{
		grid->setRowMinimumHeight(i, 30);
	} */
	setLayout(grid);
	
}

void timesDisplay::bringToTop()
{
	int index=infopass;
	std::cout << index << std::endl;
	QVector<QString> order;
	for(QLabel * lbl : labels)
	{
		order.append(lbl->text());
	}
	//order[0].replace(0, order[0].length(), "NEW TEXT");
	
	
	for(int i=0;i<labels.size();++i)
	{
		int tcpy = i;
		if(tcpy == index)
			tcpy = 0;
		else if(tcpy < index)
			tcpy += 1;
		labels[i]->setText(order[(tcpy)%order.length()]);
	}
	
}

void timesDisplay::testingpurposes()
{
	std::cout << "TP" << std::endl;
}

int timesDisplay::readHeight()
{
	QDesktopWidget widget;
	QRect mainScreenSize = widget.availableGeometry(widget.primaryScreen()); // or screenGeometry(), depending on your needs
	return mainScreenSize.height();
}

void timesDisplay::sortBy(int colToSort)
{
	std::cout << "Sort By col." << colToSort << std::endl;
}

void timesDisplay::recentSort()
{
	std::cout << "RECENTS" << std::endl;
}
