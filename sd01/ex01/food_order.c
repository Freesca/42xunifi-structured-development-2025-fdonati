#include "food_order.h"


int process_food_order(struct OrderRequest *request)
{
    int is_open;
    struct OrderConfirmation *confirmation;
    is_open = 0;
    confirmation = NULL;

    if (request == NULL || request->restaurant_name == NULL || request->order_items == NULL)
    {
        return -1; // Invalid request
    }
    is_open = check_restaurant_status(request);
    if (!is_open)
        confirmation = create_preorder_confirmation();
    else
        confirmation = create_standard_confirmation();
    if (confirmation == NULL)
        return 0;
    send_confirmation_notification(confirmation);
    free_confermation(confirmation);
    return 1;
}