# OJ CH8_1_liveCoding
### 문제 설명
```
커피 머신을 시뮬레이션하는 프로그램을 작성하고자 한다 여기에는 커피 머신의 다양한 기능을 모델링하는 여러 클래스가 포함되어 있다. 
① BaseCoffeeMachine 클래스:  모든 커피 머신의 기본 클래스로, 공통 속성과 메서드를 정의 한다
② EspressoMachine 클래스: BaseCoffeeMachine에서 파생된 클래스로, 에스프레소를 만드는 데 필요한 추가 속성과 메서드를 가진다
③ AmericanoMachine 클래스: BaseCoffeeMachine에서 파생된 또 다른 클래스로, 아메리카노를 만드는 데 필요한 추가 속성과 메서드를 가진다
④ CoffeeMachineManager 클래스: 에스프레소 머신과 아메리카노머신을 관리한다.
   - 생성자에서는 두 종류의 커피 머신 인스턴스를 생성하고, 소멸자에서는 이를 삭제한다
   - operate 메서드는 사용자 입력을 받아 해당 커피 머신의 brewEspresso 또는 
     brewAmericano 메서드를 호출하고, 계속해서 커피를 만들지 여부를 묻는다

** 제공된 기본 소스는 변경할수 없다
```

### 입출력형식
```
현재 작동중인 2 대의 커피 머신은 아래와 같습니다:
에스프레소 머신: Barista Express ,Breville ,남은 물 2000ml ,남은 커피 콩 50개
아메리카노 머신: VertuoPlus ,Nespresso ,남은 물 1500ml ,남은 캡슐 30개

커피 머신(1:에스프레소, 2:아메리카노)과 컵 수 입력>>1 20
에스프레소를 만들었습니다.
Barista Express ,Breville ,남은 물 1980ml ,남은 커피 콩 30개
VertuoPlus ,Nespresso ,남은 물 1500ml ,남은 캡슐 30개
계속 커피를 만드시겠습니까(y/n)>>y

커피 머신(1:에스프레소, 2:아메리카노)과 컵 수 입력>>2 30
아메리카노를 만들었습니다.
Barista Express ,Breville ,남은 물 1980ml ,남은 커피 콩 30개
VertuoPlus ,Nespresso ,남은 물 1470ml ,남은 캡슐 0개
계속 커피를 만드시겠습니까(y/n)>>y

커피 머신(1:에스프레소, 2:아메리카노)과 컵 수 입력>>2 3
캡슐이 부족하여 아메리카노를 만들 수 없습니다.
Barista Express ,Breville ,남은 물 1980ml ,남은 커피 콩 30개
VertuoPlus ,Nespresso ,남은 물 1467ml ,남은 캡슐 0개
계속 커피를 만드시겠습니까(y/n)>>n
```

### 소스코드
```c++
#include < iostream>
#include < string>
using namespace std;

// 기본 커피 머신 클래스
class BaseCoffeeMachine {
    string model; // 커피 머신 모델명
    string manufacturer; // 제조사
    int brewedCount; // 만들어진 커피의 수
    int availableWater; // 사용 가능한 물의 양

public:
    // 생성자(모델명, 제조사, 초기 물의 양을 설정)
    BaseCoffeeMachine(string model, string manufacturer, int totalWater);
protected:
    // 커피를 만드는 메서드
    bool brew(int cups = 1);
    // 각종 getter 메서드들
    string getModel() { return model; }
    string getManufacturer() { return manufacturer; }
    int getBrewedCount() { return brewedCount; }
    int getAvailableWater() { return availableWater; }
   
    void show(); // 커피 머신 상태를 출력하는 메서드
};

// 에스프레소 머신 클래스
class EspressoMachine : public BaseCoffeeMachine {
    int availableBeans; // 사용 가능한 커피 콩의 양

public:
    // 생성자
    EspressoMachine(string model, string manufacturer, int totalWater, int totalBeans);
    bool brewEspresso(int cups = 1);// 에스프레소를 만드는 메서드
    void showState();   // 에스프레소머신 상태를 출력하는 메서드
};

// 아메리카노 머신 클래스
class AmericanoMachine : public BaseCoffeeMachine {
    int availableCapsules; // 사용 가능한 캡슐의 양

public:
    // 생성자
    AmericanoMachine(string model, string manufacturer, int totalWater, int totalCapsules);
     bool brewAmericano(int cups = 1); // 아메리카노를 만드는 메서드
     void showState(); // 아메리카노 머신 상태를 출력하는 메서드
};

// 커피 머신 관리자 클래스
class CoffeeMachineManager {
    EspressoMachine* em; 
    AmericanoMachine* am; 

public:
     CoffeeMachineManager();
     ~CoffeeMachineManager();
     void operate(); // 커피 머신을 작동시키는 메서드
};

// BaseCoffeeMachine 클래스의 생성자 구현
 /*         */

// 커피를 만드는 메서드 구현
bool BaseCoffeeMachine::brew(int cups) {
 /*                  */
}

// 커피 머신 상태를 출력하는 메서드 구현
void BaseCoffeeMachine::show() {
 /*                    */
}

// EspressoMachine 클래스의 생성자 구현
EspressoMachine::EspressoMachine(string model, string manufacturer, int totalWater, int totalBeans)
 /*                    */
}

// 에스프레소를 만드는 메서드 구현
bool EspressoMachine::brewEspresso(int cups) {
 /*                       */
}

// 에스프레소 머신 상태를 출력하는 메서드 구현
void EspressoMachine::showState() {
  /*                               */
}

// AmericanoMachine 클래스의 생성자 구현
AmericanoMachine::AmericanoMachine(string model, string manufacturer, int totalWater, int totalCapsules)
  /*                           */

}

// 아메리카노를 만드는 메서드 구현
bool AmericanoMachine::brewAmericano(int cups) {
  /*                               */
}

// 아메리카노 머신 상태를 출력하는 메서드 구현
void AmericanoMachine::showState() {
   /*                   */
}

// CoffeeMachineManager 클래스의 생성자 구현
CoffeeMachineManager::CoffeeMachineManager() {
  /*                        */
}

// CoffeeMachineManager 클래스의 소멸자 구현
CoffeeMachineManager::~CoffeeMachineManager() {
 /*                              */
}

// 커피 머신을 작동시키는 메서드 구현
void CoffeeMachineManager::operate() {
 /*                            */
int main() {
    CoffeeMachineManager manager; // 커피 머신 관리자 인스턴스 생성
    manager.operate(); // 커피 머신 작동
    return 0;
}
```