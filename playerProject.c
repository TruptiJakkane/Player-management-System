 //Player Management System
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct player{
	int jersey;
	char name[20];
	int matches;
	int runs;
	int wickets;
}player;
//Function Declarations
int ctr=0;
void storeData(player*,int);
void display(player*);
int searchByJersey(player*,int);
int searchByName(player*,char*);
void deletee(player*);
void update(player*);
void display1(player);
void Top3ByRun(player*);
void Top3ByWicket(player*);
 
int main()
{
	player *play;
	int size,number,index,m,Jnumber;
	printf("Enter size of player:");
	scanf("%d",&size);
	play=(player*)malloc(sizeof(player)*size);
	int ch,ch1,c;
do 
{
	printf("\n*$*______________PLAYER MANAGEMENT______________*$*");
	printf("\n\t1. Add Player\n\t2. Display All Players\n\t3. Search Player\n\t4. Remove Player\n\t5. Update Player Data\n\t6. Display Top 3 Players\n\t0. Exit\n");
	printf("\nEnter your choice:");
	scanf("%d", &c); 
	switch (c)
	{
		case 1:
			 // Add Player
			storeData(play,size); 
			break;
		case 2:
			 // Display All Players
			display(play);
			break;
		case 3:
			 // Search Player
			printf("\n1.Search by Jersey: \n2.Search by name:\n");
			printf("Choose any one:");
			scanf("%d",&ch);
			if(ch==1)
			{
				printf("\nSearch player by there Jersey number:");
			   	scanf("%d",&number);	 
				index=searchByJersey(play,number);
				if(index==-1)
					{
					 	printf("\nPlayer not found:\n");
					}
				else
					{
						display1(play[index]);
					}
			}
			else if(ch==2)
			{
				char name[20];
				printf("\nsearch player by there name:");
				scanf("%s",&name);
				 
				m=searchByName(play,name);
				if(m==-1)
				{
				 	printf("\nplayer not found:\n");
				}
				else
				{
					display1(play[m]);
				}
			}
			else
				printf("\nPlease enter valid choice:");
			break;
		case 4:
			 // Remove Player
			deletee(play);
			break;
		case 5:
			 // Update Player Data
			update(play);
		 	break;
		case 6:
			 // Display Top 3 Players
			 printf("\n1.Top3 BY Runs: \n2.Top3 By Wickets:\n");
			 printf("\nChoose any one:");
			 scanf("%d",&ch1);
			 if(ch1==1)
			 {
			 	Top3ByRun(play);
			 }
			 else if(ch1==2)
			 {
				 Top3ByWicket(play);
			 }
			 else
				 printf("\nPlease enter	valid choice:\n");
		 	break;
		case 0:
			 // Exit the program
			 printf("\nExiting program.Thank you!!");
			 break;
		default:
			 printf("\nInvalid choice.\n");
	    }
} 
while (c != 0);
	free(play);
	return 0;
}
void storeData(player* p,int size)
{
	if(ctr!=size)
	{
		printf("\nenter jersey number:");
		scanf("%d",&p[ctr].jersey);
		printf("enter player name:");
		scanf("%s",p[ctr].name);
		printf("enter matches:");
		scanf("%d",&p[ctr].matches);
		printf("enter runs:");
		scanf("%d",&p[ctr].runs);
		printf("enter wickets:");
		scanf("%d",&p[ctr].wickets);
		ctr++;
	}
	else
	{
		printf("\nArray is full!!\n");
	}
}
void display(player* play)
{
	printf("\nList of Players:\n");
	printf("|\t\t%s \t\t%s \t\t%s \t\t%s \t\t%s\n", "Jersey", "Name", "Runs", "Wickets", "Matches");
	int i;
	for(i=0;i<ctr;i++)
	{
		printf("|\t\t%d \t\t%s \t\t%d \t\t%d \t\t%d\n",play[i].jersey,play[i].name,play[i].matches,play[i].runs,play[i].wickets);
	}
}
void display1(player p)
{
	printf("\n jersey Number:%d\n playe	name:%s\n matches:%d\n runs:%d\n wickets:%d\n",p.jersey,p.name,p.matches,p.runs,p.wickets);
}
int searchByJersey(player* play, int number)
{
	int i;
	for(i=0;i<ctr;i++)
	{
		if(play[i].jersey ==number)
		{
			return i;
		}
	}
	return -1;
}
int searchByName(player* p,char* name)
{
	int i;
	for(i=0;i<ctr;i++)
	{
		if(strcmp(p[i].name,name)==0)
		{
			return i;
		}
	}
	 return -1;
}
void deletee(player* play)
{
	int number;
	printf("\nEnter the jersey number of the player to be deleted: ");
	scanf("%d", &number);
	int i=searchByJersey(play,number);
	if (i==-1) 
	{ 
		printf ("\nPlayer not found for deletion:\n"); 
	} 
	else 
	{ 
		printf("\nAfter deleting :");
		while(i<ctr-1)
		{
			play[i]=play[i+1];
			i++;
		}
		ctr--;
		display(play);
	}
}
 
void update(player* play)
{
	int choice;
	printf("\nwhat you want to 	update:\n1.matches \n2.runs \n3.wickets \n");
    scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		{
			int number; 
			printf("Enter jersey number:");
			scanf("%d",&number);
			int i=searchByJersey(play,number);
			int match;
			printf("Enter updated matches:");
			scanf("%d",&match);
			play[i].matches=play[i].matches+match;
			display1(play[i]);
			break;
		}
	case 2:
		{
			int number; 
			printf("Enter jersey number:");
			scanf("%d",&number);
			int i;
			i=searchByJersey(play,number);
			int run;
			printf("enter updated runs:");
			scanf("%d",&run);
			play[i].runs=run;
			display1(play[i]);
			break;
		}
	case 3:
		{
			int number; 
			printf("Enter jersey number:");
			scanf("%d",&number);
			int i;
			i=searchByJersey(play,number);
			int wicket;
			printf("Enter updated wicket:");
			scanf("%d",&wicket);
			play[i].wickets=wicket;
			display1(play[i]);
			break;
		}
	default:
	 		printf("\nInvalid choice:");
	}
}
void Top3ByRun(player* play)
{
	int i,j;
	player temp;
	for(i=0;i<ctr;i++)
	{
		for(j=i+1;j<ctr;j++)
		{
			if(play[i].runs<play[j].runs)
			{
				temp=play[i];
				play[i]=play[j];
				play[j]=temp;
			}
		}
	}
	printf("Top 3 players by runs:\n");
	for (i = 0; i < 3 && i<ctr; i++)
	{
		display1(play[i]);
	}
}
void Top3ByWicket(player* play)
{
	int i,j;
	player temp;
	for(i=0;i<ctr;i++)
	{
		for(j=i+1;j<ctr;j++)
		{
			if(play[i].wickets<play[j].wickets)
			{
				temp=play[i];
				play[i]=play[j];
				play[j]=temp;
			}
		}
	}
	printf("Top 3 players by wickets:\n");
	for (i = 0; i < 3 && i<ctr; i++) 
	{
	 	display1(play[i]);
	}
}

