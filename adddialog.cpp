// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "adddialog.h"

#include <QtWidgets>

//! [0]
//!

AddDialog::AddDialog(QWidget *parent)
    : QDialog(parent),
    nameText(new QLineEdit),
    addressText(new QTextEdit)
{
    auto nameLabel = new QLabel(tr("Name"));
    auto addressLabel = new QLabel(tr("Address"));
    okButton = new QPushButton(tr("OK"));
    auto cancelButton = new QPushButton(tr("Cancel"));

    auto gLayout = new QGridLayout;
    gLayout->setColumnStretch(1, 2);
    gLayout->addWidget(nameLabel, 0, 0);
    gLayout->addWidget(nameText, 0, 1);

    gLayout->addWidget(addressLabel, 1, 0, Qt::AlignLeft | Qt::AlignTop);
    gLayout->addWidget(addressText, 1, 1, Qt::AlignLeft);

    auto buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    gLayout->addLayout(buttonLayout, 2, 1, Qt::AlignRight);

    auto mainLayout = new QVBoxLayout;
    mainLayout->addLayout(gLayout);
    setLayout(mainLayout);

    connect(nameText, &QLineEdit::textChanged, this, &AddDialog::checkWidgetContent);
    connect(addressText, &QTextEdit::textChanged, this, &AddDialog::checkWidgetContent);

    connect(okButton, &QAbstractButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QAbstractButton::clicked, this, &QDialog::reject);

    setWindowTitle(tr("Add a Contact"));

    // Встановлення початкового стану кнопки "OK"
    checkWidgetContent();
}

void AddDialog::checkWidgetContent()
{
    QString nameTextContent = nameText->text();
    QString addressTextContent = addressText->toPlainText();

    if (nameTextContent.isEmpty() || addressTextContent.isEmpty())
    {
        okButton->setEnabled(false);
    }
    else
    {
        okButton->setEnabled(true);
    }
}

QString AddDialog::name() const
{
    return nameText->text();
}

QString AddDialog::address() const
{
    return addressText->toPlainText();
}

void AddDialog::editAddress(const QString &name, const QString &address)
{
    nameText->setReadOnly(true);
    nameText->setText(name);
    addressText->setPlainText(address);
}
//! [0]
