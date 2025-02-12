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
#include "questions.h"
#include <strings.h>


// Initializes the array of questions for the game
void initialize_game(void)
{
    int index = 0;

    // Programming Category
    strcpy(questions[index].category, "programming");
    strcpy(questions[index].question, "Which programming language is known for its readability and indentation rules?");
    strcpy(questions[index].answer, "Python");
    questions[index].value = 100;
    questions[index].answered = false;
    index++;

    strcpy(questions[index].category, "programming");
    strcpy(questions[index].question, "Which language is commonly used for system programming and embedded systems?");
    strcpy(questions[index].answer, "C");
    questions[index].value = 200;
    questions[index].answered = false;
    index++;

    strcpy(questions[index].category, "programming");
    strcpy(questions[index].question, "Which programming paradigm is based on objects and classes?");
    strcpy(questions[index].answer, "OOP");
    questions[index].value = 300;
    questions[index].answered = false;
    index++;

    strcpy(questions[index].category, "programming");
    strcpy(questions[index].question, "Which language is primarily used for web development and runs in the browser?");
    strcpy(questions[index].answer, "JavaScript");
    questions[index].value = 400;
    questions[index].answered = false;
    index++;

    // Algorithms Category
    strcpy(questions[index].category, "algorithms");
    strcpy(questions[index].question, "What algorithm is used to sort an array by repeatedly dividing it into two halves?");
    strcpy(questions[index].answer, "Merge Sort");
    questions[index].value = 100;
    questions[index].answered = false;
    index++;

    strcpy(questions[index].category, "algorithms");
    strcpy(questions[index].question, "Which algorithm finds the shortest path in a weighted graph?");
    strcpy(questions[index].answer, "Dijkstra");
    questions[index].value = 200;
    questions[index].answered = false;
    index++;

    strcpy(questions[index].category, "algorithms");
    strcpy(questions[index].question, "What data structure is used in a Breadth-First Search (BFS)?");
    strcpy(questions[index].answer, "Queue");
    questions[index].value = 300;
    questions[index].answered = false;
    index++;

    strcpy(questions[index].category, "algorithms");
    strcpy(questions[index].question, "Which algorithm uses a divide-and-conquer strategy and picks a pivot?");
    strcpy(questions[index].answer, "Quick Sort");
    questions[index].value = 400;
    questions[index].answered = false;
    index++;

    // Databases Category
    strcpy(questions[index].category, "databases");
    strcpy(questions[index].question, "Which language is used to query relational databases?");
    strcpy(questions[index].answer, "SQL");
    questions[index].value = 100;
    questions[index].answered = false;
    index++;

    strcpy(questions[index].category, "databases");
    strcpy(questions[index].question, "What type of database stores data as JSON-like documents?");
    strcpy(questions[index].answer, "NoSQL");
    questions[index].value = 200;
    questions[index].answered = false;
    index++;

    strcpy(questions[index].category, "databases");
    strcpy(questions[index].question, "Which normalization form removes partial dependencies?");
    strcpy(questions[index].answer, "2NF");
    questions[index].value = 300;
    questions[index].answered = false;
    index++;

    strcpy(questions[index].category, "databases");
    strcpy(questions[index].question, "Which SQL command is used to remove all records from a table but keep the structure?");
    strcpy(questions[index].answer, "TRUNCATE");
    questions[index].value = 400;
    questions[index].answered = false;
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    printf("\nAvailable Categories & Question Values:\n");
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (!questions[i].answered) {
            printf("%s - $%d\n", questions[i].category, questions[i].value);
        }
    }
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            if (questions[i].answered) {
                printf("Question already answered!\n");
            } else {
                printf("\n%s ($%d): %s\n", questions[i].category, questions[i].value, questions[i].question);
            }
            return;
        }
    }
    printf("Invalid category or value!\n");
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            if (strcasecmp(questions[i].answer, answer) == 0) {  // Case insensitive comparison
                questions[i].answered = true;  // Mark question as answered
                return true;
            }
        }
    }
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            return questions[i].answered;
        }
    }
    return false;
}


// Function to get the correct answer for a question
char* get_correct_answer(char *category, int value) {
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            return questions[i].answer;
        }
    }
    return "Unknown"; // Return a default value if no match is found
}

// Function to check if all questions have been answered
bool all_questions_answered() {
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (!questions[i].answered) {
            return false; // Found an unanswered question
        }
    }
    return true; // All questions have been answered
}
