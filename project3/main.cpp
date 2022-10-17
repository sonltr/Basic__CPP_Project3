
#include"Car.h"
using namespace std;

int main()
{
 	Car car;
	// Login and setSpeed
	car.loadData();
	// compare thuật toán
	car.soSanhThuatToan();
	// make a choice Y/N change MSCN
	car.changePass();
	// make a choice Y/N change safe speed
	car.changeSafeSpeed();
	// after login, user choose P D N R and POWER OFF
	car.showMenu();
	system("pause");
	return 0;
}
