#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int problem1(int hardness,float ccontent,int tensiles){
	if(hardness>50){
		if(ccontent < 0.7){
			if(tensiles > 5600){
				return 10;
			}
			else return 9;
		} else{
			if(tensiles > 5600){
				return 7;
			} else return 6;
		}
	} else {
		if(ccontent < 0.7){
			if(tensiles > 5600){
				return 8;
			}
			else return 6;
		} else {
			if(tensiles > 5600){
				return 6;
			} else return 5;
		}		
	}
}

void problem2(){
	srand((unsigned)time(0));
	int FrogPrime = 0;
	int Frogatron = 0;
	int rint;
	int jump =1;
	while (Frogatron<1000 && FrogPrime < 1000){
		rint = rand()%100;
		if(rint<2) FrogPrime += 5; else FrogPrime += 4;
		rint = rand()%100;

		Frogatron += 4;

		if(FrogPrime >= 1000 || Frogatron >= 1000) break;

		FrogPrime -= 1;

		if(rint >= 2) Frogatron -= 1;

		if(jump%50==0) cout << FrogPrime << "  " << Frogatron << endl;
		jump += 1;
	}
	if(Frogatron>=1000){
		if(FrogPrime>=1000){
			cout << "draw " << FrogPrime << "  " << Frogatron;
		} else cout << "Frogatron won " << FrogPrime << "  " << Frogatron;
	} else cout << "FrogPrime won " << FrogPrime << "  " << Frogatron;
}

bool isprime(int n){
	if(n<2){
		return false;
	}
	for(int i =2;i<n; i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}

void problem3(){
	for(int i = 2;i<=100;i++){
		if(isprime(i)){
			cout << i << endl;
		}
	}
}

int fibonacci(int n){
	if(n==1 || n==2) return 1;
	return fibonacci(n-1)+fibonacci(n-2);
}

void problem4(int n){
	int printcount = 0;
	int count=0;
	int a;
	while(true){
		count += 1;
		a=fibonacci(count);
		if (isprime(a)){
			cout << a <<endl;
			printcount += 1;
		}
		if(printcount >= n){
			break;
		}
	}
}

int main(){
	cout << problem1(40,0.8,4000);
	problem2();
	problem3();
	problem4(5);
	return 0;
}

