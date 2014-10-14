#include <string.h>
#include <stdio.h>

#define MAXDAYS 42  //7 * 6 = 42
#define MONDAY 1  //1900��1��1��������1
#define SPACE -1

char month_name[13][10] = {"","January", "February", "March", "April", "May", "June", 
							"July", "August", "September", "October", "November", "December" };

int days_in_month[2][13] = {
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
};

int empty[MAXDAYS] = {
	SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
	SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
	SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
	SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
	SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
	SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE
};

//��������
int day_in_week(int day, int month, int year);
bool is_leap(int year);
int leap_years_since1900(int year);
int day_in_year(int day, int month, int year);
void day_array(int month, int year, int *days);

//��ӡ����
void show_cal(int month, int year)
{
	printf("          %d      %s\n", year,month_name[month]);
	printf("  SUN  MON  TUE  WEN  THU  FRI  SAT\n");
	int cal[MAXDAYS];
	day_array(month, year, cal);
	for (int col = 1; col <= 6; col++)
	{
		for (int row = 1; row <= 7; row++)
		{
			int value = cal[(row - 1) + (col - 1) * 7];
			if (value > 0)
				printf("%5d", value);
			else
				printf("     ");
		}
		printf("\n");
	}
	return;
}

//��6*7��������д����
void day_array(int month, int year, int *days) {
	int daynum, dw, dm;
	memcpy(days, empty, MAXDAYS * sizeof(int));
	dm = days_in_month[is_leap(year)][month];
	dw = day_in_week(1, month, year) ;
	daynum = 1;
	while (dm--) {
		days[dw] = daynum++;
		dw++;
	}
}
//��ĳ���������ڼ�(0Ϊ������)
int day_in_week(int day, int month, int year) {
	int temp = (year - 1900) * 365 + leap_years_since1900(year)
		+ day_in_year(day, month, year);
	return (temp - 1 + MONDAY) % 7;
}
//��M��D����Y��ĵڼ���
int day_in_year(int day, int month, int year) 
{
	int leap = is_leap(year);
	for (int i = 1; i < month; i++)
		day += days_in_month[leap][i];
	return day;
}
//1900����X��֮���м������꣨������X��
int leap_years_since1900(int year)
{
	int count = 0;
	for (int i = 1900; i < year; i++)
	{
		if (is_leap(i))
			count++;
	}
	return count;
}
//�ж�����
bool is_leap(int year)
{
	bool leap = (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) ? true : false;
	return leap;
}