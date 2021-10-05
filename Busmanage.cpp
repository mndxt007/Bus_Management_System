#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>

struct ticke
{
	int full;
	int half;
	char sour[20];
	char dest[20];
	char datetime[30];
	int ticketno;
	int aprice;
	int cprice;
	int total;
	int age;
	struct ticke *link;
};
typedef struct ticke ticket;

ticket *head;
ticket *prev;//for tickets
ticket *curr;

ticket *head1;
ticket *prev2;//for pass
ticket *curr2;

void gotoxy (int x, int y);

void rectangle(int x,int y,int l,int b);

void loading();

int curposition;

void newticket();

void database();

void pass();

void printfdash(int x, int y);

char all[20][20]={"DHARWAD","NTTF","KMF","SDM","GTTC","APMC","KLE","HUBLI"};

char all2[20][20]={"HUBLI","KLE","APMC","GTTC","SDM","KMF","NTTF","DHARWAD"};

int no[20]={0,1,2,3,4,5,6,7};

int flag=0;

int counter=0,tno=100,pno=1000;


int update()
{
	
	while(1)
	{
		int choice,i,k,y=10;
		system("cls");
		gotoxy(3,3);
		printf("***************************   K  S  R  T  C   ****************************\n\n\n");
		rectangle(1,1,79,22);
		rectangle(3,2,77,4);
		rectangle(37,6,70,20);
		k=curposition;

		if((flag==0)||(flag%2==0))
		{
			gotoxy(50,7);printf("DWD-HUBLI");
			gotoxy(40,9);printf("Current stop- %d. %s",no[curposition],all[curposition]);
			while(no[k]!=7)
			{
					gotoxy(43,++y);printf("%d. %s",no[++k],all[k]);
			}
		}
		else
		{
			gotoxy(50,7);printf("HUBLI-DWD");
			gotoxy(40,9);printf("Current stop- %d. %s",no[curposition],all2[curposition]);
			while(no[k]!=7)
			{
				{
					gotoxy(43,++y);printf("%d. %s",no[++k],all2[k]);
				}
			}
		}
		
		gotoxy(3,8);printf("1.UPDATE TO NEXT STOP");
		gotoxy(3,12);printf("2.UPDATE TO PREVIOUS STOP");
		gotoxy(3,16);printf("3.BACK TO MENU");
		gotoxy(6,20);printf("Choice-->");scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					if(curposition!=7)
						curposition++;
					else 
					{
						curposition=0;
						flag++;
					}
					break;
				}
			case 2:
				{
					if(curposition!=0)
						curposition--;
					break;
				}
			case 3: 
				{
					return 0;
				}
				

			default: gotoxy(4,21);printf("Enter proper choice");Sleep(250);break;
		}
	}
	
}


void current()
{
	
		if(flag%2==0)
		{
			switch(curposition)
			{
				case 0: system("mp3\\hubli.mp3");break;
				case 1:system("mp3\\nttf1.wav");break;
				case 2: system("mp3\\kmf1.wav");break;
				case 3: system("mp3\\sdm1.wav");break;
				case 4: system("mp3\\gttc1.wav");break;
				case 5: system("mp3\\apmc1.wav");break;
				case 6: system("mp3\\kle1.wav");break;
				case 7: system("mp3\\dest.mp3");break;
				default: break;
			}
		}
		else
		{
			switch(curposition)
			{
				case 0: system("mp3\\dharwad.mp3");break;
				case 6:system("mp3\\nttf1.wav");break;
				case 5: system("mp3\\kmf1.wav");break;
				case 4: system("mp3\\sdm1.wav");break;
				case 3: system("mp3\\gttc1.wav");break;
				case 2: system("mp3\\apmc1.wav");break;
				case 1: system("mp3\\kle1.wav");break;
				case 7: system("mp3\\dest.mp3");break;
				default: break;
			}
		}
	
}

int next()
{
	rectangle(9,6,70,18);
	gotoxy(30,12);printf("playing.........");
	if(curposition==7)
	{
		system("mp3\\dest.mp3");
		return 0;
	}
	system("mp3\\next.wav");
	Sleep(3000);
	if(flag%2==0)
		{
			switch(curposition)
			{
				case 0:system("mp3\\nttf.wav");break;
				case 1: system("mp3\\kmf.wav");break;
				case 2: system("mp3\\sdm.wav");break;
				case 3: system("mp3\\gttc.wav");break;
				case 4: system("mp3\\apmc.wav");break;
				case 5: system("mp3\\kle.wav");break;
				case 6: system("mp3\\hbl.mp3");break;
				default: break;
			}
	}
		else
		{
			switch(curposition)
			{
				case 6: system("mp3\\dwd.wav");break;
				case 5:system("mp3\\nttf.wav");break;
				case 4: system("mp3\\kmf.wav");break;
				case 3: system("mp3\\sdm.wav");break;
				case 2: system("mp3\\gttc.wav");break;
				case 1: system("mp3\\apmc.wav");break;
				case 0: system("mp3\\kle.wav");break;
				default: break;
			}
		}
		
	
}

int calculatevalue(int a)
{
	int ans;
	ans=(a-curposition);
	switch(ans)
	{
		case 1:return 5;
		case 2:return 8;
		case 3:return 11;
		case 4:return 14;
		case 5:return 17;
		case 6:return 20;
		case 7:return 22;
	}
}

int main()
{
	curposition=0;
	loading();

	head=NULL;
 
	while(1)
	{
		int choice=0;
		system("cls");
		gotoxy(32,3);
		printf(" K  S  R  T  C \n\n\n");
		printf("\t\t\t1.TICKET.\n\n");
		printf("\t\t\t2.DAILY PASS.\n\n");
		printf("\t\t\t3.UPDATE CURRENT STOP.\n\n");
		printf("\t\t\t4.ANNOUNCE CURRENT STOP.\n\n");
		printf("\t\t\t5.ANNOUNCE NEXT STOP.\n\n");
		printf("\t\t\t6.TICKET DATA BASE\n\n");
		printf("\t\t\t7.EXIT\n\n");
		rectangle(1,1,79,22);
		rectangle(30,2,49,4);
		gotoxy(3,20);printf("\tChoice-->");
		scanf("%d",&choice);
		system("cls");
		gotoxy(32,3);
		printf(" K  S  R  T  C \n\n\n");
		rectangle(1,1,79,22);
		rectangle(30,2,49,4);
		switch(choice)
		{
			case 1: 
				{
					newticket();
					break;
				}
			case 2: 
				{
					pass();
					break;
				}

			case 3:update();break;
			case 4:current();break;
			case 5:next();break;
			
			case 6: 
				{
					database();
					break;
				}
			case 7: exit(0);
			default: printf("\nEnter proper choice");break;
				
		}
		
	}
}

void loading()
{
	int i,x=38;
	rectangle(1,1,79,22);
	gotoxy(32,3);
	printf("TICKET MANAGEMENT \n\n\n");
	gotoxy(37,5);
	printf("SYSTEM\n\n\n");
	rectangle(30,2,50,6);
	gotoxy(29,13);
	printf("LOADING ............\n\n\n",1);
	gotoxy(50,19);
	printf("Software by Manoj...\n\n\n");
	rectangle(25,11,56,15);
	for(i=0;i<12;i++)
	{
		gotoxy(x,13);
		x++;
		printf(".%c",1);
		Sleep(250);
	}
	Sleep(500);
}

void newticket()
{
	int y=10,k,choice,stopno=0;
	ticket *temp;

	temp=(ticket*)malloc(sizeof(ticket));


	if(head!=NULL)
        {
            prev=curr;
            curr=temp;
            prev->link=temp;
            temp->link=NULL;
        }
    else
    {
        head=temp;
        curr=head;
    }
	counter++;

	temp->age=NULL;

	rectangle(37,6,70,20);
	k=curposition;

	//for stop details block
	if((flag==0)||(flag%2==0))
		{
			gotoxy(50,7);printf("DWD-HUBLI");
			gotoxy(40,9);printf("Current stop- %d. %s",no[curposition],all[curposition]);
			while(no[k]!=7)
			{
				gotoxy(43,++y);printf("%d. %s",no[++k],all[k]);
			}
		}
	else
		{
			gotoxy(50,7);printf("HUBLI-DWD");
			gotoxy(40,9);printf("Current stop- %d. %s",no[curposition],all2[curposition]);
			while(no[k]!=7)
				{
					{
						gotoxy(43,++y);printf("%d. %s",no[++k],all2[k]);
					}
				}
		}


	gotoxy(3,8);printf("%c> NIMBER OF FULL TICKETS - ",203);scanf("%d",&temp->full);
	gotoxy(3,10);printf("%c> NIMBER OF HALF TICKETS - ",203);scanf("%d",&temp->half);
		while(1)
		{
			gotoxy(3,12);printf("%c>DESTINATION STOP NO. - ",203);scanf("%d",&stopno);
			if((flag==0)||(flag%2==0))
			{
				strcpy(temp->sour,all[curposition]);
				strcpy(temp->dest,all[stopno]);
			}
			
			else
			{
				strcpy(temp->sour,all2[curposition]);
				strcpy(temp->dest,all2[stopno]);
			}
			if(stopno>curposition&&stopno<=7)
				break;
		}
	tno++;
	temp->ticketno=tno;

	

	temp->aprice=calculatevalue(stopno);
	temp->cprice=temp->aprice/2;

	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	char a[100];
	strcpy(a,asctime (timeinfo));
	strcpy(temp->datetime,a);

	system("cls");
	gotoxy(32,3);
	printf(" K  S  R  T  C ");
	rectangle(1,1,79,22);
	rectangle(30,2,49,4);
	rectangle(24,6,54,20);
	gotoxy(34,7);printf("K.S.R.T.C");gotoxy(29,8);printf("---------------------");
	gotoxy(26,9);printf("HUBLI-DWD");
	gotoxy(44,9);printf("T.no-%d",temp->ticketno);
	gotoxy(28,11);printf("%s",temp->datetime);
	gotoxy(30,13);printf(" %s - %s",temp->sour,temp->dest);
	gotoxy(30,15);printf("FULL : %d X %d = %d",temp->full,temp->aprice,temp->full*temp->aprice);
	gotoxy(30,16);printf("HALF : %d X %d = %d",temp->half,temp->cprice,temp->half*temp->cprice);
	temp->total=(temp->full*temp->aprice)+(temp->half*temp->cprice);
	gotoxy(40,18);printf("Total- %d",temp->total);
	getch();
}

void pass()
{
	system("cls");
	
		ticket *temp;

	temp=(ticket*)malloc(sizeof(ticket));


	if(head!=NULL)
        {
            prev=curr;
            curr=temp;
            prev->link=temp;
            temp->link=NULL;
        }
    else
    {
        head=temp;
        curr=head;
    }
	counter++;

	temp->ticketno=pno;

	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	char a[100];
	strcpy(a,asctime (timeinfo));
	strcpy(temp->datetime,a);


	gotoxy(32,3);
	printf(" K  S  R  T  C ");
	rectangle(1,1,79,22);
	rectangle(30,2,49,4);
	rectangle(24,6,54,20);
	gotoxy(34,7);printf("K.S.R.T.C");gotoxy(29,8);printf("---------------------");
	gotoxy(26,9);printf("HUBLI-DWD");
	gotoxy(44,9);printf("P.no-%d",temp->ticketno);
	gotoxy(28,11);printf("%s",temp->datetime);
	gotoxy(33,15);printf("AGE - ");scanf("%d",&temp->age);
	
	temp->total=70;
	gotoxy(40,18);printf("Total- %d",temp->total);
	getch();
}

void database()
{
	system("cls");
	int x=5,y=7,count=0,i,total=0;
	ticket *temp;
	gotoxy(32,3);
	printf(" K  S  R  T  C \n\n\n");
	rectangle(30,2,49,4);
	temp=head;
	for(i=0;i<counter;i++)
	{
		if((count%2==0)&&(count!=0))
		{
			y=y+15;
			x=5;
		}
		if(temp->age==NULL)
		{
			gotoxy(x+10,y+1);printf("K.S.R.T.C");gotoxy(x+5,y+2);printf("---------------------");
			gotoxy(x+2,y+3);printf("HUBLI-DWD");
			gotoxy(x+20,y+3);printf("T.no-%d",temp->ticketno);
			gotoxy(x+4,y+5);printf("%s",temp->datetime);
			gotoxy(x+6,y+7);printf(" %s - %s",temp->sour,temp->dest);
			gotoxy(x+6,y+9);printf("FULL : %d X %d = %d",temp->full,temp->aprice,temp->full*temp->aprice);
			gotoxy(x+6,y+10);printf("HALF : %d X %d = %d",temp->half,temp->cprice,temp->half*temp->cprice);
			temp->total=(temp->full*temp->aprice)+(temp->half*temp->cprice);
			gotoxy(x+16,y+12);printf("Total- %d\n\n",temp->total);
			total+=temp->total;
		}
		else
		{
			gotoxy(x+10,y+1);printf("K.S.R.T.C");gotoxy(x+5,y+2);printf("---------------------");
			gotoxy(x+2,y+3);printf("HUBLI-DWD");
			gotoxy(x+20,y+3);printf("P.no-%d",temp->ticketno);
			gotoxy(x+4,y+5);printf("%s",temp->datetime);
			gotoxy(x+12,y+9);printf("AGE - %d",temp->age);
			gotoxy(x+16,y+12);printf("Total- %d\n\n",temp->total);
			total+=temp->total;
		}
		x=x+38;
		count++;
		temp=temp->link;
		printfdash(x,y);
	}
	printf("\n\n\t\t\t\tTOTAL COLLECTION = %d",total);
	getch();

}

void printfdash(int x, int y)
{
	int i,x1=0,y1=y;
	for(i=0;i<80;i++)
	{
		gotoxy(x1,y-1);printf("-");
		x1++;
	}
	for(i=0;i<14;i++)
	{
		gotoxy(40,y);printf("|");
		y++;
	}
	x1=0;
	for(i=0;i<80;i++)
	{
		gotoxy(x1,y1+14);printf("-");
		x1++;
	}

}

COORD coord = {0, 0}; 
void gotoxy (int x, int y)
        {
			 coord.X = x;
			coord.Y = y; // X and Y coordinates
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        }

void rectangle(int x,int y,int l,int b)
{
    int i,m;
    gotoxy(x,y); printf("%c",201);
    for(i=x+1;i<l-1;i++)
    {
        gotoxy(i,y);
        printf("%c",205);
    }
    gotoxy(i,y); printf("%c",187);

    for (m=y+1;m<b;m++)
    {
        gotoxy(x,m);
        for(i=x;i<l;i++)
        {
            if(i==x||i==l-1)
            {
                gotoxy(i,m); printf("%c",186);
            }

        }

    }

    gotoxy(x,m); printf("%c",200);
    for(i=x+1;i<l-1;i++)
    {
        gotoxy(i,m);
        printf("%c",205);
    }
    gotoxy(i,m); printf("%c",188);
}
