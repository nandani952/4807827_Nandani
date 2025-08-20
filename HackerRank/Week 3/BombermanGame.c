#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** createGrid(int r, int c, char fillChar) {
    char** newGrid = malloc(r * sizeof(char*));
    for (int i = 0; i < r; i++) {
        newGrid[i] = malloc((c + 1) * sizeof(char));
        for (int j = 0; j < c; j++) {
            newGrid[i][j] = fillChar;
        }
        newGrid[i][c] = '\0';
    }
    return newGrid;
}

void freeGrid(char** grid, int r) {
    if (grid == NULL) return;
    for (int i = 0; i < r; i++) {
        free(grid[i]);
    }
    free(grid);
}

char** detonateBombs(int r, int c, char** currentGrid) {
    char** detonateGrid = createGrid(r, c, 'O');

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (currentGrid[i][j] == 'O') {
                detonateGrid[i][j] = '.';
                if (i > 0) detonateGrid[i - 1][j] = '.';
                if (i < r - 1) detonateGrid[i + 1][j] = '.';
                if (j > 0) detonateGrid[i][j - 1] = '.';
                if (j < c - 1) detonateGrid[i][j + 1] = '.';
            }
        }
    }
    return detonateGrid;
}

char** bomberMan(int n, int grid_count, char** grid, int* result_count) {
    *result_count = grid_count;
    int r = grid_count;
    int c = strlen(grid[0]);

    if (n <= 1) {
        char** result = createGrid(r, c, ' ');
        for (int i = 0; i < r; i++) {
            strcpy(result[i], grid[i]);
        }
        return result;
    }

    if (n % 2 == 0) {
        return createGrid(r, c, 'O');
    }
    
    char** tempGrid = createGrid(r, c, ' ');
    for (int i = 0; i < r; i++) {
        strcpy(tempGrid[i], grid[i]);
    }

    if (n % 4 == 3) {
        char** finalGrid = detonateBombs(r, c, tempGrid);
        freeGrid(tempGrid, r);
        return finalGrid;
    }

    if (n % 4 == 1) {
        char** firstDetonation = detonateBombs(r, c, tempGrid);
        freeGrid(tempGrid, r);
        char** finalGrid = detonateBombs(r, c, firstDetonation);
        freeGrid(firstDetonation, r);
        return finalGrid;
    }
    return NULL;
}
int main() {
    int r, c, n;
    scanf("%d %d %d", &r, &c, &n);

    char** grid = malloc(r * sizeof(char*));
    for (int i = 0; i < r; i++) {
        grid[i] = malloc((c + 1) * sizeof(char));
        scanf("%s", grid[i]);
    }

    int result_count;
    char** result = bomberMan(n, r, grid, &result_count);

    for (int i = 0; i < result_count; i++) {
        printf("%s\n", result[i]);
    }
    freeGrid(grid, r);
    freeGrid(result, result_count);

    return 0;
}
