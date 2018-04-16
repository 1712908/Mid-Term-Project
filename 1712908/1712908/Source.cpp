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
	wchar_t* Motabanthan;
	wchar_t** Sothich;
};

void TaoHTML(SV&, int);

void DocFILECSV(FILE* &f)
{
	_setmode(_fileno(f), _O_U8TEXT);
	wchar_t** p = (wchar_t**)malloc(20 * sizeof(wchar_t*));
	int dem = 0;
	int demsothich;
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
			delete[]A.Sothich;
		}
	}
	for (int i = 0; i < dem; i++)
	{
		delete[] * (p + i);
	}
	delete[]p;
}

void TaoHTML(SV &A, int n)
{
	wchar_t s0[50] = L"WEBSITE\\";
	wchar_t s1[20];
	wcscpy(s1, A.MSSV);
	wcscat(s1, L".html");
	wcscat(s0, s1);
	FILE* f = _wfopen(s0, L"wt");
	_setmode(_fileno(f), _O_U8TEXT);
	if (f != NULL)
	{
		fwprintf(f, L"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
		fwprintf(f, L"<html xmlns=\"http://www.w3.org/1999/xhtml\">\n");
		fwprintf(f, L"<head>\n");
		fwprintf(f, L"<meta http-equiv = \"Content-Type\" content = \"text/html; charset=utf-8\" / >\n");
		fwprintf(f, L"<link rel = \"stylesheet\" type = \"text/css\" href = \"personal.css\" / >\n");
		fwprintf(f, L"<title>HCMUS - %ls</title>\n",A.HVTen);
		fwprintf(f, L"</head>\n");
		fwprintf(f, L"<body>\n");
		fwprintf(f, L"<div class = \"Layout_container\">\n");
		fwprintf(f, L"<!--Begin Layout Banner Region-->\n");
		fwprintf(f, L"<div class = \"Layout_Banner\" >\n");
		fwprintf(f, L"<div><img id = \"logo\" src = \"Images/logo.jpg\" height = \"105\" / ></div>\n");
		fwprintf(f, L"<div class = \"Header_Title\">TRƯỜNG ĐẠI HỌC KHOA HỌC TỰ NHIÊN </div>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"<!--End Layout Banner Region-->\n");
		fwprintf(f, L"<!--Begin Layout MainContents Region-->\n");
		fwprintf(f, L"<div class = \"Layout_MainContents\">\n");
		fwprintf(f, L"<!--Begin Below Banner Region-->\n");
		fwprintf(f, L"<div class = \"Personal_Main_Information\">\n");
		fwprintf(f, L"<!--Begin Thông tin cá nhân của thầy cô---------------------------------------------------------------------------------------- - -->\n");
		fwprintf(f, L"<div class = \"Personal_Location\">\n");
		fwprintf(f, L"<img src = \"Images/LogoFooter.jpg\" width = \"27\" height = \"33\" / >\n");
		fwprintf(f, L"<span class = \"Personal_FullName\">%ls - %ls</span>\n",A.HVTen,A.MSSV);
		fwprintf(f, L"<div class = \"Personal_Department\">%ls</div>\n",A.Khoa);
		fwprintf(f, L"<br />\n");
		fwprintf(f, L"<div class = \"Personal_Phone\">\n");
		fwprintf(f, L"Khóa : %ls\n",A.KhoaHoc);
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"<br />\n");
		fwprintf(f, L"<br />\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"<!--End Thông tin cá nhân của thầy cô---------------------------------------------------------------------------------------- - -->\n");
		fwprintf(f, L"<div class = \"Personal_HinhcanhanKhung\">\n");
		fwprintf(f, L"<img src = \"Images/%ls\" class = \"Personal_Hinhcanhan\" / >\n",A.Hinhanh);
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"<!--End Below Banner Region-->\n");
		fwprintf(f, L"<!--Begin MainContents Region-->\n");
		fwprintf(f, L"<div class = \"MainContain\">\n");
		fwprintf(f, L"\n");
		fwprintf(f, L"<!--Begin Top Region-->\n");
		fwprintf(f, L"<div class = \"MainContain_Top\">\n");
		fwprintf(f, L"\n");
		fwprintf(f, L"<div class = \"InfoGroup\">Thông tin cá nhân</div>\n");
		fwprintf(f, L"<div>\n");
		fwprintf(f, L"<ul class = \"TextInList\">\n");
		fwprintf(f, L"<li>Họ và tên : %ls</li>\n",A.HVTen);
		fwprintf(f, L"<li>MSSV : %ls</li>\n",A.MSSV);
		fwprintf(f, L"<li>Sinh viên khoa %ls</li>\n",A.Khoa);
		fwprintf(f, L"<li>Khóa : %ls</li>\n",A.KhoaHoc);
		fwprintf(f, L"<li>Ngày sinh : %ls</li>\n",A.NgaySinh);
		fwprintf(f, L"</ul>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"<div class = \"InfoGroup\">Sở thích</div>\n");
		fwprintf(f, L"<div>\n");
		fwprintf(f, L"<ul class = \"TextInList\">\n");
		for (int i = 0; i < n; i++)
		{
			fwprintf(f, L"	<li>%ls</li>\n", *(A.Sothich + i));
		}
		fwprintf(f, L"</ul>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"<div class = \"InfoGroup\">Mô tả</div>\n");
		fwprintf(f, L"<div class = \"Description\">\n");
		fwprintf(f, L"%ls\n",A.Motabanthan);
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"\n");
		fwprintf(f, L"<!--Begin Layout Footer-->\n");
		fwprintf(f, L"<div class = \"Layout_Footer\">\n");
		fwprintf(f, L"<div class = \"divCopyright\">\n");
		fwprintf(f, L"<br/>\n");
		fwprintf(f, L"<img src = \"Images/LogoFooter_gray.jpg\" width = \"34\" height = \"41\" / ><br/>\n");
		fwprintf(f, L"<br/>\n");
		fwprintf(f, L"@2018</br>\n");
		fwprintf(f, L"Đồ án giữ kỳ</br>\n");
		fwprintf(f, L"Kỹ thuật lập trình</br>\n");
		fwprintf(f, L"TH2018 / 03</br>\n");
		fwprintf(f, L"1712908 - Đặng Xuân Vinh</br>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"<!--End Layout Footer-->\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"</body>\n");
		fwprintf(f, L"</html>");
	}
	fclose(f);
}

void main()
{
	FILE* f1 = fopen("Thongtinsinhvien.csv", "rt");
	DocFILECSV(f1);
	fclose(f1);
}