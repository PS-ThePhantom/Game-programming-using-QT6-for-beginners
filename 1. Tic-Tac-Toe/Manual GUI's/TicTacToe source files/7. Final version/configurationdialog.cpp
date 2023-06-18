#include "configurationdialog.h"

#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPushButton>

ConfigurationDialog::ConfigurationDialog(QWidget *parent)
    : QDialog{parent}
{

    QLabel* player1Text = new QLabel("Player &A Name:",this);
    QLabel* player2Text = new QLabel("Player &B Name:",this);
    player1Name = new QLineEdit(this);
    player2Name = new QLineEdit(this);

    player1Text -> setBuddy(player1Name);
    player2Text -> setBuddy(player2Name);

    QWidget* grid = new QWidget(this);
    QGridLayout* gridLayout = new QGridLayout(grid);

    gridLayout -> addWidget(player1Text,0,0);
    gridLayout -> addWidget(player1Name,0,1);
    gridLayout -> addWidget(player2Text,1,0);
    gridLayout -> addWidget(player2Name,1,1);

    dialogButtons = new QDialogButtonBox(QDialogButtonBox::Ok |
                                         QDialogButtonBox::Cancel);

    QVBoxLayout* dialogVerticalLayout = new QVBoxLayout(this);

    dialogVerticalLayout -> addWidget(grid);
    dialogVerticalLayout -> addWidget(dialogButtons);

    connect(dialogButtons, &QDialogButtonBox::accepted,
            this, &QDialog::accept);
    connect(dialogButtons, &QDialogButtonBox::rejected,
            this, &QDialog::reject);
    connect(player1Name, &QLineEdit::textChanged,
            this, &ConfigurationDialog::updateOKButtonState);
    connect(player2Name, &QLineEdit::textChanged,
            this, &ConfigurationDialog::updateOKButtonState);

    updateOKButtonState();
}

void ConfigurationDialog::setPlayer1Name(const QString &p1name)
{
    player1Name->setText(p1name);
}

void ConfigurationDialog::setPlayer2Name(const QString &p2name)
{
    player2Name->setText(p2name);
}

QString ConfigurationDialog::playerAName() const
{
    return player1Name->text();
}

QString ConfigurationDialog::playerBName() const
{
    return player2Name->text();
}

void ConfigurationDialog::updateOKButtonState()
{
    dialogButtons -> button(QDialogButtonBox::Ok)
                  ->setEnabled(!player1Name->text().isEmpty() &&
                               !player2Name->text().isEmpty());
}
