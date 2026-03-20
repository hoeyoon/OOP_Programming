//----------------------------------------------------------------------------
// 아래 문제를 해결하는 도중 출력이 잘못되었거나 문제 설명과 출력이 일치하지 않거나 오타가 있거나 등등
// 조금이라도 문제에 이상한 것이 있으면 주저하지 말고 jhshim@chosun.ac.kr로 알려 주시기 바랍니다.
//----------------------------------------------------------------------------

/******************************************************************************
 * 프로젝트 및 소스파일 생성
 ******************************************************************************/
// 기존의 과제를 수행했던 이클립스의 작업공간(workspace)에서 다음을 실행하라.
// 1) 메뉴 [File]->[New]->[C/C++ Project] 한 후 새로운 프로젝트 CH4_1를 만들어라.
// 2) 메뉴 [File]->[New]->[Source Folder] 한 후 폴더 이름으로 src를 지정하여 생성하라.
// 3) 메뉴 [File]->[New]->[Source File]한 후 파일 이름으로 ch4_1.cpp를 지정하라.

/******************************************************************************
 * 코드 추가
 ******************************************************************************/
// 1) 기존에 작성했던 ch3_2.cpp의 내용을 모두 복사해서 ch4_1.cpp에 삽입하라.
// 2) 프로그램의 맨 앞쪽 주석 부분의 "Author: " 행 다음의 내용을 아래 *로 시작하는 행들로 교체하라.
//----------------------------------------------------------------------------

/*
 * CH2: c4_1.cpp
 *
 *  Created on: 2026. 3. 20.
 *      Author: 정회윤
 *
 *  + Person의 멤버 name의 타입을 char[]에서 string을 변환
 *  + 이로 인한 각 멤버함수의 매개변수 name의 타입 변경
 *  + string의 =, == 연산자 적용
 *  + this 키워드 활용하기
 *  + CurrentUser 클래스 수정 (Pointer 버전으로)
 *     객체의 동적 할당과 소멸 그리고 객체의 포인터를 이용한 객체 접근
 *  + MultiManager: CurrentUser(...).run() 생성시 함수인자로 포인터 넘겨 주도록 변환
 */

#include <iostream>
#include <cstring>

using namespace std;  // 헤드 파일은 반드시 이 문장 앞쪽에 include해야 한다.

/******************************************************************************
 * 아래 상수 정의는 필요에 따라 변경하여 사용하라.
 ******************************************************************************/
#define AUTOMATIC_ERROR_CHECK false // true: 자동 오류 체크, false: 키보드에서 직접 입력하여 프로그램 실행

/******************************************************************************
 * Person class
 ******************************************************************************/

class Person
{
    string name;	        // 이름
    int    id;              // Identifier
    double weight;          // 체중
    bool   married;         // 결혼여부
    char   address[40];     // 주소

protected:
    void inputMembers(istream* in);
    void printMembers(ostream* out);

public:
    Person();
    Person(const string name);
    Person(const string name, int id, double weight, bool married, const char *address);
    ~Person();

    void set(const string name, int pid, double weight, bool married, const char *address);
    void setName(const string name)       { this->name = name; }
    void setId(int id)                   { this->id = id; }
    void setWeight(double weight)        { /* TODO: [문제 3] */ this->weight = weight; }
    void setMarried(bool married)        { /* TODO: [문제 3] */ this->married = married; }
    void setAddress(const char* address) {
    	/* ch3_1.cpp의 동일 함수를 복사하라. */
    	strcpy(this->address, address);
    }

    string 		getName()    { return name; }
    int         getId()      { return id; }
    double      getWeight()  { /* TODO: [문제 2] */ return weight; }  // 구현 시
    bool        getMarried() { /* TODO: [문제 2] */ return married; }  // 리턴 값들을
    const char* getAddress() { /* TODO: [문제 2] */ return address; } // 수정하시오.

    void input(istream* pin)  { inputMembers(pin); } // ch3_2에서 추가
    void print(ostream* pout) { printMembers(pout); }
    void println()            { print(&cout); cout << endl; }
    void whatAreYouDoing();                          // ch3_2에서 추가
    bool isSame(const string name, int id);         // ch3_2에서 추가
};

Person::Person(): name{}, id{}, weight{}, married{}, address{} {
    // 위 함수 서두(:와 함수 본체 사이)에서 각 멤버를 초기화하는데 이는 함수 진입하기 전에
    // 각 멤버의 값을 초기화하는 것이다. {}는 각 데이타 타입별로 디폴트 값으로 초기화하라는 의미임.
    // 즉, name[]={'\0'}="", id=0, weight=0.0, married=false, address[]={'\0'}=""
    cout << "Person::Person():"; println();
}

Person::Person(const string name) : name{name}, id{}, weight{}, married{}, address{} /* : TODO [문제 2] */ {
    // TODO: [문제 2]
    cout << "Person::Person(\"" << name << "\"):"; println();
}

Person::Person(const string name, int id, double weight, bool married,
               const char *address) :
        name{name}, id{id}, weight{weight}, married{married} {
    // 위에서 각 멤버를 초기화하는 {}는 각 매개변수 값을 객체의 상응하는 멤버에 설정하는 것이다. 즉,
    // this->id=id, this->weight=weight, this->married=married와 동일하다.
    // 여기서 this는 해당 객체를 포인터하는 포인터 변수이며, (다음 장에서 설명될 예정임)
    // this->id는 해당 객체의 멤버 id를 지칭하며 =의 우측변수 id는 함수의 매개변수이다.
    // 값을 간단히 대입하는 것은 위처럼 하면 되지만 name[], address[]와 같은 배열 복사 함수
    // 호출 또는 다른 함수를 호출할 때는 생성자 함수의 몸체 { } 내에서 호출해야 한다.

    // TODO: [문제 2]
    setAddress(address);
    cout << "Person::Person(...):"; println();
}

void Person::set(const string name, int id, double weight,
	bool married, const char *address) {
	// TODO: [문제 4]
	this->name = name;
	this->id = id;
	this->weight = weight;
	this->married = married;
	setAddress(address);
}

void Person::inputMembers(istream* pin)   {
	// TODO: [문제 7]
	*pin >> name >> id >> weight >> married;

	if(!(*pin)){
		return;
	}

	pin->getline(address, sizeof(address), ':');
	pin->getline(address, sizeof(address), ':');
}

void Person::whatAreYouDoing() {
	// TODO: [문제 5]
	cout << name << "is taking a rest." << endl;
}

bool Person::isSame(const string name, int id) {
	// TODO: [문제 6]
	if(this->name == name && this->id == id){
		return true;
	}
	return false; // 구현 시 수정하라.
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
 * ch3_2: CurrentUser class
 ******************************************************************************/

class CurrentUser
{
    Person *pUser;

public:
    CurrentUser(Person *pUser): pUser(pUser) { }  // user(u)는 this->user = u 와 동일한 기능
    void display();
    void setter();
    void getter();
    void set();
    void whatAreYouDoing();
    void isSame();
    void inputPerson();
    void run();
};

void CurrentUser::display() { // Menu item 1
    pUser->println();
}

void CurrentUser::getter() { // Menu item 2
    cout << "name:" << pUser->getName() << ", id:" << pUser->getId() << ", weight:" <<
            pUser->getWeight() << ", married:" << pUser->getMarried() <<
            ", address:" <<pUser->getAddress() << endl;
}

void CurrentUser::setter() { // Menu item 3
    Person *pp = new Person("pp");
    pp->setName(pp->getName());
    pp->setId(pUser->getId());
    pp->setWeight(pUser->getWeight());
    pp->setMarried(pUser->getMarried());
    pp->setAddress(pUser->getAddress());
    cout << "pp->setMembers():"; pp->println();
    delete pp;
}

void CurrentUser::set() { // Menu item 4
    Person *pp = new Person("pp");
    pp->set(pp->getName(), pUser->getId(), pUser->getWeight(),
              !pUser->getMarried(), pUser->getAddress());
    cout << "pp->set():"; pp->println();
    delete pp;
}

void CurrentUser::whatAreYouDoing() {  // Menu item 5
    pUser->whatAreYouDoing();
}

void CurrentUser::isSame() { // Menu item 6
    pUser->println();
    cout << "isSame(\"user\", 1): " << pUser->isSame("user", 1) << endl;
}

void CurrentUser::inputPerson() { // Menu item 7
    if (UI::inputPerson(pUser)) // GilDong 1 70.5 true :Jongno-gu, Seoul:
        display();              // user 1 71.1 true :Gwangju Nam-ro 21:
}

void CurrentUser::run() {
    using func_t = void (CurrentUser::*)();
    func_t func_arr[] = {
        nullptr, &CurrentUser::display, &CurrentUser::getter, &CurrentUser::setter,
        &CurrentUser::set, &CurrentUser::whatAreYouDoing,
        &CurrentUser::isSame, &CurrentUser::inputPerson,
    };
    int menuCount = sizeof(func_arr) / sizeof(func_arr[0]); // func_arr[] 배열의 길이
    string menuStr =
        "+++++++++++++++++++++ Current User Menu ++++++++++++++++++++++++\n"
        "+ 0.Logout 1.Display 2.Getter 3.Setter 4.Set 5.WhatAreYouDoing +\n"
        "+ 6.IsSame 7.InputPerson                                       +\n"
        "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

    while (true) {
        int menuItem = UI::selectMenu(menuStr, menuCount);
        if (menuItem == 0) return;
        (this->*func_arr[menuItem])();
    }
}	// ch3_2: CurrentUser class

/******************************************************************************
 * ch3_2: MultiManager class
 ******************************************************************************/

class MultiManager
{
    Person person {"p0", 0, 70.0, false, "Gwangju Nam-gu Bongseon-dong 21"};

public:
    void currentUser() {
        CurrentUser(&person).run();
    }
}; // ch3_2: MultiManager class


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
        cout << "\n--- construcor_destructor_inner_inner() begins ---" << endl;
        Person ps3("ps3");
        cout << "\n- if begins -" << endl;
        if (true) {
            Person ps4("ps4");
        }
        cout << "- if ends -\n" << endl;
        cout << "- temporary object begins -" << endl;
        Person("temp_ps_1"); // 임시객체(이름 없는 객체) 성성 및 소멸
        cout << endl;
        Person("temp_ps_2").setName("TEMP_PS_2"); // 임시객체 생성,
                                                  // setName() 호출, 임시객체 소멸
        cout << "- temporary object ends -\n" << endl;
        Person ps5("ps5");
    }

    void construcor_destructor_inner() {
        cout << "\n--- construcor_destructor_inner() begins ---" << endl;
        Person ps2("ps2");
        construcor_destructor_inner_inner();
        cout << "--- construcor_destructor_inner_inner() returned ---\n" << endl;
        Person ps6("ps6");
    }

    void construcorDestructor() { // Menu item 3
        Person ps1("ps1");
        construcor_destructor_inner();
        cout << "--- construcor_destructor_inner() returned ---\n" << endl;
    }

    void global_static_local_objects_inner() {
        cout << "\n--- global_static_local_objects_inner() begins ---" << endl;
        //static Person sps("sps", 2000, 200, false, "sps adress");
    }

    void globalStaticLocalObjects() { // Menu item 4
        global_static_local_objects_inner();
        cout << "--- global_static_local_objects_inner() returned ---" << endl;
        global_static_local_objects_inner();
        cout << "--- global_static_local_objects_inner() returned ---" << endl;
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
        int menuCount = 3; // 상수 정의
        string menuStr =
"******************************* Main Menu *********************************\n"
"* 0.Exit 1.CurrentUser(ch3_2, 4_1)                                        *\n"
"* 2.Class:Object(ch3_1)                                                   *\n"
"***************************************************************************\n";

        while (true) {
            int menuItem = UI::selectMenu(menuStr, menuCount);
            if (menuItem == 0) break;

            switch(menuItem) {
            case 1: MultiManager().currentUser();     break;
            case 2: ClassAndObject().run();           break;
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
// // ch4_1.cpp 소스 끝
// //-----------------------------------------------------------------------------

// /******************************************************************************
//  * 문제 0-1
//  ******************************************************************************/
// // Person 클래스의 멤버 변수 name의 타입을 char []에서 아래처럼 string으로 변경하라.
// // address는 변경하지 말고 여전히 char []로 두어라.
//     string name;            // 이름: 변경

// // 아래 각 멤버 함수의 매개변수 중 name의 데이타 타입을 아래처럼 수정하라.
//     Person(const string name);
//     Person(const string name, int id, ...);
//     void set(const string name, int id, ...);
//     void setName(const string name)       { ... }
//     string      getName()    { ... }
//     bool isSame(const string name, int id) { ... }

// // 위의 const는 해당 매개변수가 그 멤버 함수 내에서 값이 수정되지 않고 읽히기만 한다는 의미임.

// // 참고로 name이 string이므로 strcpy()를 사용하지 않고 = 연산자를 바로 사용할 수 있다.
// // 따라서 아래 함수에서 strcpy(name, pname) 대신 this->name = name 으로 수정하라.
//     void setName(const string name)       { strcpy(name, pname); }

// // 마찬가지로 void Person::set() 함수에서 이름(name)의 경우 setName()을 호출하지 말고 
// // 직접 = 연산자를 사용하여 값을 설정하라. 

// // isSame()의 경우 문자열 비교시 직접 == 연산자를 사용하여 값을 비교하라. 즉, this->name == name

// // 마찬가지로 매개변수를 가진 Person::Person(const string name, int id, ...) 생성자의 
// // 함수 몸체 내에서 setName()을 호출하는 대신 아래처럼 함수 서두에서 name 멤버를 직적 초기화하라.
// // name은 이제 배열이 아니라 string 객체이므로 바로 초기화가 가능하다.
// // name(name)은 매개변수 name을 복사해서 멤버 name을 초기화한다.
// // Person::Person(const string name, ...): name(name), id{id}, ...
// // Person::Person(const string name, ...): name(name), id{id}, ...

// ===============================================================================
// == 문제 0-1 실행 결과
// == 이후 각 메뉴 내용은 생략
// =============================================================================== 

// ******************************* Main Menu *********************************
// ...
// Menu item number? 2

// +++++++++++ Person Class And Object Menu ++++++++++++
// Menu item number? 2
// Person::Person(): 0 0 false ::
// Person::Person("ps2"):ps2 0 0 false ::
// Person::Person(...):ps3 3 70.3 true :ps3 address:
// Person::~Person():ps3 3 70.3 true :ps3 address:
// Person::~Person():ps2 0 0 false ::
// Person::~Person(): 0 0 false ::

// ...
// Menu item number? 0

// ******************************* Main Menu *********************************
// ...
// Menu item number? 1
// Person::Person(...):p0 0 70 false :Gwangju Nam-gu Bongseon-dong 21:

// +++++++++++++++++++++ Current User Menu ++++++++++++++++++++++++
// ...
// Menu item number? 3
// Person::Person("ps"):ps 0 0 false ::
// ps.setMembers():ps 0 70 false :Gwangju Nam-gu Bongseon-dong 21:
// Person::~Person():ps 0 70 false :Gwangju Nam-gu Bongseon-dong 21:

// ...
// Menu item number? 4
// Person::Person("ps"):ps 0 0 false ::
// ps.set():ps 0 70 true :Gwangju Nam-gu Bongseon-dong 21:
// Person::~Person():ps 0 70 true :Gwangju Nam-gu Bongseon-dong 21:


// /******************************************************************************
//  * 문제 0-2
//  ******************************************************************************/
// // 기존의 멤버 함수들은 함수의 매개변수와 객체 멤버변수와의 동일한 변수 이름의 충돌을 피하기 
// // 위해 함수의 매개변수 이름 앞에 p를 붙여 사용하였다. 예를 들어, 아래 pname처럼.
//     void setName(const char* pname)       { name = pname; }

// // 이제 함수의 매개변수 이름을 객체 멤버변수의 이름과 동일하게끔 모두 변경하고, 
// // 매개변수와의 이름 충돌을 방지하기 위해 객체 멤버변수 앞에서 객체 자신에 대한 포인터인 "this->"를 붙여라. 즉,
//     void setName(const string name)       { this->name = name; }

// // 나머지 수정해야 하는 멤버 함수들은 다음과 같다. 
// // 즉, 멤버변수와 매개변수 이름을 동일하게 하고, 멤버변수 앞에 "this->"를 붙여라.
//    set(), setName(), setId(), setWeight(), setMarried(), setAddress(), isSame()
// // 이들 함수의 선언부와 구현부의 매개변수 이름이 모두 동일하도록 하라.

// ===============================================================================
// == 문제 0-2 실행 결과
// =============================================================================== 
// // 위 문제 0-1 실행 결과와 동일한 메뉴를 실행시켜 동일한 결과가 나와야 한다. 
// // 또한 아래 메뉴 항목도 실행해 보라. 

// +++++++++++++++++++++ Current User Menu ++++++++++++++++++++++++
// ...
// Menu item number? 6
// p0 0 70 false :Gwangju Nam-gu Bongseon-dong 21:
// Person::Person("user"):user 0 0 false ::
// user.isSame(): false
// Person::~Person():user 1 0 false ::
// ...
// Menu item number? 7
// input person information:
// user 1 71.1 true :Gwangju Nam-ro 21:
// user 1 71.1 true :Gwangju Nam-ro 21:
// ...
// Menu item number? 6
// user 1 71.1 true :Gwangju Nam-ro 21:
// Person::Person("user"):user 0 0 false ::
// user.isSame(): true
// Person::~Person():user 1 0 false ::


// /******************************************************************************
//  * 문제 1
//  ******************************************************************************/
// // 1) class CurrentUser의 [모든 멤버 함수들]의 본체 안의 모든 코드를 아래처럼 주석처리하라.
//       단, run() 함수는 제외하라. 그외 [모든 멤버 함수들]을 주석처리해야 한다.

// void CurrentUser::setter() { // Menu item 3
//     /*
//     Person ps("ps");
//     ps.setName(ps.getName());
//     ps.setId(user.getId());
//     ps.setWeight(user.getWeight());
//     ps.setMarried(user.getMarried());
//     ps.setAddress(user.getAddress());
//     cout << "ps.setMembers():"; ps.println();
//     */
// }

// // 2) 기존의 class CurrentUser의 멤버 데이타 Person user;를 아래처럼 포인터 변수로 변경하고
// //    생성자의 매개변수 또한 아래처럼 포인터 변수로 변경하고 
// //    함수의 서두(:와 {사이)에서 매개변수 pUser 값을 동일한 멤버변수에 저장하라. 
     
// class CurrentUser 
// {
//     Person* pUser;

// public:
//     CurrentUser(Person* pUser): /* TODO [문제 1]:  멤버 초기화 */ { }
//     ...

// // 3) CurrentUser::display()의 함수 본체 내의 주석을 풀고 
// //     객체변수 user 대신 포인터 변수 pUser를 사용하여 pUser->println()을 호출하라. 

// // 4) class MultiManager::currentUser()에서 
// //    CurrentUser의 임시 객체를 생성할 때 매개변수로 person의 주소를 넘겨주어라.

// ===============================================================================
// == 문제 1 실행 결과
// =============================================================================== 

// ******************************* Main Menu ...
// Menu item number? 1
// Person::Person(...):p0 0 70 false :Gwangju Nam-gu Bongseon-dong 21:

// +++++++++++++++++++++ Current User Menu ....
// Menu item number? 1
// p0 0 70 false :Gwangju Nam-gu Bongseon-dong 21:


// /******************************************************************************
//  * 문제 2
//  ******************************************************************************/
// // CurrentUser::getter()의 함수 본체 내의 주석을 풀고 위 display()처럼 
// // 객체변수 user 대신 포인터 변수 pUser를 사용하도록 코드를 수정하라.

// ===============================================================================
// == 문제 2 실행 결과
// =============================================================================== 
// +++++++++++++++++++++ Current User Menu ++++++++++++++++++++++++
// ...
// Menu item number? 2
// name:p0, id:0, weight:70, married:false, address:Gwangju Nam-gu Bongseon-dong 21


// /******************************************************************************
//  * 문제 3
//  ******************************************************************************/
// // CurrentUser::setter()와 CurrentUser::set()의 경우
// // 1) 함수 본체 내의 주석을 풀고 기존의 
//       Person ps("ps");
// //    문장 대신 아래 문장으로 대체하라. 
// //    아래 문장에서 "pp"라는 이름을 가진 Person 객체를 동적으로 생성하라.
// 	  Person* pp = /* TODO [문제 3]: 동적 메모리 할당 */;
// // 2) 기존의 user를 pUser로, 기존의 ps를 pp로 사용하도록 코드를 수정하라.
// //    문자열 "ps." 내의 ps도 pp로 수정해야 한다.
// // 3) 함수의 마지막에 pp가 포인터하는 객체의 메모리를 반납하는 코드를 추가하라.


// ===============================================================================
// == 문제 3 실행 결과
// =============================================================================== 
// +++++++++++++++++++++ Current User Menu ++++++++++++++++++++++++
// ...
// Menu item number? 3
// Person::Person("pp"):pp 0 0 false ::
// pp->setMembers():pp 0 70 false :Gwangju Nam-gu Bongseon-dong 21:
// Person::~Person():pp 0 70 false :Gwangju Nam-gu Bongseon-dong 21:
// ...
// Menu item number? 4
// Person::Person("pp"):pp 0 0 false ::
// pp->set():pp 0 70 true :Gwangju Nam-gu Bongseon-dong 21:
// Person::~Person():pp 0 70 true :Gwangju Nam-gu Bongseon-dong 21:


// /******************************************************************************
//  * 문제 4
//  ******************************************************************************/
// // CurrentUser::whatAreYouDoing()
// // CurrentUser::isSame()
// // CurrentUser::inputPerson()
// // 이들 함수 역시 주석을 풀고 user 대신 pUser를 사용하도록 수정하라.

// // CurrentUser::isSame()의 경우 아래처럼 수정하라.

// void CurrentUser::isSame() { // Menu item 6
//     pUser->println();
//     cout << "isSame(\"user\", 1): " << pUser->isSame("user", 1) << endl;
// }

// ===============================================================================
// == 문제 4 실행 결과
// =============================================================================== 
// ...
// Menu item number? 5
// p0 is taking a rest.
// ...
// Menu item number? 6
// p0 0 70 false :Gwangju Nam-gu Bongseon-dong 21:
// isSame("user", 1): false
// ...
// Menu item number? 7
// input person information:
// user 1 71.1 true :Gwangju Nam-ro 21:
// user 1 71.1 true :Gwangju Nam-ro 21:
// ...
// Menu item number? 6
// user 1 71.1 true :Gwangju Nam-ro 21:
// isSame("user", 1): true



// /******************************************************************************
//  * 자동 오류 체크 모드로 프로그램 실행
//  ******************************************************************************/
// // 1. clc.chosun.ac.kr의 [강의자료실]에서 CH4_1 과제 테스트 파일을 다운받은 후 
// //    압축 파일을 풀고 test 폴더를 드래깅하여 이클립스의 [Project Explorer]의 
// //    [CH4_1] 프로젝트 위에 드랍한다. (test 폴더와 그 밑에 테스트용 파일이 있어야 함)
// // 2. 기존 프로젝트 CH2의 src 폴드에 있는 check_error.h를 CH4_1 프로젝트의 
// //    src 폴더로 복사하라. (파일 선택 후 [Ctrl+C], src 폴더를 선택 후 [Ctrl+V])
// // 3. 소스 파일 맨 앞쪽에 있는 AUTOMATIC_ERROR_CHECK 상수 값을 true로 설정하라.
// // 4. main() 함수 내의 evaluate(true)가 true로 설정되어 있는지 확인하라.
// // 5. 프로그램 테스트를 위한 입출력 파일이 test 폴더에 다운로드 되어 있는지 확인하라.
// // 6. 프로그램이 정상적으로 구현되었다면 아래 [프로그램 실행 결과]와 같이 출력될 것이다.

// ===============================================================================
// == 1. 정상적인 프로그램 실행 결과
// =============================================================================== 
// test 1 : O
// test 2 : O
// test 3 : O
// test 4 : O
// test 5 : O
// Good bye!!

// ===============================================================================
// == 2. 비정상적인 경우의 프로그램 실행방법은 CH2의 실습과제 설명의 마지막 부분을 참조하기 바란다.  
// =============================================================================== 

// /******************************************************************************
//  * 프로그램 제출
//  ******************************************************************************/
// // 1. 중요: 소스 파일 맨 앞쪽에 있는 AUTOMATIC_ERROR_CHECK 상수 값을 false로 설정하라.
// // 2. 프로그램을 oj.chosun.ac.kr에 제출하라. 
// //-----------------------------------------------------------------------------