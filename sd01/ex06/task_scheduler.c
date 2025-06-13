#include "task_scheduler.h"

struct ScheduleResult *schedule_tasks(struct TaskList *tasks)
{
    struct TaskProfile *profile;
    struct PriorityMap *priorities;
    struct ScheduleResult *result;
    int core_count;
    int task_id;

    //Profile the provided task list to evaluate load and I/O patterns
    profile = profile_tasks(tasks);
    if (!profile)
    {
        perror("Failed to profile tasks");
        return NULL; // Failed to profile tasks
    }

    //Compute scheduling priorities for each task
    priorities = compute_priorities_mock(profile);
    if (!priorities)
    {
        perror("Failed to compute priorities");
        free_task_profile(profile);
        return NULL; // Failed to compute priorities
    }

    core_count = get_available_core_count();
    if (core_count <= 0)
    {
        perror("No available CPU cores");
        free_task_profile(profile);
        free_priority_map(priorities);
        return NULL; // No available CPU cores
    }
    //Create a schedule result structure for the available cores
    result = create_schedule_result(core_count);
    if (!result)
    {
        perror("Failed to create schedule result");
        free_task_profile(profile);
        free_priority_map(priorities);
        return NULL; // Failed to create schedule result
    }
    //Iteratively select the best task and assign it to a core until no tasks remain
    while ((task_id = select_best_task(profile, priorities)) != -1)
    {
        int core_id = task_id % core_count; // Simple round-robin assignment
        update_schedule_entry(result, core_id, task_id);
    }
    //Free allocated resources
    free_task_profile(profile);
    free_priority_map(priorities);
    return result; // Return the final schedule result

}