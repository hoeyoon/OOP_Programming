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