#ifndef BOOK_H
#define BOOK_H

typedef struct s_book {
    int id;
    char *title;
    char *author;
    struct s_book *next;
} t_book;

#endif