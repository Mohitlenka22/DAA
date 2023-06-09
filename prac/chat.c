#include <stdio.h>

void SubsetSum(int s, int k, int r, int x[], int w[], int m, int n) {

  
  if (k == n) {
    if (s == m) {
      for (int i = 0; i < n; i++) {
        printf("%d ", x[i]);
      }
      printf("\n");
    }
    return;
  }


  x[k] = 1;
  SubsetSum(s + w[k], k + 1, r - w[k], x, w, m, n);

  
  x[k] = 0;
  SubsetSum(s, k + 1, r, x, w, m, n);
}

int main() {
  int n;
  scanf("%d", &n);
  int w[n];
  int x[n];
  int totSum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &w[i]);
    totSum += w[i];
    x[i] = 0;
  }
  int m;
  scanf("%d", &m);
  SubsetSum(0, 0, totSum, x, w, m, n);

  return 0;
}
