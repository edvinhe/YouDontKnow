#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

protected slots:
    void slot1();// 响应pushButton的clicked信号
    void onTest1(QString str);// 响应QML的test1信号

signals:
    void test2(QString str);// 触发QML的onTest2槽


private:
    //HandleTextField handleTextField;
};

#endif // MAINWINDOW_H
