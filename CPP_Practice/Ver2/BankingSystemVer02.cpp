/*Account 클래스 정의, 객체 포인터 배열 적용*/

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
		cout << "계좌ID: " << accID << endl;
		cout << "이름: " << cusName << endl;
		cout << "잔액: " << balance << endl;
	}

	~Account() { delete []cusName; }
};

Account* accArr[100];
int accNum = 0;

int main(void) {
	int choice;

	while (1) {
		showMenu();
		cout << "선택 : ";
		cin >> choice; // 값 받기
		cout << endl; //한 줄 엔터용 (?)

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
			return 0;  //exit 안쓰고 이걸로 루프 빠져나갈 수 있나?
		default:
			cout << "~Illegal selection~" << endl << endl;
		}
	}

	return 0; //사실 리턴 0의 정확한 사용 이유를 모르겠어
}

void showMenu() {
	cout << "-----MENU-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void makeAccount() {
	int id, money;
	char name[NAME_LEN];
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";	cin >> id;
	cout << "이름: ";	cin >> name;
	cout << "입금액: ";	cin >> money;
	cout << endl;

	accArr[accNum++] = new Account(id, money, name);
}

void depositMoney() {
	int money, id;
	cout << "[입금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id) {
			accArr[i]->Deposit(money);
			cout << "입금 완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void withdrawMoney() {
	int money, id;
	cout << "[출금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "출금액: "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id) {
			if (accArr[i]->Withdraw(money) != 0) {
				cout << "출금 완료" << endl << endl;
			}
			else
				cout << "잔액 부족" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void showAllAccInfo() {
	for (int i = 0; i < accNum; i++) {
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}