# OJ CH10_1_Practice

### 문제 1 설명
```
template class 작성하기

아래의 templateClass()는 1번 메뉴을 선택했을 때 실행되는 함수이다.
1) 아래 templateClass() 함수의 코드를 소스 파일에 복사하라.
2) 아래 Store 클래스는 정수 값을 저장하고 더하고 빼올 수 있는 클래스이다.
    templateClass() 함수에서처럼 정수 뿐만 아니라 문자열, 실수 등 다양한 데이타 타입의 값을 
    저장하고 빼올 수 있도록 Store 클래스를 template 클래스 Store< T >로 변환하라. 
```
```c++
class Store {
    int value;
public:
    Store(const int& v={}) { value = v; }
    int get()              { return value; }
    void set(const int& v) { value = v; }
    int add(const int& v)  { value += v; return value;}
};

// Store< int > is 에 정수 값을 넣고 빼고 수정한다.
// Store< string > ss("S1") 에 문자열을 넣고 빼고 수정한다.
void templateClass() {
    Store< int > is;
    int i = is.get();
    cout << "is.get()   : " << i << endl;
    is.set(3);
    cout << "is.set(3)" << endl;
    i = is.add(4);
    cout << "is.add(4)  : " << i << endl;

    Store< string > ss("S1");
    string s = ss.get();
    cout << "ss.get()   : " << s << endl;
    ss.set("S3");
    cout << "ss.set(S3)" << endl;
    s = ss.add("S4");
    cout << "ss.add(S4) : " << s << endl;
}
```

### 문제 1 실행 결과
```
...
menu item? 1
is.get()   : 0
is.set(3)
is.add(4)  : 7
ss.get()   : S1
ss.set(S3)
ss.add(S4) : S3S4
```

### 문제 2 설명
```
벡터(vector) 컨테이너에 원소 삽입 및 출력

아래의 vectorDisplay()는 2번 메뉴을 선택했을 때 실행되는 함수이다. 
이 함수는 벡터에 10개의 원소를 삽입한 후 모든 벡터 원소들을 출력한다. 
1) 아래 printVector(), vectorAppend(), vectorDisplay()의 코드를 소스 파일에 복사하라.
2) printVector(), vectorAppend()의 TODO 부분을 구현하라.
    이 두 함수는 다른 메뉴 항목을 선택했을 때도 필요에 의해 호출된다.
```
```c++
// 벡터 iv의 모든 원소를 화면에 출력한다.
void printVector(string msg = {}) {
	if (!msg.empty())
	    cout << msg << endl;
    cout << "vector: ";
    
    TODO: 벡터 iv의 모든 원소를 출력하라.

    cout << endl;
}

// 10개의 난수를 발생하여 벡터에 삽입한다.
void vectorAppend() {
	//rnd.setSeed(); // 지시가 있을 때까지 주석을 해제하지 마시오. 
    if (!iv.empty()) iv.clear(); // iv에 기존 원소가 있으면 모두 제거함

    TODO: 10개의 난수를 생성하여 iv 벡터에 추가하시오.
    // 난수 생성방법: rnd() 함수를 호출한 후 그 리턴 값을 벡터에 추가하면 됨 
    //            rnd()는 [10, 29] 범위의 난수 값을 발생시킴
}

// 벡터에 10개의 값을 삽입한 후 벡터 내용을 출력한다.
void vectorDisplay() {
    vectorAppend();
    printVector();
}
```

### 문제 2 실행 결과
```
...
menu item? 2
vector: 10 12 25 19 20 14 10 23 23 28 
```

### 문제 3 설명
```
algorithm 함수 사용하기

아래의 vectorSort()는 3번 메뉴을 선택했을 때 실행되는 함수이다. 
1) 아래 vectorSort()의 코드를 소스 파일에 복사하라. 
    이 함수는 벡터 전체를 정렬한 후 정렬된 벡터를 출력한다.
2) 이 함수의 TODO 부분을 구현하라.
```
```c++
void vectorSort() {
    vectorAppend();
    printVector("before sort");

    TODO: 벡터 iv 전체를 정렬하라.

    printVector("after sort"); // 작은 수에서 큰 수 순서로 출력되어야 함
}
```

### 문제 3 실행 결과
```
...
// 프로그램 실행 후 바로 3번 메뉴를 실행하지 않으면 아래와 다른 난수들이 생생될 것이다. 
menu item? 3
before sort
vector: 10 12 25 19 20 14 10 23 23 28 
after sort
vector: 10 10 12 14 19 20 23 23 25 28 
```