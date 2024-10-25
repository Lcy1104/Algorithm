#include<bits/stdc++.h>
int main(){
	int a,b,c;
	std::cin>>a>>b;
	c=a%b;
	while(c!=0){
		a=b;
		b=c;
		c=a%b;
	}
	std::cout<<b<<"\n";
	return 0;
} 
