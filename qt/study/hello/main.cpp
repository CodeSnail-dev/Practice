#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QLabel *label = new QLabel("Hello Qt!");
	label->show();

    app.exec();

    QLabel *label1 = new QLabel("Hello Qt222!");
    label1->show();
    
//    app.exec();

	return 0; 
}