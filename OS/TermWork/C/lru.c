#include <stdio.h>
void main() {
  int n;
  printf("Enter the Total number of page reference");
  scanf("%d", &n);
  int pr[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d", &pr[i]);
  }
  int fra[3] = {-1, -1, -1};
  int miss = 0;
  int hit = 0;
  int flag = 0;
  for (int i = 0; i < n; ++i) {
    int lu[2] = {-1, -1};
    if (flag < 3) {
      if (fra[0] == pr[i] || fra[1] == pr[i] || fra[2] == pr[i]) {
        ++hit;
      } else {
        ++miss;
        fra[flag] = pr[i];
        ++flag;
      }
    }

    else if (fra[0] == pr[i] || fra[1] == pr[i] || fra[2] == pr[i]) {
      ++hit;

    } else {
      int s = 0;
      for (int k = i - 1; k >= 0 && s < 2; --k) {
        for (int x = 0; x < 2; ++x) {
          if (lu[x] != pr[k]) {
            lu[s] = pr[k];
            ++s;
            break;
          }
        }
      }
      for (int yy = 0; yy < 3; ++yy) {
        if (fra[yy] != lu[0] && fra[yy] != lu[1]) {
          fra[yy] = pr[i];
          ++miss;
        }
      }
    }
    printf("%d  %d  %d  \n", fra[0], fra[1], fra[2]);
  }
  printf("HIT %d\nMISS %d", hit, miss);
}
