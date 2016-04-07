#include <QApplication>
#include <QWidget>
#include <QFrame>
#include "timesDisplay.h"
#include "totalTime.h"

int main(int argc, char *argv[])
{
	
	QApplication app(argc, argv);
	
	QWidget window;
	
	window.resize(400,100);
	//window.showFullScreen();
	window.setWindowTitle("Simple example");
	window.setStyleSheet("background-color:blue;");
	window.show();
	
	timesDisplay *td = new timesDisplay(&window);
	
	totalTime *tt = new totalTime(&window);
	
	QGridLayout *grid = new QGridLayout(&window);
	grid->addWidget(tt, 0,0);
	grid->addWidget(td, 1,0);
	window.setLayout(grid);
	
	return app.exec();
}
