#include <stdio.h>
#include <math.h>
#include <locale.h>

void main() {
	setlocale(LC_ALL, "Russian");
	double x1, y1, r1, r2, x2, y2, d, R;
	printf("������� ���������� ������ ������ ����������(x,y) � ������:\n");
	printf("x=");
	scanf("%lf", &x1);
	printf("y=");
	scanf("%lf", &y1);
	printf("r=");
	scanf("%lf", &r1);
	printf("������� ���������� ������ ������ ����������(x,y) � ������:\n");
	printf("x=");
	scanf("%lf", &x2);
	printf("y=");
	scanf("%lf", &y2);
	printf("r=");
	scanf("%lf", &r2);
	R = abs(r1 - r2);
	d = sqrt(((x1 - x2)*(x1 - x2)) + ((y1 - y2)*(y1 - y2)));
	printf("���������� ����� �������� ���������� = %.4lf \n", d);
	printf("�������� ������������ ���� �����������: \n");
	if (d > r1+ r2) {
		printf("���������� �� ����� ����� ����� \n");
		return;
	}
	if (d == r1 + r2) {
		printf("���������� ����� 1 ����� ����� (������� �������) \n");
		return;
	}
	if (d == R) {
		printf("���������� ����� 1 ����� ����� (���������� �������) \n");
		return;
	}
	if ((R < d) && (d < r1 + r2)) {
		printf("���������� ����� ��� ����� �����(������������) \n");
		return;
	}
	if ((0 < d) && (d < R)) {
		printf("���� ���������� ������ ������ ���������� \n");
		return;
	}
	if ((x1==x2) && (y1==y2) && (r1==r2)) {
		printf("���������� ��������� \n");
		return;
	}
	if ((x1 == x2) && (y1 == y2) && (r1 != r2)) {
		printf("������ ����������� ��������� \n");
		return;
	}
}