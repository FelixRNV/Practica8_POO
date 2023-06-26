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






void MainWindow::on_btnDire_clicked()
{
    QFileDialog dialog;
    QStringList cont;
    QDir direct;
    ui->lstWidCont->clear();
    dialog.setDirectory("/home/felix");
    dialog.setWindowTitle("Selecionar Carpeta: ");
    dialog.setFileMode(QFileDialog::Directory);
    dialog.setOption(QFileDialog::ShowDirsOnly);

    if (dialog.exec()) {
            QStringList directoriosSeleccionados = dialog.selectedFiles();
            foreach (QString directorio, directoriosSeleccionados) {
                ui->txtDir->setText(directorio);
                direct.setPath(directorio);
            }
    }
    AnalisisDir direc(direct);
    pathas.setBase(direc.base());
    cont=direc.contenido();
    foreach(QString item, cont){
        QListWidgetItem *itemList = new QListWidgetItem (item);
        ui->lstWidCont->addItem(itemList);
    }
}




void MainWindow::on_lstWidCont_itemClicked(QListWidgetItem *item)
{
    QDir direc;
    direc.setPath(pathas.base()+"/"+item->text());
    pathas.setDirec(direc);
    ui->txtProp->setText(pathas.propiedades());
}

