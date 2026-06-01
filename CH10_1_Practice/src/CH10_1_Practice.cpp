#include <iostream>
#include <string>
using namespace std;

/******************************************************************************
 * Class Rand
 ******************************************************************************/
// 난수를 발생하는 클래스임. 이해하려 하지말고 건너 뛰기 바람.

#include <random>

int seed = 0;

class Rand {
    // 난수를 생성하는 엔진
    default_random_engine re;
    // 발생된 난수 값들이 일정 범위의 균등 분포(unfiform)로 매핑
    uniform_int_distribution< int > dist;
public:
    // [low, high] 범위 내의 값이 발생하도록 dist 초기화
    Rand(int low, int high): dist(low, high) { }
    
    // [low, high] 범위 내의 난수 발생하는 함수
    int operator() () { return dist(re); }
    
    void setSeed() {
        cout << "seed for random number? ";
        cin >> seed;
        re.seed(seed);
    }
};

// [10, 29] 범위의 난수 발생기
Rand rnd(10, 29);

/******************************************************************************
 * template class
 ******************************************************************************/
void templateClass() {
}

/******************************************************************************
 * 컨테이너 클래스 map and vector, algorithm, lambda
 ******************************************************************************/
#include <map>
#include <vector>
#include <algorithm>

vector<int> iv;
map<int, string> mp;

void printVector(string msg = {}) {}
void vectorAppend() {}
void vectorDisplay() {}
void vectorSort() {}
void vectorLambda() {}

// map의 모든 원소의 (키, 값) 쌍을 출력한다.
void printMap(string msg = {}) {
	if (!msg.empty())
	    cout << msg << endl;
    cout << "map: ";
    for (auto p: mp)
        cout << "(" << p.first << "," << p.second << ") ";
        // p는 struct pair { int first; string second; } 형의 구조체 변수이며
        // p는 mp에 저장된 각 원소를 의미하며 p.first가 키, p.second가 value 값임
    cout << endl;
}

void vectorToMap() {}
void find_map() {}
void mapFind() {}
void mapToVector() {}

/******************************************************************************
 * menu_switch() 함수: 선택된 메인 메뉴 항목을 실행함
 ******************************************************************************/
string menuStr =
    "------------- Template and STL ------------\n"
    "  0.exit 1.template_class 2.vector 3.sort  \n"
    "  4.lambda 5.map 6.find 7.mapToVector      \n"
    "-------------------------------------------\n"
    "menu item? ";

void menu_switch(int menu)
{
    switch (menu) {
    case 1: templateClass(); break;
    case 2: vectorDisplay(); break;
    case 3: vectorSort();    break;
    case 4: vectorLambda();  break;
    case 5: vectorToMap();   break;
    case 6: mapFind();       break;
    case 7: mapToVector();   break;
    }
    cout << endl;
}

/******************************************************************************
 * main() 함수
 ******************************************************************************/
int main()
{
    while (true) {
        int menu;
        cout << menuStr;
        cin >> menu;
        if (menu == 0) break;
        menu_switch(menu);
    }
    cout << "\nGood bye!!" << endl;
}
