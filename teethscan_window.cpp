#include "teethscan_window.h"
#include "ui_teethscan_window.h"


#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QQmlContext>

#include <QQuickView>

#include <QObject>
#include <QDebug>

TeethScanWindow::TeethScanWindow(QWidget* parent) :
  QMainWindow(parent),
  ui(new Ui::TeethScanWindow) {
  ui->setupUi(this);

  QQuickView* QuickView = new QQuickView(QUrl("qrc:/teechscanheader.qml"));
  QWidget *headerFrame = QWidget::createWindowContainer(QuickView, this);
  ui->horizontalLayout_2->addWidget(headerFrame);

  QQuickView* QuickView1 = new QQuickView(QUrl("qrc:/teechscan_left.qml"));
  QWidget *headerFrame1 = QWidget::createWindowContainer(QuickView1, this);
  ui->verticalLayout_3->addWidget(headerFrame1);

  QQuickView* QuickView2 = new QQuickView(QUrl("qrc:/teechscan_right.qml"));
  QWidget *headerFrame2 = QWidget::createWindowContainer(QuickView2, this);
  ui->horizontalLayout_4->addWidget((headerFrame2));


}

TeethScanWindow::~TeethScanWindow() {
  delete ui;
}
