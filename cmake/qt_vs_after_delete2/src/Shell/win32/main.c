#include <stdio.h>
#include <QApplication>
#include <QLabel>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	QLabel *label = new QLabel("Hello Qt!");
	label->show();
	
	printf("Hello world\n");
	return app.exec();
}