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