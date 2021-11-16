#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int N;
long long cnt;
void hanoi(int n,int from,int tmp,int to){
//	default case
	if(n==1){
//		cout<<"he0llo\n";
		cout<<from<<" "<<to<<"\n";
	}else{
//	
		hanoi(n-1,from,to,tmp);
//		cout<<"hello\n";
		cout<<from<<" "<<to<<"\n";
		hanoi(n-1,tmp,from,to);
	}
}
int main(void){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin>>N;
	string ans=to_string(pow(2,N));
	int idx=ans.find('.');
	ans=ans.substr(0,idx);
	ans[ans.length()-1]-=1;
	cout<<ans.c_str()<<"\n";
	if(N<=20) hanoi(N,1,2,3);
	
	}
