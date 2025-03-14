/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U: Operating Systems
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "players.h"

// Returns true if the player name matches one of the existing players
bool player_exists(player *players, int num_players, char *name)
{

    for (int i = 0; i < num_players; i++) {

        if (strcmp(players[i].name, name) == 0){
            
            // Player found
            return true;
        }

    }

    return false;
}


// Go through the list of players and update the score for the 
// player given their name
void update_score(player *players, int num_players, char *name, int score)
{


    
    for (int i = 0; i < num_players; i++){

        if (strcmp(players[i].name, name) == 0) {

            // Update score when player found
            players[i].score = players[i].score + score;
        }

    }

}
