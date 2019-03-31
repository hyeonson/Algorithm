#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

int a[N] = { 0, };
int b[N] = { 0, };
int c[N] = { 0, };

void Menu() {
	printf("==============[[Super Restaurant]]===========\n\n");
	printf("1. 메뉴 열람\n");
	printf("2. 주문 전체 현황\n");
	printf("3. 주문 결제\n");
	printf("4. 종료\n");
}

int order1() {
	int n, x, total = 0;
	int price = 0;
	char ans = 0;

	do {
		printf("(1).스파게티(\\10.000)\n");
		printf("(2).피자(\\20.000)\n");
		printf("(3).핫도그(\\4.000)\n");
		printf("\n원하는 메뉴 선택하세요: ");
		scanf("%d", &n);

		switch (n) {
		case 1: price = 10000; break;
		case 2: price = 20000; break;
		case 3: price = 4000; break;
		default: printf("없는 메뉴입니다. 다시 선택해주세요.\n");
		}

		printf("몇 인분을 주문하시겠습니까? ");
		scanf("%d", &x);

		total += price * x;

		printf("주문을 계속 하시곘습니까?(y/n) ");
		scanf(" %c", &ans);
		printf("\n");
	} while (ans != 'n');

	printf("%d\n", total);

	return total;
}

void order2() {
	printf("===============================================\n");
	printf("Tno.           결제금액          테이블상태 \n");
	printf("===============================================\n");

	for (int i = 0; i < 10; i++) {
		if (c[i] == 1) {
			printf("%3d %18d           사용중\n", i + 1, a[i]);
			printf("-----------------------------------------------\n");
		}
		else {
			printf("%3d %18d           빈 테이블\n", i + 1, a[i]);
			printf("-----------------------------------------------\n");
		}
	}
	printf("\n");
}

void order3() {
	int table;
	int i;

	printf("테이블 번호를 선택하세요.(1~10): ");
	scanf("%d", &table);
	printf("\n고객님의 결제 금액은 %d원입니다.\n\n", a[table - 1]);
	a[table - 1] = 0;
	c[table - 1] = 0;
	printf("고객님 고맙습니다!!\n");
}


int main() {
	int i, y, menu, table = 0, total = 0;
	srand(time(0));

	while (1) {
		Menu();
		printf("\n원하는 메뉴 선택하세요: ");
		scanf("%d", &menu);
		printf("-------------------------\n\n");

		switch (menu) {
		case 1: total = order1();
			do {
				y = rand() % 10;
			} while (c[y] != 0);
			c[y] = 1;
			a[y] = total;
			break;
		case 2: order2(); break;
		case 3: order3(); break;
		case 4: return 0;
		default: printf("없는 메뉴입니다. 다시 선택해주세요.\n");
		}
	}
}