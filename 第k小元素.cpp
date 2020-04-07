#include<stdio.h>
void setData(int a[], int n) {
	printf("������%d������Ԫ��ֵ:\n", n);
	for (int i = 0; i < n; i++)
		scanf_s("%d", &a[i]);
}
void sort(int a[], int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				int k;
				k = a[i];
				a[i] = a[j];
				a[j] = k;
			}
		}
	}
}
int localData(int a[], int value)
{
	int i = 0;
	while (a[i] != value)
		i++;
	return i;
}
void copyData(int a[], int d[], int n)
{
	for (int i = 0; i < n; i++)
		a[i] = d[i];
}
int divisionRecursion(int a[], int n, int k)
{
	if (n <= 6)
	{
		sort(a, n);
		return a[k - 1];
	}
	else
	{
		int b[10], c[10], d[50];
		int i = 0, j = 0, t = 0;
		while (i < n)
		{
			b[j++] = a[i++];
			if (i % 5 == 0 | i == n)
			{
				sort(b, j);
				c[t++] = b[j / 2];
				j = 0;
			}
		}
		sort(c, t);
		if (k == localData(a, c[t / 2]))
			return c[t / 2];
		else if (k < localData(a, c[t / 2]))
		{
			int i = 0, j = 0;
			while (i < n)
			{
				if (a[i] < c[t / 2])
					d[j++] = a[i];
				i++;
			}
			n = j;
			copyData(a, d, j);
			return divisionRecursion(a, n, k);
		}
		else
		{
			int i = 0, j = 0;
			while (i < n) {
				if (a[i] > c[t / 2])
					d[j++] = a[i];
				i++;
			}
			k = k - n + j;
			n = j;
			copyData(a, d, j);
			return divisionRecursion(a, n, k);
		}
	}
}
int main() {
	int a[50], n, k, value;
	printf("����������Ԫ�ظ���n��ֵ��");
	scanf_s("%d", &n);
	setData(a, n);
	printf("�������kСԪ���е�k��ֵ��");
	scanf_s("%d", &k);
	value = divisionRecursion(a, n, k);
	printf("����ĵ�%dСԪ���ǣ�%d\n", k, value);
}