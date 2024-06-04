#include <stdio.h>
void swap(double* pa, double* pb);
void line_up(double* maxp, double* midp, double* minp);

int main(void)
{
	double max, mid, min;
	printf("�Ǽ��� 3�� �Է� : ");
	scanf_s("%lf%lf%lf", &max, &mid, &min);
	line_up(&max, &mid, &min);
	printf("���ĵ� �� ��� : %.1lf, %.1lf, %.1lf\n", max, mid, min);

	return 0;

}

void swap(double* pa, double* pb)
{
	double temp;

	temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void line_up(double* maxp, double* midp, double* minp)
{
	// max, mid, min �߿��� ���� ū ���� maxp�� ����Ű�� ������ ��ġ�ϵ��� ��
	if (*maxp < *midp)
		swap(maxp, midp);
	if (*maxp < *minp)
		swap(maxp, minp);
	// ���� maxp�� ���� ū ���̹Ƿ� midp�� minp�� ���Ͽ� ����
	if (*midp < *minp)
		swap(midp, minp);
}
