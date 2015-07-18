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
    for (int i = 2; i*i<=num; i+=1){
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


int * digitsToArray(int number){
    int length = amountOfDigits(number);
    int digitsArray[length];
    for (int i = length; i>0; i-=1){
        digitsArray[length-i] = number/(pow(10, i-1));
        number -= digitsArray[length-i]*pow(10, i-1);
    }
    int * digitsArrayFinal = digitsArray;
    return digitsArrayFinal;
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
            printf("%d", number);
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
    
    printf("%d", (squareOfSums-sumOfSquares));
    
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
    static int numList[] = {7, 3, 1, 6, 7, 1, 7, 6, 5, 3, 1, 3, 3, 0, 6, 2, 4, 9, 1, 9, 2, 2, 5, 1, 1, 9, 6, 7, 4, 4, 2, 6, 5, 7, 4, 7, 4, 2, 3, 5, 5, 3, 4, 9, 1, 9, 4, 9, 3, 4, 9, 6, 9, 8, 3, 5, 2, 0, 3, 1, 2, 7, 7, 4, 5, 0, 6, 3, 2, 6, 2, 3, 9, 5, 7, 8, 3, 1, 8, 0, 1, 6, 9, 8, 4, 8, 0, 1, 8, 6, 9, 4, 7, 8, 8, 5, 1, 8, 4, 3, 8, 5, 8, 6, 1, 5, 6, 0, 7, 8, 9, 1, 1, 2, 9, 4, 9, 4, 9, 5, 4, 5, 9, 5, 0, 1, 7, 3, 7, 9, 5, 8, 3, 3, 1, 9, 5, 2, 8, 5, 3, 2, 0, 8, 8, 0, 5, 5, 1, 1, 1, 2, 5, 4, 0, 6, 9, 8, 7, 4, 7, 1, 5, 8, 5, 2, 3, 8, 6, 3, 0, 5, 0, 7, 1, 5, 6, 9, 3, 2, 9, 0, 9, 6, 3, 2, 9, 5, 2, 2, 7, 4, 4, 3, 0, 4, 3, 5, 5, 7, 6, 6, 8, 9, 6, 6, 4, 8, 9, 5, 0, 4, 4, 5, 2, 4, 4, 5, 2, 3, 1, 6, 1, 7, 3, 1, 8, 5, 6, 4, 0, 3, 0, 9, 8, 7, 1, 1, 1, 2, 1, 7, 2, 2, 3, 8, 3, 1, 1, 3, 6, 2, 2, 2, 9, 8, 9, 3, 4, 2, 3, 3, 8, 0, 3, 0, 8, 1, 3, 5, 3, 3, 6, 2, 7, 6, 6, 1, 4, 2, 8, 2, 8, 0, 6, 4, 4, 4, 4, 8, 6, 6, 4, 5, 2, 3, 8, 7, 4, 9, 3, 0, 3, 5, 8, 9, 0, 7, 2, 9, 6, 2, 9, 0, 4, 9, 1, 5, 6, 0, 4, 4, 0, 7, 7, 2, 3, 9, 0, 7, 1, 3, 8, 1, 0, 5, 1, 5, 8, 5, 9, 3, 0, 7, 9, 6, 0, 8, 6, 6, 7, 0, 1, 7, 2, 4, 2, 7, 1, 2, 1, 8, 8, 3, 9, 9, 8, 7, 9, 7, 9, 0, 8, 7, 9, 2, 2, 7, 4, 9, 2, 1, 9, 0, 1, 6, 9, 9, 7, 2, 0, 8, 8, 8, 0, 9, 3, 7, 7, 6, 6, 5, 7, 2, 7, 3, 3, 3, 0, 0, 1, 0, 5, 3, 3, 6, 7, 8, 8, 1, 2, 2, 0, 2, 3, 5, 4, 2, 1, 8, 0, 9, 7, 5, 1, 2, 5, 4, 5, 4, 0, 5, 9, 4, 7, 5, 2, 2, 4, 3, 5, 2, 5, 8, 4, 9, 0, 7, 7, 1, 1, 6, 7, 0, 5, 5, 6, 0, 1, 3, 6, 0, 4, 8, 3, 9, 5, 8, 6, 4, 4, 6, 7, 0, 6, 3, 2, 4, 4, 1, 5, 7, 2, 2, 1, 5, 5, 3, 9, 7, 5, 3, 6, 9, 7, 8, 1, 7, 9, 7, 7, 8, 4, 6, 1, 7, 4, 0, 6, 4, 9, 5, 5, 1, 4, 9, 2, 9, 0, 8, 6, 2, 5, 6, 9, 3, 2, 1, 9, 7, 8, 4, 6, 8, 6, 2, 2, 4, 8, 2, 8, 3, 9, 7, 2, 2, 4, 1, 3, 7, 5, 6, 5, 7, 0, 5, 6, 0, 5, 7, 4, 9, 0, 2, 6, 1, 4, 0, 7, 9, 7, 2, 9, 6, 8, 6, 5, 2, 4, 1, 4, 5, 3, 5, 1, 0, 0, 4, 7, 4, 8, 2, 1, 6, 6, 3, 7, 0, 4, 8, 4, 4, 0, 3, 1, 9, 9, 8, 9, 0, 0, 0, 8, 8, 9, 5, 2, 4, 3, 4, 5, 0, 6, 5, 8, 5, 4, 1, 2, 2, 7, 5, 8, 8, 6, 6, 6, 8, 8, 1, 1, 6, 4, 2, 7, 1, 7, 1, 4, 7, 9, 9, 2, 4, 4, 4, 2, 9, 2, 8, 2, 3, 0, 8, 6, 3, 4, 6, 5, 6, 7, 4, 8, 1, 3, 9, 1, 9, 1, 2, 3, 1, 6, 2, 8, 2, 4, 5, 8, 6, 1, 7, 8, 6, 6, 4, 5, 8, 3, 5, 9, 1, 2, 4, 5, 6, 6, 5, 2, 9, 4, 7, 6, 5, 4, 5, 6, 8, 2, 8, 4, 8, 9, 1, 2, 8, 8, 3, 1, 4, 2, 6, 0, 7, 6, 9, 0, 0, 4, 2, 2, 4, 2, 1, 9, 0, 2, 2, 6, 7, 1, 0, 5, 5, 6, 2, 6, 3, 2, 1, 1, 1, 1, 1, 0, 9, 3, 7, 0, 5, 4, 4, 2, 1, 7, 5, 0, 6, 9, 4, 1, 6, 5, 8, 9, 6, 0, 4, 0, 8, 0, 7, 1, 9, 8, 4, 0, 3, 8, 5, 0, 9, 6, 2, 4, 5, 5, 4, 4, 4, 3, 6, 2, 9, 8, 1, 2, 3, 0, 9, 8, 7, 8, 7, 9, 9, 2, 7, 2, 4, 4, 2, 8, 4, 9, 0, 9, 1, 8, 8, 8, 4, 5, 8, 0, 1, 5, 6, 1, 6, 6, 0, 9, 7, 9, 1, 9, 1, 3, 3, 8, 7, 5, 4, 9, 9, 2, 0, 0, 5, 2, 4, 0, 6, 3, 6, 8, 9, 9, 1, 2, 5, 6, 0, 7, 1, 7, 6, 0, 6, 0, 5, 8, 8, 6, 1, 1, 6, 4, 6, 7, 1, 0, 9, 4, 0, 5, 0, 7, 7, 5, 4, 1, 0, 0, 2, 2, 5, 6, 9, 8, 3, 1, 5, 5, 2, 0, 0, 0, 5, 5, 9, 3, 5, 7, 2, 9, 7, 2, 5, 7, 1, 6, 3, 6, 2, 6, 9, 5, 6, 1, 8, 8, 2, 6, 7, 0, 4, 2, 8, 2, 5, 2, 4, 8, 3, 6, 0, 0, 8, 2, 3, 2, 5, 7, 5, 3, 0, 4, 2, 0, 7, 5, 2, 9, 6, 3, 4, 5, 0};
    
    int largestProduct = 0;
    int tempProduct;
    for (int row = 0; row <= 19; row += 1){
        for (int start = 0+row*50; start <= 36+row*50; start += 1){
            tempProduct = 1;
            for (int i = 0; i <= 13; i += 1){
                tempProduct *= numList[start+i];
            }
            if (tempProduct > largestProduct){
                largestProduct = tempProduct;
            }
        }
    }
    printf("%d ", largestProduct);
}

int problem9(){
    int solution;
    for (int a = 1; a < 1000; a+=1){
        for (int b = 1; b < 1000; b+=1){
            if ((pow(a,2))+(pow(b,2)) == (pow(1000-a-b, 2))){
                solution =a*b*(1000-a-b);
                printf("%d\n", solution);
                return solution;
            }
        }
    }
    return 0;
}


long problem10(){
    int currentPrime = 2;
    long sum = 0;
    while (true){
        sum += currentPrime;
        currentPrime = nextPrimeNumber(currentPrime);
        if (currentPrime > 2000000){
            printf("%ld",sum);
            return sum;
        }
    }
}

int amountOfDivisors(int number){
    if (number == 1){
        return 1;
    }
    int divisors = 2;
    for (int i = 2; i <= pow(number,0.5); i+= 1){
        if (number % i == 0){
            divisors += 2;
        }
    }
    return divisors;
}

int problem11(){
    int triangleNumber = 0;
    for (int i = 1; true; i+=1){
        triangleNumber += i;
        if (amountOfDivisors(triangleNumber) > 500){
            printf("%d", triangleNumber);
            return triangleNumber;
        }
    }
}


//DIDN'T DO PROBLEM 11 YET BECAUSE IT'S A GRID
int main(){
    
}