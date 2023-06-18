#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "tictactoewidget.h"

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QLabel* player1Name;
    QLabel* player2Name;
    QPushButton* newGame;
    TicTacToeWidget* gameBoard;
    void setLabelBold(QLabel *label, bool isBold);
    void handleGameOver(TicTacToeWidget::Player winner);

private slots:
    void startNewGame();
    void updateNameLabels();
};
#endif // MAINWINDOW_H
