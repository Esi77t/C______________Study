#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writeMemo() {
	// ofstream : 파일 출력
	// ios::app : 기존 내용 유지
	ofstream file("memo.txt", ios::app);	// 이어쓰기

	if (!file) {
		cout << "파일 열기 실패\n";
		return;
	}

	cout << "메모 내용을 입력하세요.";

	// string + getline : 공백 입력 가능
	string memo;
	getline(cin, memo);

	file << memo << endl;
	file.close();

	cout << "메모가 저장되었습니다.";
}

void readMemo() {
	ifstream file("memo.txt");		// ifstream : 파일 입력

	if (!file) {
		cout << "저장된 메모가 없습니다.";
		return;
	}

	string line;
	cout << "\n[메모 내용]\n";

	while (getline(file, line)) {
		cout << "- " << line << endl;
	}

	file.close();
}

int main() {
	while (true) {
		cout << "\n1. 메모작성 \n2. 메모보기 \n3. 종료\n. 선택 : ";

		int choice;

		cin >> choice;
		cin.ignore();	// 개행 제거

		if (choice == 1) {
			writeMemo();
		}
		else if (choice == 2) {
			readMemo();
		}
		else if (choice == 3) {
			cout << "프로그램 종류\n";
			break;
		}
		else {
			cout << "잘못된 입력입니다.";
		}
	}
}