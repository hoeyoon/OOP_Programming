```
[6장 문제-2]

//----------------------------------------------------------------------------
// 아래 문제를 해결하는 도중 출력이 잘못되었거나 문제 설명과 출력이 일치하지 않거나 오타가 있거나 등등
// 조금이라도 문제에 이상한 것이 있으면 주저하지 말고 jhshim@chosun.ac.kr로 알려 주시기 바랍니다.
//----------------------------------------------------------------------------

/******************************************************************************
 * 프로젝트 및 소스파일 생성
 ******************************************************************************/
// 기존의 과제를 수행했던 이클립스의 작업공간에서 새로운 프로젝트 CH6_2를 만들고 
// 그 밑에 src 풀더를 만든 후 src 폴더 밑에 ch6_2.cpp 소스파일을 만들어라.

/******************************************************************************
 * 코드 추가 및 변경 1
 ******************************************************************************/
// 1) 기존에 작성했던 ch6_1.cpp의 내용을 모두 복사해서 ch6_2.cpp에 삽입하라.
// 2) 프로그램의 맨 앞쪽 주석 부분의 "Author: " 행 다음의 내용을 아래 *로 시작하는 행들로 교체하라.
//----------------------------------------------------------------------------
 *
 *  + class VectorPerson: erase(), insert() 추가
 *  + class PersonManager: remove(), insert() 추가
 *  + class ClassAndObject: 멤버 객체 변수의 초기화 시점 및 방법 추가
 *        (멤버 선언시, 생성자 서두, 생성자 본체 등)
 *        함수 선언 시 매개변수 const의 필요성 제기
 *  + 이를 위해 class Init1 ~ class Init6 추가, ClassAndObject 내부에
 *        memberInitialization(), class Parameter, normalParameter(),
 *        constParameter(), temporaryParameter(), stringParameter(),
 *        parameters() 멤버 추가
 */

/******************************************************************************
 * 코드 변경 2
 ******************************************************************************/
// VectorPerson에 아래 두 멤버 함수를 추가하고, 클래스 내부에도 두 함수를 선언하라.
//-----------------------------------------------------------------------------
void VectorPerson::erase(int index) { }
void VectorPerson::insert(int index, Person* p) { }

/******************************************************************************
 * 코드 변경 3
 ******************************************************************************/
// PersonManager의 구현부에 아래 두 멤버 함수를 추가하고 
//           클래스 선언부에 두 함수의 선언을 추가하라.
//-----------------------------------------------------------------------------
void PersonManager::insert() { // Menu item 5
}

void PersonManager::remove() { // Menu item 6
}

//-----------------------------------------------------------------------------
// PersonManager::run()에 아래 메뉴의 변경된 부분을 반영하고, 
// 위 추가된 두 멤버 함수의 주소를 func_arr[]에 추가하라.
//-----------------------------------------------------------------------------
    string menuStr =
        "====================== Person Management Menu ===================\n"
        "= 0.Exit 1.Display 2.Append 3.Clear 4.Login(CurrentUser, ch6)   =\n"
        "= 5.Insert(6_2) 6.Delete(6_2)                                   =\n"
        "=================================================================\n";


/******************************************************************************
 * [문제 1] Person 객체 원소 삭제
 ******************************************************************************/
// VectorPerson::erase(int index)를 구현하라. 
//----------------------------------------------------------------------------

// 이 함수는 pVector[index] 원소를 삭제한다.
void VectorPerson::erase(int index) {
    index가 음수이거나 마지막 원소보다 큰 인덱인 경우 바로 리턴하라.
    pVector[index] 원소를 삭제하라. 
        즉, for 문을 이용하여 
               [index+1] 원소부터 마지막 원소까지 모두 왼쪽으로 한칸씩 이동시켜라.
    pVector에 삽입된 원소의 개수를 하나 줄인다.
}

//----------------------------------------------------------------------------
// PersonManager::remove()를 구현하라. 
//----------------------------------------------------------------------------

// 이 함수는 사용자로부터 벡터 persons에 저장된 Person 객체 중 삭제할 인덱스를 입력 받고 
// 위 VectorPerson::erase()를 호출하여 해당 원소를 삭제한다.
void PersonManager::remove() { // Menu item 6
    벡터 persons가 비어 있을 경우 아래 메시지만 출력하고 바로 리턴하라.
        cout << "No entry to remove" << endl;
    UI::getIndex("Index to delete? ", persons.size())를 호출하여 삭제할
    Person 객체의 인덱스를 사용자로부터 입력 받는다.
    persons의 index 위치에 저장된 포인터가 포인트하는 Person 객체의 메모리를 반납한다.
    persons의 위 VectorPerson::erase(...)를 호출하여 index 원소를 삭제하라.
    display();
}

===============================================================================
== [문제 1] 실행 결과
=============================================================================== 
******************************* Main Menu ...
Menu item number? 1
...
====================== Person Management Menu ===================
= 0.Exit 1.Display 2.Append 3.Clear 4.Login(CurrentUser, ch6)   =
= 5.Insert(6_2) 6.Delete(6_2)                                   =
=================================================================
Menu item number? 6
Index to delete? -1
Input a positive INTEGER.
Index to delete? 5
5: OUT of selection range(0 ~ 4)
Index to delete? 0
Person::~Person():p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
display(): count 4
[0] p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
[1] p2 12 52.2 false :1001, Jungang-daero, Yeonje-gu, Busan:
[2] p3 13 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
[3] p4 14 64.4 false :88 Gongpyeong-ro, Jung-gu, Daegu:
empty():false, size():4, capacity():10
...
Menu item number? 6
Index to delete? 0
Person::~Person():p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
display(): count 3
[0] p2 12 52.2 false :1001, Jungang-daero, Yeonje-gu, Busan:
[1] p3 13 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
[2] p4 14 64.4 false :88 Gongpyeong-ro, Jung-gu, Daegu:
empty():false, size():3, capacity():10
...
Menu item number? 6
Index to delete? 0
...
Menu item number? 6
Index to delete? 0
...
Menu item number? 6
Index to delete? 0
Person::~Person():p4 14 64.4 false :88 Gongpyeong-ro, Jung-gu, Daegu:
display(): count 0
empty():true, size():0, capacity():10
...
Menu item number? 6
No entry to remove


/******************************************************************************
 * [문제 2] Person 객체 삽입
 ******************************************************************************/
// VectorPerson::insert()를 구현하라. 
//----------------------------------------------------------------------------

// 이 함수는 pVector의 index 위치에 새로운 원소를 삽입한다.
void VectorPerson::insert(int index, Person* p) {
    현재 벡터 내에 삽입된 원소의 개수가 할당된 원소의 개수와 같거나 큰 경우
        기존 함수를 호출하여 pVector의 용량을 먼저 확장한다. [push_back() 참조]
    for문을 이용하여 pVector의 마지막 원소에서부터 index까지 모두 한칸씩 오른쪽으로 이동시킨 후
    index 위치에 p를 저장한다.
    삽입된 원소 개수를 하나 늘린다.
}

//----------------------------------------------------------------------------
// PersonManager::insert()를 구현하라. 
//----------------------------------------------------------------------------

// 이 함수는 새로운 Person 객체를 동적으로 할당한 후 
// 사용자로부터 벡터 persons에 삽일할 위치와 새로운 인적정보를 입력 받아 할당된 객체에 저장하고 
// 이 객체를 위 VectorPerson::insert()를 호출하여 해당 객체 포인터를 persons에 삽입한다.
void PersonManager::insert() { // Menu item 5
    persons 벡터가 비어 있을 경우 삽입할 index 위치를 무조건 0으로 설정하고
    그렇지 않은 경우 UI::getIndex()를 호출하여 사용자로부터 입력할 위치(index)를 입력 받아라.
        주의: 기존 원소의 맨 끝에 추가하는 것도 가능해야 한다.(인덱스 값의 범위에 주의)
             UI::getIndex() 호출 시 출력할 메시지는 실행 결과를 참조하라.
    printNotice(...); // 호출 시 이 함수 인자는 append()와 실행 결과를 참조하여 완성하라.
    새로운 Person 객체를 할당받고 인적정보를 입력 받은 후 새 변수 p에 저장
       (위 문장은 append() 함수 참조) 
    if (p == nullptr) return;
    persons 벡터의 index 위치에 p를 삽입하라.
    display();
}
/* 입력할 때 아래 인적 정보를 복사하여 입력하면 편리하다.
HongGilDong 0 71.5 false :Gwangju Nam-gu Bongseon-dong 21:
LeeMongRyong 1 65 true :Jong-ro 1-gil, Jongno-gu, Seoul:
LeeSoonShin 2 80 true :1001, Jungang-daero, Yeonje-gu, Busan:
*/

===============================================================================
== [문제 2] 실행 결과
=============================================================================== 
====================== Person Management Menu ...
Menu item number? 5 // 사용자 입력
Index to insert in front? 0 // 사용자 입력
Input [person information] to insert:
Person::Person(...): 0 0 false ::
HongGilDong 0 71.5 false :Gwangju Nam-gu Bongseon-dong 21: // 사용자 입력
display(): count 6
[0] HongGilDong 0 71.5 false :Gwangju Nam-gu Bongseon-dong 21:
[1] p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
[2] p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
[3] p2 12 52.2 false :1001, Jungang-daero, Yeonje-gu, Busan:
[4] p3 13 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
[5] p4 14 64.4 false :88 Gongpyeong-ro, Jung-gu, Daegu:
empty():false, size():6, capacity():10
...
Menu item number? 5
Index to insert in front? 6
Input [person information] to insert:
Person::Person(...): 0 0 false ::
LeeMongRyong 1 65 true :Jong-ro 1-gil, Jongno-gu, Seoul:
display(): count 7
[0] HongGilDong 0 71.5 false :Gwangju Nam-gu Bongseon-dong 21:
[1] p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
[2] p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
[3] p2 12 52.2 false :1001, Jungang-daero, Yeonje-gu, Busan:
[4] p3 13 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
[5] p4 14 64.4 false :88 Gongpyeong-ro, Jung-gu, Daegu:
[6] LeeMongRyong 1 65 true :Jong-ro 1-gil, Jongno-gu, Seoul:
empty():false, size():7, capacity():10
...
Menu item number? 3 // 모두 삭제
Person::~Person():HongGilDong 0 71.5 false :Gwangju Nam-gu Bongseon-dong 21:
Person::~Person():p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
Person::~Person():p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
Person::~Person():p2 12 52.2 false :1001, Jungang-daero, Yeonje-gu, Busan:
Person::~Person():p3 13 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
Person::~Person():p4 14 64.4 false :88 Gongpyeong-ro, Jung-gu, Daegu:
Person::~Person():LeeMongRyong 1 65 true :Jong-ro 1-gil, Jongno-gu, Seoul:
display(): count 0   // 비었음
empty():true, size():0, capacity():10
...
Menu item number? 5  // 비어 있으면 "Index to insert in front? " 출력되지 말아야 함 
Input [person information] to insert:
Person::Person(...): 0 0 false ::
LeeSoonShin 2 80 true :1001, Jungang-daero, Yeonje-gu, Busan:
display(): count 1
[0] LeeSoonShin 2 80 true :1001, Jungang-daero, Yeonje-gu, Busan:
empty():false, size():1, capacity():10


/******************************************************************************
 * [문제 3] 
 ******************************************************************************/
// 이제부터 클래스의 멤버 변수가 언제, 어떻게 초기화되는지 확인해 보자.
// 우선 아래 주석문과 class Init1 과 그 뒤의 memberInitialization() 함수를
// 기존 class ClassAndObject {} 내의 globalStaticLocalObjects() 함수 
// 뒤쪽(아래쪽)에 배치하라. 클래스 안에 또 다른 서브 클래스 Init1을 선언할 수 있다.
//----------------------------------------------------------------------------

    // 이 클래스는 기본 생성자 Init1()가 없기 때문에 컴파일러가 자동으로 기본 생성자를 생성해 준다. 
    // 이 기본 생성자에 의해 여기서는 다행히 모든 멤버가 0으로 초기화되는데 
    // 이는 컴파일러마다 다르게 실행될 수 있다.
    // 따라서 사용자가 직접 생성자를 만들어 초기화시켜 주는 습관을 가지는 것이 좋다.
    class Init1 { // ch6_2 추가
        Person p;
        int i, j;
        double d;
        char name[5];
    public:
        void print() {
            // d = i = j = 0;
            cout << "Init1 i: " << i << ", j: " << j << 
                    ", d: " << d << ", name: " << name << endl;
        }
    };

    void memberInitialization() { // Menu item 5
        int i = 0, i2 = i; i = i2; // 의미 없는 문장이지만, 삭제하지 말 것
        
        // 임시객체 생성 후 print()를 호출하고 바로 소멸된다.
        Init1().print(); cout << endl;
        //Init2().print(); cout << endl;
        //Init3().print(); cout << endl;
        //Init4().print(); cout << endl;
        //Init5().print(); cout << endl;
        //Init6().print();
    }

//----------------------------------------------------------------------------
// ClassAndObject::run()의 메뉴 문자열 menuStr에 아래 메뉴 항목을 추가하고,
            "+ 5.MemberInitialization                            +\n"
// 또한 아래 문장을 ClassAndObject::run() 내의 적절한 위치에 추가한 후
        using CO = ClassAndObject;
// func_arr[]의 각 원소를 CO를 이용해서 간소화시켜라. 즉, ClassAndObject:: -> CO::
// 그리고 func_arr[]에 memberInitialization을 추가하라.

===============================================================================
== [문제 3] 실행 결과
== 만약 컴파일러에 의해 자동으로 모든 멤버가 0으로 초기화되지 않는다면
== Init1::print() 내의 주석(//)을 풀어 모든 멤버가 0이 되도록 하라.
=============================================================================== 

******************************* Main Menu ...
Menu item number? 2

+++++++++++ Person Class And Object Menu ++++++++++++
+ 0.Exit 1.DefualConstructor 2.Constructor          +
+ 3.ConstrucorDestructor 4.GlobalStaticLocalObjects +
+ 5.MemberInitialization                            +
+++++++++++++++++++++++++++++++++++++++++++++++++++++
Menu item number? 5
Person::Person(...): 0 0 false :: // 임시객체 Init1() 생성시 자동으로 p 생성자 실행됨
Init1 i: 0, j: 0, d: 0, name:     // Init1().print() 실행
Person::~Person(): 0 0 false ::   // 임시객체 Init1() 소멸 시 자동으로 멤버 p 소멸


/******************************************************************************
 * [문제 4] 
 ******************************************************************************/
// 아래 주석문과 class Init2를 ClassAndObject 클래스 내의 Init1 클래스 뒤쪽(아래쪽)에 
// 배치하고, memberInitialization() 함수에서 Init2().print()의 주석을 풀어라.
//----------------------------------------------------------------------------

    // 기본 생성자가 있지만 아무것도 실행하지 않는다. 
    // 이럴 경우 객체 멤버들(여기선 p)은 자동으로 기본 생성자가 실행되어 초기화된다.
    // 하지만 기본 데이타 타입 변수(i, j, d)들은 자동으로 초기화되지 않는다.
    // 따라서 필요한 경우 기본 데이타 타입 변수들은 생성자 내에서 반드시 초기화 해 주어야 한다.
    class Init2 {
        Person p;
        int i, j;
        double d;
    public:
        Init2() { /* i = j = 6; d = 0; */ }  // 컴파일 시 j, d가 초기화되지 않았다는 경고 메시지 나올 수도 있음
        void print() { 
            cout << "Init2 i: " << i << ", j: " << j << ", d: " << d << endl; 
        }
    };

===============================================================================
== [문제 4] 실행 결과
=============================================================================== 
...
Person::Person(...): 0 0 false :: // Init2().print() 임시객체 생성시 자동으로 p 생성자 실행됨
Init2 i: 6617528, j: 1877830040, d: 0 // i, j, d는 초기화되지 않아서 임의의 값을 가짐, d는 우연히 0이 된 것임
Person::~Person(): 0 0 false ::   // Init2().print() 실행 후 임시객체가 소멸 시 
                                  // 자동으로 멤버 p 역시 소멸됨

// 확인이 되었으면 Init2() 내의 주석을 풀어 모든 멤버가 초기화 되도록 하라.
Person::Person(...): 0 0 false ::
Init2 i: 6, j: 6, d: 0
Person::~Person(): 0 0 false ::


/******************************************************************************
 * [문제 5] 
 ******************************************************************************/
// 아래 주석문과 class Init3를 ClassAndObject 클래스 내의 Init2 클래스 뒤쪽(아래쪽)에 
// 배치하고, memberInitialization() 함수에서 Init3().print()의 주석을 풀어라.
//----------------------------------------------------------------------------

    // 기본 생성자가 있지만 아무것도 실행하지 않는다. 
    // 그러나 멤버 변수 선언 시에 멤버 p와 i처럼 선언과 동시에 초기화를 할 수 있다.
    // 멤버를 초기화하는 한 방법이지만 추천하고 싶은 방법은 아니다.
    // (일부 컴파일러는 이를 지원하지 않을 수 있는데 그럴경우 class Init4처럼 수정하라.)
    class Init3 {
        Person p { "p-Init3" };  
        // Person p("p-Init3");와 동일한 기능이나 이렇게 표현하면 컴파일 에러가 발생할 것이다.
        // 즉, 함수 리턴 타입이 Person이고 함수 이름 p, 매개변수가 "p-Init3"인 새로운 
        // [함수 선언]으로 컴파일러가 오해하여 에러 메시지(매개변수가 잘못되었다는)를 출력한다.
        // 컴파일러는 함수 선언인지 객체변수 선언인지 구분할 수 없기 때문이다. 
        // 그래서 { }를 사용한다. { }는 객체 변수 선언이며 생성자 함수 인자를 의미한다.
        int i {3}, j;  // i {3}는 i = 3으로 표현해도 됨; 그러나 i(3)은 에러
        double d;      // i는 초기화되지만 j, d는 초기화되지 않음
    public:
        Init3() { /* j = 6; d = 0; */ } // 컴파일 시 j, d가 초기화되지 않았다는 경고 메시지 출력될 수 있음 
        void print() { 
            cout << "Init3 i: " << i << ", j: " << j << ", d: " << d << endl; 
        }
    };

===============================================================================
== [문제 5] 실행 결과
== 멤버 선언 시에 초기화된 p와 i는 적절히 초기화되었는데, 나머지 멤버들은 쓰레기 값들로 초기화되었다.
=============================================================================== 
...
Person::Person(...):p-Init3 0 0 false ::
Init3 i: 3, j: 19, d: 2.3342e-313
Person::~Person():p-Init3 0 0 false ::

// 확인이 되었으면 Init3() 내의 주석을 풀어 모든 멤버가 초기화 되도록 하라.
Person::Person(...):p-Init3 0 0 false ::
Init3 i: 3, j: 6, d: 0
Person::~Person():p-Init3 0 0 false ::


/******************************************************************************
 * [문제 6]
 ******************************************************************************/
// 아래 주석문과 class Init4를 ClassAndObject 클래스 내의 Init3 클래스 뒤쪽(아래쪽)에 
// 배치하고, memberInitialization() 함수에서 Init4().print()의 주석을 풀어라.
//----------------------------------------------------------------------------

    // 생성자의 서두에서 멤버 초기화(p{"p-Init4-head"})가 있을 경우 멤버 변수 선언 때 즉, 
    // Person p는 초기화(생성자 실행 X)하지 않고 생성자의 서두에서 멤버 p와 i를 초기화 한다.
    // 이처럼 생성자 서두에서 멤버를 초기화하는 것이 일반적인 방법이다.
    class Init4 {
        Person p;
        int i, j;
        double d;
    public:
        Init4(): p{"p-Init4-head"}, i{4} { /* j = 6; d = 0; */ }
         // 위 함수 서두에서는 p("p-Init4-head") 로 초기화해도 됨; 그러나 i = 4는 안됨 
        void print() { 
            cout << "Init4 i: " << i << ", j: " << j << ", d: " << d << endl; 
        }
    };


===============================================================================
== [문제 6] 실행 결과
=============================================================================== 
...
Person::Person(...):p-Init4-head 0 0 false ::
Init4 i: 4, j: 1877772367, d: 4.03257e-313
Person::~Person():p-Init4-head 0 0 false ::

// 확인이 되었으면 Init4() 내의 주석을 풀어 모든 멤버가 초기화 되도록 하라.
Person::Person(...):p-Init4-head 0 0 false ::
Init4 i: 4, j: 6, d: 0
Person::~Person():p-Init4-head 0 0 false ::


/******************************************************************************
 * [문제 7]
/******************************************************************************
// 아래 주석문과 class Init5를 Init4 클래스 뒤쪽(아래쪽)에 배치하고,
// memberInitialization() 함수에서 Init5().print()의 주석을 풀어라.
//----------------------------------------------------------------------------

    // 멤버 선언 때도 초기화하고, 생성자 서두에서도 초기화를 하면 생성자가 두번 실행될까?
    // 정답은 생성자 서두에 있는 멤버 초기화만 한번 실행된다. 멤버 선언 때의 초기화는 무시된다.
    class Init5 {
        Person p { "p-Init5" };
        int i{4}, j;
        double d;
    public:
        Init5(): p{ "p-Init5-head" }, i{5} { /* j = 6; d = 0; */ }
        void print() { 
            cout << "Init5 i: " << i << ", j: " << j << ", d: " << d << endl; 
        }
    };

//----------------------------------------------------------------------------
// 주요: 어떤 경우는 p("p-Init4-head")가 안되어 p{"p-Init4-head"}로 초기화하 해야하고
//      어떤 경우는 i=4가 되고 어떤 경우는 이것이 허용되지 않아 i{4}로 초기화하는 경우가 있다.
//      따라서 무조건 { }로 초기화하면 이 방식은 아무곳에서나 사용할 수 있다.
//----------------------------------------------------------------------------

===============================================================================
== [문제 7] 실행 결과
=============================================================================== 
... // 생성자 서두에 있는 멤버 초기화만(한번만) 실행된다.
Person::Person(...):p-Init5-head 0 0 false :: 
Init5 i: 5, j: 1877826195, d: 1.78826e-307
Person::~Person():p-Init5-head 0 0 false ::

// 확인이 되었으면 Init5() 내의 주석을 풀어 모든 멤버가 초기화 되도록 하라.
Person::Person(...):p-Init5-head 0 0 false ::
Init5 i: 5, j: 6, d: 0
Person::~Person():p-Init5-head 0 0 false ::


/******************************************************************************
 * [문제 8]
 ******************************************************************************/
// 아래 주석문과 class Init6를 Init5 클래스 뒤쪽(아래쪽)에 배치하고,
// memberInitialization() 함수에서 Init6().print()의 주석을 풀어라.
//----------------------------------------------------------------------------

    // 멤버 선언과 생성자 서두에서 객체를 초기화 하지 않으면 객체 p의 기본 생성자가 자동으로 무조건 한 번 실행된다.
    // 생성자 함수 본체 Init6() { } 에서는 객체 p의 생성자를 호출할 수는 없고 set() 함수를 호출하여 초기화해야 한다.
    // 그래서 생성자 Init6()의 생성자 본체 { } 에서 p.set()을 호출하면 객체 p 멤버들은 두 번 초기화되는 것이다.
    //----------------------------------------------------------------------------
    // 중요: 결국 객체 멤버(p)는 생성자의 서두에서 초기화하는 것이 가장 좋으며, 
    //      기본 데이타 타입(int, double 등)의 경우 생성자 본체 또는 서두에서 초기화해도 상관없다. 
    //      어차피 기본 데이타 타입은 멤버 변수 선언 때 자동으로 초기화되지 않으니까.
    class Init6 {
        Person p;
        int i, j;
        double d;
    public:
        // 여기서는 p.set(...) 대신 편의상 p.setName(...)을 호출했다.
        Init6() { i = j = 6; d = 0; p.setName("p-Init6-body"); p.println(); }
        void print() { 
            cout << "Init6 i: " << i << ", j: " << j << ", d: " << d << endl; 
        }
    };

===============================================================================
== [문제 8] 실행 결과
=============================================================================== 
...
Person::Person(...): 0 0 false :: // 자동 실행된 Person의 기본 생성자에 의해 한번 초기화
p-Init6-body 0 0 false ::  // Init6() 생성자 본체 내에서 p.set()에 의해 또 초기화: 두번 초기화됨
Init6 i: 6, j: 6, d: 0
Person::~Person():p-Init6-body 0 0 false ::


/******************************************************************************
 * [문제 9]
 ******************************************************************************/
// 함수의 매개변수가 const로 선언되어 있을 때와 그렇지 않았을 경우 차이를 파악해 보자.
// 참고로 매개변수가 const로 선언되면 그 함수 내에서 매개변수를 수정하지 않고 읽기만 한다는 의미이다.
// 아래 코드를 ClassAndObject::memberInitialization() 함수 뒤쪽에 배치하라.
// 기존 ClassAndObject 클래스 내부에 또 다른 서브 클래스 Parameter를 선언하는 것이 가능하다.
//----------------------------------------------------------------------------

    class Parameter {
    public:
        // 아래 각 함수 선언에서 const가 있는 매개변수는 해당 함수에서 객체 p를 수정하지 않는다는 의미이고,
        // const가 없는 매개변수는 해당 함수에서 객체 p를 수정할 수 있다는 의미임
        // 함수 호출한 곳에서 함수의 실행 결과를 매개변수를 통해 넘겨 받아야 하는 경우는 const가 없어야 함
        void normalValue(Person p)           { cout << "normalValue(Person p)" << endl; }
        void constValue(const Person p)      { cout << "constValue(const Person p)" << endl; }
        void normalReference(Person& p)      { cout << "normalReference(Person& p)" << endl; }
        void constReference(const Person& p) { cout << "constReference(const Person& p)" << endl; }

        void printStr(string& s)             { cout << "printStr(string& s): " << s << endl; }
        void printConstStr(const string& s)  { cout << "printConstStr(const string& s): " << s << endl; }
    };

    Parameter cp;

    void normalParameter() {
        cout << "normalParameter()" << endl;
        cout << "Person p1(\"p1-name\")" << endl;

        // 요점: 아래 Person p1처럼 p1이 일반적인 객체일 경우 
        //      함수의 매개변수 타입에 상관없이 이 객체를 함수 인자로 넘겨 줄 수 있다.
        Person p1("p1-name");

        cp.normalValue(p1);     // 복사생성자 통해 매개변수 p에 p1을 복사해서 넘겨 줌
        cp.constValue(p1);      // 복사생성자 통해 매개변수 p에 p1을 복사해서 넘겨 줌
        cp.normalReference(p1); // 매개변수 p에 단순히 p1의 참조만 넘겨 줌
        cp.constReference(p1);  // 매개변수 p에 단순히 p1의 참조만 넘겨 줌
    }

    void parameters() { // Menu item 6
        normalParameter();
    }

//----------------------------------------------------------------------------
// ClassAndObject::run()의 메뉴 문자열 menuStr에 아래 메뉴 항목을 추가하고,
            "+ 5.MemberInitialization 6.constParameter           +\n"
// func_arr[]에 메뉴항목 6을 수행하는 함수를 추가하라.

===============================================================================
== [문제 9] 실행 결과
=============================================================================== 
******************************* Main Menu ...
Menu item number? 2

+++++++++++ Person Class And Object Menu ++++++++++++
+ 0.Exit 1.DefualConstructor 2.Constructor          +
+ 3.ConstrucorDestructor 4.GlobalStaticLocalObjects +
+ 5.MemberInitialization 6.constParameter           +
+++++++++++++++++++++++++++++++++++++++++++++++++++++
Menu item number? 6
normalParameter()
Person p1("p1-name")
Person::Person(...):p1-name 0 0 false ::
Person::Person(const Person&):p1-name 0 0 false ::
normalValue(Person p)
Person::~Person():p1-name 0 0 false ::
Person::Person(const Person&):p1-name 0 0 false ::
constValue(const Person p)
Person::~Person():p1-name 0 0 false ::
normalReference(Person p)
constReference(const Person& p)
Person::~Person():p1-name 0 0 false ::


/******************************************************************************
 * [문제 10]
 ******************************************************************************/
// 아래 constParameter() 함수를 normalParameter() 함수 뒤에 추가하고,
//----------------------------------------------------------------------------
    void constParameter() {
        cout << "constParameter()" << endl;
        cout << "const Person p2(\"const-p2-name\")" << endl;

        // 요점: p2처럼 상수(const) 객체일 경우 
        //      매개변수 타입 선언에 따라 인자로 넘겨 줄 수 없는 함수가 있다.
        const Person p2("const-p2-name"); // p2는 상수이므로 수정되어서는 안된다.

        // 아래 인자 p2가 일반 매개변수 p에 복사되므로 
        // 매개변수 p는 수정될지언정 원래 인자 p2는 수정되지 않는다. OK
        cp.normalValue(p2); 
        // 아래 인자 p2가 상수 매개변수 p에 복사되므로 원래 인자 p2는 수정되지 않는다. OK
        cp.constValue(p2);  
        //cp.normalReference(p2); 
        // 위 함수의 일반 참조 매개변수 p는 p2와 메모리를 공유하므로 해당 함수에서 상수인 p2를 
        // 수정할 가능성이 있다.(const로 선언되지 않았으므로) 
        // 이런 경우 상수 객체 p2을 normalReference()의 인자로 줄 수 없다. 컴파일 에러.
        cp.constReference(p2); // 상수 참조 매개변수 p는 p2와 메모리를 공유하지만 p가 상수  
        // 객체의 참조로 선언되어 있으므로 해당 함수에서 p2를 수정하지 않는다는 것을 보장한다. OK
    }
//----------------------------------------------------------------------------
// parameters() 함수 내의 맨 마지막에 아래 문장을 추가하여 해당 함수를 호출하라.
        constParameter(); cout << endl;
//----------------------------------------------------------------------------
// 위 //cp.normalReference(p2); 문장의 주석을 풀면 어떤 문제가 발생하는지 확인하라.
// 그리고 왜 그런지 이해가 되었으면 다시 주석처리하라.

===============================================================================
== [문제 10] 실행 결과
=============================================================================== 
+++++++++++ Person Class And Object Menu ...
Menu item number? 6
...

constParameter()
const Person p2("const-p2-name")
Person::Person(...):const-p2-name 0 0 false ::
Person::Person(const Person&):const-p2-name 0 0 false ::
normalValue(Person p)
Person::~Person():const-p2-name 0 0 false ::
Person::Person(const Person&):const-p2-name 0 0 false ::
constValue(const Person p)
Person::~Person():const-p2-name 0 0 false ::
constReference(const Person& p)
Person::~Person():const-p2-name 0 0 false ::


/******************************************************************************
 * [문제 11]
 ******************************************************************************/
// 아래 temporaryParameter() 함수를 constParameter() 함수 뒤에 추가하고,
//----------------------------------------------------------------------------
    void temporaryParameter() {
        cout << "temporaryParameter()" << endl;

        // 요점: 아래의 Person("Person-name")는 임시객체가 생성되며, 
        //      이 임시객체는 컴파일러에 의해 const로 취급된다.
        //      따라서 이 임시객체는 위 [문제 10]의 const p2와 동일하게 취급된다.

        cp.normalValue(Person("Person-name"));       // 불필요한 객체 복사 일어남
        cp.constValue(Person("Person-name"));        // 불필요한 객체 복사 일어남
        //cp.normalReference(Person("Person-name")); // 컴파일 에러 발생
        cp.constReference(Person("Person-name"));    // 임시 객체 참조만 넘어감

        // 결론: 일반적으로 객체는 함수의 매개변수로 value로 복사해서 넘기지 않고 객체의 참조를 넘긴다.
        //      이유는 객체의 크기가 커지면 복사 오버헤드가 발생하기 때문이다. 
        //      그런데 함수의 매개변수가 const가 아닌 일반 참조 변수로 선언된 경우 
        //      그 함수에서 이 참조변수를 통해 원본 객체를 수정할 수 있기 때문에
        //      const p2 또는 위 임시객체(const 취급)와 같은 객체들을 함수 인자로 넘길 수 없다. 
        //      따라서 [만약 함수 내에서 매개변수인 객체를 수정하지 않는다면]
        //      일반 & 매개변수로 선언하기 보다는 const &로 습관적으로 선언하는 것이 유리하다.
        //      (이렇게 선언하면 위 cp.constReference()처럼 
        //       임시객체의 참조를 함수의 매개변수로 바로 넘길 수 있다.)
    }
//----------------------------------------------------------------------------
// parameters() 함수 내의 맨 마지막에 아래 문장을 추가하여 해당 함수를 호출하라.
        temporaryParameter(); cout << endl;
//----------------------------------------------------------------------------
// 위 //cp.normalReference(Person("Person-name")); 문장의 주석을 풀면 어떤 문제가 
// 발생하는지 확인하라. 그리고 왜 그런지 이해가 되었으면 다시 주석처리하라.

===============================================================================
== [문제 11] 실행 결과
=============================================================================== 
+++++++++++ Person Class And Object Menu ...
Menu item number? 6
...

temporaryParameter()
Person::Person(...):Person-name 0 0 false ::
normalValue(Person p)
Person::~Person():Person-name 0 0 false ::
Person::Person(...):Person-name 0 0 false ::
constValue(const Person p)
Person::~Person():Person-name 0 0 false ::
Person::Person(...):Person-name 0 0 false ::
constReference(const Person& p)
Person::~Person():Person-name 0 0 false ::


/******************************************************************************
 * [문제 12]
 ******************************************************************************/
// 아래 stringParameter() 함수를 temporaryParameter() 함수 뒤에 추가하고,
//----------------------------------------------------------------------------
    void stringParameter() {
        cout << "stringParameter()" << endl;

        string s("name1"); // string s = "name1"; 과 동일

        cp.printStr(s);
        cp.printConstStr(s);
        // 아래는 임시 string 객체 생성 (임시객체는 항상 const): 컴파일 에러
        //cp.printStr(string("name")); 
        cp.printConstStr(string("name2")); // const 임시 객체 생성
        // 아래 "name"은 자동으로 임시 string("name") 객체 생성: 컴파일 에러
        //cp.printStr("name"); 
        cp.printConstStr("name3"); // const 임시 객체 생성
        // 결론: 함수의 매개변수로 "name3"처럼 문자열을 직접 넘겨 주고 싶으면
        //      함수 매개변수를 const string& 으로 선언해야 한다. string&로 선언시 에러.
        //      함수 내에서 매개변수 객체를 수정하지 않을 경우 습관적으로 항상 이렇게 선언하라.
        // 매개변수를 const string으로 선언해도 되지만 이 경우 문자열 전체가 복사되므로 비효율적임
    }
//----------------------------------------------------------------------------
// parameters() 함수 내의 맨 마지막에 아래 문장을 추가하여 해당 함수를 호출하라.
        stringParameter(); cout << endl;
//----------------------------------------------------------------------------
// 위 stringParameter() 내의 주석처리된 두 개의 //cp.printStr(...); 문장의 주석을 풀면 
// 어떤 문제가 발생하는지 확인하라. 그리고 왜 그런지 이해가 되었으면 다시 주석처리하라.

===============================================================================
== [문제 12] 실행 결과
=============================================================================== 
+++++++++++ Person Class And Object Menu ...
Menu item number? 6
...

stringParameter()
printStr(string& s): name1
printConstStr(const string& s): name1
printConstStr(const string& s): name2
printConstStr(const string& s): name3


/******************************************************************************
 * [문제 13]
 ******************************************************************************/
// 지금까지는 함수를 호출하는 쪽에서 함수 인자로 임시객체나 const 객체의 참조를 넘겨 줄 있는지 살펴봤다.
// 이제는 매개변수가 const Person& p처럼 const 참조 변수로 선언되었을 경우 
// 객체 p의 멤버 함수를 호출할 수 있을지 살펴보자.
 
// 아래 printPerson() 함수를 class Parameter에 추가하라.
// ClassAndObject의 멤버함수가 아니라 class Parameter의 맨 마지막 멤버함수로 추가해야 한다.
//----------------------------------------------------------------------------

        void printPerson(const Person& p) { // const Person p로 선언해도 동일한 결과가 나옴
            cout << "printPerson(const Person& p)" << endl;
            // 위 const Person& p 선언의 의미: 이 함수에서 객체 p를 수정하지 않겠다는 의미임
            // 따라서 아래의 p.setName("const-value")처럼 p의 멤버함수를 호출하면 에러로 처리함; 
            // 이유는 이 함수가 const 객체인 p의 멤버 name를 수정하기기 때문에.

            /* p.setName("const-value"); */ // 명백히 이름을 수정하는 것이므로 컴파일 에러 발생
            /* cout << p.getName() << " " << p.getId() << " " << p.getWeight() << " " <<
                    p.getMarried() << " :" << ((p.getAddress()==nullptr)?"":p.getAddress()) <<
                    ":" << endl; */

            // 주석을 풀 경우 발생하는 컴파일 에러는 매개변수가 const로 선언되었기 때문에  
            // 발생하는 것이다. 컴파일러 입장에서는 위 멤버함수들이 p의 멤버를 수정하는지 아니면 
            // 읽기만하는지 알 수 없기 때문에 컴파일 시 에러로 처리함; 
        }
        
//----------------------------------------------------------------------------
// parameters() 함수 내의 맨 마지막에 아래 문장을 추가하라.

        cp.printPerson(Person("name", 10, 77.7, true, "address"));
        // 임시 Person 객체의 참조 전달 (임시 객체는 항상 const)
        
//----------------------------------------------------------------------------
// 위 printPerson() 내의 주석처리된 두 개의 문장의 주석을 풀면 어떤 문제가 발생하는지 확인하라.
// 그런 후 p.setName("const-value");의 경우 명백히 이름을 수정하는 것이므로 
// 주석처리하여 에러가 발생하지 않도록 하라. 
// 그러나 cout << ... 문장은 주석을 푼 상태로 남겨 두라.
//----------------------------------------------------------------------------
// 그런데 cout << ... 문장 내의 p.getName()의 경우 지금은 컴파일 에러지만 객체 p를 
// 수정하는 것이 아니라 단순히 이름만 얻어오는 함수이므로 const Person& p 일지라도
// p.getName()를 호출할 수 있게 하고 싶다. 어떻게 하면 될까? 
//----------------------------------------------------------------------------
// *** const 객체 p에 대해 멤버 값을 수정하지 않는 함수를 호출할 수 있게 하려면 ***
//----------------------------------------------------------------------------
// 기존의 Person::getName() 함수의 선언에서 getName()과 함수 몸체 시작인 { 사이에 아래처럼
// const를 추가하라. 이는 이 멤버함수가 해당 클래스 객체를 수정하지 않는다는 것을 보장하는 것이다. 

    const string& getName()    const { return name; }
    
// 위처럼 선언하면 printPerson(const Person& p) 함수 내에서 p.getName()을 호출할 수 있게 된다.

// 이를 참고하여 Person의 멤버함수 중 get...()로 시작하는 모든 함수들에게 위처럼 const를 추가하여, 
// printPerson() 함수의 cout 문장이 컴파일 에러 없이 정상적으로 실행될 수 있도록 하라.

===============================================================================
== [문제 12] 실행 결과
=============================================================================== 
+++++++++++ Person Class And Object Menu ...
Menu item number? 6
...

Person::Person(...):name 10 77.7 true :address:
printPerson(const Person& p)
name 10 77.7 true :address:
Person::~Person():name 10 77.7 true :address:


/******************************************************************************
 * 자동 오류 체크 모드로 프로그램 실행
 ******************************************************************************/
// 1. clc.chosun.ac.kr의 [강의자료실]에서 CH6_2 과제 테스트 파일을 다운받은 후 
//    압축 파일을 풀고 test 폴더를 드래깅하여 이클립스의 [Project Explorer]의 
//    [CH6_2] 프로젝트 위에 드랍한다. (test 폴더와 그 밑에 테스트용 파일이 있어야 함)
// 2. 기존 프로젝트 CH2의 src 폴드에 있는 check_error.h를 CH6_2 프로젝트의 
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