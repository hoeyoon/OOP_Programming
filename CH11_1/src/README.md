# OJ CH11_1

### 코드 추가 및 변경 1
```
1) MainMenu 문자열의 일부분을 아래 문자열로 교체하라.

* 0.Exit 1.PersonManager(ch3_2, 4, 6, 7_2, 8, 9, 10, 11)                      *
```

### 문제 1 설명
```
SmartPhone의 출력 연산자 << 구현

지금까지 PersonManager::dispPhones()에서 아래 문장을 이용하여 스마트폰 객체를 출력하였다.
        cout << "[" << i << "] "; persons[i]->getSmartPhone()->println();
---------------------------------------------------------------------------
1) 이 문장을 아래 문장처럼 수정하라. 이는 출력 연산자 << 를 이용하여 스마트폰 객체가 출력되게 변경한 것이다.
        cout << "[" << i << "] " << *(persons[i]->getSmartPhone()) << endl;
---------------------------------------------------------------------------
    이것이 가능하도록 SmartPhone의 출력 연산자 << 를 구현하고, 
    이 함수를  SmartPhone과 GalaxyPhone 클래스 사이에 배치하라. 
    이 연산자 구현 시 SmartPhone::println()처럼 SmartPhone::print() 
    멤버함수를 호출하면 간단히 구현할 수 있다. 이 연산자 함수의 SmartPhone 매개변수는 
    참조 변수(call by reference)로 선언하라.
---------------------------------------------------------------------------
2) CurrentUser::display() 함수에서 rUser를 출력하는 문장 뒤쪽에
    SmartPhone의 출력 연산자 << 를 이용하여 rUser의 스마트폰 객체을 출력하는 문장을 추가하라.
```

### 문제 1 실행 결과
```
******************************* Main Menu *********************************
* 0.Exit 1.PersonManager(ch3_2, 4, 6, 7_2, 8, 9, 10, 11)                  *
* 2.Class:Object(ch3_1) 3.CopyConstructor(ch5_1) 4.AllocatedMember(ch5_2) *
* 5.OperatorOverload(ch7_1) 6.Inheritance(ch8) 7.PMbyVector               *
***************************************************************************
// 아래 메뉴 항목을 연속으로 실행하라.
1    // PersonManager
11   // DispPhones
dispPhones(): count 16
[0] p0's Phone: Apple IPhone 13
[1] p1's Phone: SAMSUNG Galaxy
...
[14] a3's Phone: SAMSUNG Galaxy
[15] a4's Phone: Apple IPhone 13

4    // Login
a1
     // 빈줄 삽입
1    // Display
a1 41 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
a1's Phone: SAMSUNG Galaxy
0    // Logout

4    // Login
s2
     // 빈줄 삽입
1    // Display
s2 22 54.3 false :Yeonje-gu Busan: Electronics 2.5 4
s2's Phone: Apple IPhone 13
``` 

### 문제 2 설명
```
Person의 출력 연산자 << 구현

지금까지 BasePM::display()에서 아래 문장을 이용하여 각 사람 객체을 출력하였다.
        cout << "[" << i << "] "; persons[i]->println();
---------------------------------------------------------------------------
1) 이 문장을 아래 문장처럼 수정하라. 
    이는 출력 연산자 << 를 이용하여 사람 객체가 출력되게 변경한 것이다.
    만약 Person p; Person& rp;로 선언되었다면 그냥 p와 rp를 바로 출력하면 되고,
        Person *p; 로 선언되었다면 *p로 출력해야 한다.
        cout << "[" << i << "] " << *(persons[i]) << endl;
---------------------------------------------------------------------------
    이것이 가능하도록 출력 연산자 << 를 구현하여 Person과 Student 클래스 사이에 배치하라.
    이 연산자 구현 시 Person::println()처럼 기존 Person::print() 멤버함수를 호출하면 
    간단히 구현할 수 있다.
    이 연산자 함수의 Person 매개변수는 참조 변수(call by reference)로 선언하라.
---------------------------------------------------------------------------
2) CurrentUser의 display(), setter(), set(), isSame() 함수 내에서 
    Person::println() 대신 위 1)처럼 << 와 endl를 사용하여 출력하도록 수정하라.
3) Factory::inputPerson(), 
    PersonManager의 find(), dispStudentWorkers(),
    그리고 UI::inputPerson()도 Person::println() 대신 
    위 1)처럼 << 와 endl를 사용하여 출력하도록 수정하라.
```

### 문제 2 실행 결과
```
1    // PersonManager
1    // Display
display(): count 16
[0] p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
...
[15] a4 44 66.6 true :Nam-gu Busan: History 3.1 1 LG DepartmentHead :CU, FamilyMart, LotteMart, HomePlus: false

9    // Find
Input [delimiter(P, S, W, or A)] [person information] to find by operator ==
S s4 24 66.6 false :Sasang-gu Sejong: History 3.1 1
[7] s4 24 66.6 false :Sasang-gu Sejong: History 3.1 1

10    // DispAlbaStud
dispStudentWorkers(): 
[12] a1 41 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
[13] a2 42 66.6 false :Sasang-gu Sejong: History 3.1 1 Kia CEO :Seven Eveven,eMart Jinju,CU Bongsun: true
[14] a3 43 51.9 false :Buk-gu Daejeon: Computer 3.5 2 Samsung Manager :Youngpung,Kyobo Gwanghwa,E-mart Suwon: true
[15] a4 44 66.6 true :Nam-gu Busan: History 3.1 1 LG DepartmentHead :CU, FamilyMart, LotteMart, HomePlus: false

2    //  Append
The number of persons to append? 1
W w5 35 77.7 true :Eunpyeong-gu Seoul: Ssangyong Vice-president
display(): count 17
[0] p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
...
[16] w5 35 77.7 true :Eunpyeong-gu Seoul: Ssangyong Vice-president

4    // Login
w2
     // 빈줄 삽입
1    // Display
w2 32 44.4 true :Dobong-gu Kwangju: Hyundai Manager
w2's Phone: Apple IPhone 13

3    // Setter
rp.setMembers():rp 32 44.4 true :Dobong-gu Kwangju:

4    // Set
rp.set():rp 32 44.4 false :Dobong-gu Kwangju:

6    // IsSame
rUser: w2 32 44.4 true :Dobong-gu Kwangju: Hyundai Manager
p    : w2 32 44.4 true :Dobong-gu Kwangju: Hyundai Manager
(rUser == p): true
input person information:
w2 32 0 false :: Hyundai Manager // 사용자 입력
rUser: w2 32 44.4 true :Dobong-gu Kwangju: Hyundai Manager
p    : w2 32 0 false :: Hyundai Manager
(rUser == p): true
```

### 문제 3 설명
```
Person의 입력 연산자 >> 구현

지금까지 UI::inputPerson(Person& p)에서 아래 문장을 이용하여 각 사람의 인적 정보를 입력하였다.
    p.input(cin);
---------------------------------------------------------------------------
1) 이 문장을 아래 문장처럼 수정하라. 이는 입력 연산자 >> 를 이용하여 인적정보를 입력받게 변경한 것이다.
    cin >> p;
---------------------------------------------------------------------------
    이것이 가능하도록 Person의 입력 연산자 >> 를 구현하고 Person과 Student 클래스 사이에 배치하라.
    이 연산자 구현 시 기존 Person::input() 을 호출하면 간단히 구현할 수 있다. 
    이 연산자 함수의 Person 매개변수는 참조 변수(call by reference)로 선언하라.
---------------------------------------------------------------------------
2) Factory::inputPerson(istream& in)에서 p->input(in) 대신
    위 1)처럼 in과 >> 연산자를 이용하여 입력하도록 수정하라.
    주의) 위 1)은 cin이고, p는 참조자이고 
         여기서는  in이고, p는 포인터 변수임을 유의하라.
```

### 문제 3 실행 결과
```
1    // PersonManager
2    // Append: Factory::inputPerson(istream& in) 호출
The number of persons to append? 1
Input 1 [delimiter(P, S, W, or A)] [person information] :
W w5 35 77.7 true :Eunpyeong-gu Seoul: Ssangyong Vice-president
display(): count 17
[0] p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
...
[16] w5 35 77.7 true :Eunpyeong-gu Seoul: Ssangyong Vice-president

4    // Login
w2
     // 빈줄 삽입
6    // IsSame
rUser: w2 32 44.4 true :Dobong-gu Kwangju: Hyundai Manager
p    : w2 32 44.4 true :Dobong-gu Kwangju: Hyundai Manager
(rUser == p): true
input person information:
// 아래는 사용자 입력: 현재 사용자가 w2(Worker)이고 UI::inputPerson(*p)에서
//                Worker::input()이 호출되므로 사람 구분자 입력하지 않아도 됨
w2 32 0 false :: Hyundai Manager
rUser: w2 32 44.4 true :Dobong-gu Kwangju: Hyundai Manager
p    : w2 32 0 false :: Hyundai Manager
(rUser == p): true
```

### 문제 4 설명
```
매개변수가 없는 출력 조작자(manipulator) 구현 및 활용

지금까지 Memo::displayMemo()의 맨 마지막에 아래 문장을 이용하여 메모 출력을 마무리하였다.
    cout << "--------------------" << endl;
---------------------------------------------------------------------------
1) 이 문장을 아래 문장처럼 매개변수가 없는 출력 조작자 drawDashLine을 사용하도록 수정하라. 
    cout << drawDashLine;
---------------------------------------------------------------------------
    이것이 가능하도록 출력 조작자 drawDashLine을 구현하라.
    구현된 코드는 아래처럼 StudentWorker와 UI 클래스 사이에 아래처럼 배치하라.
```
```c++
/*****************************************************************************
 * ch11_1: I/O Manipulator
 *****************************************************************************/

// 모든 입출력 조작자는 여기에 배치하라.

drawDashLine 조작자 구현
```
```
2) Memo::dispByLine() 함수 내에서도 위 1)처럼 출력 조작자 drawDashLine을 사용하여
    출력하도록 수정하라.
```

### 문제 4 실행 결과
```
1    // PersonManager
4    // Login
a1
     // 빈줄 삽입
9    // ManageMemo
1    // DisplayMemo
------- Memo -------
The Last of the Mohicans
...
than the native warrior of North America.
--------------------

4    // DispByLine
--- Memo by line ---
[0] The Last of the Mohicans
...
[10] than the native warrior of North America.
--------------------
```

### 문제 5 설명
```
매개변수가 있는 입력 조작자(manipulator) 구현 및 활용

지금까지 UI::getNext(const string& msg)에서 
사용자에게 질문하는 메시지인 msg를 cout을 통해 출력하고, 사용자가 입력한 
단어를 cin을 통해 입력 받기 위해 아래 두 문장을 이용하였다.
    cout << msg;
    cin >> line;
---------------------------------------------------------------------------
1) 이 문장을 아래처럼 하나의 cin 문장으로 수정하라. 
---------------------------------------------------------------------------
    cin >> question(msg) >> line;
---------------------------------------------------------------------------
이는 기존 cout을 사용하지 않고 매개변수가 있는 입력 조작자 question(msg)을 사용하여 
질문 메시지인 msg를 출력한다. (여기서 cout을 사용하지는 않는다.)
---------------------------------------------------------------------------
이 입력 조작자 question(msg)은 아래 코드와 같이 구현된다. 
아래 question 클래스와 입력 연산자 >>를 UI 클래스와 StudentWorker 클래스 사이에 배치하라.
```
```c++
class question { // 매개변수가 있는 조작자를 만들기 위한 클래스
    const string& msg;
public:
    question(const string& msg): msg{msg} { } // 생성자
    friend istream& operator >> (istream& in, const question& qst);
};

// question 클래스의 입력 연산자: 단순히 question 객체에 저장된 msg를 출력해주는 역할을 한다. 
istream& operator >> (istream& in, const question& qst) {
    cout << qst.msg;
    return in;
}
```
```
위 question은 사실 클래스 이름이며, 
cin >> question(msg) >> line; 문장 실행 시 question(msg)을 통해
이 클래스의 이름 없는 임시 객체가 생성된다.
이때 인자 msg는 생성자 question(const string& msg)에게 매개변수로 넘겨지며 
이 값은 question 클래스의 멤버 변수인 msg에 저장된다. 
임시 객체인 question(msg)의 참조자가 위 입력 연산자 operator >> (in, qst)의 
두번째 매개변수 qst로 전달된다.
---------------------------------------------------------------------------
위 입력 연산자 operator >> (istream& in, const question& qst)는 
매개변수 qst로 question 객체의 참조자를 받는다. 
이 연산자는 qst 객체의 msg 멤버를 cout을 통해 cout << qst.msg 처럼 출력한다. 
여기서 question 클래스의 private 멤버인 qst.msg에 접근할 수 있도록 하기 위해 
이 연산자 함수 >>() 를 question 내에서 friend로 선언해야 한다.
---------------------------------------------------------------------------
2) UI의 getNextLine(), getInt() 함수 내에서도 
    cout << msg 대신 위 1)처럼 매개변수가 있는 입력 조작자 question(msg)을 사용하여 
    msg를 출력하도록 관련 코드를 수정하라.
3) UI의 inputPerson(Person& p) 함수 내에서 
---------------------------------------------------------------------------
    cout << "input person information:" << endl;
    cin >> p;
---------------------------------------------------------------------------
위 두 문장 대신 위 1)처럼 매개변수가 있는 입력 조작자 question(string& msg) 를 사용하여 
출력하도록 관련 코드를 수정하라. 위 << endl 대신 "input person information:\n"을 
question(string& msg)의 msg로 넘겨주면 동일한 효과를 볼 수 있다.
```

### 문제 5 실행 결과
```
1    // PersonManager
1    // Display
Menu item number? 4   // Login: UI::selectMenu() -> getIndex() -> getInt(msg)
user name: p0         // UI::getNext()
password:             // 그냥 엔터; UI::getNextLine()
9    // ManageMemo
1    // DisplayMemo
------- Memo -------
The Last of the Mohicans
...
than the native warrior of North America.
--------------------

6    // RepaceLine
Line number to replace? 0     // UI::getPositiveInt() -> getInt(msg)
Input a line to replace:      // UI::getNextLine()
This is the first line.
--- Memo by line ---
[0] This is the first line.
[1] James Fenimore Cooper
...
[10] than the native warrior of North America.
--------------------

0    // Exit
6    // IsSame
rUser: p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
p    : p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
(rUser == p): true
input person information:     // UI::inputPerson(Person& p)
p0 11 70 false :Gwangju Nam-gu Bongseon-dong 21:
rUser: p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
p    : p0 11 70 false :Gwangju Nam-gu Bongseon-dong 21:
(rUser == p): false
```