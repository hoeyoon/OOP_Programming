```
/******************************************************************************
 * 코드 추가
 ******************************************************************************/
// 1) 기존에 작성했던 ch3_2.cpp의 내용을 모두 복사해서 ch4_1.cpp에 삽입하라.
// 2) 프로그램의 맨 앞쪽 주석 부분의 "Author: " 행 다음의 내용을 아래 *로 시작하는 행들로 교체하라.
//----------------------------------------------------------------------------
 *
 *  + Person의 멤버 name의 타입을 char[]에서 string을 변환
 *  + 이로 인한 각 멤버함수의 매개변수 name의 타입 변경
 *  + string의 =, == 연산자 적용
 *  + this 키워드 활용하기
 *  + CurrentUser 클래스 수정 (Pointer 버전으로)
 *     객체의 동적 할당과 소멸 그리고 객체의 포인터를 이용한 객체 접근
 *  + MultiManager: CurrentUser(...).run() 생성시 함수인자로 포인터 넘겨 주도록 변환
 */

//----------------------------------------------------------------------------
// 3) Main Menu의 1번 메뉴항목을 아래처럼 수정하라.
//----------------------------------------------------------------------------
"* 0.Exit 1.CurrentUser(ch3_2, 4_1)                                        *\n"


/******************************************************************************
 * 문제 0-1
 ******************************************************************************/
// Person 클래스의 멤버 변수 name의 타입을 char []에서 아래처럼 string으로 변경하라.
// address는 변경하지 말고 여전히 char []로 두어라.
    string name;            // 이름: 변경

// 아래 각 멤버 함수의 매개변수 중 name의 데이타 타입을 아래처럼 수정하라.
    Person(const string name);
    Person(const string name, int id, ...);
    void set(const string name, int id, ...);
    void setName(const string name)       { ... }
    string      getName()    { ... }
    bool isSame(const string name, int id) { ... }

// 위의 const는 해당 매개변수가 그 멤버 함수 내에서 값이 수정되지 않고 읽히기만 한다는 의미임.

// 참고로 name이 string이므로 strcpy()를 사용하지 않고 = 연산자를 바로 사용할 수 있다.
// 따라서 아래 함수에서 strcpy(name, pname) 대신 this->name = name 으로 수정하라.
    void setName(const string name)       { strcpy(name, pname); }

// 마찬가지로 void Person::set() 함수에서 이름(name)의 경우 setName()을 호출하지 말고 
// 직접 = 연산자를 사용하여 값을 설정하라. 

// isSame()의 경우 문자열 비교시 직접 == 연산자를 사용하여 값을 비교하라. 즉, this->name == name

// 마찬가지로 매개변수를 가진 Person::Person(const string name, int id, ...) 생성자의 
// 함수 몸체 내에서 setName()을 호출하는 대신 아래처럼 함수 서두에서 name 멤버를 직적 초기화하라.
// name은 이제 배열이 아니라 string 객체이므로 바로 초기화가 가능하다.
// name(name)은 매개변수 name을 복사해서 멤버 name을 초기화한다.
// Person::Person(const string name, ...): name(name), id{id}, ...
// Person::Person(const string name, ...): name(name), id{id}, ...

===============================================================================
== 문제 0-1 실행 결과
== 이후 각 메뉴 내용은 생략
=============================================================================== 

******************************* Main Menu *********************************
...
Menu item number? 2

+++++++++++ Person Class And Object Menu ++++++++++++
Menu item number? 2
Person::Person(): 0 0 false ::
Person::Person("ps2"):ps2 0 0 false ::
Person::Person(...):ps3 3 70.3 true :ps3 address:
Person::~Person():ps3 3 70.3 true :ps3 address:
Person::~Person():ps2 0 0 false ::
Person::~Person(): 0 0 false ::

...
Menu item number? 0

******************************* Main Menu *********************************
...
Menu item number? 1
Person::Person(...):p0 0 70 false :Gwangju Nam-gu Bongseon-dong 21:

+++++++++++++++++++++ Current User Menu ++++++++++++++++++++++++
...
Menu item number? 3
Person::Person("ps"):ps 0 0 false ::
ps.setMembers():ps 0 70 false :Gwangju Nam-gu Bongseon-dong 21:
Person::~Person():ps 0 70 false :Gwangju Nam-gu Bongseon-dong 21:

...
Menu item number? 4
Person::Person("ps"):ps 0 0 false ::
ps.set():ps 0 70 true :Gwangju Nam-gu Bongseon-dong 21:
Person::~Person():ps 0 70 true :Gwangju Nam-gu Bongseon-dong 21:


/******************************************************************************
 * 문제 0-2
 ******************************************************************************/
// 기존의 멤버 함수들은 함수의 매개변수와 객체 멤버변수와의 동일한 변수 이름의 충돌을 피하기 
// 위해 함수의 매개변수 이름 앞에 p를 붙여 사용하였다. 예를 들어, 아래 pname처럼.
    void setName(const char* pname)       { name = pname; }

// 이제 함수의 매개변수 이름을 객체 멤버변수의 이름과 동일하게끔 모두 변경하고, 
// 매개변수와의 이름 충돌을 방지하기 위해 객체 멤버변수 앞에서 객체 자신에 대한 포인터인 "this->"를 붙여라. 즉,
    void setName(const string name)       { this->name = name; }

// 나머지 수정해야 하는 멤버 함수들은 다음과 같다. 
// 즉, 멤버변수와 매개변수 이름을 동일하게 하고, 멤버변수 앞에 "this->"를 붙여라.
   set(), setName(), setId(), setWeight(), setMarried(), setAddress(), isSame()
// 이들 함수의 선언부와 구현부의 매개변수 이름이 모두 동일하도록 하라.

===============================================================================
== 문제 0-2 실행 결과
=============================================================================== 
// 위 문제 0-1 실행 결과와 동일한 메뉴를 실행시켜 동일한 결과가 나와야 한다. 
// 또한 아래 메뉴 항목도 실행해 보라. 

+++++++++++++++++++++ Current User Menu ++++++++++++++++++++++++
...
Menu item number? 6
p0 0 70 false :Gwangju Nam-gu Bongseon-dong 21:
Person::Person("user"):user 0 0 false ::
user.isSame(): false
Person::~Person():user 1 0 false ::
...
Menu item number? 7
input person information:
user 1 71.1 true :Gwangju Nam-ro 21:
user 1 71.1 true :Gwangju Nam-ro 21:
...
Menu item number? 6
user 1 71.1 true :Gwangju Nam-ro 21:
Person::Person("user"):user 0 0 false ::
user.isSame(): true
Person::~Person():user 1 0 false ::


/******************************************************************************
 * 문제 1
 ******************************************************************************/
// 1) class CurrentUser의 [모든 멤버 함수들]의 본체 안의 모든 코드를 아래처럼 주석처리하라.
      단, run() 함수는 제외하라. 그외 [모든 멤버 함수들]을 주석처리해야 한다.

void CurrentUser::setter() { // Menu item 3
    /*
    Person ps("ps");
    ps.setName(ps.getName());
    ps.setId(user.getId());
    ps.setWeight(user.getWeight());
    ps.setMarried(user.getMarried());
    ps.setAddress(user.getAddress());
    cout << "ps.setMembers():"; ps.println();
    */
}

// 2) 기존의 class CurrentUser의 멤버 데이타 Person user;를 아래처럼 포인터 변수로 변경하고
//    생성자의 매개변수 또한 아래처럼 포인터 변수로 변경하고 
//    함수의 서두(:와 {사이)에서 매개변수 pUser 값을 동일한 멤버변수에 저장하라. 
     
class CurrentUser 
{
    Person* pUser;

public:
    CurrentUser(Person* pUser): /* TODO [문제 1]:  멤버 초기화 */ { }
    ...

// 3) CurrentUser::display()의 함수 본체 내의 주석을 풀고 
//     객체변수 user 대신 포인터 변수 pUser를 사용하여 pUser->println()을 호출하라. 

// 4) class MultiManager::currentUser()에서 
//    CurrentUser의 임시 객체를 생성할 때 매개변수로 person의 주소를 넘겨주어라.

===============================================================================
== 문제 1 실행 결과
=============================================================================== 

******************************* Main Menu ...
Menu item number? 1
Person::Person(...):p0 0 70 false :Gwangju Nam-gu Bongseon-dong 21:

+++++++++++++++++++++ Current User Menu ....
Menu item number? 1
p0 0 70 false :Gwangju Nam-gu Bongseon-dong 21:


/******************************************************************************
 * 문제 2
 ******************************************************************************/
// CurrentUser::getter()의 함수 본체 내의 주석을 풀고 위 display()처럼 
// 객체변수 user 대신 포인터 변수 pUser를 사용하도록 코드를 수정하라.

===============================================================================
== 문제 2 실행 결과
=============================================================================== 
+++++++++++++++++++++ Current User Menu ++++++++++++++++++++++++
...
Menu item number? 2
name:p0, id:0, weight:70, married:false, address:Gwangju Nam-gu Bongseon-dong 21


/******************************************************************************
 * 문제 3
 ******************************************************************************/
// CurrentUser::setter()와 CurrentUser::set()의 경우
// 1) 함수 본체 내의 주석을 풀고 기존의 
      Person ps("ps");
//    문장 대신 아래 문장으로 대체하라. 
//    아래 문장에서 "pp"라는 이름을 가진 Person 객체를 동적으로 생성하라.
	  Person* pp = /* TODO [문제 3]: 동적 메모리 할당 */;
// 2) 기존의 user를 pUser로, 기존의 ps를 pp로 사용하도록 코드를 수정하라.
//    문자열 "ps." 내의 ps도 pp로 수정해야 한다.
// 3) 함수의 마지막에 pp가 포인터하는 객체의 메모리를 반납하는 코드를 추가하라.


===============================================================================
== 문제 3 실행 결과
=============================================================================== 
+++++++++++++++++++++ Current User Menu ++++++++++++++++++++++++
...
Menu item number? 3
Person::Person("pp"):pp 0 0 false ::
pp->setMembers():pp 0 70 false :Gwangju Nam-gu Bongseon-dong 21:
Person::~Person():pp 0 70 false :Gwangju Nam-gu Bongseon-dong 21:
...
Menu item number? 4
Person::Person("pp"):pp 0 0 false ::
pp->set():pp 0 70 true :Gwangju Nam-gu Bongseon-dong 21:
Person::~Person():pp 0 70 true :Gwangju Nam-gu Bongseon-dong 21:


/******************************************************************************
 * 문제 4
 ******************************************************************************/
// CurrentUser::whatAreYouDoing()
// CurrentUser::isSame()
// CurrentUser::inputPerson()
// 이들 함수 역시 주석을 풀고 user 대신 pUser를 사용하도록 수정하라.

// CurrentUser::isSame()의 경우 아래처럼 수정하라.

void CurrentUser::isSame() { // Menu item 6
    pUser->println();
    cout << "isSame(\"user\", 1): " << pUser->isSame("user", 1) << endl;
}

===============================================================================
== 문제 4 실행 결과
=============================================================================== 
...
Menu item number? 5
p0 is taking a rest.
...
Menu item number? 6
p0 0 70 false :Gwangju Nam-gu Bongseon-dong 21:
isSame("user", 1): false
...
Menu item number? 7
input person information:
user 1 71.1 true :Gwangju Nam-ro 21:
user 1 71.1 true :Gwangju Nam-ro 21:
...
Menu item number? 6
user 1 71.1 true :Gwangju Nam-ro 21:
isSame("user", 1): true



/******************************************************************************
 * 자동 오류 체크 모드로 프로그램 실행
 ******************************************************************************/
// 1. clc.chosun.ac.kr의 [강의자료실]에서 CH4_1 과제 테스트 파일을 다운받은 후 
//    압축 파일을 풀고 test 폴더를 드래깅하여 이클립스의 [Project Explorer]의 
//    [CH4_1] 프로젝트 위에 드랍한다. (test 폴더와 그 밑에 테스트용 파일이 있어야 함)
// 2. 기존 프로젝트 CH2의 src 폴드에 있는 check_error.h를 CH4_1 프로젝트의 
//    src 폴더로 복사하라. (파일 선택 후 [Ctrl+C], src 폴더를 선택 후 [Ctrl+V])
// 3. 소스 파일 맨 앞쪽에 있는 AUTOMATIC_ERROR_CHECK 상수 값을 true로 설정하라.
// 4. main() 함수 내의 evaluate(true)가 true로 설정되어 있는지 확인하라.
// 5. 프로그램 테스트를 위한 입출력 파일이 test 폴더에 다운로드 되어 있는지 확인하라.
// 6. 프로그램이 정상적으로 구현되었다면 아래 [프로그램 실행 결과]와 같이 출력될 것이다.

===============================================================================
== 1. 정상적인 프로그램 실행 결과
==    아래 각 테스트 번호는 위 문제 번호와는 관련 없습니다.
=============================================================================== 
test 1 : O
test 2 : O
test 3 : O
test 4 : O
test 5 : O
Good bye!!

===============================================================================
== 2. 비정상적인 경우의 프로그램 실행방법은 CH2의 실습과제 설명의 마지막 부분을 참조하기 바란다.  
=============================================================================== 

/******************************************************************************
 * 프로그램 제출
 ******************************************************************************/
// 1. 중요: 소스 파일 맨 앞쪽에 있는 AUTOMATIC_ERROR_CHECK 상수 값을 false로 설정하라.
// 2. 프로그램을 oj.chosun.ac.kr에 제출하라. 
//-----------------------------------------------------------------------------
```