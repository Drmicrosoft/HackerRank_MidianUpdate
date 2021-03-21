#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <set>
#include <ctime>
#include <fstream>

using namespace std;

//
//
//bool func (int x)
//{
////	cout<<x<<endl;
//	x=x+10;
//	return 0;
//}
//
//bool func1 (int x)
//{
//	if(x==10)
//	return 0;
//	else
//	return 1;
//}
//bool func2 (int x)
//{
//	while(x)
//	{
//		x--;
//	}
//	return 0;
//}
//struct l
//
//{
//    long long int value;
//    l * next = NULL;;
//    l * parent = NULL;
//    l (int x)
//    {
//                value = x;
////                parent = NULL:
////                next = NULL:
//    }
//};
//
//
//struct Node
//{
//  long long int value ;
//  l * left;
////  r * right;
//  int l_num=0;
//  int r_num=0;
//  bool init=false;
//  bool mid = false;
//  l * left_end;
////  r * right_end;
//}m;

int main  ()
{
	int num = 0 ;
	ifstream infile;
	infile.open("/home/omarokasha/Documents/sol_wrong1.txt");
	ifstream infile1;
	infile1.open("/home/omarokasha/Documents/eclipse_output.txt");
	string omar ;
	string omar2 ;
	int ga ;
	ifstream infile2;
	infile2.open("/home/omarokasha/Documents/wrong1.txt");
	string omar3;
	ofstream onfile2;
	onfile2.open("/home/omarokasha/Documents/result1.txt");

	string omar4;
	int i = 0;
	cout<<fixed;
	while ((infile>>omar)&&(infile1>>omar2))
	{
		infile2>>omar3>>omar4;

		cout<<i<<" > "<<omar3<<" > "<<omar4<<endl;
		if(omar!="Wrong!")
		{
			if(stof(omar)==stof(omar2))
				{
				cout<< i << " " << omar << " " <<stof(omar2) <<" " <<num<<endl;
				onfile2<< i << " " << omar << " " <<stof(omar2) <<endl;
				}
		else
			{
			cout<< i << " <> wrong " << omar << " " <<omar2 <<" " <<num<<endl;
			onfile2<< i << " <> wrong " << omar << " " <<omar2 <<endl;
			num ++;
			}
		}
		else
		{
			cout<< i << " " << omar << " " <<omar2 <<" " <<num <<endl;
			onfile2<< i << " " << omar << " " <<omar2 <<endl;
		}
		i++;
//		if(i%1000==0)
//		{
//			cin>>ga ;
//		}
	}
	cout<<"omar errors are " << num<<endl;
}
/*
int main ()
{
	cout<<fixed;
	float times =0;
	float current;
//	for(int j = 0 ; j < 10 ; j++)
	{
	const clock_t begin_time = clock();


	int x = 0;
	int y = 0;
	int z = 0;
	current = float( clock () - begin_time ) /  CLOCKS_PER_SEC;
	times = times + current;
    cout<< ">> " <<x<<" Initialize ** Time >> "<<current << "\t Total = "<< times <<endl;
    const clock_t begin_time1 = clock();


	 x = 0;
	 y = 0;
	 z = 0;
	 current = float( clock () - begin_time1 ) /  CLOCKS_PER_SEC;
	 times = times + current;
	 cout<< ">> " <<x<<" Change V ** Time >> "<<current << "\t Total = "<< times <<endl;
	const clock_t begin_time2 = clock();


	l * omar = new l (5);
	current = float( clock () - begin_time2 ) /  CLOCKS_PER_SEC;
	times = times + current;
	cout<< ">> " <<x<<" Structs Dec** Time >> "<<current << "\t Total = "<< times <<endl;
	const clock_t begin_time3 = clock();

	for(int i =0 ; i < 100000 ; i++)
	l * omarasdasdasdasdad = new l (5);
	current = float( clock () - begin_time3 ) /  CLOCKS_PER_SEC;
	times = times + current;
	cout<< ">> " <<x<<" 1>FOR init struct ** Time >> "<<current << "\t Total = "<< times <<endl;
	const clock_t begin_time5 = clock();

	for(int i =0 ; i < 100000 ; i++)
	{
	l * omarasdasdasdasdad = new l (5);
	omarasdasdasdasdad=omar;
	omarasdasdasdasdad->next=omar;
	omarasdasdasdasdad->parent = omar;
	}
	current = float( clock () - begin_time5 ) /  CLOCKS_PER_SEC;
	times = times + current;
	cout<< ">> " <<x<<" 2>FOR Full Operation ** Time >> "<<current << "\t Total = "<< times <<endl;
	const clock_t begin_time6 = clock();

	for(int i =0 ; i < 100000 ; i++)
	{
		l * omarasdasdasdasdad = new l (5);
		omarasdasdasdasdad->value=1000000;
	}
	current = float( clock () - begin_time6 ) /  CLOCKS_PER_SEC;
	times = times + current;
	cout<< ">> " <<x<<" 3>FOR Struct Set value ** Time >> "<<current << "\t Total = "<< times <<endl;


	const clock_t begin_time7 = clock();

	for(int i =0 ; i < 100000 ; i++)
	{
		m.init=1;
		m.value=5;
		m.left=omar;
	}
	current = float( clock () - begin_time7 ) /  CLOCKS_PER_SEC;
	times = times + current;
	cout<< ">> " <<x<<" 4>M>F ** Time >> "<<current << "\t Total = "<< times <<endl;

//	cin>>m.value;
	const clock_t begin_time8 = clock();

	for(int i =0 ; i < 100000 ; i++)
	{
//		cout<<"help " << m.value<<endl;
		func1(m.value);
	}
	current = float( clock () - begin_time8 ) /  CLOCKS_PER_SEC;
	times = times + current;
	cout<< ">> " <<x<<" 5>if else ** Time >> "<<current << "\t Total = "<< times <<endl;
//	cin>>m.value;
	const clock_t begin_time9 = clock();

	for(int i =0 ; i < 100000 ; i++)
	{
//		printf("help %d\n" , m.value);
		func2(m.value);
//		cout<<current<<endl;
	}
	current = float( clock () - begin_time9 ) /  CLOCKS_PER_SEC;
	times = times + current;
	cout<< ">> " <<x<<" 5>while ** Time >> "<<current << "\t Total = "<< times <<endl;


	const clock_t begin_time10 = clock();

	for(int i =0 ; i < 100000 ; i++)
	{
//		printf("help %d\n" , m.value);
		func(m.value);
	}
	current = float( clock () - begin_time10 ) /  CLOCKS_PER_SEC;
	times = times + current;
	cout<< ">> " <<x<<" 6>func ** Time >> "<<current << "\t Total = "<< times <<endl;

	const clock_t begin_time4 = clock();

	if(omar)
	l * omar1 = new l (5);
	current = float( clock () - begin_time4 ) /  CLOCKS_PER_SEC;
	times = times + current;
	cout<< ">> " <<x<<" ADDING** Time >> "<<current << "\t Total = "<< times <<endl;

	}
    return 0;



}
*/
