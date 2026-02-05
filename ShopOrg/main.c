#include "ShoeShop_C.h"
#include <stdio.h>

int main(void)
{
    // Direct implementation to ShopOrg
    ShoeShop* shop = shoeshop_create(5);

    shoeshop_add_items(shop, 2, 10);

    printf("in_stock(row 2) = %d\n", shoeshop_in_stock(shop, 2));
    printf("count_items()   = %d\n", shoeshop_count_items(shop));

    shoeshop_clear(shop, 2);

    printf("in_stock(row 2) = %d\n", shoeshop_in_stock(shop, 2));

    shoeshop_destroy(shop);
    return 0;
}