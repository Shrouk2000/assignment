#include<stdio.h>
#include<pthread.h>
int not;
int mat1[10][10],mat2[10][10],res[10][10];
int m,n;
void matrix_read(){
int i,j;
printf("enetr size of matrix");
scanf("%d %d",&m,&n);
printf("enetr matrix 1");
for(i=0;i<m;i++)
for(j=0;j<n;j++)
scanf("%d",&mat1[i][j]);
printf("enetr matrix2");
for(i=0;i<m;i++)
for(j=0;j<n;j++)
scanf("%d",&mat2[i][j]);
}

void print_matrix(int x[10][10])
{
int i,j;
for(i=0;i<m;i++){
printf("/n");
for(j=0;j<n;j++)
printf("%d",x[i][j]);
}
}
void *multiplication(void *arg){
long int num=(int)arg;
int i,j,k;
for(i=0;i<m;i++){
for(j=0;j<n;j++){
res[i][j]=0;
for(k=0;k<n;k++){
res[i][j]+=mat1[i][k]*mat2[k][i];
}
}
}
printf("\n matrix by thread %ld : \n",num);
print_matrix(res);
}
 int main(){
 long int i,j;
 pthread_t tid[10];
 matrix_read();
 printf("enter number of threads");
 scanf("%d",&not);
 //creating thread
 for(i=0;i<not;i++)
 
 pthread_create(&tid[i],NULL,multiplication,(void*)i);
 for(j=0;j<not;j++)
 pthread_join(tid[j],NULL);
 }
