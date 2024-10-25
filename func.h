#pragma once

#include <iostream>
#include <time.h>
#include <conio.h>
#include <chrono>


int randInt(int min, int max);
void randomArray(int* arr, int n);
void printArray(int* arr, int n);
void bubbleSort(int* arr, int n);
void shakerSort(int* arr, int n);
void combSort(int* arr, int n);
void insertSort(int* arr, int n);
void quickSort(int* arr, int  end, int begin);
void startTimer();
float stopTimer();

float runTime(void sort(int* arr, int n), int* arr, int n);
float runTime(void sort(int* arr, int _end, int _begin), int* arr, int n);

int maxValue(int* arr, int n);
int minValue(int* arr, int n);
int avValue(int* arr, int n);
int amountLessThanA(int* arr, int n, int a);
int amountGreaterThanB(int* arr, int n, int b);
bool binarySearch(int* arr, int a, int begin, int end);
bool stupidSearch(int* arr, int n, int a);