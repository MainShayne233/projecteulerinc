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
    if (num == 2)
        return true;
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

int problem1(){
    int sum = 0;
    for (int i = 1; i <1000; i++){
        if ((i%3==0) || (i%5==0)){
            sum += i;
        }
    }
    printf("%d", sum);
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
    printf("%d \n", sum);
    return sum;
}


int problem3(){
    int largestPrime = 0;
    for (int i = 3; i < sqrt(600851475143); i+=1){
        if ((600851475143 % i == 0) && (isPrime(i)))
            largestPrime = i;
    }
    printf("%d \n", largestPrime);
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
        printf("%d",largestProduct);
        return largestProduct;
}

int problem12(){
    int triangleNumber = 0;
    for (int i = 1; true; i+=1){
        triangleNumber += i;
        if (amountOfDivisors(triangleNumber) > 500){
            printf("%d", triangleNumber);
            return triangleNumber;
        }
    }
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
    printf("%d\n",largestNumber);
    return largestNumber;
}



int main(){
    problem14();
}