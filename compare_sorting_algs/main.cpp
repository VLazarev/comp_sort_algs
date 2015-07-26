
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 100 // Array size
#define RAND_TOP 100 // The upper limit of the range of random numbers
enum {RANDOM, ASC, DESC}; //Fill flags: RANDOM, ASC - ascending, DESC - descending

void fill_arr(int*, int); // Array fill function
void duplicate_arr(int*, int*); // Array duplicate function
void display_arr(int*); // Array display function

// Sort functions
void sort_select(int*);
void sort_buble(int*);



int main()
{
    int array0[ARR_SIZE], array1[ARR_SIZE];
    fill_arr(array0, DESC);
    duplicate_arr(array0, array1);
    sort_select(array0);
    sort_buble(array1);

    return 0;
}

void fill_arr(int* arr, int flag)
{
    switch (flag) {
        case RANDOM:
            srand(time(0));
            for(int i=0; i<ARR_SIZE; i++) {
                *(arr+i)=rand()%RAND_TOP;
            }
            printf("Random fill array:\n");
            display_arr(arr);
            break;
        case ASC:
            for(int i=0; i<ARR_SIZE; i++) {
                *(arr+i)=i+1;
            }
            printf("Ascending fill array:\n");
            display_arr(arr);
            break;
        case DESC:
            for(int i=0, j=ARR_SIZE; i<ARR_SIZE; i++, j--) {
                *(arr+i)=j;
            }
            printf("Descending fill array:\n");
            display_arr(arr);
            break;
        default:
            printf("Undefined fill type.\n");
    }
}

void duplicate_arr(int *arr0, int *arr1)
{
    for(int i=0; i<ARR_SIZE; i++) {
        *(arr1+i) = *(arr0+i);
    }
}

void display_arr(int *arr)
{
    for(int i=0; i<ARR_SIZE; i++) {
        printf("[%d] = %d\n", i, *(arr+i));
    }
}

void sort_select(int *arr)
{
    int compares = 0, moves = 0;
    for(int i=0; i<ARR_SIZE; i++) {
        for(int j=i+1; j<ARR_SIZE; j++) {
            compares++;
            if(*(arr+j)<*(arr+i)) {
                int temp = *(arr+i);
                *(arr+i) = *(arr+j);
                *(arr+j) = temp;
                moves++;
            }
        }
    }
    printf("Array sorted (Select):\n");
    printf("Compares: %d, moves: %d\n", compares, moves);
    //display_arr(arr);

}

void sort_buble(int *arr)
{
    int j, change, compares = 0, moves = 0;
    do {
            change = 0;
            for(int i=0; i<ARR_SIZE; i++) {
                j=i+1;
                if(j<ARR_SIZE) {
                    compares++;
                    if(*(arr+j)<*(arr+i)) {
                        int temp = *(arr+i);
                        *(arr+i) = *(arr+j);
                        *(arr+j) = temp;
                        change++;
                        moves++;
                    }
                }
            }
    } while(change!=0);
    printf("Array sorted (Buble):\n");
    printf("Compares: %d, moves: %d\n", compares, moves);
    //display_arr(arr);

}
