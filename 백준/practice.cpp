#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

int a[N] = { 0, };
int b[N] = { 0, };
int c[N] = { 0, };

void Menu() {
	printf("==============[[Super Restaurant]]===========\n\n");
	printf("1. �޴� ����\n");
	printf("2. �ֹ� ��ü ��Ȳ\n");
	printf("3. �ֹ� ����\n");
	printf("4. ����\n");
}

int order1() {
	int n, x, total = 0;
	int price = 0;
	char ans = 0;

	do {
		printf("(1).���İ�Ƽ(\\10.000)\n");
		printf("(2).����(\\20.000)\n");
		printf("(3).�ֵ���(\\4.000)\n");
		printf("\n���ϴ� �޴� �����ϼ���: ");
		scanf("%d", &n);

		switch (n) {
		case 1: price = 10000; break;
		case 2: price = 20000; break;
		case 3: price = 4000; break;
		default: printf("���� �޴��Դϴ�. �ٽ� �������ּ���.\n");
		}

		printf("�� �κ��� �ֹ��Ͻðڽ��ϱ�? ");
		scanf("%d", &x);

		total += price * x;

		printf("�ֹ��� ��� �ϽÁٽ��ϱ�?(y/n) ");
		scanf(" %c", &ans);
		printf("\n");
	} while (ans != 'n');

	printf("%d\n", total);

	return total;
}

void order2() {
	printf("===============================================\n");
	printf("Tno.           �����ݾ�          ���̺���� \n");
	printf("===============================================\n");

	for (int i = 0; i < 10; i++) {
		if (c[i] == 1) {
			printf("%3d %18d           �����\n", i + 1, a[i]);
			printf("-----------------------------------------------\n");
		}
		else {
			printf("%3d %18d           �� ���̺�\n", i + 1, a[i]);
			printf("-----------------------------------------------\n");
		}
	}
	printf("\n");
}

void order3() {
	int table;
	int i;

	printf("���̺� ��ȣ�� �����ϼ���.(1~10): ");
	scanf("%d", &table);
	printf("\n������ ���� �ݾ��� %d���Դϴ�.\n\n", a[table - 1]);
	a[table - 1] = 0;
	c[table - 1] = 0;
	printf("���� �����ϴ�!!\n");
}


int main() {
	int i, y, menu, table = 0, total = 0;
	srand(time(0));

	while (1) {
		Menu();
		printf("\n���ϴ� �޴� �����ϼ���: ");
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
		default: printf("���� �޴��Դϴ�. �ٽ� �������ּ���.\n");
		}
	}
}