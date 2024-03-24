#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void big(char* first, char* second, int v) 
{
    char sum[101]={'0',};  // 덧셈 저장할 문자열
    char sub[100]={'0',};  // 뺄셈 저장할 문자열
    int carry = 0;  // 올림값을 저장할 변수
    bool nonZeroEncountered = false;// 쓸데없는0이 아닌 값0을 지우지 않기 위해 필요함

    // 덧셈
    for (int i = 99; i >= 0; --i) {
        int x = (first[i] - '0') + (second[i] - '0') + carry;
        sum[i + 1] = (x % 10) + '0';  // 현재 자릿수에 대한 결과를 저장
        carry = x / 10; // 다음 자릿수로 올림
    }
    sum[0] = carry + '0';  // 덧셈에서 100칸을 넘어가는 값이 나올때 사용


    cout << "sum            >>";

    bool firstNonZero = false;
    for(int i = 0; i < 101; i++) {
        if (sum[i] != '0' || firstNonZero) {
            cout << sum[i];
            firstNonZero = true;
        }
    }

    cout << endl;

    // 뺄셈
    carry = 0;
    cout << "sub            >>";

    if(v==1) { // first > second
        for (int i = 99; i >= 0; --i) {
            int y = (first[i] - '0') - (second[i] - '0') - carry;
            carry = 0;
            if (y < 0) {
                carry = 1;
                y += 10;
            }
            sub[i] = y + '0';
        }
    }
    else if(v==2) { // first < second
        for (int i = 99; i >= 0; --i) {
            int y = (second[i] - '0') - (first[i] - '0') - carry;
            carry = 0;
            if (y < 0) {
                carry = 1;
                y += 10;
            }
            sub[i] = y + '0';
        }
        cout << '-';
    }
    else if(v==3) { // first == second
        cout << "0" << endl;
        return;
    }

    firstNonZero = false;
    for(int i = 0; i < 100; i++) {
        if (sub[i] != '0' || firstNonZero) {
            cout << sub[i];
            firstNonZero = true;
        }
    }
    
}

int main() {
    //100칸의 포인터에 0을 집어넣음
    char* first = new char[100];
    memset(first, '0', 100);
    char* second = new char[100];
    memset(second, '0', 100);
    string f;
    string s;
    cout << "First number   >>";
    cin >> f;
    cout << "Second number  >>";
    cin >> s;

    int fl = f.length();
    int sl = s.length();

    //입력받은 문자열을 100칸의 포인터에 넣음
    for (int i = 0; i < fl; ++i) 
    {
        first[i + (100 - fl)] = f[i];
    }

    for (int i = 0; i < sl; ++i) 
    {
        second[i + (100 - sl)] = s[i];
    }

    int v=0;
    //first second 길이 판단
    if(fl > sl ) v=1;
    else if(fl < sl ) v=2;
    else
    {
        for (int i = 0; i < fl; i++) 
        {
            if (f[i] > s[i])
            {
                v=1;
                break;
            } 
            else if (f[i] < s[i]) 
            {
                v=2;
                break;
            }
            else
            {
                v=3;
            }
        }
    }

    big(first, second, v);
   
    

    return 0;
}
