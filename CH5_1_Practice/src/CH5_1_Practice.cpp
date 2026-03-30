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
    ~Container();

    void setTitle(string title);
    string getTitle();
    void printIntArray();
    void newIntArray();
    void inputIntArray();
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

void Container::newIntArray() {
    if (arr != nullptr)
        delete [] arr;
    cout << "element numbers of int array[]? ";
    cin >> size;
    arr = new int[size];
}

void Container::inputIntArray() {
    cout << "input " << size << " integers: ";
    for (int i = 0; i < size; ++i)
        cin >> arr[i];
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
}

void refRet2() {
}

void explicitCopy() {
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
