#ifndef SHOESHOP_C_H
#define SHOESHOP_C_H

#include "Shop_C.h"

// Opaque type (forward declared): struct definition is hidden in the .c file
typedef struct ShoeShop ShoeShop;

// Constructor
ShoeShop* shoeshop_create(int size);


#endif