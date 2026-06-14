```
곧 여름이다...
이 문제는 가족들이 1일 1식을하며 가족들의 하루 섭취량을 계산하는 프로그램을 작성하는 것이다.
가족 하루 섭취량 계산 클래스인 'CalFood'는 여러 가족구성원이 함께 사용하기 때문에 전체 하나만 있어야한다.
따라서 CalFood의 멤버변수와 멤버함수는 static으로 작성해야한다.
아래 입/출력과 제약사항에 맞는 CalFood 클래스와 Person 클래스를 작성하시오.

*제약사항
- CalFood의 멤버변수는 public, Person 클래스의 멤버변수는 private(public으로 선언 불가)
- main 함수 수정 불가.
- CalFood의 멤버변수와 멤버함수는 static으로 작성.
- Person 클래스의 음식을 나타내는 멤버변수 Infofood는 1개
- CalFood의 음식을 나타내는 구조체는  멤버변수 Infofood100개

/*=======================예제====================*/
예제 -1
(입력)
피자 1000
통닭 2000
아메리카노 0

(출력)
************* 누적된 칼로리 *************
지금 까지 먹은 음식 : 피자 통닭 아메리카노
총 칼로리: 3000 kcal

예제 -2
(입력)
공기밥 300
된장국 200
김치찌개 600

(출력)
************* 누적된 칼로리 *************
지금 까지 먹은 음식 : 공기밥 된장국 김치찌개
총 칼로리: 1100 kcal


/*=======================소스코드====================*/
#include
#include
using namespace std;

struct Infofood {
    string food;
    int calories;
};

class CalFood {

};

void CalFood::addFood(Infofood _eatfood) {

}
class Person {

};

void CalFood::printTotalCalories() {
    int i = 0;
    cout << "************* 누적된 칼로리 *************\n";
    cout << "지금 까지 먹은 음식 : ";
    while (i < cnt) {
        cout << food[i].food << " ";
        i++;
    }
    cout << endl;
    cout << "총 칼로리: " << totalCalories << " kcal" << endl;
    cout << endl;
}

int main() {
    Person human[3];
    int i = 0;

    while (i < 3) {
        Infofood eatfood;
        cin >> eatfood.food >> eatfood.calories;
        human[i].setfood(eatfood);
        i++;
    }
    CalFood::printTotalCalories();
}
```