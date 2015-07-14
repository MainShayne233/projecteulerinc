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
    int multiplierIterate = 1;
    while (true){
        if (num > 9*multiplier)
            digits += 1;
        else
            return digits;
        multiplierIterate *= 10;
        multiplier += multiplierIterate;
    }
}


bool productOfTwoThreeDigitNums(int numInt){
    float num = numInt;
    float tempResult;
    int tempResultInt;
    
    for (float divider = 100; divider < 999; divider+=1){
        tempResult = num/divider;
        tempResultInt = tempResult;
        if ((amountOfDigits(tempResultInt) == 3) && (tempResult == tempResultInt)){
            return true;
        }
    }
    return false;
}


int problem4(){
    
    int workingNumber = 0;
    
    for (int a = 9; a >= 0; a-=1){
        workingNumber = 0;
        workingNumber += (100000*a + a);
        for (int b = 9; b >= 0; b-=1){
            workingNumber += (10000*b + 10*b);
            for (int c = 9; c >= 0; c-=1){
                workingNumber += (1000*c + 100*c);
                if (productOfTwoThreeDigitNums(workingNumber) == true){
                    printf("%d \n\n", workingNumber);
                    return workingNumber;
                }
                workingNumber -= (1000*c + 100*c);
            }
            workingNumber -= (10000*b + 10*b);
        }
        workingNumber += (100000*a + a);
    }
    return 0;
}




int nextPrimeNumber(int number){
    while (true){
        number += 1;
        if (isPrime(number)){
            return number;
        }
    }
}




int primeFactorizationProduct(int number){
    int prime = 2;
    int product = 1;
    while (true){
        while (number % prime == 0){
            product *= prime;
            number /= prime;
        }
        if (number == 1){
            return product;
        }
        prime = nextPrimeNumber(prime);
    }
    
}


int problem5(){
    int number = 1;
    int circut;
    while (true){
        circut = 1;
        for (int i = 2; i <= 20; i+=1){
            if (number % i != 0){
                circut = 0;
                break;
            }
        }
        if (circut == 1){
            return number;
        }
        number += 1;
    }
}



void problem6(){
    int sumOfSquares = 0;
    int squareOfSums = 0;
    
    for (int i = 1; i <= 100; i += 1){
        sumOfSquares += pow(i, 2);
        squareOfSums += i;
    }
    
    squareOfSums = pow (squareOfSums, 2);
    
    printf("%d - %d = %d", squareOfSums, sumOfSquares, (squareOfSums-sumOfSquares));
    
}

void problem7(){
    int counter = 1;
    for (int prime = 3; counter <= 10001; prime += 2){
        if (isPrime(prime)){
            counter += 1;
        }
        if ((isPrime(prime)) && (counter == 10001)){
            printf("%d\n", prime);
        }
    }
}

void problem8(){
    
}




int main(){
    problem7();
    
    
}