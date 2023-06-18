#include "mainwindow.h"
#include "configurationdialog.h"

#include <QVBoxLayout>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    player1Name = new QLabel("Player 1",this);
    player2Name = new QLabel("Player 2",this);
    newGame = new QPushButton("Start new game",this);
    gameBoard = new TicTacToeWidget(this);

    QWidget* mainArea = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(mainArea);

    this -> setCentralWidget(mainArea);

    layout -> addWidget(newGame);
    layout -> addWidget(player1Name);
    layout -> addWidget(gameBoard);
    layout -> addWidget(player2Name);

    connect(newGame, &QPushButton::clicked,
            this, &MainWindow::startNewGame);
    connect(gameBoard, &TicTacToeWidget::currentPlayerChanged,
            this, &MainWindow::updateNameLabels);
    connect(gameBoard, &TicTacToeWidget::gameOver,
            this,&MainWindow::handleGameOver);
}

MainWindow::~MainWindow()
{
}

void MainWindow::setLabelBold(QLabel *label, bool isBold)
{
    QFont f = label->font();
    f.setBold(isBold);
    label->setFont(f);
}

void MainWindow::startNewGame()
{
    ConfigurationDialog dialog(this);
    player1Name->setText(tr("Alice"));
    player2Name->setText(tr("Bob"));
    gameBoard->initNewGame();
}

void MainWindow::updateNameLabels()
{
    setLabelBold(player1Name, gameBoard->currentPlayer() ==
                 TicTacToeWidget::Player::Player1);
    setLabelBold(player2Name, gameBoard->currentPlayer() ==
                 TicTacToeWidget::Player::Player2);
}

void MainWindow::handleGameOver(TicTacToeWidget::Player winner) {
    QString message;
    if(winner == TicTacToeWidget::Player::Draw) {
        message = tr("Game ended with a draw.");
    } else {
        QString winnerName = winner == TicTacToeWidget::Player::Player1 ?
                             player1Name->text() : player2Name->text();
        message = tr("%1 wins").arg(winnerName);
        }
    QMessageBox::information(this, tr("Info"), message);
}
