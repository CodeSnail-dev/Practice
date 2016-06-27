#include <QApplication>
#include <QLabel>
#include <QDialog>
#include "NavShellDialog.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	
	QLabel *label = new QLabel("Hello Qt!");
	label->show();
	
	QDialog *dialog = new QDialog();
	NavShellDialog *ui_dialog = new NavShellDialog();
	ui_dialog->setupUi(dialog);
	dialog->show();

	return app.exec();
}