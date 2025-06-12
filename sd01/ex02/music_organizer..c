#include "music_organizer.h"


struct MusicLibrary *organize_music_library(const char *directory_path)
{
    struct MusicLibrary *library;
    struct MusicFile *song;
    const char **filenames;

    int i;

    i = 0;

    library = create_music_library();
    if (library == NULL)
        return NULL;

    filenames = scan_directory(directory_path);
    if (filenames == NULL)
    {
        free(library);
        return NULL;
    }

    while (filenames[i] != NULL)
    {
        song = process_music_file(directory_path, filenames[i]);
        if (song == NULL)
            printf("Failed to process file: %s\n", filenames[i]);
        else
        {
            update_music_library(library, song);
            printf("Processed file: %s\n", filenames[i]);
            free_song(song);
        }
        i++;
    }

    free_matrix(filenames);
    return library;
        
}