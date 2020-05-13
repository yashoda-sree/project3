#include<iostream>
using namespace std;
int i=0,j=0,p=0,q=0,n=0,g=0,h=0;
struct addr{
	string time;
	string date;
	string name;
	string place;
	string duration;
	string note; 
};
struct addr record[1000];
int addrecord()
{
	char c;
				cout<<"                 ********************************\n";
				cout<<"                 ******WELCOME TO ADD MENU*******\n";
				cout<<"                 ********************************\n\n\n";
				cout<<"enter date of your record (dd-mm-yyyy) : ";
				cin>>record[i].date;
				cin.get();
				cout<<"enter time :{hh:mm} : ";
				getline(cin,record[i].time);
				cout<<"enter name : ";
				getline(cin,record[i].name);
				cout<<"enter place : ";
				getline(cin,record[i].place);
				cout<<"enter duration : ";
				getline(cin,record[i].duration);
				cout<<"NOTE : ";
				getline(cin,record[i].note);
				cout<<"    your record is added  :)\n";
				i++;
				cout<<"do you want to add another record? (y/n) : ";
				cin>>c;
				if(c=='y')
				{
					addrecord();
				}
				return 0;
}
int view()
{
	int v;
	char a;
	string date_p,time_p;
	cout<<"how would you like to view :\n1.whole record of the day\n2.record of fixed time\n";
				cin>>v;
				if(v==1)
				{
					cout<<"enter date:{dd-mm-yyyy} : ";
					cin>>date_p;
					for(int k=0;k<=i;k++)
					{
						if(record[k].date==date_p)
						{
							cout<<"\nwhole record of  "<<record[k].date<<" is :";
							cout<<"\nTIME : "<<record[k].time<<endl;
							cout<<"name : "<<record[k].name<<endl;
							cout<<"place : "<<record[k].place<<endl;
							cout<<"duration : "<<record[k].duration<<endl;
							cout<<"NOTE of the record : "<<record[k].note<<endl;
							h=1;
						}
					}
				}
				else 
				{
					if(v==2)
					{
						cout<<"enter time: { hh:mm} : ";
						cin>>time_p;
						for(int k=0;k<=i;k++)
						{
							if(record[k].time==time_p)
							{
							cout<<"\nwhole record of  "<<record[k].time<<" is :";
							cout<<"\nDATE : "<<record[k].date<<endl;
							cout<<"name : "<<record[k].name<<endl;
							cout<<"place : "<<record[k].place<<endl;
							cout<<"duration : "<<record[k].duration<<endl;
							cout<<"NOTE of the record : "<<record[k].note<<endl;
							h=1;
							}
						}	
					}
					else
					{
					cout<<"invalid input"<<endl;
					view();
					}
				}
				if(!h)
				cout<<"no such record\n";
					cout<<"WOULD YOU LIKE TO VIEW AGAIN : {y/n} ";
					cin>>a;	
					if(a=='y')
					view();
					else
					return 0;
}
int viewrecord(string password)
{
	string b;	
	if(j>=3)
	{
		cout<<"access denied\n";
		return 0;
	}
	else
	{
			cout<<"enter correct password : ";
			cin>>b;
			if(b==password && j<3)
			{
				cout<<"access granted\n";
				view();
				j=0;
			}
			else
			{
					j++;
					cout<<"incorrect password\n";
					viewrecord(password);
			}
	}
		return 0;							
}
int edit()
{
	int choice,c=0;
	string time_p,newly;
	cout<<"enter time of the record you want to edit {hh:mm} :";
	cin>>time_p;
	for(int k=0;k<=i;k++)
	{
		if(record[k].time==time_p)
		{
			cout<<"\nwhole record of  "<<record[k].time<<" is :";
			cout<<"\nDATE : "<<record[k].date<<endl;
			cout<<"name : "<<record[k].name<<endl;
			cout<<"place : "<<record[k].place<<endl;
			cout<<"duration : "<<record[k].duration<<endl;
			cout<<"NOTE of the record : "<<record[k].note<<endl;
			cout<<"which aspect you would like to change : \n1.time\n2.date\n3.name\n4.place\n5.duration\n6.note\n7.quit\n";
			cout<<"enter your choice : ";
			cin>>choice;
			switch(choice)
			{
				case 1:{
					cout<<"enter time : {hh::mm}  ";
					cin>>newly;
					record[k].time=newly;
					break;
				}
				case 2:{
					cout<<"enter date : {dd-mm-yyyy} ";
					cin>>newly;
					record[k].date=newly;
					break;
				}
				case 3:{
					cout<<"enter name : ";
					cin>>newly;
					record[k].name=newly;
					break;
				}
				case 4:{
					cout<<"enter place : ";
					cin>>newly;
					record[k].place=newly;
					break;
				}
				case 5:{
					cout<<"enter duration : ";
					cin>>newly;
					record[k].duration=newly;
					break;
				}
				case 6:{
					cout<<"enter note : ";
					cin>>newly;
					record[k].note=newly;
					break;
				}
				case 7:{
					
					return 0;
				}
				default:
					cout<<"invalid input\n";
				
			}
			c=1;	
		}
	}
	if(!c)
	cout<<"no such record"<<endl;
	cout<<"WOULD YOU LIKE TO EDIT ANY OTHER RECORD : {y/n} : ";
	char a;
	cin>>a;
	if(a=='y')
	edit();
	else 
	return 0;
}
int editrecord(string password)
{
		string b;	
	if(p>=3)
	{
		cout<<"access denied\n";
		return 0;
	}
	else
	{
			cout<<"enter correct password : ";
			cin>>b;
			if(b==password && p<3)
			{
				cout<<"access granted\n";
				edit();
				p=0;
			}
			else
			{
					p++;
					cout<<"incorrect password\n";
					editrecord(password);
			}
	}
		return 0;
}
int deleter()
{
	int v,c=0;
	char a;
	string date_p,time_p;
	cout<<"how would you like to delete :\n1.delete by whole day\n2.delete by time\n";
				cin>>v;
				if(v==1)
				{
					cout<<"enter date:{dd-mm-yyyy} : ";
					cin>>date_p;
					for(int k=0;k<=i;k++)
					{
						if(record[k].date==date_p)
						{
							for(int l=k;l<=i;l++)
							{
								record[l].time=record[l+1].time;
								record[l].date=record[l+1].date;
								record[l].name=record[l+1].name;
								record[l].place=record[l+1].place;
								record[l].duration=record[l+1].duration;
								record[l].note=record[l+1].note;
								c=1;
							}
							i--;
						}
					}
				}
				else
				{
					cout<<"enter time: { hh:mm} : ";
					cin>>time_p;
					for(int k=0;k<=i;k++)
					{
						if(record[k].time==time_p)
						{
							for(int l=k;l<=i;l++)
							{
								record[l].time=record[l+1].time;
								record[l].date=record[l+1].date;
								record[l].name=record[l+1].name;
								record[l].place=record[l+1].place;
								record[l].duration=record[l+1].duration;
								record[l].note=record[l+1].note;
								c=1;
							}
							i--;
						}
					}	
				}
				if(!c)
				cout<<"no such record"<<endl;
				cout<<"WOULD YOU LIKE TO DELETE ANY OTHER FILE : {y/n} ";
				cin>>a;	
				if(a=='y')
				deleter();
				else
				return 0;	
}
int deleterecord(string password)
{
	string b;	
	if(q>=3)
	{
		cout<<"access denied\n";
		return 0;
	}
	else
	{
			cout<<"enter correct password : ";
			cin>>b;
			if(b==password && q<3)
			{
				cout<<"access granted\n";
				deleter();
				q=0;
			}
			else
			{
					q++;
					cout<<"incorrect password\n";
					deleterecord(password);
			}
	}
		return 0;
}
int changepassword(string password)
{
					string b,newp;	
					if(n>=3)
					{
						cout<<"access denied\n";
						g=1;
						return 0;
					}
					else
					{
						cout<<"enter old password : ";
						cin>>b;
						if(b==password && n<3)
						{
							cout<<"access granted\n";
							cout<<"enter new password : ";
							cin>>newp;
							password=newp;
							n=0;
						}
						else
						{
							n++;
							cout<<"incorrect password\n";
							changepassword(password);
						}	
					}	
}
int main()
{
	int ch;
	string password;
	cout<<"create your password\n";
	getline(cin,password);
	cout<<"\n\n\n                             ************************\n";
	cout<<"                             *****PERSONAL DIARY*****\n";
	cout<<"                             ************************\n\n\n";
	do
	{
	
		cout<<"MAIN MENU\n\n";
		cout<<"1.ADD RECORD\n2.VIEW RECORD\n3.EDIT RECORD\n4.DELETE RECORD\n5.CHANGE PASSWORD\n6.QUIT\n";
		cout<<"enter your choice : ";
		cin>>ch;
		cout<<endl;
		switch(ch)
		{
			case 1:
			{
				addrecord();
				break;
			}
			case 2:{
				viewrecord(password);
				break;
			}
			case 3:{
				editrecord(password);
				break;
			}
			case 4:{
				deleterecord(password);
				break;
			}
			case 5:{
				if(!g)
				{
					cout<<"FOR SECURITY PURPOSE YOU HAVE ONLY THREE CHANCES OF ENTERING OLD PASSWORD : \n";
				}
				changepassword(password);
				break;
			}
			case 6:{
				return 0;
			}
			default:
				cout<<"INVALID INPUT\n";
		}
		
	}while(ch!=6);
}
