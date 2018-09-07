#include <iostream>

using namespace std;

//Problem 1

bool checkTemp(int curr,int* tem);
void checkPes(int curr,int& max,int* min, bool& alar);    
void checkHum(int curr,int* max,int* min, bool* alar);

void problem1 () 
{
	int humdity [2] = {0 ,0};
	int temp [2] = {0,0};
	int press [2] = {0,0};
	int current_reading[3] = {0,0,0}; 
	bool alarm = false;

	for (int i = 0;i<50;i ++) //menu display 
	{
		cout <<"~"; 
	}
	cout<<"\n WELCOME TO DATA CENTER \n"; //menu display 
	for (int i = 0;i<50;i ++) //menu display
	{
		cout <<"~"; 
	}
	cout<<endl;
	cout<<"Please enter maximum limit of temperature: "; 
	cin>>temp[0]; cout<<endl;
	cout<<"Please enter minimum limit of temperature: "; 
	cin>>temp[1]; cout<<endl;

	cout<<"Please enter maximum limit of pressure: "; 
	cin>>press[0]; cout<<endl;
	cout<<"Please enter minimum limit of pressure: "; 
	cin>>press[1]; cout<<endl;

	cout<<"Please enter maximum limit of humidity: "; 
	cin>>humdity[0]; cout<<endl;
	cout<<"Please enter minimum limit of humidity: "; 
	cin>>humdity[1]; cout<<endl;

	bool terminator = false; 
	char inp;
	while (terminator != true) {
		cout<<"Please enter current reading of temperature: "; 
		cin>>current_reading[0]; cout<<endl;
		cout<<"Please enter current reading of pressure: "; 
		cin>>current_reading[1];cout<<endl;
		cout<<"Please enter current reading of humidity: "; 
		cin>>current_reading[2];cout<<endl;

		alarm = checkTemp(current_reading[0],temp); 
		checkPes(current_reading[1],press[0],&press[1], alarm); 
		checkHum(current_reading[2], &humdity[0], &humdity[1], &alarm);

		if (alarm == true) 
		{
			cout<<"Alarm is on"<<endl; 
		}
		else        
		{
			cout <<"All is well"<<endl;
		}

		cout<<"enter 'c' to continue and 'e' to exit "; 
		cin>>inp;cout<<endl;

		if (inp == 'e') 
		{
			terminator = true; 
		}
		else if(inp == 'c') 
		{
      continue;
		}
		else
		{
			cout<<"You entered wrong input, program terminated"<<endl; 
			terminator = true;
		} 
	}
}


bool checkTemp(int curr,int* tem) 
{
    // Write your code
	if(curr>tem[0] || curr<tem[1]){
		return true;
	}
	return false;
}

void checkPes(int curr, int &max, int *min, bool &alar)
{
	// Write your code 
	if(curr>max || curr < *min){
		alar=true;
	}
}

void checkHum(int curr, int* max, int* min, bool* alar)
{
	// Write your code 
	if(curr > *max || curr < *min){
		*alar = true;
	}
}

//Problem 2

int* combine(int* a1, int* a2, int sizea1 ,int sizea2 ,	int* final)
{
	int sizef = sizea1 + sizea2;
	final = new int[sizef];

	for(int i = 0; i<sizea1 ;i++)
	{
		final[i]=a1[i];
	}
	for(int i = 0; i<sizea2; i++)
	{
		final[sizea1+i]=a2[i];
	}
	return final;
}

void problem2(){
	int* final;
	int a[] = {1,2,3,4,5};
	int b[] = {7,8,9,0};
	int sizea1 = sizeof(a)/4;
	int sizea2 = sizeof(b)/4;
	int* finals=combine(a,b,sizea1,sizea2,final);
	for(int i =0 ; i<9;i++)
	{
		cout << finals[i] << endl;
	}
}

//Problem 3

void problem3()
{
	int arr[64];
	int* p=arr;

}

int main(){
//  problem1();
//	problem2();
	problem3();
}

