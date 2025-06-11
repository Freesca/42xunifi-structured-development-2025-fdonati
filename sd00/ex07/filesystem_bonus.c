#include "filesystem.h"

int compute_total_size(FSNode *node)
{
    int size;
    FSNode *child;

    size = 0;
    size += node->size; 
    child = node->child;
    while (child != NULL)
    {
        size += compute_total_size(child);
        child = child->sibling;
    }
    return size;
}

void print_structure(const FSNode *node, int indent)
{

    FSNode *child;
    int i;

    i = 0;
    if (node == NULL)
        return;

    /* printf("indent: %d\n", indent); */
    while (i < indent)
    {
        printf(" ");
        i++;
    }
    printf("%s", node->name);
    if (node->size > 0)
        printf(" (%d bytes)", node->size);
    printf("\n");
    child = node->child;
    while (child != NULL)
    {
        print_structure(child, indent + (indent / 2));
        child = child->sibling;
    }
    
}

void free_filesystem(FSNode *node)
{
    FSNode *child;
    FSNode *sibling;

    if (node == NULL)
        return;
    child = node->child;
    if (child != NULL)
        free_filesystem(child);
    sibling = node->sibling;
    if (sibling != NULL)
        free_filesystem(sibling);
    free(node->name);
    free(node);
}

int main()
{
    FSNode *root = create_folder("root");
    FSNode *file0_0 = create_file("file0_0", 100);
    FSNode *file0_1 = create_file("file0_1", 200);
    FSNode *folder0_2 = create_folder("subfolder0_2");
    FSNode *folder0_3 = create_folder("subfolder0_3");
    add_child(root, file0_0);
    add_child(root, file0_1);
    add_child(root, folder0_2);
    add_child(root, folder0_3);
    FSNode *file2_0 = create_file("file2_0", 300);
    FSNode *folder2_1 = create_folder("subfolder2_1");
    FSNode *folder2_2 = create_folder("subfolder2_2");
    add_child(folder0_2, file2_0);
    add_child(folder0_2, folder2_1);
    add_child(folder0_2, folder2_2);
    FSNode *file2_2_0 = create_file("file2_2_0", 400);
    FSNode *folder2_2_1 = create_folder("subfolder2_2_1");
    FSNode *folder2_2_2 = create_folder("subfolder2_2_2");
    add_child(folder2_2, file2_2_0);
    add_child(folder2_2, folder2_2_1);
    add_child(folder2_2, folder2_2_2);
    FSNode *file2_2_1_0 = create_file("file2_2_1_0", 600);
    add_child(folder2_2_1, file2_2_1_0);
    FSNode *file3_0 = create_file("file3_0", 500);
    FSNode *folder3_1 = create_folder("subfolder3_1");
    add_child(folder0_3, file3_0);
    add_child(folder0_3, folder3_1);

    print_structure(root, 10);
    printf("Total size: %d bytes\n", compute_total_size(root));
    free_filesystem(root);
    return 0;
}