#include <iostream>
#include <string>
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
BaseCoffeeMachine::BaseCoffeeMachine(string model, string manufacturer, int totalWater){
	this->model = model;
	this->manufacturer = manufacturer;
	this->availableWater = totalWater;
	this->brewedCount = 0;
}

// 커피를 만드는 메서드 구현
bool BaseCoffeeMachine::brew(int cups) {
	if(this->availableWater < cups){
		return false;
	}
	this->availableWater -= cups;
	brewedCount += cups;
	return true;
}

// 커피 머신 상태를 출력하는 메서드 구현
void BaseCoffeeMachine::show() {
	cout << model << " ," << manufacturer << " ,남은 물 " << availableWater << "ml ,";
}

// EspressoMachine 클래스의 생성자 구현
EspressoMachine::EspressoMachine(string model, string manufacturer, int totalWater, int totalBeans):
		BaseCoffeeMachine(model, manufacturer, totalWater), availableBeans(totalBeans){}

// 에스프레소를 만드는 메서드 구현
bool EspressoMachine::brewEspresso(int cups) {
	if(brew(cups)){
		if (availableBeans >= cups) {
			availableBeans -= cups;
			return true;
		}
		return false;
	}
	return false;
}

// 에스프레소 머신 상태를 출력하는 메서드 구현
void EspressoMachine::showState() {
	show(); cout << "남은 커피 콩 " << availableBeans << "개" << endl;
}

// AmericanoMachine 클래스의 생성자 구현
AmericanoMachine::AmericanoMachine(string model, string manufacturer, int totalWater, int totalCapsules):
		BaseCoffeeMachine(model, manufacturer, totalWater), availableCapsules(totalCapsules){}

// 아메리카노를 만드는 메서드 구현
bool AmericanoMachine::brewAmericano(int cups) {
	if(brew(cups)){
		if (availableCapsules >= cups) {
			availableCapsules -= cups;
			return true;
		}
		return false;
	}
	return false;
}

// 아메리카노 머신 상태를 출력하는 메서드 구현
void AmericanoMachine::showState() {
	show(); cout << "남은 캡슐 " << availableCapsules << "개" << endl;
}

// CoffeeMachineManager 클래스의 생성자 구현
CoffeeMachineManager::CoffeeMachineManager() {
	em = new EspressoMachine("Barista Express", "Breville", 2000, 50);
	am = new AmericanoMachine("VertuoPlus", "Nespresso", 1500, 30);
}

// CoffeeMachineManager 클래스의 소멸자 구현
CoffeeMachineManager::~CoffeeMachineManager() {
	delete em;
	delete am;
}

// 커피 머신을 작동시키는 메서드 구현
void CoffeeMachineManager::operate() {
	cout << "현재 작동중인 2 대의 커피 머신은 아래와 같습니다:" << endl;
	cout << "에스프레소 머신: "; em->showState();
	cout << "아메리카노 머신: "; am->showState();
	
	char chk = 'y';
	while(chk != 'n'){
		 cout << endl << "커피 머신(1:에스프레소, 2:아메리카노)과 컵 수 입력>>";
		 int cm, cups;
		 cin >> cm >> cups;
		 switch(cm){
		 case 1:
			 if(em->brewEspresso(cups))
				 cout << "에스프레소를 만들었습니다." << endl;
			 else
				 cout << "커피 콩이 부족하여 에스프레소를 만들 수 없습니다." << endl;
			 break;
			
		 case 2:
			 if(am->brewAmericano(cups))
				 cout << "아메리카노를 만들었습니다." << endl;
			 else
				 cout << "캡슐이 부족하여 아메리카노를 만들 수 없습니다." << endl;
			 break;
			 			
		 }
		 em->showState();
		 am->showState();
		 cout << "계속 커피를 만드시겠습니까(y/n)>>"; cin >> chk;
	}
}

int main() {
    CoffeeMachineManager manager; // 커피 머신 관리자 인스턴스 생성
    manager.operate(); // 커피 머신 작동
    return 0;
}
