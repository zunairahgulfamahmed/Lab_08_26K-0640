#include<stdio.h>
void print () ;
int packNumber () ;
long long mobileNumber () ;
int amount (int packNumber) ;
int tax (int amount) ;
int bonus (int amount) ;
void rechargeSlip (int PackNumber,long long MobileNumber,int Amount,int Tax,int Bonus)
{
        printf("\n\tRecharge Slip\t") ;
        printf("\n===============================\n") ;
        printf("\nPack Number: %d",PackNumber) ;
        printf("\nMobile Number: %lld",MobileNumber) ;
        printf("\nAmount: %d PKR",Amount) ;
        printf("\nTax: %d PKR",Tax) ;
        printf("\nBonus: %d PKR",Bonus) ;
        printf("\nFinal Amount: %d PKR",Amount+Bonus) ; 
        printf("\n===============================\n") ;
}


int main ()
{
    int i ;
    int totalAmount = 0 ;
    for (i=0;i<3;i++)
    {
        print() ;
        int PackNumber = packNumber () ;
        long long MobileNumber = mobileNumber () ; 
        int Amount = amount (PackNumber) ;
        int Tax = tax (Amount) ;
        int Bonus = bonus(Amount) ;
        rechargeSlip(PackNumber,MobileNumber,Amount,Tax,Bonus) ;
        totalAmount = totalAmount + Amount + Tax + Bonus ;
    }
    printf("\nTotal Amount Spent = %d PKR",totalAmount) ;
    
}

void print () 
{
    printf("\nSelect your desired Pack Number\n1)100 PKR\n2)200 PKR\n3)500 PKR\n4)1000 PKR\n") ;
}

int packNumber () 
{
    int PackNumber ;
    scanf("%d",&PackNumber) ;
    return PackNumber ;
}

long long mobileNumber () 
{
    long long MobileNumber ;
    printf("Enter your mobile number\n") ;
    scanf("%lld",&MobileNumber) ;
    return MobileNumber ;
}

int amount (int packNumber) 
{
    int amountt ;
    switch (packNumber)
    {
        case 1: amountt = 100 ;
                break;
        case 2: amountt = 200 ;
                break;
        case 3: amountt = 500 ;
                break;
        case 4: amountt = 1000 ;
                break;
        default : printf("Invalid pack number"); 
                
    }
    return amountt ;
}

int tax (int amount) 
{
    int tax = (amount*0.15) ;
    return tax ;
}

int bonus (int amount) 
{
    int Bonus ;
    if(amount>=500)
    {
        Bonus = 0.10*amount ;
    }
    else
    {
        Bonus = 0 ;
    }
    return Bonus ;
}