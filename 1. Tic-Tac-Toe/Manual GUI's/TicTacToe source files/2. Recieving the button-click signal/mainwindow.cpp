#include "mainwindow.h"

#include <QVBoxLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    player1Name = new QLabel("Player 1");
    player2Name = new QLabel("Player 2");
    newGame = new QPushButton("Start new game");
    gameBoard = new QWidget;

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
    qDebug() << "button clicked!";
}
