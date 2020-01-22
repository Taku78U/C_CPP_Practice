#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define NUM 12

int a[NUM] = {0}; // Array

void printarray(int n){
  for(int i = 0; i < NUM; i++){
    printf("%d ", a[i]);
  }
}

int main(){
  printf("Please input array, LENGTH = %d\n", NUM);
  for(int i = 0; i < NUM; i++){
    scanf("%d", &a[i]);
  }

  printf ("Inputted array\n");
  printarray(NUM);
  printf ("\n");
  std::sort(a, a + NUM);
  printf ("Sorted array\n");
  printarray(NUM);
  printf("\n");

  int s_num;
  printf("Search Number:");
  scanf("%d", &s_num);
  

  // two-way search
  int left = 0; // include
  int right = NUM; // not include
  int mid;
  int cnt_s_num = 0;

  while(left < right){
    mid = (left + right) / 2;
    printf("left = %d, right = %d, mid = %d\n", left, right, mid);
    if(s_num <= a[mid]){
      right = mid;
      continue;
    }
    if(s_num > a[mid]){
      left = mid + 1;
      continue;
    }
  }

  if(left == NUM) {
    printf("s_num %d does not exist!\n", s_num);
    return 0;
  }

  for(int i = left; i < NUM; i++){
    if(a[i] == s_num){
      ++cnt_s_num;
    } else {
      break;
    }
  }
  printf("left = %d, right = %d, mid = %d\n", left, right, mid);
  if(cnt_s_num == 0){
    printf("s_num %d does not exist!\n", s_num);
  } else {
    printf("s_num %d cnt is %d\n", s_num, cnt_s_num);
  }
  return 0;
}
