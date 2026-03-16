//----------------------------------------------------------------------------
// 아래 문제를 해결하는 도중 출력이 잘못되었거나 문제 설명과 출력이 일치하지 않거나 오타가 있거나 등등
// 조금이라도 문제에 이상한 것이 있으면 주저하지 말고 jhshim@chosun.ac.kr로 알려 주시기 바랍니다.
//----------------------------------------------------------------------------

/******************************************************************************
 * 프로젝트 및 소스파일 생성
 ******************************************************************************/
// 이클립스에서 기존의 CH2 프로젝트를 실행하라.
// (즉, 기존과 동일한 workspace(작업공간) 내에서 실행하라.)
// [Project Explorer]에 CH2 프로젝트가 있는 상태에서 아래를 수행하라.
// 1) 메뉴 [File]->[New]->[C/C++ Project] 한 후 새로운 프로젝트 CH3_1을 만들어라.
// 2) 메뉴 [File]->[New]->[Source Folder] 한 후 폴더 이름으로 src를 지정하여 생성하라.
// 3) 메뉴 [File]->[New]->[Source File]한 후 파일 이름으로 ch3_1.cpp를 지정하라.
// 그러면 기존의 CH2 프로젝트와 CH3_1 프로젝트를 동일 이클립스에서 수정하거나 실행할 수 있다.

//-----------------------------------------------------------------------------
// 향후 모든 과제는 위처럼 하나의 이클립스 workspace(작업공간) 내에서
// 모든 프로젝트 파일들을 생성할 예정이다.
//-----------------------------------------------------------------------------

/******************************************************************************
 * 코드 추가 1
 ******************************************************************************/
// 1) 기존에 작성했던 ch2.cpp의 내용을 모두 복사해서 ch3_1.cpp에 삽입하라.
// 2) 프로그램의 맨 앞쪽 주석 부분의 "Author: " 행 다음의 내용을 아래 *로 시작하는 행들로 교체하라.
//----------------------------------------------------------------------------

/*
 * CH2: ch3_1.cpp
 *
 *  Created on: 2026. 3. 15.
 *      Author: 정회윤
 *
 *  + struct Person을 class Person으로 변경
 *  + Person의 멤버 함수들 구현
 *  + UI::inputPerson() 수정
 *  + ClassAndObject 클래스 추가:
 *     객체의 생성 및 소멸,
 *     전역객체, static 객체, 지역객체의 생성 및 소멸 시기
 */

//----------------------------------------------------------------------------
// 3) 기존의 Person 구조체와 이 구조체를 조작하던 모든 함수들(print()부터 init()까지)을
//    삭제하고 아래의 Person 클래스 선언부와 함수 구현부 부분을 새로 복사해서 삽입하라.
// 4) 기존의 namespace UI와 run(), main() 및 자동오류체크 부분은 그대로 남겨 두어라.
//-----------------------------------------------------------------------------
// 주의: 아래 소스 코드들을 복사할 때 /* */와 같은 주석 문장을 함께 복사할 경우 주석 뒤쪽에 있는
//      소스코드의 인덴트(공백을 안으로 밀어 넣어 주는 것)가 4칸이 아니라 2~3칸으로 인덴트가 줄어드는
//      문제가 발생할 수 있다. 이 경우 /* */와 같은 주석을 제외하고 소스코드만 먼저 복사한 후
//      나중에 별도로 /* */만 복사하면 괜찮아질 것이다.
//-----------------------------------------------------------------------------

#include <iostream>
#include <cstring>

using namespace std;  // 헤드 파일은 반드시 이 문장 앞쪽에 include해야 한다.

/******************************************************************************
 * 아래 상수 정의는 필요에 따라 변경하여 사용하라.
 ******************************************************************************/
#define AUTOMATIC_ERROR_CHECK true // true: 자동 오류 체크, false: 키보드에서 직접 입력하여 프로그램 실행

/******************************************************************************
 * Person class
 ******************************************************************************/

class Person
{
    char   name[20];        // 이름
    int    id;              // Identifier
    double weight;          // 체중
    bool   married;         // 결혼여부
    char   address[40];     // 주소

protected:
    void printMembers(ostream* out);

public:
    Person();
    Person(const char *name);
    Person(const char *name, int id, double weight,
           bool married, const char *address);
    ~Person();

    void setName(const char* pname)       { strcpy(name, pname); }
    void setAddress(const char* paddress) {
    	/* TODO: [문제 2] */
    	strcpy(address, paddress);
    }

    void input(istream* pin)  {  }
    void print(ostream* pout) { printMembers(pout); }
    void println()            { print(&cout); cout << endl; }
};

Person::Person(): name{}, id{}, weight{}, married{}, address{} {
    // 위 함수 서두(:와 함수 본체 사이)에서 각 멤버를 초기화하는데 이는 함수 진입하기 전에
    // 각 멤버의 값을 초기화하는 것이다. {}는 각 데이타 타입별로 디폴트 값으로 초기화하라는 의미임.
    // 즉, name[]={'\0'}="", id=0, weight=0.0, married=false, address[]={'\0'}=""
    cout << "Person::Person():"; println();
}

Person::Person(const char *name) : id{}, weight{}, married{}, address{} /* : TODO [문제 2] */ {
    // TODO: [문제 2]
	setName(name);
    cout << "Person::Person(\"" << name << "\"):"; println();
}

Person::Person(const char *name, int id, double weight, bool married,
               const char *address) :
        id{id}, weight{weight}, married{married} {
    // 위에서 각 멤버를 초기화하는 {}는 각 매개변수 값을 객체의 상응하는 멤버에 설정하는 것이다. 즉,
    // this->id=id, this->weight=weight, this->married=married와 동일하다.
    // 여기서 this는 해당 객체를 포인터하는 포인터 변수이며, (다음 장에서 설명될 예정임)
    // this->id는 해당 객체의 멤버 id를 지칭하며 =의 우측변수 id는 함수의 매개변수이다.
    // 값을 간단히 대입하는 것은 위처럼 하면 되지만 name[], address[]와 같은 배열 복사 함수
    // 호출 또는 다른 함수를 호출할 때는 생성자 함수의 몸체 { } 내에서 호출해야 한다.

    // TODO: [문제 2]
    setName(name);
    setAddress(address);
    cout << "Person::Person(...):"; println();
}

Person::~Person() {
    cout << "Person::~Person():"; println();
}

void Person::printMembers(ostream* pout)   {
    // TODO: [문제 1]
	*pout << name << " " << id << " " << weight << " " << married << " :" << address << ":";
}

/******************************************************************************
 * User Interface
 ******************************************************************************/
// 기본적인 입력과 관련된 전역 함수들을 UI라는 이름공간 내부에 정의함

namespace UI {

bool echo_input = false;
string line, emptyLine;

// 입력에서 정수 대신 일반 문자가 입력되었는지 체크하고 에러 발생시 에러 메시지 출력
bool checkInputError(istream* pin, const string msg) {
    if (!(*pin)) { // 에러가 발생했다면
        cout << msg;  // 에러 메시지를 출력
        pin->clear(); // 에러 발생 상태정보를 리셋함; 그래야 다음 문장에서 읽을 수 있음
        getline(*pin, emptyLine); // 에러가 발생한 행 전체를 읽어 데이터를 버림
        return true;
    }
    return false;
}

// 정수나 실수를 입력해야 하는 곳에 일반 문자열을 입력한 경우의 에러 체크
bool checkDataFormatError(istream* pin) {
    return checkInputError(pin, "Input-data format MISMATCHED\n");
}

// 한 사람의 정보 즉, 각 멤버 데이터를 순서적으로 입력 받아 p에 저장하고
// 입력 중 입력 데이터에 오류가 있는지 확인하고 오류가 있을 시 에러 메시지를 출력한다.
bool inputPerson(Person* p) {
    cout << "input person information:" << endl;
    p->input(&cin);
    if (checkDataFormatError(&cin)) return false;
    if (echo_input) p->println(); // 자동체크에서 사용됨
    return true;
}

// 하나의 정수를 입력 받음; 정수가 아닌 아닌 문자열 입력시 에러 메시지 출력 후 재입력 받음
int getInt(const string msg) {
    for (int value; true; ) {
        cout << msg;
        cin >> value;
        if (echo_input) cout << value << endl; // 자동체크 시 출력됨
        if (checkInputError(&cin, "Input an INTEGER.\n"))
            continue;
        getline(cin, emptyLine); // skip [enter] after the number
        return value;
    }
}

// 하나의 양의 정수를 입력 받음; 음수 입력시 에러 메시지 출력 후 재입력 받음
int getPositiveInt(const string msg) {
    int value;
    while ((value = getInt(msg)) < 0)
        cout << "Input a positive INTEGER." << endl;
    return value;
}

// 0~(size-1)사이의 선택된 메뉴 항목 또는 리스트의 항목의 인덱스 값을 리턴함
// 존재하지 않는 메뉴항목을 선택한 경우 에러 출력
int getIndex(const string msg, int size) {
    while (true) {
        int index = getPositiveInt(msg);
        if (0 <= index  && index < size) return index;
        cout << index << ": OUT of selection range(0 ~ "
             << size-1 << ")" << endl;
    }
}

// 사용자에게 메뉴를 보여주고 사용자가 선택한 메뉴항목의 인덱스를 리턴함
int selectMenu(const string menuStr, int menuItemCount) {
    cout << endl << menuStr;
    return getIndex("Menu item number? ", menuItemCount);
}

} // namespace UI

/******************************************************************************
 * ch3_1: Class And Object
 ******************************************************************************/

//Person gps("gps", 1000, 100, true, "gps adress");

class ClassAndObject
{
    void defualConstructor() { // Menu item 1
        Person ps;    // Person::Person() 기본 생성자 및 소멸자 실행
    }

    void constructor() { // Menu item 2: 지역객체의 다양한 생성자 및 소멸자 실행
        Person ps1;
        Person ps2("ps2");
        Person ps3("ps3", 3, 70.3, true, "ps3 address");
    }

    void construcor_destructor_inner_inner() {
    }

    void construcor_destructor_inner() {
    }

    void construcorDestructor() { // Menu item 3
    }

    void global_static_local_objects_inner() {
    }

    void globalStaticLocalObjects() { // Menu item 4
    }

public:
    // 사용자가 선택한 메뉴 항목을 실행하는 멤버 함수(func_arr[menuItem]에 등록된 함수)를 호출
    void run() {
        // ClassAndObject의 멤버 함수에 대한 포인터 타입인 새로운 데이타 타입 func_t를 정의함
        using func_t = void (ClassAndObject::*)();
        // 위 using 문은 ClassAndObject 클래스의 멤버 함수(리턴 타입이 void 이면서 매개변수가 없는)에
        // 대한 포인터 타입을 앞으로는 간단히 func_t로 사용하겠다는 의미이다.

        // ClassAndObject의 멤버 함수 포인터들의 배열
        // 나중에 호출하기 위해 멤버 함수의 이름을 미리 배열에 저장(등록)
        //     함수 이름이 곧 함수에 대한 포인터임: 즉, 함수의 첫번째 명령어의 주소를 저장함
        // 등록된 이 멤버 함수들은 나중에 run()에서 호출됨
        //     (즉, 함수 주소로 jump 해 가서 함수를 실행함)

        func_t func_arr[] = { // 메뉴항목을 실행하는 멤버 함수를 배열에 미리 저장(등록)해 둠
            nullptr, &ClassAndObject::defualConstructor, &ClassAndObject::constructor,
            &ClassAndObject::construcorDestructor, &ClassAndObject::globalStaticLocalObjects,
        };
        int menuCount = sizeof(func_arr) / sizeof(func_arr[0]);
        // func_arr[]의 원소의 개수 = 배열 전체 크기 / 한 배열 원소의 크기

        // 화면에 보여 줄 메뉴
        string menuStr =
            "+++++++++++ Person Class And Object Menu ++++++++++++\n"
            "+ 0.Exit 1.DefualConstructor 2.Constructor          +\n"
            "+ 3.ConstrucorDestructor 4.GlobalStaticLocalObjects +\n"
            "+++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

        while (true) {
            int menuItem = UI::selectMenu(menuStr, menuCount); // 메뉴 번호 입력 받음
            if (menuItem == 0) return;
            (this->*func_arr[menuItem])(); // 선택된 메뉴 항목을 실행할 멤버 함수를 호출함
            /* 위 문장은 다음을 간단히 한 것이다. 앞으로 계속 나올테니 잘 이해하기 바란다.
               func_t f = func_arr[menuItem];// 배열에 저장된 멤버 함수 포인터
               (this->*f)();                 // 멤버함수 포인터를 이용하여 해당 함수를 호출함
            */
        }
    }
}; // ch3_1: class ClassAndObject


/******************************************************************************
 * Main Menu
 ******************************************************************************/

class MainMenu
{
public:
    void run() {
        int menuCount = 2; // 상수 정의
        string menuStr =
"******************************* Main Menu *********************************\n"
"* 0.Exit 1.Class:Object(ch3_1)                                            *\n"
"***************************************************************************\n";

        while (true) {
            int menuItem = UI::selectMenu(menuStr, menuCount);
            if (menuItem == 0) break;

            switch(menuItem) {
            case 1: ClassAndObject().run();           break;
            // 위 ClassAndObject()는 임시객체(이름없는 객체)를 생성하하는 코드이고
            // 이후 바로 해당 객체의 멤버 run()을 호출하고 run()에서 리턴된 후에는 객체 자동 소멸됨
            // 위는 다음과 같다. ClassAndObject tmp; tmp.run();
            }
        }
        cout << "Good bye!!" << endl;
    }
}; // class MainMenu


/******************************************************************************
 * run() 함수
 ******************************************************************************/

void run() {
    MainMenu().run();
    // MainMenu 타입의 이름 없는 임시객체를 생성한 후
    // 그 객체의 run() 멤버함수를 호출함; run()에서 리턴한 후에는 임시객체가 자동 소멸됨
    // 즉, 위 문장은 아래 두 문장과 동일한 기능임
    // MainMenu mm;
    // mm.run();
}

/******************************************************************************
 * Program Test: Automatic Error Check
 ******************************************************************************/
#if AUTOMATIC_ERROR_CHECK
#include "check_error.h"
#endif

/******************************************************************************
 * main() 함수
 ******************************************************************************/
int main() {
    cout << boolalpha;  // 11장에서 배움; bool 타입 값을 0, 1 대신 true, false로 출력하도록 설정
    cin >> boolalpha;   // bool 타입 값을 0, 1 대신 true, false로 입력 받도록 설정

#if AUTOMATIC_ERROR_CHECK
    evaluate(true);   // 각 문제에 대해 단순히 O, X만 확인하고자 할 때는 false
#else
    run();
#endif
}

// //-----------------------------------------------------------------------------
// // ch3_1.cpp 소스 끝
// //-----------------------------------------------------------------------------

/******************************************************************************
 * 초기 프로그램 실행
 ******************************************************************************/
// 1) ch3_1.cpp을 저장하라.(Ctrl+S)
// 2) 컴파일한 후 실행파일을 만들어라. (메뉴 [Project] -> [Build Project])
//    Debug 폴더가 만들어지고 그 밑에 src 폴더가 만들어지고 그 밑에
//    정상적으로 컴파일된 경우 ch3_1.o가 생성되고
//    그리고 Debug 폴더 밑에 ch3_1.exe가 생성됨 (PC Windows의 경우)
//    (실행 파일 이름은 PC Windows의 경우 .exe로 끝나고 Linux Ubuntu일 경우 확장자가 없음)
// 3. 반드시 실행파일이 생성되었는지 확인한 후 프로그램을 실행해야 한다. 프로그램을 실행할 때는
//    툴바에서 오른쪽으로 누운 초록색의 삼각형 버튼을 누르거나 또는 Ctrl+F11 또는 메뉴 [Run] -> [Run]
//    (처음에 한번은 "Local C/C++ Appication"를 선택해 주어야 함)
// 4) 프로그램의 실행결과는 아래와 같다.
//-----------------------------------------------------------------------------
// 주의: C++ 컴파일러가 C++11(2011년 제정 표준 스펙)을 지원하지 않으면 컴파일 에러가 발생할 수 있음
//      이 경우 최신버전 컴파일러를 설치하기 바랍니다.
//-----------------------------------------------------------------------------

// ===============================================================================
// == 초기 프로그램 실행 결과
// ===============================================================================

// ******************************* Main Menu *********************************
// * 0.Exit 1.Class:Object(ch3_1)                                            *
// ***************************************************************************
// Menu item number? 1

// +++++++++++ Person Class And Object Menu ++++++++++++
// + 0.Exit 1.DefualConstructor 2.Constructor          +
// + 3.ConstrucorDestructor 4.GlobalStaticLocalObjects +
// +++++++++++++++++++++++++++++++++++++++++++++++++++++
// Menu item number? 1 // 실행하는 내용이 없다.

// +++++++++++ Person Class And Object Menu ++++++++++++
// + 0.Exit 1.DefualConstructor 2.Constructor          +
// + 3.ConstrucorDestructor 4.GlobalStaticLocalObjects +
// +++++++++++++++++++++++++++++++++++++++++++++++++++++
// Menu item number? 2

// +++++++++++ Person Class And Object Menu ++++++++++++
// + 0.Exit 1.DefualConstructor 2.Constructor          +
// + 3.ConstrucorDestructor 4.GlobalStaticLocalObjects +
// +++++++++++++++++++++++++++++++++++++++++++++++++++++
// Menu item number? 0

// ******************************* Main Menu *********************************
// * 0.Exit 1.Class:Object(ch3_1)                                            *
// ***************************************************************************
// Menu item number? 0
// Good bye!!

// /******************************************************************************
//  * 프로그램 테스트를 위한 입출력 파일 다운로드
//  ******************************************************************************/
// // 1. clc.chosun.ac.kr의 [강의자료실]에서 CH3_1 과제와 관련된 테스트용 파일을 다운받는다.
// // 2. 압축파일을 풀면 test라는 폴더가 생성되고 그 밑에 .in 또는 .out 파일이 존재할 것이다.
// // 3. 해당 test 폴더를 드래깅하여 이클립스의 [Project Explorer]의 [CH3_1] 프로젝트 위에 드랍한다.
// // 4. 그러면 CH3_1 프로젝트 밑에 기존의 Debug와 src 외에 test 폴더가 새로 생성되어 복사될 것이다.
// // 5. 이 test 폴더를 펼치면 다양한 입력용 파일 .in과 출력용 .out 파일이 존재함을 확인할 수 있다.

// /******************************************************************************
//  * 자동 오류 체크를 위한 check_error.h 추가
//  ******************************************************************************/
// // 1. 기존 프로젝트 CH2의 src 폴드에 있는 check_error.h를 CH3_1 프로젝트의 src 폴더로 복사하라.
// //    즉, CH2/src 폴드의 check_error.h를 선택하여 [Ctrl+C]한 후 CH3_1/src 폴더를 선택하고
// //    [Ctrl+V]하라. 또는 마우스로 CH2/src의 check_error.h를 선택한 후 드래깅하여
// //    CH3_1/src 폴더 위에서 Ctrl를 누른상태에서 드랍한다. (이때 복사 옵션을 선택하라).

// /******************************************************************************
//  * 자동 오류 체크 실행
//  ******************************************************************************/
// // 프로그램 맨 앞쪽의 AUTOMATIC_ERROR_CHECK를 true로 설정하고
// // main() 함수 내에서 evaluate()의 인자를 false로 설정하라.
// // 그러면 오류가 발생한 곳의 상세한 위치 출력은 생략하고 단순히 O, X로만 표시해 줄 것이다.
// //-----------------------------------------------------------------------------

// int main() {
// #if AUTOMATIC_ERROR_CHECK
//     evaluate(false);   // 각 문제에 대해 단순히 O, X만 확인하고자 할 때는 false
// #else
//     run();
// #endif
// }

// ===============================================================================
// == 자동 오류 체크 초기 실행 결과
// == 현재 구현된 것이 없기 때문에 모두 X가 출력된다.
// ===============================================================================
// test 1 : X
// test 2 : X
// test 3 : X
// test 4 : X
// Good bye!!

// //-----------------------------------------------------------------------------
// // 주의: 확인이 되었으면 AUTOMATIC_ERROR_CHECK를 다시 false로 설정하고
// //      evaluate(false)를 evaluate(true)로 복구하라.
// //      아래 각 문제를 해결할 때마다 AUTOMATIC_ERROR_CHECK true, evaluate(true)로
// //      설정하고 실행하여 현재 문제를 정확히 구현했는지 바로 확인한 후 그 다음 문제로 넘어가도 된다.
// //-----------------------------------------------------------------------------

// /******************************************************************************
//  * 실행중인 프로그램 강제 종료
//  ******************************************************************************/
// // 참고로 프로그램 실행 중 오류가 있어 종료가 되지 않고 응답이 없거나 또는 프로그램 실행 중에
// // 프로그램을 강제로 종료하고자 할 경우 [Console] 창 타이틀 바 부분에 [빨간 사각형 아이콘]이
// // 있는데 이를 누르면 프로그램이 강제 종료된다. 이 아이콘이 [빨간색]이면 프로그램 [실행 중]이고
// // [회색]이면 [종료]되었음을 의미한다
// //-----------------------------------------------------------------------------

// /******************************************************************************
//  * 문제 1
//  ******************************************************************************/
// // ch2.cpp의 print() 함수의 내용을 복사해서 printMembers(ostream* pout) { }에
// // 추가하라. cout 대신에 매개변수인 pout을 활용하고, 기존의 p->는 모두 제거하라.
// // pout은 ostream* 포인터 변수인데 println()에서 print() 호출 시 &cout을 넘겨 준다.
// // 따라서 기존 코드 중에 cout은 매개변수 *pout과 동일하므로 *pout << ...로 하면 된다.
// //-----------------------------------------------------------------------------
// // 기존 defualConstructor() 함수를 아래 함수로 교체하라.
// //-----------------------------------------------------------------------------

//     void defualConstructor() { // Menu item 1
//         Person ps;    // Person::Person() 기본 생성자 및 소멸자 실행
//     }

// ===============================================================================
// == 문제 1 실행 결과
// == 아래와 같이 출력되지 않았다면 printMembers(ostream* pout) 함수를 점검하라.
// ===============================================================================
// ... // 생략
// +++++++++++ Person Class And Object Menu ++++++++++++
// + 0.Exit 1.DefualConstructor 2.Constructor          +
// + 3.ConstrucorDestructor 4.GlobalStaticLocalObjects +
// +++++++++++++++++++++++++++++++++++++++++++++++++++++
// Menu item number? 1
// Person::Person(): 0 0 false ::     // 이름과 주소가 ""임
// Person::~Person(): 0 0 false ::
// ... // 생략

// /******************************************************************************
//  * 문제 2
//  ******************************************************************************/
// // 1) Person의 멤버함수 setName()을 참조하여 setAddress()을 구현하라.
// //    즉, 문자열 매개변수 paddress를 클래스 멤버 변수 address로 복사하라.
// // 2) Person::Person(const char *name) 생성자의 id, weight, married, address 멤버의
// //    초기화는 기존 Person::Person()를 참고하여 동일하게 초기화하라.
// //    단, name 멤버의 경우 생성자의 함수 몸체 { } 내에서 setName()을 호출하여 초기화하라.
// // 3) Person::Person(const char *name, int id, ... ) 생성자의 경우 id, weight,
// //    married 멤버를 초기화하는 것은 이미 구현되어 있다. name과 address 멤버의 경우
// //    이 생성자의 함수 몸체 { } 내에서 setName()과 setAddress()를 호출하여 초기화하라.
// //-----------------------------------------------------------------------------
// // 기존 constructor() 함수를 아래 함수로 교체하라.
// //-----------------------------------------------------------------------------

//     void constructor() { // Menu item 2: 지역객체의 다양한 생성자 및 소멸자 실행
//         Person ps1;
//         Person ps2("ps2");
//         Person ps3("ps3", 3, 70.3, true, "ps3 address");
//     }

// ===============================================================================
// == 문제 2 실행 결과
// ===============================================================================
// ...
// +++++++++++ Person Class And Object Menu ++++++++++++
// + 0.Exit 1.DefualConstructor 2.Constructor          +
// ...
// Menu item number? 2
// Person::Person(): 0 0 false ::
// Person::Person("ps2"):ps2 0 0 false ::
// Person::Person(...):ps3 3 70.3 true :ps3 address:
// Person::~Person():ps3 3 70.3 true :ps3 address:
// Person::~Person():ps2 0 0 false ::
// Person::~Person(): 0 0 false ::
// ...


// /******************************************************************************
//  * 문제 3
//  ******************************************************************************/
// // 기존 construcorDestructor() 관련 함수들을 아래 함수로 교체하라.
// //-----------------------------------------------------------------------------

//     void construcor_destructor_inner_inner() {
//         cout << "\n--- construcor_destructor_inner_inner() begins ---" << endl;
//         Person ps3("ps3");
//         cout << "\n- if begins -" << endl;
//         if (true) {
//             Person ps4("ps4");
//         }
//         cout << "- if ends -\n" << endl;
//         cout << "- temporary object begins -" << endl;
//         Person("temp_ps_1"); // 임시객체(이름 없는 객체) 성성 및 소멸
//         cout << endl;
//         Person("temp_ps_2").setName("TEMP_PS_2"); // 임시객체 생성,
//                                                   // setName() 호출, 임시객체 소멸
//         cout << "- temporary object ends -\n" << endl;
//         Person ps5("ps5");
//     }

//     void construcor_destructor_inner() {
//         cout << "\n--- construcor_destructor_inner() begins ---" << endl;
//         Person ps2("ps2");
//         construcor_destructor_inner_inner();
//         cout << "--- construcor_destructor_inner_inner() returned ---\n" << endl;
//         Person ps6("ps6");
//     }

//     void construcorDestructor() { // Menu item 3
//         Person ps1("ps1");
//         construcor_destructor_inner();
//         cout << "--- construcor_destructor_inner() returned ---\n" << endl;
//     }

// ===============================================================================
// == 문제 3 실행 결과
// == ----------------------------------------------------------------------------
// == 실행 결과를 통해 함수들이 충첩해서 계속 호출될 때
// == 언제 각 객체의 생성자가 호출되고 언제 자동으로 소멸되는지를 정확히 인지하기 바란다.
// ===============================================================================
// ...
// Menu item number? 3
// Person::Person("ps1"):ps1 0 0 false ::

// --- construcor_destructor_inner() begins ---
// Person::Person("ps2"):ps2 0 0 false ::

// --- construcor_destructor_inner_inner() begins ---
// Person::Person("ps3"):ps3 0 0 false ::

// - if begins -
// Person::Person("ps4"):ps4 0 0 false ::
// Person::~Person():ps4 0 0 false ::
// - if ends -

// - temporary object begins -
// Person::Person("temp_ps_1"):temp_ps_1 0 0 false ::
// Person::~Person():temp_ps_1 0 0 false ::

// Person::Person("temp_ps_2"):temp_ps_2 0 0 false ::
// Person::~Person():TEMP_PS_2 0 0 false ::
// - temporary object ends -

// Person::Person("ps5"):ps5 0 0 false ::
// Person::~Person():ps5 0 0 false ::
// Person::~Person():ps3 0 0 false ::
// --- construcor_destructor_inner_inner() returned ---

// Person::Person("ps6"):ps6 0 0 false ::
// Person::~Person():ps6 0 0 false ::
// Person::~Person():ps2 0 0 false ::
// --- construcor_destructor_inner() returned ---

// Person::~Person():ps1 0 0 false ::
// ...

// /******************************************************************************
//  * 문제 4
//  ******************************************************************************/
// // ClassAndObject 클래스 선언 위쪽의 전역 객체 gps의 주석을 아래처럼 풀어라.
// //-----------------------------------------------------------------------------

// Person gps("gps", 1000, 100, true, "gps adress");

// class ClassAndObject { ... }

// //-----------------------------------------------------------------------------
// // 기존 globalStaticLocalObjects() 관련 함수들을 아래 함수로 교체하라.
// //-----------------------------------------------------------------------------

//     void global_static_local_objects_inner() {
//         cout << "\n--- global_static_local_objects_inner() begins ---" << endl;
//         static Person sps("sps", 2000, 200, false, "sps adress");
//     }

//     void globalStaticLocalObjects() { // Menu item 4
//         global_static_local_objects_inner();
//         cout << "--- global_static_local_objects_inner() returned ---" << endl;
//         global_static_local_objects_inner();
//         cout << "--- global_static_local_objects_inner() returned ---" << endl;
//     }

// ===============================================================================
// == 문제 4 실행 결과
// ===============================================================================
// // 아래 실행 결과에서 main()이 실행하기 전에 전역 객체 gps의 생성자가 먼저 실행되어 초기화된다.
// // 그 후 global_static_local_objects_inner()가 처음 호출될 때 static 객체인 sps의 생성자가
// // 딱 한번만 호출된다. 두번째 global_static_local_objects_inner()가 호출될 때는
// // sps의 생성자가 실행되지 않음을 확인할 수 있다.
// // sps 및 gps와 같은 전역 및 static 객체는 main() 함수가 리턴된 후 소멸자가 호출된다.
// // 생성자가 호출되는 역순으로 소멸자가 호출된다.
// //-----------------------------------------------------------------------------

// Person::Person(...):gps 1000 100 1 :gps adress:  // main() 호출이전에 전역객체 초기화
//                             // 아직 main()이 실행 전이라 married가 true가 아닌 1로 출력됨

// ******************************* Main Menu *********************************
// * 0.Exit 1.Class:Object(ch3_1)                                            *
// ***************************************************************************
// Menu item number? 1

// +++++++++++ Person Class And Object Menu ++++++++++++
// + 0.Exit 1.DefualConstructor 2.Constructor          +
// + 3.ConstrucorDestructor 4.GlobalStaticLocalObjects +
// +++++++++++++++++++++++++++++++++++++++++++++++++++++
// Menu item number? 4

// --- global_static_local_objects_inner() begins ---
// Person::Person(...):sps 2000 200 false :sps adress:   // 처음 호출할 때만 sps 초기화함
// --- global_static_local_objects_inner() returned ---

// --- global_static_local_objects_inner() begins --- //두번째 호출에서는 sps 초기화하지 않음
// --- global_static_local_objects_inner() returned ---

// +++++++++++ Person Class And Object Menu ++++++++++++
// + 0.Exit 1.DefualConstructor 2.Constructor          +
// + 3.ConstrucorDestructor 4.GlobalStaticLocalObjects +
// +++++++++++++++++++++++++++++++++++++++++++++++++++++
// Menu item number? 0

// ******************************* Main Menu *********************************
// * 0.Exit 1.Class:Object(ch3_1)                                            *
// ***************************************************************************
// Menu item number? 0
// Good bye!!                            // main()에서 리턴한 후 전역객체와 static 객체 소멸
// Person::~Person():sps 2000 200 false :sps adress:
// Person::~Person():gps 1000 100 true :gps adress:


// /******************************************************************************
//  * 문제 4-1
//  ******************************************************************************/
// // 1) 위 문제 4의 실행결과를 확인한 후 전역변수 gps를 아래처럼 주석처리하라.
// //Person gps("gps", 1000, 100, true, "gps adress");

// // 2) static 변수 sps를 아래처럼 주석처리하라.
//     void global_static_local_objects_inner() {
//         cout << "\n--- global_static_local_objects_inner() begins ---" << endl;
//         //static Person sps("sps", 2000, 200, false, "sps adress");
//     }

// //-----------------------------------------------------------------------------
// // 경고: 자동 오류 체크 시 또는 oj 시스템에 프로그램 제출 시 위처럼 계속 주석처리 되어 있어야 한다.
// //-----------------------------------------------------------------------------

// ===============================================================================
// == 문제 4-1 실행 결과
// ==============================================================================
// ...
// Menu item number? 4

// --- global_static_local_objects_inner() begins ---
// --- global_static_local_objects_inner() returned ---

// --- global_static_local_objects_inner() begins ---
// --- global_static_local_objects_inner() returned ---

// +++++++++++ Person Class And Object Menu ++++++++++++
// + 0.Exit 1.DefualConstructor 2.Constructor          +
// + 3.ConstrucorDestructor 4.GlobalStaticLocalObjects +
// +++++++++++++++++++++++++++++++++++++++++++++++++++++
// Menu item number? 0

// ******************************* Main Menu *********************************
// * 0.Exit 1.Class:Object(ch3_1)                                            *
// ***************************************************************************
// Menu item number? 0
// Good bye!!


// /******************************************************************************
//  * 자동 오류 체크 모드로 프로그램 실행
//  ******************************************************************************/
// // 1. 소스 파일 맨 앞쪽에 있는 AUTOMATIC_ERROR_CHECK 상수 값을 아래처럼 true로 설정하라.
// #define AUTOMATIC_ERROR_CHECK true

// // 2. main() 함수 내의 evaluate()를 true로 설정하라.
//     evaluate(true);   // 각 문제에 대해 단순히 O, X만 확인하고자 할 때는 false

// // 3. 문제 4-1에서 기술한 전역 gps 객체와 static sps 객체를 주석 처리했는지 확인하라.

// //Person gps("gps", 1000, 100, true, "gps adress");
//         //static Person sps("sps", 2000, 200, false, "sps adress");

// // 프로그램이 정상적으로 구현되었다면 아래 [프로그램 실행 결과]와 같이 출력될 것이다.

// ===============================================================================
// == 1. 정상적인 프로그램 실행 결과
// ===============================================================================
// test 1 : O
// test 2 : O
// test 3 : O
// test 4 : O
// Good bye!!

// ===============================================================================
// == 2. 비정상적인 경우의 프로그램 실행방법은 CH2의 실습과제 설명의 마지막 부분을 참조하기 바란다.
// ===============================================================================

// /******************************************************************************
//  * 프로그램 제출
//  ******************************************************************************/
// // 1. 중요: ch3_1.cpp 소스 파일 맨 앞쪽에 있는 AUTOMATIC_ERROR_CHECK 상수 값을
// //         다시 false로 변경한 후 저장하라.
// //         oj 시스템에서는 AUTOMATIC_ERROR_CHECK 값이 true으로 설정되어 있으면
// //         프로그램이 정상적으로 실행되지 않는다.
// //-----------------------------------------------------------------------------
// // 2. 문제 4-1에서 기술한 전역 gps 객체와 static sps 객체를 주석 처리했는지 확인하라.
// //-----------------------------------------------------------------------------
// // 3. 프로그램을 oj.chosun.ac.kr에 제출하라.
// //-----------------------------------------------------------------------------
