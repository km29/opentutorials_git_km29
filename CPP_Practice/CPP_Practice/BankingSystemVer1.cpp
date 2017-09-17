#include <iostream>

using namespace std;

void showMenu();
void makeAccount();
void depositMoney();
void withdrawMoney();
void showAllAccInfo();

typedef struct {
	int accID;  //계좌번호
	char custName[20];
	int balance; //잔액
}Account;

Account accArr[100];
int accNum = 0;		//저장된 계좌의 수... 

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
			cout << "~Illegal selection~" << endl;
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
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";	cin >> accArr[accNum].accID;
	cout << "이름: ";	cin >> accArr[accNum].custName;
	cout << "입금액: ";	cin >> accArr[accNum].balance;
	cout << endl;

	accNum++;
}

void depositMoney() {
	int money, id;
	cout << "[입금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == id) {
			accArr[i].balance += money;
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
		if (accArr[i].accID == id) {
			if (accArr[i].balance >= money) {
				accArr[i].balance -= money;
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
		cout << "계좌ID: " << accArr[i].accID << endl;
		cout << "이름: " << accArr[i].custName << endl;
		cout << "잔액: " << accArr[i].balance << endl;
	}
}
