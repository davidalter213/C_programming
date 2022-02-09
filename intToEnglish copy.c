/*
intToEnglish.c asks the user to enter any integer number from 1-999,
it then will return that integer in english words. (123 = one hundred twenty three)

Written by: David Alter
251158774
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    // array to store numbers 0-9
    char* singles[10] = {"zero", "one", "two", "three", "four", "five"
    , "six", "seven", "eight", "nine"};

    // array to store number 10-19
    char* teens[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen"
    , "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

    //array to store all the tens, first two spots are empty as they are covered by above arrays
    char* tens[10] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty",
    "seventy", "eighty", "ninety"};
    
    //array to add hundred word to to 3 digit numbers
    char* hun[1] = {"hundred"};


    int num;    //number that the user enters
    int dig_count;  //variable for amount of digits in the entered number

    //ask user to enter a number, read input
    printf("Please enter a value (1-999, 0 to quit): ");
    scanf("%d", & num);

    int number = num;   //number is only used to calculate number of tens and hundreds

    //determine number of digits in entered number
    do {
    number /= 10;
    ++dig_count;
  } while (number != 0);

    int remainder;  //variable for ones column
    int tens_count = 0; //variable for tens column
    int huns_count = 0; //variable for hundreds column

    // if the number is one digit output singles array element with numbered entered
    if (dig_count == 1){
        printf("The number you entered is %s\n", singles[num]);
    } else if ( dig_count == 2){
        // if the two digit number is less than 20, output appropriate number from teens array
        if (num < 20){
            //the ones column of num is  num - 10
            remainder = num - 10;
            printf("The number you entered is %s\n", teens[remainder]);
        } else {
            // if number is larger than 20, we need to get ones and tens column separately
            number = num;

            //determine number of ten multiples in number
            do {
                number -= 10;
                ++tens_count;
            } while (number > 10);

            //determine ones column
            remainder = num - tens_count * 10;

            if (num % 10 == 0){ //if the ones column is zero, dont enter a ones column
                tens_count++;
                printf("The number you entered is %s\n", tens[tens_count]);
            } else {
                printf("The number you entered is %s %s\n", tens[tens_count], singles[remainder]);
            }
        }
     // if the number is three digits
    } else {
        number = num;

        //determine hundreds column
        do {
            number -= 100;
            ++huns_count;
        } while (number > 100);

        //determine tens column
        do
        {
            number -= 10;
            ++tens_count;
        } while (number > 10);

        //determine ones column
        remainder = num - huns_count * 100 - tens_count *10;

        if (num % 10 == 0){ //if the ones column is zero, dont enter a ones column
            tens_count++;
            printf("The number you entered is %s %s %s \n", singles[huns_count], hun[0], tens[tens_count]);
        } else {
            printf("The number you entered is %s %s %s %s\n", singles[huns_count], hun[0], tens[tens_count], singles[remainder]);
        }
    }
}