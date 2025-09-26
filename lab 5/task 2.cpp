#include <iostream>

using namespace std;

const int N = 5;

int maze[N][N] = {
    {0, 0, 1, 1, 1},
    {0, 1, 0, 1, 1},
    {1, 0, 0, 0, 1},
    {1, 0, 1, 0, 1},
    {1, 1, 1, 0, 0}
};

int solution[N][N] = {0};

void printSolution() {
    cout << "Solution Array (Path from (0, 0) to (4, 4)):" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int row, int col) {
    return (row >= 0 && row < N && col >= 0 && col < N && maze[row][col] == 1);
}

bool solveMazeBacktracking(int row, int col) {
    if (row == N - 1 && col == N - 1) {
        solution[row][col] = 1;
        return true;
    }

    if (isSafe(row, col)) {
        solution[row][col] = 1;

        if (solveMazeBacktracking(row + 1, col)) {
            return true;
        }

        if (solveMazeBacktracking(row, col + 1)) {
            return true;
        }

        if (solveMazeBacktracking(row - 1, col)) {
            return true;
        }

        if (solveMazeBacktracking(row, col - 1)) {
            return true;
        }

        solution[row][col] = 0;
        return false;
    }

    return false;
}

int main() {
    cout << "Start point: (0, 0), Destination point: (4, 4)." << endl;
    
    if (solveMazeBacktracking(0, 0)) {
        cout << "Path found successfully!" << endl;
        printSolution();
    } else {
        cout << "\nNo path exists from (0, 0) to (4, 4) in the given maze." << endl;
        cout << "Reason: The starting cell (0, 0) is an obstacle ('0') in the maze grid." << endl;
    }

    return 0;
}
