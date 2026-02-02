#include "high_scores.h"

/// Return the latest score.
int32_t latest(const int32_t *scores, size_t scores_len) {
    return scores[scores_len - 1];
}

/// Return the highest score.
int32_t personal_best(const int32_t *scores, size_t scores_len) {
    int32_t max = 0;
    for (size_t i = 0; i < scores_len; i++) {
        if (max < scores[i]) {
            max = scores[i];
        }
    }
    return max;
}

/// Write the highest scores to `output` (in non-ascending order).
/// Return the number of scores written.
size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output) {
    int32_t top1 = 0;
    int32_t top2 = 0;
    int32_t top3 = 0;
    for (size_t i = 0; i < scores_len; i++) {
        if (top1 <= scores[i]) {
            top3 = top2;
            top2 = top1;
            top1 = scores[i];
        }
        else if (top2 <= scores[i]) {
            top3 = top2;
            top2 = scores[i];
        }
        else if (top3 <= scores[i]) {
            top3 = scores[i];
        }
    }
    output[0] = top1;
    output[1] = top2;
    output[2] = top3;
    return (scores_len >= 3)? 3 : scores_len;
}