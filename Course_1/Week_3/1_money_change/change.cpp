#include <iostream>
#include <cassert>

using namespace std;

int get_change(int m) {
  //write your code here
   int n = 0;
   if(m<0) cout << "No exchange! Amount of money can't be bellow zero<0 " << endl;
   else if(m==0) n = 0;
   else{
      if(m%10==0) n = m/10;
      else if(m%5==0) {
         m = m - 5;
         n++;
         n += m/10; 
      }
      else{
         if((m%10) > 5){
            while((m%10) > 5){
	             m = m - 1;
               n++;
	          }
            m = m - 5;
            n++;
            n += m/10;	
	       }
         else{
	    while((m%10) > 0){
               m = m - 1;
               n++;
            } 
            n += m/10;
         }
      }
   }   
   return n;
}

void test(){
   assert(get_change(2) == 2);
   assert(get_change(28) == 6);
   cout << "OK!" << endl;
}

int main() {
//  test();
    int m;
    cin >> m;
    cout << get_change(m) << '\n';
}
