#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QDebug>
#include <vector>
#include <string>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *e);

private slots:
    void on_enterPushButton_clicked();
    void deletePressed();
    void processList();


private:
    Ui::MainWindow *ui;
    std::vector<std::string> vec;

};

#endif // MAINWINDOW_H
