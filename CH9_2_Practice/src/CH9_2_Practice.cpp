/******************************************************************************
 ch9-AllinOne.cpp의 내용
*******************************************************************************/

//필요한 모든 헤드 파일 include(입출력 및 문자열 관련 헤드 파일)
#include <iostream>
#include <string>
using namespace std;

/******************************************************************************
 UI 클래스 선언 및 구현
    모든 멤버 함수들이 모두 정적(static) 함수임
    입력과 출력을 담당하는 전역 함수들의 모음
    static 함수 호출은 예제 6-10 참조
*******************************************************************************/

class UI {
public:
    static void println(string msg);    // msg 문자열 및 줄 바꾸기 출력
    static void print(string msg);    // msg 문자열 출력
    static int  printGetInt(string msg);// msg 문자열 출력 후 정수 하나 읽어 리턴  
    static int  getMainMenu();      // 메인 메뉴 종류 출력하고 메인 메뉴 값 입력 받아 리턴
    // 사용자로부터 x, y축으로 이동할 량 width와 height값을 입력 받음
    static void getWidthHeight(int &width, int &height);  // 정수 두 개 입력 받음
};

// UI의 모든 멤버 함수들은 static 함수임; 함수 정의 때는 static을 붙이지 않음

int UI::printGetInt(string msg) { // msg 문자열 출력 후 정수 값 하나 읽어 리턴
    문자열 msg 출력
    키보드에서 정수를 하나 읽어 리턴       // 예제 2-3 참조
}

UI의 println 함수 {
    문자열 msg와 줄바꾸기를 출력
}

UI의 print(string msg) 함수 {
    문자열 msg 출력
}

// 메인 메뉴 종류 출력하고 메뉴 선택 값(정수) 입력 받아 리턴
UI의 getMainMenu 함수 {
    // printGetInt() 함수를 사용하여 
    // 메인 메뉴를 출력하고 입력한 메뉴 번호 값을 읽어 리턴함. 즉,
    return printGetInt(출력할 메인 메뉴 문자열);
}
// 삽입할 도형 종류 출력하고 종류 값 입력 받아 리턴
UI의 getWidthHeight 함수 {
    ＂X축과 Y축으로 이동할 양은(정수 두개 입력)? >> ＂를 출력 // 교재 p.66 참조, cout 사용
    정수 값 두개를 읽어 인자인 width와 height에 저장 // cin 사용
}


/******************************************************************************
 Point 클래스 선언 및 구현
    화면의 한 점의 좌표 값을 가지는 Point 클래스
    교재에 없는 클래스임
*******************************************************************************/

class Point { // 한 점의 x, y 좌표 값을 가지고 있는 클래스
    int x; // 점의 x 좌표 값
    int y; // 점의 y 좌표 값
public:
    Point(int x = 0, int y = 0);
    void move(int width, int height);
    string toString();
};

// 객체 초기화: x, y 좌표 초기화
Point::Point(int x, int y) { 
     함수 인자인 x, y를 이 객체의 x, y 멤버에 저장
}

// x, y 좌표를 각각 width, height만큼 이동시킨다.
void Point::move(int width, int height) {
    이 객체의 x, y 멤버에 각각 width, height를 더하여 좌표를 이동함 
}

// (x,y) 좌표를 문자열로 변환하여 리턴, 예) "(10,15)"
// to_string(x): 정수 250을 "250"으로 변화함;  헤드 파일에 선언되어 있음
string Point::toString() { 
    return "(" + to_string(x) + "," + to_string(y) + ")"; 
}


/******************************************************************************
 Shape 클래스 선언
    교재 [그림 9-13] 기존 Shape.h의 내용을 복사한 후 아래 내용을 추가하라.
*******************************************************************************/

class Shape {
    . . .
public:
    . . .

    // 기존 객체를 x, y 축 방향으로 width, height 만큼 각각 이동함
    virtual void move(int width, int height) = 0;
};


/******************************************************************************
 Line 클래스 선언 및 구현
    교재 [그림 9-13] 기존 Line.h의 내용을 복사한 후 아래 내용을 추가하라.
*******************************************************************************/

class Line : public Shape {
    Point p1;    // 라인의 시작 좌표
    Point p2;    // 라인의 끝 좌표
protected:
    . . .
public:
    Line(const Point &p1, const Point &p2);
    Shape 클래스의 move()를 override 선언하라.
};

// 생성자: 객체 멤버 초기화
Line::Line(const Point &p1, const Point &p2) {
    // 함수 인자로 넘어 온 p1과 p2를 이 객체의 p1, p2에 저장
    this->p1 = p1;
    this->p2 = p2;
}

void Line::draw() { // UI의 static 함수 호출
    // 화면에 라인의 좌표 값을 출력, 예) "Line (10,15) (20,30)"
    UI::println("Line " + p1.toString() + " " + p2.toString());
}

// 기존 객체의 위치를 width, height만큼 옮긴다.
void Line::move(int width, int height) {
    // 기존 p1의 위치를 width, height만큼 옮긴다.
    p1.move(width, height);
    // 기존 p2의 위치를 width, height만큼 옮긴다.
    p2.move(width, height);
}


/******************************************************************************
 Rect 클래스 선언 및 구현
    교재 [그림 9-13] 기존 Rect.h에 아래처럼 추가하라.
*******************************************************************************/

class Rect : public Shape {
    Point p1;    // 사각형의 왼쪽 위쪽 좌표
    Point p2;    // 사각형의 오른쪽 아래쪽 좌표
protected:
    . . .
public:
    Rect(const Point &p1, const Point &p2);
    Shape 클래스의 move()를 override 선언하라.
};

// 위 Line 클래스 구현 부분을 참고하여 작성할 것

Rect의 생성자 함수 {
    함수 인자로 넘어 온 p1과 p2를 이 객체의 p1, p2에 저장
}

Rect의 draw() {  // UI의 적절한 멤버 함수 사용할 것
    화면에 사각형의 좌표 값을 출력, 예) "Rectangle (10,15) (20,30)"
}

Rect의 move 함수 { 기존 p1과 p2의 위치를 width, height만큼 옮긴다. }


/******************************************************************************
 Circle 클래스 선언 및 구현
    교재 [그림 9-13] 기존 Circle.h의 내용을 복사한 후 아래 내용을 추가하라.
*******************************************************************************/

class Circle : public Shape {
    Point center;// 원의 중심 좌표
    int   radius;// 반지름의 길이
protected:
    . . .
public:
    Circle(int radius, const Point ¢er);
    Shape 클래스의 move()를 override 선언하라.
};

// 위 Line 클래스 구현 부분을 참고하여 작성할 것

Circle 의 생성자 함수 {
    함수 인자로 넘어 온 radiu와 center를 이 객체의 해당 멤버에 저장
}

Circle 의 draw() { // 반지름은 to_string(radius)를 이용하여 문자열로 변화
                   // 이 함수 사용법은 Point.cpp의 toString() 함수 참조할 것
    // UI의 적절한 멤버 함수 사용할 것
    화면에 반지름과 중심 좌표 값을 출력, 예) "Circle 5 (20,30)"
}

Circle 의 move 함수 { 기존 중심 좌표의 위치를 width, height만큼 옮긴다. }


/******************************************************************************
 Factory 클래스 선언 및 구현
    임의의 숫자 발생 및 그래픽 객체 자동 생성 등
*******************************************************************************/

class Factory {
public:
   // 자동 생성할 그래픽 객체의 종류
    enum { LINE = 0, CIRCLE = 1, RECT = 2 };
    static Shape *create();  // 임의의 그래픽 객체를 자동 생성함
    // shapeType은 LINE, CIRCLE, RECT 등 셋 중 하나의 값을 가짐 
    static Shape *create(int shapeType);  // shapeType 객체 생성
    static int    getSize();      // 자동 생성할 그래픽 객체의 수 리턴
};

/*
#include 
using namespace std;

class Rand {
    // 난수를 생성하는 엔진  
    default_random_engine re;
    // 발생된 난수 값들이 일정 범위의 균등 분포(unfiform)로 매핑 
    uniform_int_distribution dist;
public:
    // [low, high] 범위 내의 값이 발생하도록 dist 초기화
    Rand(int low, int high) : dist(low, high) { }
    // [low, high] 범위 내의 난수 발생
    int operator() () { return dist(re); }
};
*/

// oj.chosun.ac.kr시스템 제출을 위해 위 Rand 클래스 대신 아래 클래스 사용함

class Rand {
    int low, max, cur;

public:
    Rand(int low, int high) {
        this->low = low, this->max = high-low+1, this->cur = (high-low+1) / 2;
    }
    // [low, high] 범위 내의 난수 발생
    int operator() () { cur = (cur + 1) % max; return low+cur; }
};

enum { MAX_XY = 99, MIN_SIZE = 5, MID_SIZE = 10, MAX_SIZE = 20 };

// [LINE, RECT] 범위의 난수 발생기 객체 선언, 자동 생성할 그래픽 종류 생성
static Rand randShapeType(Factory::LINE, Factory::RECT);

// [0, 99] 범위의 난수 발생기 객체 선언, x 또는 y 좌표 값 생성시 사용 
static Rand randXY(0, MAX_XY);

// [5, 20] 범위의 난수 발생기 객체 선언, 원의 반지름 생성시 활용
static Rand randRadius(MIN_SIZE, MAX_SIZE);

// [5, 10] 범위의 난수 발생기 객체 선언, 다각형 점의 개수 또는 그래픽 객체의 개수 생성시 활용
static Rand randSize(MIN_SIZE, MID_SIZE);

// 새로운 Point 객체를 생성하는 함수: x, y 좌표는 자동 지정
// randXY()는 위에서 선언된 randXY 객체의 멤버 함수 operator()를 호출하는 것임
static Point newPoint()        { return Point(randXY(), randXY()); }

// shapeType 객체를 생성함: 각 객체의 멤버들은 자동으로 설정됨
Shape* Factory::create(int shapeType) {
    switch (shapeType) {
    case LINE: // 라인
        return new Line(newPoint(), newPoint());
    case CIRCLE: // 원
        // randRadius()는 위에서 선언된 randRadius 객체의 멤버 함수 operator()를 호출하는 것임
        return new Circle(randRadius(), newPoint());
    case RECT: // 사각형
        return new Rect(newPoint(), newPoint());
    }
    return nullptr;
}

// 라인, 사각형, 원 중 임의로 하나의 객체를 생성함
Shape* Factory::create() {
    // randShapeType(): [LINE, RECT] 범위의 난수를 발생
    // randShapeType()는 위에서 선언된 randShapeType 객체의 멤버 함수 operator()를 호출하는 것임
    return create(randShapeType());
}

// 자동 생성할 그래픽 객체의 개수를 난수로 생성
int Factory::getSize() {
    return randSize(); // [5, 10] 범위의 난수 생성
}

/******************************************************************************
 GraphicEditor 클래스 선언 및 구현
*******************************************************************************/

class GraphicEditor {
    // 메인 메뉴의 종류
    enum { EXIT=0, ALL_PAINT=1, AUTO_INSERT=2, ALL_MOVE=3, ALL_REMOVE=4};

    Shape* pStart; // 삽입된 그래픽 객체들의 linked 리스트의 맨 처음을 가리킴
    Shape* pLast;  // 삽입된 그래픽 객체들의 linked 리스트의 맨 마지막을 가리킴

    void add(Shape* p);     // 새로운 그래픽 객체 p를 맨 마지막인 pLast 다음에 추가
    bool empty();           // 객체가 하나도 없는지 체크
    void removeAllShapes(); // 모든 그래픽 객체 삭제

protected:
    void autoInsert();// 임의의 개수의 그래픽 객체를 자동으로 삽입함
    void allRemove(); // 모든 그래픽 객체들을 삭제
    void allPaint();  // 삽입된 모든 그래픽 객체들을 화면에 출력
    void allMove();   // 모든 객체들을 사용자가 입력한 width, height 이동량만큼 좌표 이동

public:
    GraphicEditor();
    ~GraphicEditor();
    void run();   // 메인 메뉴를 보여 주고 사용자가 선택한 작업을 실행함 
};

// GraphicEditor 클래스 멤버인 pStart와 pLast의 용도는 [그림 9-12 참조할 것]
GraphicEditor의 생성자 함수 {
    pStart와 pLast 멤버 데이터를 nullptr(NULL아닌 nullptr)로 초기화 
}

GraphicEditor의 removeAllShapes 함수 {
    // 현재 생성된 모든 객체를 삭제: [그림 9-11]의 마지막 부분 참조할 것
    // Shape 객체의 linked list인 pStart에서 pLast까지 모두 삭제
    for (Shape *p = pStart, *q; p != nullptr; p = q) {
        p의 다음 객체에 대한 포인터를 구해 q에 저장;
        p가 포인터하는 객체 반납;
    }
    pStart와 pLast 멤버 데이터를 nullptr로 초기화 
}

GraphicEditor의 소멸자 함수 {
    removeAllShapes 함수 호출하여 리스트의 모든 객체 삭제
}

// 새로운 그래픽 객체 p를 맨 마지막인 pLast 다음에 추가
// GraphicEditor 클래스의 멤버인 pStart와 pLast의 용도는 [그림 9-12 참조할 것]
GraphicEditor의 add(Shape *p) 함수 { 
    pStart가 nullptr이면 {
        // [그림 9-11] 12~13행 참조
        pStart, pLast를 p로 설정한 후 리턴
    }
    else {
        // [그림 9-11] 16행 부분 참조
        pLast 뒤에 p를 추가하고(pLast의 멤버 함수 add()를 호출하여 p를 추가할 것)
        add()의 리턴 값을 pLast에 저장(pLast가 삽입된 마지막 도형을 포인터하게 함)
    }
}

// 객체가 하나도 없으면 에러 메시지 출력 후 true 리턴, 있을 경우 false 리턴
GraphicEditor의 empty() 함수 {
    pStart가 nullptr이면 {
        UI의 적절한 멤버 함수 이용하여 "그려진 도형이 없습니다." 출력
        적절한 값 리턴
    }
    적절한 값 리턴
}

// 삽입된 모든 그래픽 객체들을 화면에 출력
GraphicEditor allPaint 함수 { 
    // 처음부터 끝까지 linked list를 따라 가면서 도형을 그린다.
    // [그림 9-11] 중간부분 참조할 것
    Shape의 포인터형 변수 p를 선언하고 pStart로 초기화
    for (int i = 0; p != nullptr; ++i, p = p->getNext()) {
       // 인덱스 출력: 예), [1] 또는 [4]
       UI 적절한 멤버 함수 이용하여 "[" + to_string(i) + "]: " 출력(인덱스 출력)
       도형을 그리는 p의 멤버 함수 호출 // 도형 그리기 public 함수 호출
    }
}

// 자동으로 객체를 생성하여 리스트에 추가한다.
GraphicEditor autoInsert 함수 { 
    // 자동 삽입할 그래픽 객체의 개수를 얻어 옴(난수 발생)
    정수형 변수 size를 선언하고 Factory::getSize()를 호출하여 리턴 값으로 초기화 
    for 문을 이용하여 size만큼 반복 수행
        Factory::create()호출하여 새로운 그래픽 객체를 자동 생성하고
        생성된 객체를 GraphicEditor의 add() 함수 호출하여 리스트에 추가
        // Factory::create()의 리턴 값을 add()의 인자로 주면 됨
    모든 객체를 화면에 보여줌 (allPaint() 사용)
}

// 현재 생성된 모든 객체를 이동한다.
GraphicEditor allMove 함수 { 
    객체가 전혀 없을 경우 에러 출력 후 여기서 리턴 // empty() 사용
    정수형 변수 width, height 선언 // 각 도형의 이동할 양
    // 아래 함수는 "참조에 의한 호출"임; 그림[5-8] 참조
    UI의 getWidthHeight() 호출하여 사용자로부터 width, height 입력 받음
    // 처음부터 끝까지 링크를 따라 가면서 
    // 각 도형을 사용자가 지정한 width, height만큼 이동한다.
    for를 이용하여 리스트의 처음부터 끝까지 링크를 따라 가면서
         // for문은 allPaint()의 for를 적절히 응용 (필요 없는 변수와 문장은 빼고)
         각 도형의 move 함수 호출     // 도형 옮기기
    모든 객체를 화면에 보여줌
}

// 현재 생성된 모든 객체를 삭제한다.
GraphicEditor allRemove 함수 { 
    객체가 전혀 없을 경우 에러 출력 후 여기서 리턴 // empty() 사용
    removeAllShapes 함수 호출하여 리스트의 모든 객체 삭제 
}

// 메인 메뉴를 보여 주고 사용자가 선택한 작업을 실행함
GraphicEditor run 함수 {
    // UI 클래스의 함수들은 모두 static 함수임; 함수 호출은 예제 6-10 참조
    UI의 적절한 함수를 사용하여 "그래픽 에디터입니다." 출력
    while문을 이용하여 다음을 반복 수행 {
        정수형 변수 menu를 선언함과 동시에 
            UI의 getMainMenu()를 호출하여 리턴 값으로 초기화
        switch(menu) {
        // 모두보기인 ALL_PAINT는 enum 열거자이며 상수처럼 사용가능하며
        // GraphicEditor 클래스에 선언되어 있음
        case ALL_PAINT : 
             allPaint(); break;
             위와 같은 방법으로 
        AUTO_INSERT면 autoInsert() 호출 // 자동삽입 
        ALL_MOVE면 allMove()호출       // 모두이동
        ALL_REMOVE면 allRemove() 호출   // 모두삭제
        EXIT면 return           // 끝내기, 이 함수에서 리턴함
        그 외(default)는 "명령 선택 오류" 출력 (UI의 멤버 함수 사용)
        }
    }
}


/******************************************************************************
 *
 * main() 함수
 *
 ******************************************************************************/

int main()
{
    GraphicEditor 변수 g 선언
    g의 멤버 함수 run() 호출  // g는 포인터 변수가 아닌 일반 객체임
}
