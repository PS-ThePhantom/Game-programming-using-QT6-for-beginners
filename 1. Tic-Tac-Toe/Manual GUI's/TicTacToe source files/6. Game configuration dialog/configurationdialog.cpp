#include "configurationdialog.h"

#include <QLabel>
#include <QDialog>
#include <QDialogButtonBox>
#include <QGridLayout>
#include <QGridLayout>

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

    QDialogButtonBox* dialogButtons = new QDialogButtonBox(QDialogButtonBox::Ok |
                                                           QDialogButtonBox::Cancel);
    QDialog* dialog = new QDialog(this);
    QVBoxLayout* dialogVerticalLayout = new QVBoxLayout(dialog);

    dialogVerticalLayout -> addWidget(grid);
    dialogVerticalLayout -> addWidget(dialogButtons);

    connect(dialogButtons, &QDialogButtonBox::accepted, dialog, &QDialog::accept);
    connect(dialogButtons, &QDialogButtonBox::rejected, dialog, &QDialog::reject);

    dialog -> exec();
}
