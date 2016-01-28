#include <QApplication>
#include <QWidget>
#include <QFrame>
#include "timesDisplay.h"

int main(int argc, char *argv[])
{
	
	QApplication app(argc, argv);
	
	QWidget window;
	
	window.resize(250,150);
	window.setWindowTitle("Simple example");
	window.show();
	
	timesDisplay *td = new timesDisplay(&window);
	
	QGridLayout *grid = new QGridLayout(&window);
	grid->addWidget(td, 0,0);
	window.setLayout(grid);
	
	return app.exec();
}
