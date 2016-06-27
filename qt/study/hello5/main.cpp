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
	Ui_Dialog *ui_dialog = new Ui_Dialog();
	ui_dialog->setupUi(dialog);
	dialog->show();

	return app.exec();
}