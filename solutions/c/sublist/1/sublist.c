#include "sublist.h"

comparison_result_t check_lists(int *list_to_compare, int *base_list,
                                size_t list_to_compare_element_count,
                                size_t base_list_element_count) {
    int flag = 0;
    if (list_to_compare_element_count == base_list_element_count) {
        for (size_t i = 0; i < list_to_compare_element_count; i++) {
            if (list_to_compare[i] != base_list[i]) {
                return UNEQUAL;
            }
        }
        return EQUAL;
    }
    if (list_to_compare_element_count > base_list_element_count) {
        for (size_t i = 0; i < list_to_compare_element_count - base_list_element_count + 1; i++) {
            flag = 0;
            for (size_t j = 0; j < base_list_element_count; j++) {
                if (list_to_compare[i+j] != base_list[j]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                return SUPERLIST;
            }
        }
        return UNEQUAL;
    }
    if (list_to_compare_element_count < base_list_element_count) {
        for (size_t i = 0; i < base_list_element_count - list_to_compare_element_count + 1; i++) {
            flag = 0;
            for (size_t j = 0; j < list_to_compare_element_count; j++) {
                if (base_list[i+j] != list_to_compare[j]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                return SUBLIST;
            }
        }
        return UNEQUAL;
    }
    return UNEQUAL;
}