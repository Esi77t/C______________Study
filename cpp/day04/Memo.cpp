#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

enum {
	WRITE = 1,
	READ,
	DELETE,
	EXIT
};

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

void deleteMemo() {
	ifstream file("memo.txt");

	if (!file) {
		cout << "삭제할 메모가 없습니다.";
		return;
	}

	vector<string> memos;
	string line;

	// 파일 전체 읽기
	while (getline(file, line)) {
		memos.push_back(line);
	}

	file.close();

	if (memos.empty()) {
		cout << "메모가 없습니다.";
		return;
	}

	// 목록 출력
	cout << "\n메모 출력\n";
	for (int i = 0; i < memos.size(); i++) {
		cout << i + 1 << ". " << memos[i] << endl;
	}

	// 삭제 번호 입력
	cout << "삭제 번호 입력 : ";
	int del;
	cin >> del;
	cin.ignore();

	if (del < 1 || del > memos.size()) {
		cout << "잘못된 입력입니다.";
		return;
	}

	// 벡터에서 제거
	memos.erase(memos.begin() + (del - 1));

	// 파일 다시쓰기
	ofstream out("memo.txt");

	for (string& memo : memos) {
		out << memo << endl;
	}

	out.close();

	cout << "삭제 완료";
}

void printMenu() {
	cout << "\n1. 메모 작성\n";
	cout << "2. 메모 보기\n";
	cout << "3. 메모 삭제\n";
	cout << "4. 종료\n";
	cout << "선택 : ";
}

int main() {
	while (true) {
		printMenu();

		int choice;
		cin >> choice;
		cin.ignore();

		switch (choice) {
		case WRITE:
			writeMemo();
			break;
		case READ:
			readMemo();
			break;
		case DELETE:
			deleteMemo();
			break;
		case EXIT:
			cout << "프로그램 종료\n";
			return 0;
		default:
			cout << "잘못된 입력입니다.\n";
		}
	}
}