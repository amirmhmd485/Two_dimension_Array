#include <iostream>
using namespace std;
int main(){


    int R , S;
    cout << "Enter the Number of Rows \n";
    cin >> R;
    cout << "Enter the Number of Seats \n";
    cin >> S;
    int cinemaArray [R][S];
    int sizeOfArray = sizeof(cinemaArray) / sizeof(int);
    int totalNumberOFReservedSeats = 0 , totalNumberOFAvailableSeats = 0, precentageOfReservedSeats = 0;
    int rowOfHighestReservedSeats = 0 , rowOfLowestReservedSeats = 0 , temp1 = 0 , temp2 = 0 , tempforHighest = 0 , tempforLowest = 0;
    // for Entering the Seats
    cout << "\t\tEnter 1 for Booked and 0 for Available \n";
    for(int i = 0 ; i<R ; i++){
        cout << "Enter The Seats for Row " << i + 1 << " \n";
        cout << "----------------------------------\n";
        for(int j = 0 ; j < S ; j++){
            do{
                cout << "Seat " << j + 1 << " : ";
                cin >> cinemaArray[i][j];
                if(cinemaArray[i][j] == 1){
                    totalNumberOFReservedSeats++;
                    temp1++;
                } 
                else if( cinemaArray[i][j] == 0){
                    totalNumberOFAvailableSeats++;
                    temp2++;
                }
                else cout << "Invalid Input \n";
            }while(cinemaArray[i][j] < 0 || cinemaArray[i][j] > 1);
        }
        if(temp1 >  tempforHighest){
            tempforHighest = temp1;
            rowOfHighestReservedSeats = i + 1;
        }
        if(temp2 >  tempforLowest){
            tempforLowest = temp2;
            rowOfLowestReservedSeats = i + 1;
        }
        temp1 = 0;
        temp2 = 0;
    }
    cout << "\n\n\t\tThe Cinema Seats Are \n";
    cout << "----------------------------------\n";
    for(int i = 0 ; i < R ; i++){
        for(int j = 0 ; j < S ; j++){
            cout << cinemaArray[i][j] << " ";
        }
        cout << " \n";
    }
    cout << "-----------------------------------------------------\n";
    cout << "The statistics About the Cinema Seats Are \n";
    cout << "-----------------------------------------------------\n";
    cout << "The total Number of Reserved Seats Are : " << totalNumberOFReservedSeats << "\n";
    cout << "The total Number of Available Seats Are : " << totalNumberOFAvailableSeats << "\n";
    cout << "The Percentage of Reserved Seats Are : " << (totalNumberOFReservedSeats * 100) / sizeOfArray << "%\n";
    cout << "The Row of Highest Reserved Seats Are : " << rowOfHighestReservedSeats << "\n";
    cout << "The Row of Lowest Reserved Seats Are : " << rowOfLowestReservedSeats << "\n";

    cout << "-----------------------------------------------------\n";


    int rowToCheck;
    cout << "Enter a Number of Row to Check the Seats \n";
    cin >> rowToCheck;
    bool isAvailable = false;
    cout << "Checking for Row " << rowToCheck << " Are \n";
    for(int i = 0 ; i < S ; i++){
        if(cinemaArray[rowToCheck - 1][i] == 0){
            cout << "Seat " << i + 1 << " is Available\n";
            isAvailable = true;
        }
    }
    if(!isAvailable){
        cout << "No Available Seats in Row " << rowToCheck << "\n";
    }



    cout << "-----------------------------------------------------\n";
    int rowToReserve , colToReserve;
    cout << "Enter a Number of Row and Column to Reserve the Seats \n";
    cin >> rowToReserve >> colToReserve;
    if(cinemaArray[rowToReserve - 1][colToReserve - 1] == 0){
        cinemaArray[rowToReserve - 1][colToReserve -1] = 1;
        cout << "Seat " << colToReserve << " in Row " << rowToReserve << " is Reserved Now \n";
    }
    else{
        cout << "Seat " <<colToReserve <<" In Row " << rowToReserve << " Is Already Reserved \n";
    }
    return 0;
}