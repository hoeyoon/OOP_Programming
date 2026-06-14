``` 
[5장 문제-1]

//----------------------------------------------------------------------------
// 아래 문제를 해결하는 도중 출력이 잘못되었거나 문제 설명과 출력이 일치하지 않거나 오타가 있거나 등등
// 조금이라도 문제에 이상한 것이 있으면 주저하지 말고 jhshim@chosun.ac.kr로 알려 주시기 바랍니다.
//----------------------------------------------------------------------------

/******************************************************************************
 * 프로젝트 및 소스파일 생성
 ******************************************************************************/
// 기존의 과제를 수행했던 이클립스의 작업공간에서 새로운 프로젝트 CH5_1를 만들고 
// 그 밑에 src 풀더를 만든 후 src 폴더 밑에 ch5_1.cpp 소스파일을 만들어라.

/******************************************************************************
 * 코드 추가 1
 ******************************************************************************/
// 1) 기존에 작성했던 ch4_3.cpp의 내용을 모두 복사해서 ch5_1.cpp에 삽입하라.
// 2) 프로그램의 맨 앞쪽 주석 부분의 "Author: " 행 다음의 내용을 아래 *로 시작하는 행들로 교체하라.
//----------------------------------------------------------------------------
 *
 *  + Person(const Person& p) 복사생성자 추가
 *  + PersonManager::PersonManager(Person array[], int len)에서 복사 생성자 사용으로 변경
 *  + 다양한 call by value, call by address, call by reference의 차이점 확인
 *  + 함수의 return 값으로 value, address, reference를 리턴할 때의 차이점
 *  + 명시적 복사 생성자 호출과 묵시적 복사 생성자 호출 확인
 *  + MainMenu에 새로운 메뉴 항목 추가
 */

/******************************************************************************
 * 코드 추가 2
 ******************************************************************************/
// 1) 아래 class CopyConstructor를 ClassAndObject와 MainMenu 클래스 사이에 배치하라.
//-----------------------------------------------------------------------------

/******************************************************************************
 * ch5_1: Reference and CopyConstructor
 ******************************************************************************/
class CopyConstructor
{
    Person u;
    Person backup;

public:
    // u는 일반 생성자, backup은 복사생성자를 이용하여 멤버를 초기화
    CopyConstructor(): u("u", 1, 70, true, "Gwangju"), backup(u) { }

    void run() {
        //using CC = CopyConstructor;

        // TODO 문제 [3]: func_t, func_arr[], menuCount 선언

        string menuStr =
            "+++++++++ Reference And Copy Constructor Menu ++++++++++\n"
            "+ 0.Exit 1.ExplicitCopyConstructor 2.ReferenceVariable +\n"
            "+ 3.ImplicitCopyConstructor 4.TemporaryObject          +\n"
            "+ 5.FunctionParameterType 6.FunctionReturnType         +\n"
            "+ 7.inputPerson                                        +\n"
            "++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

        // TODO 문제 [3]: while 문장 삽입하여 선택된 메뉴항목 실행하는 함수를 호출하라.
        cout << menuStr;
        u.println();
        backup.setName("backup");
        backup.println();
        cout << "------------------" << endl;
  }
}; // ch5_1: Reference and CopyConstructor


//-----------------------------------------------------------------------------
// 2) MainMenu::run() 내의 메뉴 문자열을 아래 menuStr로 대체하라.
//    그리고 switch 문장에 CopyConstructor().run()을 호출하는 case 문장도 추가하라.
//    menuCount의 값도 조정하라.
//-----------------------------------------------------------------------------

        string menuStr =
"******************************* Main Menu *********************************\n"
"* 0.Exit 1.PersonManager(ch3_2, 4)                                        *\n"
"* 2.Class:Object(ch3_1) 3.CopyConstructor(ch5_1)                          *\n"
"***************************************************************************\n";

===============================================================================
== 초기 프로그램 실행 결과
== 아래에서 주석문(//)은 출력 내용이 아님
=============================================================================== 

******************************* Main Menu *********************************
* 0.Exit 1.PersonManager(ch3_2, 4)                                        *
* 2.Class:Object(ch3_1) 3.CopyConstructor(ch5_1)                          *
***************************************************************************
Menu item number? 3
    // MainMenu::run() 내의 case 3: CopyConstructor() 생성자에 의해 
    // 멤버 u와 backup이 아래처럼 초기화됨; 이 생성자 서두에서 backup(u) 실행; 
    // 즉, 컴파일러에 의해 자동 생성된 복사생성자가 u를 복사하여 backup을 초기화 함
Person::Person(...):u 1 70 true :Gwangju:
+++++++++ Reference And Copy Constructor Menu ++++++++++
+ 0.Exit 1.ExplicitCopyConstructor 2.ReferenceVariable +
+ 3.ImplicitCopyConstructor 4.TemporaryObject          +
+ 5.FunctionParameterType 6.FunctionReturnType         +
+ 7.inputPerson                                        +
++++++++++++++++++++++++++++++++++++++++++++++++++++++++
u 1 70 true :Gwangju:
backup 1 70 true :Gwangju:
------------------
    // 아래는 MainMenu::run() 내의 case 3: CopyConstructor().run() 리턴 후 
    // 임시 객체인 CopyConstructor()가 소멸시 멤버 u와 backup 소멸
Person::~Person():backup 1 70 true :Gwangju:
Person::~Person():u 1 70 true :Gwangju:

******************************* Main Menu ...
Menu item number? 0
Good bye!!


/******************************************************************************
 * [문제 1]
 ******************************************************************************/
// 기존 Person 클래스에 아래 복사 생성자 선언을 클래스 내부의 ~Person() 선언 앞에 추가하라.
    Person(const Person& p);

//-----------------------------------------------------------------------------
// 아래 주석 및 복사 생성자 구현 함수를 Person::~Person() 구현 함수 앞에 배치하고 구현하라.
//-----------------------------------------------------------------------------

// Person 멤버 데이타 중에 동적으로 메모리를 할당 받는 멤버가 없기 때문에
// 복사생성자를 직접 만들지 않아도 컴파일러가 자동으로 아래와 같은 복사생성자를 만들어 준다.
// 여기서 복사생성자를 굳이 만든 이유는 실행과정을 확인하기 위한 출력문을 넣기 위해서이다.
Person::Person(const Person& p):
    name(p.name), id{p.id}, TODO [문제1]:나머지 weight, married 멤버도 초기화 {
    /*
    TODO [문제1]: address와 memo_c_str 역시 setAddress(), setMemo()를 호출하여 
                 p의 상응하는 멤버를 복사해서 초기화하라.
    */
    cout << "Person::Person(const Person&):"; println();
}

===============================================================================
== [문제 1] 실행 결과
=============================================================================== 

******************************* Main Menu *********************************
* 0.Exit 1.PersonManager(ch3_2, 4)                                        *
* 2.Class:Object(ch3_1) 3.CopyConstructor(ch5_1)                          *
***************************************************************************
Menu item number? 3
Person::Person(...):u 1 70 true :Gwangju:
Person::Person(const Person&):u 1 70 true :Gwangju: // backup(u)에 의해 복사 생성자 실행됨
+++++++++ Reference And Copy Constructor Menu ++++++++++
+ 0.Exit 1.ExplicitCopyConstructor 2.ReferenceVariable +
+ 3.ImplicitCopyConstructor 4.TemporaryObject          +
+ 5.FunctionParameterType 6.FunctionReturnType         +
+ 7.inputPerson                                        +
++++++++++++++++++++++++++++++++++++++++++++++++++++++++
u 1 70 true :Gwangju:
backup 1 70 true :Gwangju:
------------------
Person::~Person():backup 1 70 true :Gwangju:
Person::~Person():u 1 70 true :Gwangju:


/******************************************************************************
 * [문제 2]
 ******************************************************************************/
// 기존의 PersonManager::PersonManager(Person* array[], int len) 함수에서 새로운 객체를 
// 동적으로 생성하여 초기화할 때 Person(const string name, int id, ...) 생성자를 사용하여
// 객체를 초기화 했다. 이제 이 생성자를 사용하지 말고 array[i]가 포인터하는 객체를 복사해서 초기화시키는
// 즉, 복사생성자를 호출하여 초기화하라. 예) new Person(복사할 원본 객체);
// 복사생성자 호출 시 array[i]는 포인터이므로 이것이 포인터하는 원본 객체를 (사실은 그 객체의 레퍼런스) 
// 복사생성자의 인자로 넘길 때는 *array[i]로 넘겨 주면 된다.   

===============================================================================
== [문제 2] 실행 결과
=============================================================================== 

******************************* Main Menu *********************************
* 0.Exit 1.PersonManager(ch3_2, 4)                                        *
* 2.Class:Object(ch3_1) 3.CopyConstructor(ch5_1)                          *
***************************************************************************

Menu item number? 1              // 아래는 MultiManager::persons[]의 배열 객체 생성임
Person::Person(...):p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
Person::Person(...):p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
Person::Person(...):p2 12 52.2 false :1001, Jungang-daero, Yeonje-gu, Busan:
Person::Person(...):p3 13 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
Person::Person(...):p4 14 64.4 false :88 Gongpyeong-ro, Jung-gu, Daegu:
VectorPerson::VectorPerson(10)
PersonManager::PersonManager(array[], len) // 아래처럼 객체가 복사생성자에 의해 초기화되어야 함
Person::Person(const Person&):p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
Person::Person(const Person&):p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
Person::Person(const Person&):p2 12 52.2 false :1001, Jungang-daero, Yeonje-gu, Busan:
Person::Person(const Person&):p3 13 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
Person::Person(const Person&):p4 14 64.4 false :88 Gongpyeong-ro, Jung-gu, Daegu:
display(): count 5
[0] p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
[1] p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
[2] p2 12 52.2 false :1001, Jungang-daero, Yeonje-gu, Busan:
[3] p3 13 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
[4] p4 14 64.4 false :88 Gongpyeong-ro, Jung-gu, Daegu:
empty():false, size():5, capacity():10
PersonManager::run() starts


/******************************************************************************
 * [문제 3]
 ******************************************************************************/
// CopyConstructor::run()에서 아래 사항들을 수행하라.
// 1) 기존의 아래 문장들을 삭제하라.
    cout << menuStr; u.println(); backup.setName("backup"); backup.println();
    cout << "------------------" << endl;

// 2) 기존 PersonManager::run()을 참조하여 func_t, func_arr[], menuCount를 추가하라.
//    현재는 메뉴항목 중 Exit만 지원하도록 func_arr[]을 구성하라.

// 3) while 문장을 만들고 그 안에 메뉴를 보여 준 후 선택된 메뉴항목을 실행하는 코드를 삽입하라.

===============================================================================
== [문제 3] 실행 결과
=============================================================================== 

******************************* Main Menu ...
Menu item number? 3
Person::Person(...):u 1 70 true :Gwangju:
Person::Person(const Person&):u 1 70 true :Gwangju:

+++++++++ Reference And Copy Constructor Menu ++++++++++
+ 0.Exit 1.ExplicitCopyConstructor 2.ReferenceVariable +
+ 3.ImplicitCopyConstructor 4.TemporaryObject          +
+ 5.FunctionParameterType 6.FunctionReturnType         +
+ 7.inputPerson                                        +
++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Menu item number? 1                // 현재는 메뉴항목 중 Exit만 지원하도록 하라.
1: OUT of selection range(0 ~ 0)
Menu item number? 0
Person::~Person():u 1 70 true :Gwangju:
Person::~Person():u 1 70 true :Gwangju:


/******************************************************************************
 * [문제 4]
 ******************************************************************************/
// 1) 아래 함수를 CopyConstructor 클래스 내의 run() 함수 앞쪽에 배치하라.
//    u와 p의 생성 시기와 소멸 시기를 잘 이해하라.
//-----------------------------------------------------------------------------

    void explicitCopyConstructor() { // Menu item 1
        cout << "u: "; u.println();
        
        TODO: Person형의 객체 p를 선언하되 복사생성자를 사용하여 u을 복사하여 초기화하라. 

        TODO: 실행결과를 참고하여 지역 객체 p의 멤버 값들을 변경하라.

        cout << "u: "; u.println();
        cout << "p: "; p.println();
        // 함수 리턴 시 객체 p의 소멸자가 실행됨
    }

//-----------------------------------------------------------------------------
// 2) CopyConstructor::run() 내의 CC 주석문 풀고 
//    func_arr[]에 위 멤버 함수 주소를 추가하라. 이때 CC를 활용하라.

===============================================================================
== [문제 4] 실행 결과
=============================================================================== 
...
+++++++++ Reference And Copy Constructor Menu ...
Menu item number? 1
u: u 1 70 true :Gwangju:
Person::Person(const Person&):u 1 70 true :Gwangju:
u: u 1 70 true :Gwangju:
p: p 2 80 false :Seoul:
Person::~Person():p 2 80 false :Seoul:


/******************************************************************************
 * [문제 5]
 ******************************************************************************/
// 아래 함수를 CopyConstructor 클래스 내의 run() 함수 앞쪽에 배치하고,
// CopyConstructor::run() 내의 func_arr[]에 아래 멤버 함수 주소를 추가하라.
// 아래 함수의 코드를 완성하고 참조 변수의 기능을 이해하라.
//-----------------------------------------------------------------------------

    void referenceVariable() { // Menu item 2
        cout << "p: ";
        Person p(u);
        
        TODO: 지역 변수 p와 객체를 공유하는 Person형의 참조 변수 r을 선언하고 초기화하라. 

        cout << "p: "; p.println();         // r은 참조이고 u와 동일한 객체를 공유하므로
        cout << "r: "; r.println();         // 두 출력물은 동일한 객체를 출력함

        TODO: 실행결과를 참고하여 참조 변수 r의 멤버 값들을 변경하라.

        cout << "p: "; p.println();
        cout << "r: "; r.println();

        TODO: 실행결과를 참고하여 지역 객체 p의 멤버 값들을 변경하라.

        cout << "p: "; p.println();
        cout << "r: "; r.println();
        // r은 객체 p를 공유하는 참조이므로 함수 리턴 시 소멸자가 실행되지 않음
    }


===============================================================================
== [문제 5] 실행 결과
=============================================================================== 
...
+++++++++ Reference And Copy Constructor Menu ...
Menu item number? 2
p: Person::Person(const Person&):u 1 70 true :Gwangju:
p: u 1 70 true :Gwangju:
r: u 1 70 true :Gwangju:
p: r 2 80 false :Seoul:
r: r 2 80 false :Seoul:
p: p 1 70 true :Gwangju:
r: p 1 70 true :Gwangju:
Person::~Person():p 1 70 true :Gwangju:


/******************************************************************************
 * [문제 6]
 ******************************************************************************/
// 아래 함수들을 CopyConstructor::run() 함수 앞쪽에 배치하고,
// CopyConstructor::run() 내의 func_arr[]에 아래 적절한 멤버 함수 주소를 추가하라.
// 아래 함수의 코드를 완성하라.
//-----------------------------------------------------------------------------
// 주의: 언제 묵시적으로 복사생성자가 실행되는지 이해하라.
//-----------------------------------------------------------------------------

    // 매개변수 a는 함수호출시 복사 생성자에 의해 복사되어 초기화됨; call by value로 매개변수를 선언하라.
    void function_argument( /* TODO: 매개변수 a 선언; [교재 예제 5-12] 참조 */ ) { // Menu item 3-1
        cout << "a: "; a.println();
        cout << "a.setName(a)" << endl;
        a.setName("a");
        cout << "a: "; a.println();
    }

    Person return_member_object() { // Menu item 3-2
        TODO: u 객체를 반환함 (여기서는 임식 객체에 복사됨); [교재 예제 5-12] 참조
    }

    void implicitCopyConstructor() { // Menu item 3
        cout << "u: "; u.println();
        cout << "\nimplicit copy constructor 1: operator =" << endl;
        cout << "Person p = u" << endl;
        cout << "p: ";
        
        TODO: 새로운 Person 객체 p를 선언하고 객체 u를 p에 대입하여 초기화하라.(묵시적 복사생성자를 호출) [교재 예제 5-12] 참조
        
        cout << "p.setName(p)" << endl;
        p.setName("p");
        cout << "p: "; p.println();

        cout << "\nimplicit copy constructor 2: function argument" << endl;
        cout << "call function_argument(u)" << endl;
        
        // 묵시적으로 복사 생성자를 호출하여 함수 인자를 복사하여 함수의 매개변수 a에 넘김
        function_argument(u); 
        cout << "function_argument(u) returned" << endl;

        cout << "\nimplicit copy constructor 3: return object" << endl;
        cout << "call return_member_object().println()" << endl;
        return_member_object().println();
          // return_member_object()의 리턴 값을 복사생성자에 의해 임시객체(이름 없는 지역변수)에 복사하고
          // 그 임시 객체의 println()을 호출하여 객체를 출력한다.
          // 출력 후 더 이상 그 임시 객체가 필요 없기 때문에 소멸자를 호출하여 바로 임시 객체를 소멸시킴
        cout << "return_member_object() returned" << endl;
    }

===============================================================================
== [문제 6] 실행 결과
=============================================================================== 
...
+++++++++ Reference And Copy Constructor Menu ...
Menu item number? 3
u: u 1 70 true :Gwangju:

implicit copy constructor 1: operator =
Person p = u
p: Person::Person(const Person&):u 1 70 true :Gwangju: // 복사생성자: 지역 변수 p에 대입시 복사
p.setName(p)
p: p 1 70 true :Gwangju:

implicit copy constructor 2: function argument
call function_argument(u)
Person::Person(const Person&):u 1 70 true :Gwangju: // 복사생성자: 함수 매개변수로 복사
a: u 1 70 true :Gwangju:
a.setName(a)
a: a 1 70 true :Gwangju:
Person::~Person():a 1 70 true :Gwangju:             // 함수 매개변수 객체 소멸
function_argument(u) returned

implicit copy constructor 3: return object
call return_member_object().println()
Person::Person(const Person&):u 1 70 true :Gwangju: // 복사생성자: 리턴할 객체 복사
u 1 70 true :Gwangju:                        // 리턴된 임시객체의 println() 실행 결과
Person::~Person():u 1 70 true :Gwangju:             // 리턴된 임시객체 소멸
returnMemberObject() returned
Person::~Person():p 1 70 true :Gwangju:             // 지역 변수인 객체 p 소멸


/******************************************************************************
 * [문제 7]
 ******************************************************************************/
// 아래 함수들을 CopyConstructor::run() 함수 앞쪽에 배치하고,
// CopyConstructor::run() 내의 func_arr[]에 아래 적절한 멤버 함수 주소를 추가하라.
// 아래 함수의 코드를 완성하라.
//-----------------------------------------------------------------------------
// 주지: 어떻게 임시 객체를 생성하고 언제 임시객체가 생성되는지를 이해하라.
//      실행결과를 참고하여 효율적인 프로그램 실행을 위해 컴파일러가 어떻게 하는지 추측해 보라.
//-----------------------------------------------------------------------------
// 주의: 아래 실행 과정은 컴파일러마다 실행 방법이 다를 수 있다.
//      좋은 컴파일러일수록 코드의 문맥을 보고 불필요한 중복적인 객체복사 또는 객체생성 등을 회피한다.
//-----------------------------------------------------------------------------

    Person return_local_object() { // Menu item 4-1
        Person pL("pL", 0, 70, true, "Gwangju Nam-gu");
        cout << "return_local_object() returns pL" << endl;
        return pL;
        // 정석대로 하면 리턴하기 전에 복사생성자를 호출하여 지역 객체 pL를 복사해 준 후 
        // 리턴 직전에 pL를 소멸해야 한다.
        // 그러나 컴파일러는 효율적인 실행을 위해 복사생성자와 소멸자를 호출하지 않고
        // 함수가 리턴한 후 return_local_object().println() 호출 시 
        // 함수의 지역 객체 pL의 메모리를 그대로 재사용한다. (소멸되지 않았으므로)
        // println() 실행 후 더 이상 객체가 필요 없으면 그제서야 소멸자를 호출하여 소멸시킴
    }

    Person return_temporary_object() { // Menu item 4-2
        cout << "return_temporary_object() returns Person(pT, 0, 70, true, Gwangju Nam-gu)" << endl;
        return Person("pT", 0, 70, true, "Gwangju Nam-gu"); // 임시 객체를 리턴함
        // return {"p", 0, 70, true, "Gwangju Nam-gu"}; // 위 문장과 동일한 기능임
        // 위 문장은 컴파일러가 함수의 리턴 타입을 참고하여 
        //   Person("p", 0, 70, true, "Gwangju Nam-gu")으로 자동 처리함
    }

    void temporaryObject() { // Menu item 4
        cout << "temporary object 1: Person(p0, 10, 70, true, Gwangju)" << endl;
        // 임시객체 생성 방법: 클래스이름(생성자 인자들)
        // 생성자 호출된 후 아래 문장이 끝나면 바로 소멸자가 호출됨
        // 주요: 임시 객체가 포함된 해당 문장의 실행이 종료되면 임시 객체는 소멸됨
        Person("p0", 10, 70, true, "Gwangju");

        cout << "\ntemporary object 2: Person(p1, 11, 60, false, Seoul).println()" << endl;
        // 임시객체: 생성자 호출, println() 호출, 소멸자 호출
        Person("p1", 11, 60, false, "Seoul").println();

        cout << "\nreturn_member_object().println()" << endl;
        return_member_object().println(); // 복사 생성자 활용
        cout << "return_member_object() returned" << endl;

        cout << "\nreturn_local_object().println()" << endl;
        return_local_object().println(); // 복사 생성자 사용하지 않음
        cout << "return_local_object() returned" << endl;

        cout << "\nPerson pL = return_local_object()" << endl;
        Person pL = return_local_object(); // 복사 생성자 활용
        cout << "return_local_object() returned" << endl;
        pL.println();

        cout << "\nreturn_temporary_object().println()" << endl;
        return_temporary_object().println();  // 생성자 활용
        cout << "return_temporary_object() returned" << endl;
        
        cout << "\nPerson pT = return_temporary_object()" << endl;
        Person pT = return_temporary_object();  // 생성자 활용
        cout << "return_temporary_object() returned" << endl;
        pT.println();
    }

===============================================================================
== [문제 7] 실행 결과
== 아래 결과는 컴파일러에 따라 다르게 실행될 수도 있음 (효율적인 실행을 위해 컴파일러마다 다르게 구현할 수 있음)
=============================================================================== 
...
+++++++++ Reference And Copy Constructor Menu ...
Menu item number? 4
temporary object 1: Person(p0, 10, 70, true, Gwangju)
// 생성자 호출된 후 해당 문장이 끝나면 바로 소멸자가 호출됨
Person::Person(...):p0 10 70 true :Gwangju: 
Person::~Person():p0 10 70 true :Gwangju:

temporary object 2: Person(p1, 11, 60, false, Seoul).println()
Person::Person(...):p1 11 60 false :Seoul:
p1 11 60 false :Seoul:    // 생성자 호출, println() 호출, 소멸자 호출                  
Person::~Person():p1 11 60 false :Seoul:

return_member_object().println()
// 복사생성자 이용하여 리턴할 임시 객체 생성(클래스 객체 멤버 u를 임시 객체에 복사)
Person::Person(const Person&):u 1 70 true :Gwangju: 
u 1 70 true :Gwangju: // 함수 리턴 후 임시 객체의 println() 출력
Person::~Person():u 1 70 true :Gwangju: // 출력한 후 바로 임시 객체 소멸
return_member_object() returned

return_local_object().println()
// return_local_object() 함수 내에서 일반 생성자 이용하여 지역 객체 생성
Person::Person(...):pL 0 70 true :Gwangju Nam-gu:
return_local_object() returns pL                 
// 함수 리턴해도 함수의 지역객체 pL이 바로 소멸되지 않음
// 이유: 리턴할 객체가 pL이므로 소멸을 잠시 보류함
//  컴파일러가 복사 생성자를 이용해 pL을 복사하지 않고 리턴된 객체로 pL을 바로 사용
// 아래는 리턴된 임시객체(사실은 지역객체 pL임)의 println() 출력
pL 0 70 true :Gwangju Nam-gu: 
// println()하고 임시객체(즉, 지역객체 pL) 소멸
Person::~Person():pL 0 70 true :Gwangju Nam-gu:  
return_local_object() returned

Person pL = return_local_object()
// return_local_object() 함수 내에서 일반 생성자 이용하여 지역 객체 pL 생성
Person::Person(...):pL 0 70 true :Gwangju Nam-gu:
return_local_object() returns pL
// 함수 리턴해도 그것의 지역객체 pL 소멸되지 않음
// temporaryObject()의 pL은 return_local_object()의 pL와 객체를 공유함
return_local_object() returned
pL 0 70 true :Gwangju Nam-gu:        // pL.println()
// println() 후에도 return_local_object()의 지역 객체 pL은 소멸되지 않음
// 이 객체는 temporaryObject()의 pL과 메모리를 공유하므로 소멸되지 않고 계속 존재하다가
// temporaryObject()가 리턴할 때 결국 소멸됨
// 결론: return_local_object()와 temporaryObject()가 pL을 공유함;

return_temporary_object().println()
return_temporary_object() returns Person(pT, 0, 70, true, Gwangju Nam-gu)
// return_temporary_object() 함수 리턴시 리턴할 객체 생성
Person::Person(...):pT 0 70 true :Gwangju Nam-gu: 
pT 0 70 true :Gwangju Nam-gu: // return_temporary_object().println()
// 출력한 후 바로 임시 객체 바로 소멸
Person::~Person():pT 0 70 true :Gwangju Nam-gu:  
return_temporary_object() returned

Person pT = return_temporary_object()
return_temporary_object() returns Person(pT, 0, 70, true, Gwangju Nam-gu)
// return_temporary_object()에서 리턴할 임시 객체는 바로 pT 객체 변수에 생성됨
Person::Person(...):pT 0 70 true :Gwangju Nam-gu: 
return_temporary_object() returned
pT 0 70 true :Gwangju Nam-gu:  // pT.println()
// temporaryObject() 리턴할 때 pT, pL 소멸됨
Person::~Person():pT 0 70 true :Gwangju Nam-gu: 
Person::~Person():pL 0 70 true :Gwangju Nam-gu:


/******************************************************************************
 * [문제 8]
 ******************************************************************************/
// 아래 함수들을 CopyConstructor::run() 함수 앞쪽에 배치하고,
// CopyConstructor::run() 내의 func_arr[]에 아래 적절한 멤버 함수 주소를 추가하라.
// 아래의 각 TODO 부분의 코드를 완성하라. 
//-----------------------------------------------------------------------------

    // TODO: 아래 함수 매개변수를 call by value가 되게 Person의 객체 p로 선언하라.
    void call_by_value( /* TODO */ ) { // Menu item 5-1: call by value: 복사생성자에 의해 복사됨
        cout << "p: "; p.println();
        cout << "u: "; u.println();
        cout << "p.set(p, 2, 80, false, Seoul)" << endl;
        p.set("p", 2, 80, false, "Seoul");
        cout << "p: "; p.println();      // p는 u과 다른 메모리를 사용하는 객체임
        cout << "u: "; u.println(); // u은 영향을 받지 않음
        // 함수 리턴 시 매개변수 p 객체의 소멸자 함수가 호출됨
    }

    // TODO: 아래 함수 매개변수를 call by reference가 되게 Person의 참조변수 p로 선언하라.
    void call_by_reference( /* TODO */ ) { // Menu item 5-2: call by reference
        cout << "p: "; p.println();   // p는 u의 참조이므로 u와 동일한 객체 메모리를 공유함
        cout << "u: "; u.println();
        cout << "p.set(p, 2, 80, false, Seoul)" << endl;
        p.set("p", 2, 80, false, "Seoul");
        cout << "p: "; p.println();   // p와 u은 동일한 객체 메모리를 공유하므로 항상 내용이 동일함
        cout << "u: "; u.println();
        u = backup;       // u 값을 원래 값으로 복구
        // 매개변수 p는 참조이므로 함수 리턴 시 소멸자가 호출되지 않음
    }

    // TODO: 아래 함수 매개변수를 call by address가 되게 Person에 대한 포인터 변수 p로 선언하라.
    void call_by_address( /* TODO */ ) { // Menu item 5-3: call by address
        cout << "p: "; p->println();   // p는 u 메모리를 포인터하므로 동일한 내용이 출력됨
        cout << "u: "; u.println();
        cout << "p->set(p, 2, 80, false, Seoul)" << endl;
        p->set("p", 2, 80, false, "Seoul");
        cout << "p: "; p->println();   // p는 u 메모리를 포인터하므로 항상 동일한 내용이 출력됨
        cout << "u: "; u.println();
        u = backup;       // u 값을 원래 값으로 복구
        // 매개변수 p는 포인터이므로 함수 리턴 시 소멸자가 호출되지 않음
    }

    void functionParameterType() { // Menu item 5
        cout << "call_by_value" << endl;
        // 함수 호출 시 복사생성자를 통해 u 객체를 매개변수 p에 복사
        TODO: call_by_value()을 호출하되 멤버 객체 u을 인자로 넘겨 주어라.
        cout << endl;

        cout << "call_by_reference" << endl;
        TODO: call_by_reference()을 호출하되 멤버 객체 u을 인자로 넘겨 주어라.
        cout << endl; // 단순히 u의 참조만 전달됨

        cout << "call_by_address" << endl;
        TODO: call_by_address()을 호출하되 멤버 객체 u의 주소를 인자로 넘겨 주어라.
        cout << endl; // 단순히 u의 주소값, 즉 포인터가 전달됨
    }


===============================================================================
== [문제 8] 실행 결과
=============================================================================== 
...
+++++++++ Reference And Copy Constructor Menu ...
Menu item number? 5
call_by_value
// 복사 생성자에 의한 매개변수 p 초기화
Person::Person(const Person&):u 1 70 true :Gwangju:
p: u 1 70 true :Gwangju:
u: u 1 70 true :Gwangju:
p.set(p, 2, 80, false, Seoul)
p: p 2 80 false :Seoul:
u: u 1 70 true :Gwangju:
Person::~Person():p 2 80 false :Seoul: // 매개변수 p 소멸

call_by_reference
// 참조 변수 p는 참조(사실 메모리 주소임)를 이용하여 객체 u와 메모리를 공유하므로 
// 함수호출 시 생성자, 복사생성자에 의해 초기화되지 않고 참조 값만 초기화된다. 
p: u 1 70 true :Gwangju:
u: u 1 70 true :Gwangju:
p.set(p, 2, 80, false, Seoul)
p: p 2 80 false :Seoul:
u: p 2 80 false :Seoul:  // p는 참조변수이므로 소멸자 실행되지 않음

call_by_address
// 포인터 변수 p는 메모리 주소를 이용하여 객체 u의 메모리를 공유하므로 
// 함수호출 시 생성자, 복사생성자에 의해 초기화되지 않고 포인터 값만 초기화된다. 
p: u 1 70 true :Gwangju:
u: u 1 70 true :Gwangju:
p->set(p, 2, 80, false, Seoul)
p: p 2 80 false :Seoul:
u: p 2 80 false :Seoul:  // p는 포인터 변수이므로 소멸자 실행되지 않음

//-----------------------------------------------------------------------------
// 주의: 참조와 포인터는 대상 객체의 주소 값을 가지고 객체에 접근하는 것은 동일하나
//      그 변수를 사용하는 방식에 있어서 참조는 .을 이용하고 포인터는 ->를 이용하는 차이가 있다.
//      또한 참조는 그 주소 값에 대해 포인터처럼 증가, 감소하는 등의 연산을 할 수 없다.
//-----------------------------------------------------------------------------


/******************************************************************************
 * [문제 9]
 ******************************************************************************/
// 아래 함수들을 CopyConstructor::run() 함수 앞쪽에 배치하고,
// CopyConstructor::run() 내의 func_arr[]에 아래 적절한 멤버 함수 주소를 추가하라.
// 아래의 각 TODO 부분의 코드를 완성하라. 
//-----------------------------------------------------------------------------

// TODO: 아래 주석(/* */)을 지우고 Person 객체를 리턴하도록 함수의 리턴 타입을 선언하라.
/* TODO */ return_value() {                   // return value
        return u;
    }

   void return_value_test() { // Menu item 6-1
        cout << "--- return_value_test() ---" << endl;
        cout << "call return_value()" << endl;
        cout << "p: ";

        TODO: Person형 객체 변수 p를 선언하고 return_value()의 리턴 값으로 초기화하라.

        cout << "return_value() returned" << endl;
        cout << "p: "; p.println();
        cout << "p.set(p, 2, 80, false, Seoul)" << endl;
        p.set("p", 2, 80, false, "Seoul");
        cout << "p: "; p.println();        // 두 객체의 name은 다른 값임
        cout << "u: "; u.println();
        // 함수 리턴 시 지역변수 p 객체의 소멸자 함수가 호출됨
    }

// TODO: 아래 주석(/* */)을 지우고 
//       Person 객체의 참조를 리턴하도록 함수의 리턴 데이타 타입을 선언하라.
/* TODO */ return_reference() {                  // return reference
        return u;
    }

    void return_reference_test() { // Menu item 6-2
        cout << "--- return_reference_test() ---" << endl;
        cout << "call return_reference()" << endl;
        cout << "p: ";

        TODO: Person형 객체 변수 p를 선언하고 return_reference()의 리턴 값으로 초기화하라.

        cout << "return_reference() returned" << endl;
        cout << "p.set(p, 2, 80, false, Seoul)" << endl;
        p.set("p", 2, 80, false, "Seoul");
        cout << "p: "; p.println();
        cout << "u: "; u.println();
        cout << endl;

        cout << "call return_reference()" << endl;

        TODO: Person형 참조 변수 r를 선언하고 return_reference()의 리턴 값으로 초기화하라.

        Person& r = return_reference(); // r는 리턴된 u의 참조를 저장하고 있는 참조변수임
        cout << "return_reference() returned" << endl;
        cout << "u: "; u.println();
        cout << "r.set(p, 2, 80, false, Seoul)" << endl;
        r.set("r", 2, 80, false, "Seoul");
        cout << "r: "; r.println();
        cout << "u: "; u.println();
        u = backup;
        // 함수 리턴 시 지역 객체 p의 경우 소멸자 함수가 호출되지만
        //           참조 변수 r는 소멸자가 호출되지 않음
    }

// TODO: 아래 주석을 지우고 함수의 리턴 값을 참조하여 함수의 리턴 데이타 타입을 적절히 선언하라.
/* TODO */ return_address() {                  // return address
        return &u;
    }

    void return_address_test() { // Menu item 6-3
        cout << "--- return_address_test() ---" << endl;
        cout << "call return_address()" << endl;

        TODO: Person형 포인터 변수 p를 선언하고 return_address()의 리턴 값으로 초기화하라.

        cout << "return_address() returned" << endl;
        cout << "p: "; p->println();
        cout << "u: "; u.println();
        cout << "p.set(p, 2, 80, false, Seoul)" << endl;
        p->set("p", 2, 80, false, "Seoul"); // p는 u 객체를 포인터하므로 u과 동일한 메모리를 공유함
        cout << "p: "; p->println();
        cout << "u: "; u.println();
        u = backup;
        // 함수 리턴 시 p는 포인터 변수이므로 소멸자가 호출되지 않음
    }

    void returnDataType() { // Menu item 6
        return_value_test();        cout << endl;
        return_reference_test();    cout << endl;
        return_address_test();
    }


===============================================================================
== [문제 9] 실행 결과
=============================================================================== 
...
+++++++++ Reference And Copy Constructor Menu ...
Menu item number? 6
--- return_value_test() ---
call return_value()
p: Person::Person(const Person&):u 1 70 true :Gwangju: // 묵시적 복사생성자 실행
return_value() returned
p: u 1 70 true :Gwangju:
p.set(p, 2, 80, false, Seoul)
p: p 2 80 false :Seoul:
u: u 1 70 true :Gwangju:
Person::~Person():p 2 80 false :Seoul:

--- return_reference_test() ---
call return_reference()      
// Person p = return_reference(): 참조(주소) 값이 리턴되며 참조된 객체 u를 p에 복사하여 초기화
// p와 u는 서로 다른 별개의 객체임
p: Person::Person(const Person&):u 1 70 true :Gwangju: // 묵시적 복사생성자 실행
return_reference() returned
p.set(p, 2, 80, false, Seoul)
p: p 2 80 false :Seoul:
u: u 1 70 true :Gwangju:

call return_reference()      
// Person& r = return_reference(): 참조 값만 리턴되므로 복사생성자 실행되지 않음
// r는 참조(주소)를 이용하여 u와 객체 메모리를 공유함
return_reference() returned
u: u 1 70 true :Gwangju:
r.set(p, 2, 80, false, Seoul)
r: r 2 80 false :Seoul:
u: r 2 80 false :Seoul:
Person::~Person():p 2 80 false :Seoul:  // 객체 변수 p 소멸

--- return_address_test() ---
call return_address()
// Person* p = return_address(): 주소 값만 리턴되므로 복사생성자 실행되지 않음
// p는 포인터(주소)를 이용하여 u와 객체 메모리를 공유함
return_address() returned
p: u 1 70 true :Gwangju:
u: u 1 70 true :Gwangju:
p.set(p, 2, 80, false, Seoul)
p: p 2 80 false :Seoul:
u: p 2 80 false :Seoul:


/******************************************************************************
 * [문제 10]
 ******************************************************************************/
// 아래 함수를 CopyConstructor::run() 함수 앞쪽에 배치하고,
// CopyConstructor::run() 내의 func_arr[]에 아래 멤버 함수 주소를 추가하라.
//-----------------------------------------------------------------------------
    void inputPerson() { // Menu item 7
    	cout << "u: "; u.println();
        while (!UI::inputPerson(&u)) ;  // USER 11 88 false :DONG-GU, DAEGU:
        backup = u;
        cout << "u: "; u.println();
    }


===============================================================================
== [문제 10] 실행 결과
=============================================================================== 
...
+++++++++ Reference And Copy Constructor Menu ...
Menu item number? 7
u: u 1 70 true :Gwangju:
input person information:
USER A11 88 false :DONG-GU, DAEGU:
Input-data format MISMATCHED
input person information:
USER 11 88B false :DONG-GU, DAEGU:
Input-data format MISMATCHED
input person information:
USER 11 88 false :DONG-GU, DAEGU:
u: USER 11 88 false :DONG-GU, DAEGU:

//-----------------------------------------------------------------------------
// 주지: 자동오류체크에서는 위 방식으로 새로 입력된 u 객체를 이용하여 모든 메뉴 항목들을 테스트한다.
//-----------------------------------------------------------------------------

/******************************************************************************
 * 자동 오류 체크 모드로 프로그램 실행
 ******************************************************************************/
// 1. clc.chosun.ac.kr의 [강의자료실]에서 CH5_1 과제 테스트 파일을 다운받은 후 
//    압축 파일을 풀고 test 폴더를 드래깅하여 이클립스의 [Project Explorer]의 
//    [CH5_1] 프로젝트 위에 드랍한다. (test 폴더와 그 밑에 테스트용 파일이 있어야 함)
// 2. 기존 프로젝트 CH2의 src 폴드에 있는 check_error.h를 CH5_1 프로젝트의 
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
test 10 : O
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