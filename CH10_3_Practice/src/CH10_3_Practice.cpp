#include <iostream>
#include <vector>
using namespace std;

// 대량의 데이터를 순서적으로 저장하고 있는 템플릿 컨테이너 클래스 선언
template<typename T> 
class Container {
	/*
    기존 int value를 저장하는 vector의 구체화된 타입 int 대신에 제네릭 타입 T로 변경하라.  

    각 멤버 함수의 매개변수 value의 데이터 타입을 T로 변경하라. 즉, 매개변수 value를 가진 
        함수들만 찾아서 이 변수의 데이타 타입을 int 대신에 제네릭 타입 T로 변경 해 주면 된다.
	*/
	vector<T> v;
	
public:
	void push(T value);	// value를 컨테이너에 삽입
	void add(T inc);		// 컨테이너에 삽입된 모든 원소에 inc를 더함
	bool get(int index, T &value);// 컨테이너의 index(배열처럼 0부터 시작) 위치에 있는 원소 값을 반환
	int  find(T value);	// value 값을 가진 원소의 인덱스를 리턴함
	bool remove(T value);	// value 값을 가진 원소를 삭제하고 true 리턴, 존재하지 않으면 false
	void print();			// 컨테이너에 삽입된 모든 원소를 순서적으로 출력
};


template<typename T> 
void Container<T>::push(T value){
	v.push_back(value);
}

template<typename T> 
void Container<T>::add(T inc){
	for(int i = 0; i < (int)v.size(); i++){
		v[i] += inc;
	}
}

template<typename T> 
bool Container<T>::get(int index, T &value){
	if(index < 0 || index >= (int)v.size()){
		return false;
	}
	value = v[index];
	return true;
}

template<typename T> 
int Container<T>::find(T value){
	for(int i = 0; i < (int)v.size(); i++){
		if(v[i] == value){
			return i;
		}
	}
	return -1;
}

template<typename T> 
bool Container<T>::remove(T value){
	for(auto it = v.begin(); it != v.end(); it++){
		if(*it == value){
			v.erase(it);
			return true;
		}
	}
	return false;
}

template<typename T> 
void Container<T>::print() {
	for (int i = 0; i < (int)v.size(); i++)
		cout << "[" << i << "]" << v[i] << " ";
	cout << endl << endl;
}


// 기존의 
void test_int(int size) {
	/*
    첫 문장이었던 기존의 Container c; 대신
    위 템플릿 클래스를 활용하여 int 형으로 구체화된 Container 클래스 객체 변수 c를 아래처럼 변경하라.
    Container c;
    
    나머지는 기존과 동일
    */
	Container<int> c;
	
	int min = 100 + size;
	int max = min + size - 1;
	int mid = min + size / 2;

	// size개 만큼 자동으로 원소를 삽입한다.
	for (int i = 0; i < size; i++)
		c.push(min+i);
	cout << "push: ";
	c.print();

	int value;
	cout << boolalpha; // boolean 값이 true, false로 출력되게 함
	cout << "get(" << size/2 << "): " << c.get(size/2, value) << " : " << value << endl;
	cout << "get(" << size << "): " << c.get(size, value) << " : " << value << endl;
	cout << "get(" << -1 << "): " << c.get(-1, value) << " : " << value << endl << endl;

	cout << "find(" << max << "): " << c.find(max) << endl;
	cout << "find(" << min-1 << "): " << c.find(min-1) << endl << endl;

	cout << "remove(" << mid << "): " << c.remove(mid) << endl;
	c.print();

	cout << "remove(" << max+1 << "): " << c.remove(max+1) << endl;
	c.print();

	c.add(100);
	cout << "add(100): ";
	c.print();
}

void test_string(int size) {
	/*
    위 템플릿 클래스를 활용하여 string 형으로 구체화된 Container 클래스 객체 변수 c를 선언하라.
    이 클래스는 문자열을 저장할 수 있는 container이다.
    */
	Container<string> c;

	int min = 100 + size;
	int max = min + size - 1;
	int mid = min + size / 2;

	// size개 만큼 자동으로 원소를 삽입한다.
	for (int i = 0; i < size; i++)
		c.push("abc"+to_string(min+i));
	cout << "push: ";
	c.print();

	string value;
	cout << boolalpha; // boolean 값이 true, false로 출력되게 함
	cout << "get(" << size/2 << "): " << c.get(size/2, value) << " : " << value << endl;
	cout << "get(" << size << "): " << c.get(size, value) << " : " << value << endl;
	cout << "get(" << -1 << "): " << c.get(-1, value) << " : " << value << endl << endl;

	value = "abc" + to_string(max);
	cout << "find(\"" << value << "\"): " << c.find(value) << endl;
	value = "abc" + to_string(min-1);
	cout << "find(\"" << value << "\"): " << c.find(value) << endl << endl;

	value = "abc" + to_string(mid);
	cout << "remove(\"" << value << "\"): " << c.remove(value) << endl;
	c.print();

	value = "abc" + to_string(max+1);
	cout << "remove(\"" << value << "\"): " << c.remove(value) << endl;
	c.print();

	c.add("def");
	cout << "add(\"def\"): ";
	c.print();

}

int main()
{
	cout << "Enter the number of elements : " ;
	int size;
	cin >> size;
	cout << endl << "INTEGER Test" << endl << endl;
	test_int(size);
	cout << endl << "STRING Test" << endl << endl;
	test_string(size);
	return 0;
}
