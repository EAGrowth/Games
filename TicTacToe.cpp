#include <iostream>
#include <ctime>

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main()
{
    char player = 'X';
    char computer = 'O';
    bool playAgain;

    do {
        char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
        bool running = true;

        drawBoard(spaces);

        while (running) {
            playerMove(spaces, player);
            drawBoard(spaces);
            if (checkWinner(spaces, player, computer)) {
                running = false;
                break;
            } else if (checkTie(spaces)) {
                running = false;
                break;
            }

            computerMove(spaces, computer);
            drawBoard(spaces);
            if (checkWinner(spaces, player, computer)) {
                running = false;
                break;
            } else if (checkTie(spaces)) {
                running = false;
                break;
            }
        }

        char choice;
        std::cout << "Do you want to play again? (Y/N): ";
        std::cin >> choice;
        playAgain = (choice == 'y' || choice == 'Y');

    } while (playAgain);

    std::cout << "Thanks for playing!\n";
    return 0;
}

void drawBoard(char *spaces) {
    std::cout << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << '\n';
}

void playerMove(char *spaces, char player) {
    int number;
    do {
        std::cout << "Enter a spot to place a marker (1-9): ";
        std::cin >> number;
        number--;
        if (number >= 0 && number < 9 && spaces[number] == ' ') {
            spaces[number] = player;
            break;
        }
    } while (true);
}

void computerMove(char *spaces, char computer) {
    int number;
    srand(time(0));

    while (true) {
        number = rand() % 9;
        if (spaces[number] == ' ') {
            spaces[number] = computer;
            break;
        }
    }
}

bool checkWinner(char *spaces, char player, char computer) {
    int winPattern = -1;

    // Array of win conditions, each containing three indices for the winning line
    int winConditions[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}             // Diagonals
    };

    // Loop through the win conditions to find a winning pattern
    for (int i = 0; i < 8; ++i) {
        int a = winConditions[i][0];
        int b = winConditions[i][1];
        int c = winConditions[i][2];

        if (spaces[a] != ' ' && spaces[a] == spaces[b] && spaces[b] == spaces[c]) {
            winPattern = i;
            break;
        }
    }

    switch (winPattern) {
        case 0:
            spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
            break;
        case 1:
            spaces[3] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
            break;
        case 2:
            spaces[6] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
            break;
        case 3:
            spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
            break;
        case 4:
            spaces[1] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
            break;
        case 5:
            spaces[2] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
            break;
        case 6:
            spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
            break;
        case 7:
            spaces[2] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
            break;
        default:
            return false;
    }

    return true;
}

bool checkTie(char *spaces) {
    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') {
            return false;
        }
    }
    std::cout << "IT'S A TIE!\n";
    return true;
}
