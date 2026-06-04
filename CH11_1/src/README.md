# OJ CH11_1

### 코드 추가 및 변경 1
```
1) MainMenu 문자열의 일부분을 아래 문자열로 교체하라.

* 0.Exit 1.PersonManager(ch3_2, 4, 6, 7_2, 8, 9, 10, 11)                      *
```

### 문제 1 설명
```
SmartPhone의 출력 연산자 << 구현
 ******************************************************************************/
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