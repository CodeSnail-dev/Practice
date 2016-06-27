#include <QApplication>
#include <QWidget>

int main(int argc, char * argv[])
{
	QApplication a(argc, argv);

	QWidget wnd;
	wnd.show();

	return a.exec();
}