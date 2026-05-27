# OJ CH10_1
### 이번 문제의 목적
```
VectorPerson 클래스를 템플릿 클래스 Vector< T >로 변경한다.
PMbyVector 클래스를 추가하여 Vector< T >를 테스트한다.
```

### 문제 1 설명
```
1) MainMenu의 문자열에서 일부분을 아래 문자열로 교체하라.
```
```
* 0.Exit 1.PersonManager(ch3_2, 4, 6, 7_2, 8, 9, 10)                      *
```
```
2) 기존의 MultiManager를 아래 내용으로 교체하라.
    각 배열을 static으로 변경하고 배열 원소를 더 추가하였다. 배열 선언과 초기화를 주지하라.
    참고로 static 변수의 초기 값 설정은 클래스 외부에서 정의해 주어야 한다.
```
```c++
class MultiManager
{
    static Person persons[];
    static Student students[];
    static Worker workers[];
    static StudentWorker albas[];

public:
    static const int allPersonCount;
    static Person* allPersons[];
    PersonManager personMng { allPersons, allPersonCount };

    void run() {
        //cout << "PersonManager::run() starts" << endl;
        personMng.run();
        //cout << "PersonManager::run() returned" << endl;
    }
}; // ch3_2, 4_1, 4_2, ch8_2: MultiManager class

Person MultiManager::persons[5] = {
    Person("p0", 10, 70.0, false, "Gwangju Nam-gu Bongseon-dong 21"),
    Person("p1", 11, 61.1, true,  "Jong-ro 1-gil, Jongno-gu, Seoul"),
    Person("p2", 12, 52.2, false, "1001, Jungang-daero, Yeonje-gu, Busan"),
    Person("p3", 13, 83.3, true,  "100 Dunsan-ro Seo-gu Daejeon"),
    Person("p4", 14, 64.4, false, "88 Gongpyeong-ro, Jung-gu, Daegu"),
};

Student MultiManager::students[4] = {
    Student("s1", 21, 65.4, true,  "Jongno-gu Seoul", "Physics", 3.8, 1),
    Student("s2", 22, 54.3, false, "Yeonje-gu Busan", "Electronics", 2.5, 4),
    Student("s3", 23, 55.5, true,  "Dong-gu Incheon", "Computer", 3.5, 2),
    Student("s4", 24, 66.6, false, "Sasang-gu Sejong","History", 3.1, 1),
};

Worker MultiManager::workers[4] = {
    Worker("w1", 31, 33.3, false, "Kangnam-gu Seoul",  "Samsung", "Director"),
    Worker("w2", 32, 44.4, true,  "Dobong-gu Kwangju", "Hyundai", "Manager"),
    Worker("w3", 33, 55.5, true,  "Dong-gu Incheon",   "Hyundai", "Labor"),
    Worker("w4", 34, 66.6, false, "Sasang-gu Sejong",  "Kia", "CEO"),
};

StudentWorker MultiManager::albas[4] = {
    StudentWorker("a1", 41, 55.5, true, "Dong-gu Incheon",
                  "Computer", 3.5, 2, "Hyundai", "Labor",
                  "CU KangNam,Seven Eleven,GSStore Suwon", false),
    StudentWorker("a2", 42, 66.6, false, "Sasang-gu Sejong",
                  "History", 3.1, 1, "Kia", "CEO",
                  "Seven Eveven,eMart Jinju,CU Bongsun", true),
    StudentWorker("a3", 43, 51.9, false, "Buk-gu Daejeon",
                  "Computer", 3.5, 2, "Samsung", "Manager",
                  "Youngpung,Kyobo Gwanghwa,E-mart Suwon", true),
    StudentWorker("a4", 44, 66.6, true, "Nam-gu Busan",
                  "History", 3.1, 1, "LG", "DepartmentHead",
                  "CU, FamilyMart, LotteMart, HomePlus", false),
};

const int MultiManager::allPersonCount = 16;
Person* MultiManager::allPersons[allPersonCount] = {
        &persons[0],  &persons[1],  &persons[2],  &persons[3],
        &students[0], &students[1], &students[2], &students[3],
        &workers[0],  &workers[1],  &workers[2],  &workers[3],
        &albas[0],    &albas[1],    &albas[2],    &albas[3],
};
```
```
3) MultiManager::run() 함수 내의 두 개의 출력문을 아래처럼 모두 주석 처리하라.
```
```c++
class MultiManager
{
    ...
    void run() {
        //cout << "PersonManager::run() starts" << endl;
        personMng.run();
        //cout << "PersonManager::run() returned" << endl;
    }
};
```

### 문제 1 실행 결과
```
******************************* Main Menu *********************************
* 0.Exit 1.PersonManager(ch3_2, 4, 6, 7_2, 8, 9, 10)                      *
* 2.Class:Object(ch3_1) 3.CopyConstructor(ch5_1) 4.AllocatedMember(ch5_2) *
* 5.OperatorOverload(ch7_1) 6.Inheritance(ch8) 7.PMbyVector               *
***************************************************************************
Menu item number? 1

====================== Person Management Menu ===================
= 0.Exit 1.Display 2.Append 3.Clear 4.Login(CurrentUser, ch9)   =
= 5.Insert(6_2) 6.Delete(6_2) 7.CopyPersons(7_3) 8.Reset(7_3)   =
= 9.Find(9_2) 10.DispAlbaStud(9_2) 11.DispPhones(9_2)           =
=================================================================
Menu item number? 1
display(): count 16
[0] p0 10 70 false :Gwangju Nam-gu Bongseon-dong 21:
[1] p1 11 61.1 true :Jong-ro 1-gil, Jongno-gu, Seoul:
[2] p2 12 52.2 false :1001, Jungang-daero, Yeonje-gu, Busan:
[3] p3 13 83.3 true :100 Dunsan-ro Seo-gu Daejeon:
[4] s1 21 65.4 true :Jongno-gu Seoul: Physics 3.8 1
[5] s2 22 54.3 false :Yeonje-gu Busan: Electronics 2.5 4
[6] s3 23 55.5 true :Dong-gu Incheon: Computer 3.5 2
[7] s4 24 66.6 false :Sasang-gu Sejong: History 3.1 1
[8] w1 31 33.3 false :Kangnam-gu Seoul: Samsung Director
[9] w2 32 44.4 true :Dobong-gu Kwangju: Hyundai Manager
[10] w3 33 55.5 true :Dong-gu Incheon: Hyundai Labor
[11] w4 34 66.6 false :Sasang-gu Sejong: Kia CEO
[12] a1 41 55.5 true :Dong-gu Incheon: Computer 3.5 2 Hyundai Labor :CU KangNam,Seven Eleven,GSStore Suwon: false
[13] a2 42 66.6 false :Sasang-gu Sejong: History 3.1 1 Kia CEO :Seven Eveven,eMart Jinju,CU Bongsun: true
[14] a3 43 51.9 false :Buk-gu Daejeon: Computer 3.5 2 Samsung Manager :Youngpung,Kyobo Gwanghwa,E-mart Suwon: true
[15] a4 44 66.6 true :Nam-gu Busan: History 3.1 1 LG DepartmentHead :CU, FamilyMart, LotteMart, HomePlus: false
```

### 문제 2 설명
```
지금까지 VectorPerson에 삽입하고, 저장하고, 빼내는 원소의 데이타 타입은 Person* 였다.
다시 말하지만 Person의 객체가 아니고 포인터를 pVector[]에 저장했다.
이제 VectorPerson을 Person, Student, Worker, StudWorker 등의 
다양한 종류의 객체 또는 포인터를 저장할 수 있는 템플릿 클래스로 만들어 보자. 
---------------------------------------------------------------------------
기존 VectorPerson 클래스를 템플릿 클래스 Vector< T >로 변환해 보자.
주의: 아래 각 항목을 실수없이 차근차근 수행하기 바란다.
---------------------------------------------------------------------------
1) class VectorPerson의 [선언부] 및 [멤버 함수 구현부]에서 VectorPerson 단어들을 
    모두 Vector로 수정하라. (이 외의 다른 곳은 아직 수정하지 마라.)
---------------------------------------------------------------------------
2)  아래 한 행 전체를 
template < typename T >
    클래스 외부에서 구현한 모든 멤버 함수 앞 줄에 추가하고, class Vector { 앞 줄에도 추가하라. 
    단, 클래스 [내부]에 있는 멤버 함수 앞에는 추가하지 마라.
---------------------------------------------------------------------------
3) 클래스 [외부]에서 구현한 모든 멤버 함수에 대해 아래를 수행하라. (클래스 [내부] 함수들은 제외)
    i) 외부에 구현된 멤버 함수들(operator 연산자 포함)의 이름 앞에 있는 
        Vector:: 을 Vector< T >:: 로 변경하라. 
    ii) 외부에 구현된 operator =, operator +=, operator + 연산자 함수의 
        [리턴 타입], [매개변수 타입], [지역 변수 타입]이 Vector 이면 Vector< T > 로 변경하고,
        Vector& 이면 Vector< T >& 로 변경하라.
---------------------------------------------------------------------------
 4) 지금까지 Vector에 삽입하고, 저장하고, 빼내는 원소의 데이타 타입은 Person* 였다.
    이제 변수 선언 시 Person* 를 임의의 데이타 타입(타입 매개변수) T 로 변경하자. 
    즉, Vector 클래스의 [선언부]와 [구현부]에서 Person* 를 모두 T 로 변경하고, 
    Person** 를 T* 로 변경하라.
    즉, Person **pVector 선언, at()와 operator [] 함수의 리턴 데이타 타입 등이다.
    이렇게 하면 Vector< Person* > 또는 Vector< Person >로 선언하여 
    Person 포인터 뿐만 아니라 Person 객체도 벡터 내에 저장할 수 있게 된다.
---------------------------------------------------------------------------
5) PersonManager 클래스 내의 멤버 변수 VectorPerson persons; 를 
    Vector< Person* > persons; 로 변경하라. 즉, Vector 클래스에 
    삽입하고, 저장하고, 빼내는 원소의 데이타 타입은 여전히 Person* 로 하겠다는 것이다.
---------------------------------------------------------------------------
6) VectorOperator 클래스 내에서 사용된 모든 VectorPerson 단어를 Vector< Person* > 
    로 변경하라. 출력 문장 내의 "VectorPerson ..." 단어도 마찬가지로 수정하라.
```

### 문제 2 실행 결과
```
// 컴파일 했을 경우 정상적으로 컴파일되어야 하며 
// 아래 메뉴항목을 순서적으로 실행했을 때 모두 정상 실행되어야 한다. (죽지 않고 실행된다면 OK)

******************************* Main Menu *...
* 5.OperatorOverload(ch7_1) 6.Inheritance(ch8)                            *
***************************************************************************
5   // OperatorOverload
9   // VectorOOL
1   // operator[]
1   // Display
0   // Exit
2   // operator!
3   // CopyConstructor
4   // operator=
5   // operator+
6   // operator=+
0   // Exit
0   // Exit
0   // Exit
```