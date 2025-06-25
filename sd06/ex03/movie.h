#ifndef MOVIE_H
#define MOVIE_H

typedef struct s_movie {
    unsigned int id;
    char *title;
    char *genre;
    unsigned char watched;
    unsigned char rating;
    char watch_date[11];
    struct s_movie *next;
} t_movie;

typedef struct s_watchlist {
    t_movie *movies;
    unsigned int max_id;
    unsigned int count;
    struct {
        unsigned int watched;
        unsigned int unwatched;
        float avg_rating;
    } stats;
} t_watchlist;

#endif