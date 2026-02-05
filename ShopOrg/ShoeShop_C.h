#ifndef SHOESHOP_C_H
#define SHOESHOP_C_H

#include <stdbool.h>

// Opaque type: users can hold ShoeShop* but cannot access its fields
// The struct definition is hidden in ShoeShop_C.c (encapsulation)
typedef struct ShoeShop ShoeShop;


// Public API (create/destroy)
ShoeShop* shoeshop_create(int size);
void shoeshop_destroy(ShoeShop* shop);

// Public operations on a ShoeShop instance
void  shoeshop_add_items(ShoeShop* shop, int row, int num);
int   shoeshop_in_stock(const ShoeShop* shop, int row);  
int   shoeshop_count_items(const ShoeShop* shop);
bool  shoeshop_clear(ShoeShop* shop, int row);

#endif

