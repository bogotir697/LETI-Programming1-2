#include <iostream>
#include <cmath>
#include <conio.h>
#include <windows.h>
#include "func.h"

using namespace std;

bool active = 1;
unsigned char state[2] = { 0, 0 };
unsigned char prevState[2] = { -1, -1 };
unsigned char length[12] = { 11, 3, 2, 5, 5, 3, 4, 2, 2, 4, 2, 4 };
unsigned char step[12] = { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 };
char sort = -1;

const int n = 100;
int mainArr[n];

void gotoxy(int x, int y) {
	COORD coordinate;
	coordinate.X = x;
	coordinate.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

void mainMenu() {
	printf(" [ Создать массив ]\n");
	printf(" [ Вывести массив ]\n");
	printf(" [ Выбранная сортировка ]: ");
	string s = "";
	switch (sort) {
	case 0:
		s = "bubble sort";
		break;
	case 1:
		s = "shaker sort";
		break;
	case 2:
		s = "comb sort";
		break;
	case 3:
		s = "insert sort";
		break;
	case 4:
		s = "quick sort";
		break;
	}
	cout << s << "\n";
	printf(" [ Сортировка массива ]\n");
	printf(" [ Поиск максимального и минимального элементов ]\n");
	printf(" [ Среднее значение максимального и минимального элементов ]\n");
	printf(" [ Определение количества элементов, меньших введённого числа ]\n");
	printf(" [ Определение количества элементов, больших введённого числа ]\n");
	printf(" [ Поиск числа в массиве ]\n");
	printf(" [ Поменять местами элементы массива ]\n");
	printf(" [ ИДЗ 5 ]\n");
}

void f1CreateArray() {
	printf(" N = %d:\n ", n);
	printArray(mainArr, n);
	cout << endl;
}
void f2ShowArray() {
	cout << " Массив: ";
	printArray(mainArr, n);
	cout << endl;
}
void f3ChooseSort() {
	printf(" [ bubble sort ]  \n");
	printf(" [ shaker sort ]  \n");
	printf(" [ comb sort ]    \n");
	printf(" [ insert sort ]  \n");
	printf(" [ quick sort ]   \n");
	if (sort > -1) {
		gotoxy(18, sort % 5 + 1);
		putchar('*');
	}
	gotoxy(0, 6);
}
void f4SortArray() {
	if (sort == -1) {
		cout << " Не выбрана сортировка!\n\n\n\n\n";
		return;
	}
	cout << " Массив: ";
	printArray(mainArr, n);
	float runtime = 0;
	switch (sort) {
	case 0:
		runtime = runTime(bubbleSort, mainArr, n);
		break;
	case 1:
		runtime = runTime(shakerSort, mainArr, n);
		break;
	case 2:
		runtime = runTime(combSort, mainArr, n);
		break;
	case 3:
		runtime = runTime(insertSort, mainArr, n);
		break;
	case 4:
		runtime = runTime(quickSort, mainArr, n);
		break;
	}
	cout << endl;
	cout << " Отсортированный массив: ";
	printArray(mainArr, n);
	cout << endl;
	cout << " Время сортировки: " << runtime << " мкс" << endl;
}
void f5FindMaxMin() {
	float runtime = 0; int mx; int mn;
	startTimer();
	mx = maxValue(mainArr, n);
	runtime = stopTimer();
	startTimer();
	mn = minValue(mainArr, n);
	runtime += stopTimer();
	cout << " Максимальный элемент: " << mx << endl;
	cout << " Минимальный элемент: " << mn << endl;
	cout << " Время поиска: " << runtime << " мкс" << endl;
}
void f6AverageMaxMin() {
	float runtime = 0;
	startTimer();
	avValue(mainArr, n);
	runtime = stopTimer();
	cout << " Время поиска: " << runtime << " мкс" << endl;
}
void f7AmountLessThanA() {
	int a = 0;
	cout << " Введите число: ";
	cin >> a;
	int amount = amountLessThanA(mainArr, n, a);
	cout << " Количество элементов, меньших числа: " << amount << endl;
}
void f8AmountGreaterThanB() {
	int b = 0;
	cout << " Введите число: ";
	cin >> b;
	int amount = amountGreaterThanB(mainArr, n, b);
	cout << " Количество элементов, больших числа: " << amount << endl;
}
void f9FindAInArray() {
	int a = 0;
	cout << " Введите число: ";
	cin >> a;
	bool contains = binarySearch(mainArr, a, 0, n - 1);
	if (contains) {
		cout << " В массиве есть введённое число\n";
	}
	else {
		cout << " В массиве нет введённого числа\n";
	}
	startTimer();
	binarySearch(mainArr, a, 0, n - 1);
	float runtime = stopTimer();
	cout << " Время поиска алгоритмом бинарного поиска: " << runtime << " мкс" << endl;
	startTimer();
	stupidSearch(mainArr, n, a);
	runtime = stopTimer();
	cout << " Время поиска переборным алгоритмом: " << runtime << " мкс" << endl;
}
void f10SwapElements() {
	cout << " Введите индексы элементов, которые хотите поменять местами: ";
	unsigned int index0(0), index1(0);
	cin >> index0 >> index1;
	if (index0 >= n || index1 >= n) {
		cout << " Индексы введены неверно!\n";
		return;
	}
	startTimer();
	int temp = mainArr[index1];
	mainArr[index1] = mainArr[index0];
	mainArr[index0] = temp;
	float runtime = stopTimer();
	cout << " Время перемещения элементов: " << runtime << " мкс" << endl;

}
void f11IHT5() {
	cout << " Введите значение: ";
	int k = 0;
	cin >> k;
	for (int i = 1; i < n; i += 2) {
		mainArr[i] -= k;
		mainArr[i] *= randInt(1, 9);
	}
	int amountOdd(0), amountEven(0);
	for (int i = 0; i < n; i += 2) {
		amountOdd += mainArr[i] % 2;
		if (i + 1 < n) {
			amountEven += (mainArr[i + 1] % 2 + 1) % 2;
		}
	}
	cout << " Количество чётных элементов с чётными значениями: " << amountEven << endl;
	cout << " Количество нечётных элементов с нечётными значениями: " << amountOdd << endl;
	int amountMultiple[9] = { 0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < n; i++) {
		amountMultiple[0] += 1;
		for (int j = 2; j <= 9; j++) {
			amountMultiple[j - 1] += ((mainArr[i] % j + (j - 1)) % j) / (j - 1);
		}
	}
	cout << " Количество элементов, кратных: ";
	for (int i = 0; i < 9; i++) {
		cout << (i + 1) << " - " << amountMultiple[i] << ", ";
	}
	cout << endl;
}

void print() {
	int len = 0;
	cout << "\b";
	cout << " ";
	if (prevState[0] != state[0]) {
		system("cls");
		gotoxy(0, 1);
		switch (state[0]) {
		case 0:
			mainMenu();
			break;
		case 1:
			f1CreateArray();
			break;
		case 2:
			f2ShowArray();
			break;
		case 3:
			f3ChooseSort();
			break;
		case 4:
			f4SortArray();
			break;
		case 5:
			f5FindMaxMin();
			break;
		case 6:
			f6AverageMaxMin();
			break;
		case 7:
			f7AmountLessThanA();
			break;
		case 8:
			f8AmountGreaterThanB();
			break;
		case 9:
			f9FindAInArray();
			break;
		case 10:
			f10SwapElements();
			break;
		case 11:
			f11IHT5();
			break;
		}
		printf(" exit");
	}
	prevState[0] = state[0];
	gotoxy(0, 0);
	printf(" Практическая работа No2");
	len = length[state[0]] + 1;
	state[1] = state[1] % len;
	gotoxy(0, state[1] + 1);
	printf("%c", 62);
}

void activateFunc() {
	if (state[1] == length[state[0]]) {
		switch (state[0]) {
		case 0:
			active = 0;
			break;
		default:
			state[0] = 0;
		}
		return;
	}
	switch (state[0]) {
	case 0:
		switch (state[1]) {
		case 0:
			randomArray(mainArr, n);
		default:
			state[0] = state[1] + 1;
		}
		break;
	case 3:
		switch (state[1]) {
		default:
			sort = state[1];
			state[0] = 0;
			break;
		}
		break;
	}
}

int menu()
{
	print();
	char c = _getch();
	while (active) {
		c = _getch();
		switch (c) {
		case 72:
			state[1] += length[state[0]] + 1 - step[state[0]];
			state[1] = state[1] % (length[state[0]] + 1);
			break;
		case 80:
			state[1] += step[state[0]];
			state[1] = state[1] % (length[state[0]] + 1);
			break;
		case 13:
			activateFunc();
			state[1] = length[state[0]] + step[state[0]];
			state[1] = state[1] % (length[state[0]] + 1);
			break;
		}
		print();
	}

	gotoxy(0, 20);
	system("pause");
	return 0;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    menu();
    return 0;
}

