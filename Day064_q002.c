#include <stdlib.h>

typedef struct {
    int x, y, time;
} Node;

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];

    Node queue[rows * cols];
    int front = 0, rear = 0;

    int fresh = 0;

    // Initialize queue with rotten oranges
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                queue[rear++] = (Node){i, j, 0};
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    int time = 0;

    // BFS
    while (front < rear) {
        Node curr = queue[front++];
        int x = curr.x, y = curr.y;
        time = curr.time;

        for (int d = 0; d < 4; d++) {
            int nx = x + directions[d][0];
            int ny = y + directions[d][1];

            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 1) {
                grid[nx][ny] = 2;
                fresh--;
                queue[rear++] = (Node){nx, ny, curr.time + 1};
            }
        }
    }

    return (fresh == 0) ? time : -1;
}
