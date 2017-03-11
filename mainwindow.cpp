#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QQmlContext>

#include <QQuickView>

#include <QObject>
#include <QDebug>

#include "handletextfield.h"

//class MyClass : public QObject
//{
//    Q_OBJECT
//public slots:
//    void cppSlot(const QString &msg) {
//        //qDebug() << "Called the C++ slot with message:" << msg;
//    }
//};


//MyClass myClass;

HandleTextField handleTextField;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QQuickView *QuickView = new QQuickView(QUrl("qrc:/main.qml"));
    QWidget *ViewContainer = QWidget::createWindowContainer(QuickView, this);
    //ViewContainer->setGeometry(150, 0, 300, 200);
    ui->horizontalLayout->addWidget(ViewContainer);


    QQuickView *QuickView2 = new QQuickView(QUrl("qrc:/my.qml"));
    QWidget *ViewContainer2 = QWidget::createWindowContainer(QuickView2, this);
    ui->horizontalLayout_2->addWidget(ViewContainer2);
    QObject *item = (QObject*)QuickView2->rootObject();

    //    QObject *topLevel = engine.rootObjects().value(0);
    QObject *window = qobject_cast<QObject *>(item);

    // connect our QML signal to our C++ slot
    QObject::connect(window, SIGNAL(submitTextField(QString)),
                         &handleTextField, SLOT(handleSubmitTextField(QString)));

    // connect our C++ signal to our QML slot
    // NOTE: if we want to pass an parameter to our QML slot, it has to be
    // a QVariant.
    QObject::connect(&handleTextField, SIGNAL(setTextField(QVariant)),
                         window, SLOT(setTextField(QVariant)));

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::onTest1(QString str)
{
    //qDebug() << str;
}

void MainWindow::slot1()
{
    test2("abcdef");
}

