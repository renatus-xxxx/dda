#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH  31
#define HEIGHT 25

void drawline(int x0, int y0, int x1, int y1, int screen[HEIGHT][WIDTH]) {
  int dx = x1 - x0;
  int dy = y1 - y0;

  int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

  float xinc = dx / (float) steps;
  float yinc = dy / (float) steps;

  float x = x0;
  float y = y0;
  int i;
  for(i = 0; i <= steps; i++) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
      screen[(int)round(y)][(int)round(x)] = 1;
    x += xinc;
    y += yinc;
  }
}

int main(int argc, char *argv[]) {
  if(argc != 3) {
    printf("usage: dda x y\n");
    return 1;
  }

  int x1 = atoi(argv[1]);
  int y1 = atoi(argv[2]);

  if(x1 < 0 || x1 >= WIDTH || y1 < 0 || y1 >= HEIGHT) {
    printf("Coordinates out of bounds (0-31 for x and 0-25 for y)\n");
    return 1;
  }

  static int screen[HEIGHT][WIDTH];
  for(int i = 0; i < HEIGHT; i++){
    for(int j = 0; j < WIDTH; j++){
      screen[i][j] = 0;
    }
  }

  drawline(15, 13, x1, y1, screen);

  int y;
  for (y = 0; y < HEIGHT; y++) {
    int x;
    for (x = 0; x < WIDTH; x++) {
      printf("%d", screen[y][x]);
    }
    printf("\n");
  }

  return 0;
}