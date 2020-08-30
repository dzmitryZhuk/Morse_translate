#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include <QFile>
#include <QWidget>
#include <QMessageBox>
#include <QTextStream>
#include "translator.h"

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
    // open file button clicked
    void on_import_2_clicked();

    void on_input_textChanged();

    // save file button clicked
    void on_export_3_clicked();

private:
    Ui::MainWindow *ui;

    // window title
    QString title = "Morse translate";

    // return FALSE if text is encoded (Morse), otherwise TRUE (plain text)
    bool autodetection(QString text);
    };
#endif // MAINWINDOW_H
