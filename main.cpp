#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <set>
#include <ctime>
#include <unordered_map>
#include <map>
#include <fstream>
using namespace std;

struct l
{
	int value = 0 ;
	l * next	= NULL;
	l * parent 	= NULL;
	multimap<int,l*>::iterator it;
	l(int x)
	{
		value =x;
	}
};

struct r
{
	int value = 0 ;
	r * next	= NULL;
	r * parent 	= NULL;
	r(int x)
	{
		value =x;
	}
	multimap<int,r*>::iterator it;
};



struct ma
{
	double value = 0;
	l * left 	= NULL;
	r * right	= NULL;
	l * l_end 	= NULL;
	r * r_end 	= NULL;
	bool init 	= false;
	bool mid 	= false;
	int status = 0 ;

};





int main ()
{

	multimap <int , l* , greater <int>> left  ;
	multimap <int , r* > right ;
	int n = 0;
	cin>>n;
	char x =' ';
	int y =0;
	ma midian;
	bool flag1 = true ;
	int tempint =0;
	char temp;
	 vector<char> s;
	 vector<int> xx;
	 for(int i = 0; i < n; i++)
	 {
	 cin >> temp >> tempint;
	 s.push_back(temp);
	 xx.push_back(tempint);
	 }
	for(int i = 0 ; i < n ; i ++)
	{



		x = s[i];
		y = xx[i];
		if(x=='a')
		{
			if(!midian.init)
			{
				midian.value 	= y;
				midian.init 	= true;
				midian.mid		= true;
				midian.status = 0;
			}
			else
			{
				if(y < (midian.value))
				{
					midian.mid=!midian.mid;
					midian.status = 1;
					if(midian.l_end)
					{
						flag1 = false;
						if((midian.l_end->value)>=y)
						{
							flag1 = true ;
							l * b = new l (y);
							b->parent=midian.l_end;
							midian.l_end->next=b;
							midian.l_end= b;
							pair <int,l*> my_pair (y,b);
							auto x = left.emplace_hint(left.begin(),my_pair);
							b->it=x;
						}
						if(!flag1)
						{
							auto x = left.find(y);
							if(x!=left.end())
							{
								l * b = x->second;
								l * c = new l (y);
								if(b==midian.left)
								{
									midian.left=c;
								}
								c->next		= b;
								if(b->parent)
								b->parent->next = c ;
								c->parent 	= b->parent;
								b->parent   	= c ;
								pair <int,l*> my_pair (y,c);
								auto s = left.emplace_hint(b->it,my_pair);
								c->it=s;
							}
							else
							{

								if(midian.left->value<y)
								{
									l * b = new l (y);
									b->next = midian.left;
									midian.left->parent= b;
									pair <int,l*> my_pair (y,b);
									auto s =left.emplace_hint(midian.left->it,my_pair);
									b->it=s;
									midian.left=b;
								}
								else
								{
									auto x = left.rbegin();
									while(x!=left.rend())
									{
										if(x->first > y)
										{
											l * b = (x->second);
											l * c = new l (y);
											c->next		= b->next;
											b->next->parent = c ;
											c->parent 	= b;
											b->next   	= c ;
											pair <int,l*> my_pair (y,c);
											auto s = left.emplace_hint(b->it,my_pair);
											c->it=s;
											break;
										}
										else
										{
											x++;
										}

									}
								}
							}


						}

					}
					else {
						l * c = new l (y);
						midian.left	= c;
						midian.l_end= c;
						pair <int,l*> my_pair (y,c);
						auto s = left.insert(my_pair);
						c->it=s;
					}
				}
				else if(y>midian.value)
				{
					midian.mid=!midian.mid;
					midian.status = 2;
					if(midian.r_end)
					{
						flag1 = false;
						if((midian.r_end->value)<=y)
						{
							flag1 = true ;
							r * b = new r (y);
							b->parent=midian.r_end;
							midian.r_end->next=b;
							midian.r_end= b;
							pair <int,r*> my_pair (y,b);
							if(midian.r_end->value==y)
							{
								auto ret = right.equal_range(y);
								auto x = right.emplace_hint(ret.second,my_pair);
								b->it=x;
							}
							else
							{
								auto x = right.insert(right.begin(),my_pair);
								b->it=x;
							}


						}
						if(!flag1)
						{
							auto x = right.find(y);
							if(x!=right.end())
							{
								r * b = x->second;
								r * c = new r (y);
								c->next		= b->next;
								if(b->next)
								b->next->parent = c ;
								c->parent 	= b;
								b->next   	= c ;
								pair <int,r*> my_pair (y,c);
								auto s = right.insert(c->next->it,my_pair);
								c->it=s;
							}
							else
							{
								if(midian.right->value>y)
								{
									r * b = new r (y);
									b->next = midian.right;
									midian.right->parent= b;
									pair <int,r*> my_pair (y,b);
									auto s =right.emplace_hint(midian.right->it,my_pair);
									b->it=s;
									midian.right=b;
								}
								else
								{
									auto x = right.rbegin();
									while(x!=right.rend())
									{
										if(x->first < y)
										{
											r * b = (x->second);
											r * c = new r (y);
											c->next		= b->next;
											b->next->parent = c;
											c->parent 	= b;
											b->next   	= c ;

											pair <int,r*> my_pair (y,c);
											auto s = right.emplace_hint(b->it,my_pair);
											c->it=s;
											break;
										}
										else
										{
											x++;
										}
									}
								}
							}


						}

					}
					else {
						r * c = new r (y);
						midian.right= c;
						midian.r_end= c;
						pair <int,r*> my_pair (y,c);
						auto s = right.insert(my_pair);
						c->it=s;
					}

				}
				else // y == midian
				{
					midian.status = 0;
					if(midian.mid)
					{
						midian.mid=false ;
						if(midian.left)
						{
							l * b = new l (y);
							b->next = midian.left;
							midian.left->parent= b;
							pair <int,l*> my_pair (y,b);
							auto s =left.emplace_hint(midian.left->it,my_pair);
							b->it=s;
							midian.left=b;
						}
						else
						{
							l * c = new l (y);
							midian.left	= c;
							midian.l_end= c;
							pair <int,l*> my_pair (y,c);
							auto s = left.insert(my_pair);
							c->it=s;
						}
						if(midian.right)
						{
							r * bb = new r (y);
							bb->next = midian.right;
							midian.right->parent= bb;
							pair <int,r*> my_pair1 (y,bb);
							auto ss =right.emplace_hint(midian.right->it,my_pair1);
							bb->it=ss;
							midian.right=bb;
						}
						else
						{
							r * c = new r (y);
							midian.right= c;
							midian.r_end= c;
							pair <int,r*> my_pair (y,c);
							auto s = right.insert(my_pair);
							c->it=s;
						}
					}
					else
					{
						midian.mid=true;
					}

				}
			}
			if(midian.status == 1)
			{
				if(midian.mid)
				{
					midian.value = midian.left->value;
//					midian.left = midian.left->next;
					if(midian.left->next)
						midian.left->next->parent=NULL;
//					cout << "><><><>< "<<midian.left->it->first <<endl;
					left.erase(midian.left->it);
					if(midian.left==midian.l_end)
					{
						midian.l_end = NULL;
						midian.left  = NULL;
					}
					else
					{
						midian.left=midian.left->next;
					}
//					midian.mid=!midian.mid;
					printf("%.f\n",midian.value);
				}
				else
				{
					r * b = new r (midian.value);
					b->next = midian.right;
					pair <int,r*> my_pair (midian.value,b);
					if(midian.right)
					{
						midian.right->parent= b;
						auto s =right.emplace_hint(midian.right->it,my_pair);
						b->it=s;
					}
					else
					{
						midian.r_end = b ;
						auto s =right.insert(my_pair);
						b->it=s;
					}

					midian.right=b;
					long long int  o =(long long int) midian.right->value +(long long int) midian.left->value;
					midian.value=o/2.0;
					if(abs(o)%2==1)
					{
						printf("%.1f\n" , o/2.0);
					}
					else {
						printf("%.f\n" , (o/2.0));
					}


				}
			}
			else if(midian.status == 2)
			{
				if(midian.mid)
				{
					midian.value = midian.right->value;
//					midian.right = midian.right->next;
					if(midian.right->next)
						midian.right->next->parent=NULL;
					right.erase(midian.right->it);
					if(midian.right==midian.r_end)
					{
						midian.r_end = NULL;
						midian.right  = NULL;
					}
					else
					{
						midian.right=midian.right->next;
					}
//					midian.mid=!midian.mid;
					printf("%.f\n",midian.value);
				}
				else
				{
					l * b = new l (midian.value);
					b->next = midian.left;
					pair <int,l*> my_pair (midian.value,b);
					if(midian.left)
					{
						midian.left->parent= b;
						auto s =left.emplace_hint(midian.left->it,my_pair);
						b->it=s;
					}
					else
					{
						midian.l_end = b;
						auto s =left.insert(my_pair);
						b->it=s;
					}
					midian.left=b;
					long long int  o =(long long int) midian.right->value +(long long int) midian.left->value;
					midian.value=o/2.0;
					if(abs(o)%2==1)
					{
						printf("%.1f\n" , o/2.0);
					}
					else {
						printf("%.f\n" , (o/2.0));
					}

				}
			}
			else if (midian.status == 0)
			{
				printf("%.f\n",midian.value);
			}


		}
		else if (x=='r')
		{
			if(!midian.init)
			{
				printf("Wrong!\n");
				continue;
			}
			if(midian.mid)
			{
				if(midian.value==y)
				{
//					printf("kmlasd\n");
					midian.mid=false;
					if((midian.right)&&(midian.left))
					{
//						cout<<"right "<<midian.right->value<<endl;
//						cout<<"left "<<midian.left->value<<endl;
//						cout<<"sum " <<(long long int)midian.right->value + midian.left->value<< endl;
						long long int  o =(long long int) midian.right->value +(long long int) midian.left->value;
//						cout<<o;
						midian.value=o/2.0;
						if(abs(o)%2==1)
						{
							printf("%.1f\n" , o/2.0);
						}
						else {
							printf("%.f\n" , (o/2.0));
						}
						continue;
					}
					else
					{
						midian.init=false;
						printf("Wrong!\n");
						continue;
					}
				}
			}
			if(midian.value >= y)
			{
				if(midian.left)
				{
					if(midian.left->value == y)
					{
						if(midian.left->next)
						midian.left->next->parent=NULL;
						left.erase(midian.left->it);
						if(midian.left==midian.l_end)
						{
							midian.l_end = NULL;
							midian.left  = NULL;
						}
						else
						{
							midian.left=midian.left->next;
						}
						midian.mid=!midian.mid;

					}
					else if(midian.l_end->value == y)
					{
						left.erase(midian.l_end->it);
						if(midian.l_end->parent)
							{
							midian.l_end=midian.l_end->parent;
							midian.l_end->next=NULL;
							}
						else
							{
							midian.l_end=midian.left;
							midian.l_end->next=NULL;
							}
						midian.mid=!midian.mid;

					}
					else
					{
						auto vv = left.find(y);
						if(vv!=left.end())
						{

							if(vv->second->parent)
							{
								vv->second->parent->next = vv->second->next;
							}
							if(vv->second->next)
							{
								vv->second->next->parent = vv->second->parent;
							}

							left.erase(vv);
							midian.mid=!midian.mid;
						}
						else
						{
							printf("Wrong!\n");
							continue;
						}
					}
				}
				else
				{
					printf("Wrong!\n");
					continue;
				}
				if(midian.mid)
				{
					if(midian.right==midian.r_end)
					{
						midian.r_end = midian.right->next;
					}
					right.erase(midian.right->it);
					if(midian.right->next)
					midian.right->next->parent=NULL;
					midian.value = midian.right->value;
					midian.right = midian.right->next;
					printf("%.f\n",midian.value);
				}
				else
				{
					l * b = new l (midian.value);
					if(!midian.l_end)
						midian.l_end=b;
					b->next=midian.left;
					if(midian.left)
						midian.left->parent= b ;
					midian.left=b;
					pair <int,l*> my_pair (b->value,b);
					auto c = left.emplace_hint(left.begin(),my_pair);
					b->it=c;
					long long int  o =(long long int) midian.right->value +(long long int) midian.left->value;
					midian.value=o/2.0;
					if(abs(o)%2==1)
					{
						printf("%.1f\n" , o/2.0);
					}
					else {
						printf("%.f\n" , (o/2.0));
					}

				}
			}

			else if(midian.value < y)
			{
				if(midian.right)
				{
					if(midian.right->value == y)

				{
					if(midian.right->next)
					midian.right->next->parent=NULL;
					right.erase(midian.right->it);
					if(midian.right==midian.r_end)
					{
						midian.r_end = NULL;
						midian.right  = NULL;
					}
					else
					{
						midian.right=midian.right->next;
					}
					midian.mid=!midian.mid;

				}
				else if(midian.r_end->value == y)
				{
					right.erase(midian.r_end->it);
					if(midian.r_end->parent)
					{
						midian.r_end=midian.r_end->parent;
						midian.r_end->next =NULL;
					}
					else
					{
						midian.r_end=midian.right;
						midian.r_end->next=NULL;
					}
					midian.mid=!midian.mid;

				}
				else
				{
					auto vv = right.find(y);
					if(vv!=right.end())
					{
						if(vv->second->parent)
						{
							vv->second->parent->next = vv->second->next;

						}
						if(vv->second->next)
						{
							vv->second->next->parent = vv->second->parent;
						}
						right.erase(vv);
						midian.mid=!midian.mid;
					}
					else
					{
						printf("Wrong!\n");
						continue;
					}
				}
			if(midian.mid)
			{
				if(midian.left==midian.l_end)
				{
					midian.l_end = midian.left->next;
				}
				left.erase(midian.left->it);
				if(midian.left->next)
				midian.left->next->parent=NULL;
				midian.value = midian.left->value;
				midian.left = midian.left->next;
				printf("%.f\n",midian.value);
			}
			else
			{
				r * b = new r (midian.value);
				b->next=midian.right;
				if(!midian.r_end)
					midian.r_end=b;
				if(midian.right)
					midian.right->parent= b ;
				midian.right=b;
				pair <int,r*> my_pair (b->value,b);
				auto c = right.emplace_hint(right.begin(),my_pair);
				b->it=c;
				long long int  o =(long long int) midian.right->value +(long long int) midian.left->value;
				midian.value=o/2.0;
				if(abs(o)%2==1)
				{
					printf("%.1f\n" , o/2.0);				}
				else {
					printf("%.f\n" , (o/2.0));
				}
			}


			}
						else
						{
							printf("Wrong!\n");
							continue;
						}
			}

		}



	}
	return 0 ;


}
