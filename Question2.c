#include<stdio.h>
void printFun () ;
int roomTypeFun () ;
int daysFun () ;
int chargesFun (int days, int room) ;
int medicineBillFun () ;
int discountFun (int daysStayed,int total) ;
int seniorFun (int FinalAmount) ;
void BillFun (int room,int days,int charges,int medicineBill,int discount,int FinalBill) ;
int main ()
{
    printFun () ;
    int room = roomTypeFun () ;
    int days = daysFun() ;
    int charges = chargesFun (days,room) ;
    int medicineBill = medicineBillFun () ;
    int total = charges + medicineBill ;
    int discount = discountFun (days,total) ;
    int FinalAmount = total - discount ;
    int FinalBill = seniorFun(FinalAmount) ;
    BillFun (room,days,charges,medicineBill,discount,FinalBill) ;
    return 0 ;
}

void printFun () 
{
    printf("\t======ABC HOSPITAL======\t") ;
    printf("\nWhich room do you want ?\n1)General Ward is Rs. 1500/day\n2)Semi-Private is Rs. 3500/day\n3)Private is Rs. 6000/day\n") ;
}

int roomTypeFun () 
{
    int room ;
    scanf("%d",&room) ;
    return room ;
}

int daysFun () 
{
    printf("\nEnter the number of days you want to stay (1-30)\n") ;
    int days ;
    scanf("%d",&days) ;
    return days ;
}

int chargesFun (int days, int room) 
{
    int roomprice;
    if (room==1)
    {
        roomprice = 1500 ;   
    }
    else if (room==2)
    {
        roomprice = 3500 ;
    }
    else
    {
        roomprice = 6000 ;
    }
    int charges = roomprice * days ;
    return charges ;
}

int medicineBillFun () 
{
    int medicine;
    printf("\nEnter your medidcine Bill\n") ;
    scanf("%d",&medicine) ;
    int medicineBill = medicine + (0.05*medicine) ;
    return medicineBill ;
}

int discountFun (int daysStayed, int total) 
{
    int discount ;
    if (daysStayed>=7)
    {
       discount =  0.05*total ;
    }
    return discount ;
}

int seniorFun (int FinalAmount) 
{
    int x,y ;
    printf("Are you a senior citizen\n1)Yes\n2)No") ;
    scanf("%d",&x) ;
    if (x==1)
    {
        if (FinalAmount>1000)
        {
            FinalAmount = FinalAmount - 1000 ;
        }
        else
        {
            FinalAmount = FinalAmount ;
        }
    }
    else
    {
        FinalAmount = FinalAmount ;
    }
    return FinalAmount ;

}

void BillFun (int room,int days,int charges,int medicineBill,int discount,int FinalBill) 
{
    printf("\n==================================") ;
    printf("\n\tFinal Bill Reciept\t") ;
    printf("\n==================================") ;
    if (room==1)
    {
        printf("\nRoom Name: General Ward") ;   
    }
    else if (room==2)
    {
        printf("\nRoom Name: Semi Private") ;
    }
    else
    {
        printf("\nRoom Name: Private") ;
    }
    printf("\nDays: %d",days) ;
    printf("\nRoom Charges: %d", charges) ;
    printf("\nMedicine Charges: %d",medicineBill) ;
    printf("\nDiscount: %d", discount) ;
    printf("\nFinal Bill: %d",FinalBill) ;
}