#include <hand.h>
#include <deckutils.h>

bool
hasAce(Card cards[], int size){
    for(int i = 0; i < size; i++){
        if ((cards[i].number == 14) || (cards[i].number == 1)){
            return 1;
        }
    }
    return 0;
}
bool 
hasPair(Card hand[], int size, Number* number, Number ignored_number){
    sort_deck(hand, size, false);
    for(int j = 0; j < size - 2; ++j){
        if ((hand[j].number != ignored_number) && (hand[j].number == hand[j + 1].number)){
            *number = hand[j].number;
            return 1;
        }
    }
    return 0;
}
bool 
hasTwoPairs(Card hand[], int size){
    Number number;
    return (hasPair(hand, size, &number, InvalidNumber) && hasPair(hand, size, &number, number));
}
bool 
hasThreeOfKind(Card hand[], int size, Number* number){
    int count = 0;
    *number = InvalidNumber;
    sort_deck(hand, size, false);
    for(int j = 0; j < size - 2; ++j){
        if ((hand[j].number == hand[j + 1].number) &&(hand[j + 1].number == hand[j + 2].number)){
            *number = hand[j].number; 
            return 1;
        }
    }
    return 0;
}
bool 
hasStraight(Card hand[], int size){
    sort_deck(hand, size, false);

    for (int i = 0; i < size - 4; i++) {
        if (hand[i].number + 1 == hand[i + 1].number &&
            hand[i + 1].number + 1 == hand[i + 2].number &&
            hand[i + 2].number + 1 == hand[i + 3].number &&
            hand[i + 3].number + 1 == hand[i + 4].number) {
            return 1;
        }
    }

    if (hasAce(hand, size)){
        for (int i = 0; i < size; i++) {
            if (hand[i].number == 14) {
                hand[i].number = (Number)1;
            }
    }
        for (int i = 0; i < size - 4; i++) {
            if (hand[i].number + 1 == hand[i + 1].number &&
                hand[i + 1].number + 1 == hand[i + 2].number &&
                hand[i + 2].number + 1 == hand[i + 3].number &&
                hand[i + 3].number+ 1 == hand[i + 4].number) {
                return 1;    
            }
        }
    }
    return 0;
}
bool
hasFlush(Card hand[], int size){
    sort_deck_by_color(hand, size);
    int count = 0;
    for(int i = 0; i < size; ++i){
        if (i == 0 || hand[i].color == hand[i -1].color){
            count++;
        }
        else{
            count = 0;
        }
        if (count == 5){
            return 1;
        }
    }
    return 0;
}
bool 
hasFullHouse(Card hand[], int size){
    Number number;
    Number ignore;
    if (hasThreeOfKind(hand, size, &number)){
        if (hasPair(hand, size, &ignore, number)){
            return true;
        }
    }
    return false;
}
bool
hasFourOfKind(Card hand[], int size){
    sort_deck(hand, size, false);
    int count = 0;
    for(int i = 0; i < size; ++i){
        if (i == 0 || hand[i].number == hand[i -1].number){
            count++;
        }
        else{
            count = 0;
        }
        if (count == 4){
            return 1;
        }
    }
    return 0;

}
bool 
hasStraightFlush(Card hand[], int size){
    sort_deck(hand, size, false);
    for (int i = 0; i < size - 4; i++) {
        if (hand[i].number + 1 == hand[i + 1].number &&
            hand[i + 1].number + 1 == hand[i + 2].number &&
            hand[i + 2].number + 1 == hand[i + 3].number &&
            hand[i + 3].number + 1 == hand[i + 4].number &&
            hand[i].color + 1 == hand[i + 1].color &&
            hand[i + 1].color + 1 == hand[i + 2].color &&
            hand[i + 2].color + 1 == hand[i + 3].color&&
            hand[i + 3].color + 1 == hand[i + 4].color) {
            return 1;
        }
    }

    if (hasAce(hand, size)){
        for (int i = 0; i < size; i++) {
            if (hand[i].number == 14) {
                hand[i].number = (Number)1;
            }
    }
        for (int i = 0; i < size - 4; i++) {
            if (hand[i].number + 1 == hand[i + 1].number &&
                hand[i + 1].number + 1 == hand[i + 2].number &&
                hand[i + 2].number + 1 == hand[i + 3].number &&
                hand[i + 3].number+ 1 == hand[i + 4].number && 
                hand[i].color + 1 == hand[i + 1].color &&
                hand[i + 1].color + 1 == hand[i + 2].color &&
                hand[i + 2].color + 1 == hand[i + 3].color &&
                hand[i + 3].color+ 1 == hand[i + 4].color) {
                return 1;    
            }
        }
    }
    return 0;
}

HandValues handValue(Card hand[], int size)
{
    return HighCard;
}
