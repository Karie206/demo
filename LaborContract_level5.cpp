#include <iostream>
#include <iomanip>              
#include <string>
#include <vector>
#include <conio.h>
#include <typeinfo>

using namespace std;

class CHopDong
{
	private:
		string maHD;
		string tenNguoiLaoDong;
		long long luongCanBan;
	public:
		CHopDong(string = " ", string = " ", long long = 0);
		CHopDong(const CHopDong&);
		~CHopDong() {};
		virtual void nhap();
		virtual void in();
		virtual long long luong() = 0;
		long long getLuongCanBan();
};

long long CHopDong::getLuongCanBan() 
{
	return luongCanBan; 
}

CHopDong::CHopDong(string maHD, string tenNguoiLaoDong, long long luongCanBan)
{
	this->maHD = maHD;
	this->tenNguoiLaoDong = tenNguoiLaoDong;
	this->luongCanBan = luongCanBan;
}

CHopDong::CHopDong(const CHopDong& temp)
{
	maHD = temp.maHD;
	tenNguoiLaoDong = temp.tenNguoiLaoDong;
	luongCanBan = temp.luongCanBan;
}

void CHopDong::nhap()
{
	cin.ignore();
	cout << "\n- Ma hop dong: "; 
	getline(cin, maHD);
	cout << "- Ten nguoi lao dong: "; 
	getline(cin, tenNguoiLaoDong);
	
	do
	{
		cout << "- Luong can ban: ";
		cin >> luongCanBan;
		
		if (luongCanBan <= 2500000)
			cout << "\n[!] Khong hop le! Luong toi thieu > 2,500,000VND...\n\n";

		cin.ignore();
		
	} while (luongCanBan <= 2500000);
}

void CHopDong::in()
{
    cout << setw(15) << "|| " + maHD;
    cout << setw(30) << "|| " + tenNguoiLaoDong;
    cout << "|| " << setw(15) << luongCanBan; 
}

//hop dong ngan han
class CHopDongNganHan : public CHopDong
{
	private: 
		int thoiHan;
	public:
		CHopDongNganHan(string = " ", string = " ", long long = 0, int = 0);
		CHopDongNganHan(const CHopDongNganHan&);
		~CHopDongNganHan() {};
		void nhap();
		void in();
		long long luong();
};

CHopDongNganHan::CHopDongNganHan(string maHD, string tenNguoiLaoDong, long long luongCanBan, int thoiHan)
: CHopDong(maHD, tenNguoiLaoDong, luongCanBan)
{
	this->thoiHan = thoiHan;
}

CHopDongNganHan::CHopDongNganHan(const CHopDongNganHan& temp)
: CHopDong(temp)
{
	thoiHan = temp.thoiHan;
}

void CHopDongNganHan::nhap()
{
	CHopDong::nhap();
	cout << "- Thoi han: ";
	cin >> thoiHan;
}

void CHopDongNganHan::in()
{
	CHopDong::in();
	cout << "|| " << setw(12) << thoiHan;
    cout << "|| " << setw(15) << luong();
    cout << "||";
}

long long CHopDongNganHan::luong()
{
	return getLuongCanBan();
}

//hop dong dai han
class CHopDongDaiHan : public CHopDong
{
	private:
		long long phuCap;
	public:
		CHopDongDaiHan(string = " ", string = " ", long long = 0, long long = 0);
		CHopDongDaiHan(const CHopDongDaiHan&);
		~CHopDongDaiHan() {};
		void nhap();
		void in();
		long long luong();
};

CHopDongDaiHan::CHopDongDaiHan(string maHD, string tenNguoiLaoDong, long long luongCanBan, long long phuCap)
: CHopDong(maHD, tenNguoiLaoDong, luongCanBan)
{
	this->phuCap = phuCap;
}

CHopDongDaiHan::CHopDongDaiHan(const CHopDongDaiHan& temp)
: CHopDong(temp)
{
	phuCap = temp.phuCap;
}

void CHopDongDaiHan::nhap()
{
	CHopDong::nhap();
	cout << "- Phu cap: ";
	cin >> phuCap;
}

void CHopDongDaiHan::in()
{
	CHopDong::in();
	cout << "|| " << setw(12) << phuCap;
	cout << "|| " << setw(15) << luong();
	cout << "||";
}

long long CHopDongDaiHan::luong()
{
	return getLuongCanBan() + phuCap;
}

//quan ly hop dong
class CQuanLyHopDong
{
	private:
		//int soLuongHD;
		//CHopDong* dsHopDong[1000];
		vector<CHopDong*> dsHopDong; 
	public:
		CQuanLyHopDong();
		~CQuanLyHopDong();
		void nhapDanhSachHD();
		void inDanhSachHD();
		void tinhTongTienLuong();
		void timHopDongLuongCaoNhat();
		void thucHienChuongTrinh();
		void thongKeSoLuongHD();
};

CQuanLyHopDong::~CQuanLyHopDong()
{
	for (int i = 0; i < dsHopDong.size(); i++)
	delete dsHopDong[i];
}

CQuanLyHopDong::CQuanLyHopDong()
{
	//soLuongHD = 0; 
}

void CQuanLyHopDong::nhapDanhSachHD()
{
	int luaChon;
	do
	{
		system("cls");
		cout << "\n+==================================+\n";
   	 	cout << "|      NHAP HOP DONG LAO DONG      |\n";
   	 	cout << "+==================================+\n";
    	cout << "| [1]: Them hop dong ngan han.     |\n";
    	cout << "| [2]: Them hop dong dai han.      |\n";
    	cout << "| [3]: Thoat.                      |\n";
    	cout << "+----------------------------------+\n";
    	cout << "[*] Lua chon cua ban: "; cin >> luaChon;
    	switch(luaChon)
    	{
    		case 1:
    		{
    			CHopDongNganHan* temp = new CHopDongNganHan();
    			temp->nhap();
    			dsHopDong.push_back(temp);
    			break;
    		}
    		case 2:
    		{
    			CHopDongDaiHan* temp = new CHopDongDaiHan();
    			temp->nhap();
    			dsHopDong.push_back(temp);
    			break;
			}
    		case 3:
    		{
    			cout << "\n[!] Thoat...";
				getch();
				break;
			}
			default:
				cout << "\n[!] Lua chon khong hop le, vui long nhap lai...";
				getch();
				break;
		}
	} while(luaChon != 3);
}

void CQuanLyHopDong::inDanhSachHD()
{
	cout << left;
    cout << "\n+================================================================================================+";
    cout << "\n|                                 DANH SACH HOP DONG NGAN HAN                                    |";
    cout << "\n+------------------------------------------------------------------------------------------------+";
    cout << endl;
	cout << setw(15) << "|| Ma HD ";
	cout << setw(30) << "|| Ten nguoi lao dong ";
	cout << setw(18) << "|| Luong can ban ";
	cout << setw(15) << "|| Thoi han ";
	cout << setw(18) << "|| Tong luong ";
	cout << "||" << endl;
	cout << setfill('-') << setw(98) << "-" << endl;
	cout << setfill(' ');
	
	for (int i = 0; i < dsHopDong.size(); i++)
	{
		if(typeid(*dsHopDong[i]) == typeid(CHopDongNganHan))
		{
			dsHopDong[i]->in();
			cout << endl;
		}
	}
	
	cout << endl;
    cout << "\n+================================================================================================+";
    cout << "\n|                                  DANH SACH HOP DONG DAI HAN                                    |";
    cout << "\n+------------------------------------------------------------------------------------------------+";
    cout << endl;
    cout << setw(15) << "|| Ma HD ";
    cout << setw(30) << "|| Ten nguoi lao dong ";
    cout << setw(18) << "|| Luong can ban ";
    cout << setw(15) << "|| Phu cap ";
    cout << setw(18) << "|| Tong luong ";
    cout << "||" << endl;
    cout << setfill('-') << setw(98) << "-" << endl;
    cout << setfill(' ');
    
    for (int i = 0; i < dsHopDong.size(); i++) 
	{
		if(typeid(*dsHopDong[i]) == typeid(CHopDongDaiHan))
		{
			dsHopDong[i]->in();
			cout << endl;
		}
    }
    
    cout << "\n[!] Bam phim bat ky de thoat...";
}

void CQuanLyHopDong::tinhTongTienLuong()
{
	long long tongLuongNH = 0;
	long long tongLuongDH = 0;
	
	for (int i = 0; i < dsHopDong.size(); i++)
	{
		if (typeid(*dsHopDong[i]) == typeid(CHopDongNganHan))
		{
			tongLuongNH += dsHopDong[i]->luong();
		}
		else if (typeid(*dsHopDong[i]) == typeid(CHopDongDaiHan))
		{
			tongLuongDH += dsHopDong[i]->luong();
		}
	}
	cout << "\n";
	cout << "- Tong tien luong hop dong ngan han: " << tongLuongNH << endl;
	cout << "- Tong tien luong hop dong dai han: " << tongLuongDH << endl;
	cout << "- Tong tien luong tat ca: " << tongLuongNH + tongLuongDH << endl;
	
	cout << "\n[!] Bam phim bat ky de thoat...";
}

void CQuanLyHopDong::timHopDongLuongCaoNhat()
{
	if (dsHopDong.size() == 0) 
	{
		cout << "\n[!] Danh sach hop dong dang rong...\n";
		cout << "\n[!] Bam phim bat ky de thoat...";
		return;
	}
	
	long long maxLuong = dsHopDong[0]->luong();
	int viTriMax = 0; 
	
	for (int i = 1; i < dsHopDong.size(); i++)
	{
		if (dsHopDong[i]->luong() > maxLuong)
		{
			maxLuong = dsHopDong[i]->luong();
			viTriMax = i; 
		}
	}
	
	cout << "\n+================================================================================================+";
	cout << "\n|                                 HOP DONG CO LUONG CAO NHAT                                     |";
	cout << "\n+------------------------------------------------------------------------------------------------+";
	cout << endl;
	
	if (typeid(*dsHopDong[viTriMax]) == typeid(CHopDongNganHan))
	{
		cout << left;
		cout << setw(15) << "|| Ma HD ";
		cout << setw(30) << "|| Ten nguoi lao dong ";
		cout << setw(18) << "|| Luong can ban ";
		cout << setw(15) << "|| Thoi han ";
		cout << setw(18) << "|| Tong luong ";
		cout << "||" << endl;	
	}
	else 
	{
		cout << left;
		cout << setw(15) << "|| Ma HD ";
		cout << setw(30) << "|| Ten nguoi lao dong ";
		cout << setw(18) << "|| Luong can ban ";
		cout << setw(15) << "|| Phu cap ";
		cout << setw(18) << "|| Tong luong ";
		cout << "||" << endl;
	}
	cout << setfill('-') << setw(98) << "-" << endl;
	cout << setfill(' ');
	
	dsHopDong[viTriMax]->in();
	cout << endl;
	cout << "\n[!] Bam phim bat ky de thoat...";
}

void CQuanLyHopDong::thongKeSoLuongHD()
{
	int soHDNH = 0;                                                                                                                                                                                                   
	int soHDDH = 0;
	
	for (int i = 0; i < dsHopDong.size(); i++)
	{
		if (typeid(*dsHopDong[i]) == typeid(CHopDongNganHan))
			soHDNH++;
			
		else if (typeid(*dsHopDong[i]) == typeid(CHopDongDaiHan))
			soHDDH++;
	}

	cout << "\n";
	cout << "- So luong hop dong ngan han: " << soHDNH << endl;
	cout << "- So luong hop dong dai han: " << soHDDH << endl;
	cout << "- Tong so luong hop dong: " << soHDNH + soHDDH << endl;
	
	cout << "\n[!] Bam phim bat ky de thoat...";
}

void CQuanLyHopDong::thucHienChuongTrinh()
{
	int luaChon;
	do
	{
		system("cls");
		cout << "\n+=======================================+\n";
    	cout << "|       QUAN LY HOP DONG LAO DONG       |\n";
    	cout << "+=======================================+\n";
    	cout << "| [1]: Nhap danh sach hop dong.         |\n";
    	cout << "| [2]: In danh sach hop dong.           |\n";
    	cout << "| [3]: Tinh tong tien luong.            |\n";
    	cout << "| [4]: Tim hop dong co luong cao nhat.  |\n";
    	cout << "| [5]: Thong ke so luong hop dong.      |\n";
    	cout << "| [6]: Thoat.                           |\n";
    	cout << "+---------------------------------------+\n";
    	cout << "[*] Lua chon cua ban: "; cin >> luaChon;
    	switch(luaChon)
    	{
    		case 1:
    		{
    			nhapDanhSachHD();
    			break;
			}
			case 2:
			{
				inDanhSachHD();
				getch();
				break;
			}
			case 3:
			{
				tinhTongTienLuong();
				getch();
				break;
			}
			case 4:
			{
				timHopDongLuongCaoNhat();
				getch();
				break;
			}
			case 5:
			{
				thongKeSoLuongHD();
				getch();
				break;
			}
			case 6:
			{
				cout << "\n[!] Cam on ban da su dung chuong trinh...";
				break;
			}
			default:
				cout << "\n[!] Lua chon khong hop le, vui long nhap lai...";
				getch();
				break;
		}
	} while (luaChon != 6);
}

int main ()
{
	CQuanLyHopDong qlHD;
	qlHD.thucHienChuongTrinh();
	
	return 0;
}
