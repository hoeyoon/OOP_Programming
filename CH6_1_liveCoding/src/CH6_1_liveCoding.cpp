#include <iostream>
#include <string>
using namespace std;

/*=======================소=스=코=드====================*/

class Player {
private:
    //멤버 변수
	string name;
	int health;
	int weapon;

public:
   //멤버 함수
	Player(){}
	Player(string name, int health);
	Player(string name, int health, int weapon);
	~Player();

	void getInfo();
	string getName(){ return name; }
	int getHealth(){ return health; }
	int getWeapon(){ return weapon; }
	void setHealth(int health){ this->health = health; }
	void setWeapon(int weapon){ this->weapon = weapon; }
};

Player::Player(string name, int health) : Player(name, health, 10){}

Player::Player(string name, int health, int weapon) : name(name), health(health), weapon(weapon){}

Player::~Player(){}

void Player::getInfo() {
    cout << "-----플레이어 정보-----" << endl;
    cout << "플레이어 이름 : " << name << endl;
    cout << "체력 : " << health << endl;
    cout << "무기 : " << weapon << endl;
}


class Monster {
private:
    //멤버 변수
	string name;
	int health;
	int weapon;

public:
   //멤버 함수
	Monster();
	Monster(string name);
	Monster(string name, int health);
	~Monster();

	void getInfo();
	string getName(){ return name; }
	int getHealth(){ return health; }
	int getWeapon(){ return weapon; }
	void setHealth(int health){ this->health = health; }
	void setWeapon(int weapon){ this->weapon = weapon; }
};

Monster::Monster(string name) : Monster(name, 100){}

Monster::Monster(string name, int health)
: name(name), health(health), weapon(1){}

Monster::~Monster(){}

void Monster::getInfo() {
    cout << "-----몬스터 정보-----" << endl;
    cout << "몬스터 이름 : " << name << endl;
    cout << "체력 : " << health << endl;
    cout << "무기 : " << weapon << endl;
}

void Attack(Player &p, Monster& m) {
	cout << p.getName() << "(이)가 " << m.getName() << "을 공격했다!" << endl;
	m.setHealth(m.getHealth() - p.getWeapon());
}
void Attack(Monster& m, Player& p) {
	cout << m.getName() << "(이)가 " << p.getName() << "을 공격했다!" << endl;
	p.setHealth(p.getHealth() - m.getWeapon());
}
void Attack(Player& p1, Player& p2) {
	cout << p1.getName() << "(이)가 " << p2.getName() << "을 공격했다!" << endl;
	p2.setHealth(p2.getHealth() - p1.getWeapon());
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
