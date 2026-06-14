```
[7장 문제-2]

//----------------------------------------------------------------------------
// 아래 문제를 해결하는 도중 출력이 잘못되었거나 문제 설명과 출력이 일치하지 않거나 오타가 있거나 등등
// 조금이라도 문제에 이상한 것이 있으면 주저하지 말고 jhshim@chosun.ac.kr로 알려 주시기 바랍니다.
//----------------------------------------------------------------------------

/******************************************************************************
 * 프로젝트 및 소스파일 생성
 ******************************************************************************/
// 기존의 과제를 수행했던 이클립스의 작업공간에서 새로운 프로젝트 CH7_2를 만들고 
// 그 밑에 src 풀더를 만든 후 src 폴더 밑에 ch7_2.cpp 소스파일을 만들어라.

/******************************************************************************
 * 코드 추가 및 변경 1
 ******************************************************************************/
// 1) 기존에 작성했던 ch7_1.cpp의 내용을 모두 복사해서 ch7_2.cpp에 삽입하라.
// 2) 프로그램의 맨 앞쪽 주석 부분의 "Author: " 행 다음의 내용을 아래 *로 시작하는 행들로 교체하라.
//----------------------------------------------------------------------------
 *
 *  + VectorPerson에 operator 추가
 *  + VectorOperator 클래스 추가
 */

/******************************************************************************
 * 코드 추가 2
 ******************************************************************************/
// 1) 아래 class VectorOperator를 AllocatedMember와 OperatorOverload 클래스 사이에 배치하라.
//-----------------------------------------------------------------------------

/******************************************************************************
 * ch7_2: VectorOperator class
 ******************************************************************************/
class VectorOperator
{
    Person pa[5] = {
        Person("Hong ", 0, 72.1, true, nullptr),
        Person("Mong ", 1, 65.4, true, nullptr),
        Person("Choon", 3, 56.7, true, nullptr),
        Person("Soon ", 2, 87.6, true, nullptr),
        Person("Chung", 4, 67.8, true, nullptr),
    };
    int pa_len = sizeof(pa) / sizeof(pa[0]);

    VectorPerson pv1, pv2;

    void disp_vector(const VectorPerson& pv) {
        int count = pv.size();
        cout << "count " << count << endl;
        for (int i = 0; i < count; ++i) {
            cout << "[" << i << "] "; pv.at(i)->println();
        }
        cout << endl;
    }

public:
    VectorOperator() {
        int i;
        for (i = 0; i < 2; ++i)
            pv1.push_back(&pa[i]); // &pa[i] == &(pa[i])
        cout << "pv1: "; disp_vector(pv1);

        for ( ; i < pa_len; ++i)
            pv2.push_back(pa+i);     // pa+i == &pa[i]
        cout << "pv2: "; disp_vector(pv2);
    }

    void run() {
        //using VO = VectorOperator;

        // TODO: func_t, func_arr[], menuCount 선언
        string menuStr =
            "+++++++++++++ Vector Operator Overload ++++++++++++++\n"
            "+ 0.Exit 1.operator[] 2.operator! 3.CopyConstructor +\n"
            "+ 4.operator= 5.operator+ 6.operator=+              +\n"
            "+++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

        // TODO: while 문장 삽입하여 선택된 메뉴항목 실행하는 함수 호출
    }

}; // ch7_2: VectorOperator class


//-----------------------------------------------------------------------------
// 2) OperatorOverload::currentUser() 함수 뒤에 아래 함수를 추가하라.
//-----------------------------------------------------------------------------
    void vectorOOL() { // Memu item 9
        VectorOperator().run();
    }

//-----------------------------------------------------------------------------
// 3) OperatorOverload::run() 내의 menuStr에 아래 내용을 교체하라.
//    또한 9번 메뉴 항목이 선택되었을 때 위 vectorOOL()을 호출하라.
            "+ 6.Shift 7.TypeConversion 8.CurrentUser 9.VectorOOL  +\n"
//-----------------------------------------------------------------------------


/******************************************************************************
 * [문제 0-1] 
 ******************************************************************************/
// VectorOperator::run()에서 아래 사항들을 수행하라.
// 1) 기존의 다른 클래스의 run()을 참조하여 func_t, func_arr[], menuCount를 추가하라.
// 2) 현재는 메뉴항목 중 Exit만 지원하도록 func_arr[]을 구성하라.
// 3) while 문장 삽입하여 선택된 메뉴항목을 실행하는 함수를 호출하라.

===============================================================================
== [문제 0-1] 실행 결과
=============================================================================== 

******************************* Main Menu ...
Menu item number? 5

+++++++++++++++++++ Operator Overload +++++++++++++++++
+ 0.Exit 1.MemoAdd 2.Equal 3.Add 4.Assign 5.Increment +
+ 6.Shift 7.TypeConversion 8.CurrentUser 9.VectorOOL  +
+++++++++++++++++++++++++++++++++++++++++++++++++++++++
Menu item number? 9
pv1: count 2     // 생성자 VectorOperator()에 의해 두 개의 벡터 pv1, pv2가 초기화됨
[0] Hong  0 72.1 true ::
[1] Mong  1 65.4 true ::

pv2: count 3
[0] Choon 3 56.7 true ::
[1] Soon  2 87.6 true ::
[2] Chung 4 67.8 true ::


+++++++++++++ Vector Operator Overload ++++++++++++++
+ 0.Exit 1.operator[] 2.operator! 3.CopyConstructor +
+ 4.operator= 5.operator+ 6.operator=+              +
+++++++++++++++++++++++++++++++++++++++++++++++++++++
Menu item number? 


/******************************************************************************
 * [문제 1] 
 ******************************************************************************/
// 기존 VectorPerson 클래스에 아래 연산자 [] 를 구현하라.
// 이 연산자의 기능은 기존의 멤버함수 VectorPerson::at()과 동일하다. 
// (기존의 at() 함수는 삭제하지 말고 그대로 두기 바란다.)

    Person* operator [] (int index) const;

//----------------------------------------------------------------------------
// 기존의 PersonManager 클래스 내에서 at() 함수를 호출하던 곳을 찾아 모두 [] 연산자로 교체하라.
// 또한 VectorOperator::disp_vector() 내의 at() 도 [] 연산자로 교체하라.
// 예) persons.at(i) => persons[i]
//----------------------------------------------------------------------------
// 아래 함수를 VectorOperator 클래스에 추가하고 run() 함수에서 호출할 수 있도록 하라.
//----------------------------------------------------------------------------
    void operatorIndex() { // Memu item 1
        MultiManager().run();
        // display(), remove(), clear(), login()에서 [index] 연산자 사용
    }

===============================================================================
== [문제 1] 실행 결과
=============================================================================== 
// test_1.in의 메뉴항목을 순서적으로 입력한 후 실행 결과를 test_1.out과 비교해 보라.
// 실행결과 비교가 힘들면 자동 오류 체크 기능을 활용해도 됨
// 각 메뉴 항목은 VectorPerson::[] 연산자를 사용한다.

/******************************************************************************
 * [문제 2] 
 ******************************************************************************/
// 기존 VectorPerson 클래스에 단항 연산자 ! 를 구현하라.

    bool operator ! ();
    
// 이 연산자는 기존의 empty() 멤버함수를 호출한 후 그 결과를 바로 리턴하면 된다.
// 즉, 벡터가 비어 있으면 true를, 원소를 하나라도 가지고 있으면 false를 반환한다.
//----------------------------------------------------------------------------
// 또한 기존 VectorPerson 클래스에 단항 연산자 bool을 구현하라.
// 이 연산자는 별도의 리턴 타입을 표시하지 않아도 되며 연산자 bool이 곧 리턴 타입이다.

    operator bool ();
    
// 이 연산자는 기존의 empty() 멤버함수를 호출한 후 그 결과의 반대 값을 리턴하면 된다.
// 즉, 벡터가 비어 있으면 false를, 원소를 하나라도 가지고 있으면 true를 반환한다.
// 이 연산자는 주로 if, while, for, ?:: 등의 조건문에서 사용된다. 아래 operatorNot() 참조

//----------------------------------------------------------------------------
// 아래 함수를 VectorOperator 클래스에 추가하고 run() 함수에서 호출할 수 있도록 하라.
//----------------------------------------------------------------------------

    void operatorNot() { // Memu item 2
        VectorPerson pv;
        disp_vector(pv);

        // operator bool() 호출
        if (pv) cout << "if(pv): true" << endl;
        else    cout << "if(pv): false" << endl;
        cout << "operator bool(): " << (bool)pv << endl;

        // operator !() 호출
        if (!pv) cout << "if(!pv): true" << endl;
        else     cout << "if(!pv): false" << endl;
        cout << "operator !(): " << !pv << endl;

        pv.push_back(pa);
        disp_vector(pv);
        cout << "(pv? true: false) " << (pv? true: false) << endl;// operator bool() 호출
        pv.push_back(new Person("Chung", 2, 67.8, true,  nullptr));
        disp_vector(pv);

        // operator []
        cout << "pv[0]: "; pv[0]->println();
        cout << "delete pv[1];" << endl;
        delete pv[1];
        // pv[0]는 동적으로 할당받은 주소가 아니므로, 즉 배열 원소 pa[0]의 주소이므로 반납하지 않아도 됨
    }

===============================================================================
== [문제 2] 실행 결과
=============================================================================== 
+++++++++++++ Vector Operator Overload ++++++++++++++
+ 0.Exit 1.operator[] 2.operator! 3.CopyConstructor + ...
Menu item number? 2
count 0

if(pv): false
operator bool(): false
if(!pv): true
operator !(): true
count 1
[0] Hong  0 72.1 true ::

(pv? true: false) true
count 2
[0] Hong  0 72.1 true ::
[1] Chung 2 67.8 true ::

pv[0]: Hong  0 72.1 true ::
delete pv[1];


/******************************************************************************
 * [문제 3] 
 ******************************************************************************/
// VectorPerson 클래스에 아래 복사생성자를 구현하라.

    VectorPerson(const VectorPerson& vp);

// 구현 시 아래 아래 출력문을 삽입하고  
    cout << "VectorPerson::VectorPerson(const VectorPerson& vp)" << endl;
// vp의 멤버를 참고하여 현재 초기화되는 객체의 allocSize, count 값을 설정하라.
// allocSize만큼의 (Person*) 배열용 메모리를 할당하여 pVector에 저장한 후
// vp의 pVector[i]의 내용을 현재 초기화 되는 pVector[i]로 복사하라. (count 개수만큼만 복사)

//----------------------------------------------------------------------------
// 아래 함수를 VectorOperator 클래스에 추가하고 run() 함수에서 호출할 수 있도록 하라.
//----------------------------------------------------------------------------

    VectorPerson call_return_value(VectorPerson pv) {
        cout << "pv: "; disp_vector(pv);
        cout << "return pv1 " << endl;
        return pv1;
    }
    
    void copyConstructor() { // Memu item 3
        cout << "VectorPerson pv3 = pv2" << endl;
        VectorPerson pv3 = pv2;  // 묵시적 복사생성자 호출; VectorPerson pv3(pv2)와 동일
        cout << "pv3: "; disp_vector(pv3);
        pv3.erase(0);
        cout << "pv3.erase(0)" << endl;
        cout << "pv3: "; disp_vector(pv3);
        cout << "pv2: "; disp_vector(pv2);
        cout << "disp_vector(call_return_value(vp2))" << endl;
        // 아래 함수 호출에서 pv2 인자를 복사생성자를 이용하여 call_return_value()의 
        // 매개변수 pv에 복사하고 함수에서 리턴되는 pv1 또한 복사생성자를 통해 임시객체에 복사된다.
        // 그 후 disp_vector()를 호출하여 리턴된 임시객체를 보여줌
        disp_vector(call_return_value(pv2)); // 임시객체와 아래 pv1의 출력이 같아야 함
        cout << "pv1: "; disp_vector(pv1);
    }

===============================================================================
== [문제 3] 실행 결과
=============================================================================== 

+++++++++++++ Vector Operator Overload ++++++++++++++
+ 0.Exit 1.operator[] 2.operator! 3.CopyConstructor + ...
Menu item number? 3
VectorPerson pv3 = pv2
VectorPerson::VectorPerson(const VectorPerson& vp)
pv3: count 3
[0] Choon 3 56.7 true ::
[1] Soon  2 87.6 true ::
[2] Chung 4 67.8 true ::

pv3.erase(0)
pv3: count 2
[0] Soon  2 87.6 true ::
[1] Chung 4 67.8 true ::

pv2: count 3
[0] Choon 3 56.7 true ::
[1] Soon  2 87.6 true ::
[2] Chung 4 67.8 true ::

disp_vector(call_return_value(vp2))
VectorPerson::VectorPerson(const VectorPerson& vp) // 함수 호출 시 
pv: count 3
[0] Choon 3 56.7 true ::
[1] Soon  2 87.6 true ::
[2] Chung 4 67.8 true ::

return pv1 
VectorPerson::VectorPerson(const VectorPerson& vp) // 함수 리턴 시
count 2
[0] Hong  0 72.1 true ::
[1] Mong  1 65.4 true ::

pv1: count 2
[0] Hong  0 72.1 true ::
[1] Mong  1 65.4 true ::


/******************************************************************************
 * [문제 4] 
 ******************************************************************************/
// VectorPerson 클래스에 아래 대입 연산자 = 를 구현하라.

    VectorPerson& operator = (const VectorPerson& vp);

// 매개변수 vp의 count가 현재 객체의 allocSize보다 큰 경우 (같거나 작은 경우는 현재 메모리 재사용함)
//         기존 pVector 반납하고 
//         allocSize 값을 vp의 allocSize와 동일하게 수정한 후
//         allocSize만큼의 메모리를 새로 할당하여 pVector에 저장한 후 아래 메시지를 출력한다.
           cout << "VectorPerson::operator = : capacity extended to " << allocSize << endl;
// count 값 새로 수정하고 vp의 pVector[i]의 내용을 현재 객체의 pVector[i]로 복사하라.
// count 개수만큼만 복사한 후 현 객체의 참조를 리턴한다.
//----------------------------------------------------------------------------
// 아래 함수를 VectorOperator 클래스에 추가하고 run() 함수에서 호출할 수 있도록 하라.
//----------------------------------------------------------------------------

    void operatorAssign() { // Memu item 4
        cout << "VectorPerson pv3 = pv2" << endl;
        VectorPerson pv3 = pv2;
        cout << "pv3: "; disp_vector(pv3);
        cout << "pv3 = pv1" << endl;
        pv3 = pv1; // 대입 연산자
        cout << "pv3: "; disp_vector(pv3);
        cout << "repeat 9 times: pv3.push_back(pa+2)" << endl;
        for (int i = 0; i < 9; ++i) // 원소개수가 11개 이상이면 pv3 메모리가 확장되어야 함
            pv3.push_back(pa+2);
        cout << "pv3: "; disp_vector(pv3);
        VectorPerson pv4;
        cout << "pv4 = pv3" << endl;
        pv4 = pv3; // 대입 연산자: 원소개수가 11개 이상이면 pv4의 메모리가 확장되어야 함
        cout << "pv4: "; disp_vector(pv4);
    }

===============================================================================
== [문제 4] 실행 결과
=============================================================================== 

+++++++++++++ Vector Operator Overload ...
+ 4.operator= 5.operator+ 6.operator=+              + ...
Menu item number? 4
VectorPerson pv3 = pv2
VectorPerson::VectorPerson(const VectorPerson& vp)
pv3: count 3
[0] Choon 3 56.7 true ::
[1] Soon  2 87.6 true ::
[2] Chung 4 67.8 true ::

pv3 = pv1
pv3: count 2
[0] Hong  0 72.1 true ::
[1] Mong  1 65.4 true ::

repeat 9 times: pv3.push_back(pa+2)
VectorPerson: capacity extended to 20   // 배열이 확장되어야 함
pv3: count 11
[0] Hong  0 72.1 true ::
[1] Mong  1 65.4 true ::
[2] Choon 3 56.7 true ::
...
[10] Choon 3 56.7 true ::

pv4 = pv3
VectorPerson::operator = : capacity extended to 20   // 배열이 확장되어야 함
pv4: count 11
[0] Hong  0 72.1 true ::
[1] Mong  1 65.4 true ::
[2] Choon 3 56.7 true ::
...
[10] Choon 3 56.7 true ::


/******************************************************************************
 * [문제 5] 
 ******************************************************************************/
// VectorPerson 클래스에 아래 + 연산자를 구현하라.

    VectorPerson  operator + (const VectorPerson& vp);

// 구현 시 먼저 VectorPerson tmp(capacity); 객체를 선언하되 생성자의 매개변수인 
//  capacity는 현(this) 객체와 vp 객체의 count 값의 합으로 하라.
// 그러면 tmp 객체 내에 capacity 개수의 pVector[] 배열이 생성될 것이다.
//
// 그런 후 현 객체의 count개의 pVector[i]를 tmp의 pVector[i]에 저장하고 그 뒤에 추가적으로
// vp 객체의 vp.count개의 vp.pVector[i]를 tmp의 pVector[] 끝에 추가적으로 저장하라. 
// 즉, 두 객체의 pVector[i]를 tmp에 연속적으로 저장하라.
//
// 마지막으로 tmp의 count를 적절히 설정하고 tmp를 리턴한다.

//----------------------------------------------------------------------------
// 아래 함수를 VectorOperator 클래스에 추가하고 run() 함수에서 호출할 수 있도록 하라.
//----------------------------------------------------------------------------

    void operatorAdd() { // Memu item 5
        VectorPerson pv3;
        cout << "pv3 = pv1 + pv2" << endl;
        pv3 = pv1 + pv2;
        cout << "pv3: "; disp_vector(pv3);
        cout << "pv3 = pv2 + pv2 + pv3" << endl;
        pv3 = pv2 + pv2 + pv3; // + 연산자: pv3의 메모리가 확장
        cout << "pv3: "; disp_vector(pv3);
    }

===============================================================================
== [문제 5] 실행 결과
=============================================================================== 

+++++++++++++ Vector Operator Overload ...
+ 4.operator= 5.operator+ 6.operator=+              + ...
Menu item number? 5
pv3 = pv1 + pv2
pv3: count 5
[0] Hong  0 72.1 true ::
[1] Mong  1 65.4 true ::
[2] Choon 3 56.7 true ::
[3] Soon  2 87.6 true ::
[4] Chung 4 67.8 true ::

pv3 = pv2 + pv2 + pv3
VectorPerson::operator = : capacity extended to 11
pv3: count 11
[0] Choon 3 56.7 true ::
[1] Soon  2 87.6 true ::
[2] Chung 4 67.8 true ::
[3] Choon 3 56.7 true ::
[4] Soon  2 87.6 true ::
[5] Chung 4 67.8 true ::
[6] Hong  0 72.1 true ::
[7] Mong  1 65.4 true ::
[8] Choon 3 56.7 true ::
[9] Soon  2 87.6 true ::
[10] Chung 4 67.8 true ::


/******************************************************************************
 * [문제 6] 
 ******************************************************************************/
// 기존의 VectorPerson::extend_capacity()를 아래처럼 매개변수 capacity를 받는 함수로 수정하라.

    void extend_capacity(int capacity);

// 기존의 extend_capacity()는 allocSize *= 2 한 후 새로 allocSize만큼 메모리를 할당 받았다. 
// 이제는 allocSize = capacity 로 설정한 후 기존처럼 allocSize 크기의 새로운 배열을 할당받고 
// 기존 배열을 새 배열로 복사한 후(count만큼만) 기존 배열은 반납하라.
//----------------------------------------------------------------------------
// 기존의 extend_capacity()를 호출하던 곳을 찾아 기존과 동일하게 수행하도록 새로 수정된
// extend_capacity(/* TODO:할당할 배열 원소 개수 */)를 호출하도록 수정하라. 
// 호출 시 기존과 동일하게 수행하도록 적절한 매개변수 값을 넘겨 주어라.
//----------------------------------------------------------------------------
// VectorPerson 클래스에 아래 += 연산자를 구현하라. 이 연산자는 vp 객체의 pVector[] 
// 전체(vp.count까지)를 순서적으로 현(this) 객체의 pVector의 끝(count)에 추가하는 연산자 함수이다.

    VectorPerson& operator += (const VectorPerson& vp);

// 구현 시 먼저 현 객체와 vp의 count의 합이 allocSize보다 클 경우 extend_capacity()를 호출하여
// 배열 크기를 확장한다. 확장할 새로운 배열의 capacity는 기존 두 객체의 allocSize의 합으로 하라. 
// 현 객체의 count 값을 재 설정하고 현 객체의 참조를 리턴한다.
//----------------------------------------------------------------------------
// 아래 함수를 VectorOperator 클래스에 추가하고 run() 함수에서 호출할 수 있도록 하라.
//----------------------------------------------------------------------------

    void operatorAddAssign() { // Memu item 6
        cout << "VectorPerson pv4 = pv1: " << endl;
        VectorPerson pv4 = pv1;   // 묵시적 복사생성자 호출
        cout << "pv4: "; disp_vector(pv4);
        cout << "pv4 += pv2" << endl;
        pv4 += pv2; // += 연산자
        cout << "pv4: "; disp_vector(pv4);
        cout << "pv4 += pv2 + pv2" << endl;
        pv4 += pv2 + pv2;       // 원소개수가 11개 이상이면 메모리 확장해야 함
        cout << "pv4: "; disp_vector(pv4);
    }

===============================================================================
== [문제 6] 실행 결과
=============================================================================== 

+++++++++++++ Vector Operator Overload ...
+ 4.operator= 5.operator+ 6.operator=+              + ...
Menu item number? 4  // extend_capacity(int capacity)를 테스트하기 위해 실행함
...                  // 배열이 확장되는 것이 위 [문제 4] 실행 결과와 동일해야 함
...
Menu item number? 6
VectorPerson pv4 = pv1: 
VectorPerson::VectorPerson(const VectorPerson& vp)
pv4: count 2
[0] Hong  0 72.1 true ::
[1] Mong  1 65.4 true ::

pv4 += pv2
pv4: count 5
[0] Hong  0 72.1 true ::
[1] Mong  1 65.4 true ::
[2] Choon 3 56.7 true ::
[3] Soon  2 87.6 true ::
[4] Chung 4 67.8 true ::

pv4 += pv2 + pv2
VectorPerson: capacity extended to 16
pv4: count 11
[0] Hong  0 72.1 true ::
[1] Mong  1 65.4 true ::
[2] Choon 3 56.7 true ::
[3] Soon  2 87.6 true ::
[4] Chung 4 67.8 true ::
[5] Choon 3 56.7 true ::
[6] Soon  2 87.6 true ::
[7] Chung 4 67.8 true ::
[8] Choon 3 56.7 true ::
[9] Soon  2 87.6 true ::
[10] Chung 4 67.8 true ::


/******************************************************************************
 * 자동 오류 체크 모드로 프로그램 실행
 ******************************************************************************/
// 1. clc.chosun.ac.kr의 [강의자료실]에서 CH7_2 과제 테스트 파일을 다운받은 후 
//    압축 파일을 풀고 test 폴더를 드래깅하여 이클립스의 [Project Explorer]의 
//    [CH7_2] 프로젝트 위에 드랍한다. (test 폴더와 그 밑에 테스트용 파일이 있어야 함)
// 2. 기존 프로젝트 CH2의 src 폴드에 있는 check_error.h를 CH7_2 프로젝트의 
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
Good bye!!

===============================================================================
== 2. 비정상적인 경우의 프로그램 실행방법은 clc 강의자료실의 [자동 오류 체크 부분의 설명만 따로 발췌]
==    부분을 참조하기 바란다.  
=============================================================================== 

/******************************************************************************
 * 프로그램 제출
 ******************************************************************************/
// 1. 중요: 소스 파일 맨 앞쪽에 있는 AUTOMATIC_ERROR_CHECK 상수 값을 false로 설정하라.
// 2. 프로그램을 oj.chosun.ac.kr에 제출하라. 
//-----------------------------------------------------------------------------
```