#include "qinfo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QInfo w;
	w.show();
	return a.exec();
}
