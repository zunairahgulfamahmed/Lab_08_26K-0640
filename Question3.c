
#include <stdio.h>


void printFun();
int routeFun();
int seatsFun();
int farePerSeatFun(int routeNum);
int totalFareFun(int seatFare, int seats);
char seatTypeFun();
double FinalFareFun(char seatType, int totalFare);
void ticketFun(int routeNum, int seats, char seatType, double finalFare);

int main()
{
    printFun();

    double earnings = 0;

    for (int i = 1; i <= 2; i++)
    {
        printf("\n========== PASSENGER %d ==========\n", i);

        int RouteNum = routeFun();
        int seats = seatsFun();

        int farePerSeat = farePerSeatFun(RouteNum);
        int totalFare = totalFareFun(farePerSeat, seats);

        char seatType = seatTypeFun();

        double FinalFare = FinalFareFun(seatType, totalFare);

        ticketFun(RouteNum, seats, seatType, FinalFare);

        earnings += FinalFare;
    }

    printf("\nTotal earnings of the bus company: Rs. %.2lf\n", earnings);

    return 0;
}

void printFun()
{
    printf("========== BUS TICKET BOOKING ==========\n");
    printf("1. Karachi to Hyderabad - Rs. 800\n");
    printf("2. Karachi to Sukkur    - Rs. 2200\n");
    printf("3. Karachi to Multan    - Rs. 3500\n");
}


int routeFun()
{
    int route;

    do
    {
        printf("\nEnter route number (1-3): ");
        scanf("%d", &route);

        if (route < 1 || route > 3)
            printf("Invalid route! Try again.\n");

    } while (route < 1 || route > 3);

    return route;
}


int seatsFun()
{
    int seats;

    do
    {
        printf("Enter number of seats (1-6): ");
        scanf("%d", &seats);

        if (seats < 1 || seats > 6)
            printf("Invalid number of seats! Try again.\n");

    } while (seats < 1 || seats > 6);

    return seats;
}


int farePerSeatFun(int routeNum)
{
    if (routeNum == 1)
        return 800;

    else if (routeNum == 2)
        return 2200;

    else
        return 3500;
}


int totalFareFun(int seatFare, int seats)
{
    return seatFare * seats;
}


char seatTypeFun()
{
    char type;

    do
    {
        printf("Select seat type (E = Economy, B = Business): ");
        scanf(" %c", &type);

        if (type != 'E' && type != 'e' &&
            type != 'B' && type != 'b')
        {
            printf("Invalid seat type! Try again.\n");
        }

    } while (type != 'E' && type != 'e' &&
             type != 'B' && type != 'b');

    return type;
}


double FinalFareFun(char seatType, int totalFare)
{
    if (seatType == 'B' || seatType == 'b')
        return totalFare + (totalFare * 0.30);

    else
        return totalFare;
}

void ticketFun(int routeNum, int seats, char seatType, double finalFare)
{
    printf("\n========== YOUR TICKET ==========\n");

    if (routeNum == 1)
        printf("Route: Karachi to Hyderabad\n");

    else if (routeNum == 2)
        printf("Route: Karachi to Sukkur\n");

    else
        printf("Route: Karachi to Multan\n");

    printf("Number of seats: %d\n", seats);

    if (seatType == 'E' || seatType == 'e')
        printf("Seat type: Economy\n");

    else
        printf("Seat type: Business\n");

    printf("Final fare: Rs. %.2lf\n", finalFare);

    printf("================================\n");
}
