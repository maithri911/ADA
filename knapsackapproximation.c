#include<stdio.h>
#define MAX_ITEMS 100
double computeMaxValue (double w,double weight[],double value[],double ratio[],int nItems){
double cw=0;
double cv=0;
printf("\n Items considered are:");
while(cw<w){
int item=getNextItem(weight,value,ratio,nItems);
if(item==-1){
break;
}
printf("item %d ",item+1);
if(cw+weight[item]<=w){
cw+=weight[item];
cv+=value[item];
ratio[item]=0;
}
else{
cv+=(ratio[item]*(w-cw));
cw+=(w-cw);
break;
}}
return cv;
}
int getNextItem(double weight[],double value[],double ratio[],int nItems){
int i;
double highest=0;
int index=-1;
for(i=0;i<nItems;i++){
if(ratio[i]>highest){
highest=ratio[i];
index=i;
}}
return index;
}	
int main(){
int nItems;
int i;
double w,weight[MAX_ITEMS],value[MAX_ITEMS];
double ratio[MAX_ITEMS];
printf("Enter the number of items:");
scanf("%d",&nItems);
printf("Enter the weights ofthe items\n");
for(i=0;i<nItems;i++){
scanf("%lf",&weight[i]);
}
printf("Enter the value/profit of items:\n");
for(i=0;i<nItems;i++){
scanf("%lf",&value[i]);
}
for(i=0;i<nItems;i++){
ratio[i]=value[i]/weight[i];
}
printf("Enter the capacity of knapsack:");
scanf("%lf",&w);
printf("\n The maximum value in a knapsack capacity %2f is:%2f\n",w,computeMaxValue(w,weight,value,ratio,nItems));
return 0;
}
