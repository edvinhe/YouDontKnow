#include "teethscan_window.h"
#include "ui_teethscan_window.h"


#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QQmlContext>

#include <QQuickView>

#include <QObject>
#include <QDebug>

#include <QDialog>
#include <QLabel>

QDialog* createDialog(QWidget* parent, const QString& windowTitle) {
    QDialog* dialog = new QDialog(parent, Qt::CustomizeWindowHint | Qt::WindowTitleHint);

    dialog->setWindowOpacity(0.8);
    dialog->setWindowTitle(windowTitle);
    dialog->setLayout(new QVBoxLayout);

    return dialog;
}

TeethScanWindow::TeethScanWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::TeethScanWindow) {
    ui->setupUi(this);

    QQuickView* QuickView = new QQuickView(QUrl("qrc:/teechscanheader.qml"));
    QWidget* headerFrame = QWidget::createWindowContainer(QuickView, this);
    ui->horizontalLayout_2->addWidget(headerFrame);

    QQuickView* QuickView1 = new QQuickView(QUrl("qrc:/teechscan_left.qml"));
    QWidget* headerFrame1 = QWidget::createWindowContainer(QuickView1, this);
    ui->verticalLayout_3->addWidget(headerFrame1);

    QQuickView* QuickView2 = new QQuickView(QUrl("qrc:/teechscan_right.qml"));
    QWidget* headerFrame2 = QWidget::createWindowContainer(QuickView2, this);
    ui->horizontalLayout_4->addWidget((headerFrame2));

    //QWidget* instructions = createDialog(this, tr("Instructions"));
    //instructions->layout()->addWidget(new QLabel( tr("Use mouse wheel to zoom model, and click and " "drag to rotate model")));
    //instructions->layout()->addWidget(new QLabel( tr("Move the sun around to change the light " "position")));
    //instructions->show();

    createControlPanel();
}

TeethScanWindow::~TeethScanWindow() {
    delete ui;
}

void TeethScanWindow::moveEvent(QMoveEvent* event) {
    QPoint parent_fD_p = QWidget::mapToParent(QPoint(30, 70));
    tools_panel_->move(parent_fD_p);

    QWidget::moveEvent(event);
}

void TeethScanWindow::createControlPanel() {
    tools_panel_ = createDialog(this, tr("Instructions with qml"));
    QQuickView* QuickViewP = new QQuickView(QUrl("qrc:/my.qml"));
    QWidget* headerFrameP = QWidget::createWindowContainer(QuickViewP, this);
    tools_panel_->setFixedSize(QSize(250, 400));
    tools_panel_->layout()->addWidget(headerFrameP);
    tools_panel_->show();

    QPoint parent_fD_p = QWidget::mapToParent(QPoint(30, 70));
    tools_panel_->move(parent_fD_p);
}
