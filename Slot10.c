//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int main(){
//    system("cls");
//    char a[] = "HOA";
//    char b[10];
//    char c[] = "LA";
//    strcpy(b,a);
//    strcat(a," ");
//    strcat(a, c);
//
//    printf("\nOUTPUT:\n");
//    printf("b=%s\n", b);
//    printf("a=%s\n", a);
//
//    printf("strcmp(HOA,LA) = %d\n",strcmp(b, c));
//    printf("strcmp(LA,HOA) = %d\n",strcmp(c, b));
//    printf("strcmp(HOA,HOA) = %d\n",strcmp(b, b));
//    printf("\n");
//    system("pause");
//    return 0;    
//}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createData(int a[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        a[i] = 10 + rand() % 91;
}

void view(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

//sap xep bubble sort theo thu tu tang dan
void sort_bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    system("cls");

    int a[100], n = 10;
    createData(a, n);
    printf("Before sorting:\n");
    view(a, n);
    printf("After sorting:\n");
    sort_bubbleSort(a, n);
    view(a, n);

    printf("\n");
    printf("\n");
    system("pause");
    return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void input(double a[], int &n) {
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    printf("Enter element %d: ", i + 1);
    scanf("%lf", &a[i]);
  }
}

void display(double a[], int n) {
  printf("The array is: ");
  for (int i = 0; i < n; i++) {
    printf("%lf ", a[i]);
  }
  printf("\n");
}

int search(double a[], int n, double x) {
  for (int i = 0; i < n; i++) {
    if (a[i] == x) {
      return i;
    }
  }
  return -1;
}

void dele(double a[], int &n, int k) {
  if (k < 0 || k >= n) {
    printf("Invalid position\n");
    return;
  }

  for (int i = k; i < n - 1; i++) {
    a[i] = a[i + 1];
  }
  n--;
}

void dele(double a[], int &n, double x) {
  int k = search(a, n, x);
  if (k == -1) {
    printf("Value not found\n");
    return;
  }

  dele(a, n, k);
}

int maxPos(double a[], int n) {
  int maxPos = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] > a[maxPos]) {
      maxPos = i;
    }
  }
  return maxPos;
}

void sort(double a[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int maxPos = maxPos(a, n - i);
    double temp = a[i];
    a[i] = a[maxPos];
    a[maxPos] = temp;
  }
}

int main() {
  system("cls");
  double a[100];
  int n, k;
  double x;
  int choice;

  while (1) {
    printf("\n");
    printf("1. Input data\n");
    printf("2. Display\n");
    printf("3. Search\n");
    printf("4. Delete position\n");
    printf("5. Delete value\n");
    printf("6. Sort data\n");
    printf("0. Exit\n");
    printf("Enter your selection (0 -> 6): ");
    scanf("%d", &choice);

    if (choice == 0) {
      break;
    }

    switch (choice) {
      case 1:
        input(a, n);
        break;
      case 2:
        display(a, n);
        break;
      case 3:
        printf("Enter a value to be searched x = ");
        scanf("%lf", &x);
        k = search(a, n, x);
        if (k == -1) {
          printf("Not found\n");
        } else {
          printf("Found at position %d\n", k);
        }
        break;
      case 4:
        printf("Enter a position to be deleted k = ");
        scanf("%d", &k);
        dele(a, n, k);
        break;
      case 5:
        printf("Enter a value to be deleted x = ");
        scanf("%lf", &x);
        dele(a, n, x);
        break;
      case 6:
        sort(a, n);
        break;
      default:
        printf("Your selection is incorrect\n");
        break;
    }
  }

  printf("\n");
 system("pause");
 return(0);
}









