#include <stdio.h>
#include <stdbool.h>
#include <deckutils.h>
#include <hand.h>
#include <game.h>

Card g_deck[52];
Player g_me;
Game* g_game = NULL;


int main(){
    
    build_std_deck(g_deck);
    print_std_deck(g_deck);
    while (true) {

        printf("new game?(y/n)\n");
        char a;
        if (scanf("%c", &a) == 'y') {
            if (g_game)
                free(g_game);
            g_game = (Game*)malloc(sizeof(Game));
            printf("set number of players:\n");

        }
        break;
    }

    
    return 0;
}