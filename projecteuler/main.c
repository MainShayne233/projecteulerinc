//
//  main.c
//  projecteuler
//
//  Created by Shayne Tremblay on 7/11/15.
//  Copyright (c) 2015 Open Sorcery. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num){
    if (num<0)
        num*=-1;
    if (num == 2)
        return true;
    if (num == 1 || num == 0)
        return false;
    for (int i = 2; i*i<=num; i+=1){
        if (num % i == 0)
            return false;
    }
    return true;
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

int collatzSequence(long startNumber){
    int steps = 1;
    while (startNumber != 1){
        steps += 1;
        if (startNumber % 2 == 0){
            startNumber /= 2;
        }
        else{
            startNumber = 3*startNumber + 1;
        }
    }
    return steps;
}

int summation(int n){
    return (n*(n+1))/(2);
}

int divisors_sum(int n){
    int sum = 0;
    for (int i = 1; i <= n/2; i+=1){
        if (n%i==0)
            sum += i;
    }
    return sum;
}

bool is_amicable(int n){
    int firstSum = divisors_sum(n);
    if (firstSum == n)
        return false;
    int secondSum = divisors_sum(firstSum);
    if (secondSum == n)
        return true;
    else
        return false;
}

int ones_digit_value(int n){
    switch (n){
        case 1:
            return 3;
        case 2:
            return 3;
        case 3:
            return 5;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 3;
        case 7:
            return 5;
        case 8:
            return 5;
        case 9:
            return 4;
        default:
            return 0;
    }
}


int tens_digit_value(int n){
    if (n<10){
        return ones_digit_value(n);
    }
    if (n==10)
        return 3;
    if (n==11 || n==12)
        return 6;
    else if (n==13)
        return 8;
    else if (n==15)
        return 7;
    else if (n==18)
        return 8;
    if (n==14 || (n>15 && n<20))
        return 4+ones_digit_value(n%10);
    else if ((n>19 && n<40) || (n>79 && n <100))
        return 6+ones_digit_value(n%10);
    else if (n>39 && n<70)
        return 5+ones_digit_value(n%10);
    else if (n>69 && n<80)
        return 7+ones_digit_value(n%10);
    else
        return 0;
}



int hundred_sum(int n){
    if (n < 100)
        return tens_digit_value(n);
    else if (n>99 && n<1000)
        if (n%100 == 0)
            return ones_digit_value(n/100)+7;
        else
            return ones_digit_value(n/100)+10+tens_digit_value(n%100);
        else
            return 11;
}

int recurring_decimal_length(int n){
    int decimalArray[1000] = {-1}, numerator = 1, index = 0, remainder, circut;
    while (true){
        //printf("%d\n",index);
        remainder = numerator%n;
        circut = 1;
        for (int i=0;i<1000;i+=1){
            if (decimalArray[i] == remainder)
                circut = 0;
        }
        if (circut == 1){
            decimalArray[index] = remainder;
            index+=1;
        }
        else{
            return index;
        }
        numerator=remainder*10;
    }
}

int quadratic_primes(int a, int b){
    int n = 0;
    while (true){
        if (!isPrime(pow(n,2) + a*n + b)){
            if (n==1011)
                printf("a : %d, b : %d",a,b);
            return n;
        }
        n+=1;
    }
}

int problem1(){
    int sum = 0;
    for (int i = 1; i <1000; i++){
        if ((i%3==0) || (i%5==0)){
            sum += i;
        }
    }
    return sum;
}

int problem2(){
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
    return sum;
}


int problem3(){
    int largestPrime = 0;
    for (int i = 3; i < sqrt(600851475143); i+=1){
        if ((600851475143 % i == 0) && (isPrime(i)))
            largestPrime = i;
    }
    return largestPrime;
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

int problem6(){
    int sumOfSquares = 0;
    int squareOfSums = 0;
    
    for (int i = 1; i <= 100; i += 1){
        sumOfSquares += pow(i, 2);
        squareOfSums += i;
    }
    
    squareOfSums = pow (squareOfSums, 2);
    
    return(squareOfSums-sumOfSquares);
    
}

int problem7(){
    int counter = 1;
    for (int prime = 3; counter <= 10001; prime += 2){
        if (isPrime(prime)){
            counter += 1;
        }
        if ((isPrime(prime)) && (counter == 10001)){
            return prime;
        }
    }
    return 0;
}

int problem8(){
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
    return largestProduct;
}

int problem9(){
    int solution;
    for (int a = 1; a < 1000; a+=1){
        for (int b = 1; b < 1000; b+=1){
            if ((pow(a,2))+(pow(b,2)) == (pow(1000-a-b, 2))){
                solution =a*b*(1000-a-b);
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
            return sum;
        }
    }
}

int problem11(){
    static int gridArray[] = {8, 2, 22, 97, 38, 15, 0, 40, 0, 75, 4, 5, 7, 78, 52, 12, 50, 77, 91, 8, 49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 4, 56, 62, 0, 81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30, 3, 49, 13, 36, 65, 52, 70, 95, 23, 4, 60, 11, 42, 69, 24, 68, 56, 1, 32, 56, 71, 37, 2, 36, 91, 22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80, 24, 47, 32, 60, 99, 3, 45, 2, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50, 32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70, 67, 26, 20, 68, 2, 62, 12, 20, 95, 63, 94, 39, 63, 8, 40, 91, 66, 49, 94, 21, 24, 55, 58, 5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72, 21, 36, 23, 9, 75, 0, 76, 44, 20, 45, 35, 14, 0, 61, 33, 97, 34, 31, 33, 95, 78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 3, 80, 4, 62, 16, 14, 9, 53, 56, 92, 16, 39, 5, 42, 96, 35, 31, 47, 55, 58, 88, 24, 0, 17, 54, 24, 36, 29, 85, 57, 86, 56, 0, 48, 35, 71, 89, 7, 5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58, 19, 80, 81, 68, 5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 4, 89, 55, 40, 4, 52, 8, 83, 97, 35, 99, 16, 7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66, 88, 36, 68, 87, 57, 62, 20, 72, 3, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69, 4, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8, 46, 29, 32, 40, 62, 76, 36, 20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 4, 36, 16, 20, 73, 35, 29, 78, 31, 90, 1, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 5, 54, 1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52, 1, 89, 19, 67, 48};
    int largestProduct = 0;
    int tempProduct;
    int tempValue;
    //HORIZONTAL
    for (int row = 0; row <= 19; row +=1){
        for (int start = 0; start <= 16; start += 1){
            tempProduct = 1;
            for (int i = 0; i <= 3; i += 1){
                tempProduct *= gridArray[start+row*20+i];
            }
            if (tempProduct > largestProduct){
                largestProduct = tempProduct;
            }
        }
    }
    //VERTICAL
    for (int start = 0; start <= 16; start += 1){
        for (int column = 0; column <= 19; column += 1){
            tempProduct = 1;
            for (int i = 0; i <= 3; i += 1){
                tempValue = gridArray[column+start*20+i*20];
                tempProduct *= tempValue;
            }
            if (tempProduct > largestProduct){
                largestProduct = tempProduct;
            }
        }
    }
    //DIAGNAL DOWN LEFT
    for (int start = 0; start <= 16; start += 1){
        for (int column = 0; column <= 16; column += 1){
            tempProduct = 1;
            for (int i = 0; i <= 3; i += 1){
                tempValue = gridArray[start*20+column+i*21];
                tempProduct *= tempValue;
            }
            if (tempProduct > largestProduct){
                largestProduct = tempProduct;
            }
        }
    }
    //DIAGNAL DOWN RIGHT
    for (int start = 0; start <= 16; start += 1){
        for (int column = 0; column <= 16; column += 1){
            tempProduct = 1;
            for (int i = 0; i <= 3; i += 1){
                tempValue = gridArray[start*20+column+i*19+3];
                tempProduct *= tempValue;
            }
            if (tempProduct > largestProduct){
                largestProduct = tempProduct;
            }
        }
    }
        return largestProduct;
}

int problem12(){
    int triangleNumber = 0;
    for (int i = 1; true; i+=1){
        triangleNumber += i;
        if (amountOfDivisors(triangleNumber) > 500){
            return triangleNumber;
        }
    }
}

long problem13(){
    int bigNumberList[] = {3, 7, 1, 0, 7, 2, 8, 7, 5, 3, 3, 9, 0, 2, 1, 0, 2, 7, 9, 8, 7, 9, 7, 9, 9, 8, 2, 2, 0, 8, 3, 7, 5, 9, 0, 2, 4, 6, 5, 1, 0, 1, 3, 5, 7, 4, 0, 2, 5, 0, 4, 6, 3, 7, 6, 9, 3, 7, 6, 7, 7, 4, 9, 0, 0, 0, 9, 7, 1, 2, 6, 4, 8, 1, 2, 4, 8, 9, 6, 9, 7, 0, 0, 7, 8, 0, 5, 0, 4, 1, 7, 0, 1, 8, 2, 6, 0, 5, 3, 8, 7, 4, 3, 2, 4, 9, 8, 6, 1, 9, 9, 5, 2, 4, 7, 4, 1, 0, 5, 9, 4, 7, 4, 2, 3, 3, 3, 0, 9, 5, 1, 3, 0, 5, 8, 1, 2, 3, 7, 2, 6, 6, 1, 7, 3, 0, 9, 6, 2, 9, 9, 1, 9, 4, 2, 2, 1, 3, 3, 6, 3, 5, 7, 4, 1, 6, 1, 5, 7, 2, 5, 2, 2, 4, 3, 0, 5, 6, 3, 3, 0, 1, 8, 1, 1, 0, 7, 2, 4, 0, 6, 1, 5, 4, 9, 0, 8, 2, 5, 0, 2, 3, 0, 6, 7, 5, 8, 8, 2, 0, 7, 5, 3, 9, 3, 4, 6, 1, 7, 1, 1, 7, 1, 9, 8, 0, 3, 1, 0, 4, 2, 1, 0, 4, 7, 5, 1, 3, 7, 7, 8, 0, 6, 3, 2, 4, 6, 6, 7, 6, 8, 9, 2, 6, 1, 6, 7, 0, 6, 9, 6, 6, 2, 3, 6, 3, 3, 8, 2, 0, 1, 3, 6, 3, 7, 8, 4, 1, 8, 3, 8, 3, 6, 8, 4, 1, 7, 8, 7, 3, 4, 3, 6, 1, 7, 2, 6, 7, 5, 7, 2, 8, 1, 1, 2, 8, 7, 9, 8, 1, 2, 8, 4, 9, 9, 7, 9, 4, 0, 8, 0, 6, 5, 4, 8, 1, 9, 3, 1, 5, 9, 2, 6, 2, 1, 6, 9, 1, 2, 7, 5, 8, 8, 9, 8, 3, 2, 7, 3, 8, 4, 4, 2, 7, 4, 2, 2, 8, 9, 1, 7, 4, 3, 2, 5, 2, 0, 3, 2, 1, 9, 2, 3, 5, 8, 9, 4, 2, 2, 8, 7, 6, 7, 9, 6, 4, 8, 7, 6, 7, 0, 2, 7, 2, 1, 8, 9, 3, 1, 8, 4, 7, 4, 5, 1, 4, 4, 5, 7, 3, 6, 0, 0, 1, 3, 0, 6, 4, 3, 9, 0, 9, 1, 1, 6, 7, 2, 1, 6, 8, 5, 6, 8, 4, 4, 5, 8, 8, 7, 1, 1, 6, 0, 3, 1, 5, 3, 2, 7, 6, 7, 0, 3, 8, 6, 4, 8, 6, 1, 0, 5, 8, 4, 3, 0, 2, 5, 4, 3, 9, 9, 3, 9, 6, 1, 9, 8, 2, 8, 9, 1, 7, 5, 9, 3, 6, 6, 5, 6, 8, 6, 7, 5, 7, 9, 3, 4, 9, 5, 1, 6, 2, 1, 7, 6, 4, 5, 7, 1, 4, 1, 8, 5, 6, 5, 6, 0, 6, 2, 9, 5, 0, 2, 1, 5, 7, 2, 2, 3, 1, 9, 6, 5, 8, 6, 7, 5, 5, 0, 7, 9, 3, 2, 4, 1, 9, 3, 3, 3, 1, 6, 4, 9, 0, 6, 3, 5, 2, 4, 6, 2, 7, 4, 1, 9, 0, 4, 9, 2, 9, 1, 0, 1, 4, 3, 2, 4, 4, 5, 8, 1, 3, 8, 2, 2, 6, 6, 3, 3, 4, 7, 9, 4, 4, 7, 5, 8, 1, 7, 8, 9, 2, 5, 7, 5, 8, 6, 7, 7, 1, 8, 3, 3, 7, 2, 1, 7, 6, 6, 1, 9, 6, 3, 7, 5, 1, 5, 9, 0, 5, 7, 9, 2, 3, 9, 7, 2, 8, 2, 4, 5, 5, 9, 8, 8, 3, 8, 4, 0, 7, 5, 8, 2, 0, 3, 5, 6, 5, 3, 2, 5, 3, 5, 9, 3, 9, 9, 0, 0, 8, 4, 0, 2, 6, 3, 3, 5, 6, 8, 9, 4, 8, 8, 3, 0, 1, 8, 9, 4, 5, 8, 6, 2, 8, 2, 2, 7, 8, 2, 8, 8, 0, 1, 8, 1, 1, 9, 9, 3, 8, 4, 8, 2, 6, 2, 8, 2, 0, 1, 4, 2, 7, 8, 1, 9, 4, 1, 3, 9, 9, 4, 0, 5, 6, 7, 5, 8, 7, 1, 5, 1, 1, 7, 0, 0, 9, 4, 3, 9, 0, 3, 5, 3, 9, 8, 6, 6, 4, 3, 7, 2, 8, 2, 7, 1, 1, 2, 6, 5, 3, 8, 2, 9, 9, 8, 7, 2, 4, 0, 7, 8, 4, 4, 7, 3, 0, 5, 3, 1, 9, 0, 1, 0, 4, 2, 9, 3, 5, 8, 6, 8, 6, 5, 1, 5, 5, 0, 6, 0, 0, 6, 2, 9, 5, 8, 6, 4, 8, 6, 1, 5, 3, 2, 0, 7, 5, 2, 7, 3, 3, 7, 1, 9, 5, 9, 1, 9, 1, 4, 2, 0, 5, 1, 7, 2, 5, 5, 8, 2, 9, 7, 1, 6, 9, 3, 8, 8, 8, 7, 0, 7, 7, 1, 5, 4, 6, 6, 4, 9, 9, 1, 1, 5, 5, 9, 3, 4, 8, 7, 6, 0, 3, 5, 3, 2, 9, 2, 1, 7, 1, 4, 9, 7, 0, 0, 5, 6, 9, 3, 8, 5, 4, 3, 7, 0, 0, 7, 0, 5, 7, 6, 8, 2, 6, 6, 8, 4, 6, 2, 4, 6, 2, 1, 4, 9, 5, 6, 5, 0, 0, 7, 6, 4, 7, 1, 7, 8, 7, 2, 9, 4, 4, 3, 8, 3, 7, 7, 6, 0, 4, 5, 3, 2, 8, 2, 6, 5, 4, 1, 0, 8, 7, 5, 6, 8, 2, 8, 4, 4, 3, 1, 9, 1, 1, 9, 0, 6, 3, 4, 6, 9, 4, 0, 3, 7, 8, 5, 5, 2, 1, 7, 7, 7, 9, 2, 9, 5, 1, 4, 5, 3, 6, 1, 2, 3, 2, 7, 2, 5, 2, 5, 0, 0, 0, 2, 9, 6, 0, 7, 1, 0, 7, 5, 0, 8, 2, 5, 6, 3, 8, 1, 5, 6, 5, 6, 7, 1, 0, 8, 8, 5, 2, 5, 8, 3, 5, 0, 7, 2, 1, 4, 5, 8, 7, 6, 5, 7, 6, 1, 7, 2, 4, 1, 0, 9, 7, 6, 4, 4, 7, 3, 3, 9, 1, 1, 0, 6, 0, 7, 2, 1, 8, 2, 6, 5, 2, 3, 6, 8, 7, 7, 2, 2, 3, 6, 3, 6, 0, 4, 5, 1, 7, 4, 2, 3, 7, 0, 6, 9, 0, 5, 8, 5, 1, 8, 6, 0, 6, 6, 0, 4, 4, 8, 2, 0, 7, 6, 2, 1, 2, 0, 9, 8, 1, 3, 2, 8, 7, 8, 6, 0, 7, 3, 3, 9, 6, 9, 4, 1, 2, 8, 1, 1, 4, 2, 6, 6, 0, 4, 1, 8, 0, 8, 6, 8, 3, 0, 6, 1, 9, 3, 2, 8, 4, 6, 0, 8, 1, 1, 1, 9, 1, 0, 6, 1, 5, 5, 6, 9, 4, 0, 5, 1, 2, 6, 8, 9, 6, 9, 2, 5, 1, 9, 3, 4, 3, 2, 5, 4, 5, 1, 7, 2, 8, 3, 8, 8, 6, 4, 1, 9, 1, 8, 0, 4, 7, 0, 4, 9, 2, 9, 3, 2, 1, 5, 0, 5, 8, 6, 4, 2, 5, 6, 3, 0, 4, 9, 4, 8, 3, 6, 2, 4, 6, 7, 2, 2, 1, 6, 4, 8, 4, 3, 5, 0, 7, 6, 2, 0, 1, 7, 2, 7, 9, 1, 8, 0, 3, 9, 9, 4, 4, 6, 9, 3, 0, 0, 4, 7, 3, 2, 9, 5, 6, 3, 4, 0, 6, 9, 1, 1, 5, 7, 3, 2, 4, 4, 4, 3, 8, 6, 9, 0, 8, 1, 2, 5, 7, 9, 4, 5, 1, 4, 0, 8, 9, 0, 5, 7, 7, 0, 6, 2, 2, 9, 4, 2, 9, 1, 9, 7, 1, 0, 7, 9, 2, 8, 2, 0, 9, 5, 5, 0, 3, 7, 6, 8, 7, 5, 2, 5, 6, 7, 8, 7, 7, 3, 0, 9, 1, 8, 6, 2, 5, 4, 0, 7, 4, 4, 9, 6, 9, 8, 4, 4, 5, 0, 8, 3, 3, 0, 3, 9, 3, 6, 8, 2, 1, 2, 6, 1, 8, 3, 3, 6, 3, 8, 4, 8, 2, 5, 3, 3, 0, 1, 5, 4, 6, 8, 6, 1, 9, 6, 1, 2, 4, 3, 4, 8, 7, 6, 7, 6, 8, 1, 2, 9, 7, 5, 3, 4, 3, 7, 5, 9, 4, 6, 5, 1, 5, 8, 0, 3, 8, 6, 2, 8, 7, 5, 9, 2, 8, 7, 8, 4, 9, 0, 2, 0, 1, 5, 2, 1, 6, 8, 5, 5, 5, 4, 8, 2, 8, 7, 1, 7, 2, 0, 1, 2, 1, 9, 2, 5, 7, 7, 6, 6, 9, 5, 4, 7, 8, 1, 8, 2, 8, 3, 3, 7, 5, 7, 9, 9, 3, 1, 0, 3, 6, 1, 4, 7, 4, 0, 3, 5, 6, 8, 5, 6, 4, 4, 9, 0, 9, 5, 5, 2, 7, 0, 9, 7, 8, 6, 4, 7, 9, 7, 5, 8, 1, 1, 6, 7, 2, 6, 3, 2, 0, 1, 0, 0, 4, 3, 6, 8, 9, 7, 8, 4, 2, 5, 5, 3, 5, 3, 9, 9, 2, 0, 9, 3, 1, 8, 3, 7, 4, 4, 1, 4, 9, 7, 8, 0, 6, 8, 6, 0, 9, 8, 4, 4, 8, 4, 0, 3, 0, 9, 8, 1, 2, 9, 0, 7, 7, 7, 9, 1, 7, 9, 9, 0, 8, 8, 2, 1, 8, 7, 9, 5, 3, 2, 7, 3, 6, 4, 4, 7, 5, 6, 7, 5, 5, 9, 0, 8, 4, 8, 0, 3, 0, 8, 7, 0, 8, 6, 9, 8, 7, 5, 5, 1, 3, 9, 2, 7, 1, 1, 8, 5, 4, 5, 1, 7, 0, 7, 8, 5, 4, 4, 1, 6, 1, 8, 5, 2, 4, 2, 4, 3, 2, 0, 6, 9, 3, 1, 5, 0, 3, 3, 2, 5, 9, 9, 5, 9, 4, 0, 6, 8, 9, 5, 7, 5, 6, 5, 3, 6, 7, 8, 2, 1, 0, 7, 0, 7, 4, 9, 2, 6, 9, 6, 6, 5, 3, 7, 6, 7, 6, 3, 2, 6, 2, 3, 5, 4, 4, 7, 2, 1, 0, 6, 9, 7, 9, 3, 9, 5, 0, 6, 7, 9, 6, 5, 2, 6, 9, 4, 7, 4, 2, 5, 9, 7, 7, 0, 9, 7, 3, 9, 1, 6, 6, 6, 9, 3, 7, 6, 3, 0, 4, 2, 6, 3, 3, 9, 8, 7, 0, 8, 5, 4, 1, 0, 5, 2, 6, 8, 4, 7, 0, 8, 2, 9, 9, 0, 8, 5, 2, 1, 1, 3, 9, 9, 4, 2, 7, 3, 6, 5, 7, 3, 4, 1, 1, 6, 1, 8, 2, 7, 6, 0, 3, 1, 5, 0, 0, 1, 2, 7, 1, 6, 5, 3, 7, 8, 6, 0, 7, 3, 6, 1, 5, 0, 1, 0, 8, 0, 8, 5, 7, 0, 0, 9, 1, 4, 9, 9, 3, 9, 5, 1, 2, 5, 5, 7, 0, 2, 8, 1, 9, 8, 7, 4, 6, 0, 0, 4, 3, 7, 5, 3, 5, 8, 2, 9, 0, 3, 5, 3, 1, 7, 4, 3, 4, 7, 1, 7, 3, 2, 6, 9, 3, 2, 1, 2, 3, 5, 7, 8, 1, 5, 4, 9, 8, 2, 6, 2, 9, 7, 4, 2, 5, 5, 2, 7, 3, 7, 3, 0, 7, 9, 4, 9, 5, 3, 7, 5, 9, 7, 6, 5, 1, 0, 5, 3, 0, 5, 9, 4, 6, 9, 6, 6, 0, 6, 7, 6, 8, 3, 1, 5, 6, 5, 7, 4, 3, 7, 7, 1, 6, 7, 4, 0, 1, 8, 7, 5, 2, 7, 5, 8, 8, 9, 0, 2, 8, 0, 2, 5, 7, 1, 7, 3, 3, 2, 2, 9, 6, 1, 9, 1, 7, 6, 6, 6, 8, 7, 1, 3, 8, 1, 9, 9, 3, 1, 8, 1, 1, 0, 4, 8, 7, 7, 0, 1, 9, 0, 2, 7, 1, 2, 5, 2, 6, 7, 6, 8, 0, 2, 7, 6, 0, 7, 8, 0, 0, 3, 0, 1, 3, 6, 7, 8, 6, 8, 0, 9, 9, 2, 5, 2, 5, 4, 6, 3, 4, 0, 1, 0, 6, 1, 6, 3, 2, 8, 6, 6, 5, 2, 6, 3, 6, 2, 7, 0, 2, 1, 8, 5, 4, 0, 4, 9, 7, 7, 0, 5, 5, 8, 5, 6, 2, 9, 9, 4, 6, 5, 8, 0, 6, 3, 6, 2, 3, 7, 9, 9, 3, 1, 4, 0, 7, 4, 6, 2, 5, 5, 9, 6, 2, 2, 4, 0, 7, 4, 4, 8, 6, 9, 0, 8, 2, 3, 1, 1, 7, 4, 9, 7, 7, 7, 9, 2, 3, 6, 5, 4, 6, 6, 2, 5, 7, 2, 4, 6, 9, 2, 3, 3, 2, 2, 8, 1, 0, 9, 1, 7, 1, 4, 1, 9, 1, 4, 3, 0, 2, 8, 8, 1, 9, 7, 1, 0, 3, 2, 8, 8, 5, 9, 7, 8, 0, 6, 6, 6, 9, 7, 6, 0, 8, 9, 2, 9, 3, 8, 6, 3, 8, 2, 8, 5, 0, 2, 5, 3, 3, 3, 4, 0, 3, 3, 4, 4, 1, 3, 0, 6, 5, 5, 7, 8, 0, 1, 6, 1, 2, 7, 8, 1, 5, 9, 2, 1, 8, 1, 5, 0, 0, 5, 5, 6, 1, 8, 6, 8, 8, 3, 6, 4, 6, 8, 4, 2, 0, 0, 9, 0, 4, 7, 0, 2, 3, 0, 5, 3, 0, 8, 1, 1, 7, 2, 8, 1, 6, 4, 3, 0, 4, 8, 7, 6, 2, 3, 7, 9, 1, 9, 6, 9, 8, 4, 2, 4, 8, 7, 2, 5, 5, 0, 3, 6, 6, 3, 8, 7, 8, 4, 5, 8, 3, 1, 1, 4, 8, 7, 6, 9, 6, 9, 3, 2, 1, 5, 4, 9, 0, 2, 8, 1, 0, 4, 2, 4, 0, 2, 0, 1, 3, 8, 3, 3, 5, 1, 2, 4, 4, 6, 2, 1, 8, 1, 4, 4, 1, 7, 7, 3, 4, 7, 0, 6, 3, 7, 8, 3, 2, 9, 9, 4, 9, 0, 6, 3, 6, 2, 5, 9, 6, 6, 6, 4, 9, 8, 5, 8, 7, 6, 1, 8, 2, 2, 1, 2, 2, 5, 2, 2, 5, 5, 1, 2, 4, 8, 6, 7, 6, 4, 5, 3, 3, 6, 7, 7, 2, 0, 1, 8, 6, 9, 7, 1, 6, 9, 8, 5, 4, 4, 3, 1, 2, 4, 1, 9, 5, 7, 2, 4, 0, 9, 9, 1, 3, 9, 5, 9, 0, 0, 8, 9, 5, 2, 3, 1, 0, 0, 5, 8, 8, 2, 2, 9, 5, 5, 4, 8, 2, 5, 5, 3, 0, 0, 2, 6, 3, 5, 2, 0, 7, 8, 1, 5, 3, 2, 2, 9, 6, 7, 9, 6, 2, 4, 9, 4, 8, 1, 6, 4, 1, 9, 5, 3, 8, 6, 8, 2, 1, 8, 7, 7, 4, 7, 6, 0, 8, 5, 3, 2, 7, 1, 3, 2, 2, 8, 5, 7, 2, 3, 1, 1, 0, 4, 2, 4, 8, 0, 3, 4, 5, 6, 1, 2, 4, 8, 6, 7, 6, 9, 7, 0, 6, 4, 5, 0, 7, 9, 9, 5, 2, 3, 6, 3, 7, 7, 7, 4, 2, 4, 2, 5, 3, 5, 4, 1, 1, 2, 9, 1, 6, 8, 4, 2, 7, 6, 8, 6, 5, 5, 3, 8, 9, 2, 6, 2, 0, 5, 0, 2, 4, 9, 1, 0, 3, 2, 6, 5, 7, 2, 9, 6, 7, 2, 3, 7, 0, 1, 9, 1, 3, 2, 7, 5, 7, 2, 5, 6, 7, 5, 2, 8, 5, 6, 5, 3, 2, 4, 8, 2, 5, 8, 2, 6, 5, 4, 6, 3, 0, 9, 2, 2, 0, 7, 0, 5, 8, 5, 9, 6, 5, 2, 2, 2, 9, 7, 9, 8, 8, 6, 0, 2, 7, 2, 2, 5, 8, 3, 3, 1, 9, 1, 3, 1, 2, 6, 3, 7, 5, 1, 4, 7, 3, 4, 1, 9, 9, 4, 8, 8, 9, 5, 3, 4, 7, 6, 5, 7, 4, 5, 5, 0, 1, 1, 8, 4, 9, 5, 7, 0, 1, 4, 5, 4, 8, 7, 9, 2, 8, 8, 9, 8, 4, 8, 5, 6, 8, 2, 7, 7, 2, 6, 0, 7, 7, 7, 1, 3, 7, 2, 1, 4, 0, 3, 7, 9, 8, 8, 7, 9, 7, 1, 5, 3, 8, 2, 9, 8, 2, 0, 3, 7, 8, 3, 0, 3, 1, 4, 7, 3, 5, 2, 7, 7, 2, 1, 5, 8, 0, 3, 4, 8, 1, 4, 4, 5, 1, 3, 4, 9, 1, 3, 7, 3, 2, 2, 6, 6, 5, 1, 3, 8, 1, 3, 4, 8, 2, 9, 5, 4, 3, 8, 2, 9, 1, 9, 9, 9, 1, 8, 1, 8, 0, 2, 7, 8, 9, 1, 6, 5, 2, 2, 4, 3, 1, 0, 2, 7, 3, 9, 2, 2, 5, 1, 1, 2, 2, 8, 6, 9, 5, 3, 9, 4, 0, 9, 5, 7, 9, 5, 3, 0, 6, 6, 4, 0, 5, 2, 3, 2, 6, 3, 2, 5, 3, 8, 0, 4, 4, 1, 0, 0, 0, 5, 9, 6, 5, 4, 9, 3, 9, 1, 5, 9, 8, 7, 9, 5, 9, 3, 6, 3, 5, 2, 9, 7, 4, 6, 1, 5, 2, 1, 8, 5, 5, 0, 2, 3, 7, 1, 3, 0, 7, 6, 4, 2, 2, 5, 5, 1, 2, 1, 1, 8, 3, 6, 9, 3, 8, 0, 3, 5, 8, 0, 3, 8, 8, 5, 8, 4, 9, 0, 3, 4, 1, 6, 9, 8, 1, 1, 6, 2, 2, 2, 0, 7, 2, 9, 7, 7, 1, 8, 6, 1, 5, 8, 2, 3, 6, 6, 7, 8, 4, 2, 4, 6, 8, 9, 1, 5, 7, 9, 9, 3, 5, 3, 2, 9, 6, 1, 9, 2, 2, 6, 2, 4, 6, 7, 9, 5, 7, 1, 9, 4, 4, 0, 1, 2, 6, 9, 0, 4, 3, 8, 7, 7, 1, 0, 7, 2, 7, 5, 0, 4, 8, 1, 0, 2, 3, 9, 0, 8, 9, 5, 5, 2, 3, 5, 9, 7, 4, 5, 7, 2, 3, 1, 8, 9, 7, 0, 6, 7, 7, 2, 5, 4, 7, 9, 1, 5, 0, 6, 1, 5, 0, 5, 5, 0, 4, 9, 5, 3, 9, 2, 2, 9, 7, 9, 5, 3, 0, 9, 0, 1, 1, 2, 9, 9, 6, 7, 5, 1, 9, 8, 6, 1, 8, 8, 0, 8, 8, 2, 2, 5, 8, 7, 5, 3, 1, 4, 5, 2, 9, 5, 8, 4, 0, 9, 9, 2, 5, 1, 2, 0, 3, 8, 2, 9, 0, 0, 9, 4, 0, 7, 7, 7, 0, 7, 7, 5, 6, 7, 2, 1, 1, 3, 0, 6, 7, 3, 9, 7, 0, 8, 3, 0, 4, 7, 2, 4, 4, 8, 3, 8, 1, 6, 5, 3, 3, 8, 7, 3, 5, 0, 2, 3, 4, 0, 8, 4, 5, 6, 4, 7, 0, 5, 8, 0, 7, 7, 3, 0, 8, 8, 2, 9, 5, 9, 1, 7, 4, 7, 6, 7, 1, 4, 0, 3, 6, 3, 1, 9, 8, 0, 0, 8, 1, 8, 7, 1, 2, 9, 0, 1, 1, 8, 7, 5, 4, 9, 1, 3, 1, 0, 5, 4, 7, 1, 2, 6, 5, 8, 1, 9, 7, 6, 2, 3, 3, 3, 1, 0, 4, 4, 8, 1, 8, 3, 8, 6, 2, 6, 9, 5, 1, 5, 4, 5, 6, 3, 3, 4, 9, 2, 6, 3, 6, 6, 5, 7, 2, 8, 9, 7, 5, 6, 3, 4, 0, 0, 5, 0, 0, 4, 2, 8, 4, 6, 2, 8, 0, 1, 8, 3, 5, 1, 7, 0, 7, 0, 5, 2, 7, 8, 3, 1, 8, 3, 9, 4, 2, 5, 8, 8, 2, 1, 4, 5, 5, 2, 1, 2, 2, 7, 2, 5, 1, 2, 5, 0, 3, 2, 7, 5, 5, 1, 2, 1, 6, 0, 3, 5, 4, 6, 9, 8, 1, 2, 0, 0, 5, 8, 1, 7, 6, 2, 1, 6, 5, 2, 1, 2, 8, 2, 7, 6, 5, 2, 7, 5, 1, 6, 9, 1, 2, 9, 6, 8, 9, 7, 7, 8, 9, 3, 2, 2, 3, 8, 1, 9, 5, 7, 3, 4, 3, 2, 9, 3, 3, 9, 9, 4, 6, 4, 3, 7, 5, 0, 1, 9, 0, 7, 8, 3, 6, 9, 4, 5, 7, 6, 5, 8, 8, 3, 3, 5, 2, 3, 9, 9, 8, 8, 6, 7, 5, 5, 0, 6, 1, 6, 4, 9, 6, 5, 1, 8, 4, 7, 7, 5, 1, 8, 0, 7, 3, 8, 1, 6, 8, 8, 3, 7, 8, 6, 1, 0, 9, 1, 5, 2, 7, 3, 5, 7, 9, 2, 9, 7, 0, 1, 3, 3, 7, 6, 2, 1, 7, 7, 8, 4, 2, 7, 5, 2, 1, 9, 2, 6, 2, 3, 4, 0, 1, 9, 4, 2, 3, 9, 9, 6, 3, 9, 1, 6, 8, 0, 4, 4, 9, 8, 3, 9, 9, 3, 1, 7, 3, 3, 1, 2, 7, 3, 1, 3, 2, 9, 2, 4, 1, 8, 5, 7, 0, 7, 1, 4, 7, 3, 4, 9, 5, 6, 6, 9, 1, 6, 6, 7, 4, 6, 8, 7, 6, 3, 4, 6, 6, 0, 9, 1, 5, 0, 3, 5, 9, 1, 4, 6, 7, 7, 5, 0, 4, 9, 9, 5, 1, 8, 6, 7, 1, 4, 3, 0, 2, 3, 5, 2, 1, 9, 6, 2, 8, 8, 9, 4, 8, 9, 0, 1, 0, 2, 4, 2, 3, 3, 2, 5, 1, 1, 6, 9, 1, 3, 6, 1, 9, 6, 2, 6, 6, 2, 2, 7, 3, 2, 6, 7, 4, 6, 0, 8, 0, 0, 5, 9, 1, 5, 4, 7, 4, 7, 1, 8, 3, 0, 7, 9, 8, 3, 9, 2, 8, 6, 8, 5, 3, 5, 2, 0, 6, 9, 4, 6, 9, 4, 4, 5, 4, 0, 7, 2, 4, 7, 6, 8, 4, 1, 8, 2, 2, 5, 2, 4, 6, 7, 4, 4, 1, 7, 1, 6, 1, 5, 1, 4, 0, 3, 6, 4, 2, 7, 9, 8, 2, 2, 7, 3, 3, 4, 8, 0, 5, 5, 5, 5, 6, 2, 1, 4, 8, 1, 8, 9, 7, 1, 4, 2, 6, 1, 7, 9, 1, 0, 3, 4, 2, 5, 9, 8, 6, 4, 7, 2, 0, 4, 5, 1, 6, 8, 9, 3, 9, 8, 9, 4, 2, 2, 1, 7, 9, 8, 2, 6, 0, 8, 8, 0, 7, 6, 8, 5, 2, 8, 7, 7, 8, 3, 6, 4, 6, 1, 8, 2, 7, 9, 9, 3, 4, 6, 3, 1, 3, 7, 6, 7, 7, 5, 4, 3, 0, 7, 8, 0, 9, 3, 6, 3, 3, 3, 3, 0, 1, 8, 9, 8, 2, 6, 4, 2, 0, 9, 0, 1, 0, 8, 4, 8, 8, 0, 2, 5, 2, 1, 6, 7, 4, 6, 7, 0, 8, 8, 3, 2, 1, 5, 1, 2, 0, 1, 8, 5, 8, 8, 3, 5, 4, 3, 2, 2, 3, 8, 1, 2, 8, 7, 6, 9, 5, 2, 7, 8, 6, 7, 1, 3, 2, 9, 6, 1, 2, 4, 7, 4, 7, 8, 2, 4, 6, 4, 5, 3, 8, 6, 3, 6, 9, 9, 3, 0, 0, 9, 0, 4, 9, 3, 1, 0, 3, 6, 3, 6, 1, 9, 7, 6, 3, 8, 7, 8, 0, 3, 9, 6, 2, 1, 8, 4, 0, 7, 3, 5, 7, 2, 3, 9, 9, 7, 9, 4, 2, 2, 3, 4, 0, 6, 2, 3, 5, 3, 9, 3, 8, 0, 8, 3, 3, 9, 6, 5, 1, 3, 2, 7, 4, 0, 8, 0, 1, 1, 1, 1, 6, 6, 6, 6, 2, 7, 8, 9, 1, 9, 8, 1, 4, 8, 8, 0, 8, 7, 7, 9, 7, 9, 4, 1, 8, 7, 6, 8, 7, 6, 1, 4, 4, 2, 3, 0, 0, 3, 0, 9, 8, 4, 4, 9, 0, 8, 5, 1, 4, 1, 1, 6, 0, 6, 6, 1, 8, 2, 6, 2, 9, 3, 6, 8, 2, 8, 3, 6, 7, 6, 4, 7, 4, 4, 7, 7, 9, 2, 3, 9, 1, 8, 0, 3, 3, 5, 1, 1, 0, 9, 8, 9, 0, 6, 9, 7, 9, 0, 7, 1, 4, 8, 5, 7, 8, 6, 9, 4, 4, 0, 8, 9, 5, 5, 2, 9, 9, 0, 6, 5, 3, 6, 4, 0, 4, 4, 7, 4, 2, 5, 5, 7, 6, 0, 8, 3, 6, 5, 9, 9, 7, 6, 6, 4, 5, 7, 9, 5, 0, 9, 6, 6, 6, 0, 2, 4, 3, 9, 6, 4, 0, 9, 9, 0, 5, 3, 8, 9, 6, 0, 7, 1, 2, 0, 1, 9, 8, 2, 1, 9, 9, 7, 6, 0, 4, 7, 5, 9, 9, 4, 9, 0, 1, 9, 7, 2, 3, 0, 2, 9, 7, 6, 4, 9, 1, 3, 9, 8, 2, 6, 8, 0, 0, 3, 2, 9, 7, 3, 1, 5, 6, 0, 3, 7, 1, 2, 0, 0, 4, 1, 3, 7, 7, 9, 0, 3, 7, 8, 5, 5, 6, 6, 0, 8, 5, 0, 8, 9, 2, 5, 2, 1, 6, 7, 3, 0, 9, 3, 9, 3, 1, 9, 8, 7, 2, 7, 5, 0, 2, 7, 5, 4, 6, 8, 9, 0, 6, 9, 0, 3, 7, 0, 7, 5, 3, 9, 4, 1, 3, 0, 4, 2, 6, 5, 2, 3, 1, 5, 0, 1, 1, 9, 4, 8, 0, 9, 3, 7, 7, 2, 4, 5, 0, 4, 8, 7, 9, 5, 1, 5, 0, 9, 5, 4, 1, 0, 0, 9, 2, 1, 6, 4, 5, 8, 6, 3, 7, 5, 4, 7, 1, 0, 5, 9, 8, 4, 3, 6, 7, 9, 1, 7, 8, 6, 3, 9, 1, 6, 7, 0, 2, 1, 1, 8, 7, 4, 9, 2, 4, 3, 1, 9, 9, 5, 7, 0, 0, 6, 4, 1, 9, 1, 7, 9, 6, 9, 7, 7, 7, 5, 9, 9, 0, 2, 8, 3, 0, 0, 6, 9, 9, 1, 5, 3, 6, 8, 7, 1, 3, 7, 1, 1, 9, 3, 6, 6, 1, 4, 9, 5, 2, 8, 1, 1, 3, 0, 5, 8, 7, 6, 3, 8, 0, 2, 7, 8, 4, 1, 0, 7, 5, 4, 4, 4, 9, 7, 3, 3, 0, 7, 8, 4, 0, 7, 8, 9, 9, 2, 3, 1, 1, 5, 5, 3, 5, 5, 6, 2, 5, 6, 1, 1, 4, 2, 3, 2, 2, 4, 2, 3, 2, 5, 5, 0, 3, 3, 6, 8, 5, 4, 4, 2, 4, 8, 8, 9, 1, 7, 3, 5, 3, 4, 4, 8, 8, 9, 9, 1, 1, 5, 0, 1, 4, 4, 0, 6, 4, 8, 0, 2, 0, 3, 6, 9, 0, 6, 8, 0, 6, 3, 9, 6, 0, 6, 7, 2, 3, 2, 2, 1, 9, 3, 2, 0, 4, 1, 4, 9, 5, 3, 5, 4, 1, 5, 0, 3, 1, 2, 8, 8, 8, 0, 3, 3, 9, 5, 3, 6, 0, 5, 3, 2, 9, 9, 3, 4, 0, 3, 6, 8, 0, 0, 6, 9, 7, 7, 7, 1, 0, 6, 5, 0, 5, 6, 6, 6, 3, 1, 9, 5, 4, 8, 1, 2, 3, 4, 8, 8, 0, 6, 7, 3, 2, 1, 0, 1, 4, 6, 7, 3, 9, 0, 5, 8, 5, 6, 8, 5, 5, 7, 9, 3, 4, 5, 8, 1, 4, 0, 3, 6, 2, 7, 8, 2, 2, 7, 0, 3, 2, 8, 0, 8, 2, 6, 1, 6, 5, 7, 0, 7, 7, 3, 9, 4, 8, 3, 2, 7, 5, 9, 2, 2, 3, 2, 8, 4, 5, 9, 4, 1, 7, 0, 6, 5, 2, 5, 0, 9, 4, 5, 1, 2, 3, 2, 5, 2, 3, 0, 6, 0, 8, 2, 2, 9, 1, 8, 8, 0, 2, 0, 5, 8, 7, 7, 7, 3, 1, 9, 7, 1, 9, 8, 3, 9, 4, 5, 0, 1, 8, 0, 8, 8, 8, 0, 7, 2, 4, 2, 9, 6, 6, 1, 9, 8, 0, 8, 1, 1, 1, 9, 7, 7, 7, 1, 5, 8, 5, 4, 2, 5, 0, 2, 0, 1, 6, 5, 4, 5, 0, 9, 0, 4, 1, 3, 2, 4, 5, 8, 0, 9, 7, 8, 6, 8, 8, 2, 7, 7, 8, 9, 4, 8, 7, 2, 1, 8, 5, 9, 6, 1, 7, 7, 2, 1, 0, 7, 8, 3, 8, 4, 3, 5, 0, 6, 9, 1, 8, 6, 1, 5, 5, 4, 3, 5, 6, 6, 2, 8, 8, 4, 0, 6, 2, 2, 5, 7, 4, 7, 3, 6, 9, 2, 2, 8, 4, 5, 0, 9, 5, 1, 6, 2, 0, 8, 4, 9, 6, 0, 3, 9, 8, 0, 1, 3, 4, 0, 0, 1, 7, 2, 3, 9, 3, 0, 6, 7, 1, 6, 6, 6, 8, 2, 3, 5, 5, 5, 2, 4, 5, 2, 5, 2, 8, 0, 4, 6, 0, 9, 7, 2, 2, 5, 3, 5, 0, 3, 5, 3, 4, 2, 2, 6, 4, 7, 2, 5, 2, 4, 2, 5, 0, 8, 7, 4, 0, 5, 4, 0, 7, 5, 5, 9, 1, 7, 8, 9, 7, 8, 1, 2, 6, 4, 3, 3, 0, 3, 3, 1, 6, 9, 0};
    long sum = 0;
    for (int row = 0; row <= 99; row += 1){
        for (int index = 0; index <= 10; index += 1){
            sum += bigNumberList[index + row*50]*(pow(10,10-index));
        }
    }
    return sum;
}

int problem14(){
    int mostSteps = 0;
    int largestNumber = 0;
    for (int i = 1; i < 1000000; i += 1){
        if (collatzSequence(i) > mostSteps){
            mostSteps = collatzSequence(i);
            largestNumber = i;
        }
        
    }
    return largestNumber;
}

long problem15(){
    long matrixArray[441];
    long tempSum;
    int leftValue;
    int topValue;
    long debugValue;
    for (int index = 0; index < 441; index += 1){
        matrixArray[index] = 0;
    }
    for (int row = 0; row < 21; row +=1){
        for (int element = 0; element < 21; element += 1){
            tempSum = 0;
            leftValue = (row*21+element-1);
            topValue = ((row-1)*21+element);
            if (element != 0){
                tempSum += matrixArray[leftValue];
            }
            if (topValue >= 0 && topValue <= 441){
                tempSum += matrixArray[topValue];
            }
            if (element == 0  && row == 0){
                matrixArray[0] = 1;
                debugValue = 1;
            }
            else{
                matrixArray[row*21+element] = tempSum;
                debugValue = tempSum;
            };
        }
    }
    return matrixArray[440];
}

int problem16(){
    int digits[500] = {0}, highest = 0, sum = 0;
    
    digits[0] = 1;
    
    for (int i = 1; i <= 1000; i++){
        int carry = 0, product = 1;
        
        for (int j = 0; j <= highest; j++){
            product = digits[j]*2+carry;
            digits[j] = product%10;
            carry = product/10;
            
            if ((carry != 0) && (j == highest)){
                highest++;
            }
        }
    }
    
    for (int i = 0; i <= highest; i++){
        sum += digits[i];
    }
    return sum;
}

int problem17(){
    int sum = 0;
    for (int i = 1; i <= 1000; i+=1){
        sum += hundred_sum(i);
    }
    return sum;
}

int problem18(){
    int pyramid[] = {75,95,64,17,47,82,18,35,87,10,20,4,82,47,65,19,1,23,75,3,34,88,2,77,73,7,63,67,99,65,4,28,6,16,70,92,41,41,26,56,83,40,80,70,33,41,48,72,33,47,32,37,16,94,29,53,71,44,65,25,43,91,52,97,51,14,70,11,33,28,77,73,17,78,39,68,17,57,91,71,52,38,17,14,91,43,58,50,27,29,48,63,66,4,68,89,53,67,30,73,16,69,87,40,31,4,62,98,27,23,9,70,98,73,93,38,53,60,4,23};
    int position;
    for (int row = 15; row > 0; row-=1){
        position = summation(row)-1;
        for (int slot = row-1; slot > 0; slot-=1){
            if (pyramid[position-slot] > pyramid[position-slot+1])
                pyramid[position-slot-row+1] += pyramid[position-slot];
            else
                pyramid[position-slot-row+1] += pyramid[position-slot+1];
        }
    }
    return pyramid[0];
}

int problem20(){
    int digits[5000] = {0}, highest = 0, sum = 0;
    
    digits[0] = 1;
    
    for (int i = 1; i <= 100; i++){
        int carry = 0, product = 1;
        
        for (int j = 0; j <= highest; j++){
            product = digits[j]*i+carry;
            digits[j] = product%10;
            carry = product/10;
            
            if ((carry != 0) && (j == highest)){
                highest++;
            }
        }
    }
    
    for (int i = 0; i <= highest; i++){
        sum += digits[i];
    }
    return sum;
}



int problem21(){
    int sum = 0;
    for (int i = 1; i < 10000; i+=1){
        if (is_amicable(i))
            sum+=i;
    }
    return sum;
}

int problem22(){
    char nameList[] = {"AARON,ABBEY,ABBIE,ABBY,ABDUL,ABE,ABEL,ABIGAIL,ABRAHAM,ABRAM,ADA,ADAH,ADALBERTO,ADALINE,ADAM,ADAN,ADDIE,ADELA,ADELAIDA,ADELAIDE,ADELE,ADELIA,ADELINA,ADELINE,ADELL,ADELLA,ADELLE,ADENA,ADINA,ADOLFO,ADOLPH,ADRIA,ADRIAN,ADRIANA,ADRIANE,ADRIANNA,ADRIANNE,ADRIEN,ADRIENE,ADRIENNE,AFTON,AGATHA,AGNES,AGNUS,AGRIPINA,AGUEDA,AGUSTIN,AGUSTINA,AHMAD,AHMED,AI,AIDA,AIDE,AIKO,AILEEN,AILENE,AIMEE,AISHA,AJA,AKIKO,AKILAH,AL,ALAINA,ALAINE,ALAN,ALANA,ALANE,ALANNA,ALAYNA,ALBA,ALBERT,ALBERTA,ALBERTHA,ALBERTINA,ALBERTINE,ALBERTO,ALBINA,ALDA,ALDEN,ALDO,ALEASE,ALEC,ALECIA,ALEEN,ALEIDA,ALEISHA,ALEJANDRA,ALEJANDRINA,ALEJANDRO,ALENA,ALENE,ALESHA,ALESHIA,ALESIA,ALESSANDRA,ALETA,ALETHA,ALETHEA,ALETHIA,ALEX,ALEXA,ALEXANDER,ALEXANDRA,ALEXANDRIA,ALEXIA,ALEXIS,ALFONSO,ALFONZO,ALFRED,ALFREDA,ALFREDIA,ALFREDO,ALI,ALIA,ALICA,ALICE,ALICIA,ALIDA,ALINA,ALINE,ALISA,ALISE,ALISHA,ALISHIA,ALISIA,ALISON,ALISSA,ALITA,ALIX,ALIZA,ALLA,ALLAN,ALLEEN,ALLEGRA,ALLEN,ALLENA,ALLENE,ALLIE,ALLINE,ALLISON,ALLYN,ALLYSON,ALMA,ALMEDA,ALMETA,ALONA,ALONSO,ALONZO,ALPHA,ALPHONSE,ALPHONSO,ALTA,ALTAGRACIA,ALTHA,ALTHEA,ALTON,ALVA,ALVARO,ALVERA,ALVERTA,ALVIN,ALVINA,ALYCE,ALYCIA,ALYSA,ALYSE,ALYSHA,ALYSIA,ALYSON,ALYSSA,AMADA,AMADO,AMAL,AMALIA,AMANDA,AMBER,AMBERLY,AMBROSE,AMEE,AMELIA,AMERICA,AMI,AMIE,AMIEE,AMINA,AMIRA,AMMIE,AMOS,AMPARO,AMY,AN,ANA,ANABEL,ANALISA,ANAMARIA,ANASTACIA,ANASTASIA,ANDERA,ANDERSON,ANDRA,ANDRE,ANDREA,ANDREAS,ANDREE,ANDRES,ANDREW,ANDRIA,ANDY,ANETTE,ANGEL,ANGELA,ANGELE,ANGELENA,ANGELES,ANGELIA,ANGELIC,ANGELICA,ANGELIKA,ANGELINA,ANGELINE,ANGELIQUE,ANGELITA,ANGELLA,ANGELO,ANGELYN,ANGIE,ANGILA,ANGLA,ANGLE,ANGLEA,ANH,ANIBAL,ANIKA,ANISA,ANISHA,ANISSA,ANITA,ANITRA,ANJA,ANJANETTE,ANJELICA,ANN,ANNA,ANNABEL,ANNABELL,ANNABELLE,ANNALEE,ANNALISA,ANNAMAE,ANNAMARIA,ANNAMARIE,ANNE,ANNELIESE,ANNELLE,ANNEMARIE,ANNETT,ANNETTA,ANNETTE,ANNICE,ANNIE,ANNIKA,ANNIS,ANNITA,ANNMARIE,ANTHONY,ANTIONE,ANTIONETTE,ANTOINE,ANTOINETTE,ANTON,ANTONE,ANTONETTA,ANTONETTE,ANTONIA,ANTONIETTA,ANTONINA,ANTONIO,ANTONY,ANTWAN,ANYA,APOLONIA,APRIL,APRYL,ARA,ARACELI,ARACELIS,ARACELY,ARCELIA,ARCHIE,ARDATH,ARDELIA,ARDELL,ARDELLA,ARDELLE,ARDEN,ARDIS,ARDITH,ARETHA,ARGELIA,ARGENTINA,ARIANA,ARIANE,ARIANNA,ARIANNE,ARICA,ARIE,ARIEL,ARIELLE,ARLA,ARLEAN,ARLEEN,ARLEN,ARLENA,ARLENE,ARLETHA,ARLETTA,ARLETTE,ARLIE,ARLINDA,ARLINE,ARLYNE,ARMAND,ARMANDA,ARMANDINA,ARMANDO,ARMIDA,ARMINDA,ARNETTA,ARNETTE,ARNITA,ARNOLD,ARNOLDO,ARNULFO,ARON,ARRON,ART,ARTHUR,ARTIE,ARTURO,ARVILLA,ASA,ASHA,ASHANTI,ASHELY,ASHLEA,ASHLEE,ASHLEIGH,ASHLEY,ASHLI,ASHLIE,ASHLY,ASHLYN,ASHTON,ASIA,ASLEY,ASSUNTA,ASTRID,ASUNCION,ATHENA,AUBREY,AUDIE,AUDRA,AUDREA,AUDREY,AUDRIA,AUDRIE,AUDRY,AUGUST,AUGUSTA,AUGUSTINA,AUGUSTINE,AUGUSTUS,AUNDREA,AURA,AUREA,AURELIA,AURELIO,AURORA,AURORE,AUSTIN,AUTUMN,AVA,AVELINA,AVERY,AVIS,AVRIL,AWILDA,AYAKO,AYANA,AYANNA,AYESHA,AZALEE,AZUCENA,AZZIE,BABARA,BABETTE,BAILEY,BAMBI,BAO,BARABARA,BARB,BARBAR,BARBARA,BARBERA,BARBIE,BARBRA,BARI,BARNEY,BARRETT,BARRIE,BARRY,BART,BARTON,BASIL,BASILIA,BEA,BEATA,BEATRICE,BEATRIS,BEATRIZ,BEAU,BEAULAH,BEBE,BECKI,BECKIE,BECKY,BEE,BELEN,BELIA,BELINDA,BELKIS,BELL,BELLA,BELLE,BELVA,BEN,BENEDICT,BENITA,BENITO,BENJAMIN,BENNETT,BENNIE,BENNY,BENTON,BERENICE,BERNA,BERNADETTE,BERNADINE,BERNARD,BERNARDA,BERNARDINA,BERNARDINE,BERNARDO,BERNEICE,BERNETTA,BERNICE,BERNIE,BERNIECE,BERNITA,BERRY,BERT,BERTA,BERTHA,BERTIE,BERTRAM,BERYL,BESS,BESSIE,BETH,BETHANIE,BETHANN,BETHANY,BETHEL,BETSEY,BETSY,BETTE,BETTIE,BETTINA,BETTY,BETTYANN,BETTYE,BEULA,BEULAH,BEV,BEVERLEE,BEVERLEY,BEVERLY,BIANCA,BIBI,BILL,BILLI,BILLIE,BILLY,BILLYE,BIRDIE,BIRGIT,BLAINE,BLAIR,BLAKE,BLANCA,BLANCH,BLANCHE,BLONDELL,BLOSSOM,BLYTHE,BO,BOB,BOBBI,BOBBIE,BOBBY,BOBBYE,BOBETTE,BOK,BONG,BONITA,BONNIE,BONNY,BOOKER,BORIS,BOYCE,BOYD,BRAD,BRADFORD,BRADLEY,BRADLY,BRADY,BRAIN,BRANDA,BRANDE,BRANDEE,BRANDEN,BRANDI,BRANDIE,BRANDON,BRANDY,BRANT,BREANA,BREANN,BREANNA,BREANNE,BREE,BRENDA,BRENDAN,BRENDON,BRENNA,BRENT,BRENTON,BRET,BRETT,BRIAN,BRIANA,BRIANNA,BRIANNE,BRICE,BRIDGET,BRIDGETT,BRIDGETTE,BRIGETTE,BRIGID,BRIGIDA,BRIGITTE,BRINDA,BRITANY,BRITNEY,BRITNI,BRITT,BRITTA,BRITTANEY,BRITTANI,BRITTANIE,BRITTANY,BRITTENY,BRITTNEY,BRITTNI,BRITTNY,BROCK,BRODERICK,BRONWYN,BROOK,BROOKE,BROOKS,BRUCE,BRUNA,BRUNILDA,BRUNO,BRYAN,BRYANNA,BRYANT,BRYCE,BRYNN,BRYON,BUCK,BUD,BUDDY,BUENA,BUFFY,BUFORD,BULA,BULAH,BUNNY,BURL,BURMA,BURT,BURTON,BUSTER,BYRON,CAITLIN,CAITLYN,CALANDRA,CALEB,CALISTA,CALLIE,CALVIN,CAMELIA,CAMELLIA,CAMERON,CAMI,CAMIE,CAMILA,CAMILLA,CAMILLE,CAMMIE,CAMMY,CANDACE,CANDANCE,CANDELARIA,CANDI,CANDICE,CANDIDA,CANDIE,CANDIS,CANDRA,CANDY,CANDYCE,CAPRICE,CARA,CAREN,CAREY,CARI,CARIDAD,CARIE,CARIN,CARINA,CARISA,CARISSA,CARITA,CARL,CARLA,CARLEE,CARLEEN,CARLENA,CARLENE,CARLETTA,CARLEY,CARLI,CARLIE,CARLINE,CARLITA,CARLO,CARLOS,CARLOTA,CARLOTTA,CARLTON,CARLY,CARLYN,CARMA,CARMAN,CARMEL,CARMELA,CARMELIA,CARMELINA,CARMELITA,CARMELLA,CARMELO,CARMEN,CARMINA,CARMINE,CARMON,CAROL,CAROLA,CAROLANN,CAROLE,CAROLEE,CAROLIN,CAROLINA,CAROLINE,CAROLL,CAROLYN,CAROLYNE,CAROLYNN,CARON,CAROYLN,CARRI,CARRIE,CARROL,CARROLL,CARRY,CARSON,CARTER,CARY,CARYL,CARYLON,CARYN,CASANDRA,CASEY,CASIE,CASIMIRA,CASSANDRA,CASSAUNDRA,CASSEY,CASSI,CASSIDY,CASSIE,CASSONDRA,CASSY,CATALINA,CATARINA,CATERINA,CATHARINE,CATHERIN,CATHERINA,CATHERINE,CATHERN,CATHERYN,CATHEY,CATHI,CATHIE,CATHLEEN,CATHRINE,CATHRYN,CATHY,CATINA,CATRICE,CATRINA,CAYLA,CECELIA,CECIL,CECILA,CECILE,CECILIA,CECILLE,CECILY,CEDRIC,CEDRICK,CELENA,CELESTA,CELESTE,CELESTINA,CELESTINE,CELIA,CELINA,CELINDA,CELINE,CELSA,CEOLA,CESAR,CHAD,CHADWICK,CHAE,CHAN,CHANA,CHANCE,CHANDA,CHANDRA,CHANEL,CHANELL,CHANELLE,CHANG,CHANTAL,CHANTAY,CHANTE,CHANTEL,CHANTELL,CHANTELLE,CHARA,CHARIS,CHARISE,CHARISSA,CHARISSE,CHARITA,CHARITY,CHARLA,CHARLEEN,CHARLENA,CHARLENE,CHARLES,CHARLESETTA,CHARLETTE,CHARLEY,CHARLIE,CHARLINE,CHARLOTT,CHARLOTTE,CHARLSIE,CHARLYN,CHARMAIN,CHARMAINE,CHAROLETTE,CHAS,CHASE,CHASIDY,CHASITY,CHASSIDY,CHASTITY,CHAU,CHAUNCEY,CHAYA,CHELSEA,CHELSEY,CHELSIE,CHER,CHERE,CHEREE,CHERELLE,CHERI,CHERIE,CHERILYN,CHERISE,CHERISH,CHERLY,CHERLYN,CHERRI,CHERRIE,CHERRY,CHERRYL,CHERY,CHERYL,CHERYLE,CHERYLL,CHESTER,CHET,CHEYENNE,CHI,CHIA,CHIEKO,CHIN,CHINA,CHING,CHIQUITA,CHLOE,CHONG,CHRIS,CHRISSY,CHRISTA,CHRISTAL,CHRISTEEN,CHRISTEL,CHRISTEN,CHRISTENA,CHRISTENE,CHRISTI,CHRISTIA,CHRISTIAN,CHRISTIANA,CHRISTIANE,CHRISTIE,CHRISTIN,CHRISTINA,CHRISTINE,CHRISTINIA,CHRISTOPER,CHRISTOPHER,CHRISTY,CHRYSTAL,CHU,CHUCK,CHUN,CHUNG,CIARA,CICELY,CIERA,CIERRA,CINDA,CINDERELLA,CINDI,CINDIE,CINDY,CINTHIA,CIRA,CLAIR,CLAIRE,CLARA,CLARE,CLARENCE,CLARETHA,CLARETTA,CLARIBEL,CLARICE,CLARINDA,CLARINE,CLARIS,CLARISA,CLARISSA,CLARITA,CLARK,CLASSIE,CLAUD,CLAUDE,CLAUDETTE,CLAUDIA,CLAUDIE,CLAUDINE,CLAUDIO,CLAY,CLAYTON,CLELIA,CLEMENCIA,CLEMENT,CLEMENTE,CLEMENTINA,CLEMENTINE,CLEMMIE,CLEO,CLEOPATRA,CLEORA,CLEOTILDE,CLETA,CLETUS,CLEVELAND,CLIFF,CLIFFORD,CLIFTON,CLINT,CLINTON,CLORA,CLORINDA,CLOTILDE,CLYDE,CODI,CODY,COLBY,COLE,COLEEN,COLEMAN,COLENE,COLETTA,COLETTE,COLIN,COLLEEN,COLLEN,COLLENE,COLLETTE,COLLIN,COLTON,COLUMBUS,CONCEPCION,CONCEPTION,CONCETTA,CONCHA,CONCHITA,CONNIE,CONRAD,CONSTANCE,CONSUELA,CONSUELO,CONTESSA,CORA,CORAL,CORALEE,CORALIE,CORAZON,CORDELIA,CORDELL,CORDIA,CORDIE,COREEN,CORENE,CORETTA,COREY,CORI,CORIE,CORINA,CORINE,CORINNA,CORINNE,CORLISS,CORNELIA,CORNELIUS,CORNELL,CORRIE,CORRIN,CORRINA,CORRINE,CORRINNE,CORTEZ,CORTNEY,CORY,COURTNEY,COY,CRAIG,CREOLA,CRIS,CRISELDA,CRISSY,CRISTA,CRISTAL,CRISTEN,CRISTI,CRISTIE,CRISTIN,CRISTINA,CRISTINE,CRISTOBAL,CRISTOPHER,CRISTY,CRUZ,CRYSTA,CRYSTAL,CRYSTLE,CUC,CURT,CURTIS,CYNDI,CYNDY,CYNTHIA,CYRIL,CYRSTAL,CYRUS,CYTHIA,DACIA,DAGMAR,DAGNY,DAHLIA,DAINA,DAINE,DAISEY,DAISY,DAKOTA,DALE,DALENE,DALIA,DALILA,DALLAS,DALTON,DAMARIS,DAMIAN,DAMIEN,DAMION,DAMON,DAN,DANA,DANAE,DANE,DANELLE,DANETTE,DANI,DANIA,DANIAL,DANICA,DANIEL,DANIELA,DANIELE,DANIELL,DANIELLA,DANIELLE,DANIKA,DANILLE,DANILO,DANITA,DANN,DANNA,DANNETTE,DANNIE,DANNIELLE,DANNY,DANTE,DANUTA,DANYEL,DANYELL,DANYELLE,DAPHINE,DAPHNE,DARA,DARBY,DARCEL,DARCEY,DARCI,DARCIE,DARCY,DARELL,DAREN,DARIA,DARIN,DARIO,DARIUS,DARLA,DARLEEN,DARLENA,DARLENE,DARLINE,DARNELL,DARON,DARREL,DARRELL,DARREN,DARRICK,DARRIN,DARRON,DARRYL,DARWIN,DARYL,DAVE,DAVID,DAVIDA,DAVINA,DAVIS,DAWN,DAWNA,DAWNE,DAYLE,DAYNA,DAYSI,DEADRA,DEAN,DEANA,DEANDRA,DEANDRE,DEANDREA,DEANE,DEANGELO,DEANN,DEANNA,DEANNE,DEB,DEBBI,DEBBIE,DEBBRA,DEBBY,DEBERA,DEBI,DEBORA,DEBORAH,DEBRA,DEBRAH,DEBROAH,DEDE,DEDRA,DEE,DEEANN,DEEANNA,DEEDEE,DEEDRA,DEENA,DEETTA,DEIDRA,DEIDRE,DEIRDRE,DEJA,DEL,DELAINE,DELANA,DELBERT,DELCIE,DELENA,DELFINA,DELIA,DELICIA,DELILA,DELILAH,DELINDA,DELISA,DELL,DELLA,DELMA,DELMAR,DELMER,DELMY,DELOIS,DELOISE,DELORA,DELORAS,DELORES,DELORIS,DELORSE,DELPHA,DELPHIA,DELPHINE,DELSIE,DELTA,DEMARCUS,DEMETRA,DEMETRIA,DEMETRICE,DEMETRIUS,DENA,DENAE,DENEEN,DENESE,DENICE,DENIS,DENISE,DENISHA,DENISSE,DENITA,DENNA,DENNIS,DENNISE,DENNY,DENVER,DENYSE,DEON,DEONNA,DEREK,DERICK,DERRICK,DESHAWN,DESIRAE,DESIRE,DESIREE,DESMOND,DESPINA,DESSIE,DESTINY,DETRA,DEVIN,DEVON,DEVONA,DEVORA,DEVORAH,DEWAYNE,DEWEY,DEWITT,DEXTER,DIA,DIAMOND,DIAN,DIANA,DIANE,DIANN,DIANNA,DIANNE,DICK,DIEDRA,DIEDRE,DIEGO,DIERDRE,DIGNA,DILLON,DIMPLE,DINA,DINAH,DINO,DINORAH,DION,DIONE,DIONNA,DIONNE,DIRK,DIVINA,DIXIE,DODIE,DOLLIE,DOLLY,DOLORES,DOLORIS,DOMENIC,DOMENICA,DOMINGA,DOMINGO,DOMINIC,DOMINICA,DOMINICK,DOMINIQUE,DOMINQUE,DOMITILA,DOMONIQUE,DON,DONA,DONALD,DONELLA,DONETTA,DONETTE,DONG,DONITA,DONN,DONNA,DONNELL,DONNETTA,DONNETTE,DONNIE,DONNY,DONOVAN,DONTE,DONYA,DORA,DORATHY,DORCAS,DOREATHA,DOREEN,DORENE,DORETHA,DORETHEA,DORETTA,DORI,DORIA,DORIAN,DORIE,DORINDA,DORINE,DORIS,DORLA,DOROTHA,DOROTHEA,DOROTHY,DORRIS,DORSEY,DORTHA,DORTHEA,DORTHEY,DORTHY,DOT,DOTTIE,DOTTY,DOUG,DOUGLAS,DOUGLASS,DOVIE,DOYLE,DREAMA,DREMA,DREW,DRUCILLA,DRUSILLA,DUANE,DUDLEY,DULCE,DULCIE,DUNCAN,DUNG,DUSTI,DUSTIN,DUSTY,DWAIN,DWANA,DWAYNE,DWIGHT,DYAN,DYLAN,EARL,EARLE,EARLEAN,EARLEEN,EARLENE,EARLIE,EARLINE,EARNEST,EARNESTINE,EARTHA,EASTER,EBONI,EBONIE,EBONY,ECHO,ED,EDA,EDDA,EDDIE,EDDY,EDELMIRA,EDEN,EDGAR,EDGARDO,EDIE,EDISON,EDITH,EDMOND,EDMUND,EDMUNDO,EDNA,EDRA,EDRIS,EDUARDO,EDWARD,EDWARDO,EDWIN,EDWINA,EDYTH,EDYTHE,EFFIE,EFRAIN,EFREN,EHTEL,EILEEN,EILENE,ELA,ELADIA,ELAINA,ELAINE,ELANA,ELANE,ELANOR,ELAYNE,ELBA,ELBERT,ELDA,ELDEN,ELDON,ELDORA,ELDRIDGE,ELEANOR,ELEANORA,ELEANORE,ELEASE,ELENA,ELENE,ELENI,ELENOR,ELENORA,ELENORE,ELEONOR,ELEONORA,ELEONORE,ELFREDA,ELFRIEDA,ELFRIEDE,ELI,ELIA,ELIANA,ELIAS,ELICIA,ELIDA,ELIDIA,ELIJAH,ELIN,ELINA,ELINOR,ELINORE,ELISA,ELISABETH,ELISE,ELISEO,ELISHA,ELISSA,ELIZ,ELIZA,ELIZABET,ELIZABETH,ELIZBETH,ELIZEBETH,ELKE,ELLA,ELLAMAE,ELLAN,ELLEN,ELLENA,ELLI,ELLIE,ELLIOT,ELLIOTT,ELLIS,ELLSWORTH,ELLY,ELLYN,ELMA,ELMER,ELMIRA,ELMO,ELNA,ELNORA,ELODIA,ELOIS,ELOISA,ELOISE,ELOUISE,ELOY,ELROY,ELSA,ELSE,ELSIE,ELSY,ELTON,ELVA,ELVERA,ELVIA,ELVIE,ELVIN,ELVINA,ELVIRA,ELVIS,ELWANDA,ELWOOD,ELYSE,ELZA,EMA,EMANUEL,EMELDA,EMELIA,EMELINA,EMELINE,EMELY,EMERALD,EMERITA,EMERSON,EMERY,EMIKO,EMIL,EMILE,EMILEE,EMILIA,EMILIE,EMILIO,EMILY,EMMA,EMMALINE,EMMANUEL,EMMETT,EMMIE,EMMITT,EMMY,EMOGENE,EMORY,ENA,ENDA,ENEDINA,ENEIDA,ENID,ENOCH,ENOLA,ENRIQUE,ENRIQUETA,EPIFANIA,ERA,ERASMO,ERIC,ERICA,ERICH,ERICK,ERICKA,ERIK,ERIKA,ERIN,ERINN,ERLENE,ERLINDA,ERLINE,ERMA,ERMELINDA,ERMINIA,ERNA,ERNEST,ERNESTINA,ERNESTINE,ERNESTO,ERNIE,ERROL,ERVIN,ERWIN,ERYN,ESMERALDA,ESPERANZA,ESSIE,ESTA,ESTEBAN,ESTEFANA,ESTELA,ESTELL,ESTELLA,ESTELLE,ESTER,ESTHER,ESTRELLA,ETHA,ETHAN,ETHEL,ETHELENE,ETHELYN,ETHYL,ETSUKO,ETTA,ETTIE,EUFEMIA,EUGENA,EUGENE,EUGENIA,EUGENIE,EUGENIO,EULA,EULAH,EULALIA,EUN,EUNA,EUNICE,EURA,EUSEBIA,EUSEBIO,EUSTOLIA,EVA,EVALYN,EVAN,EVANGELINA,EVANGELINE,EVE,EVELIA,EVELIN,EVELINA,EVELINE,EVELYN,EVELYNE,EVELYNN,EVERETT,EVERETTE,EVETTE,EVIA,EVIE,EVITA,EVON,EVONNE,EWA,EXIE,EZEKIEL,EZEQUIEL,EZRA,FABIAN,FABIOLA,FAE,FAIRY,FAITH,FALLON,FANNIE,FANNY,FARAH,FARRAH,FATIMA,FATIMAH,FAUSTINA,FAUSTINO,FAUSTO,FAVIOLA,FAWN,FAY,FAYE,FE,FEDERICO,FELECIA,FELICA,FELICE,FELICIA,FELICIDAD,FELICITA,FELICITAS,FELIPA,FELIPE,FELISA,FELISHA,FELIX,FELTON,FERDINAND,FERMIN,FERMINA,FERN,FERNANDA,FERNANDE,FERNANDO,FERNE,FIDEL,FIDELA,FIDELIA,FILIBERTO,FILOMENA,FIONA,FLAVIA,FLETA,FLETCHER,FLO,FLOR,FLORA,FLORANCE,FLORENCE,FLORENCIA,FLORENCIO,FLORENE,FLORENTINA,FLORENTINO,FLORETTA,FLORIA,FLORIDA,FLORINDA,FLORINE,FLORRIE,FLOSSIE,FLOY,FLOYD,FONDA,FOREST,FORREST,FOSTER,FRAN,FRANCE,FRANCENE,FRANCES,FRANCESCA,FRANCESCO,FRANCHESCA,FRANCIE,FRANCINA,FRANCINE,FRANCIS,FRANCISCA,FRANCISCO,FRANCOISE,FRANK,FRANKIE,FRANKLIN,FRANKLYN,FRANSISCA,FRED,FREDA,FREDDA,FREDDIE,FREDDY,FREDERIC,FREDERICA,FREDERICK,FREDERICKA,FREDIA,FREDRIC,FREDRICK,FREDRICKA,FREEDA,FREEMAN,FREIDA,FRIDA,FRIEDA,FRITZ,FUMIKO,GABRIEL,GABRIELA,GABRIELE,GABRIELLA,GABRIELLE,GAIL,GALA,GALE,GALEN,GALINA,GARFIELD,GARLAND,GARNET,GARNETT,GARRET,GARRETT,GARRY,GARTH,GARY,GASTON,GAVIN,GAY,GAYE,GAYLA,GAYLE,GAYLENE,GAYLORD,GAYNELL,GAYNELLE,GEARLDINE,GEMA,GEMMA,GENA,GENARO,GENE,GENESIS,GENEVA,GENEVIE,GENEVIEVE,GENEVIVE,GENIA,GENIE,GENNA,GENNIE,GENNY,GENOVEVA,GEOFFREY,GEORGANN,GEORGE,GEORGEANN,GEORGEANNA,GEORGENE,GEORGETTA,GEORGETTE,GEORGIA,GEORGIANA,GEORGIANN,GEORGIANNA,GEORGIANNE,GEORGIE,GEORGINA,GEORGINE,GERALD,GERALDINE,GERALDO,GERALYN,GERARD,GERARDO,GERDA,GERI,GERMAINE,GERMAN,GERRI,GERRY,GERTHA,GERTIE,GERTRUD,GERTRUDE,GERTRUDIS,GERTUDE,GHISLAINE,GIA,GIANNA,GIDGET,GIGI,GIL,GILBERT,GILBERTE,GILBERTO,GILDA,GILLIAN,GILMA,GINA,GINETTE,GINGER,GINNY,GINO,GIOVANNA,GIOVANNI,GISELA,GISELE,GISELLE,GITA,GIUSEPPE,GIUSEPPINA,GLADIS,GLADY,GLADYS,GLAYDS,GLEN,GLENDA,GLENDORA,GLENN,GLENNA,GLENNIE,GLENNIS,GLINDA,GLORIA,GLORY,GLYNDA,GLYNIS,GOLDA,GOLDEN,GOLDIE,GONZALO,GORDON,GRACE,GRACIA,GRACIE,GRACIELA,GRADY,GRAHAM,GRAIG,GRANT,GRANVILLE,GRAYCE,GRAZYNA,GREG,GREGG,GREGORIA,GREGORIO,GREGORY,GRETA,GRETCHEN,GRETTA,GRICELDA,GRISEL,GRISELDA,GROVER,GUADALUPE,GUDRUN,GUILLERMINA,GUILLERMO,GUS,GUSSIE,GUSTAVO,GUY,GWEN,GWENDA,GWENDOLYN,GWENN,GWYN,GWYNETH,HA,HAE,HAI,HAILEY,HAL,HALEY,HALINA,HALLEY,HALLIE,HAN,HANA,HANG,HANH,HANK,HANNA,HANNAH,HANNELORE,HANS,HARLAN,HARLAND,HARLEY,HARMONY,HAROLD,HARRIET,HARRIETT,HARRIETTE,HARRIS,HARRISON,HARRY,HARVEY,HASSAN,HASSIE,HATTIE,HAYDEE,HAYDEN,HAYLEY,HAYWOOD,HAZEL,HEATH,HEATHER,HECTOR,HEDWIG,HEDY,HEE,HEIDE,HEIDI,HEIDY,HEIKE,HELAINE,HELEN,HELENA,HELENE,HELGA,HELLEN,HENRIETTA,HENRIETTE,HENRY,HERB,HERBERT,HERIBERTO,HERLINDA,HERMA,HERMAN,HERMELINDA,HERMILA,HERMINA,HERMINE,HERMINIA,HERSCHEL,HERSHEL,HERTA,HERTHA,HESTER,HETTIE,HIEDI,HIEN,HILARIA,HILARIO,HILARY,HILDA,HILDE,HILDEGARD,HILDEGARDE,HILDRED,HILLARY,HILMA,HILTON,HIPOLITO,HIRAM,HIROKO,HISAKO,HOA,HOBERT,HOLLEY,HOLLI,HOLLIE,HOLLIS,HOLLY,HOMER,HONEY,HONG,HOPE,HORACE,HORACIO,HORTENCIA,HORTENSE,HORTENSIA,HOSEA,HOUSTON,HOWARD,HOYT,HSIU,HUBERT,HUE,HUEY,HUGH,HUGO,HUI,HULDA,HUMBERTO,HUNG,HUNTER,HUONG,HWA,HYACINTH,HYE,HYMAN,HYO,HYON,HYUN,IAN,IDA,IDALIA,IDELL,IDELLA,IESHA,IGNACIA,IGNACIO,IKE,ILA,ILANA,ILDA,ILEANA,ILEEN,ILENE,ILIANA,ILLA,ILONA,ILSE,ILUMINADA,IMA,IMELDA,IMOGENE,IN,INA,INDIA,INDIRA,INELL,INES,INEZ,INGA,INGE,INGEBORG,INGER,INGRID,INOCENCIA,IOLA,IONA,IONE,IRA,IRAIDA,IRENA,IRENE,IRINA,IRIS,IRISH,IRMA,IRMGARD,IRVIN,IRVING,IRWIN,ISA,ISAAC,ISABEL,ISABELL,ISABELLA,ISABELLE,ISADORA,ISAIAH,ISAIAS,ISAURA,ISELA,ISIAH,ISIDRA,ISIDRO,ISIS,ISMAEL,ISOBEL,ISRAEL,ISREAL,ISSAC,IVA,IVAN,IVANA,IVELISSE,IVETTE,IVEY,IVONNE,IVORY,IVY,IZETTA,IZOLA,JA,JACALYN,JACELYN,JACINDA,JACINTA,JACINTO,JACK,JACKELINE,JACKELYN,JACKI,JACKIE,JACKLYN,JACKQUELINE,JACKSON,JACLYN,JACOB,JACQUALINE,JACQUE,JACQUELIN,JACQUELINE,JACQUELYN,JACQUELYNE,JACQUELYNN,JACQUES,JACQUETTA,JACQUI,JACQUIE,JACQUILINE,JACQULINE,JACQULYN,JADA,JADE,JADWIGA,JAE,JAIME,JAIMEE,JAIMIE,JAKE,JALEESA,JALISA,JAMA,JAMAAL,JAMAL,JAMAR,JAME,JAMEE,JAMEL,JAMES,JAMEY,JAMI,JAMIE,JAMIKA,JAMILA,JAMISON,JAMMIE,JAN,JANA,JANAE,JANAY,JANE,JANEAN,JANEE,JANEEN,JANEL,JANELL,JANELLA,JANELLE,JANENE,JANESSA,JANET,JANETH,JANETT,JANETTA,JANETTE,JANEY,JANI,JANICE,JANIE,JANIECE,JANINA,JANINE,JANIS,JANISE,JANITA,JANN,JANNA,JANNET,JANNETTE,JANNIE,JANUARY,JANYCE,JAQUELINE,JAQUELYN,JARED,JAROD,JARRED,JARRETT,JARROD,JARVIS,JASMIN,JASMINE,JASON,JASPER,JAUNITA,JAVIER,JAY,JAYE,JAYME,JAYMIE,JAYNA,JAYNE,JAYSON,JAZMIN,JAZMINE,JC,JEAN,JEANA,JEANE,JEANELLE,JEANENE,JEANETT,JEANETTA,JEANETTE,JEANICE,JEANIE,JEANINE,JEANMARIE,JEANNA,JEANNE,JEANNETTA,JEANNETTE,JEANNIE,JEANNINE,JED,JEFF,JEFFEREY,JEFFERSON,JEFFERY,JEFFIE,JEFFREY,JEFFRY,JEN,JENA,JENAE,JENE,JENEE,JENELL,JENELLE,JENETTE,JENEVA,JENI,JENICE,JENIFER,JENIFFER,JENINE,JENISE,JENNA,JENNEFER,JENNELL,JENNETTE,JENNI,JENNIE,JENNIFER,JENNIFFER,JENNINE,JENNY,JERALD,JERALDINE,JERAMY,JERE,JEREMIAH,JEREMY,JERI,JERICA,JERILYN,JERLENE,JERMAINE,JEROLD,JEROME,JEROMY,JERRELL,JERRI,JERRICA,JERRIE,JERROD,JERROLD,JERRY,JESENIA,JESICA,JESS,JESSE,JESSENIA,JESSI,JESSIA,JESSICA,JESSIE,JESSIKA,JESTINE,JESUS,JESUSA,JESUSITA,JETTA,JETTIE,JEWEL,JEWELL,JI,JILL,JILLIAN,JIM,JIMMIE,JIMMY,JIN,JINA,JINNY,JO,JOAN,JOANA,JOANE,JOANIE,JOANN,JOANNA,JOANNE,JOANNIE,JOAQUIN,JOAQUINA,JOCELYN,JODEE,JODI,JODIE,JODY,JOE,JOEANN,JOEL,JOELLA,JOELLE,JOELLEN,JOESPH,JOETTA,JOETTE,JOEY,JOHANA,JOHANNA,JOHANNE,JOHN,JOHNA,JOHNATHAN,JOHNATHON,JOHNETTA,JOHNETTE,JOHNIE,JOHNNA,JOHNNIE,JOHNNY,JOHNSIE,JOHNSON,JOI,JOIE,JOLANDA,JOLEEN,JOLENE,JOLIE,JOLINE,JOLYN,JOLYNN,JON,JONA,JONAH,JONAS,JONATHAN,JONATHON,JONE,JONELL,JONELLE,JONG,JONI,JONIE,JONNA,JONNIE,JORDAN,JORDON,JORGE,JOSE,JOSEF,JOSEFA,JOSEFINA,JOSEFINE,JOSELYN,JOSEPH,JOSEPHINA,JOSEPHINE,JOSETTE,JOSH,JOSHUA,JOSIAH,JOSIE,JOSLYN,JOSPEH,JOSPHINE,JOSUE,JOVAN,JOVITA,JOY,JOYA,JOYCE,JOYCELYN,JOYE,JUAN,JUANA,JUANITA,JUDE,JUDI,JUDIE,JUDITH,JUDSON,JUDY,JULE,JULEE,JULENE,JULES,JULI,JULIA,JULIAN,JULIANA,JULIANE,JULIANN,JULIANNA,JULIANNE,JULIE,JULIEANN,JULIENNE,JULIET,JULIETA,JULIETTA,JULIETTE,JULIO,JULISSA,JULIUS,JUNE,JUNG,JUNIE,JUNIOR,JUNITA,JUNKO,JUSTA,JUSTIN,JUSTINA,JUSTINE,JUTTA,KA,KACEY,KACI,KACIE,KACY,KAI,KAILA,KAITLIN,KAITLYN,KALA,KALEIGH,KALEY,KALI,KALLIE,KALYN,KAM,KAMALA,KAMI,KAMILAH,KANDACE,KANDI,KANDICE,KANDIS,KANDRA,KANDY,KANESHA,KANISHA,KARA,KARAN,KAREEM,KAREEN,KAREN,KARENA,KAREY,KARI,KARIE,KARIMA,KARIN,KARINA,KARINE,KARISA,KARISSA,KARL,KARLA,KARLEEN,KARLENE,KARLY,KARLYN,KARMA,KARMEN,KAROL,KAROLE,KAROLINE,KAROLYN,KARON,KARREN,KARRI,KARRIE,KARRY,KARY,KARYL,KARYN,KASANDRA,KASEY,KASHA,KASI,KASIE,KASSANDRA,KASSIE,KATE,KATELIN,KATELYN,KATELYNN,KATERINE,KATHALEEN,KATHARINA,KATHARINE,KATHARYN,KATHE,KATHELEEN,KATHERIN,KATHERINA,KATHERINE,KATHERN,KATHERYN,KATHEY,KATHI,KATHIE,KATHLEEN,KATHLENE,KATHLINE,KATHLYN,KATHRIN,KATHRINE,KATHRYN,KATHRYNE,KATHY,KATHYRN,KATI,KATIA,KATIE,KATINA,KATLYN,KATRICE,KATRINA,KATTIE,KATY,KAY,KAYCE,KAYCEE,KAYE,KAYLA,KAYLEE,KAYLEEN,KAYLEIGH,KAYLENE,KAZUKO,KECIA,KEELEY,KEELY,KEENA,KEENAN,KEESHA,KEIKO,KEILA,KEIRA,KEISHA,KEITH,KEITHA,KELI,KELLE,KELLEE,KELLEY,KELLI,KELLIE,KELLY,KELLYE,KELSEY,KELSI,KELSIE,KELVIN,KEMBERLY,KEN,KENA,KENDA,KENDAL,KENDALL,KENDRA,KENDRICK,KENETH,KENIA,KENISHA,KENNA,KENNETH,KENNITH,KENNY,KENT,KENTON,KENYA,KENYATTA,KENYETTA,KERA,KEREN,KERI,KERMIT,KERRI,KERRIE,KERRY,KERSTIN,KESHA,KESHIA,KETURAH,KEVA,KEVEN,KEVIN,KHADIJAH,KHALILAH,KIA,KIANA,KIARA,KIERA,KIERSTEN,KIESHA,KIETH,KILEY,KIM,KIMBER,KIMBERELY,KIMBERLEE,KIMBERLEY,KIMBERLI,KIMBERLIE,KIMBERLY,KIMBERY,KIMBRA,KIMI,KIMIKO,KINA,KINDRA,KING,KIP,KIRA,KIRBY,KIRK,KIRSTEN,KIRSTIE,KIRSTIN,KISHA,KIT,KITTIE,KITTY,KIYOKO,KIZZIE,KIZZY,KLARA,KOREY,KORI,KORTNEY,KORY,KOURTNEY,KRAIG,KRIS,KRISHNA,KRISSY,KRISTA,KRISTAL,KRISTAN,KRISTEEN,KRISTEL,KRISTEN,KRISTI,KRISTIAN,KRISTIE,KRISTIN,KRISTINA,KRISTINE,KRISTLE,KRISTOFER,KRISTOPHER,KRISTY,KRISTYN,KRYSTA,KRYSTAL,KRYSTEN,KRYSTIN,KRYSTINA,KRYSTLE,KRYSTYNA,KUM,KURT,KURTIS,KYLA,KYLE,KYLEE,KYLIE,KYM,KYMBERLY,KYOKO,KYONG,KYRA,KYUNG,LACEY,LACHELLE,LACI,LACIE,LACRESHA,LACY,LADAWN,LADONNA,LADY,LAEL,LAHOMA,LAI,LAILA,LAINE,LAJUANA,LAKEESHA,LAKEISHA,LAKENDRA,LAKENYA,LAKESHA,LAKESHIA,LAKIA,LAKIESHA,LAKISHA,LAKITA,LALA,LAMAR,LAMONICA,LAMONT,LAN,LANA,LANCE,LANDON,LANE,LANELL,LANELLE,LANETTE,LANG,LANI,LANIE,LANITA,LANNIE,LANNY,LANORA,LAQUANDA,LAQUITA,LARA,LARAE,LARAINE,LAREE,LARHONDA,LARISA,LARISSA,LARITA,LARONDA,LARRAINE,LARRY,LARUE,LASANDRA,LASHANDA,LASHANDRA,LASHAUN,LASHAUNDA,LASHAWN,LASHAWNA,LASHAWNDA,LASHAY,LASHELL,LASHON,LASHONDA,LASHUNDA,LASONYA,LATANYA,LATARSHA,LATASHA,LATASHIA,LATESHA,LATIA,LATICIA,LATINA,LATISHA,LATONIA,LATONYA,LATORIA,LATOSHA,LATOYA,LATOYIA,LATRICE,LATRICIA,LATRINA,LATRISHA,LAUNA,LAURA,LAURALEE,LAURAN,LAURE,LAUREEN,LAUREL,LAUREN,LAURENA,LAURENCE,LAURENE,LAURETTA,LAURETTE,LAURI,LAURICE,LAURIE,LAURINDA,LAURINE,LAURYN,LAVADA,LAVELLE,LAVENIA,LAVERA,LAVERN,LAVERNA,LAVERNE,LAVETA,LAVETTE,LAVINA,LAVINIA,LAVON,LAVONA,LAVONDA,LAVONE,LAVONIA,LAVONNA,LAVONNE,LAWANA,LAWANDA,LAWANNA,LAWERENCE,LAWRENCE,LAYLA,LAYNE,LAZARO,LE,LEA,LEAH,LEAN,LEANA,LEANDRA,LEANDRO,LEANN,LEANNA,LEANNE,LEANORA,LEATHA,LEATRICE,LECIA,LEDA,LEE,LEEANN,LEEANNA,LEEANNE,LEENA,LEESA,LEIA,LEIDA,LEIF,LEIGH,LEIGHA,LEIGHANN,LEILA,LEILANI,LEISA,LEISHA,LEKISHA,LELA,LELAH,LELAND,LELIA,LEMUEL,LEN,LENA,LENARD,LENITA,LENNA,LENNIE,LENNY,LENORA,LENORE,LEO,LEOLA,LEOMA,LEON,LEONA,LEONARD,LEONARDA,LEONARDO,LEONE,LEONEL,LEONIA,LEONIDA,LEONIE,LEONILA,LEONOR,LEONORA,LEONORE,LEONTINE,LEOPOLDO,LEORA,LEOTA,LERA,LEROY,LES,LESA,LESHA,LESIA,LESLEE,LESLEY,LESLI,LESLIE,LESSIE,LESTER,LETA,LETHA,LETICIA,LETISHA,LETITIA,LETTIE,LETTY,LEVI,LEWIS,LEXIE,LEZLIE,LI,LIA,LIANA,LIANE,LIANNE,LIBBIE,LIBBY,LIBERTY,LIBRADA,LIDA,LIDIA,LIEN,LIESELOTTE,LIGIA,LILA,LILI,LILIA,LILIAN,LILIANA,LILLA,LILLI,LILLIA,LILLIAM,LILLIAN,LILLIANA,LILLIE,LILLY,LILY,LIN,LINA,LINCOLN,LINDA,LINDSAY,LINDSEY,LINDSY,LINDY,LINETTE,LING,LINH,LINN,LINNEA,LINNIE,LINO,LINSEY,LINWOOD,LIONEL,LISA,LISABETH,LISANDRA,LISBETH,LISE,LISETTE,LISHA,LISSA,LISSETTE,LITA,LIVIA,LIZ,LIZA,LIZABETH,LIZBETH,LIZETH,LIZETTE,LIZZETTE,LIZZIE,LLOYD,LOAN,LOGAN,LOIDA,LOIS,LOISE,LOLA,LOLITA,LOMA,LON,LONA,LONDA,LONG,LONI,LONNA,LONNIE,LONNY,LORA,LORAINE,LORALEE,LORE,LOREAN,LOREE,LOREEN,LORELEI,LOREN,LORENA,LORENE,LORENZA,LORENZO,LORETA,LORETTA,LORETTE,LORI,LORIA,LORIANN,LORIE,LORILEE,LORINA,LORINDA,LORINE,LORIS,LORITA,LORNA,LORRAINE,LORRETTA,LORRI,LORRIANE,LORRIE,LORRINE,LORY,LOTTIE,LOU,LOUANN,LOUANNE,LOUELLA,LOUETTA,LOUIE,LOUIS,LOUISA,LOUISE,LOURA,LOURDES,LOURIE,LOUVENIA,LOVE,LOVELLA,LOVETTA,LOVIE,LOWELL,LOYCE,LOYD,LU,LUANA,LUANN,LUANNA,LUANNE,LUBA,LUCAS,LUCI,LUCIA,LUCIANA,LUCIANO,LUCIE,LUCIEN,LUCIENNE,LUCILA,LUCILE,LUCILLA,LUCILLE,LUCINA,LUCINDA,LUCIO,LUCIUS,LUCRECIA,LUCRETIA,LUCY,LUDIE,LUDIVINA,LUE,LUELLA,LUETTA,LUIGI,LUIS,LUISA,LUISE,LUKE,LULA,LULU,LUNA,LUPE,LUPITA,LURA,LURLENE,LURLINE,LUTHER,LUVENIA,LUZ,LYDA,LYDIA,LYLA,LYLE,LYMAN,LYN,LYNDA,LYNDIA,LYNDON,LYNDSAY,LYNDSEY,LYNELL,LYNELLE,LYNETTA,LYNETTE,LYNN,LYNNA,LYNNE,LYNNETTE,LYNSEY,LYNWOOD,MA,MABEL,MABELLE,MABLE,MAC,MACHELLE,MACIE,MACK,MACKENZIE,MACY,MADALENE,MADALINE,MADALYN,MADDIE,MADELAINE,MADELEINE,MADELENE,MADELINE,MADELYN,MADGE,MADIE,MADISON,MADLYN,MADONNA,MAE,MAEGAN,MAFALDA,MAGALI,MAGALY,MAGAN,MAGARET,MAGDA,MAGDALEN,MAGDALENA,MAGDALENE,MAGEN,MAGGIE,MAGNOLIA,MAHALIA,MAI,MAIA,MAIDA,MAILE,MAIRA,MAIRE,MAISHA,MAISIE,MAJOR,MAJORIE,MAKEDA,MALCOLM,MALCOM,MALENA,MALIA,MALIK,MALIKA,MALINDA,MALISA,MALISSA,MALKA,MALLIE,MALLORY,MALORIE,MALVINA,MAMIE,MAMMIE,MAN,MANA,MANDA,MANDI,MANDIE,MANDY,MANIE,MANUAL,MANUEL,MANUELA,MANY,MAO,MAPLE,MARA,MARAGARET,MARAGRET,MARANDA,MARC,MARCEL,MARCELA,MARCELENE,MARCELINA,MARCELINE,MARCELINO,MARCELL,MARCELLA,MARCELLE,MARCELLUS,MARCELO,MARCENE,MARCHELLE,MARCI,MARCIA,MARCIE,MARCO,MARCOS,MARCUS,MARCY,MARDELL,MAREN,MARG,MARGARET,MARGARETA,MARGARETE,MARGARETT,MARGARETTA,MARGARETTE,MARGARITA,MARGARITE,MARGARITO,MARGART,MARGE,MARGENE,MARGERET,MARGERT,MARGERY,MARGET,MARGHERITA,MARGIE,MARGIT,MARGO,MARGORIE,MARGOT,MARGRET,MARGRETT,MARGUERITA,MARGUERITE,MARGURITE,MARGY,MARHTA,MARI,MARIA,MARIAH,MARIAM,MARIAN,MARIANA,MARIANELA,MARIANN,MARIANNA,MARIANNE,MARIANO,MARIBEL,MARIBETH,MARICA,MARICELA,MARICRUZ,MARIE,MARIEL,MARIELA,MARIELLA,MARIELLE,MARIETTA,MARIETTE,MARIKO,MARILEE,MARILOU,MARILU,MARILYN,MARILYNN,MARIN,MARINA,MARINDA,MARINE,MARIO,MARION,MARIS,MARISA,MARISELA,MARISHA,MARISOL,MARISSA,MARITA,MARITZA,MARIVEL,MARJORIE,MARJORY,MARK,MARKETTA,MARKITA,MARKUS,MARLA,MARLANA,MARLEEN,MARLEN,MARLENA,MARLENE,MARLIN,MARLINE,MARLO,MARLON,MARLYN,MARLYS,MARNA,MARNI,MARNIE,MARQUERITE,MARQUETTA,MARQUIS,MARQUITA,MARQUITTA,MARRY,MARSHA,MARSHALL,MARTA,MARTH,MARTHA,MARTI,MARTIN,MARTINA,MARTINE,MARTY,MARVA,MARVEL,MARVELLA,MARVIN,MARVIS,MARX,MARY,MARYA,MARYALICE,MARYAM,MARYANN,MARYANNA,MARYANNE,MARYBELLE,MARYBETH,MARYELLEN,MARYETTA,MARYJANE,MARYJO,MARYLAND,MARYLEE,MARYLIN,MARYLN,MARYLOU,MARYLOUISE,MARYLYN,MARYLYNN,MARYROSE,MASAKO,MASON,MATHA,MATHEW,MATHILDA,MATHILDE,MATILDA,MATILDE,MATT,MATTHEW,MATTIE,MAUD,MAUDE,MAUDIE,MAURA,MAUREEN,MAURICE,MAURICIO,MAURINE,MAURITA,MAURO,MAVIS,MAX,MAXIE,MAXIMA,MAXIMINA,MAXIMO,MAXINE,MAXWELL,MAY,MAYA,MAYBELL,MAYBELLE,MAYE,MAYME,MAYNARD,MAYOLA,MAYRA,MAZIE,MCKENZIE,MCKINLEY,MEAGAN,MEAGHAN,MECHELLE,MEDA,MEE,MEG,MEGAN,MEGGAN,MEGHAN,MEGHANN,MEI,MEL,MELAINE,MELANI,MELANIA,MELANIE,MELANY,MELBA,MELDA,MELIA,MELIDA,MELINA,MELINDA,MELISA,MELISSA,MELISSIA,MELITA,MELLIE,MELLISA,MELLISSA,MELODEE,MELODI,MELODIE,MELODY,MELONIE,MELONY,MELVA,MELVIN,MELVINA,MELYNDA,MENDY,MERCEDES,MERCEDEZ,MERCY,MEREDITH,MERI,MERIDETH,MERIDITH,MERILYN,MERISSA,MERLE,MERLENE,MERLIN,MERLYN,MERNA,MERRI,MERRIE,MERRILEE,MERRILL,MERRY,MERTIE,MERVIN,MERYL,META,MI,MIA,MICA,MICAELA,MICAH,MICHA,MICHAEL,MICHAELA,MICHAELE,MICHAL,MICHALE,MICHEAL,MICHEL,MICHELE,MICHELINA,MICHELINE,MICHELL,MICHELLE,MICHIKO,MICKEY,MICKI,MICKIE,MIESHA,MIGDALIA,MIGNON,MIGUEL,MIGUELINA,MIKA,MIKAELA,MIKE,MIKEL,MIKI,MIKKI,MILA,MILAGRO,MILAGROS,MILAN,MILDA,MILDRED,MILES,MILFORD,MILISSA,MILLARD,MILLICENT,MILLIE,MILLY,MILO,MILTON,MIMI,MIN,MINA,MINDA,MINDI,MINDY,MINERVA,MING,MINH,MINNA,MINNIE,MINTA,MIQUEL,MIRA,MIRANDA,MIREILLE,MIRELLA,MIREYA,MIRIAM,MIRIAN,MIRNA,MIRTA,MIRTHA,MISHA,MISS,MISSY,MISTI,MISTIE,MISTY,MITCH,MITCHEL,MITCHELL,MITSUE,MITSUKO,MITTIE,MITZI,MITZIE,MIYOKO,MODESTA,MODESTO,MOHAMED,MOHAMMAD,MOHAMMED,MOIRA,MOISES,MOLLIE,MOLLY,MONA,MONET,MONICA,MONIKA,MONIQUE,MONNIE,MONROE,MONSERRATE,MONTE,MONTY,MOON,MORA,MORGAN,MORIAH,MORRIS,MORTON,MOSE,MOSES,MOSHE,MOZELL,MOZELLA,MOZELLE,MUI,MUOI,MURIEL,MURRAY,MY,MYESHA,MYLES,MYONG,MYRA,MYRIAM,MYRL,MYRLE,MYRNA,MYRON,MYRTA,MYRTICE,MYRTIE,MYRTIS,MYRTLE,MYUNG,NA,NADA,NADENE,NADIA,NADINE,NAIDA,NAKESHA,NAKIA,NAKISHA,NAKITA,NAM,NAN,NANA,NANCEE,NANCEY,NANCI,NANCIE,NANCY,NANETTE,NANNETTE,NANNIE,NAOMA,NAOMI,NAPOLEON,NARCISA,NATACHA,NATALIA,NATALIE,NATALYA,NATASHA,NATASHIA,NATHALIE,NATHAN,NATHANAEL,NATHANIAL,NATHANIEL,NATISHA,NATIVIDAD,NATOSHA,NEAL,NECOLE,NED,NEDA,NEDRA,NEELY,NEIDA,NEIL,NELDA,NELIA,NELIDA,NELL,NELLA,NELLE,NELLIE,NELLY,NELSON,NENA,NENITA,NEOMA,NEOMI,NEREIDA,NERISSA,NERY,NESTOR,NETA,NETTIE,NEVA,NEVADA,NEVILLE,NEWTON,NGA,NGAN,NGOC,NGUYET,NIA,NICHELLE,NICHOL,NICHOLAS,NICHOLE,NICHOLLE,NICK,NICKI,NICKIE,NICKOLAS,NICKOLE,NICKY,NICOL,NICOLA,NICOLAS,NICOLASA,NICOLE,NICOLETTE,NICOLLE,NIDA,NIDIA,NIESHA,NIEVES,NIGEL,NIKI,NIKIA,NIKITA,NIKKI,NIKOLE,NILA,NILDA,NILSA,NINA,NINFA,NISHA,NITA,NOAH,NOBLE,NOBUKO,NOE,NOEL,NOELIA,NOELLA,NOELLE,NOEMI,NOHEMI,NOLA,NOLAN,NOMA,NONA,NORA,NORAH,NORBERT,NORBERTO,NOREEN,NORENE,NORIKO,NORINE,NORMA,NORMAN,NORMAND,NORRIS,NOVA,NOVELLA,NU,NUBIA,NUMBERS,NYDIA,NYLA,OBDULIA,OCIE,OCTAVIA,OCTAVIO,ODA,ODELIA,ODELL,ODESSA,ODETTE,ODILIA,ODIS,OFELIA,OK,OLA,OLEN,OLENE,OLETA,OLEVIA,OLGA,OLIMPIA,OLIN,OLINDA,OLIVA,OLIVE,OLIVER,OLIVIA,OLLIE,OLYMPIA,OMA,OMAR,OMEGA,OMER,ONA,ONEIDA,ONIE,ONITA,OPAL,OPHELIA,ORA,ORALEE,ORALIA,OREN,ORETHA,ORLANDO,ORPHA,ORVAL,ORVILLE,OSCAR,OSSIE,OSVALDO,OSWALDO,OTELIA,OTHA,OTILIA,OTIS,OTTO,OUIDA,OWEN,OZELL,OZELLA,OZIE,PA,PABLO,PAGE,PAIGE,PALMA,PALMER,PALMIRA,PAM,PAMALA,PAMELA,PAMELIA,PAMELLA,PAMILA,PAMULA,PANDORA,PANSY,PAOLA,PARIS,PARKER,PARTHENIA,PARTICIA,PASQUALE,PASTY,PAT,PATIENCE,PATRIA,PATRICA,PATRICE,PATRICIA,PATRICK,PATRINA,PATSY,PATTI,PATTIE,PATTY,PAUL,PAULA,PAULENE,PAULETTA,PAULETTE,PAULINA,PAULINE,PAULITA,PAZ,PEARL,PEARLE,PEARLENE,PEARLIE,PEARLINE,PEARLY,PEDRO,PEG,PEGGIE,PEGGY,PEI,PENELOPE,PENNEY,PENNI,PENNIE,PENNY,PERCY,PERLA,PERRY,PETE,PETER,PETRA,PETRINA,PETRONILA,PHEBE,PHIL,PHILIP,PHILLIP,PHILLIS,PHILOMENA,PHOEBE,PHUNG,PHUONG,PHYLICIA,PHYLIS,PHYLISS,PHYLLIS,PIA,PIEDAD,PIERRE,PILAR,PING,PINKIE,PIPER,POK,POLLY,PORFIRIO,PORSCHE,PORSHA,PORTER,PORTIA,PRECIOUS,PRESTON,PRICILLA,PRINCE,PRINCESS,PRISCILA,PRISCILLA,PROVIDENCIA,PRUDENCE,PURA,QIANA,QUEEN,QUEENIE,QUENTIN,QUIANA,QUINCY,QUINN,QUINTIN,QUINTON,QUYEN,RACHAEL,RACHAL,RACHEAL,RACHEL,RACHELE,RACHELL,RACHELLE,RACQUEL,RAE,RAEANN,RAELENE,RAFAEL,RAFAELA,RAGUEL,RAINA,RAISA,RALEIGH,RALPH,RAMIRO,RAMON,RAMONA,RAMONITA,RANA,RANAE,RANDA,RANDAL,RANDALL,RANDEE,RANDELL,RANDI,RANDOLPH,RANDY,RANEE,RAPHAEL,RAQUEL,RASHAD,RASHEEDA,RASHIDA,RAUL,RAVEN,RAY,RAYE,RAYFORD,RAYLENE,RAYMON,RAYMOND,RAYMONDE,RAYMUNDO,RAYNA,REA,REAGAN,REANNA,REATHA,REBA,REBBECA,REBBECCA,REBECA,REBECCA,REBECKA,REBEKAH,REDA,REED,REENA,REFUGIA,REFUGIO,REGAN,REGENA,REGENIA,REGGIE,REGINA,REGINALD,REGINE,REGINIA,REID,REIKO,REINA,REINALDO,REITA,REMA,REMEDIOS,REMONA,RENA,RENAE,RENALDO,RENATA,RENATE,RENATO,RENAY,RENDA,RENE,RENEA,RENEE,RENETTA,RENITA,RENNA,RESSIE,RETA,RETHA,RETTA,REUBEN,REVA,REX,REY,REYES,REYNA,REYNALDA,REYNALDO,RHEA,RHEBA,RHETT,RHIANNON,RHODA,RHONA,RHONDA,RIA,RICARDA,RICARDO,RICH,RICHARD,RICHELLE,RICHIE,RICK,RICKEY,RICKI,RICKIE,RICKY,RICO,RIGOBERTO,RIKKI,RILEY,RIMA,RINA,RISA,RITA,RIVA,RIVKA,ROB,ROBBI,ROBBIE,ROBBIN,ROBBY,ROBBYN,ROBENA,ROBERT,ROBERTA,ROBERTO,ROBIN,ROBT,ROBYN,ROCCO,ROCHEL,ROCHELL,ROCHELLE,ROCIO,ROCKY,ROD,RODERICK,RODGER,RODNEY,RODOLFO,RODRICK,RODRIGO,ROGELIO,ROGER,ROLAND,ROLANDA,ROLANDE,ROLANDO,ROLF,ROLLAND,ROMA,ROMAINE,ROMAN,ROMANA,ROMELIA,ROMEO,ROMONA,RON,RONA,RONALD,RONDA,RONI,RONNA,RONNI,RONNIE,RONNY,ROOSEVELT,RORY,ROSA,ROSALBA,ROSALEE,ROSALIA,ROSALIE,ROSALINA,ROSALIND,ROSALINDA,ROSALINE,ROSALVA,ROSALYN,ROSAMARIA,ROSAMOND,ROSANA,ROSANN,ROSANNA,ROSANNE,ROSARIA,ROSARIO,ROSAURA,ROSCOE,ROSE,ROSEANN,ROSEANNA,ROSEANNE,ROSELEE,ROSELIA,ROSELINE,ROSELLA,ROSELLE,ROSELYN,ROSEMARIE,ROSEMARY,ROSENA,ROSENDA,ROSENDO,ROSETTA,ROSETTE,ROSIA,ROSIE,ROSINA,ROSIO,ROSITA,ROSLYN,ROSS,ROSSANA,ROSSIE,ROSY,ROWENA,ROXANA,ROXANE,ROXANN,ROXANNA,ROXANNE,ROXIE,ROXY,ROY,ROYAL,ROYCE,ROZANNE,ROZELLA,RUBEN,RUBI,RUBIE,RUBIN,RUBY,RUBYE,RUDOLF,RUDOLPH,RUDY,RUEBEN,RUFINA,RUFUS,RUPERT,RUSS,RUSSEL,RUSSELL,RUSTY,RUTH,RUTHA,RUTHANN,RUTHANNE,RUTHE,RUTHIE,RYAN,RYANN,SABINA,SABINE,SABRA,SABRINA,SACHA,SACHIKO,SADE,SADIE,SADYE,SAGE,SAL,SALENA,SALINA,SALLEY,SALLIE,SALLY,SALOME,SALVADOR,SALVATORE,SAM,SAMANTHA,SAMARA,SAMATHA,SAMELLA,SAMIRA,SAMMIE,SAMMY,SAMUAL,SAMUEL,SANA,SANDA,SANDEE,SANDI,SANDIE,SANDRA,SANDY,SANFORD,SANG,SANJUANA,SANJUANITA,SANORA,SANTA,SANTANA,SANTIAGO,SANTINA,SANTO,SANTOS,SARA,SARAH,SARAI,SARAN,SARI,SARINA,SARITA,SASHA,SATURNINA,SAU,SAUL,SAUNDRA,SAVANNA,SAVANNAH,SCARLET,SCARLETT,SCOT,SCOTT,SCOTTIE,SCOTTY,SEAN,SEASON,SEBASTIAN,SEBRINA,SEE,SEEMA,SELENA,SELENE,SELINA,SELMA,SENA,SENAIDA,SEPTEMBER,SERAFINA,SERENA,SERGIO,SERINA,SERITA,SETH,SETSUKO,SEYMOUR,SHA,SHAD,SHAE,SHAINA,SHAKIA,SHAKIRA,SHAKITA,SHALA,SHALANDA,SHALON,SHALONDA,SHAMEKA,SHAMIKA,SHAN,SHANA,SHANAE,SHANDA,SHANDI,SHANDRA,SHANE,SHANEKA,SHANEL,SHANELL,SHANELLE,SHANI,SHANICE,SHANIKA,SHANIQUA,SHANITA,SHANNA,SHANNAN,SHANNON,SHANON,SHANTA,SHANTAE,SHANTAY,SHANTE,SHANTEL,SHANTELL,SHANTELLE,SHANTI,SHAQUANA,SHAQUITA,SHARA,SHARAN,SHARDA,SHAREE,SHARELL,SHAREN,SHARI,SHARICE,SHARIE,SHARIKA,SHARILYN,SHARITA,SHARLA,SHARLEEN,SHARLENE,SHARMAINE,SHAROLYN,SHARON,SHARONDA,SHARRI,SHARRON,SHARYL,SHARYN,SHASTA,SHAUN,SHAUNA,SHAUNDA,SHAUNNA,SHAUNTA,SHAUNTE,SHAVON,SHAVONDA,SHAVONNE,SHAWANA,SHAWANDA,SHAWANNA,SHAWN,SHAWNA,SHAWNDA,SHAWNEE,SHAWNNA,SHAWNTA,SHAY,SHAYLA,SHAYNA,SHAYNE,SHEA,SHEBA,SHEENA,SHEILA,SHEILAH,SHELA,SHELBA,SHELBY,SHELDON,SHELIA,SHELLA,SHELLEY,SHELLI,SHELLIE,SHELLY,SHELTON,SHEMEKA,SHEMIKA,SHENA,SHENIKA,SHENITA,SHENNA,SHERA,SHEREE,SHERELL,SHERI,SHERICE,SHERIDAN,SHERIE,SHERIKA,SHERILL,SHERILYN,SHERISE,SHERITA,SHERLENE,SHERLEY,SHERLY,SHERLYN,SHERMAN,SHERON,SHERRELL,SHERRI,SHERRIE,SHERRIL,SHERRILL,SHERRON,SHERRY,SHERRYL,SHERWOOD,SHERY,SHERYL,SHERYLL,SHIELA,SHILA,SHILOH,SHIN,SHIRA,SHIRELY,SHIRL,SHIRLEE,SHIRLEEN,SHIRLENE,SHIRLEY,SHIRLY,SHIZUE,SHIZUKO,SHON,SHONA,SHONDA,SHONDRA,SHONNA,SHONTA,SHOSHANA,SHU,SHYLA,SIBYL,SID,SIDNEY,SIERRA,SIGNE,SIGRID,SILAS,SILVA,SILVANA,SILVIA,SIMA,SIMON,SIMONA,SIMONE,SIMONNE,SINA,SINDY,SIOBHAN,SIRENA,SIU,SIXTA,SKYE,SLYVIA,SO,SOCORRO,SOFIA,SOILA,SOL,SOLANGE,SOLEDAD,SOLOMON,SOMER,SOMMER,SON,SONA,SONDRA,SONG,SONIA,SONJA,SONNY,SONYA,SOO,SOOK,SOON,SOPHIA,SOPHIE,SORAYA,SPARKLE,SPENCER,SPRING,STACEE,STACEY,STACI,STACIA,STACIE,STACY,STAN,STANFORD,STANLEY,STANTON,STAR,STARLA,STARR,STASIA,STEFAN,STEFANI,STEFANIA,STEFANIE,STEFANY,STEFFANIE,STELLA,STEPANIE,STEPHAINE,STEPHAN,STEPHANE,STEPHANI,STEPHANIA,STEPHANIE,STEPHANY,STEPHEN,STEPHENIE,STEPHINE,STEPHNIE,STERLING,STEVE,STEVEN,STEVIE,STEWART,STORMY,STUART,SU,SUANNE,SUDIE,SUE,SUEANN,SUELLEN,SUK,SULEMA,SUMIKO,SUMMER,SUN,SUNDAY,SUNG,SUNNI,SUNNY,SUNSHINE,SUSAN,SUSANA,SUSANN,SUSANNA,SUSANNAH,SUSANNE,SUSIE,SUSY,SUZAN,SUZANN,SUZANNA,SUZANNE,SUZETTE,SUZI,SUZIE,SUZY,SVETLANA,SYBIL,SYBLE,SYDNEY,SYLVESTER,SYLVIA,SYLVIE,SYNTHIA,SYREETA,TA,TABATHA,TABETHA,TABITHA,TAD,TAI,TAINA,TAISHA,TAJUANA,TAKAKO,TAKISHA,TALIA,TALISHA,TALITHA,TAM,TAMA,TAMALA,TAMAR,TAMARA,TAMATHA,TAMBRA,TAMEIKA,TAMEKA,TAMEKIA,TAMELA,TAMERA,TAMESHA,TAMI,TAMICA,TAMIE,TAMIKA,TAMIKO,TAMISHA,TAMMARA,TAMMERA,TAMMI,TAMMIE,TAMMY,TAMRA,TANA,TANDRA,TANDY,TANEKA,TANESHA,TANGELA,TANIA,TANIKA,TANISHA,TANJA,TANNA,TANNER,TANYA,TARA,TARAH,TAREN,TARI,TARRA,TARSHA,TARYN,TASHA,TASHIA,TASHINA,TASIA,TATIANA,TATUM,TATYANA,TAUNYA,TAWANA,TAWANDA,TAWANNA,TAWNA,TAWNY,TAWNYA,TAYLOR,TAYNA,TED,TEDDY,TEENA,TEGAN,TEISHA,TELMA,TEMEKA,TEMIKA,TEMPIE,TEMPLE,TENA,TENESHA,TENISHA,TENNIE,TENNILLE,TEODORA,TEODORO,TEOFILA,TEQUILA,TERA,TEREASA,TERENCE,TERESA,TERESE,TERESIA,TERESITA,TERESSA,TERI,TERICA,TERINA,TERISA,TERRA,TERRANCE,TERRELL,TERRENCE,TERRESA,TERRI,TERRIE,TERRILYN,TERRY,TESHA,TESS,TESSA,TESSIE,THAD,THADDEUS,THALIA,THANH,THAO,THEA,THEDA,THELMA,THEO,THEODORA,THEODORE,THEOLA,THERESA,THERESE,THERESIA,THERESSA,THERON,THERSA,THI,THOMAS,THOMASENA,THOMASINA,THOMASINE,THORA,THRESA,THU,THURMAN,THUY,TIA,TIANA,TIANNA,TIARA,TIEN,TIERA,TIERRA,TIESHA,TIFANY,TIFFANEY,TIFFANI,TIFFANIE,TIFFANY,TIFFINY,TIJUANA,TILDA,TILLIE,TIM,TIMIKA,TIMMY,TIMOTHY,TINA,TINISHA,TINY,TISA,TISH,TISHA,TITUS,TOBI,TOBIAS,TOBIE,TOBY,TOCCARA,TOD,TODD,TOI,TOM,TOMAS,TOMASA,TOMEKA,TOMI,TOMIKA,TOMIKO,TOMMIE,TOMMY,TOMMYE,TOMOKO,TONA,TONDA,TONETTE,TONEY,TONI,TONIA,TONIE,TONISHA,TONITA,TONJA,TONY,TONYA,TORA,TORI,TORIE,TORRI,TORRIE,TORY,TOSHA,TOSHIA,TOSHIKO,TOVA,TOWANDA,TOYA,TRACEE,TRACEY,TRACI,TRACIE,TRACY,TRAN,TRANG,TRAVIS,TREASA,TREENA,TRENA,TRENT,TRENTON,TRESA,TRESSA,TRESSIE,TREVA,TREVOR,TREY,TRICIA,TRINA,TRINH,TRINIDAD,TRINITY,TRISH,TRISHA,TRISTA,TRISTAN,TROY,TRUDI,TRUDIE,TRUDY,TRULA,TRUMAN,TU,TUAN,TULA,TUYET,TWANA,TWANDA,TWANNA,TWILA,TWYLA,TY,TYESHA,TYISHA,TYLER,TYNISHA,TYRA,TYREE,TYRELL,TYRON,TYRONE,TYSON,ULA,ULRIKE,ULYSSES,UN,UNA,URSULA,USHA,UTE,VADA,VAL,VALARIE,VALDA,VALENCIA,VALENE,VALENTIN,VALENTINA,VALENTINE,VALERI,VALERIA,VALERIE,VALERY,VALLIE,VALORIE,VALRIE,VAN,VANCE,VANDA,VANESA,VANESSA,VANETTA,VANIA,VANITA,VANNA,VANNESA,VANNESSA,VASHTI,VASILIKI,VAUGHN,VEDA,VELDA,VELIA,VELLA,VELMA,VELVA,VELVET,VENA,VENESSA,VENETTA,VENICE,VENITA,VENNIE,VENUS,VEOLA,VERA,VERDA,VERDELL,VERDIE,VERENA,VERGIE,VERLA,VERLENE,VERLIE,VERLINE,VERN,VERNA,VERNELL,VERNETTA,VERNIA,VERNICE,VERNIE,VERNITA,VERNON,VERONA,VERONICA,VERONIKA,VERONIQUE,VERSIE,VERTIE,VESTA,VETA,VI,VICENTA,VICENTE,VICKEY,VICKI,VICKIE,VICKY,VICTOR,VICTORIA,VICTORINA,VIDA,VIKI,VIKKI,VILMA,VINA,VINCE,VINCENT,VINCENZA,VINCENZO,VINITA,VINNIE,VIOLA,VIOLET,VIOLETA,VIOLETTE,VIRGEN,VIRGIE,VIRGIL,VIRGILIO,VIRGINA,VIRGINIA,VITA,VITO,VIVA,VIVAN,VIVIAN,VIVIANA,VIVIEN,VIVIENNE,VON,VONCILE,VONDA,VONNIE,WADE,WAI,WALDO,WALKER,WALLACE,WALLY,WALTER,WALTON,WALTRAUD,WAN,WANDA,WANETA,WANETTA,WANITA,WARD,WARNER,WARREN,WAVA,WAYLON,WAYNE,WEI,WELDON,WEN,WENDELL,WENDI,WENDIE,WENDOLYN,WENDY,WENONA,WERNER,WES,WESLEY,WESTON,WHITLEY,WHITNEY,WILBER,WILBERT,WILBUR,WILBURN,WILDA,WILEY,WILFORD,WILFRED,WILFREDO,WILHELMINA,WILHEMINA,WILL,WILLA,WILLARD,WILLENA,WILLENE,WILLETTA,WILLETTE,WILLIA,WILLIAM,WILLIAMS,WILLIAN,WILLIE,WILLIEMAE,WILLIS,WILLODEAN,WILLOW,WILLY,WILMA,WILMER,WILSON,WILTON,WINDY,WINFORD,WINFRED,WINIFRED,WINNIE,WINNIFRED,WINONA,WINSTON,WINTER,WM,WONDA,WOODROW,WYATT,WYNELL,WYNONA,XAVIER,XENIA,XIAO,XIOMARA,XOCHITL,XUAN,YADIRA,YAEKO,YAEL,YAHAIRA,YAJAIRA,YAN,YANG,YANIRA,YASMIN,YASMINE,YASUKO,YEE,YELENA,YEN,YER,YESENIA,YESSENIA,YETTA,YEVETTE,YI,YING,YOKO,YOLANDA,YOLANDE,YOLANDO,YOLONDA,YON,YONG,YOSHIE,YOSHIKO,YOULANDA,YOUNG,YU,YUETTE,YUK,YUKI,YUKIKO,YUKO,YULANDA,YUN,YUNG,YUONNE,YURI,YURIKO,YVETTE,YVONE,YVONNE,ZACHARIAH,ZACHARY,ZACHERY,ZACK,ZACKARY,ZADA,ZAIDA,ZANA,ZANDRA,ZANE,ZELDA,ZELLA,ZELMA,ZENA,ZENAIDA,ZENIA,ZENOBIA,ZETTA,ZINA,ZITA,ZOE,ZOFIA,ZOILA,ZOLA,ZONA,ZONIA,ZORA,ZORAIDA,ZULA,ZULEMA,ZULMA."};
    int index = 0, multipler = 1, total = 0, tempValue = 0;
    while (true){
        if (nameList[index] == 44){
            total += (tempValue*multipler);
            tempValue = 0;
            multipler+=1;
        }
        else if (nameList[index] == 46){
            total += tempValue*multipler;
            return total;
        }
        else
            tempValue+=nameList[index]-64;
        index+=1;
    }
    
}

int problem25(){
    int fib1[1000] = {0}, fib2[1000] = {0}, tempFib[1000] = {0}, carry = 0, counter = 2, tempSum;
    fib1[0] = 1, fib2[0] = 1;
    while (true){
        counter += 1;
        for (int i=0; i<1000;i+=1){
            tempFib[i]=fib2[i];
            tempSum = (fib1[i]+fib2[i]+carry);
            carry = tempSum/10;
            fib2[i] = tempSum%10;
            fib1[i] = tempFib[i];
        }
        if (fib2[999] != 0)
            return counter;
    }
}

int problem26(){
    int largestRepeat = 0;
    int largestD = 0;
    for (int i=1;i<1000;i+=1){
        if (recurring_decimal_length(i) > largestRepeat){
            largestRepeat = recurring_decimal_length(i);
            largestD = i;
        }
    }
    return largestD;
}

int problem27(){
    int mostPrimes=0, product=0, primes = 0, b;
    for (int a = (-999); a < 1000; a+=2){
        b = -997;
        while (b < 1000){
            primes = quadratic_primes(a, b);
            if (primes>mostPrimes){
                mostPrimes=primes, product = a*b;
            }
            b=nextPrimeNumber(b);
        }
    }
    return product;
}

int problem28(){
    int sum = 1;
    int square;
    for (int i = 3; i <= 1001; i += 2){
        square = pow(i,2);
        for (int j = 0; j < 4; j+=1)
            sum+=square-((i-1)*j);
    }
    return sum;
}

int problem30(){
    int sum = 0, powerSum;
    for (int i=2;i<200000;i+=1){
        powerSum=0;
        int * digits = digitsToArray(i);
        for (int t=0;t<amountOfDigits(i);t+=1){
            powerSum += pow(digits[t],5);
        }
        if (powerSum == i)
            sum+=i;
    }
    return sum;
}







int main(){
    /*
    printf("problem1: %d\n",problem1());
    printf("problem2: %d\n",problem2());
    printf("problem3: %d\n",problem3());
    printf("problem4: %d\n",problem4());
    printf("problem5: %d\n",problem5());
    printf("problem6: %ld\n",problem6());
    printf("problem7: %d\n",problem7());
    printf("problem8: %d\n",problem8());
    printf("problem9: %d\n",problem9());
    printf("problem10: %ld\n",problem10());
    printf("problem11: %d\n",problem11());
    printf("problem12: %d\n",problem12());
    printf("problem13: %ld\n",problem13());
    printf("problem14: %d\n",problem14());
    printf("problem15: %ld\n",problem15());
    printf("problem16: %d\n",problem16());
    printf("problem17: %d\n",problem17());
    printf("problem18: %d\n",problem18());
    printf("problem20: %d\n",problem20());
    printf("problem21: %d\n",problem21());
    printf("problem22: %d\n",problem22());
    printf("problem25: %d\n",problem25());
    printf("problem26: %d\n",problem26());
    printf("problem27: %d\n",problem27());
    printf("problem28: %d\n",problem28());
    printf("problem30: %d\n",problem30());
    */
    
    
   


    
}