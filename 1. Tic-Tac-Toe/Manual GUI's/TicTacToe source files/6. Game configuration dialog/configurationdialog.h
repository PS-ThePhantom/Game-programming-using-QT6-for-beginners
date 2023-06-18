#ifndef CONFIGURATIONDIALOG_H
#define CONFIGURATIONDIALOG_H

#include <QLineEdit>
#include <QWidget>
#include <QDialog>

class ConfigurationDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ConfigurationDialog(QWidget *parent = nullptr);

private:
    QLineEdit* player1Name;
    QLineEdit* player2Name;

signals:

};

#endif // CONFIGURATIONDIALOG_H
