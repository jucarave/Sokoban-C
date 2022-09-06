#include <stdio.h>
#include <stdlib.h>
#include "movement.h"

#define MAX_HISTORY_SIZE 100

struct Node {
  struct Node *next;
  Movement *value;
};

typedef struct Node MovementNode;

static MovementNode *history;
static int size = 0;

Movement *Movement_create(int xTo, int yTo, Box *box) {
  Movement *movement = malloc(sizeof(MovementNode));

  movement->xTo = xTo;
  movement->yTo = yTo;
  movement->box = box;

  return movement;
}

void Movement_clearList() {
  if (history == NULL) {
    return;
  }

  MovementNode *node = history;
  MovementNode *next = node->next;

  free(node->value);
  free(node);

  while (next != NULL) {
    node = next;
    next = node->next;

    free(node->value);
    free(node);
  }

  size = 0;
  history = NULL;
}

void Movement_clearTop() {
  if (history == NULL) {
    return;
  }

  MovementNode *next = history->next;

  free(history->value);
  free(history);

  size -= 1;
  history = next;
}

void Movement_add(int xTo, int yTo, Box *box) {
  MovementNode *newNode = malloc(sizeof(MovementNode));
  newNode->value = Movement_create(xTo, yTo, box);
  newNode->next = NULL;

  if (history != NULL) {
    MovementNode *node = history;
    while (node->next != NULL) {
      node = node->next;
    }

    node->next = newNode;
  } else {
    history = newNode;
  }

  size += 1;

  if (size >= MAX_HISTORY_SIZE) {
    Movement_clearTop();
  }
}

void Movement_removeLast() {
  if (history == NULL) {
    return;
  }

  MovementNode *prev = NULL;
  MovementNode *node = history;

  while (node->next != NULL) {
    prev = node;
    node = node->next;
  }

  if (prev != NULL) {
    prev->next = NULL;
  } else {
    history = NULL;
  }

  free(node->value);
  free(node);

  size -= 1;
}

Movement *Movement_getLast() {
  if (history == NULL) {
    return NULL;
  }

  MovementNode *node = history;

  while (node->next != NULL) {
    node = node->next;
  }

  return node->value;
}