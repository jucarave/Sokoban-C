#include <stdio.h>
#include <stdlib.h>
#include "level.h"

void Data_freeLevel(Level *level) {
  free(level);
}

Level *Data_loadLevel(int index) {
  int levelIndex = 1;

  FILE *file = fopen("game.data", "rb");
  if (file == NULL) {
    printf("Error opening the game.data file.\n");
    return NULL;
  }

  Level *level = malloc(sizeof(Level));

  while (levelIndex < index) {
    unsigned char skipLevel;

    fread(&skipLevel, sizeof(skipLevel), 1, file);
    fseek(file, (long) skipLevel, SEEK_CUR);

    levelIndex += 1;
  }

  fseek(file, 1, SEEK_CUR);
  fread(&level->width, sizeof(char), 1, file);
  fread(&level->height, sizeof(char), 1, file);

  fread(&level->playerX, sizeof(char), 1, file);
  fread(&level->playerY, sizeof(char), 1, file);

  fread(&level->boxesCount, sizeof(char), 1, file);

  for (int i = 0; i < level->boxesCount; i++) {
    fread(&level->boxes[i].x, sizeof(char), 1, file);
    fread(&level->boxes[i].y, sizeof(char), 1, file);

    fread(&level->targets[i].x, sizeof(char), 1, file);
    fread(&level->targets[i].y, sizeof(char), 1, file);
  }

  for (int y = 0; y < level->height; y++) {
    fread(&level->data[y], sizeof(char) * level->width, 1, file);
  }

  fclose(file);

  return level;
}