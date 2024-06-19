#include <bits/stdc++.h>

using namespace std;

int main(){
  cout<<1<<'\n';
  int times = 200000;
  cout<<times<<' '<<times<<'\n';
  for(int i=0;i<times; i++){
    cout<<times<<" \n"[i == times-1];
  }
  for(int i=0;i<times; i++){
    cout<<1<<" \n"[i == times-1];
  }
}
