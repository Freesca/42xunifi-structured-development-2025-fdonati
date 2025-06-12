#include "playlist_creator.h"

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

    mood_variations = get_mood_variations(mood);
    if (mood_variations <= 0)
    {
        printf("Invalid mood variations count: %d\n", mood_variations);
        free_mood_settings(mood);
        free_filter_settings(filters);
        return NULL;
    }

        
        
}