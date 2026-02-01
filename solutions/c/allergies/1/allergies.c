#include "allergies.h"
bool is_allergic_to(allergen_t allergen, int n) {
    return (n & (1 << allergen));
}

allergen_list_t get_allergens(int n) {
    allergen_list_t list;
    list.count = 0;
    for (int i = 0; i < ALLERGEN_COUNT; i++) {
        if (n & (1 << i)) {
            list.allergens[i] = true;
            list.count++;
        }
        else {
            list.allergens[i] = false;
        }
        
    }
    
    return list;
}