#include<stdio.h>
#include<fcntl.h> 
#include<io.h>    
#include<string.h>
#include<wchar.h>

struct SV{
	wchar_t MSSV[20];
	wchar_t HVTen[30];
	wchar_t Khoa[30];
	int KhoaHoc;
	wchar_t NgaySinh[11];
	wchar_t Hinhanh[16];
	wchar_t Motabanthan[1001];
	wchar_t Sothich1[101];
	wchar_t Sothich2[101];
};

void DocFILECSV(FILE* f, SV &A)
{
	if (f != NULL)
	{
		fgetws(A.MSSV, 14, f);
		A.MSSV[wcslen(A.MSSV) - 1] = L'\0';
	}
	fclose(f);
}

void main()
{
	FILE* f = fopen("1712908.csv", "rt");
	SV A;
	_setmode(_fileno(stdout), _O_U16TEXT); 
	_setmode(_fileno(stdin), _O_U16TEXT);
	DocFILECSV(f, A);
	FILE* f1 = fopen("B.txt", "wt");
	if (f1 != NULL)
	{
		fputws(A.MSSV, f1);
	}
	fclose(f1);
}