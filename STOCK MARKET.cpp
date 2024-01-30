#include<stdio.h>
#include<conio.h>
#include <math.h>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>
int prev(int *p,int n)
{
while(p[n]==p[n-1])
{
n--;
}
return n-1;
}
int next(int *p,int n )
{
while(p[n]==p[n+1])
{
n++;
}
return n+1;
}
int main()
{
int i,j,m,y,amt=0,n=0,v=0,d,b,c1=0;
printf( "enter month of transaction: ");
scanf("%d",&m);
printf("enter year of transaction: ");
scanf("%d",&y);

switch(m)
{
 case 1:
 case 3:
 case 5:
 case 7:
 case 8:
 case 10:
 case 12:
  d=31;
  break;
 
 case 2:
  if((y%400==0)||((y%100!=0)&&(y%4==0)))
  {
   d=29;
  }
     else
     {
      d=28;
  }
  break;
 case 4:
 case 6:
 case 9:
 case 11:
  d=30;
  break;
 default:
  printf("\n Invalid number");  
}
int sp[d];
printf(" stock price for %d days\n",d);
int u;
for(i=1;i<=d;i++)
{
FILE *myFile;
    myFile = fopen("C:\\Users\\Rupali Dalavi\\OneDrive\\Desktop\\hello.txt", "r");

    //read file into array
 for (i= 1; i<=d; i++){
        fscanf(myFile, "%d,", &sp[i] );
    }

    for (i= 1; i<=d; i++){
        printf("%d/%d/%d\t",i,m,y);
  printf("%d\n",sp[i]);
    }

    fclose(myFile);

}

printf("Enter budget for the month\n");
scanf("%d",&b);
struct account
{
int ns;// no of stocks
int td;// date of transaction
int ch;// choice of transaction
};
struct account ac[d];
printf("enter initial number of stocks: \n");
scanf("%d",&ac[0].ns);
printf("enter initial date of purchase: \n");
scanf("%d",&ac[0].td);
if((ac[0].ns*sp[ac[0].td]) > b)
{
printf("you have exceeded the budget\n");
}
else
{
n=n+ac[0].ns;
amt=amt-(sp[ac[0].td]*ac[0].ns);
b=b-(sp[ac[0].td]*ac[0].ns);
ac[0].ch=1;
j=1;
c1++;
printf("\namount=%d",amt);
}
while(j<=d)
{
printf("\n1:purchase\n2:sell\n3:exit\n");
printf("enter choice: ");
scanf("%d",&ac[j].ch);
if(ac[j].ch==3)
break;
switch(ac[j].ch)
{
case 1:
printf("enter date of transaction: \n");
scanf("%d",&ac[j].td);
printf("enter no of stocks: ");
scanf("%d",&ac[j].ns);
if((sp[ac[j].td]*ac[j].ns)>b)
{
printf("you have exeeded the budget\n");
}
else
{
amt=amt-(sp[ac[j].td]*ac[j].ns);
b=b-(sp[ac[0].td]*ac[0].ns);
n=n+ac[j].ns;
j++;
c1++;
printf("\namount=%d",amt);
}
break;
case 2:
printf("enter date of transaction:\n");
scanf("%d",&ac[j].td);
printf("enter no of stocks: \n");
scanf("%d",&ac[j].ns);
if(ac[j].ns>n)
{
printf("inadequate no of stocks available\n");
}
else
{
amt=amt+(sp[ac[j].td]*ac[j].ns);
b=b+(sp[ac[0].td]*ac[0].ns);
n=n-ac[j].ns;
j++;
c1++;
printf("\namount=%d",amt);
}
break;
default:
printf("invalid choice");
}//switch
}//while
if(amt<0)
{
printf("you have incured loss of Rs: %d",-amt);
}
else
{
printf("you have incurred profit of Rs: %d\n",amt);
b=b+amt;
}
v=n*sp[d];
printf("\nvalue of stock at hand: %d\n",v);
printf("\n");
int val[d];
int date[d];
j=1;
val[1]=sp[1];
date[1]=1;
i=2;
while(sp[i]<=sp[i-1] && i<d)
{
val[1]=sp[i];
date[1]=i;
i++;
}
while(i<d) //update this loop for handelling stock price remaining same intermediately
//declare 2 functions called prev(i) and next(i)
//prev(i) will decrement i and return the value of i which has sp[] value not same as sp[i]
//next(i) will increment i and return the value of i which has sp[] value not same as sp[i]
{
if(sp[prev(sp,i)]>sp[i] && sp[i]<sp[next(sp,i)])
{
 j++;
 date[j]=i;
val[j]=sp[i];
}
else if(sp[prev(sp,i)]<sp[i] && sp[i]>sp[next(sp,i)])
{
 j++;
 date[j]=i;
val[j]=sp[i];
}
i=next(sp,i);
}
if(j%2!=0)
{
if(val[j]<=sp[d])
{

 j++;
 val[j]=sp[d];
}
else
{
 j--;
}

}
for(i=1;i<=j;i++)
{
printf("%d\t",val[i]);
}
int pp=0; //predicted profit
i=1;
while(i<=j)
{
n=b/val[i];
n=floor(n);
//b=b-(n*val[i]);
//b=b+(n*val[i+1]);
int cp=n*(val[i+1]-val[i]);
pp=pp+cp;
i=i+2;
b=b+cp;
}
printf("\npredicted profit: %d\n",pp);
int gd = DETECT,gm;
 initgraph(&gd,&gm,"\\tc\\bgi");
 line(50,640,850,640);//total width of x is 800
 line(50,640,50,40);//total width of y is 600
 char s1[5];
 for(i=1;i<=d;i++)
 {
  line(50+i*25,635,50+i*25,645);
  itoa(i,s1,10);
  outtextxy(47+i*25,650,s1);//convert string 10 to the value of i.Use
 }
 int min,max;
 min=val[1];
 max=val[2];
 for(i=3;i<=j;i=i+2)
 {
  if(val[i]<min) min=val[i];
  if(val[i+1]>max) max=val[i+1];
 }

int ybase=590;
int ylow=(min/10)*10;
int yhigh= ((max/10)+1)*10;
float yscale=500/(yhigh-ylow);
char s2[5];
int k=0;
int fact=((yhigh-ylow)/10);
       
 for(i=590;i>40;i=i-50)
 {
  line(45,i,55,i);
}
for(k=0;k<11;k++)
{
sprintf(s2,"%d",(ylow+k*fact));
  puts(s2);
  settextstyle(8,0,2);

   outtextxy(15,583-k*50,s2);
}
 for(i=1;i<d;i++)
 {
  line(50+i*25,ybase-(sp[i]-ylow)*(yscale),50+(i+1)*25,ybase-(sp[i+1]-ylow)*(yscale));
}
for(i=0;i<c1;i++)
{
circle(50+(ac[i].td)*25,ybase-(sp[ac[i].td]-ylow)*yscale,10);
}
/*for(i=1;i<=j;i++)
{
if(i%2==0)
{
setcolor(BLUE);

circle(50+date[i]25,640-val[i](640/max),5);
floodfill(50+date[i]25,640-val[i](640/max),15);
}
else{
   setcolor(RED);
circle(50+date[i]25,640-val[i](640/max),5);
floodfill(50+date[i]25,640-val[i](640/max),15);
}
}*/
 getch();
 closegraph();
return 0;
}
