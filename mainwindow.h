#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QListWidget>
#include <analisisdir.h>
#include <QDir>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_btnDire_clicked();

    void on_lstWidCont_itemClicked(QListWidgetItem *item);

    void on_txtDir_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    AnalisisDir pathas;
};
#endif // MAINWINDOW_H
