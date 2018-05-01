/* 처음 작성일  : 2017.09.10   최종 수정일 : 2017.10.31
작성자 : 김민영                     프로그램 : 캔디 팝팝팝  */
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<Windows.h>
#include<fstream>
#include<string>
#include<thread>
#pragma comment(lib, "winmm.lib")
#include "Mmsystem.h"
#include "Digitalv.h"
MCI_OPEN_PARMS m_mciOpenParms;
MCI_PLAY_PARMS m_mciPlayParms;
DWORD m_dwDeviceID;
MCI_OPEN_PARMS mciOpen;
MCI_PLAY_PARMS mciPlay;
int dwID, dwPA; // 게임 음악 넣을
int score = 0; // 점수
int bumb = 3; // 폭탄 개수
int flag = 0; // 스테이지 확인
using namespace std;
void gotoxy(int, int);
void playMusicOne(){ // 첫 번째 메인 음악
	mciOpen.lpstrElementName = "candy.mp3"; // 파일 경로 입력
	mciOpen.lpstrDeviceType = "mpegvideo";

	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&mciOpen);

	dwID = mciOpen.wDeviceID;

	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, // play & repeat
		(DWORD)(LPVOID)&m_mciPlayParms);
}
void playMusicTwo(){ // 게임 실행 시 음악
	mciSendCommandW(dwID, MCI_CLOSE, 0, NULL);
	mciOpen.lpstrElementName = "start.mp3"; // 파일 경로 입력
	mciOpen.lpstrDeviceType = "mpegvideo";

	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&mciOpen);

	dwPA = mciOpen.wDeviceID;

	mciSendCommand(dwPA, MCI_PLAY, MCI_DGV_PLAY_REPEAT, // play & repeat
		(DWORD)(LPVOID)&m_mciPlayParms);
}
int main(){
	playMusicOne();
	system("mode con:cols=100 lines=31");
	system("title candy pop,pop,pop!");
	//system("color 70");
	void start();
	void menu(); void game_start(); void game_method(); void game_record();
	// 메인 첫 시작화면
	start();
	// 메뉴 선택 화면
	menu();
	return 0;
}
void start(){ // 시작 화면
	gotoxy(90, 1);
	printf("2202 김민영\n");
	system("color 3F");
	cout << endl << endl << endl;
	cout << "                     ■■■   ■   ■■■ ■■■ ■ ■    ■■■ ■■■ ■■■" << endl;
	cout << "                     ■     ■  ■ ■  ■ ■  ■ ■ ■    ■  ■ ■■■ ■  ■" << endl;
	cout << "                     ■     ■■■ ■  ■ ■  ■  ■      ■■■ ■■■ ■■■" << endl;
	cout << "                     ■■■ ■  ■ ■  ■ ■■■  ■      ■     ■■■ ■    ";
	gotoxy(38, 15);
	cout << "아무키나 누르면 시작합니다." << endl;
	cout << endl << endl << endl << endl;
	cout << "                                  ■■■                   ■■■          " << endl;
	cout << "                     ■■■      ■    ■      ■■■     ■    ■     ■■" << endl;
	cout << "                    ■    ■     ■    ■     ■    ■    ■    ■     ■■" << endl;
	cout << "                    ■    ■      ■■■      ■    ■     ■■■      ■■" << endl;
	cout << "                     ■■■         ■         ■■■        ■        ■■" << endl;
	cout << "                       ■           ■           ■          ■             " << endl;
	cout << "                       ■           ■           ■          ■         ■" << endl;
	cout << "                       ■           ■           ■          ■         ■";
	_getch();
}
void menu(){ // 메뉴 선택 화면
	mciSendCommandW(dwPA, MCI_CLOSE, 0, NULL);
	playMusicOne();
	system("cls");
	void game_start(); void game_method(); void game_record(); void draw_square(); void user_input(); void buy_bumb(); void finish(); void timer(int);// 함수 프로토타입
	int num = 0;
	gotoxy(90, 1);
	cout << "2202 김민영" << endl;
	cout << "                                                                              " << endl;
	cout << "                                                                              " << endl;
	cout << "                                                                              " << endl;
	cout << "                                  1. 게임 방법" << endl << endl;
	cout << "                                  2. 게임 시작" << endl << endl;
	cout << "                                  3. 종료" << endl << endl;
	cout << "                                  4. 기록" << endl << endl;
	cout << "                                  5. 상점" << endl << endl;
	cout << "                                 ☞ 1에서 5까지 메뉴를 고르세요 : ";
	cin >> num; // 메뉴선택
	if (num > 5 || num < 1){
		gotoxy(37, 17);
		cout << "1에서 5사이의 수로 입력하세요!!!";
		Sleep(1000);
		return menu();
	}
	switch (num){
	case 1:{
			   game_method(); // 게임방법
			   break; }
	case 2:{
			   user_input();
			   game_start();
			   break; }
	case 3:{
			   finish();
			   exit(0);
	}
	case 4:
		game_record(); // 게임기록
		break;
	case 5:
		buy_bumb(); // 상점
		break;
	}

}
void new_money(int *money){
	int mo;
	cout << "얼마를 충전하시겠습니까?(100~1000코인) : ";
	cin >> mo;
	cout << "충전이 완료되었습니다. ";
	*money += mo;
}
int money = 1000;
void buy_bumb(){
	void new_money(int*);
	int count;
	char check, money_check;
	gotoxy(90, 1);
	cout << "2202 김민영" << endl;

	system("cls");
	gotoxy(33, 3);
	cout << "※ CANDY POP! POP! POP!의 상점입니다 ※" << endl;
	gotoxy(80, 4);
	cout << "현재 코인 : " << money;
	gotoxy(33, 5);
	cout << "현재는 폭탄만 추가 구입가능합니다!" << endl;
	gotoxy(20, 6);
	cout << "폭탄을 구입하시고 싶으시면 Y/y를, 메뉴로 가실 시 N/n을 눌러주세요 : ";
	cin >> check;
	if (check == 'Y' || check == 'y'){
		gotoxy(27, 7);
		cout << "폭탄을 몇 개 구입하시겠습니까? (하나에 200코인) : ";
		cin >> count;
		if (money - (count * 200) <= 0){
			gotoxy(13, 8);
			cout << "머니가 부족합니다. 머니를 충전하시려면 Y/y를, 그만하시려면 N/n을 눌러주세요 : ";
			cin >> money_check;
			if (money_check == 'Y' || money_check == 'y'){
				new_money(&money);
				return buy_bumb();
			}
			else{
				gotoxy(30, 9);
				cout << "   아무키나 누르면 메뉴로 돌아갑니다.";
				if (_getch()){
					system("cls");
					return menu();
				}
			}
		}
		else{
			bumb += count;
			money -= (200 * count);
			gotoxy(40, 9);
			cout << "폭탄 " << count << "개 구매하였습니다.";
			gotoxy(30, 11);
			cout << "   아무키나 누르면 메뉴로 돌아갑니다.";
			if (_getch()){
				system("cls");
				return menu();
			}
		}
	}
	else{
		gotoxy(30, 10);
		cout << "   아무키나 누르면 메뉴로 돌아갑니다.";
		if (_getch()){
			system("cls");
			return menu();
		}
	}
}
void game_method(){ // 게임 방법 설명
	system("cls");
	gotoxy(90, 1);
	printf("2202 김민영\n");
	cout << "   ▶ CANDY POP POP POP 게임 방법 ◀\n\n";
	cout << "1. 4행 4열의 표가 주어지고, 3개의 모양을 띈 도형이 나온다.\n\n";
	cout << "   무작위로 배치된 도형을 같은 모양으로 한 줄이 같도록 만드면\n\n";
	cout << "   각 색깔에 맞는 점수가 누적된다.\n\n";
	cout << "   바꾸고 싶은 두 수를 물어보면 교체할 두 수를 쓴다.\n\n";
	cout << "   (두 수는 바로 밑의 수 또는 옆의 수와만 바꿀 수 있다.)\n\n";
	cout << "   참고로 수는 왼쪽부터 1번이고 총 16 까지의 수가 있다.\n\n";
	cout << "   즉 첫째 줄은 1 2 3 4 둘째 줄은 5 6 7 8과 같다.\n\n\n";
	cout << "2. STAGE 1에서 1200 SCORE를 얻을 시 다음 스테이지로 넘어가게 된다.\n\n";
	cout << "   점수 획득은 다음과 같다.\n\n";
	cout << "   별   사탕 ★  =>  + 100\n\n";
	cout << "   하트 사탕 ♡  =>  + 200\n\n";
	cout << "   반쪽 사탕 ◐  =>  + 300\n\n";
	cout << "   Bumb     100  =>  + 400\n\n\n\n";
	cout << "   아무키나 누르면 메뉴로 돌아갑니다.";
	if (_getch()){
		system("cls");
		menu();
	}
}
void game_start(){ // 게임 시작 함수
	playMusicTwo();
	int i = 1;
	int stage[2] = { 1200, 2300 }; // 스테이지 별 점수 1200,2300
	void game_random(int *); void game_check(int *); void first_stage(); void second_stage(); void last_stage(); void game_over(); int number_check(int, int); void square_method(); void bumb_change(int*, int*); void menu_change(); void wait(int);// 함수 프로토타입
	clock_t sta, end;// 시작시간, 끝시간
	int can[16], change, that, temp; // 난수 발생
	double g_time = 100;
	char candy[16][4]; // 모양 넣어놓을
	system("cls");
	// 게임 시작
	srand((unsigned)time(NULL));
	gotoxy(90, 1);
	cout << "2202 김민영" << endl;
	gotoxy(90, 3);
	cout << "폭탄 : " << bumb << "개";
	gotoxy(89, 4);
	cout << "SCORE : " << score << endl;
	gotoxy(25, 3);
	cout << "남은 시간 : " << g_time - clock() / 1000 << "초";
	game_random(&can[0]);
	while (true){
		game_check(&can[0]);
		gotoxy(25, 3);
		cout << "남은 시간 : " << g_time - clock() / 1000 << "초";
		if (g_time - clock() / 1000 <= 0){
			game_over();
		}
		if (score >= stage[0] && flag == 0){ // 점수가 1200 이상
			system("cls");
			first_stage();
			flag = 1;
			g_time = 90;
			system("color 0E");
		}
		if (score >= stage[1] && flag == 1){ // 점수가 2300 이상
			system("cls");
			second_stage();
			flag = 2;
			g_time = 80;
			system("color 71");
		}
		game_check(&can[0]); // 같은 숫자 체크
		cout << "                 ";
		gotoxy(90, 1);
		cout << "2202 김민영" << endl;
		gotoxy(90, 3);
		cout << "폭탄 : " << bumb << "개";
		gotoxy(89, 4);
		cout << "SCORE : " << score << endl;


		square_method(); // 옆에 띄우는 간단한 화면

		for (int i = 0; i < 16; i++){ // 숫자를 캔디로 바꾸기
			switch (can[i]){
			case 1: strcpy_s(candy[i], "★"); break;
			case 2: strcpy_s(candy[i], "♡"); break;
			case 3: strcpy_s(candy[i], "◐"); break;
			}
		}
		gotoxy(7, 2);
		for (int i = 0; i < 16; i++){ // 모양 찍기
			if (i % 4 == 0){
				cout << endl << endl << endl << endl;
				cout << "            ";
			}
			cout << candy[i] << "           ";
		}
		// 바꿀 숫자 입력받기
		gotoxy(15, 22);
		cout << "어디를 바꾸시겠어요 ? (ENTER) : ";
		cin >> change;
		if (change == 200){
			menu_change();
			Sleep(1000);
			return menu();
		}
		if (change == 100){ // * 누르면 폭탄 실행
			if (bumb != 0){
				bumb_change(&bumb, &score);
				Sleep(1000);
			}
			else{
				gotoxy(18, 24);
				cout << "폭탄의 개수가 부족합니다!" << endl;
				Sleep(700);
				return game_start();
			}
		}
		else{
			cout << "                                    ";
			gotoxy(15, 22);
			cout << "어디와 바꾸시겠어요 ? (ENTER) : " << change << " -> ";
			cin >> that;

			int result = number_check(change, that); // 양옆 위아래 숫자인지 확인
			// 바꾼 숫자 바꾸기
			if (result == 1){ // 양옆 위아래 숫자이면
				temp = can[change - 1];
				can[change - 1] = can[that - 1];
				can[that - 1] = temp;
			}
			else if (result == 0 || result == 2){ // 다른 숫자일경우
				gotoxy(17, 24);
				cout << "교환은 양옆 위 아래만 가능합니다!" << endl;
				Sleep(500);
			}
		}
		gotoxy(25, 5);
		system("cls");
	}
};
int number_check(int change, int that){ //바꿀 수가 양옆 위아래 수인지 확인하는 함수
	int temp;
	if (that == (change + 4) || that == (change + 1) || that == (change - 1) || that == (change - 4)){
		temp = 1;
	}
	else{
		temp = 0;
	}
	if (change % 4 == 0 && that == (change + 1)){
		temp = 2;
	}
	return temp;
}
void game_record(){ // 기록 확인
	int i = 9;
	system("cls");
	gotoxy(90, 1);
	cout << "2202 김민영" << endl;
	gotoxy(37, 5);
	cout << "※ 닉네임과 기록확인하세요 ※" << endl;
	gotoxy(41, 7);
	cout << "닉네임";
	gotoxy(55, 7);
	cout << "기록";
	ifstream input("nickname_record.txt");
	if (input.fail()){
		cout << "파일을 여는 데 실패했습니다." << endl;
	}

	string line;

	while (!input.eof()){
		getline(input, line);
		gotoxy(42, i);
		cout << line << endl;
		getline(input, line);
		gotoxy(55, i);
		cout << line << endl;
		i++;
	}
	input.close();
	gotoxy(32, 2);
	cout << "아무키나 누르시면 메뉴로 다시 이동합니다. ";
	if (_getch()){
		system("cls");
		menu();
	}
	cout << endl << endl << endl;
	system("pause>null");
}
void menu_change(){ // 메뉴로 돌아갈 때 이용하는 함수
	gotoxy(90, 1);
	cout << "2202 김민영" << endl;
	system("cls");
	gotoxy(30, 8);
	cout << "■■■  ■■■      ■■■    ■    ■■■  ■  ■";
	gotoxy(30, 9);
	cout << "■      ■  ■      ■  ■  ■  ■  ■      ■■";
	gotoxy(30, 10);
	cout << "■■■  ■  ■      ■■■  ■■■  ■      ■";
	gotoxy(30, 11);
	cout << "■  ■  ■  ■      ■  ■  ■  ■  ■      ■■";
	gotoxy(30, 12);
	cout << "■■■  ■■■      ■■■  ■  ■  ■■■  ■  ■";
	gotoxy(40, 15);
	cout << "메뉴로 돌아갑니다!!!";
	ofstream output("nickname_record.txt", ios::app);
	output << score << endl;
	output.close();

}
void bumb_change(int *bumb, int *score){ // 폭탄 실행 함수
	PlaySound("bumb.wav", NULL, SND_ASYNC);
	gotoxy(90, 1);
	cout << "2202 김민영" << endl;
	system("cls");
	gotoxy(30, 8);
	cout << "■■■■  ■    ■  ■      ■  ■■■■   ■■";
	gotoxy(30, 9);
	cout << "■    ■  ■    ■  ■■  ■■  ■    ■   ■■";
	gotoxy(30, 10);
	cout << "■■■■  ■    ■  ■  ■  ■  ■■■■   ■■";
	gotoxy(30, 11);
	cout << "■    ■  ■    ■  ■      ■  ■    ■       ";
	gotoxy(30, 12);
	cout << "■■■■  ■■■■  ■      ■  ■■■■   ■■";
	gotoxy(40, 15);
	cout << "폭탄 실행!!! +400 SCORE";
	*bumb -= 1;
	*score += 400;
}
void gotoxy(int x, int y){ // 좌표 이동
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void game_random(int* can){ // 랜덤 수 발생 함수
	for (int i = 0; i < 16; i++){
		can[i] = rand() % 3 + 1;
	}
}
void game_check(int* can){ // 사탕 같은 지 확인하는 함수
	void game_result(int*, int, int, int, int);
	if (can[0] == can[1] && can[0] == can[2] && can[0] == can[3]) game_result(&can[0], 0, 1, 2, 3);
	if (can[4] == can[5] && can[4] == can[6] && can[4] == can[7]) game_result(&can[0], 4, 5, 6, 7);
	if (can[8] == can[9] && can[8] == can[10] && can[8] == can[11]) game_result(&can[0], 8, 9, 10, 11);
	if (can[12] == can[13] && can[12] == can[14] && can[12] == can[15]) game_result(&can[0], 12, 13, 14, 15);
	if (can[0] == can[4] && can[0] == can[8] && can[0] == can[12]) game_result(&can[0], 0, 4, 8, 12);
	if (can[1] == can[5] && can[1] == can[9] && can[1] == can[13]) game_result(&can[0], 1, 5, 9, 13);
	if (can[2] == can[6] && can[2] == can[10] && can[2] == can[14]) game_result(&can[0], 2, 6, 10, 14);
	if (can[3] == can[7] && can[3] == can[11] && can[3] == can[15]) game_result(&can[0], 3, 7, 11, 15);
}
void game_result(int *can, int a, int b, int c, int d){ // 점수 확인 함수
	PlaySound("coin.wav", NULL, SND_ASYNC);
	switch (can[a]){
	case 1:{ // 별사탕 4개 같을 때
			   score += 100;
			   gotoxy(18, 25);
			   cout << "===============================" << endl;
			   gotoxy(18, 26);
			   cout << "별 사탕 처치 +100 SCORE " << score << endl;
			   gotoxy(18, 27);
			   cout << "===============================" << endl;
			   break;
	}
	case 2:{ // 하트사탕 4개 같을 때
			   score += 200;
			   gotoxy(18, 25);
			   cout << "===============================" << endl;
			   gotoxy(18, 26);
			   cout << "하트 사탕 처치 +200 SCORE " << score << endl;
			   gotoxy(18, 27);
			   cout << "===============================" << endl;
			   break;
	}
	case 3:{ // 반쪽사탕 4개 같을 때
			   score += 300;
			   gotoxy(18, 25);
			   cout << "===============================" << endl;
			   gotoxy(18, 26);
			   cout << "반쪽 사탕 처치 +300 SCORE " << score << endl;
			   gotoxy(18, 27);
			   cout << "===============================" << endl;
			   break;
	}
	}
	// 같은 숫자의 수만 바꾸어주기
	can[a] = rand() % 3 + 1;
	can[b] = rand() % 3 + 1;
	can[c] = rand() % 3 + 1;
	can[d] = rand() % 3 + 1;
}
void first_stage(){ // 스테이지 1 클리어 함수
	PlaySound("levelup.wav", NULL, SND_ASYNC);
	gotoxy(90, 1);
	printf("2202 김민영\n");
	printf("                                                                                     \n");
	printf("                                                                                     \n");
	printf("                                                                                     \n");
	printf("                         ■     ■■■  ■    ■   ■■■  ■           ■               \n");
	printf("                         ■     ■      ■    ■   ■      ■           ■               \n");
	printf("                         ■     ■■■  ■    ■   ■■■  ■           ■               \n");
	printf("                         ■     ■      ■■■■   ■      ■           ■               \n");
	printf("                         ■■■ ■■■    ■■     ■■■  ■■■       ■               ");
	gotoxy(26, 15);
	printf("레벌 1 클리어, 레벨 2를 하려면 아무키나 누르세요.");
	_getch();
	system("cls");
}
void second_stage(){ // 스테이지 2 클리어 함수
	PlaySound("levelup.wav", NULL, SND_ASYNC);
	gotoxy(90, 1);
	printf("2202 김민영\n");
	printf("                                                                                     \n");
	printf("                                                                                     \n");
	printf("                                                                                     \n");
	printf("                      ■     ■■■  ■    ■   ■■■  ■           ■■■■         \n");
	printf("                      ■     ■      ■    ■   ■      ■                 ■         \n");
	printf("                      ■     ■■■  ■    ■   ■■■  ■           ■■■■         \n");
	printf("                      ■     ■      ■■■■   ■      ■           ■               \n");
	printf("                      ■■■ ■■■    ■■     ■■■  ■■■       ■■■■         \n\n\n\n");
	printf("                        레벌 2 클리어, 레벨 3를 하려면 아무키나 누르세요.");
	_getch();
	system("cls");
}
void game_over(){ // 시간 다 되면 게임 오버
	gotoxy(90, 1);
	cout << "2202 김민영" << endl;
	PlaySound("gameover.wav", NULL, SND_ASYNC);
	system("cls");
	gotoxy(20, 10);
	cout << "■■■   ■     ■  ■   ■■■    ■■■ ■  ■ ■■■ ■■■" << endl;
	gotoxy(20, 11);
	cout << "■     ■  ■ ■  ■  ■ ■        ■  ■ ■  ■ ■     ■  ■" << endl;
	gotoxy(20, 12);
	cout << "■  ■ ■■■ ■  ■  ■ ■■■    ■  ■ ■  ■ ■■■ ■■" << endl;
	gotoxy(20, 13);
	cout << "■  ■ ■  ■ ■  ■  ■ ■        ■  ■ ■  ■ ■     ■  ■";
	gotoxy(20, 14);
	cout << "■■■ ■  ■ ■  ■  ■ ■■■    ■■■  ■■  ■■■ ■  ■";
	gotoxy(35, 16);
	cout << "점수를 저장하고 메인으로 돌아갑니다." << endl;
	ofstream output("nickname_record.txt", ios::app);
	output << score << endl;
	output.close();
	Sleep(1500);
	menu();
}
void finish(){ // 종료
	system("cls");
	gotoxy(90, 1);
	cout << "2202 김민영" << endl;
	gotoxy(35, 10);
	cout << "캔디 팝팝팝 게임을 종료합니다."; // 게임 종료
	gotoxy(36, 12);
	cout << "♡이용해주셔서 감사합니다♡\n\n\n\n";
	system("pause>null");
}
void user_input(){ // 닉네임 입력
	system("cls");
	char username[15];
	gotoxy(90, 1);
	printf("2202 김민영\n");
	gotoxy(40, 12);
	cout << "※닉네임을 등록해주세요※";
	gotoxy(45, 16);
	cout << "닉네임 : ";
	cin >> username;

	ofstream output("nickname_record.txt", ios::app);
	output << username << endl;
	output.close();
	if (username != NULL){
		gotoxy(29, 22);
		cout << "닉네임이 등록되었습니다! 2초 후 자동으로 넘어가요!!\n";
		Sleep(2000);
	}
	system("cls");
}
void square_method(){ // 게임 옆에 간단한 설명하는 네모상자
	gotoxy(69, 5);
	cout << "-------------------------------";
	gotoxy(69, 6);
	cout << "|                             |";
	gotoxy(69, 7);
	cout << "|       각 위치의 숫자        |";
	for (int i = 0; i < 3; i++){
		gotoxy(69, 8 + i);
		cout << "|                             |";
	}
	gotoxy(69, 11);
	cout << "|     1     2     3     4     |";
	gotoxy(69, 12);
	cout << "|                             |";
	gotoxy(69, 13);
	cout << "|     5     6     7     8     |";
	gotoxy(69, 14);
	cout << "|                             |";
	gotoxy(69, 15);
	cout << "|     9     10    11    12    |";
	gotoxy(69, 16);
	cout << "|                             |";
	gotoxy(69, 17);
	cout << "|     13    14    15    16    |";
	for (int i = 0; i < 3; i++){
		gotoxy(69, 18 + i);
		cout << "|                             |";
	}
	gotoxy(69, 21);
	cout << "|  폭탄실행은 100을 누르세요  |";
	gotoxy(69, 22);
	cout << "|                             |";
	gotoxy(69, 23);
	cout << "|  메인으로는 200을 누르세요  |";
	for (int i = 0; i < 2; i++){
		gotoxy(69, 24 + i);
		cout << "|                             |";
	}
	gotoxy(69, 26);
	cout << "-------------------------------";
}