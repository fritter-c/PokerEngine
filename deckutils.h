#pragma once

#include <stdio.h>
#include<stdbool.h>
#include <stdlib.h>
#include <card.h>
#include <string.h>
static const int DECK_SIZE = 52;

inline const void build_std_deck(Card* deck) {
    int k = 0;
    for (int i = 0; i < COLORS; i++) {
        for (int j = 2; j <= NUMBERS; j++) {
            deck[k] = card_constructor((Color)i, (Number)j);
            k++;
        }
    }
}
inline void print_std_deck(Card* deck) {
    for (int i = 0; i < DECK_SIZE; ++i) {
        char name[20] = {'\0'};
        const char* color = color_to_string(deck[i].color);
        const char* number = number_to_string(deck[i].number);

        strcat_s(name,20, color);
        strcat_s(name,20, CARD_NAME_SEPARATOR);
        strcat_s(name,20, number);
        printf("%s\n", name);
    }
}

inline void print_deck(Card* deck, int size) {
    for (int i = 0; i < size; ++i) {
        char name[20] = { '\0' };
        const char* color = color_to_string(deck[i].color);
        const char* number = number_to_string(deck[i].number);

        strcat_s(name, 20, color);
        strcat_s(name, 20, CARD_NAME_SEPARATOR);
        strcat_s(name, 20, number);
        printf("%s\n", name);
    }
}



inline void sort_deck(Card* deck, int size, bool reversed) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if ((!reversed) && (deck[i].number > deck[j].number)) {
                Card temp = deck[i];
                deck[i] = deck[j];
                deck[j] = temp;
            }
            else if ((reversed) && (deck[i].number < deck[j].number)) {
                Card temp = deck[i];
                deck[i] = deck[j];
                deck[j] = temp;
            }
        }
    }
}

inline void sort_deck_by_color(Card* deck, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (deck[i].color > deck[j].color) {
                Card temp = deck[i];
                deck[i] = deck[j];
                deck[j] = temp;
            }
        }
    }
}

inline void create_invalid_deck(Card* deck, int size) {
    for (int i = 0; i < size; ++i) {
        deck[i] = card_constructor(InvalidColor, InvalidNumber);
    }
}

inline void swap_card(Card* A, Card* B)
{
    *A = *B;
}