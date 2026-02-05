#ifndef SHOP_C_H
#define SHOP_C_H

#include <stdbool.h>

// Type alias (and forward declaration): allows using 'Shop' instead of 'struct Shop'
typedef struct Shop Shop;

// Abstract class in C (interface)
struct Shop {
    void (*destroy)(Shop* self);
    
    void (*add_items)(Shop* self, int row, int num);
    int  (*in_stock)(Shop* self, int row);
    int  (*count_items)(Shop* self);
    bool (*clear)(Shop* self, int row);
};


#endif