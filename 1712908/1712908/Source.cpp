#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h> 
#include<io.h>    
#include<string.h>
#include<wchar.h>

struct SV
{
	wchar_t* MSSV;
	wchar_t* HVTen;
	wchar_t* Khoa;
	wchar_t* KhoaHoc;
	wchar_t* NgaySinh;
	wchar_t* Hinhanh;
	wchar_t* Email;
	wchar_t* Motabanthan;
	wchar_t** Sothich;
};

void TaoHTML(SV&, int);

void DocFILECSV(FILE* f)
{
	_setmode(_fileno(f), _O_U8TEXT);
	wchar_t** p = (wchar_t**)malloc(20 * sizeof(wchar_t*));
	int dem = 0;
	if (f != NULL)
	{
		while (!feof(f))
		{
			p[dem] = (wchar_t*)malloc(1000 * sizeof(wchar_t));
			fgetws(*(p + dem), 1000, f);
			p[dem][wcslen(p[dem]) - 1] = L'\0';
			dem++;
		}
		dem--;
		for (int i = 0; i < dem; i++)
		{
			SV A;
			int demsothich = 0;
			wchar_t* flag[10];
			wchar_t* del;
			if (i == 0)
			{
				del = wcstok(p[i], L"\"");
				A.MSSV = wcstok(NULL, L"\"");
			}
			else
			{
				A.MSSV = wcstok(p[i], L"\"");
			}
			del = wcstok(NULL, L"\"");
			A.HVTen = wcstok(NULL, L"\"");
			del = wcstok(NULL, L"\"");
			A.Khoa = wcstok(NULL, L"\"");
			del = wcstok(NULL, L"\"");
			A.KhoaHoc = wcstok(NULL, L"\"");
			del = wcstok(NULL, L"\"");
			A.NgaySinh = wcstok(NULL, L"\"");
			del = wcstok(NULL, L"\"");
			A.Hinhanh = wcstok(NULL, L"\"");
			del = wcstok(NULL, L"\"");
			A.Email = wcstok(NULL, L"\"");
			del = wcstok(NULL, L"\"");
			A.Motabanthan = wcstok(NULL, L"\"");
			del = wcstok(NULL, L"\"");
			flag[demsothich] = wcstok(NULL, L"\"");
			while (flag[demsothich] != NULL)
			{
				demsothich++;
				del = wcstok(NULL, L"\"");
				flag[demsothich] = wcstok(NULL, L"\"");
			}
			A.Sothich =(wchar_t**)malloc(demsothich * sizeof(wchar_t*));
			for (int j = 0; j < demsothich; j++)
			{
				*(A.Sothich + j) = flag[j];
			}
			TaoHTML(A, demsothich);
			free(A.Sothich);
		}
		fclose(f);
	}
	for (int i = 0; i < dem; i++)
	{
		free(*(p + i));
	}
	free(p);
}

void TaoHTML(SV &A, int n)
{
	wchar_t s0[50] = L"WEBSITE\\";
	wchar_t s1[20];
	wcscpy(s1, A.MSSV);
	wcscat(s1, L".html");
	wcscat(s0, s1);
	FILE* f = _wfopen(s0, L"wt");
	FILE* f1 = fopen("WEBSITE\\Template.html", "rt");
	_setmode(_fileno(f1), _O_U8TEXT);
	_setmode(_fileno(f), _O_U8TEXT);
	if ((f != NULL) && (f1 != NULL))
	{
		wchar_t* check;
		wchar_t flag[500];
		wchar_t s1[] = L"Họ và tên";
		wchar_t s2[] = L"MSSV";
		wchar_t s3[] = L"Sinh viên khoa";
		wchar_t s4[] = L"Ngày sinh";
		wchar_t s5[] = L"Email";
		wchar_t s6[] = L"class=\"InfoGroup\">Sở thích";
		wchar_t s7[] = L"class=\"InfoGroup\">Mô tả";
		wchar_t s8[] = L"class=\"Personal_HinhcanhanKhung\"";
		wchar_t s9[] = L"class=\"Personal_Phone\"";
		wchar_t s10[] = L"class=\"Personal_Department\"";
		wchar_t s11[] = L"class=\"Personal_FullName\"";
		wchar_t s12[] = L"<title>";
		while (!feof(f1))
		{
			int tieptuc = 1;
			fgetws(flag, 500, f1);
			flag[wcslen(flag) - 1] = L'\0';
			check = wcswcs(flag, s1);
			if (check != NULL)
			{
				fwprintf(f, L"<li>Họ và tên: %ls</li>\n", A.HVTen);
				tieptuc = 0;
			}
			check = wcswcs(flag, s2);
			if ((check != NULL) && (tieptuc))
			{
				fwprintf(f, L"<li>MSSV: %ls</li>\n", A.MSSV);
				tieptuc = 0;
			}
			check = wcswcs(flag, s3);
			if ((check != NULL) && (tieptuc))
			{
				fwprintf(f, L"<li>Sinh viên khoa %ls</li>\n", A.Khoa);
				tieptuc = 0;
			}
			check = wcswcs(flag, s4);
			if ((check != NULL) && (tieptuc))
			{
				fwprintf(f, L"<li>Ngày sinh: %ls</li>\n", A.NgaySinh);
				tieptuc = 0;
			}
			check = wcswcs(flag, s5);
			if ((check != NULL) && (tieptuc))
			{
				fwprintf(f, L"<li>Email : <a href=\"mailto:%ls\" target=\"_blank\" title=\"Email cá nhân\">%ls</a></li>\n", A.Email, A.Email);
				tieptuc = 0;
			}
			check = wcswcs(flag, s6);
			if ((check != NULL) && (tieptuc))
			{
				fwprintf(f, L"%ls\n", flag);
				fgetws(flag, 500, f1);
				flag[wcslen(flag) - 1] = L'\0';
				fwprintf(f, L"%ls\n", flag);
				fgetws(flag, 500, f1);
				flag[wcslen(flag) - 1] = L'\0';
				fwprintf(f, L"%ls\n", flag);
				for (int i = 0; i < n; i++)
				{
					fwprintf(f, L"	<li>%ls</li>\n", *(A.Sothich + i));
				}
				tieptuc = 0;
			}
			check = wcswcs(flag, s7);
			if ((check != NULL) && (tieptuc))
			{
				fwprintf(f, L"%ls\n", flag);
				fgetws(flag, 500, f1);
				flag[wcslen(flag) - 1] = L'\0';
				fwprintf(f, L"%ls\n", flag);
				fwprintf(f, L"%ls\n", A.Motabanthan);
				tieptuc = 0;
			}
			check = wcswcs(flag, s8);
			if ((check != NULL) && (tieptuc))
			{
				fwprintf(f, L"%ls\n", flag);
				fwprintf(f, L"<img src=\"Images/%ls\" class=\"Personal_Hinhcanhan\" />\n", A.Hinhanh);
				tieptuc = 0;
			}
			check = wcswcs(flag, s9);
			if ((check != NULL) && (tieptuc))
			{
				fwprintf(f, L"%ls\n", flag);
				fwprintf(f, L"Email: %ls\n", A.Email);
				tieptuc = 0;
			}
			check = wcswcs(flag, s10);
			if ((check != NULL) && (tieptuc))
			{
				fwprintf(f, L"<div class=\"Personal_Department\">%ls</div>\n", A.Khoa);
				tieptuc = 0;
			}
			check = wcswcs(flag, s11);
			if ((check != NULL) && (tieptuc))
			{
				fwprintf(f, L"<span class=\"Personal_FullName\">%ls - %ls</span>",A.HVTen,A.MSSV);
				tieptuc = 0;
			}
			check = wcswcs(flag, s12);
			if ((check != NULL) && (tieptuc))
			{
				fwprintf(f, L"<title>HCMUS - %ls</title>\n", A.HVTen);
				tieptuc = 0;
			}
			if (tieptuc) fwprintf(f, L"%ls\n", flag);
		}
		fclose(f);
		fclose(f1);
	}
}

void main()
{
	FILE* f1 = fopen("Thongtinsinhvien.csv", "rt");
	DocFILECSV(f1);
}