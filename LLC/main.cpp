//
//  main.cpp
//  LLC
//
//  Created by 刘隆昌 on 15-1-31.
//  Copyright (c) 2015年 刘隆昌. All rights reserved.
//

#include <iostream>


#define ElementNumber 10

void quickSort(int a[],int left,int right);
void printList(int a[], int n);
void quick(int *a,int i,int j);


#pragma mark 入口函数  main主函数
int main(int argc, const char * argv[]) {
    // insert code here...

    int list[ElementNumber];
    for (int i=0; i<ElementNumber; i++) {
        
        list[i] = (rand())%30;
        for (int j=i-1; j>=0; j--) {
            
            while (list[i]==list[j]) {
                list[i]= (rand())%20;
            }
            
        }
        
    }
    
    
    std::cout<<"快速排序之前的数组：";
    printList(list, ElementNumber);
    
    
    /*==快排*/
    quick(list,0,9);
    /*==*/
    
    
    std::cout<<"快速排序之后的数组：";
    printList(list, ElementNumber);
    
    return 0;
}

#pragma mark 快速排序法实现
void quick(int *a,int i,int j)
{
    int m,n,temp,k;
    m=i;n=j;
    k=a[(i+j)/2]; /*选取的参照*/
    do {
        while(a[m]<k&&m<j) m++; /* 从左到右找比k大的元素*/
        while(a[n]>k&&n>i) n--; /* 从右到左找比k小的元素*/
        if(m<=n) { /*若找到且满足条件，则交换*/
            temp=a[m];
            a[m]=a[n];
            a[n]=temp;
            m++;n--;
        }
    }while(m<=n);
    if(m<j) quick(a,m,j); /*运用递归*/
    if(n>i) quick(a,i,n);
}


#pragma mark 打印数组
void printList(int a[], int n){
    for (int i=0; i<n; i++) {
        std::cout<<a[i]<<" ";
    }
    std::cout<<"\n";
}

