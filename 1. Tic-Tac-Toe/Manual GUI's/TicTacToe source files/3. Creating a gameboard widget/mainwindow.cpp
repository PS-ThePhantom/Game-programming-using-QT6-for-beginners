#include "mainwindow.h"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    player1Name = new QLabel("Player 1");
    player2Name = new QLabel("Player 2");
    newGame = new QPushButton("Start new game");

    gameBoard = new TicTacToeWidget;

    QWidget* mainArea = new QWidget;
    QVBoxLayout* layout = new QVBoxLayout(mainArea);

    this -> setCentralWidget(mainArea);

    layout -> addWidget(newGame);
    layout -> addWidget(player1Name);
    layout -> addWidget(gameBoard);
    layout -> addWidget(player2Name);

    connect(newGame, &QPushButton::clicked,
            this, &MainWindow::startNewGame);
}

MainWindow::~MainWindow()
{
}

void MainWindow::startNewGame()
{
    player1Name->setText(tr("Alice"));
    player2Name->setText(tr("Bob"));
}
