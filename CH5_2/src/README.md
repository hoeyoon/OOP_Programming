```
[5장 문제-2]

//----------------------------------------------------------------------------
// 아래 문제를 해결하는 도중 출력이 잘못되었거나 문제 설명과 출력이 일치하지 않거나 오타가 있거나 등등
// 조금이라도 문제에 이상한 것이 있으면 주저하지 말고 jhshim@chosun.ac.kr로 알려 주시기 바랍니다.
//----------------------------------------------------------------------------

/******************************************************************************
 * 프로젝트 및 소스파일 생성
 ******************************************************************************/
// 기존의 과제를 수행했던 이클립스의 작업공간에서 새로운 프로젝트 CH5_2를 만들고 
// 그 밑에 src 풀더를 만든 후 src 폴더 밑에 ch5_2.cpp 소스파일을 만들어라.

/******************************************************************************
 * 코드 추가 1
 ******************************************************************************/
// 1) 기존에 작성했던 ch5_1.cpp의 내용을 모두 복사해서 ch5_2.cpp에 삽입하라.
// 2) 프로그램의 맨 앞쪽 주석 부분의 "Author: " 행 다음의 내용을 아래 *로 시작하는 행들로 교체하라.
//----------------------------------------------------------------------------
 *
 *  + MainMenu 수정
 *  + class Person의 두 멤버의 타입을 배열[]에서 포인터로 즉, char* address, char* memo_c_str로 변경
 *  + Person 클래스에 copyAddress(), copyMemo() 추가
 *  + Person 생성자, inputMembers(), printMembers(), setAddress(), setMemo() 수정
 *  + Person(const Person& p) 복사생성자 수정
 *  + Memo::set_c_str(): 매개변수 c_str==nullptr일 경우 ""로 설정
 *  + Person::printMembers(): address==nullptr일 경우 "" 출력
 *  + Person::inputMembers(): 지역변수 char address[40] 추가
 *  + Person::assign() 추가
 *  + CopyConstructor 멤버 함수에서 u = backup 대신 u.assign(backup)
 */

/******************************************************************************
 * 코드 추가 2
 ******************************************************************************/
// 1) 아래 class AllocatedMember를 CopyConstructor와 MainMenu 클래스 사이에 배치하라.
//-----------------------------------------------------------------------------

/******************************************************************************
 * ch5_2: AllocatedMember, new을 이용한 동적 메모리 할당한 멤버 취급
 ******************************************************************************/
class AllocatedMember
{
    Person  u;
    Memo    memo;

public:
    AllocatedMember():
        u("u", 1, 70, true, "NAMDAEMUN-RO 123, JONGNO-GU, SEOUL, KOREA") {
        //u.setMemo("It is believed that the Aborigines of the American continent\n");
    }

    void run() {
        //using AM = AllocatedMember;

        // TODO 문제 [1]: func_t, func_arr[], menuCount 선언

        string menuStr =
            "++++++++++++++++ Allocated Member Menu ++++++++++++++++\n"
            "+ 0.Exit 1.ChangeAddress 2.ChangeMemo 3.UsingMemoMenu +\n"
            "+ 4.CopyConstructor 5.NullptrMember 6.inputPerson     +\n"
            "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

        // TODO 문제 [1]: while 문장 삽입하여 선택된 메뉴항목 실행하는 함수 호출
        cout << menuStr;
  }
}; // ch5_2: AllocatedMember


//-----------------------------------------------------------------------------
// 2) MainMenu::run() 내의 menuStr의 일부를 아래처럼 대체하라.
//    그리고 switch 문장에 AllocatedMember().run()을 호출하는 case를 추가하라.
//    menuCount도 조정하라.
//-----------------------------------------------------------------------------

"* 2.Class:Object(ch3_1) 3.CopyConstructor(ch5_1) 4.AllocatedMember(ch5_2) *\n"


===============================================================================
== 초기 프로그램 실행 결과
=============================================================================== 

******************************* Main Menu *********************************
* 0.Exit 1.PersonManager(ch3_2, 4)                                        *
* 2.Class:Object(ch3_1) 3.CopyConstructor(ch5_1) 4.AllocatedMember(ch5_2) *
***************************************************************************
Menu item number? 4
Person::Person(...):u 1 70 true :NAMDAEMUN-RO 123, JONGNO-GU, SEOUL, KOREA:
++++++++++++++++ Allocated Member Menu ++++++++++++++++
+ 0.Exit 1.ChangeAddress 2.ChangeMemo 3.UsingMemoMenu +
+ 4.CopyConstructor 5.NullptrMember 6.inputPerson     +
+++++++++++++++++++++++++++++++++++++++++++++++++++++++
Person::~Person():u 1 70 true :NAMDAEMUN-RO 123, JONGNO-GU, SEOUL, KOREA:

******************************* Main Menu ...
Menu item number?


/******************************************************************************
 * [문제 1]
 ******************************************************************************/
// AllocatedMember::run()에서 아래 사항들을 수행하라.
// 1) 기존의 아래 문장들을 삭제하라.
        cout << menuStr;
// 2) 기존 PersonManager::run()을 참조하여 func_t, func_arr[], menuCount를 추가하라.
//    현재는 메뉴항목 중 Exit만 지원하도록 func_arr[]을 구성하라.
// 3) while 문장 삽입하여 선택된 메뉴항목 실행하는 함수를 호출하라.

===============================================================================
== [문제 1] 실행 결과
=============================================================================== 

******************************* Main Menu *********************************
* 0.Exit 1.PersonManager(ch3_2, 4)                                        *
* 2.Class:Object(ch3_1) 3.CopyConstructor(ch5_1) 4.AllocatedMember(ch5_2) *
***************************************************************************
Menu item number? 4
Person::Person(...):u 1 70 true :NAMDAEMUN-RO 123, JONGNO-GU, SEOUL, KOREA:

++++++++++++++++ Allocated Member Menu ++++++++++++++++
+ 0.Exit 1.ChangeAddress 2.ChangeMemo 3.UsingMemoMenu +
+ 4.CopyConstructor 5.NullptrMember 6.inputPerson     +
+++++++++++++++++++++++++++++++++++++++++++++++++++++++
Menu item number? 1
1: OUT of selection range(0 ~ 0)
Menu item number? 0
Person::~Person():u 1 70 true :NAMDAEMUN-RO 123, JONGNO-GU, SEOUL, KOREA:

******************************* Main Menu ...
Menu item number? 


/******************************************************************************
 * [문제 2]
 ******************************************************************************/
// 지금까지는 Person의 멤버 중 동적으로 메모리를 할당 받는 멤버가 없었기 때문에 굳이 복사생성자가 
// 필요없었다. 이 경우 컴파일러가 자동으로 복사생성자를 만드는데 이는 멤버들을 1:1로 복사해 준다.
// 그럼에도 불구하고 우리가 복사생성자를 만든 이유는 이 함수의 실행 과정을 확인하기 위해서였다.
//-----------------------------------------------------------------------------
// 반드시 복사생성자를 만들어야 하는 경우를 보이기 위해 
// 우선 Person의 address와 memo_c_str 두 멤버를 아래처럼 포인터로 수정하고,
// 두 멤버함수 copyAddress()와 copyMemo()의 함수 선언을 추가하라.
//-----------------------------------------------------------------------------
// 중요: 클래스 멤버들 중 포인터 변수가 있고 이 변수에 메모리를 동적으로 할당해야 한다면
//      생성자, 복사생성자, 소멸자 함수가 반드시 필요하게 된다. 
//-----------------------------------------------------------------------------

class Person {
    string name;            // 이름: 변경
    ...
    char*  address;         // 주소:  5_2에서 []에서 *로 변경
    char*  memo_c_str;      // 메모장: 5_2에서 []에서 *로 변경

protected: ...
    void copyAddress(const char* address); // 5_2에서 추가
    void copyMemo(const char* c_str);      // 5_2에서 추가

//-----------------------------------------------------------------------------
// Person 생성자를 아래처럼 수정하라. memo_c_str은 초기 값으로 nullptr로 설정한다.
//-----------------------------------------------------------------------------

Person::Person(const string name, int id, double weight, bool married, const char* address):
        name(name), id{id}, weight{weight}, married{married}, memo_c_str{} {
    // 생성자 서두에서 memo_c_str{}은 초기 값으로 디폴트 값인 nullptr(실제로는 주소 값 0)로 설정됨
    copyAddress(address);
    cout << "Person::Person(...):"; println();
}

//-----------------------------------------------------------------------------
// 1) 아래의 함수 코드들을 교체 또는 추가하고 TODO 부분을 구현하라. 
//-----------------------------------------------------------------------------

Person::~Person() {
    cout << "Person::~Person():"; println();

    if (address) cout << "address";
    if (address && memo_c_str) cout << ", ";
    if (memo_c_str) cout << "memo_c_str";
    if (address || memo_c_str) cout << " deleted" << endl;
    // 위 if 문장들은 i) "address deleted" 또는 
    // ii) "memo_c_str deleted" 또는 
    // iii) "address, memo_c_str deleted" 가 출력됨; 즉, 셋 중 하나가 출력됨

    TODO: address와 memo_c_str가 포인터하는 배열 메모리를 반납한다.
          이들 포인터가 nullptr인 경우 반납하지 말아야 한다.
}

// 처음 객체가 초기화될 때(생성자 또는 복사생성자) address 멤버를 초기화하고자 할 때 호출된다. 
// 즉, 일반 생성자 또는 복사 생성자에서만 호출됨.
// 새로 할당받은 메모리에 매개변수 address 문자열을 복사한다.
void Person::copyAddress(const char* address) {
    TODO: 매개변수 address가 nullptr인 경우, address 멤버도 nullptr로 설정하고 리턴하라.
          매개변수 address가 포인터하는 문자열을 포함할 수 있는 배열 메모리를 할당 받은 후
          할당된 메모리 주소를 멤버 address에 저장하고, 
          매개변수의 문자열을 멤버 변수의 할당받은 메모리로 복사한다. 
          // [교재 예제 5-11]의 복사 생성자  참조할 것
          // strlen(), strcpy() 함수는 구글링 또는 http://www.cplusplus.com/reference/에서 검색
          // strlen()은 끝의 null 문자를 포함하지 않은 길이이므로 
          // 이를 포함하기 위해 할당해야 할 메모리는 strlen()+1이어야 함 
          // strcpy()는 끝의 null 문자도 함께 복사해 준다라는 사실에 유의하라.
}

// 복사 생성자에 의해 처음 메모 문자열 memo_c_str을 초기화할 때 호출된다. 
// 복사 생성자에서만 호출되고 일반 생성자에서는 nullptr로 설정됨
void Person::copyMemo(const char* c_str)      {
    TODO: 매개변수 c_str가 nullptr인 경우, memo_c_str만 nullptr로 설정하고 리턴하라.
          매개변수 c_str가 포인터하는 문자열을 포함할 수 있는 배열 메모리를 할당 받아 
          멤버 memo_c_str에 주소를 저장하고 매개변수의 문자열을 멤버 변수로 복사한다.
}

===============================================================================
== [문제 2] 실행 결과
=============================================================================== 

******************************* Main Menu *********************************
* 0.Exit 1.PersonManager(ch3_2, 4)                                        *
* 2.Class:Object(ch3_1) 3.CopyConstructor(ch5_1) 4.AllocatedMember(ch5_2) *
***************************************************************************
Menu item number? 4             
// AllocatedMember::u 멤버 생성자 실행; 아래에서 address가 정확히 출력되어야 함
Person::Person(...):u 1 70 true :NAMDAEMUN-RO 123, JONGNO-GU, SEOUL, KOREA:

++++++++++++++++ Allocated Member Menu ++++++++++++++++
+ 0.Exit 1.ChangeAddress 2.ChangeMemo 3.UsingMemoMenu +
+ 4.CopyConstructor 5.NullptrMember 6.inputPerson     +
+++++++++++++++++++++++++++++++++++++++++++++++++++++++
Menu item number? 0
// AllocatedMember::u 멤버 소멸자 실행
Person::~Person():u 1 70 true :NAMDAEMUN-RO 123, JONGNO-GU, SEOUL, KOREA:
address deleted                 // memo_c_str은 nullptr이므로 출력되지 않음

******************************* Main Menu ...
Menu item number? 


/******************************************************************************
 * [문제 3]
 ******************************************************************************/
// 1) Person 클래스 내부에서 구현했던 기존 setAddress()를 아래처럼 선언문으로 변경하라.
    void setAddress(const char* address); // 5_2에서 수정

//-----------------------------------------------------------------------------
//    그리고 클래스 외부에 아래처럼 구현 함수를 Person::copyMemo() 뒤에 배치하고 TODO를 구현하라.
//-----------------------------------------------------------------------------

// 생성자 또는 복사생성자에 의해 이미 한번 초기화된 주소 문자열(기존의 주소)을 다른 주소로 변경할 때 호출됨 
// 이미 멤버 address용 메모리가 할당되었기 때문에 기존 메모리를 먼저 반납해야 하고 새로 할당해야 함
void Person::setAddress(const char* address) {
    TODO: 기존의 멤버 address가 nullptr이 아닌 경우
        cout << "old address(" << this->address << ") deleted" << endl;
        멤버 address가 포인터하는 [배열] 메모리를 반납한다. 반납시 [] 를 꼭 사용해야 한다.
    copyAddress(address); // 새로 메모리 할당받은 후 복사한다.
}

//-----------------------------------------------------------------------------
// 2) 아래 함수를 AllocatedMember 클래스 내의 public: 영역 위 쪽의 private 영역에 배치하라.
//    Person::setAddress() 함수를 테스트한다.
//-----------------------------------------------------------------------------

    void set_print_address(Person& p, const char* address) {
        cout << "p.setAddress(" << (address? address : "") << ")" << endl;
        p.setAddress(address);
        p.println();
        cout << endl;
    }

    void changeAddress() { // Menu Item 1
        Person p("p", 1, 70, true, "Gwangju");
        set_print_address(p, "short address");
        set_print_address(p, "middle length Address, Seoul");
        set_print_address(p, "long length Address Seoul Mapo-gu Korea");
        set_print_address(p, u.getAddress());
    }
    
//-----------------------------------------------------------------------------
// 3) AllocatedMember::run() 내의 AM 주석을 해제하고 
//    func_arr[]에 위 멤버 함수 주소를 추가하라. 이때 AM을 활용하라.

===============================================================================
== [문제 3] 실행 결과
=============================================================================== 

++++++++++++++++ Allocated Member Menu ...
Menu item number? 1
Person::Person(...):p 1 70 true :Gwangju:
p.setAddress(short address)
old address(Gwangju) deleted
p 1 70 true :short address:

p.setAddress(middle length Address, Seoul)
old address(short address) deleted
p 1 70 true :middle length Address, Seoul:

p.setAddress(long length Address Seoul Mapo-gu Korea)
old address(middle length Address, Seoul) deleted
p 1 70 true :long length Address Seoul Mapo-gu Korea:

p.setAddress(NAMDAEMUN-RO 123, JONGNO-GU, SEOUL, KOREA)
old address(long length Address Seoul Mapo-gu Korea) deleted
p 1 70 true :NAMDAEMUN-RO 123, JONGNO-GU, SEOUL, KOREA:

Person::~Person():p 1 70 true :NAMDAEMUN-RO 123, JONGNO-GU, SEOUL, KOREA:
address deleted                     // 소멸시 address가 반납되었음


/******************************************************************************
 * [문제 4]
 ******************************************************************************/
// 1) Person 클래스 내부에 구현했던 기존 setMemo()를 아래처럼 선언문으로 변경하라.
    void setMemo(const char* c_str);      // 5_2에서 수정

//-----------------------------------------------------------------------------
//    그리고 클래스 외부에 아래처럼 구현 함수를 Person::setAddress() 뒤에 배치하고 TODO를 구현하라.
//-----------------------------------------------------------------------------

// 멤버 memo_c_str은 생성자에 의해 nullptr로 설정되었거나 복사생성자에 의해 이미 초기화되었 수도 있음
// 만약 멤버 memo_c_str용 메모리가 할당되었다면 먼저 반납해야 함
void Person::setMemo(const char* c_str)      {
    TODO: 기존의 멤버 memo_c_str가 nullptr이 아닌 경우
              cout << "old memo_c_str deleted" << endl;
              멤버 memo_c_str가 포인터하는 [배열] 메모리를 반납한다. []를 잊지 마라.
    copyMemo(c_str); // 새로 메모리 할당받아 복사한다.
}

//-----------------------------------------------------------------------------
// 2) 아래 함수를 AllocatedMember 클래스 내의 changeAddress() 뒤에 배치하고
//    AllocatedMember::run() 내의 func_arr[]에 적절한 멤버 함수 주소를 추가하라.
//    Person::setMemo() 함수를 테스트한다.
//-----------------------------------------------------------------------------

    void print_memo(Person& p) { // 객체 p의 메모 출력
        cout << "------ " << p.getName() << " memo ------" << endl;
        const char *pmemo = p.getMemo();
        cout << (pmemo? pmemo : ""); // 메모 출력; nullptr이면 "" 출력
        cout << "--------------------" << endl << endl;
    }

    void set_print_memo(Person& p, const char* memo) { // 객체 p에 메모 복사하고 출력
        cout << "p.setMemo(memo)" << endl;
        p.setMemo(memo);
        print_memo(p);
    }

    void changeMemo() { // Menu Item 2
        Person p("p", 1, 70, true, "Gwangju");
        set_print_memo(p, "short memo\n");
        set_print_memo(p, "middle long memo: The Last of the Mohicans\n");
        set_print_memo(p, u.getMemo());
    }
    
//-----------------------------------------------------------------------------
// 3) 생성자 AllocatedMember() 내의 u.setMemo(...) 주석을 풀어라.

===============================================================================
== [문제 4] 실행 결과
=============================================================================== 

++++++++++++++++ Allocated Member Menu ...
Menu item number? 2
Person::Person(...):p 1 70 true :Gwangju:
p.setMemo(memo)
// 생성자에서 memo_c_str이 nullptr로 설정되므로 memo_c_str 메모리가 반납되지 않음
------ p memo ------
short memo
--------------------

p.setMemo(memo)
old memo_c_str deleted // 기존 메모 메모리 반납
------ p memo ------
middle long memo: The Last of the Mohicans
--------------------

p.setMemo(memo)
old memo_c_str deleted
------ p memo ------
It is believed that the Aborigines of the American continent
--------------------

Person::~Person():p 1 70 true :Gwangju:
address, memo_c_str deleted   // 소멸시 address와 memo_c_str가 반납되었음


/******************************************************************************
 * [문제 5]
 ******************************************************************************/
// 아래 함수를 AllocatedMember 클래스 내의 changeMemo() 뒤에 배치하고
// AllocatedMember::run() 내의 func_arr[]에 적절한 멤버 함수 주소를 추가하라.
// 이 역시 Person::setMemo() 함수를 테스트한다.
//-----------------------------------------------------------------------------

    void manageMemo() { // Menu item 3
        memo.set_c_str(u.getMemo());
        memo.run();
        cout << "\nmemo.run() returned" << endl;
        u.setMemo(memo.get_c_str());   // 메모 메뉴에서 새로 삽입한 메모를 u에 저장 
        print_memo(u);
    }

===============================================================================
== [문제 5] 실행 결과
=============================================================================== 

++++++++++++++++ Allocated Member Menu ++++++++++++++++
+ 0.Exit 1.ChangeAddress 2.ChangeMemo 3.UsingMemoMenu + ...
Menu item number? 3

++++++++++++++++++++++ Memo Management Menu ...
Menu item number? 1
------- Memo -------
It is believed that the Aborigines of the American continent
--------------------

++++++++++++++++++++++ Memo Management Menu ...
Menu item number? 9
--- Input memo lines, and then input empty line at the end ---
In war, he is daring, boastful, cunning, ruthless, self-denying,
and self-devoted; in peace, just, generous, hospitable, revengeful,
superstitious, modest, and commonly chaste.
These are qualities, it is true, which do not distinguish all alike;
but they are so far the predominating traits of these remarkable people
as to be characteristic.
It is generally believed that the Aborigines of the American continent
have an Asiatic origin.


++++++++++++++++++++++ Memo Management Menu ...
Menu item number? 0

memo.run() returned
old memo_c_str deleted
------ u memo ------    // 메모 메뉴에서 새로 삽입한 메모를 u에 저장한 한 후 출력으로 확인함
In war, he is daring, boastful, cunning, ruthless, self-denying,
and self-devoted; in peace, just, generous, hospitable, revengeful,
superstitious, modest, and commonly chaste.
These are qualities, it is true, which do not distinguish all alike;
but they are so far the predominating traits of these remarkable people
as to be characteristic.
It is generally believed that the Aborigines of the American continent
have an Asiatic origin.
--------------------


++++++++++++++++ Allocated Member Menu ...
Menu item number? 


/******************************************************************************
 * [문제 6]
 ******************************************************************************/
// 클래스 멤버들 중 메모리를 할당 받은 포인터 변수가 있으면 복사 생성자도 수정하여야 한다.
// Person의 복사 생성자를 아래처럼 수정하라.
// copyAddress()와 copyMemo()는 멤버 address와 memo_c_str 를 위한 메모리를 동적으로 할당받고
// p 객체의 주소와 메모를 복사하는 역할을 한다. 
// 이 두 함수는 생성자 또는 복사생성자에서 처음으로 두 멤버를 초기화할 때만 사용된다. 
// 이렇게 초기화된 두 멤버들을 수정하고자 할 때는 setAddress()와 setMemo()를 사용해야 함
//-----------------------------------------------------------------------------

Person::Person(const Person& p): /* 기존과 동일 */ {
    TODO: p 객체의 address 문자열을 멤버 address에 복사함 
          (즉, setAddress() 대신 copyAddress() 사용해야 함)
          p 객체의 메모 문자열을 멤버 memo_c_str에 복사함 (copyMemo() 사용해야 함)
    cout << "Person::Person(const Person&):"; println();
}

//-----------------------------------------------------------------------------
// 아래 함수를 AllocatedMember 클래스 내의 manageMemo() 뒤에 배치하고
// AllocatedMember::run() 내의 func_arr[]에 적절한 멤버 함수 주소를 추가하라.
// 복사생성자 Person::Person(const Person& p)를 테스트한다.
//-----------------------------------------------------------------------------

    Person call_by_value_and_return_value(Person p) { // 복사생성자로 p 초기화
        cout << "p.setName(p)" << endl;
        p.setName("p");
        // 함수 리턴 전에 p를 p2에 복사해서 초기화(복사생성자)
        cout << "p2: ";
        return p; // 함수 리턴 시 p 소멸자 실행
    }

    void copyConstructor() { // Menu Item 4
        cout << "u: ";    u.println();
        print_memo(u);

        cout << "Person p1(u)" << endl;
        cout << "p1: ";
        Person p1(u); // 명시적 복사생성자로 p1 초기화
        p1.setName("p1");
        p1.println();
        print_memo(p1);

        cout << "Person p2 = call_by_value_and_return_value(p1)" << endl;
        // 묵시적으로 두번의 복사생성자 실행: 함수 인자를 넘길 때, 함수 리턴 값을 p2에 복사할 때
        cout << "p: ";
        Person p2 = call_by_value_and_return_value(p1);
        cout << "call_by_value_and_return_value(p1) returned\n" << endl;
        cout << "p2.setName(p2)" << endl;
        p2.setName("p2");
        p2.println();
        print_memo(p2);
        cout << "copyConstructor() returns" << endl;
        // 함수 리턴 시 지역객체 p1, p2 소멸자 실행됨
    }

===============================================================================
== [문제 6] 실행 결과
=============================================================================== 

++++++++++++++++ Allocated Member Menu ...
Menu item number? 4
u: u 1 70 true :NAMDAEMUN-RO 123, JONGNO-GU, SEOUL, KOREA:
------ u memo ------     // print_memo(u)
It is believed that the Aborigines of the American continent
--------------------

Person p1(u)  // 명시적으로 복사생성자를 이용해 p1 초기화
p1: Person::Person(const Person&):u 1 70 true :NAMDAEMUN-RO 123, JONGNO-GU, SEOUL, KOREA:
p1 1 70 true :NAMDAEMUN-RO 123, JONGNO-GU, SEOUL, KOREA:
------ p1 memo ------
It is believed that the Aborigines of the American continent
--------------------

Person p2 = call_by_value_and_return_value(p1) 
// 아래는 복사생성자를 이용해 call_by_value_and_return_value(Person p)의 매개변수 p 초기화 
p: Person::Person(const Person&):p1 1 70 true :NAMDAEMUN-RO 123, JONGNO-GU, SEOUL, KOREA:
p.setName(p)                 
// 리턴할 때 p를 복사하여 임시 객체를 만들고(복사생성자) 
// 이 임시 객체를 다시 p2에 대입(복사생성자)하는 두번의 복사생성자를 실행하는 대신에  
// 객체 p를 복사생성자를 이용하여 p2에 바로 복사함 (이 경우 한번의 복사생성자만 실행함)
p2: Person::Person(const Person&):p 1 70 true :NAMDAEMUN-RO 123, JONGNO-GU, SEOUL, KOREA:
// call_by_value_and_return_value(Person p)의 매개변수 p 소멸
Person::~Person():p 1 70 true :NAMDAEMUN-RO 123, JONGNO-GU, SEOUL, KOREA:
address, memo_c_str deleted              // 매개변수 p의 address와 memo_c_str가 반납되었음
call_by_value_and_return_value(p1) returned

p2.setName(p2)
p2 1 70 true :NAMDAEMUN-RO 123, JONGNO-GU, SEOUL, KOREA:
------ p2 memo ------
It is believed that the Aborigines of the American continent
--------------------

copyConstructor() returns      
// 아래는 묵시적으로 복사생성자(Person p2 = call_...)에 의해 초기화되었던 지역 객체 p2 소멸
Person::~Person():p2 1 70 true :NAMDAEMUN-RO 123, JONGNO-GU, SEOUL, KOREA:
address, memo_c_str deleted    
// 아래는 명시적 복사생성자(Person p1(u))에 의해 초기화되었던 지역 객체 p1 소멸
Person::~Person():p1 1 70 true :NAMDAEMUN-RO 123, JONGNO-GU, SEOUL, KOREA:
address, memo_c_str deleted


/******************************************************************************
 * [문제 7]
 ******************************************************************************/
// 아래 함수를 AllocatedMember 클래스 내의 copyConstructor() 뒤에 배치하고
// AllocatedMember::run() 내의 func_arr[]에 적절한 멤버 함수 주소를 추가하라.
// Person::setAddress()와 setMemo() 호출 시 인자로 nullptr가 주어졌을 때를 테스트한다.
//-----------------------------------------------------------------------------

    void nullptrMember() { // Menu Item 5
        u.println();
        print_memo(u);
        cout << "set address = memo_c_str = nullptr" << endl;
        u.setAddress(nullptr);
        u.setMemo(nullptr);
        u.println();
        print_memo(u);

        cout << "memo.set_c_str(u.getMemo())" << endl;
        memo.set_c_str(u.getMemo()); // u.getMemo() == nullptr이므로 memo의 mStr은 ""이다.
        memo.displayMemo();

        cout << endl << "u.setMemo(memo.get_c_str())" << endl;
        u.setMemo(memo.get_c_str()); // memo.get_c_str() == nullptr 이므로
                                      // u의 memo_c_str은 nullptr로 설정
        print_memo(u);
    }

//-----------------------------------------------------------------------------
// 위 함수의 memo.set_c_str(u.getMemo())에서 알 수 있듯이 매개변수가 nullptr일 수 있다.
// 기존의 Memo::set_c_str(const char *c_str)은 무조건 mStr = c_str로 설정했다.
// 이 경우 c_str이 nullptr일 경우 프로그램이 죽게된다. 따라서 아래처럼 수정하라.
//-----------------------------------------------------------------------------

    void set_c_str(const char *c_str) { 
        TODO: 매개변수 c_str이 nullptr일 경우 mStr을 ""로 설정하고 
              아닌 경우 mStr을 c_str로 설정하라. 
              mStr = ? : ; 3항 연산자를 사용하여 한 문장으로 완성하라.
    }  // C 문자열로 메모 mStr 초기화

//-----------------------------------------------------------------------------
// 기존의 Person::printMembers(ostream* pout)는 address가 nullptr일 경우 
// 프로그램이 죽게 된다. address가 nullptr일 경우 ""를 출력하도록 수정하라.
//-----------------------------------------------------------------------------

void Person::printMembers(ostream* pout) {
    *pout << name << ...
             married << " :" << (TODO: 3항 연산자를 이용하여 "" 또는 address 출력) << ":";
    // 3항 연산자를 이용하여 address가 nullptr일 경우 ""를 출력하고 아닌 경우 address를 출력하라. 
}

===============================================================================
== [문제 7] 실행 결과
=============================================================================== 

++++++++++++++++ Allocated Member Menu ...
Menu item number? 5
u 1 70 true :NAMDAEMUN-RO 123, JONGNO-GU, SEOUL, KOREA:
------ u memo ------
It is believed that the Aborigines of the American continent
--------------------

set address = memo_c_str = nullptr
old address(NAMDAEMUN-RO 123, JONGNO-GU, SEOUL, KOREA) deleted
old memo_c_str deleted
u 1 70 true ::
print_memo
------ u memo ------
--------------------

memo.set_c_str(u.getMemo())
------- Memo -------
--------------------

u.setMemo(memo.get_c_str())
------ u memo ------
--------------------


/******************************************************************************
 * [문제 8]
 ******************************************************************************/
// 기존의 Person::inputMembers(istream* pin)의 경우 address[]가 매우 큰 배열이었기 때문에 
// 무조건 pin->getline(address, sizeof(address), ':')로 주소를 읽어 들일 수 있었다.
// 그러나 이제 Person의 address 멤버는 동적으로 할당 받아야 하는데 읽어 들일 주소의 문자열 길이를 
// 사전에 알 수 없다. 그래서 아래처럼 함수를 수정해야 한다. 코드를 완성하라.
//-----------------------------------------------------------------------------

void Person::inputMembers(istream* pin)   {
    *pin >> name >> id >> weight >> married;
    if (!(*pin)) return;
    
    // 지역변수로 미리 큰 주소용 배열을 잡는다.
    char address[40];    // ch5_2에서 추가됨

    TODO: 기존 코드를 그대로 사용해서 키보드에서 주소를 읽어 위 지역변수 address[40]에 저장한다.
          기존 코드와 동일하지만 기존의 코드는 멤버 address에 바로 읽어 들이는 것이고,
          여기선 위 지역변수 address[40]에 먼저 읽어 들이고 이를 멤버에 복사한다.

    // 아래 함수를 통해 위 지역변수 address[]에 있는 주소를 멤버 address로 복사한다. 
    // 아래 함수에서 address[]의 문자열 길이만큼 메모리를 할당(멤버 address용) 받은 후 복사한다.
    // 멤버 address는 이전에 이미 초기화되었기 때문에 copyAddress()가 아닌 아래 함수를 사용함
    setAddress(address); // ch5_2에서 추가됨
}

//-----------------------------------------------------------------------------
// 아래 함수를 AllocatedMember 클래스 내의 nullptrMember() 뒤에 배치하고
// AllocatedMember::run() 내의 func_arr[]에 적절한 멤버 함수 주소를 추가하라.
//-----------------------------------------------------------------------------

    void inputPerson() { // Menu item 6
        cout << "u: "; u.println();
        while (!UI::inputPerson(&u)) ;  // USER 11 88 false :DONG-GU, DAEGU:
        cout << "u: "; u.println();
    }

===============================================================================
== [문제 8] 실행 결과
=============================================================================== 

++++++++++++++++ Allocated Member Menu ...
Menu item number? 6
u: u 1 70 true :NAMDAEMUN-RO 123, JONGNO-GU, SEOUL, KOREA:
input person information:
USER 11 88 false :DONG-GU, DAEGU:
old address(NAMDAEMUN-RO 123, JONGNO-GU, SEOUL, KOREA) deleted
u: USER 11 88 false :DONG-GU, DAEGU:


/******************************************************************************
 * [문제 9]
 ******************************************************************************/
// class CopyConstructor의 일부 멤버 함수에서 = 연산자 문장을 사용하였다. (예: u = backup)
// 이는 = 연산자를 이용하여 backup 객체의 메모리를 u에 그대로 복사하는 역할을 한다.
// Person의 address, memo_c_str가 과거처럼 배열[]일 경우에는 실제 배열이 복사되어 문제가 전혀 없다.
// 그런데 지금은 배열이 아니라 포인터 변수이므로 = 연산자의 경우 address와 memo_c_str 포인터 변수를 
// 그대로 복사하는 것이다.(얕은 대입) 이렇게 되면 두 객체 u와 backup은 동일한 address와 memo_c_str를 
// 공유하게 되는 것이다. 즉, 객체가 소멸할 때 두 번 메모리를 반납하는 문제가 발생할 수 있음
//-----------------------------------------------------------------------------
// 따라서 아래 실행 결과에서처럼 Copy Constructor Menu의 6번 메뉴 returnDataType()를 실행할 때 
// u = backup;는 앝은 대입 연산자가 실행되어 u와 backup은 동일한 address 포인터를 가진다.
// 이후 0번 메뉴를 실행하여 CopyConstructor 객체가 소멸될 때 멤버인 u와 backup의 소멸자가 실행되는데
// backup이 먼저 소멸되고(이땐 정상 소멸) 두번째 객체(u) 소멸 시 주소 부분에서 문제가 발생한다.
// 즉, 첫번째 객체(backup) 소멸시 address 메모리가 반납 되었는데 
// 두번째 객체(u) 소멸 시 동일한 address 메모리를 또 반납하게 되어 문제가 발생했다. 
// 교재에서 소개된 얕은 복사의 문제점과 유사하다.
//-----------------------------------------------------------------------------

******************************* Main Menu ...
* 2.Class:Object(ch3_1) 3.CopyConstructor(ch5_1) ...
Menu item number? 3
+++++++++ Reference And Copy Constructor Menu ...
Menu item number? 6
...
...

+++++++++ Reference And Copy Constructor Menu ...
Menu item number? 0
Person::~Person():u 1 70 true :Seoul:          // backup은 정상 소멸됨
address deleted
Person::~Person():u 1 70 true :(?"??"?u픎?:  // u 소멸: 여기서 문제가 발생
address deleted

//-----------------------------------------------------------------------------
// 위와 같은 문제를 해결하기 위해 얕은 대입을 하는 = 연산자 대신 "깊은 대입(=)"을 하는 
// assign() 멤버함수를 Person에 추가할 필요가 있다. 아래 구현 함수를 Person::whatAreYouDoing()
// 뒤에 배치시키고 이 구현 함수의 함수 선언을 Person 클래스 내의 제일 마지막에 추가하라.
// 1) TODO 부분의 코드를 완성하라.
//-----------------------------------------------------------------------------

// 깊은 대입(=) 연산: p의 모든 멤버 값을 this에 복사한다. 멤버가 동적으로 메모리를 할당받은 경우 
// 먼저 this의 멤버의 메모리를 먼저 반납하고 새로 메모리를 할당 받은 후 복사한다. 
Person& Person::assign(const Person& p) {

    TODO: name, passwd, id, weight, married 멤버의 경우 = 연산자를 사용하여 p의 상응하는 
          멤버 값을 this의 멤버에 바로 대입시켜라. (C++의 기본 데이타 타입과 string인 경우)
          즉, this의 각 멤버에 =를 이용해 p의 멤버 값을 저장하라.
          
          p.addres와 p.memo_c_str의 경우 각각 setAddress(), setMemo()를 호출하여
          this의 addres와 memo_c_str에 복사하라. 이 함수들은 기존에 할당 받았던 this의
          address와 memo_c_str 멤버의 메모리를 먼저 반납하고 새로 할당 받은 후 복사한다.
          // 복사생성자에서는 copyAddress()와 copyMemo()를 호출했는데 (처음 초기화할 때)
          // 여기서는 setAddress(), setMemo()를 호출하였다. (기존 값을 변경하고자 할 때)
          // 왜 그렇게 했는지 이해했는가?

    return *this; // this 객체 자신의 참조자를 반환한다.
    // 자신 객체의 참조자를 리턴했기 때문에 c.assign(p.assign(backup)).println() 등의
    // 연속된 함수 호출도 가능해 진다. 즉 (c = p = backup).println()과 같은 효과
}

//-----------------------------------------------------------------------------
// 2) CopyConstructor 클래스 내의 callByReference(), callByAddress(), 
//    return_reference_test(), return_address_test() 함수들에 있는 
//    u = backup 문장을 위 Person::assign() 멤버 함수로 대체하라.
//-----------------------------------------------------------------------------
// 3) CopyConstructor::inputPerson()에서 backup = u를 
//    위 Person::assign() 멤버 함수로 대체하라.

===============================================================================
== [문제 9] 실행 결과
=============================================================================== 
******************************* Main Menu ...
Menu item number? 3
...

+++++++++ Reference And Copy Constructor Menu ...
Menu item number? 5
...

+++++++++ Reference And Copy Constructor Menu ...
Menu item number? 6
...

+++++++++ Reference And Copy Constructor Menu ...
Menu item number? 0
Person::~Person():u 1 70 true :Gwangju:  // 정상적으로 객체의 주소가 반납되어야 한다.
address deleted
Person::~Person():u 1 70 true :Gwangju:  // 정상적으로 객체의 주소가 반납되어야 한다.
address deleted
// 프로그램이 죽지 않고 정상적으로 이 메뉴에서 종료되어야 한다.

******************************* Main Menu ...
...


/******************************************************************************
 * 자동 오류 체크 모드로 프로그램 실행
 ******************************************************************************/
// 1. clc.chosun.ac.kr의 [강의자료실]에서 CH5_2 과제 테스트 파일을 다운받은 후 
//    압축 파일을 풀고 test 폴더를 드래깅하여 이클립스의 [Project Explorer]의 
//    [CH5_2] 프로젝트 위에 드랍한다. (test 폴더와 그 밑에 테스트용 파일이 있어야 함)
// 2. 기존 프로젝트 CH2의 src 폴드에 있는 check_error.h를 CH5_2 프로젝트의 
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