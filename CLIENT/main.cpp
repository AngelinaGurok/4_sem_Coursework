/*
    Дочерний tcp-сокет получает изображение, помещенное в метку, чтобы показать эффект реализации видео
    Функция чата через связь UDP
    Переопределите события окна qt, чтобы отправлять события через tcp на сервер для управления синхронизацией
    Переопределение функции события мыши QT
*/

#include "client.h"
#include "menu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Menu w;
    w.show();

    return a.exec();
}
