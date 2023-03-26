#include<iostream>
using namespace std;

void getDigits(int num,int* ascn, int* desc){
	for(int i=0;i<4;i++){
		ascn[i]=desc[i]=num%10, num/=10;		
	}
}

void orderNum(int* ascn, int* desc, int& num1, int& num2){
	int minInd=0, maxInd=0;

	for(int i=0;i<4;i++){
		
		for(int j=0;j<4;j++){
			if(ascn[j]<ascn[minInd])
				minInd=j;			
			if(desc[j]>desc[maxInd])
				maxInd=j;			
		}

		num1=(num1*10)+ascn[minInd], ascn[minInd]=10;
		num2=(num2*10)+desc[maxInd], desc[maxInd]=-1;
	}
}

bool validator(int num){
	if(num<1 || num>9998){
		return false;
	}
	
	int temp=num%10, count=0;
	while(num>0){	
		if(num%10==temp)
			count++;		
		num/=10;
	}

	return (count==4) ? false : true;
}

// for debugging
void printDigits(int* d){
	for(int i=0;i<4;i++)
		cout<<*(d+i)<<" ";
	cout<<endl;
}

int main(){
	
	const int kap=6174;	
	cout<<"KAPREKAR's NUMBER : "<<kap<<endl;

	int num;	
	cout<<"ENTER 4 DIGIT NUMBER : ", cin>>num;
	cout<<endl;
	
	if(!validator(num)){
		cout<<"INVALID INPUT";
		return 0;
	}

	if(num<1 || num>9998){
		cout<<"INVALID INPUT";
		return 0;
	}
	
	do{
		int digits[4], ascn[4], desc[4];
		getDigits(num, ascn, desc);			

		int num1=0, num2=0;
		orderNum(ascn, desc, num1, num2);
		int diff = num2-num1;

		cout<<num2<<" - "<<num1<<" = "<<diff<<endl;
		num=diff;
			
	}while(num!=kap);

	return 0;
}
