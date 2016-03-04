/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int convert(char);
int split(char *, int, int);
int isLeapyear(int);
int isOlder(char *dob1, char *dob2) {
	int day1, month1, year1,year2,month2,day2, i,len=-1,lp;
	int a[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (i = 0; dob1[i] != '\0' && dob2[i] != '\0'; i++)
	{
		len++;
	}
	if (len != 9)
	{
		return -1;
	}
	else
	{
		year1 = split(dob1, 6, 9);
		year2 = split(dob2, 6, 9);
		month1 = split(dob1, 3, 4);
		month2 = split(dob2, 3, 4);
		day1 = split(dob1, 0, 1);
		day2 = split(dob2, 0, 1);
		if (year1 < 0 || year2 < 0 || month1 < 0 || month2 < 0 || day1 < 0 || day2 < 0)
		{
			return -1;
		}
		if (dob1[2] != '-'||dob2[2] != '-'||dob1[5] != '-' || dob2[5] != '-')
		{
			return -1;
		}
		if (month1 > 12|| month2 > 12 || month1==0 || month2==0)
		{
			return -1;
		}
		if (day1 > a[month1-1])
		{
			return -1;
		}
		if (day2 > a[month2-1])
		{
			return -1;
		}
		if (month1 == 2)
		{
			if (day1 == 29)
			{
				lp=isLeapyear(year1);
			}
			if (lp == 0)
			{
				return -1;
			}
		}
		if (month2 == 2)
		{
			if (day2 == 29)
			{
				lp=isLeapyear(year2);
			}
			if (lp == 0)
			{
				return -1;
			}
		}

		if (year1 > year2)
		{
			return 2;
		}
		else if (year2 > year1)
		{
			return 1;
		}
		if (month1 > month2)
		{
			return 2;
		}
		if (month2 > month1)
		{
			return 1;
		}
		if (day1 > day2)
		{
			return 2;
		}
		if (day2 > day1)
		{
			return 1;
		}

			
		

	}
	return 0;
}
int split(char *dob, int j, int n)
{
	int i,temp,num=0;

	for (i = j; i <= n; i++)
	{
		if (dob[i] >= 48 && dob[i] <= 57)
		{
			temp = convert(dob[i]);
			num = num * 10 + temp;
		}
		else
		{
			return -1;
		}
	}
	return num;
}

int convert(char c)
{
	int a;
	a = c - '0';
	return a;
}
int isLeapyear(int a)
{
	if (a % 400 == 0)
	{
		return 1;
	}
	else if (a % 100 == 0)
	{
		return 0;
	}
	else if (a % 4 == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}