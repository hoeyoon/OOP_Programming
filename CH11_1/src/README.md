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