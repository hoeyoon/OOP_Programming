```
//---------------------------
// 5장 문제
//---------------------------

//**************************************************
// 아래 코드는 x,y 좌표 값을 저장하는 큐(Queue)클래스를 구현하고
// 이 큐를 관리하는 프로그램이다.
// 아래 세부 문제들을 참고하여 나머지 코드를 구현하라.
//**************************************************

// 아래 include 문장에서 < > 사이의 공백 문자를 제거하시오. 
#include < iostream >
#include < string >
using namespace std;

// x,y 좌표 값을 저장하는 클래스
class Point {
public:
    int x, y;
    void print() { cout << "(" << x << "," << y << ")"; }
};

// Point 객체들을 저장하는 원형 큐
class Queue {
private:
    string *pname;    // 큐의 이름
    Point  *elements; // 큐의 원소들을 저장하고 있는 배열의 메모리 주소
    int capacity;     // 동적으로 할당된 큐의 크기 (최대 원소 개수)
    int count;        // 현재 큐에 삽입된 원소의 개수
    int frontIdx;     // 큐의 맨 앞 원소의 인덱스(pop()할 원소)
    int backIdx;      // 큐의 맨 뒤 원소 그 다음의 인덱스(새로 push()할 인덱스)
public:
    Queue(const string& name, int capacity) { // 생성자
        pname = new string(name);
        elements = new Point[capacity];
        this->capacity = capacity;
        count = frontIdx = backIdx = 0;
    }
    ~Queue() {
        delete pname;
        delete [] elements;
    }
    int maxSize()                    { return capacity; }
    int size()                       { return count; }
    bool empty()                     { return count == 0; }
    void setName(const string& name) { *pname = name; };

    void print() {
        cout << *pname << ": ";
        for (int i=frontIdx, cnt=0; cnt < count; ++cnt, i=(i+1)%capacity)
            elements[i].print();
        cout << endl;
    }
    bool push(const Point& item);
};

//-------------------------------------------------
// 여기에 Queue의 적절한 멤버 함수들을 구현하라.
//-------------------------------------------------

// 큐의 맨 뒤에 item을 삽입함
bool Queue::push(const Point& item) {
    if (count >= capacity) // 큐가 가득 찬 경우
        return false;
    // 문제 1: 여기에 아래의 코드를 삽입하시오.
    // item을 elements[backIdx]에 저장한 후
    // 원형 큐이므로 backIdx = (backIdx+1) % capacity; 한 후 
    // count 증가
    return true;
}

//-------------------------------------------------
// 아래 함수들은 문제에서 제시한 코드로 대체하시오.
//-------------------------------------------------

// 큐의 첫 원소와 마지막 원소의 위치를 서로 바꾼다.
void swap(Queue& queue) {
}
// 큐의 일부 원소들을 출력한 후 삭제한다.
void pop(Queue& queue) {
}
// 아래 함수의 매개변수는 call by value 이다. 
void printQueue(Queue q) { // 함수 수정 금지
    q.setName("q    ");
    q.print();             // q의 좌표들을 출력;
}
// 위 함수를 call by value 로 호출한다. 
void parameter(Queue& queue) { // 함수 수정 금지
    printQueue(queue);
    queue.print();
}
// 키보드에서 좌표 값들을 읽어 큐에 삽입함
void input(Queue& queue) {
    int count;
    // 큐에 삽입할 좌표의 개수
    cout << "input count? ";
    cin >> count;
    int space = queue.maxSize() - queue.size(); // 큐의 여유 공간
    // count 값이 큐의 여유 공간보다 더 클 경우 여유공간 크기만큼 설정함
    if (count > space) count = space;
    for (int i = 0; i < count; i++) {
        Point p;
        cout <<"input " << "x, y: " ;
        cin >> p.x >> p.y; // x, y 좌표 값을 입력 받음
        queue.push(p);
    }
    queue.print();
}

//-------------------------------------------------
// 아래 코드는 수정 불가
//-------------------------------------------------

int main() {
    Point points[] = { {0,1}, {2,3}, {4,5}, {6,7}, {8,9} };
    int capacity = sizeof(points) / sizeof(points[0]);

    Queue queue("queue", capacity);
    // points[] 배열에 있는 좌표들을 큐에 삽입함
    for (int i = 0; i < queue.maxSize(); i++)
        queue.push(points[i]);
    queue.print(); // 큐의 모든 원소를 출력함

    while (true) {
        cout << endl << "menu: 0.exit 1.swap 2.pop 3.parameter 4.input >> ";
        int item;
        cin >> item;
        if (item == 0) break;
        switch (item) {
            case 1: swap(queue);      break;
            case 2: pop(queue);       break;
            case 3: parameter(queue); break;
            case 4: input(queue);     break;
        }
    }
    cout << endl << "Good bye!!" << endl;
}

//**************************************************
// 소스 코드 끝
//**************************************************

===============================================================================
== 위 프로그램의 실행 결과는 아래와 같다.
=============================================================================== 
queue:                                                   // queue가 비어 있음

menu: 0.exit 1.swap 2.pop 3.parameter 4.input >> 0 [엔터] // 0을 입력한 후 엔터를 치시오.

Good bye!!

===============================================================================
== 문제 1
=============================================================================== 
// 프로그램 시작하자마자 아래 실행결과처럼 queue의 내용이 출력되도록  
// Queue::push(const Point& item) 멤버함수를 구현하시오.
// 구현시 함수 내의 주석을 참고하라.
===============================================================================
== 실행결과 1
=============================================================================== 
queue: (0,1)(2,3)(4,5)(6,7)(8,9)       // queue에 삽입된 원소들 출력

menu: 0.exit 1.swap 2.pop 3.parameter 4.input >> 

===============================================================================
== 문제 2
=============================================================================== 
// 기존 swap(Queue& queue) 함수를 아래 코드로 대체하라.
// 아래 함수는 queue의 처음과 마지막 원소의 위치를 서로 바꾸는 함수이다.
// 이를 위한 Queue::front()와 Queue::back() 함수를 구현하라.
//-----------------------------------------------------------------------------
void swap(Queue& queue) {
    queue.print();
    // queue.front()와 queue.back()의 좌표 값들의 위치를 서로 바꿈
    Point tmp = queue.front();
    queue.front() = queue.back();
    queue.back() = tmp;
    cout << "swap(queue.front(), queue.back())" << endl;
    queue.print();
}
//-----------------------------------------------------------------------------
// Queue::front()는 큐의 맨 앞 원소의 참조를 반환한다. 리턴 타입을 적절히 선언하라.
// 구현은 다음과 같이 하라. 
//-----------------------------------------------------------------------------
    elements[frontIdx]의 참조를 return한다.

//-----------------------------------------------------------------------------
// Queue::back()은 큐의 맨 뒤 원소의 참조를 반환한다. 리턴 타입을 적절히 선언하라.
// 구현은 다음과 같이 하라. 
//-----------------------------------------------------------------------------
    int idx = backIdx-1;
    if (idx < 0) idx = capacity-1; // 원형 큐이므로
    elements[idx]의 참조를 return한다. 

===============================================================================
== 실행결과 2
=============================================================================== 
queue: (0,1)(2,3)(4,5)(6,7)(8,9)

menu: 0.exit 1.swap 2.pop 3.parameter 4.input >> 1
queue: (0,1)(2,3)(4,5)(6,7)(8,9)
swap(queue.front(), queue.back())
queue: (8,9)(2,3)(4,5)(6,7)(0,1)       // 큐의 처음과 마지막 원소의 위치가 바뀌었음

menu: 0.exit 1.swap 2.pop 3.parameter 4.input >> 1
queue: (8,9)(2,3)(4,5)(6,7)(0,1)
swap(queue.front(), queue.back())
queue: (0,1)(2,3)(4,5)(6,7)(8,9)       // 큐의 처음과 마지막 원소의 위치가 바뀌었음

menu: 0.exit 1.swap 2.pop 3.parameter 4.input >> 

===============================================================================
== 문제 3
=============================================================================== 
// 기존 pop(Queue& queue) 함수를 아래 코드로 대체하라.
// 아래 함수는 queue의 내의 절반 정도의 원소들을 출력하고 해당 원소들을 삭제하는 함수이다.
// 이를 위한 Queue::pop() 멤버함수를 구현하라.
// 구현시 Queue 클래스 내의 이 멤버함수 선언 부분의 주석을 참고하라.
//-----------------------------------------------------------------------------
void pop(Queue& queue) {
    cout << "half pop: ";
    int count = queue.size() / 2;
    for (int i = 0; i < count; ++i) {
        queue.front().print();
        queue.pop();
    }
    cout << endl;
    queue.print();
}
//-----------------------------------------------------------------------------
// Queue::pop()은 큐의 맨 앞 원소(frontIdx) 삭제한다. 리턴 값은 없다.
// 구현은 다음과 같이 하라. 
//-----------------------------------------------------------------------------
    큐가 비었으면 그냥 리턴한다;
    원형 큐이므로 frontIdx = (frontIdx+1) % capacity;
    count 감소;

===============================================================================
== 실행결과 3
=============================================================================== 
queue: (0,1)(2,3)(4,5)(6,7)(8,9)

menu: 0.exit 1.swap 2.pop 3.parameter 4.input >> 2
half pop: (0,1)(2,3)          // 큐에서 빼낸 원소들 출력
queue: (4,5)(6,7)(8,9)        // 큐에 남아 있는 원소들 출력; 전체 원소의 반정도 삭제되었음

menu: 0.exit 1.swap 2.pop 3.parameter 4.input >> 

===============================================================================
== 문제 4
=============================================================================== 
// 3번 메뉴를 실행하면 프로그램이 비정상적으로 종료할 것이다. 
// 이 문제를 해결하기 위해 Queue 클래스 내에 적절한 생성자 또는 복사생성자 또는 멤버함수를 구현하라.
// 정상적으로 구현되었을 경우 아래와 같이 출력될 것이다.
===============================================================================
== 실행결과 4
=============================================================================== 
queue: (0,1)(2,3)(4,5)(6,7)(8,9)

menu: 0.exit 1.swap 2.pop 3.parameter 4.input >> 3
q    : (0,1)(2,3)(4,5)(6,7)(8,9)
queue: (0,1)(2,3)(4,5)(6,7)(8,9)  // 프로그램 죽지않고 정상 실행되었음; 두 큐의 내용 동일해야 함

menu: 0.exit 1.swap 2.pop 3.parameter 4.input >> 

===============================================================================
== 문제 5
=============================================================================== 
// 위 문제들을 모두 구현하였으면 아래처럼 입력하여 정상적으로 실행되어야 한다.  
===============================================================================
== 실행결과 5
=============================================================================== 
queue: (0,1)(2,3)(4,5)(6,7)(8,9)

menu: 0.exit 1.swap 2.pop 3.parameter 4.input >> 2
half pop: (0,1)(2,3)
queue: (4,5)(6,7)(8,9)                 // 전체 원소의 반정도 삭제

menu: 0.exit 1.swap 2.pop 3.parameter 4.input >> 2
half pop: (4,5)
queue: (6,7)(8,9)                      // 전체 원소의 반정도 삭제

menu: 0.exit 1.swap 2.pop 3.parameter 4.input >> 2
half pop: (6,7)
queue: (8,9)                           // 전체 원소의 반정도 삭제

menu: 0.exit 1.swap 2.pop 3.parameter 4.input >> 4
input count? 3
input x, y: 10 20
input x, y: 30 40
input x, y: 50 60
queue: (8,9)(10,20)(30,40)(50,60)     // 삭제된 원소만큼 새로 삽입


menu: 0.exit 1.swap 2.pop 3.parameter 4.input >> 1
queue: (8,9)(10,20)(30,40)(50,60)
swap(queue.front(), queue.back())
queue: (50,60)(10,20)(30,40)(8,9)     // 큐의 처음과 마지막 원소의 위치가 바뀌었음

menu: 0.exit 1.swap 2.pop 3.parameter 4.input >> 3
q    : (50,60)(10,20)(30,40)(8,9)
queue: (50,60)(10,20)(30,40)(8,9)     // 프로그램 죽지않고 정상 실행되었음

menu: 0.exit 1.swap 2.pop 3.parameter 4.input >> 2
half pop: (50,60)(10,20)
queue: (30,40)(8,9)                   // 전체 원소의 반정도 삭제

menu: 0.exit 1.swap 2.pop 3.parameter 4.input >> 0

Good bye!!
```