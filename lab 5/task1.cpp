#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void playGame(int target, int player, int totalPlayers) {
    int guess;
    cout << "Player " << player << ", enter your guess (1-100): ";
    cin >> guess;

    if (guess == target) {
        cout << "?? Player " << player << " wins! The number was " << target << ".\n";
        return; 
    } 
    else if (guess < target) {
        cout << "Too low! Try again.\n";
    } 
    else {
        cout << "Too high! Try again.\n";
    }

    int nextPlayer = (player % totalPlayers) + 1;
    playGame(target, nextPlayer, totalPlayers); 
}

int main() {
    srand(time(0));  
    int target = rand() % 100 + 1;

    int totalPlayers;
    cout << "Enter number of players: ";
    cin >> totalPlayers;

    cout << "\n--- Guess the Number Game ---\n";
    playGame(target, 1, totalPlayers); 
    return 0;
}
