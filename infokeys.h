#ifndef INFOKEYS_H
#define INFOKEYS_H

#include <QDialog>
#include <QString>

namespace Ui {
class InfoKeys;
}

class InfoKeys : public QDialog
{
    Q_OBJECT

public:
    explicit InfoKeys(QWidget *parent = nullptr);
    ~InfoKeys();

public slots:
    void openInfoKeyWindow();

private slots:
    void SetInfoLabel();
    void on_pushButton_clicked();

private:
    Ui::InfoKeys *ui;

};

#endif // INFOKEYS_H
