#pragma once
#include <card.h>

typedef enum{Blinds = 0, Pre_Flop = 1, Flop = 2, Turn = 3, River = 4, Show = 5} State;
typedef struct {
	Card hand[2];
	double bet;
} Player;
typedef struct {
	Player *players;
	int total_players;
	Card table[5];
	int out_players;
	int in_players;
	double pot;
	double small_blind;
	double big_blind;
	int cards_on_hand;
	int cards_on_deck;
	int cards_on_table;
	State state;	
} Game;

void create_players(Game* game, int players);
void destroy_players(Game* game);
void print_table(Game* game);
void do_flop(Game* game, Card[]);
void do_turn(Game* game, Card);
void do_river(Game* game, Card);
void set_game_state(Game* game, State state);
void create_new_game(Game* game);
void add_player(Game* game);