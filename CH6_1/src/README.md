```
[6장 문제-1]

//----------------------------------------------------------------------------
// 아래 문제를 해결하는 도중 출력이 잘못되었거나 문제 설명과 출력이 일치하지 않거나 오타가 있거나 등등
// 조금이라도 문제에 이상한 것이 있으면 주저하지 말고 jhshim@chosun.ac.kr로 알려 주시기 바랍니다.
//----------------------------------------------------------------------------

/******************************************************************************
 * 프로젝트 및 소스파일 생성
 ******************************************************************************/
// 기존의 과제를 수행했던 이클립스의 작업공간에서 새로운 프로젝트 CH6_1를 만들고 
// 그 밑에 src 풀더를 만든 후 src 폴더 밑에 ch6_1.cpp 소스파일을 만들어라.

/******************************************************************************
 * 코드 추가 및 변경 1
 ******************************************************************************/
// 1) 기존에 작성했던 ch5_2.cpp의 내용을 모두 복사해서 ch6_1.cpp에 삽입하라.
// 2) 프로그램의 맨 앞쪽 주석 부분의 "Author: " 행 다음의 내용을 아래 *로 시작하는 행들로 교체하라.
//----------------------------------------------------------------------------
 *
 *  + "address, memo_c_str deleted" 관련 출력 문장 삭제
 *  + 디폴트 매개변수를 활용하여 기본 생성자 Person(), VectorPerson() 제거
 *  + Memo 클래스 디폴트 매개변수를 가진 생성자 추가
 *  + Person::set(), Memo::c_str() 등 함수 중복
 *  + UI namespace 대신 class UI로 변경: static 멤버 활용
 *  + 함수의 매개변수 또는 반환 값으로 값이나 포인터 대신 가능하면 참조자 &를 사용하도록 변경
 *     즉, call by value 나 call by address 대신 가능하면 call by reference를 활용
 *  + 모든 UI::inputPerson() 호출시 매개변수를 포인터에서 참조자로 변경
 *  + CurrentUser: 클래스 포인터 pUser -> 참조자 rUser로 모두 변환
 *  + Factory: 멤버 함수들의 포인터 인자를 참조자로 변경
 *  + CurrentUser: 멤버 defaultParameter(), staticMember() 추가
 *  + string을 매개변수, 리턴 하는 모든 함수들의 데이타 타입을 string 참조 변수로 변경
 */


/******************************************************************************
 * 코드 변경 2
 ******************************************************************************/
// 아래 각 메뉴의 변경된 부분을 반영하여라. (ch6과 관련된 내용임)
//-----------------------------------------------------------------------------

******************************* Main Menu *********************************
* 0.Exit 1.PersonManager(ch3_2, 4, 6)                                     *
* 2.Class:Object(ch3_1) 3.CopyConstructor(ch5_1) 4.AllocatedMember(ch5_2) *
***************************************************************************
====================== Person Management Menu ===================
= 0.Exit 1.Display 2.Append 3.Clear 4.Login(CurrentUser, ch6)   =
=================================================================
+++++++++++++++++++++ Current User Menu ++++++++++++++++++++++++
+ 0.Logout 1.Display 2.Getter 3.Setter 4.Set 5.WhatAreYouDoing +
+ 6.IsSame 7.InputPerson 8.ChangePasswd(4_2) 9.ManageMemo(4_3) +
+ 10.DefaultParameter(6_1) 11.StaticMember(6_1)                +
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


/******************************************************************************
 * 코드 변경 3
 ******************************************************************************/
// Person::~Person(), Person::setAddress(), Person::setMemo()에서 
// 멤버 address와 memo_c_str의 "deleted" 관련 출력 문장을 모두 삭제하라.
// 즉, cout << ... 문장은 모두 삭제하라. (필요하면 if 문장도 포함해서)
// 단, Person::~Person()에서는 cout 문장 중 아래 문장은 남겨 두어라. 
    cout << "Person::~Person():"; println();


/******************************************************************************
 * [문제 1] 디폴트 매개변수
 ******************************************************************************/
// Person, VectorPerson 클래스의 아래 생성자들을 주석 처리하라. 앞으로 이들은 사용하지 않을 것이다.
//----------------------------------------------------------------------------
    Person(): Person("") { } // default parameter, reference
    Person(const string name): Person(name, 0, 0, false, "") { }
    VectorPerson(): VectorPerson(DEFAULT_SIZE) { } // 위임 생성자

//----------------------------------------------------------------------------
// 1) 대신 위의 생성자들과 동일한 기능을 수행할 수 있도록 아래 생성자 매개변수들을 디폴트 값을 가진  
//    매개변수로 변경하여라. 디폴트 매개변수 설정은 클래스 내부에서 함수를 선언할 때 해야 함.
// 힌트: const string name = {} 와 같이 각 매개변수를 = {}로 설정하면 각 매개변수의 디폴트 값이
//      설정된다. {}는 bool:false, char:'\0', int:0, double:0.0, 포인트:nullptr이며
//      string과 같은 클래스 객체일 경우 그 클래스의 기본 생성자가 실행된다. string:""
//----------------------------------------------------------------------------
    Person(const string name, int id, double weight, bool married, const char* address);
    VectorPerson(int capacity); // capacity의 디폴트 값은 DEFAULT_SIZE로 하라.

//----------------------------------------------------------------------------
// 2) class Memo에 아래 생성자를 새로 추가하라.
    Memo(const char* c_str /* TODO:디폴트 매개변수 초기값 설정 */ ): /* TODO:mStr 초기화 */ { }
//    i)  매개변수 c_str를 디폴트 매개변수로 선언하고 디폴트 값으로 nullptr을 설정하라.
//    ii) 생성자의 서두(함수 본체가 아님)에서 mStr(?:)을 초기화하라. 이 때 삼항 연산자(?:)을 사용해 
//        c_str이 nullptr이면 멤버 mStr을 ""로, 아닌 경우 mStr을 c_str로 초기화하라.
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 3) 이상의 변경된 내용을 확인하기 위한 아래 코드를 CurrentUser::run() 앞에 추가하고,
//    CurrentUser::run()의 func_arr[]에 적절한 원소를 추가하라.
//----------------------------------------------------------------------------

void CurrentUser::defaultParameter() { // Menu item 10
    Person ps1;
    Person ps2("ps2");
    Person ps3("ps3", 3);
    Person ps4("ps4", 4, 70.4);
    Person ps5("ps5", 5, 70.5, true);
    Person ps6("ps6", 6, 70.6, true, "ps6 address");

    cout << "\nMemo m1;" << endl;
    Memo m1; // 메모 생성자에게 인자를 넘겨 주지 않은 경우
    m1.displayMemo();

    cout << "\nMemo m2(pUser->getMemo())" << endl;
    Memo m2(pUser->getMemo()); // 메모 생성자에게 인자를 넘겨 준 경우
    m2.displayMemo();
}

===============================================================================
== [문제 1] 실행 결과 - 1 
=============================================================================== 

******************************* Main Menu *********************************
* 0.Exit 1.PersonManager(ch3_2, 4, 6) ...
Menu item number? 1
Person::Person(...):p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
...
Person::Person(...):p4 14 64.4 false :88 Gongpyeong-ro, Jung-gu, Daegu:
VectorPerson::VectorPerson(10)                 // VectorPerson::allocSize = 10
PersonManager::PersonManager(array[], len)
Person::Person(const Person&):p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
...
Person::Person(const Person&):p4 14 64.4 false :88 Gongpyeong-ro, Jung-gu, Daegu:
display(): count 5
[0] p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
...
[4] p4 14 64.4 false :88 Gongpyeong-ro, Jung-gu, Daegu:
empty():false, size():5, capacity():10        // VectorPerson::allocSize = 10
PersonManager::run() starts

====================== Person Management Menu ===================
= 0.Exit 1.Display 2.Append 3.Clear 4.Login(CurrentUser, ch6)   =
=================================================================
Menu item number? 4
user name: p0
password: 

+++++++++++++++++++++ Current User Menu ...
+ 10.DefaultParameter(6_1) 11.StaticMember(6_1)                +
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Menu item number? 10
Person::Person(...): 0 0 false ::
Person::Person(...):ps2 0 0 false ::
Person::Person(...):ps3 3 0 false ::
Person::Person(...):ps4 4 70.4 false ::
Person::Person(...):ps5 5 70.5 true ::
Person::Person(...):ps6 6 70.6 true :ps6 address:

Memo m1;
------- Memo -------              // 디폴트 생성자에 의해 메모가 ""이다.
--------------------

Memo m2(pUser->getMemo())         // pUser의 메모 내용이 현재 ""이기 때문이다.
------- Memo -------
--------------------
Person::~Person():ps6 6 70.6 true :ps6 address:
Person::~Person():ps5 5 70.5 true ::
Person::~Person():ps4 4 70.4 false ::
Person::~Person():ps3 3 0 false ::
Person::~Person():ps2 0 0 false ::
Person::~Person(): 0 0 false ::

===============================================================================
== [문제 1] 실행 결과 - 2
=============================================================================== 

******************************* Main Menu  ...
Menu item number? 1
====================== Person Management Menu ...
Menu item number? 4
user name: p0
password: 

+++++++++++++++++++++ Current User Menu ...
+ 6.IsSame 7.InputPerson 8.ChangePasswd(4_2) 9.ManageMemo(4_3) + ...
Menu item number? 9

// Memo::run() 실행 초기에 mStr = memoData로 mStr 초기 값 새로 설정

++++++++++++++++++++++ Memo Management Menu +++++++++++++++++++++
+ 0.Exit 1.DisplayMemo 2.FindString 3.CompareWord 4.DispByLine  + ...
Menu item number? 0 

// CurrentUser::manageMemo(): 메모에서 바로 빠져 나오면서 
// CurrentUser::pUser의 메모를 새로 설정함: pUser.setMemo(memo.c_str())
                    
+++++++++++++++++++++ Current User Menu ...
+ 10.DefaultParameter(6_1) 11.StaticMember(6_1)                +
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Menu item number? 10
Person::Person(...): 0 0 false ::
...
Person::Person(...):ps6 6 70.6 true :ps6 address:

Memo m1;
------- Memo -------
--------------------

Memo m2(pUser->getMemo())  // pUser의 메모가 위 메모 메뉴에서 빠져 나오면서 새로 설정되었음
------- Memo -------
The Last of the Mohicans
James Fenimore Cooper
Author's Introduction
It is believed that the scene of this tale, and most of the information
necessary to understand its allusions, are rendered sufficiently 
obvious to the reader in the text itself, or in the accompanying notes.
Still there is so much obscurity in the Indian traditions, and so much
confusion in the Indian names, as to render some explanation useful.
Few men exhibit greater diversity, or, if we may so express it, 
greater antithesis of character, 
than the native warrior of North America.
--------------------
Person::~Person():ps6 6 70.6 true :ps6 address:
...
Person::~Person(): 0 0 false ::


/******************************************************************************
 * [문제 2] static 멤버 변수 및 static 멤버 함수를 활용한 전역변수 및 전역함수
 ******************************************************************************/
// 지금까지는 UI를 namespace로 정의하고 그 속에 전역 함수로 각종 입력 함수들을 구현하였다. 이제
// namespace를 클래스로 전환하고 모든 멤버들을 static으로 선언하여 동일한 효과를 가지도록 해보자.
//----------------------------------------------------------------------------
// 1) namespace UI { } 을 class UI { }로 변경하라. 그리고 클래스 선언부와 구현부로 나누자.
// 2) 선언부: class UI { } 내에는 멤버들을 선언만하라. 
//          멤버 변수는 선언만 하고 초기화는 하지마라. (초기화는 일단 삭제하라.)
//    구현부: 기존에 구현된 함수들은 모두 클래스 바깥으로 옮긴다.
//    즉, 클래스 내부에서는 멤버 함수 선언만 하고, 함수 구현은 클래스 바깥에서 하라.
// 3) 클래스 바깥에서 멤버 변수들을 아래처럼 다시 선언하고 초기화하라. (클래스 안에서는 선언만 할 것)
//    static 멤버 변수 값을 초기화할 때는 함수 바깥에서 아래처럼 해야 한다.
//----------------------------------------------------------------------------
bool UI::echo_input = false;
string UI::line, UI::emptyLine; // ""로 초기화됨
//----------------------------------------------------------------------------
// 4) 클래스 안에 선언된 모든 멤버 변수 및 멤버 함수들을 static으로 선언하라.
//    클래스 바깥에서 멤버들의 값을 초기화할 때는 static을 붙이지 않는다.
// 5) 클래스 안에서 멤버 변수 line, emptyLine만 private 영역에 배치하고,
//    나머지 멤버 변수 및 함수들은 모두 public 영역에 배치하라.
// 6) 함수 바깥으로 옮겨진 모든 구현 함수들의 이름 앞에 UI::를 모두 붙인다.
//----------------------------------------------------------------------------
// 7) 이상의 변경된 내용을 확인하기 위한 아래 코드를 CurrentUser::run() 앞에 추가하고,
//    CurrentUser::run()의 func_arr[]에 적절한 원소를 추가하라. 
// 8) 그리고 아래 TODO 부분을 구현하라.
//----------------------------------------------------------------------------

void CurrentUser::staticMember() { // Menu item 11

    TODO: string 변수 word1을 선언하고 클래스 이름을 사용하여 UI의  
          getNext("Input a word: ")를 호출한 후 리턴 값으로 word1 변수를 초기화하라.
    cout << "UI::getNext(): " << word1 << endl << endl;

    UI ui;

    TODO: string 변수 word2을 선언하고 UI의 객체인 ui 이름으로 
          getNext("Input a word: ")를 호출한 후 리턴 값으로 word2 변수를 초기화하라.
    cout << "ui.getNext() : " << word2 << endl;
}

===============================================================================
== [문제 2] 실행 결과
=============================================================================== 
...
+++++++++++++++++++++ Current User Menu ...
+ 10.DefaultParameter(6_1) 11.StaticMember(6_1)                +
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Menu item number? 11
Input a word: access_by_CLASS_name_UI     // 사용자 입력
UI::getNext(): access_by_CLASS_name_UI

Input a word: access_by_OBJECT_name_ui    // 사용자 입력
ui.getNext() : access_by_OBJECT_name_ui

//----------------------------------------------------------------------------
// 확인: UI 클래스의 static 멤버들이 어떻게 호출되는지 확인하라. 이를 위해 먼저 소스 편집기에서 
//      단어찾기 기능[Ctrl+f]을 사용하여 "UI::" 단어를 모두 검색하여 확인해 보기 바란다.
//      UI가 namespace이든 또는 class이든 모두 멤버 함수들을 호출하는 방식은 동일하다.
//----------------------------------------------------------------------------

/******************************************************************************
 * [문제 2-1] static 멤버 함수를 활용한 전역함수
 ******************************************************************************/
// Factory 클래스와 PersonManager::factory 멤버를 잘 살펴보자. 
// Factory 클래스의 경우 inputPerson() 멤버 함수만 존재하고 멤버 변수는 존재하지 않는다. 
// 이런 경우 inputPerson()를 전역함수로 만들고 PersonManager에서 바로 이 함수를
// 호출하게 하면, 굳이 PersonManager::factory 멤버를 만들 필요가 없게 된다.
//----------------------------------------------------------------------------
// 1) Factory::inputPerson(istream* in) 함수를 static 함수로 변경하라.
// 2) PersonManager 클래스에서 
//    i) 아래 멤버 변수를 아래처럼 주석 처리하라. 이 멤버는 더 이상 필요 없다.
         // Factory factory;
//    ii) PersonManager::append() 함수 내에서 Factory의 inputPerson(...) 호출 시
//       변수명 대신 클래스 이름을 이용하여 이 static 함수를 호출하도록 수정하라.

===============================================================================
== [문제 2-1] 실행 결과
=============================================================================== 
...
====================== Person Management Menu ===================
= 0.Exit 1.Display 2.Append 3.Clear 4.Login(CurrentUser, ch6)   =
=================================================================
Menu item number? 2
The number of persons to append? 3
Input 3 [person information] :      // 연속적으로 3명의 아래 인적정보를 입력하라.
Person::Person(...): 0 0 false ::
HongGilDong 0 71.5 false :Gwangju Nam-gu Bongseon-dong 21:
Person::Person(...): 0 0 false ::
LeeMongRyong 1 65 true :Jong-ro 1-gil, Jongno-gu, Seoul:
Person::Person(...): 0 0 false ::
LeeSoonShin 2 80 true :1001, Jungang-daero, Yeonje-gu, Busan:
display(): count 8
[0] p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
[1] p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
[2] p2 12 52.2 false :1001, Jungang-daero, Yeonje-gu, Busan:
[3] p3 13 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
[4] p4 14 64.4 false :88 Gongpyeong-ro, Jung-gu, Daegu:
[5] HongGilDong 0 71.5 false :Gwangju Nam-gu Bongseon-dong 21:
[6] LeeMongRyong 1 65 true :Jong-ro 1-gil, Jongno-gu, Seoul:
[7] LeeSoonShin 2 80 true :1001, Jungang-daero, Yeonje-gu, Busan:
empty():false, size():8, capacity():10


/******************************************************************************
 * [문제 3] 함수 중복(overload)
 ******************************************************************************/
// 아래의 세 Person 멤버 함수들은 모두 멤버 값을 설정하는 함수이며 매개변수의 타입이 모두 다르다.
    void setId(int id);
    void setWeight(double weight);
    void setMarried(bool married);
//----------------------------------------------------------------------------
// 따라서 이들은 함수 중복을 이용하여 동일한 함수 이름을 사용할 수 있다.
// 1) 위 세 함수 이름을 함수 중복을 사용하여 모두 동일한 함수 이름 void set(...)으로 통일하라.
//    즉, 함수는 여전히 세 개인데 함수 이름만 동일하게 하라는 것이다. 
// 2) CurrentUser::setter()에서 위 세 함수 호출을 바뀐 함수 이름 set()을 이용하도록 수정하라.
//    setName()과 setAddress()는 수정하지 마라.

===============================================================================
== [문제 3] 실행 결과
=============================================================================== 
...
+++++++++++++++++++++ Current User Menu ++++++++++++++++++++++++
+ 0.Logout 1.Display 2.Getter 3.Setter 4.Set 5.WhatAreYouDoing + ...
Menu item number? 3
Person::Person(...):pp 0 0 false ::
pp->setMembers():pp 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
Person::~Person():pp 10 70 false :Gwangju Nam-gu Bongseon-dong 21:


/******************************************************************************
 * [문제 4] 함수 중복(overload)
 ******************************************************************************/
// 아래의 Memo 멤버 함수들은 멤버 값을 설정하거나 얻어 오는 함수인데 하나는 매개변수가 없고 다른 하나는
// 매개변수가 하나이다. 따라서 이들 역시 함수 중복을 이용하여 동일한 함수 이름을 사용할 수 있다.
    const char *get_c_str();
    void set_c_str(const char *c_str);
//----------------------------------------------------------------------------
// 1) 위 두 함수 이름를 함수 중복을 사용하여 동일한 함수 이름 c_str로 통일하라.
//    즉, 여전히 함수는 두 개인데 함수 이름은 동일하게 구현하라는 것이다. 
//----------------------------------------------------------------------------
// 2) CurrentUser::manageMemo(), AllocatedMember::manageMemo(), 
//    AllocatedMember::nullptrMember() 에서 바뀐 함수 이름 c_str을 이용하도록 수정하라.
//
//    참고로 수정할 때 함수 이름을 출력하는 메시지가 있을 경우 이 역시 수정해 주어야 한다. 예를 들어, 
//    cout << "memo.set_c_str(u.getMemo())" << endl; 는 아래처럼 수정되어야 한다.
//    cout << "memo.c_str(u.getMemo())" << endl; 
//----------------------------------------------------------------------------

===============================================================================
== [문제 4] 실행 결과
== 메뉴는 모두 생략하였음
=============================================================================== 
******************************* Main Menu ...
Menu item number? 1
...
Menu item number? 4
user name: p0
password: 
Menu item number? 9
Menu item number? 0
Menu item number? 10
...
Memo m2(pUser->getMemo())
------- Memo -------
The Last of the Mohicans
James Fenimore Cooper
Author's Introduction
It is believed that the scene of this tale, and most of the information
necessary to understand its allusions, are rendered sufficiently 
obvious to the reader in the text itself, or in the accompanying notes.
Still there is so much obscurity in the Indian traditions, and so much
confusion in the Indian names, as to render some explanation useful.
Few men exhibit greater diversity, or, if we may so express it, 
greater antithesis of character, 
than the native warrior of North America.
--------------------
...
Menu item number? 0
Menu item number? 0

******************************* Main Menu ...
Menu item number? 4
Menu item number? 3
Menu item number? 1
------- Memo -------
It is believed that the Aborigines of the American continent
--------------------

Menu item number? 0

memo.run() returned
------ u memo ------
It is believed that the Aborigines of the American continent
--------------------

Menu item number? 5
u 1 70 true :NAMDAEMUN-RO 123, JONGNO-GU, SEOUL, KOREA:
------ u memo ------
It is believed that the Aborigines of the American continent
--------------------

set address = memo_c_str = nullptr
u 1 70 true ::
------ u memo ------
--------------------

memo.c_str(u.getMemo())
------- Memo -------
--------------------

u.setMemo(memo.c_str())
------ u memo ------
--------------------


/******************************************************************************
 * [문제 5] 참조 변수 활용하기
 *         함수의 포인터 매개변수를 참조변수로 변경, 함수 호출 시 주소 대신 참조 넘겨 주기
 ******************************************************************************/
// 지금껏 CurrentUser 클래스에서는 포인터 변수 pUser를 이용하여 Person 객체에 접근했다.
// 이제 이들을 참조 변수로 변경해서 참조 변수를 이용하여 Person 객체에 접근하도록 해 보자.
//----------------------------------------------------------------------------
// 1) 먼저 class CurrentUser에 Person* pUser로 선언된 변수를 아래처럼 참조변수로 변경하라.
    Person& rUser;
// 2) 생성자 CurrentUser(Person* pUser)의 매개변수를 아래처럼 변경하라.
    CurrentUser(Person& rUser)
// 3) class CurrentUser의 클래스 내부 및 외부 구현 함수에서 
//    i) 모든 pUser 변수를 rUser 변수로 이름을 변경하라.
//    ii) 또한 모든 rUser-> 를 rUser. 로 변경하라.
//    iii) CurrentUser::Inputperson()에서 UI::inputPerson(...)을 호출할 때 
//         적절한 포인터 인자(&rUser)를 넘겨 주어라.
// 6) PersonManager::login() 에서 CurrentUser(...).run() 호출할 때
//    생성자 CurrentUser(...)의 인자로 p가 포인터하는 객체의 참조(*p)를 넘겨 주어라.
//----------------------------------------------------------------------------
// 7) CurrentUser::setter()와 CurrentUser::set()에서 아래의 문장을 삭제하고,
    Person* pp = new Person("pp");
//    대신 아래의 문장으로 대체하라.
    Person p("rp"), &rp = p; // Person p("rp"); Person& rp = p;와 동일
//    그리고 위 두 함수 내에서 포인터 변수 pp 대신 참조변수 rp를 사용하도록 코드를 수정하라.
//    출력문에서도 "pp->" 대신 "rp."를 사용하도록 수정하라.
//    기존의 delete 문장은 삭제하라.

===============================================================================
== [문제 5] 실행 결과
=============================================================================== 
+++++++++++++++++++++ Current User Menu ++++++++++++++++++++++++
+ 0.Logout 1.Display 2.Getter 3.Setter 4.Set 5.WhatAreYouDoing +
+ 6.IsSame 7.InputPerson 8.ChangePasswd(4_2) 9.ManageMemo(4_3) +
+ 10.DefaultParameter(6_1) 11.StaticMember(6_1)                +
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Menu item number? 
// 위 1 ~ 11 메뉴 항목을 모두 실행해 보고, 실행 결과는 test_5.out 파일을 참조하라.


/******************************************************************************
 * [문제 6] 참조 변수 활용하기, 함수의 매개변수를 참조변수로 변경, 함수 호출 시 참조 넘겨 주기
 ******************************************************************************/
// 지금껏 Person 객체의 출력하는 모든 함수들은 매개변수의 타입이 ostream* 을 사용하였다.
// 이제 이들도 참조 매개변수로 변경해 보자. 즉,
//----------------------------------------------------------------------------
// Person::print(ostream* pout)와 Person::printMembers(ostream* pout)의 
// 1) 매개변수 타입과 변수 이름을 (ostream& out)로 변경하라. 
// 2) 이 변경된 매개변수 타입과 변수 이름에 따라 함수 코드 내용도 적절히 수정하라.
//    즉, printMembers()에서 *pout 부분 수정
// 3) 이들 함수를 호출하는 부분을 찾아서 호출함수의 인자를 포인터가 아닌 참조를 넘겨 주도록 수정하라.
//    즉, println()에서 print(&cout) 호출할 때

===============================================================================
== [문제 6] 실행 결과
=============================================================================== 
******************************* Main Menu *********************************
* 0.Exit 1.PersonManager(ch3_2, 4, 6)                                     *
* 2.Class:Object(ch3_1) 3.CopyConstructor(ch5_1) 4.AllocatedMember(ch5_2) *
***************************************************************************
Menu item number? 1
Person::Person(...):p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
...
Person::Person(const Person&):p4 14 64.4 false :88 Gongpyeong-ro, Jung-gu, Daegu:
display(): count 5                              // 아래 인적정보가 정상적으로 출력되어야 함 
[0] p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
[1] p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
[2] p2 12 52.2 false :1001, Jungang-daero, Yeonje-gu, Busan:
[3] p3 13 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
[4] p4 14 64.4 false :88 Gongpyeong-ro, Jung-gu, Daegu:
empty():false, size():5, capacity():10
PersonManager::run() starts


/******************************************************************************
 * [문제 7] 참조 변수 활용하기, 함수의 매개변수를 참조변수로 변경, 함수 호출 시 참조 넘겨 주기
 ******************************************************************************/
// 지금껏 Person 객체의 입력하는 모든 함수들은 매개변수의 타입이 istream* 을 사용하였다.
// 이제 이들도 참조 매개변수로 변경해 보자. 즉,
//----------------------------------------------------------------------------
// Person::inputMembers(istream* pin), Person::input(istream* pin),
// UI::checkInputError(istream* pin, ...), UI::checkDataFormatError(istream* pin)
// Factory::inputPerson(istream* in) 등에서
//----------------------------------------------------------------------------
// 1) 매개변수 타입과 변수 이름을 모두 (istream& in)로 변경하라. 
// 2) 이 변경된 매개변수 타입과 변수 이름에 따라 함수 코드 내용도 적절히 수정하라.
//    즉, *pin, pin-> 등을 절절히 수정하라.
// 3) 이들 함수를 호출하는 부분을 찾아서 호출함수의 인자를 포인터가 아닌 참조를 넘겨 주도록 수정하라.
      UI::inputPerson(Person* p)에서 input(&cin), checkDataFormatError(&cin) 호출할 때
      UI::getInt(const string msg)에서 checkInputError(&cin, ...) 호출할 때
      PersonManager::append()에서 Factory의 inputPerson(&cin) 호출 때

===============================================================================
== [문제 7] 실행 결과
=============================================================================== 

******************************* Main Menu ...
Menu item number? 1
...
====================== Person Management Menu ...
Menu item number? 2
The number of persons to append? 3
Input 3 [person information] :
Person::Person(...): 0 0 false ::
HongGilDong 0 71.5 false :Gwangju Nam-gu Bongseon-dong 21:
Person::Person(...): 0 0 false ::
LeeMongRyong 1 65 true :Jong-ro 1-gil, Jongno-gu, Seoul:
Person::Person(...): 0 0 false ::
LeeSoonShin 2 80 true :1001, Jungang-daero, Yeonje-gu, Busan:
display(): count 8
[0] p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
[1] p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
[2] p2 12 52.2 false :1001, Jungang-daero, Yeonje-gu, Busan:
[3] p3 13 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
[4] p4 14 64.4 false :88 Gongpyeong-ro, Jung-gu, Daegu:
[5] HongGilDong 0 71.5 false :Gwangju Nam-gu Bongseon-dong 21:
[6] LeeMongRyong 1 65 true :Jong-ro 1-gil, Jongno-gu, Seoul:
[7] LeeSoonShin 2 80 true :1001, Jungang-daero, Yeonje-gu, Busan:
empty():false, size():8, capacity():10

====================== Person Management Menu ...
Menu item number? 4
user name: p0
password: 

+++++++++++++++++++++ Current User Menu ...
Menu item number? 7
input person information:
user 1 71.1 true :Gwangju Nam-ro 21:
user 1 71.1 true :Gwangju Nam-ro 21:


/******************************************************************************
 * [문제 8] 참조 변수 활용하기, 함수의 매개변수를 참조변수로 변경, 함수 호출 시 참조 넘겨 주기
 ******************************************************************************/
// 1) UI::inputPerson(Person* p)의 매개변수 타입을 (Person& p)로 변경하라. 
// 2) 위 함수를 호출하는 부분을 찾아서 호출 함수의 인자를 포인터가 아닌 참조를 넘겨 주도록 수정하라.
      CurrentUser::inputPerson(), CopyConstructor::inputPerson(), 
      AllocatedMember::inputPerson() 등에서 UI::inputPerson(...)을 호출할 때 인자 수정

===============================================================================
== [문제 8] 실행 결과
=============================================================================== 
// test_8.in과 동일하게 입력하여 실행하고 실행 결과는 test_8.out 파일을 참조하라.


/******************************************************************************
 * [문제 9]
 ******************************************************************************/
// 지금까지 아래 모든 함수의 호출방식은 call by value이고 (객체를 복사하여 매개변수로 넘겨 줌)
// 리턴 시에는 return with value 방식이었다. (객체를 복사하여 리턴함)
// 이 방식은 사용하기에는 편하고 기본 데이타 타입의 경우 메모리 크기가 작기 때문에 문제가 없었다.
// 그러나 string, Person과 같은 객체의 경우 크기가 매우 크기 때문에 value를 직접 함수 인자로
// 넘기고 함수 리턴 값으로 받기에는 오버헤드가 크다. (객체를 복사해야 하므로)
//----------------------------------------------------------------------------
// 따라서 가능하면 함수의 매개변수로 객체를 넘길 때 call by value가 아닌 call by reference로 
// 넘기고 객체를 반환할 때도 value로 리턴하기보다는 가능하면 참조를 리턴하도록 하자.
// 참고로 참조(reference)는 단순히 주소 값만을 넘겨 주는 방식이므로 오버헤드가 크지 않다.
//----------------------------------------------------------------------------
// 1) 아래 함수의 모든 매개변수 타입 const string을 const string& 로 교체하라.
//    const는 해당 매개변수를 그 함수 내에서 수정하지 않고 읽기만 한다는 의미이다.
//----------------------------------------------------------------------------
class Person: Person(), set(), setPasswd(), setName(), isSame()
class UI: checkInputError(), getNext(), getNextLine(), getInt(), getPositiveInt(),
          getIndex(), selectMenu()
class Memo: get_next_line(), getNext()
class PersonManager: printNotice(), findByName()
//----------------------------------------------------------------------------
// 2) 아래 모든 함수의 리턴 데이타 타입을 string에서 const string& 로 교체하라.
//    리턴된 문자열이 const이므로 해당 문자열을 수정할 수는 없고 읽기만 해야 한다. 
//----------------------------------------------------------------------------
class Person: getName(), getPasswd()
//----------------------------------------------------------------------------
// 3) 아래 모든 함수의 리턴 데이타 타입을 string에서 string& 로 교체하라.
//    const가 없으므로 리턴된 문자열을 수정할 수 있다.
//----------------------------------------------------------------------------
class Memo: get_next_line(), getNext()
//----------------------------------------------------------------------------
// 4) 아래 함수의 모든 매개변수 타입 size_t*를 size_t&로 교체하고(포인터변수에서 참조변수로 변환), 
//    이들 함수 코드 내에서 매개변수의 타입 변경으로 인해 수정해야 할 부분이 있으면 적절히 수정하라.
//    그리고 이들 함수를 호출하는 곳을 찾아 포인터 대신 참조가 함수 인자로 넘어 가도록 수정하라. 
class Memo: get_next_line(), find_line(), getNext()
//----------------------------------------------------------------------------
// 5) 아래 함수에서 매개변수 word와 line을 추가하고, 마지막 문장을 아래처럼 수정하라.
//    아래 코드는 잘라낸 서브 문자열을 참조변수인 word 또는 line에 저장한다.
//    그리고 word 또는 line의 참조를 반환한다. 
//    따라서 이 함수를 호출한 곳에서는 잘라낸 서브 문자열을 word 또는 line을 통해 넘겨 받고
//    또한 반환된 참조를 이용하여 서브 문자열에 접근해도 된다.
//----------------------------------------------------------------------------
string& Memo::getNext(size_t& pos, string& word) {
    ...
    word = mStr.substr(함수 인자는 기존의 본인 코드를 사용하라);
    return word;
}

string& Memo::get_next_line(size_t& pos, string& line) {
    ...
    line = mStr.substr(함수 인자는 기존의 본인 코드를 사용하라);
    return line;
}
//----------------------------------------------------------------------------
// 6) Memo::compareWord() 함수 내에서 for 문을 아래처럼 수정하라.
//    혹시 아래 코드의 변수명이 본인의 변수명과 다르면 적절히 수정해도 된다. 
//    아래 코드는 위 변경된 getNext() 함수의 호출과 
//    반환된 값을 활용하는 방법을 보인 것이다.
//----------------------------------------------------------------------------
    for (size_t pos = 0; !getNext(pos, next).empty(); ) {
//----------------------------------------------------------------------------
// 7) 마찬가지로 Memo::dispByLine() 함수 내에서 
//    get_next_line()를 호출하는 코드를 아래처럼 수정하라.
//----------------------------------------------------------------------------
        string line;
        get_next_line(pos, line);

===============================================================================
== [문제 9] 실행 결과
=============================================================================== 
// test_9.in과 동일하게 입력하여 실행하고 실행 결과는 test_9.out 파일을 참조하라.



/******************************************************************************
 * 자동 오류 체크 모드로 프로그램 실행
 ******************************************************************************/
// 1. clc.chosun.ac.kr의 [강의자료실]에서 CH6_1 과제 테스트 파일을 다운받은 후 
//    압축 파일을 풀고 test 폴더를 드래깅하여 이클립스의 [Project Explorer]의 
//    [CH6_1] 프로젝트 위에 드랍한다. (test 폴더와 그 밑에 테스트용 파일이 있어야 함)
// 2. 기존 프로젝트 CH2의 src 폴드에 있는 check_error.h를 CH6_1 프로젝트의 
//    src 폴더로 복사하라. (파일 선택 후 [Ctrl+C], src 폴더를 선택 후 [Ctrl+V])
// 3. 소스 파일 맨 앞쪽에 있는 AUTOMATIC_ERROR_CHECK 상수 값을 true로 설정하라.
// 4. main() 함수 내의 evaluate(true)가 true로 설정되어 있는지 확인하라.
// 5. 프로그램 테스트를 위한 입출력 파일이 test 폴더에 다운로드 되어 있는지 확인하라.
// 6. 프로그램이 정상적으로 구현되었다면 아래 [프로그램 실행 결과]와 같이 출력될 것이다.
===============================================================================
== 1. 정상적인 프로그램 실행 결과
=============================================================================== 
test 1 : O
test 2 : O
test 3 : O
test 4 : O
test 5 : O
test 6 : O
test 7 : O
test 8 : O
test 9 : O
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