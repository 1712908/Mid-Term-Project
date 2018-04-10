#include<stdio.h>
#include<fcntl.h> 
#include<io.h>    
#include<string.h>
#include<wchar.h>

struct SV{
	wchar_t* MSSV;
	wchar_t* HVTen;
	wchar_t* Khoa;
	wchar_t* KhoaHoc;
	wchar_t* NgaySinh;
	wchar_t* Hinhanh;
	wchar_t* Motabanthan;
	wchar_t** Sothich;
};

void DocFILECSV(FILE* f, SV &A, int &demsothich)
{
	if (f != NULL)
	{
		demsothich = 0;
		wchar_t* flag[20];
		wchar_t* del;
		wchar_t s[500];
		fgetws(s, 500, f);
		s[wcslen(s) - 1] = L'\0';
		del = wcstok(s, L",\"");
		A.MSSV = wcstok(NULL, L",\"");
		A.HVTen = wcstok(NULL, L",\"");
		A.Khoa = wcstok(NULL, L",\"");
		A.KhoaHoc = wcstok(NULL, L",\"");
		A.NgaySinh = wcstok(NULL, L",\"");
		A.Hinhanh = wcstok(NULL, L",\"");
		A.Motabanthan = wcstok(NULL, L",\"");
		flag[demsothich] = wcstok(NULL, L",\"");
		while (flag[demsothich] != NULL)
		{
			printf("%d\n", demsothich);
			demsothich++;
			flag[demsothich] = wcstok(NULL, L",\"");
		}
		printf("%d\n", demsothich);
		A.Sothich = new wchar_t*[demsothich];
		for (int i = 0; i < demsothich; i++)
		{
			*(A.Sothich + i) = flag[i];
		}
	}
}

void main()
{
	int n;
	FILE* f = fopen("1712908.csv", "rt");
	FILE* f1 = fopen("B.txt", "wt");
	SV A;
	_setmode(_fileno(f1), _O_U8TEXT); 
	_setmode(_fileno(f), _O_U8TEXT);
	//_setmode(_fileno(stdin), _O_U8TEXT);
	//_setmode(_fileno(stdout), _O_U8TEXT);
	DocFILECSV(f, A, n);
	if (f1 != NULL)
	{
		fputws(A.MSSV, f1);
		fputws(A.HVTen, f1);
		fputws(A.Khoa, f1);
		fputws(A.KhoaHoc, f1);
		fputws(A.NgaySinh, f1);
		fputws(A.Hinhanh, f1);
		fputws(A.Motabanthan, f1);
		for (int i = 0; i < n; i++)
		{
			fputws(*(A.Sothich + i), f1);
		}
	}
	fclose(f);
	fclose(f1);
}