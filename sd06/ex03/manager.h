#ifndef MANAGER_H
#define MANAGER_H

#include "movie.h"

int load_watchlist(t_watchlist *wl, const char *filename);
int save_watchlist(t_watchlist *wl, const char *filename);

int is_valid_id(unsigned int id, t_watchlist *wl);
int is_valid_watched_flag(int watched);
int is_valid_rating(int rating, int watched);
int is_valid_date(const char *date, int watched);

int add_movie(t_watchlist *wl);
int update_movie(t_watchlist *wl, unsigned int id);
int delete_movie(t_watchlist *wl, unsigned int id);
int mark_watched(t_watchlist *wl, unsigned int id);

void search_by_title(t_watchlist *wl, const char *substr);
void search_by_genre(t_watchlist *wl, const char *substr);
void filter_by_status(t_watchlist *wl, int watched);

void update_stats(t_watchlist *wl);
void display_stats(t_watchlist *wl);

void display_menu();
void display_movie(t_movie *movie);
void display_all(t_watchlist *wl);

#endif