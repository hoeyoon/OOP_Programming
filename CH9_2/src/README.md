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