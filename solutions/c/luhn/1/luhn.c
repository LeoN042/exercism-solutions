#include "luhn.h"
#include "string.h"

bool luhn(const char *num) {
    int len = strlen(num);
    int dou = 0;
    int sum = 0;
    int digits = 0;
    for (int i = len - 1; i >=0; i--) {
        if (num[i] == ' ') {
            dou = (dou + 1) & 1;
        }
        else if (num[i] <= '9' && num[i] >= '0') {
            int digit = num[i] - '0';
            if (((len - i) & 1) == dou) {
                int twice = digit * 2;
                int result = (twice > 9)? (twice - 9) : twice;
                sum += result;
            }
            else {
                sum += digit;
            }
            digits++;
            
        }
        else {
            return false;
        }
    }
    if (digits <= 1) { return false; }
    return ((sum % 10) == 0);
}