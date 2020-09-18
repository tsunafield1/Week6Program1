#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct SMS
{
	char a = ' ';
	int score = 0;
	bool in = 1;
};

void sort(SMS*);

int main()
{
	char vote[10001];
	SMS data[7];
	int num = 7;
	for (int i = 0; i < 7; i++)
	{
		data[i].a = 'A' + i;
	}
	scanf("%s", vote);
	while (vote[0] != '!')
	{
		for (int i = 0; vote[i] != '\0'; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (data[j].a == vote[i])
				{
					if(data[j].in == 1) data[j].score++;
					break;
				}
			}
		}
		sort(data);
		for (int i = num-1; i >= 1; i--)
		{
			if (data[i].score == data[i - 1].score)
			{
				break;
			}
			else
			{
				data[i].in = 0;
				data[i].score = -1;
				num--;
				break;
			}
		}
		scanf("%s", vote);
	}
	printf("%d\n", num);
	for (int i = 0; i < num; i++)
	{
		printf("%c %d\n", data[i].a, data[i].score);
	}
}

void sort(SMS a[])
{
	char A;
	int score;
	bool in;
	for (int i = 0; i < 6; i++)
	{
		for (int j = i + 1; j < 7; j++)
		{
			if (a[i].score < a[j].score || (a[i].score == a[j].score && a[i].a > a[j].a))
			{
				A = a[i].a;
				score = a[i].score;
				in = a[i].in;
				a[i].a = a[j].a;
				a[i].score = a[j].score;
				a[i].in = a[j].in;
				a[j].a = A;
				a[j].score = score;
				a[j].in = in;
			}
		}
	}
}