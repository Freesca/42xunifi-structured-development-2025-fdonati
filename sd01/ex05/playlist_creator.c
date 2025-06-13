#include "playlist_creator.h"

struct SongData *fetch_song_on_filters(struct FilterSettings *filters)
{
    struct SongData *song;

    if (filters == NULL)
    {
        printf("No filters provided.\n");
        return NULL;
    }

    if (filters_require_popular_song(filters))
    {
        song = fetch_popular_song();
        if (song == NULL)
        {
            printf("Failed to fetch a popular song based on filters.\n");
            return NULL;
        }
    }
    else
    {
        song = fetch_niche_song();
        if (song == NULL)
        {
            printf("Failed to fetch a niche song based on filters.\n");
            return NULL;
        }
    }
    
    return song;
}

struct FilterSettings *refine_filters_on_mood(struct MoodSettings *mood, struct FilterSettings *filters)
{
    int mood_variations;
    
    mood_variations = get_mood_variations(mood);
    if (mood_variations < 0)
    {
        printf("Failed to get mood variations.\n");
        return NULL;
    }
    for(int i = 0; i < mood_variations; i++)
    {
        filters = refine_filters(filters);
        if (filters == NULL)
        {
            printf("Failed to refine filters.\n");
            return NULL;
        }
    }
    return filters;
}

struct Playlist *create_playlist(void)
{
    struct MoodSettings *mood;
    struct FilterSettings *filters;
    struct SongData *song;
    struct Playlist *playlist;
    int mood_variations;

    mood_variations = 0;
    mood = analyze_user_mood();
    if (mood == NULL)
    {
        printf("Failed to analyze user mood.\n");
        return NULL;
    }
    
    filters = default_filters();
    if (filters == NULL)
    {
        printf("Failed to get default filter settings.\n");
        free_mood_settings(mood);
        return NULL;
    }

    filters = refine_filters_on_mood(mood, filters);
    if (filters == NULL)
    {
        printf("Failed to refine filter settings.\n");
        free_mood_settings(mood);
        free_filter_settings(filters);
        return NULL;
    }

    song = fetch_song_on_filters(filters);
    if (song == NULL)
    {
        printf("Failed to fetch song based on filters.\n");
        free_mood_settings(mood);
        free_filter_settings(filters);
        return NULL;
    }

    playlist = combine_with_mood_playlist(song, mood);
    if (playlist == NULL)
        printf("Failed to combine song with mood playlist.\n");
    free_mood_settings(mood);
    free_filter_settings(filters);
    free_song_data(song);
    return playlist;

        
        
}