#include <iostream>
#include <string>
using namespace std;

//-------------------------------------------------
// 기본 수강권 클래스 Course
//-------------------------------------------------
class Course {
protected:
    string name;    // 수강권 이름
    int price;      // 기본 가격

public:
    //-------------------------------------------------
    // 문제 1
    // Course 생성자를 구현하라.
    //
    // 조건:
    // 1. 매개변수 name을 멤버 변수 name에 저장한다.
    // 2. 매개변수 price를 멤버 변수 price에 저장한다.
    //-------------------------------------------------
    Course(string name, int price) {
        //===================
        // 문제 1의 구현
    	this->name = name;
    	this->price = price;
        //===================
    }

    //-------------------------------------------------
    // 문제 2
    // getName() 함수와 getPay() 함수를 구현하라.
    //
    // 조건:
    // 1. getName()은 수강권 이름 name을 반환한다.
    // 2. getPay()는 기본 수강권의 결제 금액 price를 반환한다.
    //-------------------------------------------------
    string getName() {
        //===================
        // 문제 2-1의 구현

        return name;
        //===================
    }

    virtual int getPay() {
        //===================
        // 문제 2-2의 구현

        return price;
        //===================
    }

    //-------------------------------------------------
    // 기본 클래스 포인터로 파생 클래스 객체를 delete할 수 있으므로
    // 소멸자는 virtual로 선언한다.
    //-------------------------------------------------
    virtual ~Course() {
    }
};

//-------------------------------------------------
// 라이브 수강권 클래스 LiveCourse
//-------------------------------------------------
class LiveCourse : public Course {
protected:
    int replayDays;     // 다시보기 일수

public:
    //-------------------------------------------------
    // 문제 3
    // LiveCourse 생성자와 getPay() 함수를 구현하라.
    //
    // 조건:
    // 1. LiveCourse 생성자는 Course 생성자를 명시적으로 호출하여
    //    name과 price를 초기화한다.
    // 2. replayDays를 멤버 변수 replayDays에 저장한다.
    // 3. getPay()는 다음 값을 반환한다.
    //
    //    price + replayDays * 100
    //-------------------------------------------------
    LiveCourse(string name, int price, int replayDays)
        : Course(name, price) {
        //===================
        // 문제 3-1의 구현
    	this->replayDays = replayDays;
        //===================
    }

    int getPay() override {
        //===================
        // 문제 3-2의 구현

        return price + replayDays * 100;
        //===================
    }
};

//-------------------------------------------------
// 프리미엄 수강권 클래스 PremiumCourse
//-------------------------------------------------
class PremiumCourse : public LiveCourse {
private:
    int coupon;     // 쿠폰 할인 금액

public:
    //-------------------------------------------------
    // 문제 4
    // PremiumCourse 생성자를 구현하라.
    //
    // 조건:
    // 1. PremiumCourse 생성자는 LiveCourse 생성자를 명시적으로 호출하여
    //    name, price, replayDays를 초기화한다.
    // 2. coupon을 멤버 변수 coupon에 저장한다.
    //-------------------------------------------------
    PremiumCourse(string name, int price, int replayDays, int coupon)
        : LiveCourse(name, price, replayDays) {
        //===================
        // 문제 4의 구현
    	this->coupon = coupon;
        //===================
    }

    //-------------------------------------------------
    // 문제 5
    // PremiumCourse의 getPay() 함수를 구현하라.
    //
    // 조건:
    // 1. 다음 값을 계산한다.
    //
    //    price + replayDays * 100 - coupon
    //
    // 2. 계산 결과가 0보다 작으면 0을 반환한다.
    // 3. 그렇지 않으면 계산 결과를 반환한다.
    //-------------------------------------------------
    int getPay() override {
        //===================
        // 문제 5의 구현
    	int r = price + replayDays * 100 - coupon;
        if(r < 0){
        	return 0;
        }
        return r;
        //===================
    }
};

//-------------------------------------------------
// 아래 코드는 수정 불가
//-------------------------------------------------
int main() {
    int N;
    cin >> N;

    Course* courses[100];

    for (int i = 0; i < N; i++) {
        char type;
        string name;
        int price;

        cin >> type >> name >> price;

        if (type == 'B') {
            courses[i] = new Course(name, price);
        }
        else if (type == 'L') {
            int replayDays;
            cin >> replayDays;

            courses[i] = new LiveCourse(name, price, replayDays);
        }
        else if (type == 'P') {
            int replayDays;
            int coupon;

            cin >> replayDays >> coupon;

            courses[i] = new PremiumCourse(name, price, replayDays, coupon);
        }
    }

    int total = 0;

    for (int i = 0; i < N; i++) {
        int pay = courses[i]->getPay();

        cout << courses[i]->getName() << " " << pay << endl;

        total += pay;
    }

    cout << "TOTAL " << total << endl;

    for (int i = 0; i < N; i++) {
        delete courses[i];
    }

    return 0;
}
//-------------------------------------------------
// 소스 코드 종료
//-------------------------------------------------
