#ifndef TEETHSCAN_WINDOW_H
#define TEETHSCAN_WINDOW_H

#include <QMainWindow>

namespace Ui {
class TeethScanWindow;
}

class TeethScanWindow : public QMainWindow {
    Q_OBJECT

  public:
    explicit TeethScanWindow(QWidget* parent = 0);
    ~TeethScanWindow();


    virtual void moveEvent(QMoveEvent* event);

  private:
    void createControlPanel();

  private:
    Ui::TeethScanWindow* ui;

    QWidget* tools_panel_;
};

#endif // TEETHSCAN_WINDOW_H
