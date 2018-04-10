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
	f = fopen("1712908.csv", "rt");
	_setmode(_fileno(f), _O_U8TEXT);
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
	fclose(f);
}

void TaoHTML(FILE* f, SV A)
{
	wchar_t s0[50] = L"WEBSITE\\";
	wchar_t s1[20];
	wcscpy(s1, A.MSSV);
	wcscat(s1, L".html");
	wcscat(s0, s1);
	f = _wfopen(s0, L"wt");
	_setmode(_fileno(f), _O_U8TEXT);
	if (f != NULL)
	{
		fwprintf(f, L"<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">\n");
		fwprintf(f, L"<html xmlns=\"http://www.w3.org/1999/xhtml\">\n");
		fwprintf(f, L"<head>\n");
		fwprintf(f, L"<meta http-equiv = \"Content-Type\" content = \"text/html; charset=utf-8\" / >\n");
		fwprintf(f, L"<link rel = \"stylesheet\" type = \"text/css\" href = \"personal.css\" / >\n");
		fwprintf(f, L"<title>HCMUS - Nguyễn Văn A</title>\n");
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
		fwprintf(f, L"<!--Begin Thông tin cá nhân c ? a th ? y cô---------------------------------------------------------------------------------------- - -->\n");
		fwprintf(f, L"<div class = \"Personal_Location\">\n");
		fwprintf(f, L"<img src = \"Images/LogoFooter.jpg\" width = \"27\" height = \"33\" / >\n");
		fwprintf(f, L"<span class = \"Personal_FullName\">NGUYỄN VĂN A - 1212123</span>\n");
		fwprintf(f, L"<div class = \"Personal_Department\">KHOA CÔNG NGHỆ THÔNG TIN</div>\n");
		fwprintf(f, L"<br/>\n");
		fwprintf(f, L"<div class = \"Personal_Phone\">\n");
		fwprintf(f, L"Email: nva@gmail.com\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"<br/>\n");
		fwprintf(f, L"<br/>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"<!--End Thông tin cá nhân c ? a th ? y cô---------------------------------------------------------------------------------------- - -->\n");
		fwprintf(f, L"<div class = \"Personal_HinhcanhanKhung\">\n");
		fwprintf(f, L"<img src = \"Images/HinhCaNhan.jpg\" class = \"Personal_Hinhcanhan\" / >\n");
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
		fwprintf(f, L"<li>Họ và tên : Nguyễn Văn A</li>\n");
		fwprintf(f, L"<li>MSSV : 1212123</li>\n");
		fwprintf(f, L"<li>Sinh viên khoa Công nghệ thông tin</li>\n");
		fwprintf(f, L"<li>Ngày sinh : 20 / 01 / 1994</li>\n");
		fwprintf(f, L"<li>Email : nva@gmail.com</li>\n");
		fwprintf(f, L"</ul>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"<div class = \"InfoGroup\">Sở thích</div>\n");
		fwprintf(f, L"<div>\n");
		fwprintf(f, L"<ul class = \"TextInList\">\n");
		fwprintf(f, L"<li>Âm nhạc : POP, Balad</li>\n");
		fwprintf(f, L"<li>Ẩm thực : bún riêu, bún thịt nướng</li>\n");
		fwprintf(f, L"</ul>\n");
		fwprintf(f, L"</div>\n");
		fwprintf(f, L"<div class = \"InfoGroup\">Mô tả</div>\n");
		fwprintf(f, L"<div class = \"Description\">\n");
		fwprintf(f, L"Tôi là một người rất thân thiện.\n");
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
		fwprintf(f, L"@2013</br>\n");
		fwprintf(f, L"Đồ án giữ kỳ</br>\n");
		fwprintf(f, L"Kỹ thuật lập trình</br>\n");
		fwprintf(f, L"TH2012 / 03</br>\n");
		fwprintf(f, L"MSSV - Tên sinh viên thực hiện</br>\n");
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
	int n;
	FILE* f = NULL;
	FILE* f1 = NULL;
	SV A;
	//_setmode(_fileno(stdin), _O_U8TEXT);
	//_setmode(_fileno(stdout), _O_U8TEXT);
	DocFILECSV(f, A, n);
	TaoHTML(f1, A);
}