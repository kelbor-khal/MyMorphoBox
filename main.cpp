#include "morho.h"

#include <QApplication>
#include <qdesktopwidget.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Morho w;
    QDesktopWidget *desktop = QApplication::desktop();

    setlocale(LC_NUMERIC,"C");
    a.setWindowIcon(QIcon("/home/ivan/MyProject/Morfius/MyMorphoBox/image/icon.png"));

    w.move((desktop->width() - w.width())/ 2,
               (desktop->height() - w.height()) /2);
    w.setWindowTitle("Генератор морфологического ящика");

    w.show();
    return a.exec();
}
