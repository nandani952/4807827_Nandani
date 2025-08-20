#include <stdio.h>
#include <stdlib.h>

int* climbingLeaderboard(int ranked_count, int* ranked, int player_count, int* player, int* result_count) {
    int* unique_ranked = malloc(ranked_count * sizeof(int));
    int unique_count = 0;

    if (ranked_count > 0) {
        unique_ranked[unique_count++] = ranked[0];
        for (int i = 1; i < ranked_count; i++) {
            if (ranked[i] != ranked[i-1]) {
                unique_ranked[unique_count++] = ranked[i];
            }
        }
    }
    *result_count = player_count;
    int* player_ranks = malloc(player_count * sizeof(int));
    int ranked_idx = unique_count - 1;
    for (int i = 0; i < player_count; i++) {
        while (ranked_idx >= 0 && player[i] >= unique_ranked[ranked_idx]) {
            ranked_idx--;
        }
        player_ranks[i] = ranked_idx + 2;
    }
    free(unique_ranked);
    return player_ranks;
}

int main() {
    int ranked_count;
    scanf("%d", &ranked_count);
    int* ranked = malloc(ranked_count * sizeof(int));
    for (int i = 0; i < ranked_count; i++) {
        scanf("%d", &ranked[i]);
    }
    int player_count;
    scanf("%d", &player_count);
    int* player = malloc(player_count * sizeof(int));
    for (int i = 0; i < player_count; i++) {
        scanf("%d", &player[i]);
    }
    int res_count;
    int* result = climbingLeaderboard(ranked_count, ranked, player_count, player, &res_count);
    
    for (int i = 0; i < res_count; i++) {
        printf("%d\n", result[i]);
    }
    
    free(ranked);
    free(player);
    free(result);
    
    return 0;
}
