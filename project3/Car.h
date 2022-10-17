
// khai bao giup cho trinh bien dich chi bien dich header mot lan duy nhat
#ifndef CAR_H
#define CAR_H

#include<iostream>
#include<fstream>
#include<string>
//size cua mang
#define SIZE 8
using namespace std;
class Car
{
public:
	//contructor and destructor none param
	Car();
	~Car();
	/*-----------speed-------------*/
	void speedUp();
	void speedReduce();
	// set speed in private class
	void setSpeed(int sp);
	// get speed in private class
	int getSpeed();
	void checkPass(int* arr);
	void inputPass();
	void outputPass();
	/*---------Sort------------------*/
	void swap(int& a, int& b);
	void selectionSort(int* a, int n, int& se);
	void bubbleSort(int* a, int n, int& bb);
	/*------------login-----------------*/
	void loadData();
	void outputDefault(int* a, int n);
	void inputSafeSpeed();
	void changeSafeSpeed();
	void changePass();
	void showMenu();
	void userControlSpeed(int gear);
	void menuCar(int gear);
	void speedWaring();
	void showControlSpeed();
	void ifNotInteger();
	bool isNumber(const string& str);
	//phần so sánh thuật toán
	int mangSe[8];
	int mangBb[8];
	void copyMang(int* a, int* b, int n);
	void printCopare(int se, int bb);
	void soSanhThuatToan();
private:
	// speed of CAR
	int speed;
	// PASS from user input
	int mscn[SIZE];
	// safe speed from user input
	int safe[3];
	int status = 0;
	//value compare thuật toán
	int se = 0, bb = 0;
};
#endif



