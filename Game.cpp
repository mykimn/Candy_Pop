/* ó�� �ۼ���  : 2017.09.10   ���� ������ : 2017.10.31
�ۼ��� : ��ο�                     ���α׷� : ĵ�� ������  */
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
int dwID, dwPA; // ���� ���� ����
int score = 0; // ����
int bumb = 3; // ��ź ����
int flag = 0; // �������� Ȯ��
using namespace std;
void gotoxy(int, int);
void playMusicOne(){ // ù ��° ���� ����
	mciOpen.lpstrElementName = "candy.mp3"; // ���� ��� �Է�
	mciOpen.lpstrDeviceType = "mpegvideo";

	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&mciOpen);

	dwID = mciOpen.wDeviceID;

	mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, // play & repeat
		(DWORD)(LPVOID)&m_mciPlayParms);
}
void playMusicTwo(){ // ���� ���� �� ����
	mciSendCommandW(dwID, MCI_CLOSE, 0, NULL);
	mciOpen.lpstrElementName = "start.mp3"; // ���� ��� �Է�
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
	// ���� ù ����ȭ��
	start();
	// �޴� ���� ȭ��
	menu();
	return 0;
}
void start(){ // ���� ȭ��
	gotoxy(90, 1);
	printf("2202 ��ο�\n");
	system("color 3F");
	cout << endl << endl << endl;
	cout << "                     ����   ��   ���� ���� �� ��    ���� ���� ����" << endl;
	cout << "                     ��     ��  �� ��  �� ��  �� �� ��    ��  �� ���� ��  ��" << endl;
	cout << "                     ��     ���� ��  �� ��  ��  ��      ���� ���� ����" << endl;
	cout << "                     ���� ��  �� ��  �� ����  ��      ��     ���� ��    ";
	gotoxy(38, 15);
	cout << "�ƹ�Ű�� ������ �����մϴ�." << endl;
	cout << endl << endl << endl << endl;
	cout << "                                  ����                   ����          " << endl;
	cout << "                     ����      ��    ��      ����     ��    ��     ���" << endl;
	cout << "                    ��    ��     ��    ��     ��    ��    ��    ��     ���" << endl;
	cout << "                    ��    ��      ����      ��    ��     ����      ���" << endl;
	cout << "                     ����         ��         ����        ��        ���" << endl;
	cout << "                       ��           ��           ��          ��             " << endl;
	cout << "                       ��           ��           ��          ��         ��" << endl;
	cout << "                       ��           ��           ��          ��         ��";
	_getch();
}
void menu(){ // �޴� ���� ȭ��
	mciSendCommandW(dwPA, MCI_CLOSE, 0, NULL);
	playMusicOne();
	system("cls");
	void game_start(); void game_method(); void game_record(); void draw_square(); void user_input(); void buy_bumb(); void finish(); void timer(int);// �Լ� ������Ÿ��
	int num = 0;
	gotoxy(90, 1);
	cout << "2202 ��ο�" << endl;
	cout << "                                                                              " << endl;
	cout << "                                                                              " << endl;
	cout << "                                                                              " << endl;
	cout << "                                  1. ���� ���" << endl << endl;
	cout << "                                  2. ���� ����" << endl << endl;
	cout << "                                  3. ����" << endl << endl;
	cout << "                                  4. ���" << endl << endl;
	cout << "                                  5. ����" << endl << endl;
	cout << "                                 �� 1���� 5���� �޴��� ������ : ";
	cin >> num; // �޴�����
	if (num > 5 || num < 1){
		gotoxy(37, 17);
		cout << "1���� 5������ ���� �Է��ϼ���!!!";
		Sleep(1000);
		return menu();
	}
	switch (num){
	case 1:{
			   game_method(); // ���ӹ��
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
		game_record(); // ���ӱ��
		break;
	case 5:
		buy_bumb(); // ����
		break;
	}

}
void new_money(int *money){
	int mo;
	cout << "�󸶸� �����Ͻðڽ��ϱ�?(100~1000����) : ";
	cin >> mo;
	cout << "������ �Ϸ�Ǿ����ϴ�. ";
	*money += mo;
}
int money = 1000;
void buy_bumb(){
	void new_money(int*);
	int count;
	char check, money_check;
	gotoxy(90, 1);
	cout << "2202 ��ο�" << endl;

	system("cls");
	gotoxy(33, 3);
	cout << "�� CANDY POP! POP! POP!�� �����Դϴ� ��" << endl;
	gotoxy(80, 4);
	cout << "���� ���� : " << money;
	gotoxy(33, 5);
	cout << "����� ��ź�� �߰� ���԰����մϴ�!" << endl;
	gotoxy(20, 6);
	cout << "��ź�� �����Ͻð� �����ø� Y/y��, �޴��� ���� �� N/n�� �����ּ��� : ";
	cin >> check;
	if (check == 'Y' || check == 'y'){
		gotoxy(27, 7);
		cout << "��ź�� �� �� �����Ͻðڽ��ϱ�? (�ϳ��� 200����) : ";
		cin >> count;
		if (money - (count * 200) <= 0){
			gotoxy(13, 8);
			cout << "�Ӵϰ� �����մϴ�. �Ӵϸ� �����Ͻ÷��� Y/y��, �׸��Ͻ÷��� N/n�� �����ּ��� : ";
			cin >> money_check;
			if (money_check == 'Y' || money_check == 'y'){
				new_money(&money);
				return buy_bumb();
			}
			else{
				gotoxy(30, 9);
				cout << "   �ƹ�Ű�� ������ �޴��� ���ư��ϴ�.";
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
			cout << "��ź " << count << "�� �����Ͽ����ϴ�.";
			gotoxy(30, 11);
			cout << "   �ƹ�Ű�� ������ �޴��� ���ư��ϴ�.";
			if (_getch()){
				system("cls");
				return menu();
			}
		}
	}
	else{
		gotoxy(30, 10);
		cout << "   �ƹ�Ű�� ������ �޴��� ���ư��ϴ�.";
		if (_getch()){
			system("cls");
			return menu();
		}
	}
}
void game_method(){ // ���� ��� ����
	system("cls");
	gotoxy(90, 1);
	printf("2202 ��ο�\n");
	cout << "   �� CANDY POP POP POP ���� ��� ��\n\n";
	cout << "1. 4�� 4���� ǥ�� �־�����, 3���� ����� �� ������ ���´�.\n\n";
	cout << "   �������� ��ġ�� ������ ���� ������� �� ���� ������ �����\n\n";
	cout << "   �� ���� �´� ������ �����ȴ�.\n\n";
	cout << "   �ٲٰ� ���� �� ���� ����� ��ü�� �� ���� ����.\n\n";
	cout << "   (�� ���� �ٷ� ���� �� �Ǵ� ���� ���͸� �ٲ� �� �ִ�.)\n\n";
	cout << "   ����� ���� ���ʺ��� 1���̰� �� 16 ������ ���� �ִ�.\n\n";
	cout << "   �� ù° ���� 1 2 3 4 ��° ���� 5 6 7 8�� ����.\n\n\n";
	cout << "2. STAGE 1���� 1200 SCORE�� ���� �� ���� ���������� �Ѿ�� �ȴ�.\n\n";
	cout << "   ���� ȹ���� ������ ����.\n\n";
	cout << "   ��   ���� ��  =>  + 100\n\n";
	cout << "   ��Ʈ ���� ��  =>  + 200\n\n";
	cout << "   ���� ���� ��  =>  + 300\n\n";
	cout << "   Bumb     100  =>  + 400\n\n\n\n";
	cout << "   �ƹ�Ű�� ������ �޴��� ���ư��ϴ�.";
	if (_getch()){
		system("cls");
		menu();
	}
}
void game_start(){ // ���� ���� �Լ�
	playMusicTwo();
	int i = 1;
	int stage[2] = { 1200, 2300 }; // �������� �� ���� 1200,2300
	void game_random(int *); void game_check(int *); void first_stage(); void second_stage(); void last_stage(); void game_over(); int number_check(int, int); void square_method(); void bumb_change(int*, int*); void menu_change(); void wait(int);// �Լ� ������Ÿ��
	clock_t sta, end;// ���۽ð�, ���ð�
	int can[16], change, that, temp; // ���� �߻�
	double g_time = 100;
	char candy[16][4]; // ��� �־����
	system("cls");
	// ���� ����
	srand((unsigned)time(NULL));
	gotoxy(90, 1);
	cout << "2202 ��ο�" << endl;
	gotoxy(90, 3);
	cout << "��ź : " << bumb << "��";
	gotoxy(89, 4);
	cout << "SCORE : " << score << endl;
	gotoxy(25, 3);
	cout << "���� �ð� : " << g_time - clock() / 1000 << "��";
	game_random(&can[0]);
	while (true){
		game_check(&can[0]);
		gotoxy(25, 3);
		cout << "���� �ð� : " << g_time - clock() / 1000 << "��";
		if (g_time - clock() / 1000 <= 0){
			game_over();
		}
		if (score >= stage[0] && flag == 0){ // ������ 1200 �̻�
			system("cls");
			first_stage();
			flag = 1;
			g_time = 90;
			system("color 0E");
		}
		if (score >= stage[1] && flag == 1){ // ������ 2300 �̻�
			system("cls");
			second_stage();
			flag = 2;
			g_time = 80;
			system("color 71");
		}
		game_check(&can[0]); // ���� ���� üũ
		cout << "                 ";
		gotoxy(90, 1);
		cout << "2202 ��ο�" << endl;
		gotoxy(90, 3);
		cout << "��ź : " << bumb << "��";
		gotoxy(89, 4);
		cout << "SCORE : " << score << endl;


		square_method(); // ���� ���� ������ ȭ��

		for (int i = 0; i < 16; i++){ // ���ڸ� ĵ��� �ٲٱ�
			switch (can[i]){
			case 1: strcpy_s(candy[i], "��"); break;
			case 2: strcpy_s(candy[i], "��"); break;
			case 3: strcpy_s(candy[i], "��"); break;
			}
		}
		gotoxy(7, 2);
		for (int i = 0; i < 16; i++){ // ��� ���
			if (i % 4 == 0){
				cout << endl << endl << endl << endl;
				cout << "            ";
			}
			cout << candy[i] << "           ";
		}
		// �ٲ� ���� �Է¹ޱ�
		gotoxy(15, 22);
		cout << "��� �ٲٽðھ�� ? (ENTER) : ";
		cin >> change;
		if (change == 200){
			menu_change();
			Sleep(1000);
			return menu();
		}
		if (change == 100){ // * ������ ��ź ����
			if (bumb != 0){
				bumb_change(&bumb, &score);
				Sleep(1000);
			}
			else{
				gotoxy(18, 24);
				cout << "��ź�� ������ �����մϴ�!" << endl;
				Sleep(700);
				return game_start();
			}
		}
		else{
			cout << "                                    ";
			gotoxy(15, 22);
			cout << "���� �ٲٽðھ�� ? (ENTER) : " << change << " -> ";
			cin >> that;

			int result = number_check(change, that); // �翷 ���Ʒ� �������� Ȯ��
			// �ٲ� ���� �ٲٱ�
			if (result == 1){ // �翷 ���Ʒ� �����̸�
				temp = can[change - 1];
				can[change - 1] = can[that - 1];
				can[that - 1] = temp;
			}
			else if (result == 0 || result == 2){ // �ٸ� �����ϰ��
				gotoxy(17, 24);
				cout << "��ȯ�� �翷 �� �Ʒ��� �����մϴ�!" << endl;
				Sleep(500);
			}
		}
		gotoxy(25, 5);
		system("cls");
	}
};
int number_check(int change, int that){ //�ٲ� ���� �翷 ���Ʒ� ������ Ȯ���ϴ� �Լ�
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
void game_record(){ // ��� Ȯ��
	int i = 9;
	system("cls");
	gotoxy(90, 1);
	cout << "2202 ��ο�" << endl;
	gotoxy(37, 5);
	cout << "�� �г��Ӱ� ���Ȯ���ϼ��� ��" << endl;
	gotoxy(41, 7);
	cout << "�г���";
	gotoxy(55, 7);
	cout << "���";
	ifstream input("nickname_record.txt");
	if (input.fail()){
		cout << "������ ���� �� �����߽��ϴ�." << endl;
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
	cout << "�ƹ�Ű�� �����ø� �޴��� �ٽ� �̵��մϴ�. ";
	if (_getch()){
		system("cls");
		menu();
	}
	cout << endl << endl << endl;
	system("pause>null");
}
void menu_change(){ // �޴��� ���ư� �� �̿��ϴ� �Լ�
	gotoxy(90, 1);
	cout << "2202 ��ο�" << endl;
	system("cls");
	gotoxy(30, 8);
	cout << "����  ����      ����    ��    ����  ��  ��";
	gotoxy(30, 9);
	cout << "��      ��  ��      ��  ��  ��  ��  ��      ���";
	gotoxy(30, 10);
	cout << "����  ��  ��      ����  ����  ��      ��";
	gotoxy(30, 11);
	cout << "��  ��  ��  ��      ��  ��  ��  ��  ��      ���";
	gotoxy(30, 12);
	cout << "����  ����      ����  ��  ��  ����  ��  ��";
	gotoxy(40, 15);
	cout << "�޴��� ���ư��ϴ�!!!";
	ofstream output("nickname_record.txt", ios::app);
	output << score << endl;
	output.close();

}
void bumb_change(int *bumb, int *score){ // ��ź ���� �Լ�
	PlaySound("bumb.wav", NULL, SND_ASYNC);
	gotoxy(90, 1);
	cout << "2202 ��ο�" << endl;
	system("cls");
	gotoxy(30, 8);
	cout << "�����  ��    ��  ��      ��  �����   ���";
	gotoxy(30, 9);
	cout << "��    ��  ��    ��  ���  ���  ��    ��   ���";
	gotoxy(30, 10);
	cout << "�����  ��    ��  ��  ��  ��  �����   ���";
	gotoxy(30, 11);
	cout << "��    ��  ��    ��  ��      ��  ��    ��       ";
	gotoxy(30, 12);
	cout << "�����  �����  ��      ��  �����   ���";
	gotoxy(40, 15);
	cout << "��ź ����!!! +400 SCORE";
	*bumb -= 1;
	*score += 400;
}
void gotoxy(int x, int y){ // ��ǥ �̵�
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void game_random(int* can){ // ���� �� �߻� �Լ�
	for (int i = 0; i < 16; i++){
		can[i] = rand() % 3 + 1;
	}
}
void game_check(int* can){ // ���� ���� �� Ȯ���ϴ� �Լ�
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
void game_result(int *can, int a, int b, int c, int d){ // ���� Ȯ�� �Լ�
	PlaySound("coin.wav", NULL, SND_ASYNC);
	switch (can[a]){
	case 1:{ // ������ 4�� ���� ��
			   score += 100;
			   gotoxy(18, 25);
			   cout << "===============================" << endl;
			   gotoxy(18, 26);
			   cout << "�� ���� óġ +100 SCORE " << score << endl;
			   gotoxy(18, 27);
			   cout << "===============================" << endl;
			   break;
	}
	case 2:{ // ��Ʈ���� 4�� ���� ��
			   score += 200;
			   gotoxy(18, 25);
			   cout << "===============================" << endl;
			   gotoxy(18, 26);
			   cout << "��Ʈ ���� óġ +200 SCORE " << score << endl;
			   gotoxy(18, 27);
			   cout << "===============================" << endl;
			   break;
	}
	case 3:{ // ���ʻ��� 4�� ���� ��
			   score += 300;
			   gotoxy(18, 25);
			   cout << "===============================" << endl;
			   gotoxy(18, 26);
			   cout << "���� ���� óġ +300 SCORE " << score << endl;
			   gotoxy(18, 27);
			   cout << "===============================" << endl;
			   break;
	}
	}
	// ���� ������ ���� �ٲپ��ֱ�
	can[a] = rand() % 3 + 1;
	can[b] = rand() % 3 + 1;
	can[c] = rand() % 3 + 1;
	can[d] = rand() % 3 + 1;
}
void first_stage(){ // �������� 1 Ŭ���� �Լ�
	PlaySound("levelup.wav", NULL, SND_ASYNC);
	gotoxy(90, 1);
	printf("2202 ��ο�\n");
	printf("                                                                                     \n");
	printf("                                                                                     \n");
	printf("                                                                                     \n");
	printf("                         ��     ����  ��    ��   ����  ��           ��               \n");
	printf("                         ��     ��      ��    ��   ��      ��           ��               \n");
	printf("                         ��     ����  ��    ��   ����  ��           ��               \n");
	printf("                         ��     ��      �����   ��      ��           ��               \n");
	printf("                         ���� ����    ���     ����  ����       ��               ");
	gotoxy(26, 15);
	printf("���� 1 Ŭ����, ���� 2�� �Ϸ��� �ƹ�Ű�� ��������.");
	_getch();
	system("cls");
}
void second_stage(){ // �������� 2 Ŭ���� �Լ�
	PlaySound("levelup.wav", NULL, SND_ASYNC);
	gotoxy(90, 1);
	printf("2202 ��ο�\n");
	printf("                                                                                     \n");
	printf("                                                                                     \n");
	printf("                                                                                     \n");
	printf("                      ��     ����  ��    ��   ����  ��           �����         \n");
	printf("                      ��     ��      ��    ��   ��      ��                 ��         \n");
	printf("                      ��     ����  ��    ��   ����  ��           �����         \n");
	printf("                      ��     ��      �����   ��      ��           ��               \n");
	printf("                      ���� ����    ���     ����  ����       �����         \n\n\n\n");
	printf("                        ���� 2 Ŭ����, ���� 3�� �Ϸ��� �ƹ�Ű�� ��������.");
	_getch();
	system("cls");
}
void game_over(){ // �ð� �� �Ǹ� ���� ����
	gotoxy(90, 1);
	cout << "2202 ��ο�" << endl;
	PlaySound("gameover.wav", NULL, SND_ASYNC);
	system("cls");
	gotoxy(20, 10);
	cout << "����   ��     ��  ��   ����    ���� ��  �� ���� ����" << endl;
	gotoxy(20, 11);
	cout << "��     ��  �� ��  ��  �� ��        ��  �� ��  �� ��     ��  ��" << endl;
	gotoxy(20, 12);
	cout << "��  �� ���� ��  ��  �� ����    ��  �� ��  �� ���� ���" << endl;
	gotoxy(20, 13);
	cout << "��  �� ��  �� ��  ��  �� ��        ��  �� ��  �� ��     ��  ��";
	gotoxy(20, 14);
	cout << "���� ��  �� ��  ��  �� ����    ����  ���  ���� ��  ��";
	gotoxy(35, 16);
	cout << "������ �����ϰ� �������� ���ư��ϴ�." << endl;
	ofstream output("nickname_record.txt", ios::app);
	output << score << endl;
	output.close();
	Sleep(1500);
	menu();
}
void finish(){ // ����
	system("cls");
	gotoxy(90, 1);
	cout << "2202 ��ο�" << endl;
	gotoxy(35, 10);
	cout << "ĵ�� ������ ������ �����մϴ�."; // ���� ����
	gotoxy(36, 12);
	cout << "���̿����ּż� �����մϴ٢�\n\n\n\n";
	system("pause>null");
}
void user_input(){ // �г��� �Է�
	system("cls");
	char username[15];
	gotoxy(90, 1);
	printf("2202 ��ο�\n");
	gotoxy(40, 12);
	cout << "�شг����� ������ּ����";
	gotoxy(45, 16);
	cout << "�г��� : ";
	cin >> username;

	ofstream output("nickname_record.txt", ios::app);
	output << username << endl;
	output.close();
	if (username != NULL){
		gotoxy(29, 22);
		cout << "�г����� ��ϵǾ����ϴ�! 2�� �� �ڵ����� �Ѿ��!!\n";
		Sleep(2000);
	}
	system("cls");
}
void square_method(){ // ���� ���� ������ �����ϴ� �׸����
	gotoxy(69, 5);
	cout << "-------------------------------";
	gotoxy(69, 6);
	cout << "|                             |";
	gotoxy(69, 7);
	cout << "|       �� ��ġ�� ����        |";
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
	cout << "|  ��ź������ 100�� ��������  |";
	gotoxy(69, 22);
	cout << "|                             |";
	gotoxy(69, 23);
	cout << "|  �������δ� 200�� ��������  |";
	for (int i = 0; i < 2; i++){
		gotoxy(69, 24 + i);
		cout << "|                             |";
	}
	gotoxy(69, 26);
	cout << "-------------------------------";
}