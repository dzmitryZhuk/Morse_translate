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
            QMessageBox::information(0, "Error opening file", file->errorString());
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
    if(!isMorse(ui->input->toPlainText()))
    {
        ui->output->setText((new Translator)->textToMorse(ui->input->toPlainText().toLower()));
    }
    else
    {
        ui->output->setText((new Translator)->morseToText(ui->input->toPlainText().toLower()));
    }
}

bool MainWindow::isMorse(QString text)
{
    if(!text.isEmpty())
    {
        int i = 0;
        char tmp = text.at(i).toLatin1();
        if(tmp != '.' && tmp != '-')
            return false;
        if(text.size() > 1 && text[0] == '-' && text[1] != '-' && text[1] != '.')
            return false;
        if(text.size() > 3 && text[0] == '.' && text[1] == '.' && text[2] == '.' && text[3] != '.' && text[3] != '-')
            return false;
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
                QMessageBox::information(0, "Error opening file", file->errorString());
            }

            QTextStream out(file);
            out << output;

            file->close();
        }
    }
    else
        QMessageBox::warning(this,"Warning","There is no encoded text!");
}
