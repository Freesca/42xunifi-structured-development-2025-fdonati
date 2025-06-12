#ifndef MOVIE_PLANNER_H
#define MOVIE_PLANNER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Preferences {
    char **genres;
    char **directors;
    char **actors;
    int min_rating;
    int max_duration;
} Preferences;

typedef struct Movie {
    char *title;
    char *genre;
    char *director;
    char **cast;
    int rating;
    int duration;
} Movie;

typedef struct MovieList {
    Movie *movies;
    MovieList *next;
} MovieList;

typedef struct Plan {
    MovieList *movies;
    int total_duration;
} Plan;

// Returns user preferences. Returns NULL on failure.
struct Preferences *get_user_preferences(void);

// Returns a list of movies matching the given preferences. Returns NULL on failure.
struct MovieList *find_movies(struct Preferences *prefs);

// Returns a movie night plan from the given list. Returns NULL on failure.
struct Plan *build_plan(struct MovieList *list);

void free_preferences(struct Preferences *prefs);
void free_movies(struct MovieList *list);

struct Plan *create_movie_night_plan(void);

#endif