#pragma once
typedef enum { InvalidColor = -1, Hearts = 0, Spade = 1, Diamonds = 2, Clubs = 3 } Color;
typedef enum { InvalidNumber = -1, Two = 2, Three = 3, Four = 4, Five = 5, Six = 6, Seven = 7, Eight = 8, Nine = 9, Ten = 10, Jack = 11, Queen = 12, King = 13, Ace = 14 } Number;


extern const char* CARD_NAME_SEPARATOR;
extern const int SEPARATOR_SIZE;

extern const int COLORS;
extern const int NUMBERS;

extern const Number INVALID_NUMBER;
extern const Color INVALID_COLOR;

const char* color_to_string(Color color);
const char* number_to_string(Number number);

typedef struct {
    Color color;
    Number number;
} Card;
Card card_constructor(Color new_color, Number new_number);
void card_destructor(Card card);