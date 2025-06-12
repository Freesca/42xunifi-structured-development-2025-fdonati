#include "recipe_generator.h"

struct Recipe *create_custom_recipe(void)
{
    struct Ingredients *ingredients;
    struct TasteProfile *taste;
    struct Recipe *recipe;
    int approved;

    approved = 0;
    ingredients = get_current_ingredients();
    if (ingredients == NULL)
    {
        printf("Failed to retrieve current ingredients.\n");
        return NULL;
    }

    taste = get_user_taste_profile();
    if (taste == NULL)
    {
        printf("Failed to retrieve user taste profile.\n");
        free_ingredients(ingredients);
        return NULL;
    }

    while (!approved)
    {
        recipe = create_recipe(ingredients, taste);
        if (recipe == NULL)
        {
            printf("Failed to create recipe with current ingredients and taste profile.\n");
            free_ingredients(ingredients);
            free_taste_profile(taste);
            return NULL;
        }

        approved = get_user_approval(recipe);
    }
    free_ingredients(ingredients);
    free_taste_profile(taste);
    return recipe;
            
}