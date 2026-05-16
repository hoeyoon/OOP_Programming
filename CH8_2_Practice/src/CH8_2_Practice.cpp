#include <iostream>
using namespace std;

// 정수값 value를 저장하고 있는 double linked 리스트 노드
class Node {
private:
    // 모든 멤버를 private으로 선언하여 외부에서 접근 못하게 하고,
    // BaseList에서만 Node의 모든 멤버에 접근할 수 있게 클래스 전체를 friend로 선언
    friend class BaseList;
    Node *prev;
    Node *next;
    int value;
    Node(int value) { prev = next = nullptr; this->value = value; }
    int getValue() { return value; }
    // 현재 노드 다음에 n 노드를 추가한다.
    void add(Node *n) { next = n; n->prev = this; }
    // 현재 노드를 삭제하고 이 노드의 next 노드를 리턴한다.
    Node *remove() { Node *n = next; delete this; return n; }
};

// 여러 개의 노드들을 가지고 있는 double linked 리스트
class BaseList {
private:
    Node *head;   // double linked 리스트의 맨 처음  노드를 가리키는 포인터
    Node *tail;   // double linked 리스트의 맨 마지막 노드를 가리키는 포인터
protected:
    int size;     // 현재 리스트 내에 있는 노드(데이터)의 개수

    BaseList() { head = tail = nullptr; size = 0; } // 생성자: 멤버 초기화
    // 소멸자: 모든 노드를 삭제함
    ~BaseList() { for (Node *n = head; n != nullptr; n = n->remove()); }

    void add_rear(int value);
    int remove_rear();
    int remove_front();
};

// 새로운 노드(value 값을 저장하고 있음)를 생성한 후 리스트의 맨 마지막에 추가
void BaseList::add_rear(int value) {
    /* Node의 포인터 변수 n을 선언하고 
    새로운 Node를 동적으로 생성(value 값 전달)하여 n에 저장;
    만약 tail이 nullptr이 아니면 // NULL 대신에 nullptr 사용
        tail의 멤버함수 add(n)호출하여 리스트의 맨 끝에 n을 추가 
        리스트 끝에 새로 추가 되었으므로 tail을 n으로 설정
    아닌 경우 // 리스트에 노드가 없을 경우 n이 첫 노드가 됨
        tail과 head 값을 n으로 설정
    BaseList의 데이터 개수를 1 증가 */
	
	Node *n = new Node(value);
	if(tail != nullptr){
		tail->add(n);
		tail = n;
	}
	else{
		tail = n;
		head = n;
	}
	size++;
}

// 리스트의 마지막 노드를 제거한 후 그 노드에 저장된 value를 리턴
int BaseList::remove_rear() {
    /* 리스트의 노드 개수가 0이면 -1 리턴 // list empty error
    정수형 변수 val을 선언하고, 
    tail 노드에 저장된 value 값을 얻어와 val에 저장
    // 삭제할 노드의 앞 노드를 저장할 변수 prev 선언 및 초기화
    Node * 변수 prev를 선언하고 tail의 prev 멤버 값을 변수 prev에 저장
    tail 노드를 메모리에 반납함
    리스트의 노드 개수를 1 감소
    변수 prev가 nullptr이 아니면 // 삭제할 노드의 앞 노드가 존재할 경우
        변수 prev가 포인트하는 노드의 next 멤버를 nullptr로 설정함
        tail에 변수 prev을 설정 // 이제 마지막 노드는 삭제된 노드의 앞 노드가 됨
    아닌경우 즉, 변수 prev가 nullptr이면 // 더 이상 남은 노드가 없는 경우
         tail과 head 값을 nullptr로 설정
    val 값을 리턴 */
	
	if(size == 0) return -1;
	
	int val;
	val = tail->getValue();
	
	Node *prev = tail->prev;
	delete tail;
	size--;
	
	if(prev != nullptr){
		prev->next = nullptr;
		tail = prev;
	}
	else{
		tail = nullptr;
		head = nullptr;
	}
	
	return val;
}

// 리스트의 맨 처음 노드를 제거한 후 그 노드에 저장된 value를 리턴
int BaseList::remove_front() {
    /* 리스트의 노드 개수가 0이면 -1 리턴 // list empty error
    정수형 변수 val을 선언하고, 
    head 노드에 저장된 value 값을 얻어와 val에 저장
    // 삭제할 노드의 뒤 노드를 저장할 변수 next 선언 및 초기화
    Node * 변수 next를 선언하고 head의 next 멤버 값을 변수 next에 저장
    head 노드를 메모리에 반납함
    리스트의 노드 개수를 1 감소
    변수 next가 nullptr이 아니면 // 삭제할 노드의 뒤 노드가 존재할 경우
        변수 next가 포인트하는 노드의 prev 멤버를 nullptr로 설정함
        head에 변수 next를 설정 // 이제 맨 첫 노드는 삭제된 노드의 뒤 노드가 됨
    아닌경우 즉, 변수 next가 nullptr이면 // 더 이상 남은 노드가 없는 경우
         tail과 head 값을 nullptr로 설정
    val 값을 리턴 */
	if(size == 0) return -1;

	int val;
	val = head->getValue();
	
	Node *next = head->next;
	delete head;
	size--;
	
	if(next != nullptr){
		next->prev = nullptr;
		head = next;
	}
	else{
		tail = nullptr;
		head = nullptr;
	}
	
	return val;
}

class MyQueue : public BaseList {  	// BaseList를 상속받게 선언해야 함
public:
    void enqueue(int value) {  // 큐의 맨 끝에 노드 추가 후 value 저장
        // Base List의 적절한 멤버함수를 호출함 
    	add_rear(value);
    }
    int dequeue() { // 큐의 맨 앞의 노드 삭제하고 노드의 value 값 리턴
        // return Base List의 적절한 멤버함수를 호출함; 
    	return remove_front();
    }
    int length() { /* Base List에 저장된 데이터의 갯수를 리턴 */ return size; }
    static void test(); // static 함수임
};

void MyQueue::test() {
    MyQueue mQ;
    int size;
    cout << "큐에 삽입할 정수의 개수? ";
    cin >> size;
    cout << "큐에 enqueue()된 원소들 : ";
    for (int i = 0; i < size; i++) {
        mQ.enqueue(i*100); // 큐에 삽입
        cout << i*100 << ' ';
    }
    cout << endl << "큐의 크기: " << mQ.length() << endl;
    cout << "큐에서 dequeue()된 모든 원소들 : ";
    while (mQ.length() != 0)
        cout << mQ.dequeue() << ' '; // 큐에서 제거하여 출력
    cout << endl << "큐의 현재 크기 : " << mQ.length() << endl;
}

class MyStack : public BaseList {
public:
    void push(int value) { // 스택의 맨 끝에 노드 추가 후 value 저장
        //Base List의 적절한 멤버함수를 호출함; 
    	add_rear(value);
    }
    int pop() { // 스택의 맨 끝의 노드 삭제하고 노드의 value 값 리턴
        //return Base List의 적절한 멤버함수를 호출함;
    	return remove_rear();
    }
    int length() { /* Base List에 저장된 데이터의 갯수를 리턴 */ return size; }
    static void test(); // static 함수임
};

void MyStack::test() {
    MyStack mStack;
    int size;
    cout << "스택에 삽입할 정수의 개수? ";
    cin >> size;
    cout << "스택에 push()된 원소들 : ";
    for (int i = 0; i < size; i++) {
        mStack.push(i); // 스택에 푸시
        cout << i << ' ';
    }
    cout << endl << "스택 크기: " << mStack.length() << endl;
    cout << "스택에서 pop()된 모든 원소들 : ";
    while (mStack.length() != 0)
        cout << mStack.pop() << ' '; // 스택에서 팝
    cout << endl << "스택의 현재 크기 : " << mStack.length() << endl;
}

int main()
{
    MyQueue::test();
    MyStack::test();
    return 0;
}
