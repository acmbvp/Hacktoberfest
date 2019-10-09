#include <stdio.h>

void insertSort(int *arr, int arr_size);
void printArray(int *arr, int arr_size);


int main(void) {
  
  // define array
  int arr[] = {10,9,8,7,6,5,4,3,2,1};
  int arr_size = (int)( sizeof(arr) / sizeof(arr[0]));

  // call sort methods
  insertSort(arr, arr_size);
  
  // print array
  printArray(arr, arr_size);
  
  return 0;
}

void insertSort(int *arr, int arr_size) {
  for (int j = 1; j < arr_size; j++) {

    int i = j-1;
    int chave = arr[j];
    int aux;

    while(i >= 0 && arr[i] > chave) {
      arr[i+1] = arr[i];
      i=i-1;
      arr[i+1] = chave;
    }
  }
}

void printArray(int *arr, int arr_size) {
  for (int i = 0; i < arr_size; i++) {
    printf("%d ", arr[i]);
  }
}