#pragma once
#include <iostream>
#include<string>
#include"LinkedListSequence.h"
using namespace std;
class Menu
{
public:
	Menu(string name, LinkedListSequence<string>* options, LinkedListSequence<Menu>* menus) :
		Name(name),
		Menus(menus) {
		Options = new LinkedListSequence<string>(options);
		CountOfOptions = Options->GetLength();
	}
	~Menu() {
		if (!Menus) {
			Menus->~LinkedListSequence();
		}
		if (!Options) {
			Options->~LinkedListSequence();
		}
	}
	void Show() {
		cout << "\t\t" << "Выберите один из пунктов меню, при вводе нуля вы попадёте в предыдущее меню\n\n";
		cout << "\t\t" << Name << "\n";
		for (size_t i = 0; i < CountOfOptions; i++) {
			string option = *(Options->Get(i));
			cout << i + 1 << ")\t" << option << "\n";
		}
		userCurrentPrint = 0;
		do
		{
			cin >> userCurrentPrint;
		} while ((userCurrentPrint < 0) || (userCurrentPrint > CountOfOptions));
		Refresh();
		if (userCurrentPrint == 0) {
			return;
		}
		Menus->Get(userCurrentPrint)->Show();
	}
	void Refresh() {
		system("cls");
	}
	int GetCountOfOptions() {
		CountOfOptions = Options->GetLength();
		return CountOfOptions;
	}
private:
	LinkedListSequence<Menu>* Menus = nullptr;
	LinkedListSequence<string>* Options = nullptr;
	int CountOfOptions = 0;
	int userCurrentPrint = -1;
	string Name = "";
	void (*SetCurrentMenu)(Menu*) = nullptr;
};

class ConsoleInterface
{
public:
	ConsoleInterface(Menu* menu):
		Menu(menu) {
		setlocale(LC_ALL, "Rus");
	}
	~ConsoleInterface() {};
	void Show() {
		Menu->Show();
		Refresh();
	}
	void Refresh() {
		system("cls");
		if (!Menu) {
			this->~ConsoleInterface();
		}
	}
	void SetCurrentMenu(Menu* newCurrentMenu) {
		Menu = newCurrentMenu;
	}
private:
	Menu* Menu = nullptr;
protected:
};