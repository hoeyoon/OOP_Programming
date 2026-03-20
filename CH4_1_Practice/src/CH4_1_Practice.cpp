/******************************************************************************
 * 코드 추가 1
 ******************************************************************************/
// 1) 메뉴 [File]->[New]->[C/C++ Project] 한 후 새로운 프로젝트 CH4을 만들어라.
// 2) 메뉴 [File]->[New]->[Source Folder] 한 후 폴더 이름으로 src를 지정하여 생성하라.
// 3) 메뉴 [File]->[New]->[Source File]   한 후 폴더 이름으로는 위에서 지정한 CH4/src로
//    설정하고 파일 이름으로 ch4.cpp를 지정하여 소스파일을 만들어라.
// 4) 아래 코드를 소스파일로 복사하라.
//-----------------------------------------------------------------------------

// iostream string head 파일 include할 것
#include <iostream>
#include <string>
using namespace std;

/******************************************************************************
 * class Container
 ******************************************************************************/

class Container {
    string title;  // 컨테이너 타이틀
    int    size;   // 컨테이너에 저장된 정수 배열 arr의 크기
    int    *arr;   // size 개의 원소를 가진 배열 시작 주소
public:
    Container();
    ~Container();

    void setTitle(string title);
    string getTitle();
    void newArray();
    void newIntArray();
    void inputIntArray();
    void average();
    void rightRotateTitle();
    void findDeleteTitle();
};

Container::Container(){
	title = "";
	size = 0;
	arr = nullptr;
	cout << "Container(): arr = nullptr" << "; size = " << size << endl;
}

Container::~Container(){
	if(arr != nullptr){
		delete []arr;
		cout << "~Container(): arr" << '[' << size << ']' << " deleted;" << endl;
	}
	else{
		cout << "~Container(): " << title << endl;
	}
}

void Container::setTitle(string title) {
    /* 매개변수 title 값을 멤버 변수 title에 저장한다. */
	this->title = title;
}

string Container::getTitle() {
    return title;  /* 멤버변수 title을 반환하라. */
}

void Container::newIntArray(){
	cout << "element numbers of int array[]? ";
	cin >> size;
	arr = new int[size];
}

void Container::inputIntArray(){
	cout << "input " << size << " integers: ";
	for(int i = 0; i < size; i++){
		cin >> arr[i];
	}

	cout << "arr" << '[' << size << "]: ";
	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

void Container::average(){
	double temp = 0;
	for(int i = 0; i < size; i++){
		temp += arr[i];
	}
	cout << "average: " << temp / size << endl;
}

/******************************************************************************
 * Global functions
 ******************************************************************************/

void constructor() {
    Container c;
    c.setTitle("constructor-title");
    cout << "c.getTitle(): " << c.getTitle() << endl;
}

void intArray() {
    Container c;
    c.newIntArray();
    c.inputIntArray();
    c.average();
}

Container *newObjectArray(int size) {
    Container *pArr = nullptr; // Container 객체 배열 시작 주소
    /* 여기에 코드를 구현하라. */
    return pArr;
}

void printTitles(Container *pArr, int size) {
}

void objectArray() {
    Container *pArr; // Container 객체 배열 시작 주소
    int size;        // Container 객체 배열 원소 개수
    cout << "element numbers of Container array[]? ";
    cin >> size;
    pArr = newObjectArray(size);
    printTitles(pArr, size);
    /* 여기서 pArr이 포인터 하는 메모리를 반납하시오. */
}

void inputTitle(Container* cp) {
    string s;
    getline(cin, s); // 앞서 입력된 메뉴항목 번호 뒤의 [엔터]를 제거함
    /* 여기에 코드를 구현하라. */
}

void rotateTitle() {
}

void findDelete() {
}

/******************************************************************************
 * main()
 ******************************************************************************/

string menuStr =
"******************************** Main Menu *********************************\n"
"* 0.Exit 1.constructor 2.intArray 3.objectArray 4.rotateTitle 5.findDelete *\n"
"****************************************************************************\n";

int main() {
    while (true) {
        int menuItem;
        cout << endl << menuStr << "menu? ";
        cin >> menuItem;
        if (menuItem == 0)
            break;
        switch(menuItem) {
        case 1: constructor(); break;
        case 2: intArray();    break;
        case 3: objectArray(); break;
        case 4: rotateTitle(); break;
        case 5: findDelete(); break;
        }
    }
    cout << "Good bye!!" << endl;
}
