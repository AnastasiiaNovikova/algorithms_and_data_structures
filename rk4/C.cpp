/*
	Покупка
 У покупателя имеется набор N монет A1 ≤ A2 ≤ ... ≤ AN, каждой монеты ровно по одной штуке.
 Найти наименьшую стоимость предмета, который нельзя купить, используя только эти монеты.
	Input format
	Output format
	Examples
 Input	Output
 5
 1
 2
 4
 8
 16
	32
 */

#include<iostream>

using namespace std;

int main(){
  
    
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        int ai;
        cin >> ai;
        
        if(ans + 1 >= ai){
            ans += ai;
        }else{
            break;
        }
    }
    
    cout << ans + 1;
    return 0;
}
