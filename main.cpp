#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QQmlContext>

#include "handletextfield.h"

#include<QApplication>
#include"MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

//    HandleTextField handleTextField;

//    QObject *topLevel = engine.rootObjects().value(0);
//    QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);

//    // connect our QML signal to our C++ slot
//    QObject::connect(window, SIGNAL(submitTextField(QString)),
//                         &handleTextField, SLOT(handleSubmitTextField(QString)));



//    // connect our C++ signal to our QML slot
//    // NOTE: if we want to pass an parameter to our QML slot, it has to be
//    // a QVariant.
//    QObject::connect(&handleTextField, SIGNAL(setTextField(QVariant)),
//                         window, SLOT(setTextField(QVariant)));

    MainWindow w;
    w.show();

    return app.exec();
}
