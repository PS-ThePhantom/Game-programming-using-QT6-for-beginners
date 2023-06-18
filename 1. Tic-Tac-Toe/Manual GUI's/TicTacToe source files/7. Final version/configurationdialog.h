#ifndef CONFIGURATIONDIALOG_H
#define CONFIGURATIONDIALOG_H

#include <QLineEdit>
#include <QWidget>
#include <QDialog>
#include <QDialogButtonBox>

class ConfigurationDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ConfigurationDialog(QWidget *parent = nullptr);
    void setPlayer1Name(const QString &p1name);
    void setPlayer2Name(const QString &p2name);
    QString playerAName() const;
    QString playerBName() const;

private:
    QLineEdit* player1Name;
    QLineEdit* player2Name;
    QDialogButtonBox* dialogButtons;

signals:

private slots:
    void updateOKButtonState();
};

#endif // CONFIGURATIONDIALOG_H
