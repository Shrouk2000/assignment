#include<stdio.h>
//#include<conio.h>
#define max 30
void main(){
int i,j,n,t,p[max],bt[max],wt[max],tat[max];
float awt=0, atat=0;
//clrscr();
printf("enetr the number of process");
scanf("%d",&n);
printf("enter the process number");
for(i=0;i<n;i++){
scanf("%d",&p[i]);
}
printf("enter the burst time of the process");
for(i=0;i<n;i++){
scanf("%d",&bt[i]);
}
for(i=0;i<n;i++){
for(j=0;j<n;j++){
if(bt[j]>bt[j+1]){
t=bt[j];
bt[j]=bt[j+1];
bt[j+1]=t;
t=p[j];
p[j]=p[j+1];
p[j+1]=t;

}
}
}
printf("process \t burst time \t waiting time \t turnarround time\n");
for(i=0;i<n;i++){
wt[i]=0;
tat[i]=0;
for(j=0;j<i;j++){
wt[i]=wt[i]+bt[j];
}
tat[i]=wt[i]+bt[i];
awt=awt+awt[i];
atat=atat+t[i];
printf("%d\t %d\t\t%d\t\t %d\n",p[i],bt[i],wt[i],tat[i]);
}
awt=awt/n;
atat=atat/n;
printf("average waiting time %f",awt);
printf("average turn arond time%f",atat);
//getch();
}
