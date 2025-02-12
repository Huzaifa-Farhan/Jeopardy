/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#ifndef JEOPARDY_H_
#define JEOPARDY_H_

#include "players.h"
#include "questions.h"

#define MAX_LEN 256

// Processes the answer from the user containing "what is" or "who is" and tokenizes it to retrieve the actual answer.
extern void tokenize(char *input, char **tokens);

// Displays the game results for each player, showing their name and final score, ranked from highest to lowest.
extern void show_results(player *players, int num_players);

// Checks if a given player exists in the game.
extern bool player_exists(player *players, int num_players, char *name);

// Updates the score of a player if they answer correctly.
extern void update_score(player *players, int num_players, char *name, int score);

#endif /* JEOPARDY_H_ */
