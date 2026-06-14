```
[4장 문제-3]

//----------------------------------------------------------------------------
// 아래 문제를 해결하는 도중 출력이 잘못되었거나 문제 설명과 출력이 일치하지 않거나 오타가 있거나 등등
// 조금이라도 문제에 이상한 것이 있으면 주저하지 말고 jhshim@chosun.ac.kr로 알려 주시기 바랍니다.
//----------------------------------------------------------------------------

/******************************************************************************
 * 프로젝트 및 소스파일 생성
 ******************************************************************************/
// 기존의 과제를 수행했던 이클립스의 작업공간에서 새로운 프로젝트 CH4_3를 만들고 
// 그 밑에 src 풀더를 만든 후 src 폴더 밑에 ch4_3.cpp 소스파일을 만들어라.

/******************************************************************************
 * 코드 추가 1
 ******************************************************************************/
// 1) 기존에 작성했던 ch4_2.cpp의 내용을 모두 복사해서 ch4_3.cpp에 삽입하라.
// 2) 프로그램의 맨 앞쪽 주석 부분의 "Author: " 행 다음의 내용을 아래 *로 시작하는 행들로 교체하라.
//----------------------------------------------------------------------------
 *
 *  + class Memo 추가: string 클래스의 멤버함수 및 operator 활용법
 *  + Person::memo_c_str[] 멤버 및 set, get 함수 추가
 *  + CurrentUser::memo 멤버, 함수 및 메뉴 항목 추가
 *  + PersonManager::~PersonManager()에서 display() 문장 삭제
 *  + PersonManager::run()의 string menuStr 수정
 */


/******************************************************************************
 * 코드 삭제
 ******************************************************************************/
// PersonManager::~PersonManager()에서 아래 문장을 삭제하라.
    display();


/******************************************************************************
 * 코드 추가 2
 ******************************************************************************/
// 아래 class Memo를 namespace UI 와 class CurrentUser 사이에 배치하라.
//----------------------------------------------------------------------------

/******************************************************************************
 * ch4_3: string and Memo class
 ******************************************************************************/

class Memo
{
    string mStr; // 메모를 저장해 두는 문자열

    string get_next_line(size_t* ppos);
    bool find_line(int line, size_t* start, size_t* next);
    size_t find_last_line();

public:
    string getNext(size_t* ppos);
    void displayMemo();
    const char *get_c_str();
    void set_c_str(const char *c_str);
    void findString();
    void compareWord();
    void dispByLine();
    void deleteLine();
    void replaceLine();
    void scrollUp();
    void scrollDown();
    void inputMemo();
    void run();
};

void Memo::displayMemo() { // Menu item 1
    cout << "------- Memo -------" << endl;
    cout << mStr;
    if (mStr.length() > 0 && mStr[mStr.length()-1] != '\n')
        cout << endl; // 메모 끝에 줄바꾸기 문자가 없을 경우 출력
    cout << "--------------------" << endl;
}

// 아래 R"( 와 )"는 그 사이에 있는 모든 문자를 하나의 문자열로 취급하라는 의미이다.
// 따라서 행과 행 사이에 있는 줄바꾸기 \n 문자도 문자열에 그대로 포함된다.
// 이런 방식을 사용하지 않으면 여러 행에 걸친 문자열을 만들려면 복잡해진다.
const char* memoData = R"(The Last of the Mohicans
James Fenimore Cooper
Author's Introduction
It is believed that the scene of this tale, and most of the information
necessary to understand its allusions, are rendered sufficiently 
obvious to the reader in the text itself, or in the accompanying notes.
Still there is so much obscurity in the Indian traditions, and so much
confusion in the Indian names, as to render some explanation useful.
Few men exhibit greater diversity, or, if we may so express it, 
greater antithesis of character, 
than the native warrior of North America.
)";

void Memo::run() {

    // TODO 문제 [1]: func_arr[], menuCount 선언

    string menuStr =
        "++++++++++++++++++++++ Memo Management Menu +++++++++++++++++++++\n"
        "+ 0.Exit 1.DisplayMemo 2.FindString 3.CompareWord 4.DispByLine  +\n"
        "+ 5.DeleteLine 6.RepaceLine 7.ScrollUp 8.ScrollDown 9.InputMemo +\n"
        "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

    if (mStr == "") mStr = memoData;// 멤버 mStr이 비었을 경우 위 memoData로 초기화한다.

    // TODO 문제 [1]: while 문장 삽입하여 선택된 메뉴항목 실행하는 함수 호출
    
    cout << menuStr; // TODO 문제 [1]: 이 두 문장은 삭제될 예정임
    cout << mStr;    // TODO 문제 [1]
}


/******************************************************************************
 * 코드 추가 3
 ******************************************************************************/
// 위 class Memo를 활용하는 코드를 삽입해 보자.
// class CurrentUser에 아래 내용들을 반영하여라.
//----------------------------------------------------------------------------

// 1) class CurrentUser 내에 pUser 멤버 뒤에 아래 멤버를 새로 추가하라.
    Memo    memo; // ch4_3에서 추가

// 2) 아래 manageMemo() 멤버 함수를 CurrentUser::changePasswd() 함수의 구현 뒤에
//    새로 추가하라. 또한 클래스 선언부 내에도 이 함수를 선언하라. 

void CurrentUser::manageMemo() { // Menu item 9
    memo.run();
}

// 3) run() 함수 내의 menuStr에 아래 9번 메뉴 항목을 추가하라.
      "+ 6.IsSame 7.InputPerson 8.ChangePasswd(4_2) 9.ManageMemo(4_3) +\n"

// 4) run() 함수 내의 func_arr[]의 마지막에 멤버 함수 manageMemo()의 함수 포인터를 추가하라.


/******************************************************************************
 * 코드 추가 4
 ******************************************************************************/
// PersonManager::run()의 string menuStr을 아래의 내용으로 교체하라.
//----------------------------------------------------------------------------
    string menuStr =
        "====================== Person Management Menu ===================\n"
        "= 0.Exit 1.Display 2.Append 3.Clear 4.Login(CurrentUser, ch4)   =\n"
        "=================================================================\n";

===============================================================================
== 초기 프로그램 실행 결과
=============================================================================== 

******************************* Main Menu *********************************
* 0.Exit 1.PersonManager(ch3_2, 4)                                        *
...
Menu item number? 1

====================== Person Management Menu ===================
= 0.Exit 1.Display 2.Append 3.Clear 4.Login(CurrentUser, ch4)   =
=================================================================
Menu item number? 4
user name: p0
password: [입력 없이 그냥 엔터]

+++++++++++++++++++++ Current User Menu ++++++++++++++++++++++++
+ 0.Logout 1.Display 2.Getter 3.Setter 4.Set 5.WhatAreYouDoing +
+ 6.IsSame 7.InputPerson 8.ChangePasswd(4_2) 9.ManageMemo(4_3) +
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Menu item number? 9 // 아래는 Memo::run()에서 출력된 것임
++++++++++++++++++++++ Memo Management Menu +++++++++++++++++++++
+ 0.Exit 1.DisplayMemo 2.FindString 3.CompareWord 4.DispByLine  +
+ 5.DeleteLine 6.RepaceLine 7.ScrollUp 8.ScrollDown 9.InputMemo +
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
The Last of the Mohicans
James Fenimore Cooper
Author's Introduction
It is believed that the scene of this tale, and most of the information
necessary to understand its allusions, are rendered sufficiently 
obvious to the reader in the text itself, or in the accompanying notes.
Still there is so much obscurity in the Indian traditions, and so much
confusion in the Indian names, as to render some explanation useful.
Few men exhibit greater diversity, or, if we may so express it, 
greater antithesis of character, 
than the native warrior of North America.

+++++++++++++++++++++ Current User Menu ++++++++++++++++++++++++
...
Menu item number? 


/******************************************************************************
 * [문제 1]
 ******************************************************************************/
// 기존의 CurrentUser::run() 과 PersonManager:run() 을 참고하여 
// Memo::run()의 코드를 완성하라.
// 1) func_arr[], menuCount을 추가하라.  
//    Memo 단어가 짧아서 using MM = Memo와 같은 문장은 사용하지 않아도 된다.
//    func_arr[]에는 두 개의 메뉴 항목 "0.Exit 1.DisplayMemo"을 처리하는
//    멤버함수 포인터를 저장하라.
// 2) while 문장을 삽입하여 선택된 메뉴항목을 수행하는 함수를 호출하라.
// 3) 두 개의 cout << ...; 문장을 삭제하라.
//-----------------------------------------------------------------------------

===============================================================================
== [문제 1] 실행 결과
=============================================================================== 

******************************* Main Menu ...
====================== Person Management Menu ...
+++++++++++++++++++++ Current User Menu ...
+ 6.IsSame 7.InputPerson 8.ChangePasswd(4_2) 9.ManageMemo(4_3) +
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Menu item number? 9

++++++++++++++++++++++ Memo Management Menu +++++++++++++++++++++
+ 0.Exit 1.DisplayMemo 2.FindString 3.CompareWord 4.DispByLine  +
+ 5.DeleteLine 6.RepaceLine 7.ScrollUp 8.ScrollDown 9.InputMemo +
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Menu item number? 1
------- Memo -------
The Last of the Mohicans
James Fenimore Cooper
Author's Introduction
It is believed that the scene of this tale, and most of the information
necessary to understand its allusions, are rendered sufficiently 
obvious to the reader in the text itself, or in the accompanying notes.
Still there is so much obscurity in the Indian traditions, and so much
confusion in the Indian names, as to render some explanation useful.
Few men exhibit greater diversity, or, if we may so express it, 
greater antithesis of character, 
than the native warrior of North America.
--------------------

...
Menu item number? 2
2: OUT of selection range(0 ~ 1)
Menu item number? 0

+++++++++++++++++++++ Current User Menu ...
Menu item number? 


/******************************************************************************
 * [문제 2]
 ******************************************************************************/
// 1) 매번 Memo 메뉴까지 찾아 들어 가려면 3번의 과정을 거쳐 들어가야 한다. 상당히 성가신 작업이므로
//    Memo 클래스의 빠른 테스트를 위해 main() 함수 바로 위에 있는 run() 함수를 당분간 임시로 
//    아래와 같이 수정하라. 메인 메뉴 거치지 않고 처음부터 바로 메모 메뉴로 진입할 것이다. 확인 해보라.

void run() {
    //MainMenu().run();
    Memo().run();
}

//-----------------------------------------------------------------------------
// 2) 아래 멤버함수 Memo::findString()의 코드를 완성하라.
//-----------------------------------------------------------------------------

// 사용자로부터 찾을 단어를 입력받고 메모 문자열에서 해당 단어의 출현 회수를 세어서 출력한다.
// 찾을 단어가 다른 단어의 일부분일지라도 모두 카운트하라.
void Memo::findString() {
    string word = UI::getNext("Word to find? ");
    int count = 0, len = word.length();
    /*
    TODO: for 문을 사용하여 반복적으로 string::find() 함수를 호출하여 찾은 단어의 
          출현 회수(count)를 세어라. find()를 통해 찾은 위치에서 len을 더하면 
          찾은 단어의 끝 위치가 되는데 이것이 다음 번에 찾기 시작할 위치이다.
          string::find()의 리턴 값이 string::npos와 같으면 
          단어를 찾지 못했다는 것을 의미한다. 못 찾을 때까지 반복 수행하면 됨.
          찾기 시작 위치 또는 리턴 값의 타입은 size_t를 사용하라.
    */
    cout << "Found count: " << count << endl;
}

//-----------------------------------------------------------------------------
// 3) Memo::run()의 func_arr[]에 Memo::findString 항목을 추가하라.
//-----------------------------------------------------------------------------

===============================================================================
== [문제 2] 실행 결과
== 프로그램 시작하자마자 아래 메뉴가 바로 실행된다.
=============================================================================== 

++++++++++++++++++++++ Memo Management Menu +++++++++++++++++++++
+ 0.Exit 1.DisplayMemo 2.FindString 3.CompareWord 4.DispByLine  +
+ 5.DeleteLine 6.RepaceLine 7.ScrollUp 8.ScrollDown 9.InputMemo +
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Menu item number? 2
Word to find? ex // 사용자 입력
Found count: 4

...
Menu item number? 2
Word to find? the
Found count: 11

// 참고로 각 단어의 회수임; if:1, th:16, t:47, it:8, in:6, of:5, o:36, i:39


/******************************************************************************
 * [문제 3]
 ******************************************************************************/
// 3번 메뉴항목(Memo::compareWord())은 메모 텍스트 중에 
// 입력 받은 단어보다 사전적 순서상으로 작은 단어, 같은 단어, 큰 단어의 개수를 출력한다.
// 아래 멤버함수 Memo::getNext()와 Memo::compareWord()의 코드를 완성하고,
// Memo::run()의 func_arr[]에 적절한 항목을 추가하라.
//-----------------------------------------------------------------------------

// 메모의 현 위치(pos = *ppos)에서 하나의 단어를 찾아 해당 단어를 별도의 string으로 구성해서 리턴함
// 스페이스, 탭, 엔터와 같은 공백 문자로 시작할 경우 이들을 먼저 모두 스킵함
// 단어의 끝은 공백, 탭, 엔터, 구두점(punctuation)으로 구분함
// 구두점이란 숫자, 영문자를 제외한 문자들을 의미한다. ,.';:"][{}()*&^%$#@!~`?>< 등
// 각 구두점 글자는 단어를 구분하는 구분자로 사용되고 그 글자 하나만으로도 하나의 단어로 취급받음
// isspace()와 ispunct() 함수는 www.cplusplus.com/reference/에서 검색해 보기 바란다.

string Memo::getNext(size_t* ppos) {
    size_t pos = *ppos, end;
    for ( ; pos < mStr.size() && isspace(mStr[pos]); ++pos) ; // 단어 앞의 공백 문자들 스킵(있을 경우)
    end = pos; // pos는 단어의 시작 위치이고 end는 단어의 끝 다음 위치이다.
    if (end < mStr.size() && ispunct(mStr[end])) // 첫 글자가 구두점일 경우
        ++end;
    else { // 단어의 끝을 찾음
        for ( ; end < mStr.size() && !isspace(mStr[end]) &&
                !ispunct(mStr[end]); ++end) ;
    }
    *ppos = end; // 다음 단어의 시작 위치를 기록해 둠
    /*
    TODO: string::substr()을 이용해서 찾은 단어를 발췌해서 별도의 string으로 구성하여 리턴하라.
          mStr의 끝에 도착하여 더 이상 찾을 단어가 없을 경우 "" 문자열을 반환하게 된다.
          발췌할 단어의 길이는 pos와 end의 간단한 계산으로 구할 수 있다. 
    */
}

// 사용자로부터 비교할 단어를 입력받고 메모 문자열에서 
// 해당 단어와 동일한 단어의 출현 회수 same,
// 사전적 순서에서 이 단어보다 앞쪽에 있는 단어의 출현 회수 less, 
// 그리고 이 단어보다 뒤쪽에 있는 단어의 출현 회수 larger를 세어서 각각을 출력한다.
void Memo::compareWord() {
    string next, word = UI::getNext("Word to compare? ");
    int less = 0, same = 0, larger = 0;
    /*
    아래 pos는 getNext(&pos)를 호출할 때 다음 단어를 찾아야 할 시작 위치임
    TODO: for(size_t pos = 0; getNext(&pos)를 호출하여 mStr의 끝까지 반복 수행; )
             위 getNext(&pos)를 호출시 리턴된 다음 단어를 next에 저장한 후
             next가 ""일 경우 mStr의 끝을 의미하므로 for문 종료
             ""가 아닌 경우 찾을 단어인 word와 비교(<, >, ==)하여 
             적절한 less, same, larger 변수의 값을 증가시킨다.
    */
    cout << "less: "   << less   << endl;
    cout << "same: "   << same   << endl;
    cout << "larger: " << larger << endl;
}

===============================================================================
== [문제 3] 실행 결과
=============================================================================== 
...
Menu item number? 3
Word to compare? ex
less: 39
same: 0
larger: 67

...
Menu item number? 3
Word to compare? the
less: 87
same: 9
larger: 10


/******************************************************************************
 * [문제 4]
 ******************************************************************************/
// 4번 메뉴항목(Memo::dispByLine())은 메모 텍스트를 행 번호와 함께 행 단위로 출력해 준다.
// 아래 멤버함수 Memo::get_next_line()와 Memo::dispByLine()의 코드를 완성하고,
// Memo::run()의 func_arr[]에 적절한 항목을 추가하라.
//-----------------------------------------------------------------------------

// 메모의 현 위치(pos = *ppos)에서 그 행의 끝을 찾은 후 행 전체를 별도의 string으로 구성해서 리턴함
// string::npos는 해당 문자를 찾지 못했을 경우의 리턴 값이며 (-1)과 동일 값임
string Memo::get_next_line(size_t* ppos) {
    size_t pos = *ppos, end;

    /*
    TODO: string::find()를 이용해 행의 끝('\n') 위치를 찾아서(현재 행의 시작 위치는 pos임) end에 저장
    */

    // 메모의 끝에 '\n'이 없을 경우: (end == string::npos) 
    end = (end == string::npos)? mStr.length() : end+1; 
    *ppos = end; // 다음 행의 시작 위치를 기록해 둠

    /*
    TODO: 찾은 현재 행을 string::substr()으로 발췌해서 별도의 string으로 구성하여 리턴하라.
          발췌할 단어 길이는 pos와 end로 간단히 계산할 수 있음
    */
}

// 메모 텍스트 mStr를 한 행씩 잘라서 행 번호와 함께 화면에 보여즘; 행 번호는 0부터 시작함
void Memo::dispByLine() {
    cout << "--- Memo by line ---" << endl;
    /*
    아래 pos는 get_next_line(&pos)를 호출할 때 다음 행의 시작 위치임
    TODO: for(size_t pos = 0, ... 문을 이용하여 pos가 mStr의 길이보다 작을 동안 반복 수행
             get_next_line(&pos)를 호출하여 반환된 다음 행 문자열을 line에 저장하고 
             적절한 행 번호와 함께 해당 행(line)을 출력(행번호 출력은 PersonManager::display() 참조)
             행의 끝에 줄바꾸기 문자 '\n'가 없을 경우 endl 출력 (displayMemo() 참조)
    */
    cout << "--------------------" << endl;
}

===============================================================================
== [문제 4] 실행 결과
=============================================================================== 
...
Menu item number? 4
--- Memo by line ---
[0] The Last of the Mohicans
[1] James Fenimore Cooper
[2] Author's Introduction
[3] It is believed that the scene of this tale, and most of the information
[4] necessary to understand its allusions, are rendered sufficiently 
[5] obvious to the reader in the text itself, or in the accompanying notes.
[6] Still there is so much obscurity in the Indian traditions, and so much
[7] confusion in the Indian names, as to render some explanation useful.
[8] Few men exhibit greater diversity, or, if we may so express it, 
[9] greater antithesis of character, 
[10] than the native warrior of North America.
--------------------

/******************************************************************************
 * [문제 4-1]
 ******************************************************************************/
// Memo의 const char* memoData 멤버의 문자열 초기화를 모두 주석처리하고 아래 문장으로 대체하라.
// 그런 후 실행 결과를 확인하고 다시 원상복구하여라.

const char* memoData = "The Last of the Mohicans"; // 행의 끝에 줄바꾸기 문자가 없다.

===============================================================================
== [문제 4-1] 실행 결과
=============================================================================== 
++++++++++++++++++++++ Memo Management Menu +++++++++++++++++++++
+ 0.Exit 1.DisplayMemo 2.FindString 3.CompareWord 4.DispByLine  +
+ 5.DeleteLine 6.RepaceLine 7.ScrollUp 8.ScrollDown 9.InputMemo +
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Menu item number? 4
--- Memo by line ---
[0] The Last of the Mohicans // 행의 끝에 줄바꾸기 문자가 없어도 줄바꾸기 해 주어야 한다.
--------------------


/******************************************************************************
 * [문제 5]
 ******************************************************************************/
// 위 실행 결과를 확인한 후 다시 원래의 const char* memoData = R"(The Last ...로 복구하여라.
// 5번 메뉴항목(Memo::deleteLine())은 삭제하고자 하는 행 번호를 입력받아 그 행을 삭제한다.
// 아래 멤버함수 Memo::find_line()와 Memo::deleteLine()의 코드를 완성하고,
// Memo::run()의 func_arr[]에 적절한 항목을 추가하라.
//-----------------------------------------------------------------------------

// 행번호가 line_num(0부터 시작)인 행을 찾아 행의 시작 위치 *start와 행 길이 *plen를 계산함
// 해당 행 번호를 찾았으면 true, 찾지 못했으면 false 반환
bool Memo::find_line(int line_num, size_t* pstart, size_t* plen) {
    size_t start = 0;

    TODO: for 문을 이용해 line_num번 반복 수행 (0 행에서 line_num-1 행까지 반복)
              string::find()를 이용해 start에서부터 행의 끝('\n')을 찾고, 
              find()의 리턴된 값을 다시 start에 저장
              행의 끝을 찾지 못했을 경우(line_num 행까지 진행하지 못한 경우) 즉,
              find()의 반환된 값 start가 string::npos이면 
                  여기서 false 리턴함 (line_num행을 찾지 못한 경우)
              start 값을 1 증가시켜 다음 행의 시작 위치로 조정
              
    *pstart = start; // line_num 행의 시작 위치를 기록

    TODO: line_num 행의 끝 위치를 찾고, 
          찾았으면 그 행의 길이를 계산하여 *plen에 저장
          찾지 못한 경우 string::npos를 *plen에 저장 /* 예를들어, 실제로 행이 
              [0], [1], [2] 행까지 있는데 [3] 행의 시작(메모의 끝 위치)을 찾을 경우에 해당함 */

    return true; // line_num 행을 찾았다는 것을 의미함
}

// 사용자로부터 삭제할 행 번호를 입력 받은 후 해당 행 전체를 삭제함
void Memo::deleteLine() {
    size_t start, len, line_num = UI::getPositiveInt("Line number to delete? ");

    TODO: 만약 line_num 행을 찾지 못한 경우 
          ( 즉, mStr이 비어 있거나 또는
            find_line(line_num,&start,&len) 호출하여 line_num 행을 못 찾았거나(false) 또는
            찾았지만(true) 행의 시작 위치인 start가 메모 텍스트의 끝인 경우(start == mStr.size()) )  
              "Out of line range" 문장 출력
          line_num 행을 찾은 경우 mStr에서 해당 행을 삭제한 후 dispByLine() 호출
}

===============================================================================
== [문제 5] 실행 결과
=============================================================================== 
...
Menu item number? 4
--- Memo by line ---
[0] The Last of the Mohicans
[1] James Fenimore Cooper
[2] Author's Introduction
...
[8] Few men exhibit greater diversity, or, if we may so express it, 
[9] greater antithesis of character, 
[10] than the native warrior of North America.
--------------------

...
Menu item number? 5
Line number to delete? 11       // 또는 12, 13
Out of line range

...
Menu item number? 5
Line number to delete? 0
--- Memo by line ---
[0] James Fenimore Cooper
[1] Author's Introduction
[2] It is believed that the scene of this tale, and most of the information
...
[7] Few men exhibit greater diversity, or, if we may so express it, 
[8] greater antithesis of character, 
[9] than the native warrior of North America.
--------------------

...
Menu item number? 5
Line number to delete? 9
--- Memo by line ---
[0] James Fenimore Cooper
[1] Author's Introduction
...
[7] Few men exhibit greater diversity, or, if we may so express it, 
[8] greater antithesis of character, 
--------------------

// 또한 모든 행을 반복적으로 모두 지운 후(mStr이 비어 있을 경우) 0 행을 찾을 경우 
// Out of line range가 출력되어야 함

/******************************************************************************
 * [문제 6]
 ******************************************************************************/
// 6번 메뉴항목(Memo::replaceLine())은 교체하고자 하는 행 번호를 입력받고 
// 그 행의 내용을 다른 내용으로 교체하는 역할을 한다.
// 아래 멤버함수 Memo::replaceLine()의 코드를 완성하고,
// Memo::run()의 func_arr[]에 적절한 항목을 추가하라.
//-----------------------------------------------------------------------------

// 교체할 행 번호와 교체할 문자열을 입력 받은 후 해당 행을 입력 받은 행으로 교체함
void Memo::replaceLine() {
    size_t start, len, line_num = UI::getPositiveInt("Line number to replace? ");

    TODO: find_line(line_num, &start, &len) 호출하여 line_num 행을 찾음
          만약 해당 행을 찾지 못한 경우 "Out of line range"를 출력하고 리턴함

    string line = UI::getNextLine("Input a line to replace:\n");

    TODO: 읽은 line의 끝에 '\n'을 추가하라.
          찾은 행을 line 문자열로 교체한 후 dispByLine() 호출
}

===============================================================================
== [문제 6] 실행 결과
=============================================================================== 
...
Menu item number? 4
--- Memo by line ---
[0] The Last of the Mohicans
[1] James Fenimore Cooper
...
[9] greater antithesis of character, 
[10] than the native warrior of North America.
--------------------

...
Menu item number? 6
Line number to replace? 0
Input a line to replace:
THIS IS A REPLACED LINE. // 사용자 입력
--- Memo by line ---
[0] THIS IS A REPLACED LINE.
[1] James Fenimore Cooper
...
[9] greater antithesis of character, 
[10] than the native warrior of North America.
--------------------

Menu item number? 6
Line number to replace? 11   // 주의: 마지막 행 [10]의 다음 행 번호임
Input a line to replace:
11th LINE.
--- Memo by line ---
[0] THIS IS A REPLACED LINE.
[1] James Fenimore Cooper
...
[9] greater antithesis of character, 
[10] than the native warrior of North America.
[11] 11th LINE.             // 맨 끝에 추가하는 것도 가능함
--------------------


/******************************************************************************
 * [문제 7]
 ******************************************************************************/
// 7번 메뉴항목(Memo::scrollUp())은 모든 행을 한 행씩 앞(위)으로 옮기는 역할을 한다. 
// 아래 멤버함수 Memo::scrollUp()의 코드를 완성하고,
// Memo::run()의 func_arr[]에 적절한 항목을 추가하라.
//-----------------------------------------------------------------------------

// 모든 행을 한 행씩 앞으로 옮김 (즉, 첫행을 마지막으로 옮김)
// 즉, 첫 행(행 번호 0)을 삭제한 후 삭제된 행을 맨 마지막에 다시 추가함
void Memo::scrollUp() {
    size_t start, len;

    TODO: find_line()를 이용해 첫 행을 찾음
          mStr의 첫 행을 mStr의 맨 마지막에 추가함
          mStr의 첫 행을 삭제한 후 dispByLine() 호출
}

===============================================================================
== [문제 7] 실행 결과
=============================================================================== 
Menu item number? 4
--- Memo by line ---
[0] The Last of the Mohicans
[1] James Fenimore Cooper
[2] Author's Introduction
...
[8] Few men exhibit greater diversity, or, if we may so express it, 
[9] greater antithesis of character, 
[10] than the native warrior of North America.
--------------------

...
Menu item number? 7
--- Memo by line ---
[0] James Fenimore Cooper
[1] Author's Introduction
[2] It is believed that the scene of this tale, and most of the information
...
[8] greater antithesis of character, 
[9] than the native warrior of North America.
[10] The Last of the Mohicans
--------------------

...
Menu item number? 7
--- Memo by line ---
[0] Author's Introduction
[1] It is believed that the scene of this tale, and most of the information
[2] necessary to understand its allusions, are rendered sufficiently 
...
[8] than the native warrior of North America.
[9] The Last of the Mohicans
[10] James Fenimore Cooper
--------------------


/******************************************************************************
 * [문제 8]
 ******************************************************************************/
// 8번 메뉴항목(Memo::scrollDown())은 모든 행을 한 행씩 뒤로(밑으로) 옮기는 역할을 한다. 
// 아래 멤버함수 Memo::find_last_line()와 Memo::scrollDown()의 코드를 완성하고,
// Memo::run()의 func_arr[]에 적절한 항목을 추가하라.
//-----------------------------------------------------------------------------

// 마지막 행의 시작 위치를 찾아서 반환함
size_t Memo::find_last_line() {
    for (size_t start = 0, pos = 0; true; start = pos) {

        TODO: start 위치 이후로 행 끝을 찾아 pos에 저장 
              행 끝을 못 찾았거나 또는 ++pos가 mStr의 길이와 같으면(마지막 행) start 값 리턴
    }
}

void Memo::scrollDown() {
    size_t last = (find_last_line()을 호출하여 마지막 행의 시작 위치를 찾음)
    size_t len = (last와 mStr의 길이를 이용하여 마지막 행의 길이 계산)
    마지막 행을 서브 string으로 발췌하여 별도 저장
    마지막 행 삭제
    발췌했던 마지막 행을 맨 처음에 삽입한 후 dispByLine() 호출
}

===============================================================================
== [문제 8] 실행 결과
=============================================================================== 
Menu item number? 4
--- Memo by line ---
[0] The Last of the Mohicans
[1] James Fenimore Cooper
[2] Author's Introduction
...
[8] Few men exhibit greater diversity, or, if we may so express it, 
[9] greater antithesis of character, 
[10] than the native warrior of North America.
--------------------

...
Menu item number? 8
--- Memo by line ---
[0] than the native warrior of North America.
[1] The Last of the Mohicans
[2] James Fenimore Cooper
...
[8] confusion in the Indian names, as to render some explanation useful.
[9] Few men exhibit greater diversity, or, if we may so express it, 
[10] greater antithesis of character, 
--------------------

...
Menu item number? 8
--- Memo by line ---
[0] greater antithesis of character, 
[1] than the native warrior of North America.
[2] The Last of the Mohicans
...
[8] Still there is so much obscurity in the Indian traditions, and so much
[9] confusion in the Indian names, as to render some explanation useful.
[10] Few men exhibit greater diversity, or, if we may so express it, 
--------------------


/******************************************************************************
 * [문제 9]
 ******************************************************************************/
// 9번 메뉴항목(Memo::inputMemo())은 메모 텍스트 전체를 새로 입력 받는 일을 수행한다. 
// 아래 멤버함수 Memo::inputMemo()의 코드를 완성하고,
// Memo::run()의 func_arr[]에 적절한 항목을 추가하라.
//-----------------------------------------------------------------------------

/*
In war, he is daring, boastful, cunning, ruthless, self-denying,
and self-devoted; in peace, just, generous, hospitable, revengeful,
superstitious, modest, and commonly chaste.
These are qualities, it is true, which do not distinguish all alike;
but they are so far the predominating traits of these remarkable people
as to be characteristic.
It is generally believed that the Aborigines of the American continent
have an Asiatic origin.

*/
// 사용자로부터 메모 데이타를 행 단위로 입력받아 기존의 mStr에 계속 추가함
// 입력의 끝은 빈 줄을 입력하면 된다. 
void Memo::inputMemo() {

    TODO: 기존 mStr의 문자열을 모두 삭제하고, 크기를 0으로 만듦

    string line;
    cout << "--- Input memo lines, and then input empty line at the end ---" << endl;
    while (true) {

        TODO: getline(cin, line)을 사용하여 키보드로부터 한 줄을 입력 받아 line에 저장
              if (UI::echo_input) cout << line << endl; // 자동체크 때 실행됨
              입력 받은 한 행이 빈 줄이면 리턴함
              입력 받은 행 끝에 "\n"을 추가
              입력 받은 행을 mStr의 끝에 추가
    }
}


===============================================================================
== [문제 9] 실행 결과
== 입력을 종료하고자 할 경우 아무것도 입력하지 않은 채 행 처음에 바로 엔터를 입력하여야 함
=============================================================================== 
Menu item number? 9
--- Input memo lines, and then input empty line at the end ---
In war, he is daring, boastful, cunning, ruthless, self-denying,
and self-devoted; in peace, just, generous, hospitable, revengeful,
superstitious, modest, and commonly chaste.
These are qualities, it is true, which do not distinguish all alike;
but they are so far the predominating traits of these remarkable people
as to be characteristic.
It is generally believed that the Aborigines of the American continent
have an Asiatic origin.

[입력 종료를 위해 위 행은 빈 줄이어야 함] 즉, 행 처음에 바로 엔터를 쳐야함

...
Menu item number? 1
------- Memo -------
In war, he is daring, boastful, cunning, ruthless, self-denying,
and self-devoted; in peace, just, generous, hospitable, revengeful,
superstitious, modest, and commonly chaste.
These are qualities, it is true, which do not distinguish all alike;
but they are so far the predominating traits of these remarkable people
as to be characteristic.
It is generally believed that the Aborigines of the American continent
have an Asiatic origin.
--------------------

/******************************************************************************
 * [문제 10]
 ******************************************************************************/
// 아래처럼 입력하여 메모 텍스트를 완전히 비게 만든 후 (즉, "") 아래 각 메뉴 항목을 테스트해 보라.
//-----------------------------------------------------------------------------
..
Menu item number? 9
--- Input memo lines, and then input empty line at the end ---

[아무것도 입력하지 않은 채 입력 종료를 위해 바로 빈 줄 입력]
...
Menu item number? 1
------- Memo -------
--------------------

...
Menu item number? 2
Word to find? it
Found count: 0

...
Menu item number? 3
Word to compare? it
less: 0
same: 0
larger: 0

...
Menu item number? 4
--- Memo by line ---
--------------------

...
Menu item number? 5
Line number to delete? 0
Out of line range

...
Menu item number? 7
--- Memo by line ---
--------------------

...
Menu item number? 8
--- Memo by line ---
--------------------

...
Menu item number? 6
Line number to replace? 0
Input a line to replace:
Author's Introduction
--- Memo by line ---
[0] Author's Introduction
--------------------


/******************************************************************************
 * [문제 11]
 ******************************************************************************/
// 1) [문제 2] 1)에서 수정한 main() 함수 위의 run()함수를 아래처럼 복구하라.

void run() {
    MainMenu().run();
}

// 2) class CurrentUser의 pUser 멤버 뒤에 아래 멤버를 추가하라.

    Memo    memo; // ch4_3에서 추가

//    또한 기존의 CurrentUser::manageMemo() 함수를 아래 주석과 코드로 대체하라.

// Person 객체에 저장되어 있던 메모 내용을 memo 객체로 복사하고
// 메모 메뉴에서 메모의 추가, 삭제, 교체 등의 조작이 끝나고 나면 (memo.run())
// 반대로 memo에 있던 메모 내용을 다시 Person 객체로 복사한다.
void CurrentUser::manageMemo() { // Menu item 9
    memo.set_c_str(pUser->getMemo());
    memo.run();
    pUser->setMemo(memo.get_c_str());
}

// 위 manageMemo() 함수가 정상적으로 작동하기 위해서는 아래 멤버 변수 및 함수들이 추가되어야 한다.

// 3) Person 클래스 선언부에 기존의 address[60] 멤버 뒤에 아래의 새로운 멤버를 추가하라.
//    이 멤버는 일반 메모를 하나의 문자열로 저장할 수 있는 멤버 변수이다.

    char   memo_c_str[1024]; // 메모장

// 4) Person 클래스의 address 멤버를 위한 setAddress(), getAddress() 함수를 참조하여 
//    아래 메모를 위한 두 멤버 함수를 Person 클래스에 추가하고 적절히 코드를 수정하라.

    void setMemo(const char* c_str)      { TODO: C 스트링 문자열 c_str을 memo_c_str로 복사하라. }

    const char* getMemo()    { TODO: C 스트링 문자열(memo_c_str)를 리턴하라. }

// 5) Person 클래스의 기존 생성자에 memo_c_str 멤버를 초기화하는 코드를 삽입하라.

Person::Person(const string name, int id, double weight, bool married, const char* address):
        ..., married{married}, memo_c_str{} {
    ... // 위 memo_c_str{}는 배열 memo_c_str[]의 모든 원소를 기본 값인 널 문자('\0')로 초기화하는 코드임
}

// 6) Memo 클래스의 클래스 내부에 아래 두 멤버 함수의 코드를 구현하라.

    const char *get_c_str() { TODO: mStr의 C 스트링 문자열(string의 적절한 멤버 함수 호출할 것)을 리턴하라. }

    void set_c_str(const char *c_str) { TODO: C 스트링 문자열 c_str을 Memo 클래스의 mStr에 대입(=)하여 저장하라. }
    // = 연산자의 좌우 데이타 타입이 달라도 C 스트링 문자열인 c_str이 string mStr 내부로 복사된다.


===============================================================================
== [문제 11] 실행 결과
=============================================================================== 

******************************* Main Menu ...
====================== Person Management Menu ...
// 사용자 p0로 로그인할 것; 비번은 없음
+++++++++++++++++++++ Current User Menu ...
...
Menu item number? 9

++++++++++++++++++++++ Memo Management Menu ...
Menu item number? 1       // 초기 메모 내용
------- Memo -------
The Last of the Mohicans
James Fenimore Cooper
Author's Introduction
It is believed that the scene of this tale, and most of the information
necessary to understand its allusions, are rendered sufficiently 
obvious to the reader in the text itself, or in the accompanying notes.
Still there is so much obscurity in the Indian traditions, and so much
confusion in the Indian names, as to render some explanation useful.
Few men exhibit greater diversity, or, if we may so express it, 
greater antithesis of character, 
than the native warrior of North America.
--------------------

++++++++++++++++++++++ Memo Management Menu ...
Menu item number? 9       // 새로 메모 내용 입력
--- Input memo lines, and then input empty line at the end ---
In war, he is daring, boastful, cunning, ruthless, self-denying,
and self-devoted; in peace, just, generous, hospitable, revengeful,
superstitious, modest, and commonly chaste.
These are qualities, it is true, which do not distinguish all alike;
but they are so far the predominating traits of these remarkable people
as to be characteristic.
It is generally believed that the Aborigines of the American continent
have an Asiatic origin.
[엔터]

++++++++++++++++++++++ Memo Management Menu ...
Menu item number? 0     // 메모 메뉴 빠져 나가기; 이 과정에서 메모 내용을 p0 객체에 복사해 둠

+++++++++++++++++++++ Current User Menu ...
Menu item number? 0     // 현재 사용자 메뉴 빠져 나가기

====================== Person Management Menu ===================
= 0.Exit 1.Display 2.Append 3.Clear 4.Login(CurrentUser, ch4)   =
=================================================================
// 다시 p0로 로그인
+++++++++++++++++++++ Current User Menu ...
Menu item number? 9     // 다시 메모 메뉴에 들어가기; 
          // p0 객체에 복사해 두었던 메모를 memo 객체에 복사한 후 memo.run()에 진입

++++++++++++++++++++++ Memo Management Menu +++++++++++++++++++++
+ 0.Exit 1.DisplayMemo 2.FindString 3.CompareWord 4.DispByLine  +
...
Menu item number? 1     // 앞전에 새로 입력했던 메모 내용이 다시 보여야 함
------- Memo -------
In war, he is daring, boastful, cunning, ruthless, self-denying,
and self-devoted; in peace, just, generous, hospitable, revengeful,
superstitious, modest, and commonly chaste.
These are qualities, it is true, which do not distinguish all alike;
but they are so far the predominating traits of these remarkable people
as to be characteristic.
It is generally believed that the Aborigines of the American continent
have an Asiatic origin.
--------------------


/******************************************************************************
 * 자동 오류 체크 모드로 프로그램 실행
 ******************************************************************************/
// 1. clc.chosun.ac.kr의 [강의자료실]에서 CH4_3 과제 테스트 파일을 다운받은 후 
//    압축 파일을 풀고 test 폴더를 드래깅하여 이클립스의 [Project Explorer]의 
//    [CH4_3] 프로젝트 위에 드랍한다. (test 폴더와 그 밑에 테스트용 파일이 있어야 함)
// 2. 기존 프로젝트 CH2의 src 폴드에 있는 check_error.h를 CH4_3 프로젝트의 
//    src 폴더로 복사하라. (파일 선택 후 [Ctrl+C], src 폴더를 선택 후 [Ctrl+V])
// 3. 소스 파일 맨 앞쪽에 있는 AUTOMATIC_ERROR_CHECK 상수 값을 true로 설정하라.
// 4. main() 함수 내의 evaluate(true)가 true로 설정되어 있는지 확인하라.
// 5. 프로그램 테스트를 위한 입출력 파일이 test 폴더에 다운로드 되어 있는지 확인하라.
// 6. 프로그램이 정상적으로 구현되었다면 아래 [프로그램 실행 결과]와 같이 출력될 것이다.

===============================================================================
== 1. 정상적인 프로그램 실행 결과
==    아래 각 테스트 번호는 위 문제 번호와는 관련 없습니다.
=============================================================================== 
test 1 : O
test 2 : O
test 3 : O
test 4 : O
test 5 : O
test 6 : O
test 7 : O
test 8 : O
test 9 : O
test 10 : O
test 11 : O
Good bye!!

===============================================================================
== 2. 비정상적인 경우의 프로그램 실행방법은 CH2의 실습과제 설명의 마지막 부분을 참조하기 바란다.  
=============================================================================== 

/******************************************************************************
 * 프로그램 제출
 ******************************************************************************/
// 1. 중요: 소스 파일 맨 앞쪽에 있는 AUTOMATIC_ERROR_CHECK 상수 값을 false로 설정하라.
// 2. 프로그램을 oj.chosun.ac.kr에 제출하라. 
//-----------------------------------------------------------------------------
```