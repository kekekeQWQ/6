#include<stdio.h>
void setData(int a[], int n) {
	printf("请输入%d个数组元素值:\n", n);
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
	printf("请输入数组元素个数n的值：");
	scanf_s("%d", &n);
	setData(a, n);
	printf("请输入第k小元素中的k的值：");
	scanf_s("%d", &k);
	value = divisionRecursion(a, n, k);
	printf("数组的第%d小元素是：%d\n", k, value);
}