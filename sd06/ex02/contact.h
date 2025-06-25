#ifndef CONTACT_H
#define CONTACT_H

typedef struct s_contact {
    unsigned int id;
    char *name;
    char *phone;
    char *email;
    char *city;
    char *address;
    struct s_contact *next;
} t_contact;

typedef struct s_contact_manager {
    t_contact *contacts;
    unsigned int max_id;
    unsigned int count;
} t_contact_manager;

#endif