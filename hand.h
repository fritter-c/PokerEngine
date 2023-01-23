#pragma once
#include <card.h>
#include <stdbool.h>

bool hasAce(Card cards[], int size);
bool hasPair(Card hand[], int size, Number* number, Number ignored_number);
bool hasTwoPairs(Card hand[], int size);
bool hasThreeOfKind(Card hand[], int size, Number* number);
bool hasStraight(Card hand[], int size);
bool hasFlush(Card hand[], int size);
bool hasFullHouse(Card hand[], int size);
bool hasFourOfKind(Card hand[], int size);
bool hasStraightFlush(Card hand[], int size);

typedef enum
HandValues {
    HighCard = 0,
    Pair = 1,
    TwoPairs = 2,
    ThreeOfKind = 3,
    Straight = 4,
    Flush = 5,
    FullHouse = 6,
    FourOfKind = 7,
    StraightFlush = 8
} HandValues;

HandValues handValue(Card hand[], int size);