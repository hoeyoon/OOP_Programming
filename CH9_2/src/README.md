# OJ Ch9_2

### 이번 문제의 목적: 추상 클래스
```
추상 클래스를 만들어 본다. 
추상 클래스를 파생 클래스에서 상속한 후 추상 클래스의 순수 가상 함수들을 구현하여 오버라이딩한다. 
추상 클래스의 포인터 변수를 사용하여 동일한 기능을 제공하는 다른 파생 클래스의 객체를 제어한다.
여기서는 추상 클래스인 SmartPhone을 상속한 GalaxyPhone과 IPhone 클래스 두 버전을 구현한다.
그런 후 이들 두 클래스의 객체를 생성한 후 SmartPhone 포인터로 이들 객체들을 통합하여 관리한다.
----------------------------------------------------------------------------

    (추상클래스)Calculator Phone(추상클래스) -----> BaseStation(추상클래스)
                  \      /                       |
                 SmartPhone(추상클래스)<--     PersonManager ------ persons[...]
                  /      \            |                                :
           GalaxyPhone  IPhone        ---------------------------------:

```
### 코드 추가 및 변경 1
```
Person, Student, Worker, StudentWorker 클래스의 생성자, 복사 생성자, 소멸자 내에서
더 이상 어떤 출력도 되지 않도록 출력 문장들을 모두 주석 처리하라. 
예를들어, Student 생성자에서는 아래 세 문장을 모두 주석 처리하여 아무것도 출력되지 않게 한다. 
```
```c++
    cout << "Student::Student(...):"; printMembers(cout); cout << endl;

```

### 코드 추가 및 변경 2
```
UI 클래스 내의 아래 두 함수의 리턴 데이타 타입이 static const string&으로
되어 있다면 아래처럼 static string&로 수정하라.
```
```c++
	static string& getNext(const string& msg);
	static string& getNextLine(const string& msg);
```

### 문제 1 설명
```
typeid()와 == 연산자 활용
아래 실행 결과를 참고하여 PersonManager에서 사용자로부터 새로운 인적정보를 입력 받아 
새 객체를 생성한 후 PersonManager에서 관리하는 persons 객체들 중 새 객체와 동일한 
종류(학생)의 객체들 중에서 == 연산자를 이용하여 같은 객체를 찾아 출력하라. 이를 위해 먼저 
```
```
1) PersonManager에 아래 멤버 함수 선언을 run() 앞에 추가하고 
    void find();         // ch9_2 추가
---------------------------------------------------------------------------
2) PersonManager::run()의 menuStr에 아래 문자열을 추가하고, 
   또한 func_arr[]에 위 find() 함수를 등록하라.
---------------------------------------------------------------------------
        "= 9.Find(9_2) 10.DispAlbaStud(9_2) 11.DispPhones(9_2)           =\n"
---------------------------------------------------------------------------
3) 구현 영역에서 find() 함수 구현 시 아래 코드를 활용하고 설명된 부분을 구현하라.
---------------------------------------------------------------------------
```
```c++
void PersonManager::find() { // Menu item 9
    printNotice("Input", "to find by operator ==");

    Person* p = 새 객체를 동적으로 생성한 후 인적정보를 입력받고 p에 대입 [insert() 참고]
    인적정보가 잘못 입력되었으면 여기서 리턴 [insert() 함수 참고]

    bool found = false;

    for 문을 이용하여 persons 벡터의 모든 객체 포인터 persons[i]에 대해
        if (persons[i]가 p가 포인터하는 객체와 동일한 종류의 객체이고, (아래 설명 참고)
            == 연산자를 이용하여 p 객체와 비교하여 같으면)  
            cout << "[" << i << "] "; persons[i]->println();
            found를 true로 설정

    위 for에서 동일한 객체를 하나도 찾지 못했으면 아래와 같이 출력
        cout << "NOT found by operator ==";
}
```
```
참고: persons 벡터 내에는 Person, Student, Worker, StudentWorker 등의 다양한 
    종류의 객체들을 관리하고 있으므로 사용자가 입력한 객체와 동일한 종류의 객체하고만 비교해야 한다.
    따라서 두 객체 변수 a, b가 동일한 종류의 객체인지는 typeid(a) == typeid(b)와 같이
    typeid() 키워드를 사용하여 비교하면 된다. 단, typeid()의 인자는 [객체] 또는 [클래스이름]
    이어야 함. 만약 객체 포인터 p가 있다면 typeid(*p)로 인자를 주어야 한다. 
    typeid()를 사용하기 위해서는 아래 파일을 include 해야 함.
    < > 사이의 공백은 제거하라. oj에서 HTML tag로 인식되는 오류를 피하기 위함임. 

#include < typeinfo >   // ch9_2 추가: for typeid(*p)
```

### 문제 1 실행 결과
```
====================== Person Management Menu ===================
= 0.Exit 1.Display 2.Append 3.Clear 4.Login(CurrentUser, ch9)   =
= 5.Insert(6_2) 6.Delete(6_2) 7.CopyPersons(7_2) 8.Reset(7_2)   =
= 9.Find(9_2) 10.DispAlbaStud(9_2) 11.DispPhones(9_2)           =
=================================================================
Menu item number? 2
The number of persons to append? 2 // 테스트를 위해 2명의 학생 정보을 추가함 
Input 2 [delimiter(P, S, W, or A)] [person information] :
// 아래 2명의 인적 정보를 복사해서 입력하라.
S s1 1 67.4 true :Seoul: Physics 3.3 1
S s1 1 77.4 false :Jongno-gu: Physics 3.5 1
display(): count 10
...
[1] p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
[2] s1 1 65.4 true :Jongno-gu Seoul: Physics 3.8 1
[3] s2 2 54.3 false :Yeonje-gu Busan: Electronics 2.5 4
...
[7] a2 6 66.6 false :Sasang-gu Sejong: History 3.1 1 Kia CEO :Seven Eveven,eMart Jinju,CU Bongsun: true
[8] s1 1 67.4 true :Seoul: Physics 3.3 1
[9] s1 1 77.4 false :Jongno-gu: Physics 3.5 1
...
Menu item number? 9   // Find
Input [delimiter(P, S, W, or A)] [person information] to find by operator ==
S s1 1 0 false :: Physics 0 1   // 학생 인적 정보: 사용자 입력
//
// 기존의 학생 객체들 중 == 연산자를 이용해 위와 동일한 객체들을 모두 찾아 출력
// 학생의 경우 == 연산자는 이름, id, 학과, 학년이 같으면 같은 객체임
//
[2] s1 1 65.4 true :Jongno-gu Seoul: Physics 3.8 1
[8] s1 1 67.4 true :Seoul: Physics 3.3 1
[9] s1 1 77.4 false :Jongno-gu: Physics 3.5 1
...
Menu item number? 9   // Find
Input [delimiter(P, S, W, or A)] [person information] to find by operator ==
S s1 1 0 false :: Physics 0 2
NOT found by operator ==
```

### 문제 2 설명
```
[문제 1]에서 사용한 typeid()를 이용해 PersonManager::persons 벡터에서 관리되는 객체들 중
StudentWorker 클래스 객체들만 찾아서 객체의 정보를 출력하라. 아래 프로그램 실행 결과 참고할 것.
이를 위해 PersonManager에 아래 함수를 추가하고 run() 함수 내의 func_arr[]에 아래 함수를 
등록하라. 그리고 함수 코드를 완성하라.
```
```c++
void PersonManager::dispStudentWorkers() { // Menu item 10
    cout << "dispStudentWorkers(): " << endl;
    for문을 이용하여 persons 벡터의 각 객체 포인터 persons[i]에 대해 
        persons[i]가 StudentWorker 클래스 객체이면 아래처럼 출력. 
        (참고로 typeid(...)의 인자(...)는 [객체] 또는 [클래스이름]이어야 함. 
         인자가 포인터면 인자 앞에 *를 붙여야만 함) 
            cout << "[" << i << "] "; persons[i]->println();
}
```

### 문제 2 실행 결과
```
====================== Person Management Menu ...
Menu item number? 2   // Append
The number of persons to append? 2 // 알바생 2명의 인적 정보를 추가함
Input 2 [delimiter(P, S, W, or A)] [person information] :     
// 아래 2명의 인적 정보를 복사해서 입력하라.
A a3 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
A a4 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
display(): count 10
[0] p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
...
[5] w2 4 44.4 true :Dobong-gu Kwangju: Hyundai Manager
[6] a1 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
[7] a2 6 66.6 false :Sasang-gu Sejong: History 3.1 1 Kia CEO :Seven Eveven,eMart Jinju,CU Bongsun: true
[8] a3 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
[9] a4 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false

====================== Person Management Menu ...
Menu item number? 10   // DispAlbaStud
dispStudentWorkers(): 
[6] a1 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
[7] a2 6 66.6 false :Sasang-gu Sejong: History 3.1 1 Kia CEO :Seven Eveven,eMart Jinju,CU Bongsun: true
[8] a3 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
[9] a4 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false

// 위 Person Management Menu에서 연속하여 아래 메뉴 항목을 계속 입력하라. 
// 인덱스 번호 6을 가진 원소를 연속적으로 3번 삭제함
6   // Delete
6   // Index to delete?
6   // Delete
6   // Index to delete?
6   // Delete
6   // Index to delete?
...
Menu item number? 10   // DispAlbaStud
dispStudentWorkers(): 
[6] a4 5 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
```