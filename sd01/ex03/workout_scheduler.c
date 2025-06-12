#include "workout_scheduler.h"

struct WorkoutPlan *create_workout_schedule(char *username)
{
    struct UserData *data;
    struct WorkoutPlan *plan;
    int duration;
    int day;

    data = get_user_data(username);
    if (data == NULL)
    {
        printf("Failed to retrieve user data for %s.\n", username);
        return NULL;
    }

    plan = build_base_plan(data);
    if (plan == NULL)
    {
        printf("Failed to build base workout plan for %s.\n", username);
        free_user_data(data);
        return NULL;
    }

    duration = determine_duration(plan);
    if (duration <= 0)
    {
        printf("Invalid workout duration for %s.\n", username);
        free_workout_plan(plan);
        free_user_data(data);
        return NULL;
    }

    plan->duration = duration;

    for (day = 0; day < duration; day++)
    {
        assign_daily_exercises(plan, day);
        assign_daily_tips(plan, day);
    }

    plan = refine_plan(plan, data);
    
    free_user_data(data);

    if (plan == NULL)
    {
        printf("Failed to refine workout plan for %s.\n", username);
        return NULL;
    }

    printf("Workout schedule created successfully for %s!\n", username);
    
    return plan;
    
}