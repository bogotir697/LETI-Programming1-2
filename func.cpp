#include "func.h"

using namespace std;
using namespace chrono;

time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> timerStart;

int randInt(int min, int max) {
    int i = rand() % (max + 1 - min);
    i += min;
    return i;
}

void randomArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = randInt(-99, 99);
    }
}

void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void shakerSort(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
        for (int j = n - 1 - i; j > i; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
}

void combSort(int* arr, int n) {
    float k = 1.247, s = n - 1;
    while (s >= 1) {
        for (int i = 0; i + s < n; i++) {
            if (arr[i] > arr[int(i + s)]) {
                swap(arr[i], arr[int(i + s)]);
            }
        }
        s /= k;
    }
}

void insertSort(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int key = arr[i];
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}

void quickSort(int* arr, int  end, int begin) {
    int mid;
    int f = begin;
    int l = end;
    mid = arr[(f + l) / 2];
    while (f < l) {
        while (arr[f] < mid) f++;
        while (arr[l] > mid) l--;
        if (f <= l) {
            swap(arr[f], arr[l]);
            f++;
            l--;
        }
    }
    if (begin < l) { quickSort(arr, l, begin); }
    if (f < end) { quickSort(arr, end, f); }
}

void startTimer() {
    timerStart = steady_clock::now();
}

float stopTimer() {
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> end = steady_clock::now();
    nanoseconds delta = duration_cast<nanoseconds>(end - timerStart);
    return (float)delta.count() / 1000;
}

float runTime(void sort(int* arr, int n), int* arr, int n) {
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;

    start = steady_clock::now();
    sort(arr, n);
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    return (float)result.count() / 1000;
}
float runTime(void sort(int* arr, int _end, int _begin), int* arr, int n) {
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;
    start = steady_clock::now();
    sort(arr, n - 1, 0);
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    return (float)result.count() / 1000;
}

int maxValue(int* arr, int n) {
    int maxItem = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxItem) {
            maxItem = arr[i];
        }
    }
    return maxItem;
}

int minValue(int* arr, int n) {
    int minItem = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] < minItem) {
            minItem = arr[i];
        }
    }
    return minItem;
}

int avValue(int* arr, int n) {
    int averageValue = round(double((maxValue(arr, n) + minValue(arr, n)) / 2));
    cout << " Среднее значение максимального и минимального: " << averageValue << endl;
    int amount = 0;
    cout << " Индексы элементов, равных среднему: ";
    for (int i = 0; i < n; i++) {
        if (arr[i] == averageValue) {
            cout << i << " ";
            amount++;
        }
    }
    cout << endl << " Количество элементов, равных среднему: " << amount << endl;
    return averageValue;
}

int amountLessThanA(int* arr, int n, int a) {
    int amount = 0;
    int i = 0;
    while (arr[i] < a && i < n) {
        amount++;
        i++;
    }
    return amount;
}

int amountGreaterThanB(int* arr, int n, int b) {
    int amount = 0;
    int i = n - 1;
    while (arr[i] > b && i >= 0) {
        amount++;
        i--;
    }
    return amount;
}

bool binarySearch(int* arr, int a, int begin, int end) {
    int midIndex = (end - begin + 1) / 2 + begin;
    if (end < begin) {
        return false;
    }
    if (a == arr[midIndex]) {
        return true;
    }
    else if (a > arr[midIndex]) {
        begin = midIndex + 1;
    }
    else {
        end = midIndex - 1;
    }
    return binarySearch(arr, a, begin, end);
}

bool stupidSearch(int* arr, int n, int a) {
    bool contains = false;
    for (int i = 0; i < n; i++) {
        if (a == arr[i]) {
            contains = true;
            break;
        }
    }
    return contains;
}