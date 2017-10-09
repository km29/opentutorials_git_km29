/*Account Ŭ���� ����, ��ü ������ �迭 ����*/

#include <iostream>
#include <cstring>

#define NAME_LEN 20

using namespace std;

void showMenu();
void makeAccount();
void depositMoney();
void withdrawMoney();
void showAllAccInfo();

class Account {
private:
	int accID;
	int balance;
	char* cusName;

public:
	Account(int ID, int money, char* name): accID(ID), balance(money) {
		cusName = new char[strlen(name) + 1];
		strcpy(cusName, name);
	}

	int GetAccID() { return accID; }

	void Deposit(int money) {
		balance += money;
	}

	int Withdraw(int money) {
		if (balance < money)
			return 0;

		balance -= money;
		return money;
	}

	void ShowAccInfo() {
		cout << "����ID: " << accID << endl;
		cout << "�̸�: " << cusName << endl;
		cout << "�ܾ�: " << balance << endl;
	}

	~Account() { delete []cusName; }
};

Account* accArr[100];
int accNum = 0;

int main(void) {
	int choice;

	while (1) {
		showMenu();
		cout << "���� : ";
		cin >> choice; // �� �ޱ�
		cout << endl; //�� �� ���Ϳ� (?)

		switch (choice) {
		case 1:
			makeAccount();
			break;
		case 2:
			depositMoney();
			break;
		case 3:
			withdrawMoney();
			break;
		case 4:
			showAllAccInfo();
			break;
		case 5:
			return 0;  //exit �Ⱦ��� �̰ɷ� ���� �������� �� �ֳ�?
		default:
			cout << "~Illegal selection~" << endl << endl;
		}
	}

	return 0; //��� ���� 0�� ��Ȯ�� ��� ������ �𸣰ھ�
}

void showMenu() {
	cout << "-----MENU-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void makeAccount() {
	int id, money;
	char name[NAME_LEN];
	cout << "[���°���]" << endl;
	cout << "����ID: ";	cin >> id;
	cout << "�̸�: ";	cin >> name;
	cout << "�Աݾ�: ";	cin >> money;
	cout << endl;

	accArr[accNum++] = new Account(id, money, name);
}

void depositMoney() {
	int money, id;
	cout << "[�Ա�]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�Աݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id) {
			accArr[i]->Deposit(money);
			cout << "�Ա� �Ϸ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}

void withdrawMoney() {
	int money, id;
	cout << "[���]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "��ݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id) {
			if (accArr[i]->Withdraw(money) != 0) {
				cout << "��� �Ϸ�" << endl << endl;
			}
			else
				cout << "�ܾ� ����" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}

void showAllAccInfo() {
	for (int i = 0; i < accNum; i++) {
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}