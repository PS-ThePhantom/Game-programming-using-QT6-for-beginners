#ifndef TICTACTOEWIDGET_H
#define TICTACTOEWIDGET_H

#include <QPushButton>
#include <QWidget>

class TicTacToeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TicTacToeWidget(QWidget *parent = nullptr);
    enum class Player {
        Invalid, Player1, Player2, Draw
    };
    Q_ENUM(Player)

    Player currentPlayer() const;
    void setCurrentPlayer(Player p);
    void initNewGame();

private:
    QVector<QPushButton*> m_board;
    Player m_currentPlayer;

    // returns the player who won, Draw if there is a draw,
    // or Invalid if the game is not finished yet
    TicTacToeWidget::Player checkWinCondition() const;

    // returns the player who occupied all 3 buttons with the specified indices,
    // or Invalid if it's not the case
    TicTacToeWidget::Player checkWinConditionForLine(
            int index1, int index2, int index3) const;

signals:
    void currentPlayerChanged(TicTacToeWidget::Player);
    void gameOver(TicTacToeWidget::Player);

private slots:
    void handleButtonClick(int index);

};

#endif // TICTACTOEWIDGET_H
