/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Define constants
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Function prototypes
void tokenize(char *input, char **tokens);
void show_results(player *players, int num_players);

int main(int argc, char *argv[])
{
    // Array of players
    player players[NUM_PLAYERS];

    // Input buffer
    char buffer[BUFFER_LEN];

    // Display the game introduction
    printf("Welcome to Jeopardy!\n");

    // Initialize game questions
    initialize_game();

    // Prompt for player names
    for (int i = 0; i < NUM_PLAYERS; i++)
    {
        printf("Enter player %d's name: ", i + 1);
        fgets(players[i].name, BUFFER_LEN, stdin);
        players[i].name[strcspn(players[i].name, "\n")] = '\0'; // Remove newline character
        players[i].score = 0; // Initialize score to 0
    }

    // Game loop: continues until all questions are answered
    while (1)
    {
        display_categories(); // Show available categories and question values

        // Get player selection
        printf("Enter player's name to pick a question: ");
        fgets(buffer, BUFFER_LEN, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline

        if (!player_exists(players, NUM_PLAYERS, buffer))
        {
            printf("Invalid player name. Try again.\n");
            continue;
        }

        char category[BUFFER_LEN];
        int value;

        // Get category
        printf("Enter category: ");
        fgets(category, BUFFER_LEN, stdin);
        category[strcspn(category, "\n")] = '\0';

        // Get question value
        printf("Enter question value: ");
        scanf("%d", &value);
        getchar(); // Consume the newline character left by scanf

        // Check if question is already answered
        if (already_answered(category, value))
        {
            printf("This question has already been answered. Pick another.\n");
            continue;
        }

        display_question(category, value); // Show the selected question

        // Get answer from player
        printf("Enter your answer (must start with 'what is' or 'who is'): ");
        fgets(buffer, BUFFER_LEN, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        // Tokenize the answer
        char *tokens[BUFFER_LEN];
        tokenize(buffer, tokens);

        // Check if answer is correct
        if (valid_answer(category, value, tokens[2])) // Assuming tokens[2] contains the answer
        {
            printf("Correct!\n");
            update_score(players, NUM_PLAYERS, value);
            player *players, int num_players, char *name, int score
        }
        else
        {
            printf("Incorrect! The correct answer was: %s\n", get_correct_answer(category, value));
        }

        // Check if all questions have been answered
        if (all_questions_answered())
        {
            printf("\nGame Over!\n");
            break;
        }
    }

    // Display final results
    show_results(players, NUM_PLAYERS);
    return EXIT_SUCCESS;
}
