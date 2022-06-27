#include <QCoreApplication>
#include <QJSEngine>

int main(int argc, char* argv[]) {

    QCoreApplication a(argc, argv);

    QJSEngine scriptEngine;
    QJSValue value = scriptEngine.evaluate("2 * 2");
    qDebug() << value.toInt();

    return 0;
}
