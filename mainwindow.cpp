#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QFileDialog dialog;
    dialog.setDirectory("/home/felix");
    dialog.setWindowTitle("Selecionar Carpeta: ");
    dialog.setFileMode(QFileDialog::Directory);
    dialog.setOption(QFileDialog::ShowDirsOnly);

    if (dialog.exec()) {
            QStringList directoriosSeleccionados = dialog.selectedFiles();
            foreach (QString directorio, directoriosSeleccionados) {
                ui->txtDir->setText(directorio);
            }
        }

}

