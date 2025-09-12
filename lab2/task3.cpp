#include <iostream>
using namespace std;

int main() {
    int num_teams;
    cout << "Enter number of teams: ";
    cin >> num_teams;

    int** scores = new int*[num_teams];
    int* team_sizes = new int[num_teams];

    for (int i = 0; i < num_teams; ++i) {
        cout << "Enter number of players in team " << i + 1 << ": ";
        cin >> team_sizes[i];
        scores[i] = new int[team_sizes[i]];
        cout << "Enter scores for team " << i + 1 << ": ";
        for (int j = 0; j < team_sizes[i]; ++j) {
            cin >> scores[i][j];
        }
    }

    cout << "\nTeam Scores Summary:\n";
    for (int i = 0; i < num_teams; ++i) {
        int sum = 0;
        for (int j = 0; j < team_sizes[i]; ++j) {
            sum += scores[i][j];
        }
        cout << "Team " << i + 1 << " total score: " << sum << "\n";
    }

    for (int i = 0; i < num_teams; ++i) {
        delete[] scores[i];
    }
    delete[] scores;
    delete[] team_sizes;

    return 0;
}
