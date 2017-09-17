#include <iostream>

using namespace std;

void showMenu();
void makeAccount();
void depositMoney();
void withdrawMoney();
void showAllAccInfo();

typedef struct {
	int accID;  //���¹�ȣ
	char custName[20];
	int balance; //�ܾ�
}Account;

Account accArr[100];
int accNum = 0;		//����� ������ ��... 

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
			cout << "~Illegal selection~" << endl;
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
	cout << "[���°���]" << endl;
	cout << "����ID: ";	cin >> accArr[accNum].accID;
	cout << "�̸�: ";	cin >> accArr[accNum].custName;
	cout << "�Աݾ�: ";	cin >> accArr[accNum].balance;
	cout << endl;

	accNum++;
}

void depositMoney() {
	int money, id;
	cout << "[�Ա�]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�Աݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == id) {
			accArr[i].balance += money;
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
		if (accArr[i].accID == id) {
			if (accArr[i].balance >= money) {
				accArr[i].balance -= money;
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
		cout << "����ID: " << accArr[i].accID << endl;
		cout << "�̸�: " << accArr[i].custName << endl;
		cout << "�ܾ�: " << accArr[i].balance << endl;
	}
}
