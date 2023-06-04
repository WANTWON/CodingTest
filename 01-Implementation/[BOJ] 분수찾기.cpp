#include <iostream>
using namespace std;
int main() {
    int idx;
    cin >> idx;
    
    int i = 0;
    while(idx>0)
    {
        
        ++i;
        idx -=i;
    }
    
    if(i%2 == 1)
        cout << 1-idx << "/" << i+idx;
    else
        cout << i+idx << "/" << 1-idx;
    return 0;
}
