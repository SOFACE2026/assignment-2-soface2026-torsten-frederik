#include "ShoeShop_C.h"
#include <stdlib.h>

struct ShoeShop {
    int* shelf;
    int size;
};

// Concrete implementations of the ShoeShop_C methods following logic from C++ methods
// Direct (non-polymorphic) C implementation: functions operate on ShoeShop*
// The struct is hidden here to provide encapsulation (opaque type in the header)
ShoeShop* shoeshop_create(int size)
{
    if (size <= 0) return NULL;

    ShoeShop* shop = malloc(sizeof *shop); // allocates enough memory for the struct ShoeShop
    if (!shop) return NULL;

    shop->shelf = calloc((size_t)size, sizeof *shop->shelf);
    if (!shop->shelf) { free(shop); return NULL; }

    shop->size = size;
    return shop;
}

// Directly implement ShoeShop methods
void shoeshop_destroy(ShoeShop* shop)
{
    if (!shop) return;
    free(shop->shelf);
    free(shop);
}

void shoeshop_add_items(ShoeShop* shop, int row, int num)
{
    if (!shop || row < 0 || row >= shop->size || num <= 0) return;
    shop->shelf[row] += num;
}

int shoeshop_in_stock(const ShoeShop* shop, int row)
{
    if (!shop || row < 0 || row >= shop->size) return 0;
    return shop->shelf[row] > 0;
}

int shoeshop_count_items(const ShoeShop* shop)
{
    if (!shop) return 0;

    int tot = 0;
    for (int k = 0; k < shop->size; k++)
        tot += shop->shelf[k];

    return tot;
}

bool shoeshop_clear(ShoeShop* shop, int row)
{
    if (!shop || row < 0 || row >= shop->size) return false;

    bool rem = shop->shelf[row] > 0;
    shop->shelf[row] = 0;
    return rem;
}