#include "mainwindow.h"
#include "configurationdialog.h"
#include "qapplication.h"

#include <QVBoxLayout>
#include <QMessageBox>
#include <QToolBar>
#include <QMenuBar>
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    player1Name = new QLabel("Player 1",this);
    player2Name = new QLabel("Player 2",this);

    player1Name -> setSizePolicy(QSizePolicy::Preferred,
                                 QSizePolicy::Fixed);
    player2Name -> setSizePolicy(QSizePolicy::Preferred,
                                 QSizePolicy::Fixed);

    gameBoard = new TicTacToeWidget(this);

    QWidget* mainArea = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(mainArea);

    this -> setCentralWidget(mainArea);

    layout -> addWidget(player1Name);
    layout -> addWidget(gameBoard);
    layout -> addWidget(player2Name);

    QToolBar *toolBar = new QToolBar(this);
    QMenu *menu = new QMenu("&Menu",this);

    this -> addToolBar(toolBar);
    this -> menuBar() -> addMenu(menu);

    QAction *newGame = new QAction("New Game",this);
    newGame -> setToolTip("Start new game");
    newGame -> setShortcut(QKeySequence(tr("Ctrl+N")));
    newGame -> setIcon(QIcon(":/icons/newgame.png"));

    QAction *quit = new QAction("Quit",this);
    quit -> setToolTip("Quit game");
    quit -> setShortcut(QKeySequence(tr("Ctrl+Q")));
    quit -> setIcon(QIcon(":/icons/application-exit.png"));

    toolBar -> addAction(newGame);
    toolBar -> addAction(quit);
    menu -> addAction(newGame);
    menu -> addAction(quit);

    connect(newGame, &QAction::triggered,
            this, &MainWindow::startNewGame);
    connect(quit, &QAction::triggered,
            this, &QApplication::quit);
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
    if(dialog.exec() == QDialog::Rejected) {
        return; // do nothing if dialog rejected
    }
    player1Name->setText(dialog.playerAName());
    player2Name->setText(dialog.playerBName());
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
