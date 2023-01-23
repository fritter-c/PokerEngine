#include <game.h>
#include <deckutils.h>
#include <stdlib.h>

void create_players(Game* game, int players) {
	game->total_players = players;
	game->players = (Player*)malloc(players * sizeof(Player));
}
void destroy_players(Game* game) {
	free(game->players);
	game->players = NULL;
	game->total_players = 0;
}
void print_table(Game* game) {
	print_deck(game->table, 5);
}
void do_flop(Game* game, Card card[])
{
	game->state = Flop;
	for (int i = 0; i < 3; ++i) {
		game->table[i] = card[i];
	}
}
void do_turn(Game* game, Card card)
{
	game->state = Turn;
	game->table[4] = card;
}
void do_river(Game* game, Card card)
{
	game->state = River;
	game->table[4] = card;
}
void set_game_state(Game* game, State state) {
	if (game->state != state) {
		game->state = state;
	}

}
void create_new_game(Game* game) {
	game = (Game*)malloc(sizeof(Game));
	if (game) {
		game->total_players = 0;
		game->state = Pre_Flop;
		game->in_players = 0;
		game->out_players = 0;
		game->players = NULL;
	}
}

void add_player(Game* game)
{
	game->total_players++;
	int s = realloc(game->players, game->total_players * sizeof(Player));
}
