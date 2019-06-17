#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
typedef struct date                            							 //�������ڽṹ�� 
	{
		int year;
		int month;
		int day;
	}date;
typedef struct expend                                                   //����֧����Ϣ�ṹ�� 
	{
		date time;
		int type;
		double money;
		char remark[18];
	}expend;
typedef struct analyze                                                 //��������ṹ���Է������� 
	{
		char type[10];
		double money;
	}analyze;	
void cursor(int n,int m);                                                 //���ƹ��λ�� 
void start();                                                              //��ʼ���� 
void finish();                                     						   //�������� 
void med();                                                                //�߿���ʽһ 
void med2();															  //�߿���ʽ�� 
void med3();															  //�߿���ʽ�� 
void reg(expend exp[],int cnt[]);										  //ע�� 
void menu(expend exp[],int cnt[]); 										  //ע�����	
void menu2(expend exp[],int cnt[]);										  //��¼���� 
void menu3(expend exp[],int cnt[]);										  //������ 
void menu4(expend exp[],int cnt[]);                                      //��ѯ���� 
void menu5(expend exp[],int cnt[]);										 //�������� 
void save(char c[],char d[]);											//�����û��������� 
void filesave(expend n,expend ex[],int cnt[]);								//����������¼ 
void filesave2(expend exp[],int cnt[],int year,int month,double sum);                    //���水�²�ѯ��� 
void filesave3(expend exp[],int cnt[],int y1,int m1,int d1,int y2,int m2,int d2,double sum);    //���水�����ѯ��� 
void create();                                                            //�����ļ��������Ƿ��һ��ʹ�� 
void read(int n,char str[]);                                              //��ȡ�û����������ļ� 
void readfile(expend exp[],int cnt[]);                                    //�����м�¼��ȡ���ṹ������ 
void record(expend ex[],int cnt[]);                                       //������¼ 
void monthana(expend exp[],int cnt[]);									//���·��� 
void yearana(expend exp[],int cnt[]);										//������� 
void daycheck(expend exp[],int cnt[]);										//���ղ�ѯ 
void monthcheck(expend exp[],int cnt[]);                                  //���²�ѯ 
void intercheck(expend exp[],int cnt[]);                                  //�����ѯ 
void password(char p[]);                                                 //�������� 
void sort1(expend exp[],int cnt[]);                                      //���������� 
void sort2(analyze ana[],int n);                                         //��������� 
int datejudge(int y, int m, int d);                                      //���ںϷ��Լ�� 
int interjudge(int y,int m,int d);                                      //���ڴ�С�Ƚ� 

int main()
{
	start();										//��ʼ���� 
	Sleep(3000);
	system("CLS");
	expend exp[30000];									//����ṹ�������Դ洢����֧����Ϣ 
	int cnt[1]={0};										//����һ����Ԫ������洢�ṹ�峤�� 
	FILE *fp;											//�ж��Ƿ��һ��ʹ��ϵͳ 
	fp=fopen("D:\\code.txt","r");
	if(fp==0)
	{
		fclose(fp);
		menu(exp,cnt);
	}
	else
	{
		menu2(exp,cnt);
	}
}

void cursor(int n,int m)                             //���ƹ��λ�� 
{
	HANDLE hout;
	COORD coord;
	coord.X=n;
	coord.Y=m;
	hout=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout,coord);
}

void start()
{
	printf("                                                                  \n");
	printf("      ������������������������������������������������������������������ \n");
    printf("      ��  ��                                                          �� \n");
	printf("      �����੤������                                                  �� \n");
	printf("      ��  ��                                                          �� \n");
	printf("      ��  ��                                                          �� \n");
	printf("      ��     �ģߡ�                                                   �� \n");
	printf("      ��   �����ء�)�ĩ���..  ��*��                                   �� \n");
	printf("      ��   �ȡ���  �� ��  ������  �b+.                                �� \n");
	printf("      ��    �� �` �ʡ�  �����㡣+ *�䡧)                              �� \n"); 
	printf("      ��                          .����b*��) .��*��                  �� \n");
	printf("      ��                              (.�����.����*                  �� \n");
	printf("      ��                                                              �� \n");
	printf("      ��                                                              �� \n");
	printf("      ��                  >>>��ӭ��¼���ӲƸ���֧ͥ������ϵͳ<<<      �� \n");
	printf("      ��                      >>>Welcome to use the system!<<<        �� \n");
	printf("      ��                         By  ��һ��  ���ĳ�  ���         ��  �� \n");
	printf("      ��                                                          ��  �� \n");
	printf("      ��                                                  ���������੤�� \n");
	printf("      ��                                                          ��  �� \n");
	printf("      ������������������������������������������������������������������ \n");
	printf("      ������������������������������������������������������������������ \n");
}

void finish()
{
	printf("                                                                  \n");
	printf("      ������������������������������������������������������������������ \n");
    printf("      ������������������������������������������������������������������ \n");
	printf("      ��                                                              �� \n");
	printf("      ��                                                              �� \n");
	printf("      ��               �� ��                                          �� \n");
	printf("      ��            (  - �� -)                                        �� \n");
	printf("      ��      ��������������������������������������                  �� \n");
	printf("      ��      ��                                  ��                  �� \n");
	printf("      ��      ��           ����лʹ�á�           ��                  �� \n"); 
	printf("      ��      ��    �����ӲƸ���֧ͥ������ϵͳ��  ��                  �� \n");
	printf("      ��      ��         ��лл����֧�֡�         ��                  �� \n");
	printf("      ��      ��           ��BYE  BYE��           ��                  �� \n");
	printf("      ��      ��         ����ӭ�´ε�¼��         ��                  �� \n");
	printf("      ��      ��������������������������������������                  �� \n");
	printf("      ��                                                              �� \n");
	printf("      ��                                 �� �� .o�� �m  �m.. ��       �� \n");
	printf("      ��                              �m���m ��  �� .�m �mo�y�z�|�}   �� \n");
	printf("      ��                              �� ��- ���� �m �� �m�m �� �m   �� \n");
	printf("      ��                              �|�}�~�����������~�}�|�z�y���m  �� \n");
	printf("      ������������������������������������������������������������������ \n");
	printf("      ������������������������������������������������������������������ \n");
}

void med()												//�߿���ʽһ 
{
	int i,j;
	cursor(0,0);
	for(i=0;i<5;i++)
	printf("\n");
	for(i=0;i<20;i++)
	printf(" ");
	for(i=0;i<20;i++)
	printf("* ");
	printf("\n");
	for(i=0;i<15;i++)
	{
		for(j=0;j<20;j++)
		printf(" ");
		printf("*");
		for(j=0;j<37;j++)
		printf(" ");
		printf("*\n");
	}
	for(i=0;i<20;i++)
	printf(" ");
	for(i=0;i<20;i++)
	printf("* ");
	printf("\n");
}

void med2()														//�߿���ʽ�� 
{
	cursor(0,0);
	int i,j;
	for(i=0;i<3;i++)
	printf("\n");
	for(i=0;i<12;i++)
	printf(" ");
	for(i=0;i<30;i++)
	printf("* ");
	printf("\n");
	for(i=0;i<290;i++)
	{
		for(j=0;j<12;j++)
		printf(" ");
		printf("*");
		for(j=0;j<57;j++)
		printf(" ");
		printf("*\n");
	}
	for(i=0;i<12;i++)
	printf(" ");
	for(i=0;i<30;i++)
	printf("* ");
	printf("\n");
}

void med3()														//�߿���ʽ�� 
{
	cursor(0,0);
	int i,j;
	for(i=0;i<3;i++)
	printf("\n");
	for(i=0;i<12;i++)
	printf(" ");
	for(i=0;i<29;i++)
	printf("* ");
	printf("\n");
	for(i=0;i<20;i++)
	{
		for(j=0;j<12;j++)
		printf(" ");
		printf("*");
		for(j=0;j<55;j++)
		printf(" ");
		printf("*\n");
	}
	for(i=0;i<12;i++)
	printf(" ");
	for(i=0;i<29;i++)
	printf("* ");
	printf("\n");
}

void menu(expend exp[],int cnt[])												//ע����� 
{
	int i;
	char x;
	char a[20];
	char b[20];
	med();
	cursor(27,10);
	printf("-------- 1.ע�� --------");
	cursor(27,11);
	printf("-------- 2.�˳� --------");
	cursor(27,12);
	scanf("%c",&x);
	system("CLS");
	switch(x)
	{
	case '1':     reg(exp,cnt);
	case '2':     system("CLS");
					finish();
	               Sleep(3000);
			      exit(1);
	default:    menu(exp,cnt);
	}
}

void reg(expend exp[],int cnt[])												//ע����� 
{
				char c[20];
				char d[20];
				char e[20];
				int i;
				med();
				cursor(30,8);
				printf("�������û���");
				cursor(30,9);
				scanf("%s",c);
				cursor(30,10);
				printf("����������");
				cursor(30,11);
				password(d);
				cursor(30,12);
				printf("��ȷ������");
				cursor(30,13);
				password(e);
				cursor(30,14);
				if(strcmp(d,e)==0)
				{
					printf("ע��ɹ�!");
					cursor(30,15);
					save(c,d);
					create();
					printf("3���Ӻ󷵻�");
					cursor(30,16);
					for(i=3;i>=1;i--)
					{
						printf("%d",i);
						Sleep(1000);
						cursor(30,16);
					}
					system("CLS");
					menu2(exp,cnt); 
				}
				else
				{
					cursor(30,15);
					printf("���벻һ�£�������ע��!");
					cursor(30,16);
					printf("3���Ӻ󷵻�");
					cursor(30,17);
					for(i=3;i>=1;i--)
					{
						printf("%d",i);
						Sleep(1000);
						cursor(30,17);
					}
					system("CLS");
					reg(exp,cnt);
				}
}

void menu2(expend exp[],int cnt[])								//��¼���� 
{
	int i=0,ct=0;
	char x;
	char a[20];
	char b[20];
	char a2[20];
	char b2[20];
	med();
	cursor(27,10);
	printf("-------- 1.��¼ --------");
	cursor(27,11);
	printf("-------- 2.�˳� --------");
	cursor(27,12);
	scanf("%c",&x);
	cursor(27,13);
	system("CLS");
	switch(x)
	{
	case '1':		read(1,a2);
				med();
				cursor(30,8);	
				printf("��ӭ�����𾴵�%s\n",a2);
				cursor(30,9); 
				printf("����������\n");
				cursor(30,10);
				password(b);
				cursor(30,11);
				read(2,b2);
				if(strcmp(b,b2)==0)
					{
						printf("��½�ɹ�!\n");
						cursor(27,14);
						printf("��ӭ���ʼ�֧ͥ������ϵͳ!");
						readfile(exp,cnt);
						Sleep(800);
						system("CLS");
						menu3(exp,cnt);
					}
				while(strcmp(b,b2)!=0)
				{
					
					if(ct>2)
					{
						printf("����������Σ������Զ��رգ�");
						i++;
						cursor(30,11+i);
						Sleep(1000);
						exit(1);	
					}
					printf("�����������������\n");
					i++;
					ct++;
					cursor(30,11+i);
					password(b);
					i++;
					if(strcmp(b,b2)==0)
					{
						cursor(30,11+i);
						printf("��½�ɹ�!\n");
						i++;
						cursor(27,13+i);
						printf("��ӭ���ʼ�֧ͥ������ϵͳ!");
						readfile(exp,cnt);
						Sleep(1500);
						system("CLS");
						menu3(exp,cnt);
					}
					cursor(30,11+i);
				}
				break;
	case '2':   system("CLS");
				finish();
				Sleep(3000);  
				exit(1);
	default: menu2(exp,cnt);
	}
}

void menu3(expend exp[],int cnt[])												//������ 
{
	char x;
	med();
	cursor(25,10);
	printf("-------- 1.���Ӽ�¼ --------");
	cursor(25,11);
	printf("-------- 2.���Ѳ�ѯ --------");
	cursor(25,12);
	printf("-------- 3.���ѷ��� --------");
	cursor(25,13);
	printf("-------- 4.ע    �� --------"); 
	cursor(25,14);
	scanf("%c",&x);
	switch(x)
	{
		case '1': record(exp,cnt);
		case '2': menu4(exp,cnt);
		case '3':menu5(exp,cnt);
		case '4': menu2(exp,cnt);
		default: menu3(exp,cnt);
	}
}

void menu4(expend exp[],int cnt[])											//��ѯ���� 
{
	char x;
	system("CLS");
	med();
	cursor(25,10);
	printf("-------- 1.���ղ�ѯ --------");
	cursor(25,11);
	printf("-------- 2.���²�ѯ --------");
	cursor(25,12);
	printf("-------- 3.�����ѯ --------");
	cursor(25,13);
	printf("-------- 4.��    �� --------");
	cursor(25,14);
	scanf("%c",&x);
	switch(x)
	{
		case '1': daycheck(exp,cnt);
		case '2': monthcheck(exp,cnt);
		case '3': intercheck(exp,cnt);
		case '4': menu3(exp,cnt);
		default: menu4(exp,cnt);
	}
}

void menu5(expend exp[],int cnt[])										//�������� 
{
	char x;
	system("CLS");
	med();
	cursor(25,10);
	printf("-------- 1.���·��� --------");
	cursor(25,11);
	printf("-------- 2.������� --------");
	cursor(25,12);
	printf("-------- 3.��    �� --------");
	cursor(25,13);
	scanf("%c",&x);
	switch(x)
	{
		case '1': monthana(exp,cnt);
		case '2': yearana(exp,cnt);
		case '3': menu3(exp,cnt);
		default: menu5(exp,cnt);
	}	
}

void save(char c[],char d[])											//�����û��������� 
{
	FILE *fp;
	fp=fopen("D:\\code.txt","w+");
	fputs(c,fp);
	fputc('\n',fp);
	fputs(d,fp);
	fputc('\n',fp);
	fclose(fp);
}

void filesave(expend n,expend ex[],int cnt[])								//����������¼ 
{
	int m;
	FILE *fp;
	fp=fopen("D:\\expend.txt","a+");
	fprintf(fp,"%d %d %d %d %f %s\n",n.time.year,n.time.month,n.time.day,n.type,n.money,n.remark);
	fclose(fp);
	m=cnt[0];
	ex[m].time.year=n.time.year;
	ex[m].time.month=n.time.month;
	ex[m].time.day=n.time.day;
	ex[m].type=n.type;
	ex[m].money=n.money;
	strcpy(ex[m].remark,n.remark);
	cnt[0]++;	
}

void filesave2(expend exp[],int cnt[],int year,int month,double sum)           //���水�²�ѯ��� 
{
	int i,j;
	char name[25];
	char num[25];
	strcpy(name,"D:\\");
	int y=year;
	int m=month;
	for(i=0;i<4;i++)
	{
		
		num[i]=y/int(pow(10,3-i))+48;
		y=y%int(pow(10,3-i));
	}
	num[4]='-';
	for(i=5;i<7;i++)
	{
		
		num[i]=m/int(pow(10,6-i))+48;
		m=m%int(pow(10,6-i));
	}
	strcat(name,num);
	strcat(name,"��������.txt");
	cursor(0,0);
	printf("%s",name);
	FILE *fp;
	fp=fopen(name,"w+");
	fprintf(fp,"               �ܼ�:  %.2fԪ\n",sum);
	fprintf(fp,"��������      ��������    ���ѽ��       ��ע\n");
	for(j=0;j<cnt[0];j++)
  	{   
	  if(year==exp[j].time.year&&month==exp[j].time.month)
	  {
		fprintf(fp,"%d��%d��%d��      ",exp[j].time.year,exp[j].time.month,exp[j].time.day); 
		switch(exp[j].type)
	  {
		case 1: fprintf(fp,"��ʳ");break;
		case 2: fprintf(fp,"ѧϰ");break;
		case 3: fprintf(fp,"ҽ��");break;
		case 4: fprintf(fp,"��ͨ");break;
		case 5: fprintf(fp,"ˮ��");break;
		case 6: fprintf(fp,"����");break;
		case 7: fprintf(fp,"����");break;
		case 8: fprintf(fp,"����");break;	
	  }      
		fprintf(fp,"  %10.2f         %s\n",exp[j].money,exp[j].remark);
	  }
  	}
	   fclose(fp);	
}

void filesave3(expend exp[],int cnt[],int y1,int m1,int d1,int y2,int m2,int d2,double sum)    //���水�����ѯ�ṹ 
{
	int i,j;
	char name[40];
	char num[25];
	strcpy(name,"D:\\");
	int y=y1;
	int m=m1;
	int d=d1;
	for(i=0;i<4;i++)
	{
		
		num[i]=y/int(pow(10,3-i))+48;
		y=y%int(pow(10,3-i));
	}
	num[4]='-';
	for(i=5;i<7;i++)
	{
		
		num[i]=m/int(pow(10,6-i))+48;
		m=m%int(pow(10,6-i));
	}
	num[7]='-';
	for(i=8;i<10;i++)
	{
		
		num[i]=d/int(pow(10,9-i))+48;
		d=d%int(pow(10,9-i));
	}
	strcat(name,num);
	strcat(name,"��");
	y=y2;
	m=m2;
	d=d2;
	for(i=0;i<4;i++)
	{
		
		num[i]=y/int(pow(10,3-i))+48;
		y=y%int(pow(10,3-i));
	}
	num[4]='-';
	for(i=5;i<7;i++)
	{
		
		num[i]=m/int(pow(10,6-i))+48;
		m=m%int(pow(10,6-i));
	}
	num[7]='-';
	for(i=8;i<10;i++)
	{
		
		num[i]=d/int(pow(10,9-i))+48;
		d=d%int(pow(10,9-i));
	}
	strcat(name,num);
	strcat(name,"��������.txt");
	FILE *fp;
	fp=fopen(name,"w+");
	fprintf(fp,"               �ܼ�:  %.2fԪ\n",sum);
	fprintf(fp,"��������      ��������    ���ѽ��       ��ע\n");
	for(j=0;j<cnt[0];j++)
  	{   
	  if(interjudge(exp[j].time.year,exp[j].time.month,exp[j].time.day)>=interjudge(y1,m1,d1)&&interjudge(exp[j].time.year,exp[j].time.month,exp[j].time.day)<=interjudge(y2,m2,d2))
	  {
		fprintf(fp,"%d��%d��%d��      ",exp[j].time.year,exp[j].time.month,exp[j].time.day); 
		switch(exp[j].type)
	  {
		case 1: fprintf(fp,"��ʳ");break;
		case 2: fprintf(fp,"ѧϰ");break;
		case 3: fprintf(fp,"ҽ��");break;
		case 4: fprintf(fp,"��ͨ");break;
		case 5: fprintf(fp,"ˮ��");break;
		case 6: fprintf(fp,"����");break;
		case 7: fprintf(fp,"����");break;
		case 8: fprintf(fp,"����");break;	
	  }      
		fprintf(fp,"  %10.2f         %s\n",exp[j].money,exp[j].remark);
	  }
  	}
	   fclose(fp);	
}

void create()																//�����ļ��������Ƿ��һ��ʹ�� 
{
	FILE *fp;
	fp=fopen("D:\\flag.txt","w+");
	fputc('0',fp);
	fclose(fp);
}

void read(int n,char str[])                                                //��ȡ�û��������� 
{
	FILE *fp;
	char ch;
	int i=0;
	fp=fopen("D:\\code.txt","r");
		while(!feof(fp))
	{
		if(fscanf(fp,"%s",str))
		{
			i++;
			if(i==n)
			{
				break;
			}
		}
	}
	fclose(fp);
}

void readfile(expend exp[],int cnt[])                                       //��ȡ����֧����Ϣ������ṹ������ 
{
	int i=1;
	FILE *fp;
	fp=fopen("D:\\expend.txt","r");
	if(fp==0)
	{
		cursor(27,18);
		printf("����û���κ����Ѽ�¼!");
		Sleep(1500);
		system("CLS");
		menu3(exp,cnt);
	}
	fscanf(fp,"%d %d %d %d %lf %s",&exp[0].time.year,&exp[0].time.month,&exp[0].time.day,&exp[0].type,&exp[0].money,exp[0].remark);
	while(!feof(fp))
  {   
  	fscanf(fp,"%d %d %d %d %lf %s",&exp[i].time.year,&exp[i].time.month,&exp[i].time.day,&exp[i].type,&exp[i].money,exp[i].remark);
  	i++;
  }
	cnt[0]=i-1;
	fclose(fp);
}

void record(expend ex[],int cnt[])              //������¼ 
{
	expend exp;
	char f[5]="��";
	int x,n,m,y,i=0;
	med();
	cursor(30,8);
	printf("����������  (����������)");
	cursor(27,10);
	printf("��ݣ� ");
	cursor(37,10);
	printf("(������һ����λ����)");
	cursor(33,10);
	scanf("%d",&exp.time.year);
	cursor(27,11);
	printf("�·ݣ� ");
	scanf("%d",&exp.time.month);
	cursor(27,12);
	printf("���ڣ� ");
	scanf("%d",&exp.time.day);
	cursor(27,13);
	while(!datejudge(exp.time.year,exp.time.month,exp.time.day))
	{
		cursor(27,14);
		printf("�������ڲ��Ϸ�,����������!");
		Sleep(1500);
		record(ex,cnt);
	}
	system("CLS");
	med();
	cursor(32,7);
	printf("��ѡ����������");
	cursor(27,10);
	printf("-------- 1.��ʳ --------");
	cursor(27,11);
	printf("-------- 2.ѧϰ --------");
	cursor(27,12);
	printf("-------- 3.ҽ�� --------");
	cursor(27,13);
	printf("-------- 4.��ͨ --------");
	cursor(27,14);
	printf("-------- 5.ˮ�� --------");
	cursor(27,15);
	printf("-------- 6.���� --------");
	cursor(27,16);
	printf("-------- 7.���� --------");
	cursor(27,17);
	printf("-------- 8.���� --------");
	cursor(27,18);
	scanf("%d",&exp.type); 
	system("CLS");
	med();
	cursor(30,9);
	printf("��������(Ԫ):  ");
	scanf("%lf",&exp.money);
	i++;
	while(exp.money<0)
	{
		cursor(30,9+i);
		printf("����Ϊ����!");
		cursor(30,10+i);
		printf("��������:  ");
		scanf("%lf",&exp.money);
		i=i+2;
	}
	cursor(30,9+i);
	printf("�Ƿ���Ҫ��ע?");
	cursor(27,10+i);
	printf("-------- 1.�� --------");
	cursor(27,11+i);
	printf("-------- 2.�� --------");
	cursor(27,12+i);
	scanf("%d",&n);
	if(n==1)
	{
		cursor(27,13+i);
		printf("�����뱸ע: ");
		scanf("%s",exp.remark);
	}
	else
	strcpy(exp.remark,f);
	system("CLS");
	med();
	cursor(30,9);
	printf("��ȷ�ϣ�");
	cursor(27,10);
	printf("����: %d �� %d �� %d ��",exp.time.year,exp.time.month,exp.time.day);
	cursor(27,11); 
	printf("��������: ");
	switch(exp.type)
	{
		case 1: printf("��ʳ");break;
		case 2: printf("ѧϰ");break;
		case 3: printf("ҽ��");break;
		case 4: printf("��ͨ");break;
		case 5: printf("ˮ��");break;
		case 6: printf("����");break;
		case 7: printf("����");break;
		case 8: printf("����");break;	
	}
	cursor(27,12);
	printf("���ѽ��: %.2f",exp.money);
	cursor(27,13);
	if(n==1)
	printf("��ע: %s",exp.remark);
	else
	printf("��ע: ��");
	cursor(27,15);
	printf("-------- 1.ȷ������ --------");
	cursor(27,16);
	printf("-------- 2.ȡ������ --------");
	cursor(27,17);
	scanf("%d",&m);
	if(m!=1)
	menu3(ex,cnt);
	if(m==1)
	{
		filesave(exp,ex,cnt);
		system("CLS");
		med();
		cursor(30,9);
		printf("�Ƿ���Ҫ������¼?");
		cursor(27,10);
		printf("-------- 1.�� --------");
		cursor(27,11);
		printf("-------- 2.�� --------");
		cursor(27,12);
		scanf("%d",&y);
		if(y==1)
		record(ex,cnt);
		else
		menu3(ex,cnt);
	}	
}

void monthana(expend exp[],int cnt[])                                //���·��� 
{
	int year,month,day,i=0,x,j;
	double sum=0;
	analyze t[8];
	for(j=0;j<8;j++)
	t[j].money=0;
	strcpy(t[0].type,"��ʳ");
	strcpy(t[1].type,"ѧϰ");
 	strcpy(t[2].type,"ҽ��");
	strcpy(t[3].type,"��ͨ");
	strcpy(t[4].type,"ˮ��");
	strcpy(t[5].type,"����");
 	strcpy(t[6].type,"����");
	strcpy(t[7].type,"����");
	system("CLS");
	med();
	cursor(25,9);
	printf("��������Ҫ�������·�  (����������)");
	cursor(25,11);
	printf("��ݣ� ");
	cursor(37,11);
	printf("(������һ����λ����)");
	cursor(32,11);
	scanf("%d",&year);
	cursor(25,12);
	printf("�·ݣ� ");
	scanf("%d",&month);
	while(!(year>=1000&&year<=9999&&month>=1&&month<=12))
	{
		cursor(25,14);
		printf("�����·ݲ��Ϸ�,����������!");
		Sleep(1500);
		monthana(exp,cnt);
	}
	system("CLS");
	med3();
	cursor(25,5);
	printf("%d��%d�����ѷ���      ",year,month);
	cursor(20,7);
    printf("��������    �����ܽ��     ռ��֧���ٷֱ�");
	for(j=0;j<cnt[0];j++)
  {   
	  if(year==exp[j].time.year&&month==exp[j].time.month)
	  {
        switch(exp[j].type)
	{
		case 1: t[0].money+=exp[j].money;break;
		case 2: t[1].money+=exp[j].money;break;
		case 3: t[2].money+=exp[j].money;break;
		case 4: t[3].money+=exp[j].money;break;
		case 5: t[4].money+=exp[j].money;break;
		case 6: t[5].money+=exp[j].money;break;
		case 7: t[6].money+=exp[j].money;break;
		case 8: t[7].money+=exp[j].money;;break;	
	}
        sum=sum+exp[j].money;
  	  }	
  }	
  	  cursor(48,5);
  	  printf("�ܼ�%.2fԪ",sum);
  	  cursor(20,8);
	  sort2(t,8);
  	  for(j=0;j<8;j++)
	{
		printf("%s     %10.2fԪ    %10.2f%%",t[i].type,t[i].money,(t[i].money/sum)*100);
		i++;
		cursor(20,8+i);
	}	
	if(sum==0) 
	{
		system("CLS");
		med3();
		cursor(32,5);
		printf("%d��%d�����ѷ���      ",year,month);
		cursor(20,7);
    	printf("��������    �����ܽ��     ռ��֧���ٷֱ�");
		cursor(30,8);
		printf("����û�����Ѽ�¼��");
		cursor(27,12);
  		printf("-------- 1.���� --------");
  		cursor(27,13);
		scanf("%d",&x);
		if(x==1)
		menu5(exp,cnt);
	}
  	cursor(27,12+i);
  	printf("-------- 1.���� --------");
  	cursor(27,13+i);
	scanf("%d",&x);
	menu5(exp,cnt);
}

void yearana(expend exp[],int cnt[])                      //������� 
{
	int year,i=0,x,j;
	double sum=0;
	analyze t[8];
	analyze m[12];
	for(j=0;j<8;j++)
	t[j].money=0;
	strcpy(t[0].type,"��ʳ");
	strcpy(t[1].type,"ѧϰ");
 	strcpy(t[2].type,"ҽ��");
	strcpy(t[3].type,"��ͨ");
	strcpy(t[4].type,"ˮ��");
	strcpy(t[5].type,"����");
 	strcpy(t[6].type,"����");
	strcpy(t[7].type,"����");
	system("CLS");
	med();
	cursor(25,9);
	printf("��������Ҫ���������  (����������)");
	cursor(25,11);
	printf("��ݣ� ");
	cursor(37,11);
	printf("(������һ����λ����)");
	cursor(32,11);
	scanf("%d",&year);
	while(!(year>=1000&&year<=9999))
	{
		cursor(25,12);
		printf("������ݲ��Ϸ�,����������!");
		Sleep(1500);
		yearana(exp,cnt);
	}
	system("CLS");
	med3();
	cursor(28,5);
	printf("%d�����ѷ���      ",year);
	cursor(20,7);
    printf("��������    �����ܽ��     ռ��֧���ٷֱ�");
	for(j=0;j<cnt[0];j++)
  {   
	  if(year==exp[j].time.year)
	  {
        switch(exp[j].type)
	{
		case 1: t[0].money+=exp[j].money;break;
		case 2: t[1].money+=exp[j].money;break;
		case 3: t[2].money+=exp[j].money;break;
		case 4: t[3].money+=exp[j].money;break;
		case 5: t[4].money+=exp[j].money;break;
		case 6: t[5].money+=exp[j].money;break;
		case 7: t[6].money+=exp[j].money;break;
		case 8: t[7].money+=exp[j].money;;break;	
	}
        sum=sum+exp[j].money;
  	  }	
  }	
  	  cursor(48,5);
  	  printf("�ܼ�%.2fԪ",sum);
	  sort2(t,8);
	  cursor(20,8);
  	  for(j=0;j<8;j++)
	{
		printf("%s     %10.2fԪ    %10.2f%%",t[i].type,t[i].money,(t[i].money/sum)*100);
		i++;
		cursor(20,8+i);
	}	
	if(sum==0) 
	{
		system("CLS");
		med3();
		cursor(32,5);
		printf("%d�����ѷ���      ",year);
		cursor(20,7);
    	printf("��������    �����ܽ��     ռ��֧���ٷֱ�");
		cursor(30,8);
		printf("����û�����Ѽ�¼��");
		cursor(27,11);
  		printf("-------- 1.���� --------");
  		cursor(27,12);
		scanf("%d",&x);
		if(x==1)
		menu5(exp,cnt);
		
	}
  	cursor(20,12+i);
	printf("-------- 1.�����鿴����������� --------");
	cursor(27,13+i);
	printf("-------- 2.���� --------");
	cursor(27,14+i);
	scanf("%d",&x);
	if(x==2)
	menu5(exp,cnt);
	else
	{
	      system("CLS");
	      med3();
	      for(j=0;j<12;j++)
			m[j].money=0;
			strcpy(m[0].type,"1��");
			strcpy(m[1].type,"2��");
 			strcpy(m[2].type,"3��");
			strcpy(m[3].type,"4��");
			strcpy(m[4].type,"5��");
			strcpy(m[5].type,"6��");
 			strcpy(m[6].type,"7��");
			strcpy(m[7].type,"8��");
			strcpy(m[8].type,"9��");
			strcpy(m[9].type,"10��");
 			strcpy(m[10].type,"11��");
			strcpy(m[11].type,"12��");
	      cursor(28,5);
	      printf("%d�����ѷ���      ",year);
	      cursor(20,7);
          printf("�����·�    �����ܽ��     ռ��֧���ٷֱ�");
	      for(j=0;j<cnt[0];j++)
         {   
	  		if(year==exp[j].time.year)
	    	{
        			switch(exp[j].time.month)
				{
				case 1: m[0].money+=exp[j].money;break;
				case 2: m[1].money+=exp[j].money;break;
				case 3: m[2].money+=exp[j].money;break;
				case 4: m[3].money+=exp[j].money;break;
				case 5: m[4].money+=exp[j].money;break;
				case 6: m[5].money+=exp[j].money;break;
				case 7: m[6].money+=exp[j].money;break;
				case 8: m[7].money+=exp[j].money;;break;
				case 9: m[8].money+=exp[j].money;break;
				case 10: m[9].money+=exp[j].money;break;
				case 11: m[10].money+=exp[j].money;break;
				case 12: m[11].money+=exp[j].money;;break;	
				}	
  	        }	
         }	
  	  	cursor(48,5);
  	  	printf("�ܼ�%.2fԪ",sum);
	  	sort2(m,12);
	  	cursor(20,8);
	  	i=0;
  	  	for(j=0;j<12;j++)
	  {
		printf("%s     %10.2fԪ    %10.2f%%",m[j].type,m[j].money,(m[j].money/sum)*100);
		i++;
		cursor(20,8+i);
	  }	
	    cursor(27,10+i);
		printf("-------- 1.���� --------");
  		cursor(27,11+i);
		scanf("%d",&x);
		menu5(exp,cnt);		
	}
}

void daycheck(expend exp[],int cnt[])                                   //���ղ�ѯ 
{
	int year,month,day,i=0,x;
	expend n;
	system("CLS");
	med();
	cursor(25,9);
	printf("�������ѯ����  (����������)");
	cursor(25,11);
	printf("��ݣ� ");
	cursor(37,11);
	printf("(������һ����λ����)");
	cursor(32,11);
	scanf("%d",&year);
	cursor(25,12);
	printf("�·ݣ� ");
	scanf("%d",&month);
	cursor(25,13);
	printf("���ڣ� ");
	scanf("%d",&day);
	while(!datejudge(year,month,day))
	{
		cursor(25,14);
		printf("�������ڲ��Ϸ�,����������!");
		Sleep(1500);
		daycheck(exp,cnt);
	}
	system("CLS");
	med2();
	cursor(37,5);
	printf("��ѯ���");
	cursor(18,6);
    printf("��������      ��������    ���ѽ��     ��ע");
	cursor(16,7);
	FILE *fp;
	fp=fopen("D:\\expend.txt","r");
	if(fp==0)
	{
		printf("file error\n");
		exit(1);
	}
	fscanf(fp,"%d %d %d %d %lf %s",&n.time.year,&n.time.month,&n.time.day,&n.type,&n.money,n.remark);
	while(!feof(fp))
  {   
	  if(year==n.time.year&&month==n.time.month&&day==n.time.day)
	  {
        printf("%d��%d��%d��      ",n.time.year,n.time.month,n.time.day);
        switch(n.type)
	{
		case 1: printf("��ʳ");break;
		case 2: printf("ѧϰ");break;
		case 3: printf("ҽ��");break;
		case 4: printf("��ͨ");break;
		case 5: printf("ˮ��");break;
		case 6: printf("����");break;
		case 7: printf("����");break;
		case 8: printf("����");break;
		default: daycheck(exp,cnt);	
	}
        printf("  %10.2f       %s",n.money,n.remark);
        i++;
        cursor(16,7+i);
  	  }
  	  fscanf(fp,"%d %d %d %d %lf %s",&n.time.year,&n.time.month,&n.time.day,&n.type,&n.money,n.remark);
  }
  	fclose(fp);
    if(i==0)
    {
		cursor(32,7+i);
  		printf("û���ҵ����������Ľ��!");
    }
  	cursor(32,12+i);
  	printf("�Ƿ���Ҫ������ѯ?");
  	cursor(32,13+i);
  	printf("-------- 1.�� --------");
  	cursor(32,14+i);
  	printf("-------- 2.�� --------");
  	cursor(32,15+i);
	scanf("%d",&x);
	if(x==1)
	daycheck(exp,cnt);
	else
	menu4(exp,cnt);
}

void monthcheck(expend exp[],int cnt[])                           //���²�ѯ 
{
	int year,month,day,i=0,x,j;
	double sum=0;
	system("CLS");
	med();
	cursor(25,10);
	printf("�������ѯ�·�  (����������)");
	cursor(25,11);
	printf("��ݣ� ");
	cursor(37,11);
	printf("(������һ����λ����)");
	cursor(32,11);
	scanf("%d",&year);
	cursor(25,12);
	printf("�·ݣ� ");
	scanf("%d",&month);
	while(!(year>=1000&&year<=9999&&month>=1&&month<=12))
	{
		cursor(25,13);
		printf("�����·ݲ��Ϸ�,����������!");
		Sleep(1500);
		monthcheck(exp,cnt);
	}
	system("CLS");
	med2();
	cursor(20,5);
	printf("%d��%d���������      ",year,month);
	cursor(18,8);
    printf("��������      ��������    ���ѽ��     ��ע");
	cursor(16,9);
	sort1(exp,cnt);
	for(j=0;j<cnt[0];j++)
  {   
	  if(year==exp[j].time.year&&month==exp[j].time.month)
	  {
        printf("%d��%d��%d��      ",exp[j].time.year,exp[j].time.month,exp[j].time.day);
        switch(exp[j].type)
	{
		case 1: printf("��ʳ");break;
		case 2: printf("ѧϰ");break;
		case 3: printf("ҽ��");break;
		case 4: printf("��ͨ");break;
		case 5: printf("ˮ��");break;
		case 6: printf("����");break;
		case 7: printf("����");break;
		case 8: printf("����");break;
		default: monthcheck(exp,cnt);	
	}
        printf("  %10.2f         %s",exp[j].money,exp[j].remark);
        sum=sum+exp[j].money;
        i++;
        cursor(16,9+i);
  	  }
  }
  	cursor(48,5);
  	printf("�ܼ�%.2fԪ",sum);
    if(i==0)
    {
		cursor(32,9+i);
  		printf("����û�����Ѽ�¼!");
    }
  	cursor(32,14+i);
  	printf("�Ƿ���Ҫ����Ϣ����Ϊ�ļ�?");
  	cursor(32,15+i);
  	printf("-------- 1.�� --------");
  	cursor(32,16+i);
  	printf("-------- 2.�� --------");
  	cursor(32,17+i);
  	scanf("%d",&x);
	if(x==1)
	{
		filesave2(exp,cnt,year,month,sum);
		cursor(38,18+i);
		printf("����ɹ�!");
	}
	cursor(32,20+i);
  	printf("�Ƿ���Ҫ������ѯ?");
  	cursor(32,21+i);
  	printf("-------- 1.�� --------");
  	cursor(32,22+i);
  	printf("-------- 2.�� --------");
  	cursor(32,23+i);
	scanf("%d",&x);
	if(x==1)
	monthcheck(exp,cnt);
	else
	menu4(exp,cnt);
}

void intercheck(expend exp[],int cnt[])                                         //�����ѯ 
{
    int y1,m1,d1,i=0,x,j;
    int y2,m2,d2;
	double sum=0;
	system("CLS");
	med();
	cursor(25,6);
	printf("�������ʼ����  (����������)");
	cursor(25,7);
	printf("��ݣ� ");
	cursor(37,7);
	printf("(������һ����λ����)");
	cursor(32,7);
	scanf("%d",&y1);
	cursor(25,8);
	printf("�·ݣ� ");
	scanf("%d",&m1);
	cursor(25,9);
	printf("���ڣ� ");
	scanf("%d",&d1);
	while(!(datejudge(y1,m1,d1)))
	{
		cursor(25,10);
		printf("�������ڲ��Ϸ�,����������!");
		Sleep(1500);
		intercheck(exp,cnt);
	}
	cursor(25,10);
	printf("�������������(����������)");
	cursor(25,11);
	printf("��ݣ� ");
	cursor(37,11);
	printf("(������һ����λ����)");
	cursor(32,11);
	scanf("%d",&y2);
	cursor(25,12);
	printf("�·ݣ� ");
	scanf("%d",&m2);
	cursor(25,13);
	printf("���ڣ� ");
	scanf("%d",&d2);
	while(!(datejudge(y2,m2,d2)))
	{
		cursor(25,14);
		printf("�������ڲ��Ϸ�,����������!");
		Sleep(1500);
		intercheck(exp,cnt);
	}
	while(!(interjudge(y2,m2,d2)>=interjudge(y1,m1,d1)))
	{
		cursor(25,15);
		printf("�������䲻�Ϸ�,����������!");
		Sleep(1500);
		intercheck(exp,cnt);
	}
	system("CLS");
	med2();
	cursor(15,5);
	printf("%d��%d��%d��--%d��%d��%d���������      ",y1,m1,d1,y2,m2,d2);
	cursor(18,8);
    printf("��������      ��������    ���ѽ��     ��ע");
	cursor(16,9);
	sort1(exp,cnt);
	for(j=0;j<cnt[0];j++)
  {   
	  if(interjudge(exp[j].time.year,exp[j].time.month,exp[j].time.day)>=interjudge(y1,m1,d1)&&interjudge(exp[j].time.year,exp[j].time.month,exp[j].time.day)<=interjudge(y2,m2,d2))
	  {
        printf("%d��%d��%d��      ",exp[j].time.year,exp[j].time.month,exp[j].time.day);
        switch(exp[j].type)
	{
		case 1: printf("��ʳ");break;
		case 2: printf("ѧϰ");break;
		case 3: printf("ҽ��");break;
		case 4: printf("��ͨ");break;
		case 5: printf("ˮ��");break;
		case 6: printf("����");break;
		case 7: printf("����");break;
		case 8: printf("����");break;
		default: intercheck(exp,cnt);	
	}
        printf("  %10.2f         %s",exp[j].money,exp[j].remark);
        sum=sum+exp[j].money;
        i++;
        cursor(16,9+i);
        if(i>280)
        {
        	cursor(14,10+i);
			printf("���������������ʾ��Χ�ѳ�����Ļ��������С,�޷�������ʾ!");
        	cursor(20,11+i);
        	printf("����С�������²�ѯ(���䲻Ҫ����4����)!");
        	Sleep(10000);
        	intercheck(exp,cnt);
        }
  	  }
  }
  	cursor(56,5);
  	printf("�ܼ�%.2fԪ",sum);
    if(i==0)
    {
		cursor(32,9+i);
  		printf("�ö�ʱ��û�����Ѽ�¼!");
    }
  	cursor(32,14+i);
  	printf("�Ƿ���Ҫ����Ϣ����Ϊ�ļ�?");
  	cursor(32,15+i);
  	printf("-------- 1.�� --------");
  	cursor(32,16+i);
  	printf("-------- 2.�� --------");
  	cursor(32,17+i);
  	scanf("%d",&x);
	if(x==1)
	{
		filesave3(exp,cnt,y1,m1,d1,y2,m2,d2,sum);
		cursor(38,18+i);
		printf("����ɹ�!");
	}
	cursor(32,21+i);
  	printf("�Ƿ���Ҫ������ѯ?");
  	cursor(32,22+i);
  	printf("-------- 1.�� --------");
  	cursor(32,23+i);
  	printf("-------- 2.�� --------");
  	cursor(32,24+i);
	scanf("%d",&x);
	if(x==1)
	intercheck(exp,cnt);
	else	
	menu4(exp,cnt);
}

void password(char p[])                                  //�������� 
{
	int i=0;
	while(p[i]=getch())
	{
		if(p[i]==13)
		break;
		if(p[i]!='\b')
		{
			printf("*");
			i++;
		}
		else
		{
			printf("\b \b");
			i--;
		}	
	}
	p[i]='\0';
}

void sort1(expend exp[],int cnt[])                                    //���������� 
{
	int i,k,index;
	expend t;
	for(k=0;k<cnt[0];k++)
	{
		index=k;
		for(i=k+1;i<cnt[0];i++)
		if(interjudge(exp[i].time.year,exp[i].time.month,exp[i].time.day)<interjudge(exp[index].time.year,exp[index].time.month,exp[index].time.day))
			index=i;
			if(index!=k)
			{
				t=exp[index];
				exp[index]=exp[k];
				exp[k]=t;
			}
	}
}

void sort2(analyze ana[],int n)                                  //��������� 
{
	int i,k,index;
	analyze temp;
	for(k=0;k<n;k++)
	{
		index=k;
		for(i=k+1;i<n;i++)
		if(ana[i].money>ana[index].money)
			index=i;
			if(index!=k)
			{
				temp=ana[index];
				ana[index]=ana[k];
				ana[k]=temp;
			}
	}
}

int datejudge(int y, int m, int d)                           //�ж����ںϷ��� 
{
        int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
                month[1] = 29; 
        return  y>=1000&&y<=9999&&m > 0 && m <= 12 && d > 0 && d <= month[m - 1]; 
}

int interjudge(int y,int m,int d)                         //���ڴ�С�Ƚ� 
{
	return y*10000+m*100+d;	
}

