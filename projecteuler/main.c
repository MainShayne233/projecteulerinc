//
//  main.c
//  projecteuler
//
//  Created by Shayne Tremblay on 7/11/15.
//  Copyright (c) 2015 Open Sorcery. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

void problem1(){
    int sum = 0;
    for (int i = 1; i <1000; i++){
        if ((i%3==0) || (i%5==0)){
            sum += i;
        }
    }
    printf("%d", sum);
}

void problem2(){
    int sum = 0;
    int num1 = 1;
    int num2 = 2;
    int tempNum2;
    while (num2 < 4000000){
        if (num2 % 2 == 0){
            sum += num2;
        }
        tempNum2 = num2;
        num2 += num1;
        num1 = tempNum2;
    }
    printf("%d \n", sum);
}


bool isPrime(int num){
    if (num == 2)
        return true;
    for (int i = 2; i <= (num/2); i+=1){
        if (num % i == 0)
            return false;
    }
    return true;
}

void problem3(){
    int largestPrime = 0;
    for (int i = 3; i < sqrt(600851475143); i+=1){
        if ((600851475143 % i == 0) && (isPrime(i)))
            largestPrime = i;
    }
    printf("%d \n", largestPrime);
}

int amountOfDigits(int num){
    int digits = 1;
    int multiplier = 1;
    while (true){
        if (num > 9*multiplier)
            digits += 1;
        else
            return digits;
        multiplier *= 10;
    }
}



void numToString(int num, char* numString){
    char tempNumString[amountOfDigits(num)];
    
}





main(){
    printf("%d \n", valueAtPlace(456789, 4));
}