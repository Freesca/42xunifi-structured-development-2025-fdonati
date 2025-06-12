#ifndef MUSIC_ORGANIZER_H
#define MUSIC_ORGANIZER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct MusicFile {
    char *filename;
    char *title;
    char *artist;
    char *album;
    char *genre;
    int year;
    int track_number;
    int duration;
} MusicFile;

typedef struct MusicLibrary {
    MusicFile **songs;
    int song_count;
} MusicLibrary;

// Creates and returns a new music library. Returns NULL on fail
struct MusicLibrary *create_music_library();

// Scans a directory for music files. Returns a NULL terminated array of filenames.
const char **scan_directory(const char *directory_path);

// Processes a single music file. Returns a data structure representing the processed file.
struct MusicFile *process_music_file(const char *directory_path, const char *filename);

// Updates the music library with the processed music file information.
void update_music_library(struct MusicLibrary *library, struct MusicFile *song);

free_song(struct MusicFile *song);
free_matrix(const char **matrix);

struct MusicLibrary *organize_music_library(const char *directory_path);

#endif