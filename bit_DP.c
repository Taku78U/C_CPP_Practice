#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// 20 x 20, but extra allocation.
int dist[21][21];

// Former: Bit expression of passed route
// Later: last check-point
int dp[(1 << 20) + 1][21];
int n;

int rec(int bit, int v){

  // Return if it has already searched.
  if(dp[bit][v] != -1){
    return dp[bit][v];
  }

  // Initial value
  if(bit == (1 << v)){
    return dp[bit][v] = 0;
  }

  int res = INT_MAX;

  int tmp_res;

  // 
  int prev_bit = bit & ~(1 << v);
  int u;

  for(u = 0; u < n; ++u){
    if(!(prev_bit & (1 << u))){
      continue;
    }
    tmp_res = rec(prev_bit, u) + dist[u][v];
    if(tmp_res < res){
      res = tmp_res;
    }
  }

  return dp[bit][v] = res;

}

int main(){

  scanf("%d", &n);

  int i, j, v, bit;

  for(i = 0; i < n; ++i){
    for(j = 0; j < n; ++j){
      scanf("%d", &dist[i][j]);
    }
  }

  for(bit = 0; bit < (1 << n); ++bit){
    for(v = 0; v < n; ++v){
      dp[bit][v] = -1;
    }
  }

  int res = INT_MAX;
  int tmp_res;
  for(v = 0; v < n; ++v){
    tmp_res = rec((1 << n) - 1, v);
    if(res > tmp_res) res = tmp_res;
  }

  printf("%d\n", res);
  
  return 0;
}
