#include<iostream>
using namespace std;
// HW question for printing sum of all even numbers
int main() {
   int n;
   cin >> n;

   int i=1;
   int sum = 0;

    while(i<=n) {
      sum = sum + i;
      i = i + 2;
    }
    cout<<"Value of sum is : "<<sum<<endl;
 

}