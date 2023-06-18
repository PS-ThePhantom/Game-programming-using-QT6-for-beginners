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

private slots:
    void startNewGame();
};
#endif // MAINWINDOW_H
