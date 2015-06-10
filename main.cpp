#include <QtCore/QCoreApplication>
#include "replacev3objects.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	replaceV3Objects(argc, argv);

	return 0;
	//return a.exec();
}
