#include <iostream>
#include "io.h"
#include "fcntl.h"
#include "windows.h"
#include <iomanip>

using namespace std;

//2.1
void Exponentiation(int degree_basis, int exponent) {
	int degree = degree_basis;
	for (int i = 1; i < exponent; i++) {
		degree *= degree_basis;
	}
	cout << degree;
}

//2.2
void Summary(int unit1, int unit2) {
	int sum = 0;
	for (; unit1 <= unit2; unit1++) {
		sum += unit1;
	}
	cout << sum;
}

//2.3
//https://en.wikipedia.org/wiki/List_of_perfect_numbers
//https://ru.wikipedia.org/wiki/%D0%A1%D0%BE%D0%B2%D0%B5%D1%80%D1%88%D0%B5%D0%BD%D0%BD%D0%BE%D0%B5_%D1%87%D0%B8%D1%81%D0%BB%D0%BE
void IdealDigit(unsigned __int64 begin, unsigned __int64 end) {
	for (unsigned __int64 i = begin; i < end; i++) {
		unsigned __int64 sum = 0;
		for (unsigned __int64 j = 1; j < i; j++) {
			if ((i % j) == 0) sum += j;
		}
		if (sum == i && sum) cout << sum << endl;
	}
}

//2.4
void Cards(int suit, int card) {
	_setmode(_fileno(stdout), _O_U16TEXT); // Переводим стандартный вывод (stdout) в режим Unicode
	wchar_t spade = L'\u2660';// L - литерал
	wchar_t club = L'\u2663';
	wchar_t heart = L'\u2665';
	wchar_t diamond = L'\u2666';
	wchar_t lear;//масть
	switch (suit) {
	case 'c':
		lear = club;
		break;
	case 's':
		lear = spade;
		break;
	case 'h':
		lear = heart;
		break;
	case 'd':
		lear = diamond;
		break;
	default:
		lear = heart;
		break;
	}
	const wchar_t* deck[15] = {
	L"\u250C\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2510\n\u2502 JK\u263B       \u2502\n\u2502     J     \u2502\n\u2502     O     \u2502\n\u2502     C     \u2502\n\u2502     K     \u2502\n\u2502     E     \u2502\n\u2502     R     \u2502\n\u2502           \u2502\n\u2502       JK\u263B \u2502\n\u2514\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2518\n",
	L"\u250C\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2510\n\u2502 A%c        \u2502\n\u2502           \u2502\n\u2502           \u2502\n\u2502           \u2502\n\u2502     %c     \u2502\n\u2502           \u2502\n\u2502           \u2502\n\u2502           \u2502\n\u2502        A%c \u2502\n\u2514\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2518\n",
	L"\u250C\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2510\n\u2502 2%c        \u2502\n\u2502     %c     \u2502\n\u2502           \u2502\n\u2502           \u2502\n\u2502           \u2502\n\u2502           \u2502\n\u2502           \u2502\n\u2502     %c     \u2502\n\u2502        2%c \u2502\n\u2514\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2518\n",
	L"\u250C\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2510\n\u2502 3%c        \u2502\n\u2502     %c     \u2502\n\u2502           \u2502\n\u2502           \u2502\n\u2502     %c     \u2502\n\u2502           \u2502\n\u2502           \u2502\n\u2502     %c     \u2502\n\u2502        3%c \u2502\n\u2514\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2518\n",
	L"\u250C\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2510\n\u2502 4%c        \u2502\n\u2502 %c       %c \u2502\n\u2502           \u2502\n\u2502           \u2502\n\u2502           \u2502\n\u2502           \u2502\n\u2502           \u2502\n\u2502 %c       %c \u2502\n\u2502        4%c \u2502\n\u2514\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2518\n",
	L"\u250C\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2510\n\u2502 5%c        \u2502\n\u2502 %c       %c \u2502\n\u2502           \u2502\n\u2502           \u2502\n\u2502     %c     \u2502\n\u2502           \u2502\n\u2502           \u2502\n\u2502 %c       %c \u2502\n\u2502        5%c \u2502\n\u2514\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2518\n",
	L"\u250C\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2510\n\u2502 6%c        \u2502\n\u2502 %c       %c \u2502\n\u2502           \u2502\n\u2502           \u2502\n\u2502 %c       %c \u2502\n\u2502           \u2502\n\u2502           \u2502\n\u2502 %c       %c \u2502\n\u2502        6%c \u2502\n\u2514\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2518\n",
	L"\u250C\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2510\n\u2502 7%c        \u2502\n\u2502 %c       %c \u2502\n\u2502           \u2502\n\u2502     %c     \u2502\n\u2502 %c       %c \u2502\n\u2502           \u2502\n\u2502           \u2502\n\u2502 %c       %c \u2502\n\u2502        7%c \u2502\n\u2514\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2518\n",
	L"\u250C\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2510\n\u2502 8%c        \u2502\n\u2502 %c       %c \u2502\n\u2502           \u2502\n\u2502 %c       %c \u2502\n\u2502           \u2502\n\u2502 %c       %c \u2502\n\u2502           \u2502\n\u2502 %c       %c \u2502\n\u2502        8%c \u2502\n\u2514\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2518\n",
	L"\u250C\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2510\n\u2502 9%c        \u2502\n\u2502 %c       %c \u2502\n\u2502     %c     \u2502\n\u2502 %c       %c \u2502\n\u2502           \u2502\n\u2502 %c       %c \u2502\n\u2502           \u2502\n\u2502 %c       %c \u2502\n\u2502        9%c \u2502\n\u2514\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2518\n",
	L"\u250C\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2510\n\u2502 10%c       \u2502\n\u2502 %c       %c \u2502\n\u2502     %c     \u2502\n\u2502 %c       %c \u2502\n\u2502           \u2502\n\u2502 %c       %c \u2502\n\u2502     %c     \u2502\n\u2502 %c       %c \u2502\n\u2502       10%c \u2502\n\u2514\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2518\n",
	L"\u250C\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2510\n\u2502 J%c        \u2502\n\u2502           \u2502\n\u2502     J     \u2502\n\u2502     A     \u2502\n\u2502     C     \u2502\n\u2502     K     \u2502\n\u2502           \u2502\n\u2502           \u2502\n\u2502        J%c \u2502\n\u2514\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2518\n",
	L"\u250C\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2510\n\u2502 Q%c        \u2502\n\u2502           \u2502\n\u2502     Q     \u2502\n\u2502     U     \u2502\n\u2502     E     \u2502\n\u2502     E     \u2502\n\u2502     N     \u2502\n\u2502           \u2502\n\u2502        Q%c \u2502\n\u2514\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2518\n",
	L"\u250C\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2510\n\u2502 K%c        \u2502\n\u2502           \u2502\n\u2502     K     \u2502\n\u2502     I     \u2502\n\u2502     N     \u2502\n\u2502     G     \u2502\n\u2502     %c     \u2502\n\u2502           \u2502\n\u2502        K%c \u2502\n\u2514\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2518\n",
	L"\u250C\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2510\n\u2502\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2502\n\u2502\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2502\n\u2502\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2502\n\u2502\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2502\n\u2502\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2502\n\u2502\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2502\n\u2502\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2502\n\u2502\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2502\n\u2502\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2592\u2502\n\u2514\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2518\n"
	};
	wcout << "\x1B[2J\x1B[H";
	wprintf(deck[card], lear, lear, lear, lear, lear, lear, lear, lear, lear, lear, lear, lear);
}

//2.5
void Lucky() {
	int number = 100000;
	int lucky_end = 999999;
	for (; number <= lucky_end; number++) {
		int f3 = 0, s3 = 0;
		f3 = number / 100000 + (number / 10000 - number / 100000 * 10) + (number / 1000 - number / 10000 * 10);
		s3 = (number / 100 - number / 1000 * 10) + (number / 10 - number / 100 * 10) + (number - number / 10 * 10);
		if (f3 == s3) {
			cout << number << endl;
		}
	}
}

int main() {

	setlocale(0, "rus");

	//1.1/1.2
	int arr[5][5];
	double num;
	cout << "Введите число" << endl;
	cin >> num;
	arr[0][0] = num;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			arr[i][j] = num;
			cout << setw(10) << arr[i][j] << " ";
			num = num * 2;
		}
		cout << endl;
	}
	cout << endl;
	num = arr[0][0];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			arr[i][j] = num;
			cout << setw(3) << arr[i][j] << " ";
			num = num + 1;
		}
		cout << endl;
	}

	1.3
		const int rows = 4;
	const int cols = 6;
	int arr[rows][cols];
	int steps;
	char direction;
	// генерация массива
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = rand() % 10 - 0;
			cout << setw(3) << arr[i][j];
		}
		cout << endl;
	}
	while (true) {
		cout << "Введите кол-во шагов сдвига и направление (влево l, вправо r, вверх u, вниз d), например 2l" << endl;
		cin >> steps >> direction;
		for (int s = 0; s < steps; s++) {
			switch (direction) {
			case 'r':
				for (int i = 0; i < rows; i++) {
					for (int j = 0; j < cols; j++) {
						swap(arr[i][j], arr[i][cols - 1]);
					}
				}
				break;
			case 'l':
				for (int i = 0; i < rows; i++) {
					for (int j = cols - 1; j >= 0; j--) {
						swap(arr[i][j], arr[i][cols - 1]);
					}
				}
				break;
			case 'u':
				for (int i = 0; i < rows; i++) {
					for (int j = 0; j < cols; j++) {
						swap(arr[i][j], arr[rows - 1][j]);
					}
				}
				break;
			case 'd':
				for (int i = 0; i < rows; i++) {
					for (int j = cols - 1; j >= 0; j--) {
						swap(arr[i][j], arr[rows - 1][j]);
					}
				}
				break;
			}
		}
		// вывод на экран
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << setw(3) << arr[i][j];
			}
			cout << endl;
		}
	}

	//2.1
	Exponentiation(12, 2);

	//2.2
	Summary(-5, 5);

	//2.3
	IdealDigit();

	//2.4
	char suit;
	int card;
	Cards('h', 14);
	while (true) {
		wcout << L"\u2663 с\n\u2660 s\n\u2665 h\n\u2666 d\n0 Jocker\n1 Ace\n2,3,4,5,6,7,8,9,10\n11 Jack\n12 Queen\n13 King\n14 back\nExample: h5\n";
		cin >> suit >> card;
		Cards(suit, card);
	}

	2.5
		Lucky();
}
