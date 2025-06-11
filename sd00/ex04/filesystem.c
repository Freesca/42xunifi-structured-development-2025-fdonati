#include "filesystem.h"

FSNode *create_file(const char *name, int size)
{
    FSNode *file = malloc(sizeof(FSNode));
    if (file == NULL)
        return NULL;
    file->name = strdup(name);
    if (file->name == NULL)
        return NULL; // I WANT TO BREAK FREEE
    file->size = size;
    file->parent = NULL;
    file->child = NULL;
    file->sibling = NULL;
    return file;
}

FSNode *create_folder(const char *name)
{
    return create_file(name, 0);
}

void add_child(FSNode *parent, FSNode *child)
{
    FSNode *node;
    if (parent == NULL || child == NULL) {
        return;
    }
    child->parent = parent;
    if (parent->child == NULL)
        parent->child = child;
    else
    {
        node = parent->child;
        while (node->sibling != NULL) {
            node = node->sibling;
        }
        node->sibling = child;
    }
}

FSNode *get_children(const FSNode *parent)
{
    if (parent == NULL)
        return NULL;
    return parent->child;
}

FSNode *get_sibling(const FSNode *node)
{
    if (node == NULL || node->parent == NULL)
        return NULL;
    return node->sibling;
}