
/*
PROG: ttwo
ID: colindi1
LANG: C++
*/

#include <bits/stdc++.h>
char grid[10][10];

/* delta x, delta y position for moving north, east, south, west */
int deltax[] = {0, 1, 0, -1};
int deltay[] = {-1, 0, 1, 0};

void move(int *x, int *y, int *dir) {
    int nx, ny;

    nx = *x + deltax[*dir];
    ny = *y + deltay[*dir];

    if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10 || grid[ny][nx] == '*')
        *dir = (*dir + 1) % 4;
    else {
        *x = nx;
        *y = ny;
    }
}

int main(void) {
    FILE *fin, *fout;
    char buf[100];
    int i, x, y;
    int cowx, cowy, johnx, johny, cowdir, johndir;

    fin = fopen("ttwo.in", "r");
    fout = fopen("ttwo.out", "w");
    assert(fin != NULL && fout != NULL);

    cowx = cowy = johnx = johny = -1;

    for (y = 0; y < 10; y++) {
        fgets(buf, sizeof buf, fin);
        for (x = 0; x < 10; x++) {
            grid[y][x] = buf[x];
            if (buf[x] == 'C') {
                cowx = x;
                cowy = y;
                grid[y][x] = '.';
            }
            if (buf[x] == 'F') {
                johnx = x;
                johny = y;
                grid[y][x] = '.';
            }
        }
    }

    assert(cowx >= 0 && cowy >= 0 && johnx >= 0 && johny >= 0);

    cowdir = johndir = 0; /* north */

    for (i = 0; i < 160000 && (cowx != johnx || cowy != johny); i++) {
        move(&cowx, &cowy, &cowdir);
        move(&johnx, &johny, &johndir);
    }

    if (cowx == johnx && cowy == johny)
        fprintf(fout, "%d\n", i);
    else
        fprintf(fout, "0\n");
    exit(0);
}
