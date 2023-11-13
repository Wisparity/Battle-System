#include<iostream>
using namespace std;
void BattleSystem();
int MonsterGen();
int PlayerHealth = 50; // global variable
string inventory[5] = {"sword", "shield", "potion", " ", " "};
int main() {
	//for (int i = 0; i < 10; i++)
	//	inventory[i] = " ";
	int room = 1;
	char input = 'a';
	srand(time(NULL)); //pulling a random seed based of the computer's clock
	while (PlayerHealth >= 0 && input != 'q') {
		cout << "your inventory";
		for (int i = 0; i < 5; i++)
			cout<<inventory[i]<<" ";
		switch (room) {
		case 1:
			cout << " You're in room 1, you can go (s)outh" << endl;
			cin >> input;
			if (input == 's')
				room = 2;
			break;
		case 2:
			cout << " You're in room 2, you can go (n)orth. there's a monster in the corner (a) to attack!" << endl;
			cin >> input;
			if (input == 'n')
				room = 1;
			else if (input == 'a')
				BattleSystem();
			if (PlayerHealth <= 0)
				break;
		} // end of switch
	}// end of game loop
	if (PlayerHealth <= 0)
		cout << "GAME OVER!" << endl;
}//end of main

int MonsterGen() {
	int num = rand() % 100;
	if (num < 50) {
		cout << " a skeleton appeared!" << endl;
		return 1;
	}
	else {
		cout << "a spider appears and attacks!" << endl;
		return 2;
	}
}
void BattleSystem() {
	cout << "An Enemy Attacks!" << endl;
	int MonsterType = MonsterGen();
	system("pause");
	int MonsterHealth = 0; //default value
	int MonsterAtk = 0;
	int PlayerAtk = 0;
	if (MonsterType == 1)
		MonsterHealth = 40; //Skeleton
	else if (MonsterType == 2) {// Spooder
		MonsterHealth = 20;
	}
	//cout << "MH" << MonsterHealth << "PH" << PlayerHealth << endl;
	while (MonsterHealth > 0 && PlayerHealth > 0) { //battle loop!
		if (MonsterType == 1)
			MonsterAtk = rand() % 25; //hits from 0-24
		else if (MonsterType == 2)
			MonsterAtk = rand() % 10 + 5;

		if (inventory[1] == "shield") {
			cout << "your shield partially blocks the blow!" << endl;
			MonsterAtk /= 2;//cut damage in half
		}
		cout << "the monster attacks you for" << MonsterAtk << " dmg!" << endl;

		PlayerHealth -= MonsterAtk;

		if(inventory[0]=="sword")
			PlayerAtk = rand() % 30 + 30;
		else
			PlayerAtk = rand() % 22 + 10;

		cout << "you attack the monster for 10 dmg!" << PlayerAtk << endl;
		MonsterHealth -= PlayerAtk;
		system("pause");
		cout << "your health is now " << PlayerHealth << ", and the monste's health is " << MonsterHealth << endl;
	}
	if (MonsterHealth <= 0) {
		cout << "you won!" << endl;
	}
	else cout << "You blacked out!" << endl;
}
