//----------------------------------------------------------------------------
// 아래 문제를 해결하는 도중 출력이 잘못되었거나 문제 설명과 출력이 일치하지 않거나 오타가 있거나 등등
//----------------------------------------------------------------------------
// 조금이라도 문제에 이상한 것이 있으면 주저하지 말고 jhshim@chosun.ac.kr로 알려 주시기 바랍니다.

/******************************************************************************
 * 코드 추가 1
 ******************************************************************************/
// 1) 메뉴 [File]->[New]->[C/C++ Project] 한 후 새로운 프로젝트 CH2을 만들어라.
// 2) 메뉴 [File]->[New]->[Source Folder] 한 후 폴더 이름으로 src를 지정하여 생성하라.
// 3) 메뉴 [File]->[New]->[Source File]   한 후 폴더 이름으로는 위에서 지정한 CH2/src로 설정하고
//    파일 이름으로 ch2.cpp를 지정하여 소스파일을 만든 후 아래 코드들을([프로그램 실행] 앞까지) 삽입하라.
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// 주의: 아래 소스 코드들을 복사할 때 /* */와 같은 주석 문장을 함께 복사할 경우 주석 뒤쪽에 있는
//      소스코드의 인덴트(공백을 안으로 밀어 넣어 주는 것)가 4칸이 아니라 2~3칸으로 인덴트가 줄어드는
//      문제가 발생할 수 있다. 이 경우 /* */와 같은 주석을 제외하고 소스코드만 먼저 복사한 후
//      나중에 별도로 /* */만 복사하면 괜찮아질 것이다.
//-----------------------------------------------------------------------------

/*
 * CH2: ch2.cpp
 *
 *  Created on: 2026. 3. 10.
 *      Author: 정회윤
 *
 *  1) struct Person 추가
 *  2) namespace UI에 기본적인 입력 함수 추가
 *  3) Person 객체를 조작하는 다양한 test 함수들
 *
 */

//-----------------------------------------------------------------------------
// 주의: 아래 헤드 파일을 include하는 < > 표시가 oj 시스템에서 HTML tag로 잘못 인식되기 때문에
//      아래와 같이 스페이스로 분리하였다. 그렇지만 실제 프로그램 소스에서는 붙여서 표기하기 바란다.
//-----------------------------------------------------------------------------
#include <iostream>
#include <cstring>

using namespace std;  // 헤드 파일은 반드시 이 문장 앞쪽에 include해야 한다.

/******************************************************************************
 * 아래 상수 정의는 필요에 따라 변경하여 사용하라.
 ******************************************************************************/
#define AUTOMATIC_ERROR_CHECK false // true: 자동 오류 체크, false: 키보드에서 직접 입력하여 프로그램 실행

/******************************************************************************
 * Person structure and its manipulation functions
 ******************************************************************************/

struct Person {
    char   name[20];        // 이름
    int    id;              // Identifier
    double weight;          // 체중
    bool   married;         // 결혼여부
    char   address[50];     // 주소
};

void print(Person* p) {
    // TODO: [문제 1]
	cout << p->name << " " << p->id << " " << p->weight << " " << p->married << " :" << p->address << ":";
}

void println(Person* p) {
    // TODO: [문제 1]
	print(p);
	cout << endl;
}

void input(Person* p) {
    // TODO: [문제 9]
	cin >> p->name >> p->id >> p->weight >> p->married;

	if(!cin){
		return;
	}

	cin.getline(p->address, sizeof(p->address), ':');
	cin.getline(p->address, sizeof(p->address), ':');
}

bool isSame(const Person* p, const char* pname, int pid) {
    // TODO: [문제 5]
	if(strcmp(p->name, pname) == 0 && p->id == pid){
		return true;
	}
    return false; // 이 문장을 삭제하고 새로 구현하라.
}

void whatAreYouDoing(Person* p) {
    // TODO: [문제 6]
	cout << p->name << "is taking a rest." << endl;
}

void init(Person* p, const char *pname, int pid, double pweight,
          bool pmarried, const char *paddress) {
    strcpy(p->name,  pname);
    p->id = pid;
    // TODO: [문제 2]
    p->weight = pweight;
    p->married = pmarried;
    strcpy(p->address, paddress);
    cout << "init("; print(p); cout << ")" << endl;
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
    input(p); // p-name 100 65 true :426 hakdong-ro, Gangnam-gu, Seoul:
    if (checkDataFormatError(&cin)) return false;
    if (echo_input) println(p); // 자동체크에서 사용됨
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
 * simple test
 ******************************************************************************/

Person p = { "Hong", 1, 61.1, true, "Seoul Jongno-gu Nam-ro 123" };

void printlnTest() { // Menu item 1
    // 디폴트 값으로 초기화, 즉 모든 멤버 값을 0으로 초기화함
    Person p1 = {}; // 또는 Person p{};
    println(&p1);
    // 위 p1을 Person p1;으로 선언해 놓고 p1을 출력해 보라. 아마 초기화가 되어 있지 않을 것이다.

    // 구조체의 각 멤버 초기화
    Person p2 = { "LeeSoonShin", 0, 70.1, true, "Gangnam Seoul" };
    println(&p2);

    Person p3{ "Hong,gildong", 1, 60.2, false, "Jongno-gu, Busan" };
    println(&p3);

    println(&p);
}
void initTest() { // Menu item 2
    Person u1;
    init(&u1, "u1", 10, 60.0, false, "Jongno-gu, Seoul");
    Person u2;
    init(&u2, "u2", p.id, p.weight, p.married, p.address);
    println(&p);
}
void getter() { // Menu item 3
	cout << "name:" << p.name << ", id:" << p.id << ", weight:" << p.weight
    << ", married:" << p.married << ", address:" << p.address << endl;
}
void setter() { // Menu item 4
    Person u;
    strcpy(u.name, "u");
    u.id = p.id;
    u.weight = p.weight;
    u.married = p.married;
    strcpy(u.address, p.address);
    //TODO: p의 weight, married, address 값들을 u의 상응하는 멤버에 저장하라.

    println(&u);
}
void isSameTest() {// Menu item 5
    println(&p);
    Person u = { "Hong", 1, };
    cout << "p.isSame(): " << isSame(&p, u.name, u.id) << endl;
}
void whatAreYouDoingTest() { // Menu item 6
    whatAreYouDoing(&p);
}
void noBoolAlphaOutput() { // Menu item 7
    // married 멤버 값 또는 bool 값이 1, 0로 출력됨
    printlnTest();
    initTest();
    getter();
    setter();
    isSameTest();
    whatAreYouDoingTest();
}
void   boolAlphaOutput() { // Menu item 8
    cout << boolalpha;    // married 멤버 값 또는 bool 값이 true, false로 출력되도록 설정
    noBoolAlphaOutput();
    cout << noboolalpha;  // 원래 상태로 복구함
}
void noBoolAlphaInputPerson() { // Menu item 9
    // married 멤버 값 또는 bool 값을 0 또는 1로 입력
    // HongGilDong 0 71.5 1 :Gwangju Nam-gu Bongseon-dong 21:
    if (UI::inputPerson(&p)) // 입력시 정수 또는 실수 값을 일반 문자로 잘못 입력하지 않은 경우
        println(&p);
}
void   boolAlphaInputPerson() { // Menu item 10
    cout << boolalpha;
    // 아래는 married 멤버 값 또는 bool 값을 true 또는 false로 입력받도록 설정
    cin  >> boolalpha;
    // 아래 입력 인적정보에서 married 멤버 값이 1이 아닌 true임
    // Hong 1 71.5 true :Gwangju Nam-gu Bongseon-dong 21:
    if (UI::inputPerson(&p))  // 입력시 정수 또는 실수 값을 일반 문자로 잘못 입력하지 않은 경우
        println(&p);
    cin  >> noboolalpha; // 원래 상태로 복구함
    cout << noboolalpha; // 원래 상태로 복구함
}
void dataTypeSize() { // Menu item 11
    cout << "bool   size: " << sizeof(bool)   << endl;
    cout << "char   size: " << sizeof(char)   << endl;
    cout << "short  size: " << sizeof(short)  << endl;
    cout << "int    size: " << sizeof(int)    << endl;
    cout << "long   size: " << sizeof(long)   << endl;
    cout << "float  size: " << sizeof(float)  << endl;
    cout << "double size: " << sizeof(double) << endl;
    cout << "int*   size: " << sizeof(int*)   << endl;
}

/******************************************************************************
 * run() 함수
 ******************************************************************************/

void run() {
    int menuCount = 12; // 상수 정의
    // 화면에 보여 줄 메뉴
    string menuStr =
    "+++++++++++++++++++++ Person Structure Test Menu +++++++++++++++++++++\n"
    "+ 0.Exit 1.printlnTest 2.initTest 3.getter 4.setter 5.isSameTest     +\n"
    "+ 6.whatAreYouDoingTest 7.NoBoolAlphaOutput 8.BoolAlphaOutput        +\n"
    "+ 9.NoBoolAlphaInputPerson 10.BoolAlphaInputPerson 11.DataTypeSize() +\n"
    "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

    while (true) {
        int menuItem = UI::selectMenu(menuStr, menuCount);
        if (menuItem == 0) break;

        switch(menuItem) {
        case 1: printlnTest();            break;
        case 2: initTest();               break;
        case 3: getter();                 break;
        case 4: setter();                 break;
        case 5: isSameTest();             break;
        case 6: whatAreYouDoingTest();    break;
        case 7: noBoolAlphaOutput();      break;
        case 8:   boolAlphaOutput();      break;
        case 9: noBoolAlphaInputPerson(); break;
        case 10:  boolAlphaInputPerson(); break;
        case 11: dataTypeSize();          break;
        }
    }
    cout << "Good bye!!" << endl;
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
#if AUTOMATIC_ERROR_CHECK
    evaluate(true);            // 함수 호출
#else
    run();
#endif
}

// //-----------------------------------------------------------------------------
// // ch2.cpp 소스 끝
// //-----------------------------------------------------------------------------

// /******************************************************************************
//  * 프로그램 실행
//  ******************************************************************************/
// // 1. ch2.cpp을 저장하라.(Ctrl+S)
// // 2. 컴파일한 후 실행파일을 만들어라.
// //     메뉴 [Project] -> [Build Project]
// //     Debug 폴더가 만들어지고 그 밑에 src 폴더가 만들어지고 그 밑에 
// //     정상적으로 컴파일된 경우 ch2.o가 생성된다.
// //     그리고 Debug 폴더 밑에는 실행파일인 ch2.exe가 생성됨 (PC Windows의 경우)
// //     (실행 파일 이름은 PC Windows의 경우 .exe로 끝나고 Linux Ubuntu일 경우 확장자가 없음)
// // 3. 반드시 실행파일이 생성되었는지 확인한 후 프로그램을 실행해야 한다. 프로그램을 실행할 때는
// //    툴바에서 오른쪽으로 누운 초록색의 삼각형 버튼을 누르거나 또는 Ctrl+F11 또는 메뉴 [Run] -> [Run]
// //    (프로그램 실행 시 처음 한번은 "Local C/C++ Appication"를 선택해 주어야 함)
// // 4. 프로그램의 실행결과는 아래와 같다.
// //-----------------------------------------------------------------------------

// ===============================================================================
// == 초기 프로그램 실행 결과
// =============================================================================== 

// +++++++++++++++++++++ Person Structure Test Menu +++++++++++++++++++++
// + 0.Exit 1.printlnTest 2.initTest 3.getter 4.setter 5.isSameTest     +
// + 6.whatAreYouDoingTest 7.NoBoolAlphaOutput 8.BoolAlphaOutput        +
// + 9.NoBoolAlphaInputPerson 10.BoolAlphaInputPerson 11.DataTypeSize() +
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Menu item number? -1[엔터] // 사용자 직접 입력
// Input a positive INTEGER.
// Menu item number? 12 // 사용자 직접 입력 
// 12: OUT of selection range(0 ~ 11)
// Menu item number? abc3 // 사용자 직접 입력
// Input an INTEGER.
// Menu item number? 1 // 사용자 직접 입력

// +++++++++++++++++++++ Person Structure Test Menu +++++++++++++++++++++
// + 0.Exit 1.printlnTest 2.initTest 3.getter 4.setter 5.isSameTest     +
// + 6.whatAreYouDoingTest 7.NoBoolAlphaOutput 8.BoolAlphaOutput        +
// + 9.NoBoolAlphaInputPerson 10.BoolAlphaInputPerson 11.DataTypeSize() +
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Menu item number? 2 // 사용자 직접 입력

// +++++++++++++++++++++ Person Structure Test Menu +++++++++++++++++++++
// + 0.Exit 1.printlnTest 2.initTest 3.getter 4.setter 5.isSameTest     +
// + 6.whatAreYouDoingTest 7.NoBoolAlphaOutput 8.BoolAlphaOutput        +
// + 9.NoBoolAlphaInputPerson 10.BoolAlphaInputPerson 11.DataTypeSize() +
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Menu item number? 0 // 사용자 직접 입력
// Good bye!!


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
// // [문제 1 실행 결과]처럼 출력되도록 print()와 println() 함수를 구현하라.

// 1) print(Person* p)
//     p가 포인하는 구조체의 각 멤버를 [문제 1 실행 결과]와 동일하게 출력하라. 
//     출력형식은 아래와 같다. 
//           이름 id 체중 결혼여부 :주소:
//     // 예) LeeSoonShin 0 70.1 1 :Gangnam Seoul:
//     // 주소의 시작과 끝에는 ":"를 출력한다. 
//     // (주소가 여러 단어로 구성되므로 ":"를 주소 구분자로 사용함)
//     // 출력결과에서 bool 타입인 married는 1 또는 0으로 출력된다는 것을 주지하라.
//     // 이후 문제에서 이를 true 또는 false로 출력되게 변경할 것이다.
//     // print(Person* p)는 멤버들만 출력하고 줄바꾸기(endl)는 출력하지 않는다.

// 2) prinln(Person* p)
//     print()를 호출하여 멤버들을 모두 출력한다.
//     그 후 endl 조작자를 이용하여 줄바꾸기를 출력하라.

// //-----------------------------------------------------------------------------
// // 기존 printlnTest() 함수를 아래 함수로 교체하라.
// //-----------------------------------------------------------------------------

// void printlnTest() { // Menu item 1
//     // 디폴트 값으로 초기화, 즉 모든 멤버 값을 0으로 초기화함
//     Person p1 = {}; // 또는 Person p{};
//     println(&p1);   
//     // 위 p1을 Person p1;으로 선언해 놓고 p1을 출력해 보라. 아마 초기화가 되어 있지 않을 것이다.

//     // 구조체의 각 멤버 초기화
//     Person p2 = { "LeeSoonShin", 0, 70.1, true, "Gangnam Seoul" };
//     println(&p2);

//     Person p3{ "Hong,gildong", 1, 60.2, false, "Jongno-gu, Busan" };
//     println(&p3);

//     println(&p);
// }

// ===============================================================================
// == 문제 1 실행 결과
// =============================================================================== 

// +++++++++++++++++++++ Person Structure Test Menu +++++++++++++++++++++
// + 0.Exit 1.printlnTest 2.initTest 3.getter 4.setter 5.isSameTest     +
// + 6.whatAreYouDoingTest 7.NoBoolAlphaOutput 8.BoolAlphaOutput        +
// + 9.NoBoolAlphaInputPerson 10.BoolAlphaInputPerson 11.DataTypeSize() +
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Menu item number? 1
//  0 0 0 ::                            // 이름과 주소는 "" 문자열(빈 문자열)임
// LeeSoonShin 0 70.1 1 :Gangnam Seoul:
// Hong,gildong 1 60.2 0 :Jongno-gu, Busan:
// Hong 1 61.1 1 :Seoul Jongno-gu Nam-ro 123:

// ... // 메뉴 생략

// /******************************************************************************
//  * 문제 2
//  ******************************************************************************/
// // [문제 2 실행 결과]를 참고하여 init(...) 함수를 구현하라.

// init(p, ...)
//     p가 포인하는 구조체의 각 멤버를 함수의 상응하는 매개변수 값으로 초기화하라.
//     p의 멤버 name과 id의 설정은 이미 구현되어 있으며 이를 참조하여 나머지 멤버도 값을 초기화하라.
//     구조체 멤버 address도 name과 동일한 방법으로 매개변수 paddress의 내용을 복사해서 초기화하라.
//     (strcpy() 사용법은 https://www.cplusplus.com/reference/을 검색해서 예문을 참조하라.)

// //-----------------------------------------------------------------------------
// // 기존 initTest() 함수를 아래 함수로 교체하라.
// //-----------------------------------------------------------------------------

// void initTest() { // Menu item 2
//     Person u1;
//     init(&u1, "u1", 10, 60.0, false, "Jongno-gu, Seoul");
//     Person u2;
//     init(&u2, "u2", p.id, p.weight, p.married, p.address);
//     println(&p);
// }

// ===============================================================================
// == 문제 2 실행 결과
// =============================================================================== 
// +++++++++++++ Person Structure Test Menu ++++++++++++
// + 0.Exit 1.printlnTest 2.initTest 3.getter 4.setter +
// ... // 메뉴 생략
// Menu item number? 2
// init(u1 10 60 0 :Jongno-gu, Seoul:)
// init(u2 1 61.1 1 :Seoul Jongno-gu Nam-ro 123:)
// Hong 1 61.1 1 :Seoul Jongno-gu Nam-ro 123:

// ... // 메뉴 생략

// /******************************************************************************
//  * 문제 3
//  ******************************************************************************/
// // 기존 getter() 함수를 아래 함수로 교체하고 TODO 부분의 코드를 완성하라.
// // 이 함수는 전역 구조체 변수 p의 각 멤버에 직접 접근하여 멤버 값을 읽어와 직접 출력한다.
// // 각 멤버의 직접 접근은 위 initTest()의 두번째 init() 호출을 참조하라.

// void getter() { // Menu item 3
//     TODO: [문제 3 실행 결과]를 참조하여 구조체 변수 p의 각 멤버를 직접 출력하라.
//           (cout << ... 문장을 직접 사용하라.)
// }

// ===============================================================================
// == 문제 3 실행 결과
// =============================================================================== 
// ...
// Menu item number? 3
// name:Hong, id:1, weight:61.1, married:1, address:Seoul Jongno-gu Nam-ro 123
// ...

// /******************************************************************************
//  * 문제 4
//  ******************************************************************************/
// // 1) 기존 setter() 함수를 아래 함수로 교체하라.
// //    이 함수는 구조체 Person의 각 멤버에 직접 접근하여 멤버 값을 직접 수정한다.
// // 2) 아래 TODO에서 지정하는 멤버의 값을 변경하라.

// void setter() { // Menu item 4
//     Person u;
//     strcpy(u.name, "u");
//     u.id = p.id;

//     TODO: p의 weight, married, address 값들을 u의 상응하는 멤버에 저장하라.

//     println(&u);
// }


// ===============================================================================
// == 문제 4 실행 결과
// =============================================================================== 
// ...
// Menu item number? 4
// u 1 61.1 1 :Seoul Jongno-gu Nam-ro 123:
// ...


// /******************************************************************************
//  * 문제 5
//  ******************************************************************************/
// // 기존 isSameTest() 함수를 아래 함수로 교체하라.

// void isSameTest() { // Menu item 5
//     println(&p);
//     Person u = { "Hong", 1, };
//     cout << "p.isSame(): " << isSame(&p, u.name, u.id) << endl;
// }

// //-----------------------------------------------------------------------------
// // 아래 [문제 5 실행 결과]처럼 출력되도록 isSame() 함수를 구현하라.
// //-----------------------------------------------------------------------------

// bool isSame(const Person* p, const char* pname, int pid)
//     // C 스타일 문자열 비교는 [교제 예제 2-5]를 참조하라.
//     만약 (p가 포인터하는 구조체의 name 멤버가 매개변수 pname과 동일하고, 
//          p가 포인터하는 구조체의 id 멤버가 매개변수 pid와 동일하면) 
//     true 반환하고, 그렇지 않으면 false를 반환
//     // return 조건문; 형식으로 하나의 문장으로만 코드를 작성해 보라.

// ===============================================================================
// == 문제 5 실행 결과
// =============================================================================== 
// ...
// Menu item number? 5
// Hong 1 61.1 1 :Seoul Jongno-gu Nam-ro 123:
// p.isSame(): 1
// ...

// /******************************************************************************
//  * 문제 6
//  ******************************************************************************/
// // 기존 whatAreYouDoingTest() 함수를 아래 함수로 교체하라.

// void whatAreYouDoingTest() { // Menu item 6
//     whatAreYouDoing(&p);
// }

// //-----------------------------------------------------------------------------
// // 아래 [문제 6 실행 결과]처럼 출력되도록 whatAreYouDoing(Person* p) 함수를 구현하라.
// // 이 함수 구현시 p가 포인터하는 객체의 name을 먼저 출력한 후 
// // 나머지는 출력 결과와 동일하게 문자열을 출력하면 된다.
// //-----------------------------------------------------------------------------

// ===============================================================================
// == 문제 6 실행 결과
// =============================================================================== 
// ...
// Menu item number? 6
// Hong is taking a rest.
// ...

// /******************************************************************************
//  * 문제 7
//  ******************************************************************************/
// // 기존 noBoolAlphaOutput() 함수를 아래 함수로 교체하라.
// // 이 함수는 기존의 모든 테스트 함수를 모두 한번에 호출한다.

// void noBoolAlphaOutput() { // Menu item 7
//     // married 멤버 값 또는 bool 값이 1, 0로 출력됨
//     printlnTest();
//     initTest();
//     getter();
//     setter();
//     isSameTest();
//     whatAreYouDoingTest();
// }

// ===============================================================================
// == 문제 7 실행 결과
// =============================================================================== 
// ...
// Menu item number? 7
//  0 0 0 ::
// LeeSoonShin 0 70.1 1 :Gangnam Seoul:
// Hong,gildong 1 60.2 0 :Jongno-gu, Busan:
// Hong 1 61.1 1 :Seoul Jongno-gu Nam-ro 123:
// init(u1 10 60 0 :Jongno-gu, Seoul:)
// init(u2 1 61.1 1 :Seoul Jongno-gu Nam-ro 123:)
// Hong 1 61.1 1 :Seoul Jongno-gu Nam-ro 123:
// name:Hong, id:1, weight:61.1, married:1, address:Seoul Jongno-gu Nam-ro 123
// u 1 61.1 1 :Seoul Jongno-gu Nam-ro 123:
// Hong 1 61.1 1 :Seoul Jongno-gu Nam-ro 123:
// p.isSame(): 1
// Hong is taking a rest.
// ...

// /******************************************************************************
//  * 문제 8
//  ******************************************************************************/
// // 지금까지 bool 타입의 값(married)은 0 또는 1로 출력되었는데 이를 false 또는 true로 출력해 보자.
// // 기존 boolalphaOut() 함수를 아래 함수로 교체하라.
// // 아래 함수에서처럼 boolalpha라는 조작자를 한번만 출력하고 나면 이후의 bool 값은 
// //    1, 0이 아닌 true, false로 항상 출력된다. 
// // 한번만 설정하면 프로그램이 종료할 때까지 유지된다. 
// // boolalpha 조작자에 대해서는 11장에서 배울 예정이다.

// void boolAlphaOutput() { // Menu item 8
//     cout << boolalpha;    // married 멤버 값 또는 bool 값이 true, false로 출력되도록 설정
//     noBoolAlphaOutput();
//     cout << noboolalpha;  // 원래 상태로 복구함
// }

// ===============================================================================
// == 문제 8 실행 결과
// == 아래 출력결과에서 married 멤버 값과 isSame()의 출력 값이 true 또는 false로 출력되어야 한다.
// =============================================================================== 
// ...
// Menu item number? 8
//  0 0 false ::
// LeeSoonShin 0 70.1 true :Gangnam Seoul:
// Hong,gildong 1 60.2 false :Jongno-gu, Busan:
// Hong 1 61.1 true :Seoul Jongno-gu Nam-ro 123:
// init(u1 10 60 false :Jongno-gu, Seoul:)
// init(u2 1 61.1 true :Seoul Jongno-gu Nam-ro 123:)
// Hong 1 61.1 true :Seoul Jongno-gu Nam-ro 123:
// name:Hong, id:1, weight:61.1, married:true, address:Seoul Jongno-gu Nam-ro 123
// u 1 61.1 true :Seoul Jongno-gu Nam-ro 123:
// Hong 1 61.1 true :Seoul Jongno-gu Nam-ro 123:
// p.isSame(): true
// Hong is taking a rest.
// ...

// /******************************************************************************
//  * 문제 9
//  ******************************************************************************/
// // 기존 noBoolAlphaInputPerson() 함수를 아래 함수로 교체하라.
// // 이 함수는 namespace UI에 있는 전역함수 inputPerson(&p)을 호출하여 인적정보를 입력 받는다.
// // UI::inputPerson()은 한 사람의 정보 즉, p의 각 멤버 데이터를 순서적으로 입력 받아 p에 저장한 후
// // 입력 중 입력 데이터에 오류가 있는지 확인하고 오류가 있을 시 에러 메시지를 출력한다.

// void noBoolAlphaInputPerson() { // Menu item 9
//     // married 멤버 값 또는 bool 값을 0 또는 1로 입력
//     // HongGilDong 0 71.5 1 :Gwangju Nam-gu Bongseon-dong 21:
//     if (UI::inputPerson(&p)) // 입력시 정수 또는 실수 값을 일반 문자로 잘못 입력하지 않은 경우
//         println(&p);
// }

// //-----------------------------------------------------------------------------
// // UI::inputPerson()은 void input(Person* p) 함수를 호출하는데 이 함수는 한 사람의 정보를 
// //    입력받아 p가 포인터하는 객체의 각 멤버에 저장하는데 이 input(p) 함수를 구현하라.
// //
// //    한 사람의 정보 입력은 다음 형식으로 입력한다. 
// //    이름 id 몸무게 결혼여부 :주소:
// //    예) HongGilDong 0 71.5 1 :Gwangju Nam-gu Bongseon-dong 21:
// //       (결혼여부는 0 또는 1로 입력하고 주소는 앞뒤에 ':'으로 구분하여 입력한다.)
// //-----------------------------------------------------------------------------

// input(Person* p) {
//     입력장치 cin으로 부터 >> 연산자를 이용하여 name, id, weight, married 멤버를 
//         순서적으로 연속적으로 계속 >>를 사용하여 한 문장에서 모두 입력받는다.
//     if (!cin) return;  // 입력시 에러가 발생했다면 바로 리턴 
//                        // 즉, 정수 값을 입력해야 하는데 숫자가 아닌 일반 문자를 입력한 경우
//     cin.getline(p->address, sizeof(p->address), ':'); // ':'는 행의 끝을 나타내는 구분자임 
//     // 위 문장은 아래 예처럼 입력장치에서 마지막으로 읽은 married 멤버 값 '1' 이후에 있는
//     // 스페이스부터 주소의 첫번째 ":"까지의 문자들(즉 " :")을 읽어 들이는 역할을 한다.
//     // 예) HongGilDong 0 71.5 1 :Gwangju Nam-gu Bongseon-dong 21:
//     // 즉, " :"를 읽어 들여 ':'를 제거한 후 address 멤버에 저장함, 이들은 사실상 무시될 데이타임
//     // [교재 예제 2-6 참조]

//     앞의 cin.getline() 문장을 동일하게 한번 더 호출한다.
//     // 이는 앞서 읽은 첫번째 ":" 이후부터 두번째 ":"까지 실제 주소 부분만을 읽어 address 멤버에 저장;
//     // 실제 주소값 입력 받았음, 두번째 ":"는 입력 장치에서 읽혀지지만 address에는 저장되지 않음 
//     // 즉, ':'는 행의 끝을 나타내는 구분자 역할을 함
// }

// //-----------------------------------------------------------------------------
// // 프로그램 실행 후 noBoolAlphaInputPerson() 함수 내의 주석문에 있는 인적 정보인 
// // 한줄 전체(줄 끝의 엔터도 포함)를 Ctrl+C로 복사한 후 Console 입력 창에 Ctrl+V로 복사해서 입력하라.
// // 입력 시 주소의 앞과 뒤에 구분자 ":"가 있을 것을 주의하라.

// ===============================================================================
// == 문제 9 실행 결과: 정상 입력인 경우
// =============================================================================== 
// ...
// Menu item number? 9
// input person information:
// HongGilDong 0 71.5 1 :Gwangju Nam-gu Bongseon-dong 21: // 사용자 입력
// HongGilDong 0 71.5 1 :Gwangju Nam-gu Bongseon-dong 21: // println(&p)
// ...

// ===============================================================================
// == 문제 9 실행 결과: 잘못된 인적 정보를 입력한 경우
// =============================================================================== 
// Menu item number? 9
// input person information:
// HongGilDong abc 71.5         // id 오류
// Input-data format MISMATCHED // checkInputError()에서 출력
// ...
// Menu item number? 9
// input person information:
// HongGilDong 1 abc 1         // weight 오류
// Input-data format MISMATCHED
// ...
// Menu item number? 9
// input person information:
// HongGilDong 1 70.1 3 :adfd: // married 오류: 0 또는 1이어야 함
// Input-data format MISMATCHED
// ...

// /******************************************************************************
//  * 문제 10
//  ******************************************************************************/
// // 기존 boolAlphaInputPerson) 함수를 아래 함수로 교체하라. 이 함수는
// // bool 값의 입력과 출력을 0, 1이 아닌 false, true로 입출력하기 위해 설정을 변경하는 방법을 보여준다.
// // 함수에서 cin >> boolalpha;를 실행하는데 
// //    이는 앞으로 입력장치에서 bool 값을 1과 0이 아닌 true와 false로 입력 받도록 설정한다.
// // 함수 마지막 부분에서 설정 값을 원상복구하고 리턴한다. 원상복구를 하지 않으면 프로그램이 종료할 때까지 
// // 설정 된 값이 계속 유지된다.(필요하면 처음에 한번만 설정해 두고 계속 사용해도 된다.)  

// void boolAlphaInputPerson() { // Menu item 10
//     cout << boolalpha;
//     // 아래는 married 멤버 값 또는 bool 값을 true 또는 false로 입력받도록 설정
//     cin  >> boolalpha;
//     // 아래 입력 인적정보에서 married 멤버 값이 1이 아닌 true임
//     // Hong 1 71.5 true :Gwangju Nam-gu Bongseon-dong 21:
//     if (UI::inputPerson(&p))  // 입력시 정수 또는 실수 값을 일반 문자로 잘못 입력하지 않은 경우
//         println(&p);
//     cin  >> noboolalpha; // 원래 상태로 복구함
//     cout << noboolalpha; // 원래 상태로 복구함
// }

// //-----------------------------------------------------------------------------
// // 프로그램 실행 후 boolAlphaInputPerson() 함수 내의 주석문에 있는 인적 정보인 한줄 전체(줄 끝의 엔터도 포함)를 
// // Ctrl+C로 복사한 후 Console 입력 창에 Ctrl+V로 복사해서 입력하라.

// ===============================================================================
// == 문제 10 실행 결과
// == 아래 실행결과에서 입력 시 married 멤버 값을 true 입력했고 
// == 출력 시 bool 값(married)이 0 또는 1이 아닌 true 또는 false로 출력되었음
// =============================================================================== 
// ...
// Menu item number? 10
// input person information:
// HongGilDong 0 71.5 true :Gwangju Nam-gu Bongseon-dong 21:
// HongGilDong 0 71.5 true :Gwangju Nam-gu Bongseon-dong 21:
// ...


// /******************************************************************************
//  * 문제 11
//  ******************************************************************************/
// // 기존 dataTypeSize() 함수를 아래 함수로 교체하라. 이 함수는
// // C++의 기본 데이터 타입의 메모리 크기를 출력한다.
// // 각 데이터 타입의 크기를 잘 외워 두기 바란다.

// void dataTypeSize() { // Menu item 11
//     cout << "bool   size: " << sizeof(bool)   << endl;
//     cout << "char   size: " << sizeof(char)   << endl;
//     cout << "short  size: " << sizeof(short)  << endl;
//     cout << "int    size: " << sizeof(int)    << endl;
//     cout << "long   size: " << sizeof(long)   << endl;
//     cout << "float  size: " << sizeof(float)  << endl;
//     cout << "double size: " << sizeof(double) << endl;
//     cout << "int*   size: " << sizeof(int*)   << endl;
// }

// ===============================================================================
// == 문제 11 실행 결과
// =============================================================================== 
// ...
// Menu item number? 11
// bool   size: 1
// char   size: 1
// short  size: 2
// int    size: 4
// long   size: 4
// float  size: 4
// double size: 8
// int*   size: 4
// ...

// //-----------------------------------------------------------------------------
// // 주의: 위 각 데이터 타입별 메모리 크기는 CPU, 컴파일러에 따라
// //       크기가 다를 수 있음. 특히 long, 포인터의 크기가 8로 
// //       출력되는 시스템이 있을 수 있음.
// //       크기가 달라도 OJ시스템에 제출하면 통과됨
// //-----------------------------------------------------------------------------


// //-----------------------------------------------------------------------------
// // 매번 여러분이 직접 입력 데이터를 만들어 입력하려면 상당히 성가시는 일이 된다. 따라서 아래 과정을 통해 
// // 프로그램 테스트를 위해 필요한 입력용 파일과 출력용 파일을 다운로드하여 이 파일들을 활용하기 바란다.
// // 이 파일들은 프로그램의 수동 테스트 및 자동 오류 테스트를 위한 입출력 파일로 사용된다.
// //-----------------------------------------------------------------------------
// // 1. clc.chosun.ac.kr의 [강의자료실]에서 CH2 과제와 관련된 테스트용 파일을 다운받는다.
// // 2. 압축파일을 풀면 test라는 폴더가 생성되고 그 밑에 .in 또는 .out 파일이 존재할 것이다.
// // 3. 해당 test 폴더를 드래깅하여 이클립스의 [Project Explorer]의 CH2 프로젝트 위에 드랍한다.
// // 4. 그러면 CH2 프로젝트 밑에 기존의 Debug와 src 외에 test 폴더가 새로 생성되어 복사될 것이다.
// // 5. 이 test 폴더를 펼치면 다양한 입력용 파일 .in과 출력용 .out 파일이 존재함을 확인할 수 있음

// ===============================================================================
// == 프로그램의 수동 체크
// =============================================================================== 
// // 프로그램을 실행하라.
// // 그런 후 test_1.in의 파일 내용을 실행 프로그램의 입력창(Console)에 순서적으로 입력한다.(한줄씩 복사)
// // 이 입력 데이타는 printlnTest() 함수를 실행하게 되며 
// // 프로그램의 실행결과와 test_1.out의 내용과 비교하여 결과가 동일하게 나와야 한다. 이와 같은 과정을 통해
// // 모든 테스트 입력 파일의 내용을 순서적으로 입력하고 실행결과가 정확한지 비교 확인하라.
// // 이 작업이 시간이 많이 걸릴 수 있으니 바로 아래 자동 오류 체크를 실행하면 더 정확히 확인할 수 있다.


// /******************************************************************************
//  * 자동 오류 체크를 위한 코드 추가
//  ******************************************************************************/
// // 지금까지의 과정이 정상적으로 모두 구현되었다면 
// // 이제 여러분의 프로그램이 정상적으로 작동하는지 확인하는 자동 오류 체크 기능을 추가 해보자. 
// // 1. clc.chosun.ac.kr의 [강의자료실]에서 CH2 과제와 관련된 파일 중 check_error.h를 다운받는다.
// // 2. 다운 받은 파일을 드래깅하여 이클립스의 [Project Explorer]의 CH2 프로젝트 밑의 src 폴더 위에
// //    드랍한다. (이때 복사 옵션을 선택해서 삽입하라)
// // 3. 그러면 src 폴더에 check_error.h가 복사될 것이다. 
// //-----------------------------------------------------------------------------
// //-----------------------------------------------------------------------------
// // 주의: 위 check_error.h가 정상적으로 컴파일되기 위해서는 컴파일러가 C++ 표준 STL 라이브러리의
// //      C++ 11 (2011에 제정한 표준 스펙)이상을 지원해야 한다.
// //-----------------------------------------------------------------------------

// /******************************************************************************
//  * 자동 오류 체크 모드로 프로그램 실행
//  ******************************************************************************/
// // ch2.cpp 소스 파일 맨 앞쪽에 있는 AUTOMATIC_ERROR_CHECK 상수 값을 아래처럼 [true]로 
// // 변경한 후 프로그램을 실행한다. 

// #define AUTOMATIC_ERROR_CHECK true 
// // true: 자동 오류 체크, false: 키보드에서 직접 입력하여 프로그램 실행

// // 이렇게 실행된 프로그램은 키보드에서 입력을 받지 않고 test_1.in에서 입력을 받아 실행한다.
// // 출력결과 역시 화면에 출력하지 않고 메모리에 출력하여 이 출력 결과와 test_1.out과 비교한다.
// // 비교 결과 오류가 있으면 해당 오류가 무엇인지 사용자에게 알려 준다.
// // 
// // 프로그램이 정상적으로 구현되었다면 아래 [프로그램 실행 결과]와 같이 출력될 것이다.
// //
// // AUTOMATIC_ERROR_CHECK를 다시 [false]로 설정하고 실행하면 
// // 원래대로 콘솔에서 직접 입력하고 출력할 수 있을 것이다.
// //-----------------------------------------------------------------------------

// ===============================================================================
// == 1. 정상적인 프로그램 실행 결과
// == 아래에서 O는 각 단계가 정상적으로 구현되었음을 의미한다.
// =============================================================================== 
// test 1 : O
// test 2 : O
// test 3 : O
// test 4 : O
// test 5 : O
// test 6 : O
// test 7 : O
// test 8 : O
// test 9 : O
// test 10 : O
// test 11 : O
// test 12 : O
// test 13 : O
// Good bye!!

// ===============================================================================
// == 2. 비정상적인 프로그램 실행 결과
// ==    프로그램이 잘못되었다면 잘못된 출력라인과 정확한 출력라인을 연속해서 출력해 줄 것이다.
// ==    두 출력라인 중 어떤 단어("iz")가 틀렸는지 아래처럼 지적해 준다.
// User output("iz") is not equal to correct output("is")
// ==    이 경우 "iz"이 "is"로 출력되어야 한다는 것을 의미함
// =============================================================================== 
// test 1 : O
// test 2 : O
// test 3 : X
// HongGD: ID is 0, weight is 71.5, iz married? 1, address is Gwangju Nam-gu.
// ^--- [wrong line]
// HongGD: ID is 0, weight is 71.5, is married? 1, address is Gwangju Nam-gu.
// ^--- [correct line]
// User output("iz") is not equal to correct output("is")
// continue[y/n]? 

// ===============================================================================
// == 3. 계속 체크하고자 할 경우
// ==    continue[y/n]? y[enter]를 입력하면 계속 잘못된 곳을 찾아 준다.
// ==    자동체크를 중단하고자 할 경우 continue[y/n]? n[enter]을 입력하면 됨 
// =============================================================================== 
// test 1 : O
// test 2 : O
// test 3 : X
// HongGD: ID is 0, weight is 71.5, iz married? 1, address is Gwangju Nam-gu.
// ^--- [wrong line]
// HongGD: ID is 0, weight is 71.5, is married? 1, address is Gwangju Nam-gu.
// ^--- [correct line]
// User output("iz") is not equal to correct output("is")
// continue[y/n]? y     // 사용자 입력

// test 4 : X
// HongGD 0 71.5 1 :Gwangju Nam-gu:
// LeeMR 0 71.5 1 :Gwangju Nam-gu:
// LeeMR 1 71.5 1 :Gwangju Nam-gu:
// LeeMR 1 94 1 :Gwangju Nam-gu:
// LeeMR 1 94 0 :Gwangju Nam-gu:
// LeeMR 1 94 0 :jJongno-gu, Seoul:
// ^--- [wrong line]
// LeeMR 1 94 0 :Jongno-gu, Seoul:
// ^--- [correct line]
// User output(":jJongno-gu,") is not equal to correct output(":Jongno-gu,")
// continue[y/n]? n    // 사용자 입력
// Good bye

// ===============================================================================
// == 4. 문제의 정상 또는 오류 여부만 확인하고자 할 경우
// ==    main() 함수 내에서 evaluate(true);를 evaluate(false);로 설정한 후 실행하면
// ==    아래 실행 결과처럼 각 문제의 정상(O) 또는 오류(X) 여부만 체크해 준다. 
// =============================================================================== 
// test 1 : O
// test 2 : O
// test 3 : X
// test 4 : X
// test 5 : O
// test 6 : O
// test 7 : X
// test 8 : O
// test 9 : O
// test 10 : O
// test 11 : O
// test 12 : O
// test 13 : O
// Good bye!!


// /******************************************************************************
//  * 프로그램 제출
//  ******************************************************************************/
// // 1. 중요: ch2.cpp 소스 파일 맨 앞쪽에 있는 AUTOMATIC_ERROR_CHECK 상수 값을
// //         다시 [false]로 변경한 후 저장하라.
// //         oj 시스템에서는 AUTOMATIC_ERROR_CHECK 값이 [true]으로 설정되어 있으면 
// //         프로그램이 정상적으로 실행되지 않는다.
// // 2. 프로그램을 oj.chosun.ac.kr에 제출하라. 
// //-----------------------------------------------------------------------------