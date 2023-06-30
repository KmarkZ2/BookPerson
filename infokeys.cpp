#include "infokeys.h"
#include "ui_infokeys.h"

InfoKeys::InfoKeys(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoKeys)
{
    ui->setupUi(this);
    SetInfoLabel();
}

InfoKeys::~InfoKeys()
{
    delete ui;
}
void InfoKeys::openInfoKeyWindow()
{
    hide();
    InfoKeys *ShowWindow = new InfoKeys(this);
    ShowWindow->show();
}

void InfoKeys::SetInfoLabel()
{
    ui->lineEdit->setText("CTRL + A");
    ui->lineEdit_2->setText("CTRL + E");
    ui->lineEdit_3->setText("CTRL + D");
    ui->lineEdit_4->setText("CTRL + S");
    ui->lineEdit_5->setText("CTRL + O");
}

void InfoKeys::on_pushButton_clicked()
{
    ui->lineEdit->setReadOnly(false);
    ui->lineEdit_2->setReadOnly(false);
    ui->lineEdit_3->setReadOnly(false);
    ui->lineEdit_4->setReadOnly(false);
    ui->lineEdit_5->setReadOnly(false);
}
