#include "ShoeShop_C.h"
#include <stdio.h>

int main(void)
{
    ShoeShop* ss = shoeshop_create(5);
    Shop* shop = (Shop*)ss; // Upcast

    shop->add_items(shop, 2, 10);  // row 2 gets +10 items

    // Prints whether row 2 is in stock (1 for true, 0 for false)
    // After adding 10 items, this should print: 1
    printf("in_stock(row %d) = %d\n", 2, shop->in_stock(shop, 2));

    // Prints total number of items in the whole shop (sum over all rows)
    printf("count_items()    = %d\n", shop->count_items(shop));

    shop->clear(shop, 2); // sets row 2 to 0

    // Prints whether row 2 is in stock after clearing
    // Now row 2 is 0, so this should print: 0
    printf("in_stock(row %d) = %d\n", 2, shop->in_stock(shop, 2));

    shop->destroy(shop);
    return 0;
}