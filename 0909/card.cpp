#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct trump
{
	char order;
	char shape[3];
	char number;
};

void display_card(trump m_card[])
{
	int i;
	int count=0;
	int j;
	int random[5];
	srand(time(NULL));
	for(i=0; i<5;i++)
	{
		random[i]=rand()%52+1;
		for(j=0;j<i;j++)
		{
			if (random[i] == random[j])
			{
				i--;
				break;
			}
		}
	}
	for(i=0;i<5;i++)
	{
		
		printf("%s", m_card[random[i]].shape);
		if(10<m_card[random[i]].number)
			printf("%-2c  ", m_card[random[i]].number);
		else
			printf("%-2d  ", m_card[random[i]].number);
		count++;
	}
}

void make_card(trump m_card[])
{
	int i,j;
	char shape[4][3]={"¢¼","¡ß","¢¾","¢À"};
	for(i=0; i<4; i++)
	{
		for(j=i*13; j<i*13+13; j++)
		{
			m_card[j].order=i;
			strcpy(m_card[j].shape, shape[i]);
			m_card[j].number=j%13+1;
			
			switch(m_card[j].number)
			{
				case 1:
					m_card[j].number='A';
					break;
				case 11:
					m_card[j].number='J';
					break;
				case 12:
					m_card[j].number='Q';
					break;
				case 13:
					m_card[j].number='K';
					break;
					
			}
		}
	}
}

int main(void)
{
	trump card[52];
	make_card(card);
	display_card(card);
	return 0;
}
