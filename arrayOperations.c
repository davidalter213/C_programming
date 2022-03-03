#include <stdio.h>
#define N 15 //macro for initial size of the array

void part1(int a[], int size){
    printf("Part 1: \n");

    printf("    Your array is: ");
    for (int i = 0; i < size; i++){ //print all elements of array
        printf("%d ", a[i]);
    }

    printf("\n  Your array has %d elements \n", size);
    printf("    The size of the array is %lu bytes \n", sizeof(int) * size);
    //multiplying size of array by size of an integer to find total bytes
    
}

void part2(int a[], int size){
    printf("\nPart 2: \n");

    printf("    Your array in reverse is: ");
    for (int i = size - 1; i >= 0; i-- ){
        printf(" %d" , a[i]);
    }
    printf("\n");
}

void part3(int a[], int size){
    int smallest = a[0]; //initially set the first element to be the smallest

    printf("\nPart3: \n");

    for (int i = 1; i < size; i++){
        if (a[i] < smallest){ //check if any other element is smaller
            smallest = a[i];
        }
    }
    
    printf("    The smallest value in the array is: %d\n", smallest);
}

void part4(int a[], int size){
    int sum = 0;
    printf("\nPart4: \n");

    for (int i = 0; i < size; i++){ //add all the numbers in the array
        sum += a[i]; 
    }

    printf("    The sum of all the values in your array is: %d\n", sum);
}

void part5(int a[], int size){
    int first = a[0];
    int last = a[size -1];
    
    printf("\nPart5: \n");
    printf("    Your array with first and last elements switched is: ");
    for (int i = 0; i < size; i++){

        if (i == 0){
            printf(" %d", last); //on the first iteration, print the last element
        } else if (i == size -1){
            printf(" %d", first); //on the last iteration, print the first element
        } else {
            printf(" %d", a[i]); //on any other iteration, print regularly
        } 
    }
    printf("\n");

}

void part6(int a[], int size){
    int temp = 0;

    for(int i = 0; i < size; i++){
        for (int j = i + 1; j < size; j++){
            if (a[i] > a[j]){
                temp = a[i]; 
                a[i] = a[j]; 
                a[j] = temp;
            }
        }
    }

    printf("\nPart 6: \n");
    printf("    Your array in sorted order is: ");
    for (int i = 0; i < size; i++){
        printf(" %d" , a[i]);
    }
    printf("\n");
}

int main(void){
    int a[N], size = 0; //create an array, variable for size of the array 
    char temp; //character that tracks when user finishes entering array
    printf("Please enter your integers separated by spaces: "); 
    
    while (temp != '\n'){ //while the user does not hit the enter key
        scanf("%d%c", &a[size], &temp); //scan for integer and for space afer it
        size++; //increase the size of the array
    }

   //function calls
    part1(a, size);
    part2(a, size);
    part3(a, size);
    part4(a, size);
    part5(a, size);
    part6(a, size);

    return 0;
}