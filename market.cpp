#ifndef market_h
#define market_h
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
struct Product
{
	char Productname[50];
	float Unitprice;
	int Quantity;
	float Totalprice;
};
struct Shop
{
	char ShopName[50];
	char Address[50];
};
struct Customer
{
	char CustomerName[50];
	char Phonenumber[50];
};
struct Person
{
	Shop shop;
	Customer customer;
	Product product;
};
void FillShoppinginfo(Person* person)
{
	cout << "Shop Name: "; cin.getline(person->shop.ShopName, 50);
	cout << "Shop Address: "; cin.getline(person->shop.Address, 50);
	cout << "Customer Name: "; cin.getline(person->customer.CustomerName, 50);
	cout << "Customer Number: "; cin >> person->customer.Phonenumber;
	cin.ignore();
	cout << "Product Name: "; cin.getline(person->product.Productname, 50);
	cout << "Unit Price: "; cin >> person->product.Unitprice;
	cout << "Quantity Ordered: "; cin >> person->product.Quantity;
	cin.ignore();
}
void WriteReceipt(Person person)
{
	ofstream Textfile;
	Textfile.open("WriteReceipt.txt");
	person.product.Totalprice = person.product.Unitprice * person.product.Quantity;
	Textfile << "******************************************************************************\n";
	Textfile << setw(20 + strlen(person.shop.ShopName) / 2) << person.shop.ShopName <<
	endl;
	Textfile << setw(20 + strlen(person.shop.Address) / 2) << person.shop.Address << endl
	<< endl;
	Textfile << "Customer\t" << person.customer.CustomerName;
	Textfile << "\nPhone Number\t" << person.customer.Phonenumber;
	Textfile << "\n\nYour Order\n\n";
	Textfile << "Product Name" << setw(14) << "Unit Price" << setw(19) << "Quantity Ordered\n";
	Textfile << "Chocolate" << setw(9) << person.product.Unitprice << setw(11) <<
	person.product.Quantity << endl;
	Textfile << setw(35) << "*******" << endl;
	Textfile << setw(27) << "Total Price" << setw(4) << person.product.Totalprice << endl;
	Textfile << setw(35) << "*******";
	Textfile << "\n\tThanks for your Patronage";
	Textfile << "\n******************************************************************************";
	Textfile.close();
	}
#endif

#include "market.h"
void FillShoppinginfo(Person* person);
void WriteReceipt(Person person);
int main()
{
Person person;
FillShoppinginfo(&person);
WriteReceipt(person);
return 0;
}