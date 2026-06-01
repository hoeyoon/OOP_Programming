# OJ CH10_3_Practice

### 문제 설명
```
이번에는 앞 전(10_1 문제)에 작성한 Conatiner 클래스를 Template 클래스로 작성해 보자.
기존 Conatiner 클래스는 정수(int) 값만 저장할 수 있었다.
따라서 기존 Conatiner 클래스를 Template 클래스로 변경하여 정수형, 실수형, 문자열 등 
다양한 데이터 타입을 저장할 수 있는 템플릿 클래스가 되도록 하라.

프로그램의 전체 구성도와 실행결과는 아래와 같다.
```

### 소스코드
```c++
// 대량의 데이터를 순서적으로 저장하고 있는 템플릿 컨테이너 클래스 선언
template 
class Container {

    기존 int value를 저장하는 vector의 구체화된 타입 int 대신에 제네릭 타입 T로 변경하라.  

    각 멤버 함수의 매개변수 value의 데이터 타입을 T로 변경하라. 즉, 매개변수 value를 가진 
        함수들만 찾아서 이 변수의 데이타 타입을 int 대신에 제네릭 타입 T로 변경 해 주면 된다.

};


Container의 모든 멤버 함수 구현에서 
1. 모든 함수 구현 앞에 template 를 추가하라.
2. 각 함수 이름 앞의 클래스 이름에 제네릭 타입 T가 들어가게 수정하라.
3. Container의 멤버 함수의 매개변수 value의 데이터 타입을 T로 변경하라. 

Container의 remove(value)에서 vector v의 iterator it 변수를 auto로 선언하고 
v.begin()으로 초기화하거나 또는 typename vector::iterator it = v.begin()로 
초기화한다.


// 기존의 
void test_int(int size) {

    첫 문장이었던 기존의 Container c; 대신
    위 템플릿 클래스를 활용하여 int 형으로 구체화된 Container 클래스 객체 변수 c를 아래처럼 변경하라.
    Container c;
    
    나머지는 기존과 동일
}

void test_string(int size) {

    위 템플릿 클래스를 활용하여 string 형으로 구체화된 Container 클래스 객체 변수 c를 선언하라.
    이 클래스는 문자열을 저장할 수 있는 container이다.

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
```

### 실행 결과
```
Enter the number of elements : 5

INTEGER Test

push: [0]105 [1]106 [2]107 [3]108 [4]109 

get(2): true : 107
get(5): false : 107
get(-1): false : 107

find(109): 4
find(104): -1

remove(107): true
[0]105 [1]106 [2]108 [3]109 

remove(110): false
[0]105 [1]106 [2]108 [3]109 

add(100): [0]205 [1]206 [2]208 [3]209 


STRING Test

push: [0]abc105 [1]abc106 [2]abc107 [3]abc108 [4]abc109 

get(2): true : abc107
get(5): false : abc107
get(-1): false : abc107

find("abc109"): 4
find("abc104"): -1

remove("abc107"): true
[0]abc105 [1]abc106 [2]abc108 [3]abc109 

remove("abc110"): false
[0]abc105 [1]abc106 [2]abc108 [3]abc109 

add("def"): [0]abc105def [1]abc106def [2]abc108def [3]abc109def
```