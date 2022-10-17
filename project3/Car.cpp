#include "Car.h"

bool Car::isNumber(const string& str)
{
	bool check = true;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (isdigit(str.at(i)) == false)
		{
			check = false;
		}
	}
	return check;
}
void Car::swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void Car::ifNotInteger()
{
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
	}
}
// contructor none param
Car::Car()
{
	this->speed = 0;
}
Car::~Car()
{

}
void Car::speedUp()
{
	this->speed += 5;
}
void Car::speedReduce()
{
	this->speed -= 5;
	if (this->speed < 5)
	{
		this->speed = 0;
	}
}
void Car::setSpeed(int sp)
{
	if (sp < 0)
	{
		cout << "VAN TOC DANG BANG 0 KM/H" << endl;
	}
	else
	{
		this->speed = sp;
	}
}
//function get Speed car
int Car::getSpeed()
{
	return this->speed;
}
// function check pass login
void Car::checkPass(int* arr)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (mscn[i] != arr[i])
		{
			cout << "MA SO KHONG GIONG NHAU" << endl;
			cout << " TAM BIET!!!!!" << endl;
			exit(0);
		}
	}
}
// user input PASS 
void Car::inputPass()
{
	cout << "NHAP MA SO CA NHAN, MANG 8 CHU SO" << '\n';
	for (int i = 0; i < SIZE; i++)
	{
		string str2 = "";
		do
		{
			cout << "SO THU " << i + 1 << ": ";
			//getline(cin, str2);
			cin >> str2;
		} while (isNumber(str2) == false || stoi(str2) < 0 || stoi(str2) > 9 || str2.length() != 1);
		this->mscn[i] = stoi(str2);
	}
}
void Car::outputPass()
{
	for (int i = 0; i < SIZE; i++)
	{

		cout << this->mscn[i] << " ";
	}
	cout << endl;
}
void Car::bubbleSort(int* a, int n, int& bb)
{
	bb = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (*(a + j) < *(a + i))
			{
				bb++;
				swap(*(a + j), *(a + i));
			}
		}
	}
}
void Car::selectionSort(int* a, int n, int& se)
{
	se = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (*(a + j) < *(a + min))
			{
				se++;
				min = j;
			}
		}
		swap(*(a + min), *(a + i));
	}
}
void Car::copyMang(int* a, int* b, int n)
{
	for (size_t i = 0; i < 8; i++)
	{
		a[i] = b[i];
	}
}
void Car::printCopare(int se, int bb)
{
	cout << "selectionSort: " << se << endl;
	cout << "bubbleSort: " << bb << endl;
}
void Car::soSanhThuatToan()
{
	cout << "SO SANH 2 THUAT TOAN: " << endl;
	int CompareArr[8] = { 1,4,5,7,2,4,8,9 };
	copyMang(mangSe, CompareArr, 8);
	copyMang(mangBb, CompareArr, 8);
	selectionSort(mangSe, 8, se);
	bubbleSort(mangBb, 8, bb);
	printCopare(se, bb);
	system("pause");
	system("cls");
}
// compare MSCN and defaultPass
void Car::loadData()
{
	//doc file ifstream 
	ifstream file_in, file_in2;
	file_in.open("AMS03.dat", ios::in | ios::binary);
	file_in2.open("safe_distance_speed.dat", ios::in | ios::binary);

	// check file.dat created yet? if created ===> open file.dat
	if (file_in.good() && file_in2.good())
	{
		// đọc xong read ở dưới thì đây với có giá trị mảng
		int mscn2[SIZE];
		file_in.read((char*)&mscn2, sizeof(mscn2));
		file_in2.read((char*)&safe, sizeof(safe));

		// DE NHAP MSCN
		this->inputPass();
		cout << "MANG NHAP VAO TRUOC KHI SAP XEP: ";
		this->outputDefault(mscn2, SIZE);
		this->bubbleSort(mscn2, SIZE, bb);
		cout << "=>MANG NHAP VAO SAU KHI SAP XEP: ";
		this->outputDefault(mscn2, SIZE);
		cout << "MA SO CA NHAN TRUOC KHI SAP XEP: ";
		//IN MẢNG mscn
		this->outputPass();
		this->selectionSort(mscn, SIZE, se);
		cout << "=>MA SO CA NHAN SAU KHI SAP XEP: ";
		this->outputPass();
		this->checkPass(mscn2);

		file_in.close();
		file_in2.close();
		system("pause");
		system("cls");
	}
	// first login!!! create new MSCN and check character is numeric character 
	else
	{
		cout << "KHOI TAO MA SO CA NHAN GOM" << SIZE << " SO:" << endl;
		inputPass();
		system("pause");
		system("cls");
		inputSafeSpeed();
		// ghi file ofstream - tao file
		//if file.dat not created or new create file.date
		ofstream file_out, file_out2;
		file_out.open("AMS03.dat", ios::out | ios::binary);
		file_out2.open("safe_distance_speed.dat", ios::out | ios::binary);
		file_out.write((char*)this->mscn, sizeof(mscn));
		file_out2.write((char*)this->safe, sizeof(safe));
		file_out.close();
		file_out2.close();
		system("pause");
		system("cls");
	}
}
// defaultPass appear in program
void Car::outputDefault(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(a + i) << " ";
	}
	cout << endl;
}
// input Safe speed in program
void Car::inputSafeSpeed()
{
	int count = 0;
	cout << "CAI DAT VAT TOC CANH BAO AN TOAN VOI 3 MUC VAN TOC:" << endl;
	for (int i = 0; i < 3; i++)
	{
		string str = "";
		do
		{
			cout << "VAN TOC MUC " << i + 1 << ": ";
			cin >> str;
			for (size_t i = 0; i < count; i++)
			{
				if (safe[i] == stoi(str))
				{
					cout << "VAN TOC MUC " << count + 1 << ": ";
					cin >> str;
				}
			}
			count++;
		} while (isNumber(str) == false || stoi(str) < 10 || stoi(str) > 99 || str.length() != 2);
		this->safe[i] = stoi(str);
	}
	//sắp xếp mảng
	bubbleSort(safe, 3, bb);
}
// make a choice Y/N change MSCN
void Car::changePass()
{
	string str = "";
	int replacePass = 0;

	do
	{
		cout << "BAN CO MUON CAI DAT LAI MA SO CA NHAN KHONG?" << endl;
		cout << " 1. YES" << endl;
		cout << " 2. NO" << endl;
		cin >> str;
		if (!isNumber(str) || str.length() > 2) {
			system("cls");
			continue;
		}
		replacePass = stoi(str);
		system("cls");
		// if gear = 1 => change PASS, if gear = 2 ==> next program
		switch (replacePass)
		{
		case 1:
		{
			inputPass();
			ofstream file_out2;
			file_out2.open("AMS03.dat", ios::out | ios::binary);
			file_out2.write((char*)this->mscn, sizeof(mscn));
			file_out2.close();
			break;
		}
		case 2:
			cout << "MA SO CA NHAN CUA BAN VAN DUOC GIU NGUYEN!!!" << endl;
			break;
		default:
			cout << "YEU CAU BAN NHAP 1 OR 2" << endl;
			break;
		}
	} while (replacePass != 1 && replacePass != 2);
}
// change safe speed
void Car::changeSafeSpeed()
{
	int replaceSpeed = 0;
	string str;
	do
	{
		cout << "BAN CO MUON CAI DAT LAI VAN TOC AN TOAN KHONG?" << endl;
		cout << " 1. YES" << endl;
		cout << " 2. NO" << endl;
		cin >> str;
		if (!isNumber(str) || str.length() > 2) {
			system("cls");
			continue;
		}
		replaceSpeed = stoi(str);
		system("cls");
		// if gear = 1 ==> change safe speed, gear = 2 not change!!!
		switch (replaceSpeed)
		{
		case 1:
		{
			inputSafeSpeed();
			ofstream file_out1;
			file_out1.open("safe_distance_speed.dat", ios::out | ios::binary);
			file_out1.write((char*)this->safe, sizeof(safe));
			file_out1.close();
			system("pause");
			system("cls");
			break;
		}
		case 2:
			cout << "BAN GIU NGUYEN VAN TOC AN TOAN" << endl;
			break;
		default:
			cout << "YEU CAU BAN NHAP 1 OR 2" << endl;
			break;
		}
	} while (replaceSpeed != 1 && replaceSpeed != 2);
}
// after login, user choose P D N R and POWER OFF
void Car::showMenu()
{
	// choice 1-2-3-4-5
	int gear;
	do
	{
		cout << "xin chao !!!" << '\n';
		cout << "xin moi lua chon: " << '\n';
		cout << "1. P" << '\n';
		cout << "2. R" << '\n';
		cout << "3. N" << '\n';
		cout << "4. D" << '\n';
		cout << "5. POWER OFF" << '\n';
		cin >> gear;
		ifNotInteger();
		system("cls");
		cout << "User chon: " << gear << '\n';
		menuCar(gear);

	} while (gear != 5);
}
// choice R P D N 
void Car::menuCar(int gear)
{

	int gear1;
	switch (gear)
	{
	case 1:
		// kiểm tra tốc độ trước khi về số P
		if (getSpeed() <= 0)
		{
			cout << "DA VE SO P." << '\n';
			cout << "CHU Y DUNG PHANH TAY DE DAM BAO AN TOAN" << '\n';
		}
		else
		{
			cout << "HAY CHAC CHAN XE DA DUNG, VA VAN TOC LA 0 KM/H" << endl;
		}
		break;
	case 2:
		// kiểm tra tốc độ = 0, để được phép vào số R hoặc D
		if (status != 2 && getSpeed() != 0)
		{
			cout << "KIEM TRA LAI VAN TOC, XE VAN DANG CHAY" << endl;
			return;
		}
		// khi vận tốc bằng 0 giá trị mặc định khi vào số bằng 7
		if (getSpeed() <= 0)
			setSpeed(7);
		status = 2;
		do
		{
			showControlSpeed();
			cin >> gear1;
			ifNotInteger();
			system("cls");
			cout << "user chon: " << gear1 << endl;
			userControlSpeed(gear1);
			if (getSpeed() > 20)
			{
				cout << "TOC DO NGUY HIEM, BAN NEN GIAM TOC DO" << endl;
			}
		} while (gear1 != 4);
		break;
	case 3:
		// kiểm tra tốc độ trước khi về số P
		if (getSpeed() <= 0)
		{
			cout << "DA VE SO N." << '\n';
			cout << "CHU Y DUNG PHANH TAY DE DAM BAO AN TOAN" << '\n';
		}
		else
		{
			cout << "HAY CHAC CHAN XE DA DUNG, VA VAN TOC LA 0 KM/H" << endl;
		}
		break;
	case 4:
		// kiểm tra tốc độ = 0, để được phép vào số R hoặc D
		if (status != 4 && getSpeed() != 0)
		{
			cout << "KIEM TRA LAI VAN TOC, XE VAN DANG CHAY" << endl;
			return;
		}
		// khi vận tốc bằng 0 giá trị mặc định khi vào số bằng 7
		if (getSpeed() <= 0)
			setSpeed(7);
		status = 4;
		do
		{
			showControlSpeed();
			cin >> gear1;
			ifNotInteger();
			system("cls");
			cout << "user chon" << gear1 << endl;
			userControlSpeed(gear1);
			if (getSpeed() > 60)
			{
				cout << "TOC DO NGUY HIEM, BAN NEN GIAM TOC DO" << endl;
			}
		} while (gear1 != 4);
		break;
	case 5:
		cout << " XE DA TAT MAY!!!" << endl;
		break;
	default:
		cout << " KHONG CO DU LIEU" << endl;
		break;
	}
}
// control SPEED car
void Car::userControlSpeed(int gear)
{
	switch (gear)
	{
	case 1:			// speed up
		cout << "TANG TOC" << endl;
		speedUp();
		speedWaring();
		break;
	case 2:			// speed reduce
		cout << "GIAM TOC" << endl;
		speedReduce();
		speedWaring();
		break;
	case 3:   // speed = 0 stop
		cout << "PHANH" << endl;
		setSpeed(0);
		break;
	case 4:		//	return showMenu
		cout << "TRO VE" << endl;
		break;
	default:
		cout << "NHAP SAI CU PHAP" << endl;
		break;
	}
}
void Car::speedWaring()
{

	if (speed < safe[0])
	{
		cout << "!!!!CHU Y PHAI GIU KHOANG CACH TOI THIEU 20M!!!!" << '\n';
	}
	if (speed >= safe[0] && speed < safe[1])
	{
		cout << "!!!!CHU Y KHOANG CACH AN TOAN TOI THIEU LA 55M!!!!" << '\n';
	}
	if (speed >= safe[1] && speed < safe[2])
	{
		cout << "!!!!CHU Y KHOANG CACH AN TOAN TOI THIEU LA 70M!!!!" << '\n';
	}
	if (speed >= safe[2])
	{
		cout << "!!!!CHU Y KHOANG CACH AN TOAN TOI THIEU LA 100M!!!!" << '\n';
	}
}
void Car::showControlSpeed()
{
	cout << "------ TOC DO HIEN TAI:" << speed << "km/h" << '\n';
	cout << "MOI LUA CHON: " << '\n';
	cout << "1: TANG TOC" << '\n';
	cout << "2: GIAM TOC" << '\n';
	cout << "3: PHANH" << '\n';
	cout << "4: TRO VE" << '\n';
}


