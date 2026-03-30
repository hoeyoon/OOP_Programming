#include <iostream>
#include <string>

using namespace std;

/******************************************************************************
 * Person Container
 ******************************************************************************/

class Container {
    string title;  // 컨테이너 타이틀
    int    size;   // 컨테이너에 저장된 정수 배열 arr의 크기
    int    *arr;   // size 개의 원소를 가진 배열 시작 주소
public:
    Container();
    Container(string title);
    Container(string title, int size);
    Container(const Container &ref);
    ~Container();

    void setTitle(string title);
    string getTitle();
    void printIntArray();
    Container& newIntArray();
    Container& inputIntArray();
};

Container::Container() : Container("no-title"){ }

Container::Container(string title) : Container(title, 0){ }

Container::Container(string title, int size) {
    arr = nullptr; this->size = size; this->title = title;// 추후 수정할 것
    if(size > 0){
    	arr = new int[size]{0};
    }
    cout << "Container(): "; printIntArray();
}

Container::Container(const Container &ref){
    arr = nullptr; size = ref.size; title = ref.title;// 추후 수정할 것
    if(size > 0){
    	arr = new int[size];
    	for(int i = 0; i < size; i++){
    		arr[i] = ref.arr[i];
    	}
    }
    cout << "Container(Container& c): "; printIntArray();
}

Container::~Container() {
    cout << "~Container(): "; printIntArray();
    if (arr != nullptr)
        delete [] arr;
}

void Container::setTitle(string title) {
    this->title = title;
}

string Container::getTitle() {
    return title;
}

void Container::printIntArray() {
    cout << title << ": arr[" << size << "]: ";
    for (int i = 0; i < size; ++i)
    	cout << arr[i] << " ";
    cout << endl;
}

Container& Container::newIntArray() {
    if (arr != nullptr)
        delete [] arr;
    cout << "element numbers of int array[]? ";
    cin >> size;
    arr = new int[size];
    return *this;
}

Container& Container::inputIntArray() {
    cout << "input " << size << " integers: ";
    for (int i = 0; i < size; ++i)
        cin >> arr[i];
    return *this;
}

/******************************************************************************
 * Global functions
 ******************************************************************************/

void skipEnter() {
    string s;
    getline(cin, s); // 메뉴항목 번호 뒤의 [엔터]를 제거함
}

void inputTitle(Container &ref){
	cout << "input title: ";
	string s;
	getline(cin, s);
	ref.setTitle(s);
}

void refParam() {
    Container c("C", 3);
    Container b("B");
    Container a;
    Container d;
    skipEnter();
    inputTitle(d);
}

Container& changeTitle(Container& rc) {
    string s;
    cout << "title to change: ";
    getline(cin, s);
    rc.setTitle(s);
    return rc;       // rc의 원본 객체의 참조를 리턴함
}

void refRet1() {
    skipEnter();
    Container c("C");
    Container& rc = changeTitle(c); // rc는 원본 객체 c의 데이타를 공유하는 참조변수임
    cout << " c.getTitle(): " <<  c.getTitle() << endl;
    cout << "rc.getTitle(): " << rc.getTitle() << endl;
    cout << "---" << endl;
    cout << "appendTitle(c).getTitle(): " << changeTitle(rc).getTitle() << endl;
    cout << "             c.getTitle(): " <<               c.getTitle() << endl;
    cout << "            rc.getTitle(): " <<              rc.getTitle() << endl;
    // changeTitle(rc)에 의해 반환되는 참조 역시 원본 객체 c의 데이타를 공유하는 참조변수임
    // 참조 변수는 생성자 및 소멸자가 없다. 원본 객체의 데이터를 공유하는 또 다른 변수 이름일 뿐이다.
}

void refRet2() {
    Container c("C");
    c.newIntArray().inputIntArray().printIntArray();
}

void explicitCopy() {
    Container c1("c1", 4);
    c1.inputIntArray().printIntArray();
    cout << "---" << endl;
    Container c2(c1);
    c2.setTitle("c2");
    c2.printIntArray();
    cout << "---" << endl;
    c2.inputIntArray().printIntArray();
    c1.printIntArray();
}

void implicitCopy() {
}

string menuStr =
"****************************** Main Menu ******************************\n"
"* 0.Exit 1.refParam 2.refRet1 3.refRet2 4.explicitCopy 5.implicitCopy *\n"
"***********************************************************************\n";

int main() {
    while (true) {
        int menuItem;
        cout << endl << menuStr << "menu? ";
        cin >> menuItem;
        if (menuItem == 0)
            break;
        switch(menuItem) {
        case 1: refParam();     break;
        case 2: refRet1();      break;
        case 3: refRet2();      break;
        case 4: explicitCopy(); break;
        case 5: implicitCopy(); break;
        }
    }
    cout << "Good bye!!" << endl;
}
