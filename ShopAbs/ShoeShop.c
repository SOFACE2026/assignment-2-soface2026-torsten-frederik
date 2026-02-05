#include "ShoeShop_C.h"
#include <stdlib.h>
#include <stdbool.h>

// Concrete implementation of the Shop interface using polymorphism
struct ShoeShop {
    // Inherites the exact same methods contained in Shop interface
    void (*destroy)(Shop*);

    void (*add_items)(Shop*, int, int);
    int  (*in_stock)(Shop*, int);
    int  (*count_items)(Shop*);
    bool (*clear)(Shop*, int);

    // ShoeShop private state (not accessible through a 'Shop*')
    int* shelf;
    int  size;
};

// Forward declare for future definitions
// static implementations ("virtual methods")
static void shoeshop_destroy_impl(Shop* self);
static void shoeshop_add_items_impl(Shop* self, int row, int num);
static int  shoeshop_in_stock_impl(Shop* self, int row);
static int  shoeshop_count_items_impl(Shop* self);
static bool shoeshop_clear_impl(Shop* self, int row);

// Small helper-function for ensuring safeness :) 
static int row_ok(const struct ShoeShop* s, int row) {
    return s && row >= 0 && row < s->size;
}

// ShoeShop constructor
ShoeShop* shoeshop_create(int size)
{
    if (size <= 0) return NULL;

    ShoeShop* s = malloc(sizeof *s);
    if (!s) return NULL;

    s->shelf = calloc((size_t)size, sizeof *s->shelf);
    if (!s->shelf) { free(s); return NULL; }

    s->size = size;

    // Install function pointers (vtable) for runtime polymorphism
    s->destroy     = shoeshop_destroy_impl;
    s->add_items   = shoeshop_add_items_impl;
    s->in_stock    = shoeshop_in_stock_impl;
    s->count_items = shoeshop_count_items_impl;
    s->clear       = shoeshop_clear_impl;

    return s;
}

// Implemenations following the C++ logic 
// static to ensure they only live in this file
static void shoeshop_destroy_impl(Shop* self)
{
    struct ShoeShop* s = (struct ShoeShop*)self; // casting Shop to ShoeShop
    if (!s) return;

    free(s->shelf);
    free(s);
}

static void shoeshop_add_items_impl(Shop* self, int row, int num)
{
    struct ShoeShop* s = (struct ShoeShop*)self; // casting Shop to ShoeShop
    if (!row_ok(s, row) || num <= 0) return;

    s->shelf[row] += num;
}

static int shoeshop_in_stock_impl(Shop* self, int row)
{
    struct ShoeShop* s = (struct ShoeShop*)self; // casting Shop to ShoeShop
    if (!row_ok(s, row)) return 0;
    
    return s->shelf[row] > 0;
}

static int shoeshop_count_items_impl(Shop* self)
{
    struct ShoeShop* s = (struct ShoeShop*)self; // casting Shop to ShoeShop
    if (!s) return 0;

    int tot = 0;
    for (int k = 0; k < s->size; k++)
        tot += s->shelf[k];

    return tot;
}

static bool shoeshop_clear_impl(Shop* self, int row)
{
    struct ShoeShop* s = (struct ShoeShop*)self; // casting Shop to ShoeShop
    if (!row_ok(s, row)) return false;

    bool rem = s->shelf[row] > 0;
    s->shelf[row] = 0;
    return rem;
}
