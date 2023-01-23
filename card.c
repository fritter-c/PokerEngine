#include <card.h>
#include <stdlib.h>
#include <string.h>

const char* CARD_NAME_SEPARATOR = "_Of_";
const int SEPARATOR_SIZE = 4;
const int COLORS = 4;
const int NUMBERS = 14;
const Number INVALID_NUMBER = InvalidNumber;
const Color INVALID_COLOR = InvalidColor;

// Returns the color string and size without de null char
const char* color_to_string(Color color){
    switch (color)
    {
    case 0:
        return "Hearts";
        break;
    case 1:
        return "Spades";
        break;
    case 2:
        return "Diamonds";
        break;
    case 3:
        return "Clubs";
        break;
    
    default:
        return "Invalid";
        break;
    }
}

// Returns the number string and size without de null char
const char* number_to_string(Number number){
    switch (number)
    {
    case 14:
        return "Ace";
        break;
    case 2:
        return "Two";
        break;
    case 3:
        return "Three";
        break;
    case 4:
        return "Four";
        break;
    case 5:
        return "Five";
        break;
    case 6:
        return "Six";
        break;
    case 7:
        return "Seven";
        break;
    case 8:
        return "Eight";
        break;
    case 9:
        return "Nine";
        break;
    case 10:
        return "Ten";
        break;
    case 11:
        return "Jack";
        break;
    case 12:
        return "Queen";
        break;
    case 13:
        return "King";
        break;
    default:
        return "Invalid";
        break;
    }
}
Card card_constructor(Color new_color, Number new_number){
    Card card = {.color = new_color, .number = new_number};
    return card;
}
void card_destructor(Card card){
    card.color = InvalidColor;
    card.number = InvalidNumber;
}
