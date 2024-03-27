#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void big(char* first, char* second, int v) 
{
    
    char sum[100]={'0',};  // 덧셈 저장할 문자열
    char sub[100]={'0',};  // 뺄셈 저장할 문자열
    int up = 0;  // 올림값을 저장할 변수
    int down = 0;
    bool zero = false;
    //  덧셈
    
    for (int i = 99; i >= 0; --i) {
        int x = (first[i] - '0') + (second[i] - '0') + up;
        sum[i] = (x % 10) + '0';  // 현재 자릿수에 대한 결과를 저장
        up = x / 10; // 다음 자릿수로 올림
    }

    cout << "Sum            >>" ;
    if (up > 0) 
    {
    cout << '1';
    }

    for(int i = 0; i <= 99; i++)
    {
        if (zero) {
            cout << sum[i];
        } else if (sum[i] >= '0'&& sum[i] <= '9') {
            zero = true;
            cout << sum[i];
        }

    }
    cout << endl;
    
    //뺄셈

    
    zero = false;

    if(v==1)
    {
            for (int k = 99; k >= 0; --k) 
        {
            int y = (first[k] - '0') - (second[k] - '0') + down;
            down=0;
            if(y<0)
            {
                down=-1;
                y=y+10;;
            }
            sub[k] = y + '0';  
            
        }

        cout << "Sub            >>" ;

        for(int k = 0; k <= 99; k++)
        {
            if (zero)
            {
                cout << sub[k];
            } 
            else if (sub[k] != '0') 
            {
                zero = true;
                cout << sub[k];
            }

            
        }

    }

    
    else if(v==2)
    {
            for (int k = 99; k >= 0; --k) 
        {
            int y = (second[k] - '0') - (first[k] - '0') + down;
            down=0;
            if(y<0)
            {
                down=-1;
                y=y+10;;
            }
            sub[k] = y + '0';  
            
        }
        cout << "Sub            >>-" ;

        for(int k = 0; k <= 99; k++)
        {
            if (zero)
            {
                cout << sub[k];
            } 
            else if (sub[k] != '0') 
            {
                zero = true;
                cout << sub[k];
            }
            
        }
    }

    else if(v==3)
    {
        cout << "Sub            >> 0";
    }
    

    
}

int main() {
   

    // 큰 수를 문자열로 표현
    char* first = new char[100];
    memset(first, 0, 100);
    char* second = new char[100];
    memset(second, 0, 100);
    string f;
    string s;
    cout << "First number   >>";
    cin >> f;
    cout << "Second number  >>";
    cin >> s;

    int fl = f.length();
    int sl = s.length();

    for (int i = 0; i < fl; ++i) 
    {
        first[i + (100 - fl)] = f[i];
    }

    for (int i = 0; i < sl; ++i) 
    {
        second[i + (100 - sl)] = s[i];
    }

    int v=0;
    if(fl > sl ) v=1;
    else if(fl < sl ) v=2;
    else
    {
        for (int i = 0; i < fl; i++) 
        {
            if (f[i] > s[i])
            {
            v=1;

            } 
            else if (f[i] < s[i]) 
            {
            v=2;
            }
            else v=3;
        }

        
    }

    // 덧셈 수행
    big(first, second, v);
   
    return 0;
}