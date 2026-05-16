# OJ CH9_1
### 이번 문제의 목적: 가상함수
```
최상위 클래스인 Person의 일부 함수를 가상함수로 선언하고 상속받은 클래스들인 Student, Worker, 
StudentWorker에서 가상함수들을 override한다.
여기서 우리가 주목해야 할 것은 PersonManager::persons은 VectorPerson형의 데이타이며
VectorPerson::pVector는 Person*의 배열인 pVector[]이다. 
즉, 각각의 pVector[i]는 Student, Worker, StudentWorker의 최상위 클래스인 Person*이다.
pVector[]는 Person*만 가지고 있을 뿐인데도 가상함수를 활용함으로써 
Student, Worker, StudentWorker의 override된 함수들을 호출할 수 있다는 것이다.
```

### 코드 추가 1
```
아래 문자열로 메뉴 문자열을 수정하라.

메인메뉴 첫줄 변경(", 9" 추가)
* 0.Exit 1.PersonManager(ch3_2, 4, 6, 7_2, 8, 9)                          *

PersonManger 메뉴 첫줄 변경(", ch9" 추가)
= 0.Exit 1.Display 2.Append 3.Clear 4.Login(CurrentUser, ch9)   =
```