// Copyright 2021 NNTU-CS
#include "train.h"

void Train::addCage(bool light) {
  if (!first) {
    Cage* item = new Cage;
    item->light = light;
    first = item;
    last = item;
  } else {
    Cage* item = new Cage;
    item->light = light;
    last->next = item;
    item->prev = last;
    last = item;
  }
  last->next = first;
  first->prev = last;
}

int Train::getLength() {
  Cage* temp = first;
  temp->light = true;
  while (true) {
    temp = temp->next;
    count1++;
    if (temp->light) {
      temp->light = false;
      for (int i = count1; i > 0; i--) {
        temp = temp->prev;
      }
      countOp += count1 * 2;
      if (!temp->light) {
        return count1;
      }
      count1 = 0;
    }
  }
  return 0;
}
int Train::getOpCount() {
  return countOp;
}
