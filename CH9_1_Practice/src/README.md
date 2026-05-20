# OJ CH9_1_Practice
```
※ 이번 실습은 9장에 대한 라이브 코딩 연습이다.
※ 아래 문제는 가상함수와 가상함수의 overriding 개념을 이해했는지를 확인함.
******************************************************************************

여기서 다루고자 하는 각 클래스의 계층적 구조는 다음과 같다. 
Student와 Employee는 Person을 상속받는다.

                      Person
                        |
            --------------------------
            |                        |
         Student                 Employee

먼저 기존 "8장 실습문제"에서 작성한 소스코드를 복사하여 9장 소스 파일에 삽입하라.
```

### 문제 1 설명
```
print() 멤버함수
1) string menuStr의 문자열의 첫 줄을 아래와 같이 수정하라.
    "--------------- Virtual Functions -------------\n"

2) 아래 실행 결과와 같이 출력되도록 Person 클래스와 파생 클래스에 적절한 키워드를 추가하라.
virtual 함수 선언과 override 키워드를 적절히 삽입해 주면 된다.
printPerson(e)의 매개변수가 Person *p이고 p->println()을 호출했는데도 
파생클래스의 print()가 호출되고 실행되었음을 주지하기 바란다.
멤버함수 println()은 Person에만 정의되어 있다. (파생 클래스에서는 새로 정의할 필요 없다.)
```
### 문제 1 실행 결과
```
--------------- Virtual Functions -------------
  0.exit 1.print 2.addHours 3.whatAreYouDoing  
  4.whatIsYourPay 5.copyPerson 6.deletePerson  
-----------------------------------------------
menu item? 1
e->print(cout): n:e i:10001 h:50 c:Samsung p:30000 o:10
e->println()  : n:e i:10001 h:50 c:Samsung p:30000 o:10
printPerson(e): n:e i:10001 h:50 c:Samsung p:30000 o:10
s->print(cout): n:s i:10002 h:10 u:Chosun y:4 t:4000000
s->println()  : n:s i:10002 h:10 u:Chosun y:4 t:4000000
printPerson(s): n:s i:10002 h:10 u:Chosun y:4 t:4000000
```

### 문제 2 설명
```
+= 연산자 구현
아래 실행 결과와 같이 출력되도록 Person 클래스와 파생 클래스에 적절한 키워드를 추가하라.
필요하지 않은 경우 굳이 추가하지 않아도 된다.
```
### 문제 2 실행 결과
```
...
menu item? 2
e += 10    : n:e i:10001 h:60 c:Samsung p:30000 o:10
addHours(e): n:e i:10001 h:70 c:Samsung p:30000 o:10
s += 10    : n:s i:10002 h:20 u:Chosun y:4 t:4000000
addHours(s): n:s i:10002 h:30 u:Chosun y:4 t:4000000
```

### 문제 3 설명
```
whatAreYouDoing() 멤버 함수: 재정의된 객체의 멤버함수 대신 부모 클래스의 멤버 함수 호출

아래 실행 결과와 같이 출력되도록 Person 클래스와 파생 클래스에 적절한 키워드를 추가하라.
whatAreYouDoing(e)의 매개변수가 Person *p 이고 p->whatAreYouDoing()이 호출되었는데도
파생클래스의 멤버함수 whatAreYouDoing()이 실행되었음을 주지하라. 
```

### 문제 3 실행 결과
```
...
menu item? 3
e->whatAreYouDoing()          : I am working.
whatAreYouDoing(e)            : I am working.
e->Person::whatAreYouDoing()  : I am taking a rest.
s->whatAreYouDoing()          : I am studying.
whatAreYouDoing(s)            : I am studying.
(*s).Person::whatAreYouDoing(): I am taking a rest.
```