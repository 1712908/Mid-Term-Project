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

void KiemTraNgoac(wchar_t*);
void TaoHTML(SV, int);
void SaoChepChuoi(wchar_t*, wchar_t*);
void XoaNgoacKep(wchar_t*);
void GhepChuoiDauPhay(wchar_t*, wchar_t*);
void GhepChuoi(wchar_t*, wchar_t*);

void DocFILECSV(char s[])
{
	FILE* f = fopen(s,"rt");
	wchar_t** p = (wchar_t**)malloc(0 * sizeof(wchar_t*));
	int dem = 0;
	if (f != NULL)
	{
		_setmode(_fileno(f), _O_U8TEXT);
		while (!feof(f))
		{
			p = (wchar_t**)realloc(p, (dem + 1)*sizeof(wchar_t*));
			*(p + dem) = (wchar_t*)malloc(600 * sizeof(wchar_t));
			fgetws(*(p + dem), 600, f);
			p[dem][wcslen(p[dem])] = L'\0';
			dem++;
		}
		for (int i = 0; i < dem - 1; i++) /*Xoa ki tu \n*/
		{
			p[i][wcslen(p[i]) - 1] = '\0';
		}
		wchar_t s3[] = L",";
		for (int i = 0; i < dem; i++)
		{
			SV A;
			int demsothich = 0;
			int n = 1;
			wchar_t** sothich = (wchar_t**)malloc(0 * sizeof(wchar_t*));
			wchar_t* a;
			wchar_t** flag;
			if (i == 0)
			{
				wchar_t* thaythe1;
				wchar_t thaythe[15];
				thaythe1 = wcstok(p[i], s3);
				SaoChepChuoi(thaythe, thaythe1);
				int m = wcslen(thaythe);
				*(thaythe + m) = '\"';
				*(thaythe + m + 1) = '\0';
				XoaNgoacKep(thaythe); /*Xoa ki tu dau tien cua file*/
				A.MSSV = thaythe;
			}
			else
			{
				A.MSSV = wcstok(p[i], s3);
			}
			KiemTraNgoac(A.MSSV);
			A.HVTen = wcstok(NULL, s3);
			KiemTraNgoac(A.HVTen);
			A.Khoa = wcstok(NULL, s3);
			KiemTraNgoac(A.Khoa);
			A.KhoaHoc = wcstok(NULL, s3);
			KiemTraNgoac(A.KhoaHoc);
			A.NgaySinh = wcstok(NULL, s3);
			KiemTraNgoac(A.NgaySinh);
			A.Hinhanh = wcstok(NULL, s3);
			KiemTraNgoac(A.Hinhanh);
			A.Email = wcstok(NULL, s3);
			KiemTraNgoac(A.Email);
			a = wcstok(NULL, s3);
			if ((*a == '\"') && (*(a + wcslen(a) - 1) == '\"'))
			{
				XoaNgoacKep(a);
				A.Motabanthan = a;
			}
			else
			{
				if (*a == '\"')
				{
					n = 1;
					wchar_t chuoi[500];
					flag = (wchar_t**)malloc(n*sizeof(wchar_t*));
					*flag = a;
					do
					{
						n++;
						a = wcstok(NULL, s3);
						flag = (wchar_t**)realloc(flag, n*sizeof(wchar_t*));
						*(flag + n - 1) = a;
					} while (*(a + wcslen(a) - 1) != '\"');
					SaoChepChuoi(chuoi, *flag);
					for (int i = 1; i < n; i++)
					{
						GhepChuoiDauPhay(chuoi, *(flag + i));
					}
					XoaNgoacKep(chuoi);
					A.Motabanthan = chuoi;
					free(flag);
				}
				else
				{
					A.Motabanthan = a;
				}
			}
			sothich = (wchar_t**)realloc(sothich, (demsothich + 1)*sizeof(wchar_t*));
			a = wcstok(NULL, s3);
			if ((*a == '\"') && (*(a + wcslen(a) - 1) == '\"'))
			{
				XoaNgoacKep(a);
				sothich[demsothich] = a;
			}
			else
			{
				if (*a == '\"')
				{
					n = 1;
					wchar_t chuoi[500];
					flag = (wchar_t**)malloc(n*sizeof(wchar_t*));
					*flag = a;
					do
					{
						n++;
						a = wcstok(NULL, s3);
						flag = (wchar_t**)realloc(flag, n*sizeof(wchar_t*));
						*(flag + n - 1) = a;
					} while (*(a + wcslen(a) - 1) != '\"');
					SaoChepChuoi(chuoi, *flag);
					for (int i = 1; i < n; i++)
					{
						GhepChuoiDauPhay(chuoi, *(flag + i));
					}
					XoaNgoacKep(chuoi);
					sothich[demsothich] = chuoi;
					free(flag);
				}
				else
				{
					sothich[demsothich] = a;
				}
			}
			while (a != NULL)
			{
				demsothich++;
				sothich = (wchar_t**)realloc(sothich, (demsothich + 1)*sizeof(wchar_t*));
				a = wcstok(NULL, s3);
				if (a != NULL)
				{
					if ((*a == '\"') && (*(a + wcslen(a) - 1) == '\"'))
					{
						XoaNgoacKep(a);
						sothich[demsothich] = a;
					}
					else
					{
						if (*a == '\"')
						{
							n = 1;
							wchar_t chuoi[500];
							flag = (wchar_t**)malloc(n*sizeof(wchar_t*));
							*flag = a;
							do
							{
								n++;
								a = wcstok(NULL, s3);
								flag = (wchar_t**)realloc(flag, n*sizeof(wchar_t*));
								*(flag + n - 1) = a;
							} while (*(a + wcslen(a) - 1) != '\"');
							SaoChepChuoi(chuoi, *flag);
							for (int i = 1; i < n; i++)
							{
								GhepChuoiDauPhay(chuoi, *(flag + i));
							}
							XoaNgoacKep(chuoi);
							sothich[demsothich] = chuoi;
							free(flag);
						}
						else
						{
							sothich[demsothich] = a;
						}
					}
				}
			}
			A.Sothich =(wchar_t**)malloc(demsothich * sizeof(wchar_t*));
			for (int j = 0; j < demsothich; j++)
			{
				*(A.Sothich + j) = sothich[j];
			}
			TaoHTML(A, demsothich);
			free(A.Sothich);
			free(sothich);
		}
		for (int i1 = 0; i1 < dem; i1++)
		{
			free(*(p + i1));
		}
		fclose(f);
	}
	free(p);
}

void TaoHTML(SV A, int n)
{
	wchar_t s0[50] = L"WEBSITE\\";
	GhepChuoi(s0, A.MSSV);
	GhepChuoi(s0, L".html");
	FILE* f = _wfopen(s0, L"wt");
	FILE* f1 = fopen("WEBSITE\\Template.html", "rt");
	if ((f != NULL) && (f1 != NULL))
	{
		_setmode(_fileno(f1), _O_U8TEXT);
		_setmode(_fileno(f), _O_U8TEXT);
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
		wchar_t s13[] = L"Khóa:";
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
				fwprintf(f, L"<div class=\"Personal_Department\">KHOA %ls</div>\n", A.Khoa);
				tieptuc = 0;
			}
			check = wcswcs(flag, s11);
			if ((check != NULL) && (tieptuc))
			{
				fwprintf(f, L"<span class=\"Personal_FullName\">%ls - %ls</span>\n",A.HVTen,A.MSSV);
				tieptuc = 0;
			}
			check = wcswcs(flag, s12);
			if ((check != NULL) && (tieptuc))
			{
				fwprintf(f, L"<title>HCMUS - %ls</title>\n", A.HVTen);
				tieptuc = 0;
			}
			check = wcswcs(flag, s13);
			if ((check != NULL) && (tieptuc))
			{
				fwprintf(f, L"<li>Khóa: %ls</li>\n", A.KhoaHoc);
				tieptuc = 0;
			}
			if (tieptuc) fwprintf(f, L"%ls\n", flag);
		}
		fclose(f);
		fclose(f1);
	}
}

void KiemTraNgoac(wchar_t* a)
{
	if ((*a == '\"') && (*(a + wcslen(a) - 1) == '\"'))
	{
		XoaNgoacKep(a);
	}
}

void SaoChepChuoi(wchar_t* a, wchar_t* b)
{
	for (int i = 0; i < wcslen(b); i++)
	{
		*(a + i) = *(b + i);
	}
	*(a + wcslen(b)) = '\0';
}

void GhepChuoiDauPhay(wchar_t* a, wchar_t* b)
{
	int flag = wcslen(a);
	*(a + flag) = ',';
	*(a + flag + 1) = '\0';
	flag = wcslen(a);
	for (int i = flag; i < flag + wcslen(b); i++)
	{
		*(a + i) = *(b + i - flag);
	}
	*(a + flag + wcslen(b)) = '\0';
}

void XoaNgoacKep(wchar_t* a)
{
	for (int i = 0; i < wcslen(a) - 1; i++)
	{
		*(a + i) = *(a + i + 1);
	}
	*(a + wcslen(a) - 2) = '\0';
}

void GhepChuoi(wchar_t* a,wchar_t* b)
{
	int flag = wcslen(a);
	for (int i = flag; i < flag + wcslen(b); i++)
	{
		*(a + i) = *(b + i - flag);
	}
	*(a + flag + wcslen(b)) = '\0';
}

void main()
{
	char s1[] = "Thongtinsinhvien1.csv";
	char s2[] = "Thongtinsinhvien2.csv";
	DocFILECSV(s1);
}