// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train(): countOp(0), first(nullptr) {}

void Train::addCage(bool light) {
    if (first != nullptr) {
        Cage* dark;
        dark = new Cage;
        dark->light = light;
        dark->next = nullptr;
        dark->prev = last;
        last->next = dark;
        last = dark;
    } else {
        first = new Cage;
        first->light = light;
        first->next = nullptr;
        first->prev = nullptr;
        last = first;
        return;
    }
}
int Train::getLength() {
        first->light = true;
        first->prev = last;
        last->next = first;
        Cage* ctemp = first;
        Cage* square = first->next;
        while (square != nullptr) {
            if (!square->light) {
                count++;
                countOp++;
                square = square->next;
            } else {
                if (square->light) {
                        square->light = 0;
                    countOp++;
                }
                for (int i = count; i > 0; i--) {
                    square = square->prev;
                    countOp++;
                }
                if (!square->light) {
                    break;
                }
                square = square->next;
                count = 1;
            }
        }
        return count;
    }
int Train::getOpCount() {
  return countOp;
}
        
