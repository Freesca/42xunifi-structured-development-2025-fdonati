#include "movie_planner.h"

struct Plan *create_movie_night_plan(void)
{
    int i;
    int num_people;
    struct Preferences *preferences;
    struct MovieList *movies;
    struct Plan *plan;

    i = 0;
    preferences = NULL;
    movies = NULL;
    plan = NULL;
    printf("Welcome to the Movie Night Planner!\n");
    printf("How many are you?\n");

    scanf("%d", &num_people);
    if (num_people <= 0)
    {
        printf("Invalid number of people.\n");
        return NULL;
    }

    while (i < num_people)
    {
        preferences = get_user_preferences();
        if (preferences == NULL)
        {
            printf("Failed to get user preferences.\n");
            return NULL;
        }
        movies = find_movies(preferences);
        if (movies == NULL)
        {
            printf("No movies found for the given preferences.\n");
            return NULL;
        }
        free_preferences(preferences);
    }

    plan = build_plan(movies);
    free_movies(movies);
    if (plan == NULL)
    {
        printf("Failed to build movie night plan.\n");
        return NULL;
    }
    printf("Movie night plan created successfully!\n");
    return plan;
}

