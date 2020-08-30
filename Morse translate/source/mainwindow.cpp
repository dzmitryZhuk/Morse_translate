#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(title);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_import_2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                tr("Open file"),
                                "",
                                tr("Text Files (*.txt);;All Files (*)"));
    if (!fileName.isEmpty())
    {
        QFile *file = new QFile(fileName);
        if(!file->open(QIODevice::ReadOnly)) {
            QMessageBox::information(0, "error", file->errorString());
        }

        QTextStream in(file);
        QString text = in.readAll();
        if(!text.isEmpty())
            ui->input->setText(text);
        else
            QMessageBox::warning(this,"Warning","File is empty!");

        file->close();
    }
}

void MainWindow::on_input_textChanged()
{
    if(autodetection(ui->input->toPlainText()))
        ui->output->setText((new Translator)->textToMorse(ui->input->toPlainText()));
    else
        ui->output->setText((new Translator)->morseToText(ui->input->toPlainText()));
}

bool MainWindow::autodetection(QString text)
{
    if(!text.isEmpty())
    {
        char firstChar = text.at(0).toLatin1();
        if(firstChar == '.' || firstChar == '-')
            return false;
        else
            return true;

    }
}

void MainWindow::on_export_3_clicked()
{
    QString output = ui->output->toPlainText();
    if(!output.isEmpty())
    {
        QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                   "",
                                   tr("Text Files (*.txt);;All Files (*)"));
        if (!fileName.isEmpty())
        {
            QFile *file = new QFile(fileName);
            if(!file->open(QIODevice::WriteOnly)) {
                QMessageBox::information(0, "error", file->errorString());
            }

            QTextStream out(file);
            out << output;

            file->close();
        }
    }
    else
        QMessageBox::warning(this,"Warning","There is no encoded text!");
}
