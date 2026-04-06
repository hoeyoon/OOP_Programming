#include <iostream>
#include <string>
using namespace std;

/*=======================소=스=코=드====================*/

class Player {
private:
    //멤버 변수
public:
   //멤버 함수
};

void Player::getInfo() {
    cout << "-----플레이어 정보-----" << endl;
    cout << "플레이어 이름 : " << << endl;
    cout << "체력 : " << << endl;
    cout << "무기 : " <<  << endl;
}


class Monster {
private:
    //멤버 변수
public:
   //멤버 함수
};
void Monster::getInfo() {
    cout << "-----몬스터 정보-----" << endl;
    cout << "몬스터 이름 : " <<  << endl;
    cout << "체력 : " <<  << endl;
    cout << "무기 : " <<  << endl;
}

void Attack() {
  cout << << "(이)가 " <<  << "을 공격했다!" << endl;
}
void Attack() {
  cout << << "(이)가 " <<  << "을 공격했다!" << endl;
}
void Attack() {
  cout << << "(이)가 " <<  << "을 공격했다!" << endl;
}

int main() {

    Player player_1("홍길동", 100);
    Player player_2("손오공", 100, 5);
    Monster monster_A("몬스터 A"), monster_B("몬스터 B", 200);

    int i;
    cin >> i;
    switch (i)
    {
    case 1: //플레이어가 몬스터 공격
        Attack(player_2, monster_A);
        player_2.getInfo();
        monster_A.getInfo();
        break;
    case 2: //몬스터가 플레이어 공격
        Attack(monster_B, player_1);
        player_1.getInfo();
        monster_B.getInfo();
        break;
    case 3: //플레이어가 플레이어 공격
        Attack(player_1, player_2);
        player_1.getInfo();
        player_2.getInfo();
        break;
    }
    return 0;
}
