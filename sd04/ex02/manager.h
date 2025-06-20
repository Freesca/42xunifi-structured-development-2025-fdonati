#ifndef MANAGER_H
#define MANAGER_H

#include "contact.h"

int load_contacts(t_contact_manager *manager, const char *filename);
int save_contacts(t_contact_manager *manager, const char *filename);

int is_valid_id(unsigned int id, t_contact_manager *manager);
int is_valid_phone(const char *phone);
int is_valid_email(const char *email);
void trim_whitespace(char **str);

int add_contact(t_contact_manager *manager);
int update_contact(t_contact_manager *manager, unsigned int id);
int delete_contact(t_contact_manager *manager, unsigned int id);

void search_by_name(t_contact_manager *manager, const char *substr);
void search_by_city(t_contact_manager *manager, const char *substr);

void display_menu();
void display_contact(t_contact *contact);
void display_all(t_contact_manager *manager);

#endif