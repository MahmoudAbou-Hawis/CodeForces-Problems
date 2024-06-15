#include <stdio.h>
#include <stdbool.h>

#define MAX_N 30

int n;
int dx[] = {-1, -1, -1,  0, 0,  1, 1, 1};
int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};
int matrix[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

bool valid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

void dfs(int x, int y) {
    visited[x][y] = true;
    int i;
    for (i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (valid(nx, ny) && matrix[nx][ny] == 1 && !visited[nx][ny]) {
            dfs(nx, ny);
        }
    }
}

int main() {
    int cse = 1;

    while (scanf("%d", &n) == 1) {
        int i, j;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                visited[i][j] = false;
                scanf("%1d", &matrix[i][j]);
            }
        }
        int cnt = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (matrix[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n", cse++, cnt);
    }
    return 0;
}
