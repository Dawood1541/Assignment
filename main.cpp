//
//  main.cpp
//  01
//
//  Created by MacBook Pro on 18/08/2016.
//  Copyright (c) 2016 MacBook Pro. All rights reserved.
//


#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>
using namespace std;

void player1 (int array1[], int num1, int &pseed1);         //add in seeds of player 1
void player2 (int array2[], int num2, int &pseed2);         //ADD IN SEEDS OF PLAYERS
void add_player1 (int array_1[], int &num_1);      //PLACE THE REMAINIG SEEDS IN PLAYER 1 FROM PLAYER 2 TURN
void add_player2 (int array_2[], int &num_2);      // PLACE THE REMAINING SEEDS IN PLAYER 2 FROM PLAYER 1

int main()

{
    int pl_1[7];                    // ARRAY OF SIZE 7 TO STORE NO OF SEEDS OF EACH HOUS FOR PLAYER 1
    int pl_2[7];                    // ARRAY OF SIZE 7 TO STORE NO OF SEEDS OF EACH HOUS FOR PLAYER 2
    int n1, n2;                     // INPUT FROM PLAYER 1 AND PLAYER 2
    int remain1, remain2;           // TO SAVE THE SEEDS LEFT AFTER PLAYER TURN TO CONTINUE ADDIGN IT IN
                                        //0THTER PLAERS HOUSES UNTIL ALL SEEDS ARE FINISHED
    int seed1, seed2, sav_1, sav_2; // SAVING SEEDS
    int new_seed1, new_seed2;       //KEEPING RECORD OF SEEDS FROM PREVIOUS TURN TO DISPLAY OUTPUT STEP WISE
    
    int a1, a2, a3, a4, a5, a6, a7; // SAVE VALUES OF SEEDS OF PLAYER 1 HOUSES TO CHECK FOR DIFFERENT LOOPS
    int b1, b2, b3, b4, b5, b6, b7; // SAVE VALUES OF SEEDS OF PLAYER 1 HOUSES TO CHECK FOR DIFFERENT LOOPS
    
    a1= a2= a3= a4= a5= a6= a7 = 1; // INITIALIZING TO 1 TO RUN THE PROGRAM
    b1= b2= b3= b4= b5= b6= b7 = 1;
    
    // INITIALIZINH DIFFRENT PARAMETERS WHICH WERE DECLARED EARLIER
    
    n1 = n2 = 1;
    seed1 = seed2 = 0;
    new_seed1 = new_seed2 = 0;
    sav_1 = sav_2 = 0;
    
    // TO GENERATE RANDOMLY 0 OR 1 TO DECIDE PLAYER TURN. "O" FOR PLAYER 1 AND "1" FOR PLAYER 2
     srand(time(0));
    int x = rand()%2;
    
    // INITIALLY ALL HOUSES HAVE 7 SEEDS
    for (int i = 0; i<7; i++)
        
    {
        pl_1[i] = 7;
        pl_2[i] = 7;
  
    }
    // TO RUN THE PROGRAM AS LONG ALL THE SEEDS IN ALL THE PLAYER HOUSES FINISHED
    while (a1 !=0 || a2 !=0 || a3 !=0 || a4 !=0 || a5 != 0 || a6 != 0 || a7 != 0 || b1 != 0 || b2 !=0 || b3 != 0 || b4 != 0 || b5 != 0 || b6 != 0 || b7 != 0)
    {
        if (x == 0) // PLAYER 1 WILL START FIRST
        {
        a1 = pl_1[0];
        a2 = pl_1[1];
        a3 = pl_1[2];
        a4 = pl_1[3];
        a5 = pl_1[4];
        a6 = pl_1[5];
        a7 = pl_1[6];
        
        b1 = pl_2[0];
        b2 = pl_2[1];
        b3 = pl_2[2];
        b4 = pl_2[3];
        b5 = pl_2[4];
        b6 = pl_2[5];
        b7 = pl_2[6];
        
            // IF ALL SEED IN PLAYER 1 HOUSE ARE "0" THEN PLAYER 1 TURN WILL BE SKIP
        if (a1 == 0 && a2 == 0 && a3 == 0 && a4 == 0 && a5 == 0 && a6 == 0 && a7 == 0)
        {
            cout << "Player 1: All houses are empty, Skip your turn" << endl;
        }
        else
        {
            cout << endl;
            cout << "Player 1 \n Please choose your location (1 to 7) => ";
            cin >> n1;
            // CHECKING THAT USER ONLY PUT INTEGERS NO ALPHABET
            
            /*
            while(!(cin >> n1))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "You entered wrong input";
            }
             */
            // CHECKING FOR NO TO BE IN BETWEEN 1 AND 7
            while (n1 <1 || n1 > 7)
                
            {
                cout << "You entered wrong input";
                cout << endl;
                
                cout << "\nPlayer 1 \n Please choose your location (1 to 7) => ";
                cin >> n1;
                
            }
            // IF THE SELECTED HOUSE HAS NO SEED PLAYER 1 WILL BE ASKED TO SELECT A DIFFERENT HOUSE
            while (pl_1[n1-1] == 0)
            {
                cout << "No seed at location " << n1 <<" Please select different input" << endl;
                cout << "Player 1" << endl;
                cin >> n1;
            }
        
            player1 (pl_1, n1, seed1);          //CALLING FUNCTION PLAYER1 TO ADD THE SEEDS
    
            if (seed1 == 1)
            {
                new_seed1 = new_seed1 + seed1;
            }
            
            // IF SEEDS ARE LEFT AFTER PLACING ONE SEED IN HOUSES OF PLAYER 1 IT WILL ADD ONE SEED IN STOREHOUSE 1 AND CONTINUE ADDING
            else if (seed1 > 1)
            {
                remain1 = seed1 - 1;
                seed1 = 1;
                new_seed1 = new_seed1 + 1;
                add_player2(pl_2, remain1);
                
                // CONTINOUS LOOP TO MAKE SURE ALL SEEDS ARE ADDED. THIS LOOP WILL SKIP ENEMY STOREHOUSE
                while (remain1 != 0)
                {
                    if(remain1 < 1)
                    {
                        break;
                    }
                    else if (remain1 > 1)
                    {
                        add_player1(pl_1, remain1);     // SKIPING ENEMY STOREHOUSE
                    }
                    
                    if (remain1 < 1)
                    {
                        break;
                    }
                    else if (remain1 >= 1)
                    {
                        remain1 = remain1 - 1;          // ADDING TO OWN STOREHOUSE ON MOVING TO ENEY HOUSE
                        new_seed1 = new_seed1 + 1;      // secoond time
                        add_player2(pl_2, remain1);
                    }
                }
            
            }
            // output step by step
            for (int i = n1; i < 8; i++)
            {
            cout << "           Player 1" << endl << endl;
            cout << "    --1--2--3--4--5--6--7-" << endl;
            cout << "    ----------------------" << endl;
            switch (i)
                {
                    case 0:
                        cout << "       |"<<pl_1[0]<< "|" << a2 << "|" << a3 << "|" << a4 << "|" << a5 << "|" << a6 << "|" << a7 << "|" << endl;
                        cout <<  sav_2 << " ----------------------  " << sav_1<< endl;
                       // cin.get();
                        break;
                    case 1:
                        cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << a3 << "|" << a4 << "|" << a5 << "|" << a6 << "|" << a7 << "|" << endl;
                        cout <<  sav_2 << " ----------------------  " << sav_1<< endl;
                       // cin.get();
                        break;
                    case 2:
                        cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << pl_1[2] << "|" << a4 << "|" << a5 << "|" << a6 << "|" << a7 << "|" << endl;
                        cout <<  sav_2 << " ----------------------  " << sav_1<< endl;
                        //cin.get();
                        break;
                    case 3:
                        cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << pl_1[2] << "|" << pl_1[3] << "|" << a5 << "|" << a6 << "|" << a7 << "|" << endl;
                        cout <<  sav_2 << " ----------------------  " << sav_1<< endl;
                        //cin.get();
                        break;
                    case 4:
                        cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << pl_1[2] << "|" << pl_1[3] << "|" << pl_1[4] << "|" << a6 << "|" << a7 << "|" << endl;
                        cout <<  sav_2 << " ----------------------  " << sav_1<< endl;
                        //cin.get();
                        break;
                    case 5:
                        cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << pl_1[2] << "|" << pl_1[3] << "|" << pl_1[4] << "|" << pl_1[5] << "|" << a7 << "|" << endl;
                        cout <<  sav_2 << " ----------------------  " << sav_1<< endl;
                        //cin.get();
                        break;
                    case 6:
                        cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << pl_1[2] << "|" << pl_1[3] << "|" << pl_1[4] << "|" << pl_1[5] << "|" << pl_1[6] << "|" << endl;
                        cout <<  sav_2 << " ----------------------  " << sav_1<< endl;
                        //cin.get();
                        break;
                    case 7:
                        cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << pl_1[2] << "|" << pl_1[3] << "|" << pl_1[4] << "|" << pl_1[5] << "|" << pl_1[6] << "|" << endl;
                        cout <<  sav_2 << " ----------------------  " << new_seed1<< endl;
                        //cin.get();
                        break;
                }
            cout << "       |"<<b7<< "|" << b6 << "|" << b5 << "|" << b4 << "|" << b3 << "|" << b2 << "|" << b1 << "|" << endl;
            cout << "    ----------------------" << endl;
            cout << "    --7--6--5--4--3--2--1-" << endl << endl;
            cout << "           Player 2" << endl << endl;
                
            }
            for (int i = n2; i < 8; i++)
            {
                cout << endl;
                cout << "           Player 1" << endl << endl;
                cout << "    --1--2--3--4--5--6--7-" << endl;
                cout << "    ----------------------" << endl;
                cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << pl_1[2] << "|" << pl_1[3] << "|" << pl_1[4] << "|" << pl_1[5] << "|" << pl_1[6] << "|" << endl;
                switch (i)
                {
                    case 0:
                        cout <<  sav_2 << " ----------------------  " << new_seed1<< endl;
                        cout << "       |"<<b7<< "|" << b6 << "|" << b5 << "|" << b4 << "|" << b3 << "|" << b2 << "|" << pl_2[0] << "|" << endl;
                        break;
                    case 1:
                        cout <<  sav_2 << " ----------------------  " << new_seed1<< endl;
                        cout << "       |"<<b7<< "|" << b6 << "|" << b5 << "|" << b4 << "|" << b3 << "|" << pl_2[1] << "|" << pl_2[0] << "|" << endl;
                        break;
                    case 2:
                        cout <<  sav_2 << " ----------------------  " << new_seed1<< endl;
                        cout << "       |"<<b7<< "|" << b6 << "|" << b5 << "|" << b4 << "|" << pl_2[2] << "|" << pl_2[1] << "|" << pl_2[0] << "|" << endl;
                        break;
                    case 3:
                        cout <<  sav_2 << " ----------------------  " << new_seed1<< endl;
                        cout << "       |"<<b7<< "|" << b6 << "|" << b5 << "|" << pl_2[3] << "|" << pl_2[2] << "|" << pl_2[1] << "|" << pl_2[0] << "|" << endl;
                        break;
                    case 4:
                        cout <<  sav_2 << " ----------------------  " << new_seed1<< endl;
                        cout << "       |"<<b7<< "|" << b6 << "|" << pl_2[4] << "|" << pl_2[3] << "|" << pl_2[2] << "|" << pl_2[1] << "|" << pl_2[0] << "|" << endl;
                        break;
                    case 5:
                        cout <<  sav_2 << " ----------------------  " << new_seed1<< endl;
                        cout << "       |"<<b7<< "|" << pl_2[5] << "|" << pl_2[4] << "|" << pl_2[3] << "|" << pl_2[2] << "|" << pl_2[1] << "|" << pl_2[0] << "|" << endl;
                        break;
                    case 6:
                        cout <<  sav_2 << " ----------------------  " << new_seed1<< endl;
                        cout << "       |"<<pl_2[6]<< "|" << pl_2[5] << "|" << pl_2[4] << "|" << pl_2[3] << "|" << pl_2[2] << "|" << pl_2[1] << "|" << pl_2[0] << "|" << endl;
                        break;
                    case 7:
                        cout <<  new_seed2 << " ----------------------  " << new_seed1<< endl;
                        cout << "       |"<<pl_2[6]<< "|" << pl_2[5] << "|" << pl_2[4] << "|" << pl_2[3] << "|" << pl_2[2] << "|" << pl_2[1] << "|" << pl_2[0] << "|" << endl;
                        break;
                }
                cout << "    ----------------------" << endl;
                cout << "    --7--6--5--4--3--2--1-" << endl << endl;
                cout << "           Player 2" << endl << endl;
            }
            
        }
            cout << endl<< endl<< "Final Output " << endl;
            
            cout << endl;
            cout << "           Player 1" << endl << endl;
            cout << "    --1--2--3--4--5--6--7-" << endl;
            cout << "    ----------------------" << endl;
            cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << pl_1[2] << "|" << pl_1[3] << "|" << pl_1[4] << "|" << pl_1[5] << "|" << pl_1[6] << "|" << endl;
            cout <<  new_seed2 << " ----------------------  " << new_seed1<< endl;
            cout << "       |"<<pl_2[6]<< "|" << pl_2[5] << "|" << pl_2[4] << "|" << pl_2[3] << "|" << pl_2[2] << "|" << pl_2[1] << "|" << pl_2[0] << "|" << endl;
            cout << "    ----------------------" << endl;
            cout << "    --7--6--5--4--3--2--1-" << endl << endl;
            cout << "           Player 2" << endl << endl;
            
        sav_1 = new_seed1;      // TO KEEP THE PREVIOUS VALUE OF SEEDS IN STOREHOUSE TO USE IN NECT OUTPUT
        sav_2 = new_seed2;
            // ONLY TO USE IT TO PRINT STEP BY STEP
        a1 = pl_1[0];
        a2 = pl_1[1];
        a3 = pl_1[2];
        a4 = pl_1[3];
        a5 = pl_1[4];
        a6 = pl_1[5];
        a7 = pl_1[6];
        
        b1 = pl_2[0];
        b2 = pl_2[1];
        b3 = pl_2[2];
        b4 = pl_2[3];
        b5 = pl_2[4];
        b6 = pl_2[5];
        
            // NOW CHECKING FOR PLAYER 2 WHETHER ALL HOUSES ARE EYMPTY OR NOT
        if (b1 == 0 && b2 == 0 && b3 == 0 && b4 == 0 && b5 == 0 && b6 == 0 && b7 == 0 )
        {
            cout << "Player 2: All houses are empty skip your turn " << endl;
        }
        else
        {
            
            cout << endl;
            cout << "Player 2 \n Please choose your location (1 to 5) => ";
            cin >> n2;
            
            // CHECKING FOR ALPHABETS
            /*
            while(!(cin >> n2))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "You entered wrong input";
                cout << endl;
                
                cout << "\nPlayer 2 \n Please choose your location (1 to 7) => ";
            }
             */
            // CHECKING FOR NO LIMIT
            while (n2 <1 || n2 > 7)
        
            {
                cout << "You entered wrong input";
                cout << endl;
        
                cout << "\nPlayer 2 \n Please choose your location (1 to 7) => ";
                cin >> n2;
            }
            // IF THE HOUSE HAVE NO SEED ASK AGAIN FROM PLAYER 2
            while (pl_2[n2-1] == 0)
            {
                cout << "No seed at location " << n1 <<" Please select different input" << endl;
                cout << "Player 2" << endl;
                cin >> n2;
            }
    
            player2(pl_2, n2, seed2);       //CALLING PLAYER2 FUNCTION TO ADD THE SEEDS
            
            if (seed2 == 1)
            {
                new_seed2 = new_seed2 + seed2;
            }
            // AFTER ADDING IN HOUSE 2 THE REMAINIG SEEDS WILL BE CONTINUED ADDING
            if (seed2 > 1)
            {
                remain2 = seed2 - 1;
                seed2 = 1;
                new_seed2 = new_seed2 + 1;
                add_player1(pl_1, remain2);
                
                // MAKE SRE SEEDS ARE BEEN ADDED UNTIL THE FINISHED BY STKIPPING ENEMY STORHOUSE
                while (remain2 != 0)
                {
                    if (remain2 < 1)
                    {
                        break;
                    }
                    else if (remain2 >= 1)
                    {
                        add_player2(pl_2, remain2);     // SKIPPING ENEMY STOREHOUSE
                    }
                    
                    if (remain2 < 1)
                    {
                        break;
                    }
                    else if (remain2 >= 1)
                    {
                        remain2 = remain2 - 1;          // ADDING SEEDS IN OWN STORE HOUSE BY GOING 2ND TIME
                        new_seed2 = new_seed2 + 1;      // ENEMY HOUSE
                        add_player1(pl_1, remain2);
                    }
                }
            }
            // PRINITNG OUT STEP BY STEP
            for (int i = n2; i < 8; i++)
            {
                cout << endl;
                cout << "           Player 1" << endl << endl;
                cout << "    --1--2--3--4--5--6--7-" << endl;
                cout << "    ----------------------" << endl;
                cout << "       |"<<a1<< "|" << a2 << "|" << a3 << "|" << a4 << "|" << a5<< "|" << a6 << "|" << a7 << "|" << endl;
                switch (i)
                {
                    case 0:
                        cout <<  sav_2 << " ----------------------  " << new_seed1<< endl;
                        cout << "       |"<<b7<< "|" << b6 << "|" << b5 << "|" << b4 << "|" << b3 << "|" << b2 << "|" << pl_2[0] << "|" << endl;
                        break;
                    case 1:
                        cout <<  sav_2 << " ----------------------  " << new_seed1<< endl;
                        cout << "       |"<<b7<< "|" << b6 << "|" << b5 << "|" << b4 << "|" << b3 << "|" << pl_2[1] << "|" << pl_2[0] << "|" << endl;
                        break;
                    case 2:
                        cout <<  sav_2 << " ----------------------  " << new_seed1<< endl;
                        cout << "       |"<<b7<< "|" << b6 << "|" << b5 << "|" << b4 << "|" << pl_2[2] << "|" << pl_2[1] << "|" << pl_2[0] << "|" << endl;
                        break;
                    case 3:
                        cout <<  sav_2 << " ----------------------  " << new_seed1<< endl;
                        cout << "       |"<<b7<< "|" << b6 << "|" << b5 << "|" << pl_2[3] << "|" << pl_2[2] << "|" << pl_2[1] << "|" << pl_2[0] << "|" << endl;
                        break;
                    case 4:
                        cout <<  sav_2 << " ----------------------  " << new_seed1<< endl;
                        cout << "       |"<<b7<< "|" << b6 << "|" << pl_2[4] << "|" << pl_2[3] << "|" << pl_2[2] << "|" << pl_2[1] << "|" << pl_2[0] << "|" << endl;
                        break;
                    case 5:
                        cout <<  sav_2 << " ----------------------  " << new_seed1<< endl;
                        cout << "       |"<<b7<< "|" << pl_2[5] << "|" << pl_2[4] << "|" << pl_2[3] << "|" << pl_2[2] << "|" << pl_2[1] << "|" << pl_2[0] << "|" << endl;
                        break;
                    case 6:
                        cout <<  sav_2 << " ----------------------  " << new_seed1<< endl;
                        cout << "       |"<<pl_2[6]<< "|" << pl_2[5] << "|" << pl_2[4] << "|" << pl_2[3] << "|" << pl_2[2] << "|" << pl_2[1] << "|" << pl_2[0] << "|" << endl;
                        break;
                    case 7:
                        cout <<  new_seed2 << " ----------------------  " << new_seed1<< endl;
                        cout << "       |"<<pl_2[6]<< "|" << pl_2[5] << "|" << pl_2[4] << "|" << pl_2[3] << "|" << pl_2[2] << "|" << pl_2[1] << "|" << pl_2[0] << "|" << endl;
                        break;
                }
                cout << "    ----------------------" << endl;
                cout << "    --7--6--5--4--3--2--1-" << endl << endl;
                cout << "           Player 2" << endl << endl;
            }

            for (int i = n1; i < 8; i++)
            {
                cout << "           Player 1" << endl << endl;
                cout << "    --1--2--3--4--5--6--7-" << endl;
                cout << "    ----------------------" << endl;
                switch (i)
                {
                    case 0:
                        cout << "       |"<<pl_1[0]<< "|" << a2 << "|" << a3 << "|" << a4 << "|" << a5 << "|" << a6 << "|" << a7 << "|" << endl;
                        cout <<  sav_2 << " ----------------------  " << sav_1<< endl;
                        // cin.get();
                        break;
                    case 1:
                        cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << a3 << "|" << a4 << "|" << a5 << "|" << a6 << "|" << a7 << "|" << endl;
                        cout <<  sav_2 << " ----------------------  " << sav_1<< endl;
                        // cin.get();
                        break;
                    case 2:
                        cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << pl_1[2] << "|" << a4 << "|" << a5 << "|" << a6 << "|" << a7 << "|" << endl;
                        cout <<  sav_2 << " ----------------------  " << sav_1<< endl;
                        //cin.get();
                        break;
                    case 3:
                        cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << pl_1[2] << "|" << pl_1[3] << "|" << a5 << "|" << a6 << "|" << a7 << "|" << endl;
                        cout <<  sav_2 << " ----------------------  " << sav_1<< endl;
                        //cin.get();
                        break;
                    case 4:
                        cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << pl_1[2] << "|" << pl_1[3] << "|" << pl_1[4] << "|" << a6 << "|" << a7 << "|" << endl;
                        cout <<  sav_2 << " ----------------------  " << sav_1<< endl;
                        //cin.get();
                        break;
                    case 5:
                        cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << pl_1[2] << "|" << pl_1[3] << "|" << pl_1[4] << "|" << pl_1[5] << "|" << a7 << "|" << endl;
                        cout <<  sav_2 << " ----------------------  " << sav_1<< endl;
                        //cin.get();
                        break;
                    case 6:
                        cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << pl_1[2] << "|" << pl_1[3] << "|" << pl_1[4] << "|" << pl_1[5] << "|" << pl_1[6] << "|" << endl;
                        cout <<  sav_2 << " ----------------------  " << sav_1<< endl;
                        //cin.get();
                        break;
                    case 7:
                        cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << pl_1[2] << "|" << pl_1[3] << "|" << pl_1[4] << "|" << pl_1[5] << "|" << pl_1[6] << "|" << endl;
                        cout <<  sav_2 << " ----------------------  " << new_seed1<< endl;
                        //cin.get();
                        break;
                }
                cout << "       |"<<pl_2[7]<< "|" << pl_2[6] << "|" << pl_2[5] << "|" << pl_2[4] << "|" << pl_2[3] << "|" << pl_2[2] << "|" << pl_2[1] << "|" << endl;
                cout << "    ----------------------" << endl;
                cout << "    --7--6--5--4--3--2--1-" << endl << endl;
                cout << "           Player 2" << endl << endl;
                
            }
            
            cout << endl<< endl<< "Final Output " << endl;
            
            cout << endl;
            cout << "           Player 1" << endl << endl;
            cout << "    --1--2--3--4--5--6--7-" << endl;
            cout << "    ----------------------" << endl;
            cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << pl_1[2] << "|" << pl_1[3] << "|" << pl_1[4] << "|" << pl_1[5] << "|" << pl_1[6] << "|" << endl;
            cout <<  new_seed2 << " ----------------------  " << new_seed1<< endl;
            cout << "       |"<<pl_2[6]<< "|" << pl_2[5] << "|" << pl_2[4] << "|" << pl_2[3] << "|" << pl_2[2] << "|" << pl_2[1] << "|" << pl_2[0] << "|" << endl;
            cout << "    ----------------------" << endl;
            cout << "    --7--6--5--4--3--2--1-" << endl << endl;
            cout << "           Player 2" << endl << endl;
            
            // TO KEEP RECORD OF PREVIOS SEED VALUES IN STACK HOUSES TO USE FOR NEXT LOOP OF OUTPUT
            sav_1 = new_seed1;
            sav_2 = new_seed2;
        }
        // JUST TO KEEP RECORD OF PREVIOUS VALUES FOR NEXT OUTPUT
        a1 = pl_1[0];
        a2 = pl_1[1];
        a3 = pl_1[2];
        a4 = pl_1[3];
        a5 = pl_1[4];
        a6 = pl_1[5];
        a7 = pl_1[6];
    
        b1 = pl_2[0];
        b2 = pl_2[1];
        b3 = pl_2[2];
        b4 = pl_2[3];
        b5 = pl_2[4];
        b6 = pl_2[5];
        b7 = pl_2[6];
        
        
   }
        // EVERTHING IS EXACTLY SAME EXCEPT THAT THIS TIME PLAYER 2 WILL START THE GAME
        else if (x == 1)
        {
            a1 = pl_1[0];
            a2 = pl_1[1];
            a3 = pl_1[2];
            a4 = pl_1[3];
            a5 = pl_1[4];
            a6 = pl_1[5];
            a7 = pl_1[6];
            
            b1 = pl_2[0];
            b2 = pl_2[1];
            b3 = pl_2[2];
            b4 = pl_2[3];
            b5 = pl_2[4];
            b6 = pl_2[5];
            b7 = pl_2[6];
            
            if (b1 == 0 && b2 == 0 && b3 == 0 && b4 == 0 && b5 == 0 && b6 == 0 && b7 == 0 )
            {
                cout << "Player 2: All houses are empty skip your turn " << endl;
            }
            else
            {
                
                cout << endl;
                cout << "Player 2 \n Please choose your location (1 to 5) => ";
                cin >> n2;
                /*
                 while(!(cin >> n2))
                 {
                 cin.clear();
                 cin.ignore(numeric_limits<streamsize>::max(), '\n');
                 cout << "You entered wrong input";
                 cout << endl;
                 
                 cout << "\nPlayer 2 \n Please choose your location (1 to 7) => ";
                 }
                 */
                while (n2 <1 || n2 > 7)
                    
                {
                    cout << "You entered wrong input";
                    cout << endl;
                    
                    cout << "\nPlayer 2 \n Please choose your location (1 to 7) => ";
                    cin >> n2;
                }
                while (pl_2[n2-1] == 0)
                {
                    cout << "No seed at location " << n1 <<" Please select different input" << endl;
                    cout << "Player 2" << endl;
                    cin >> n2;
                }
                
                player2(pl_2, n2, seed2);
                
                if (seed2 == 1)
                {
                    new_seed2 = new_seed2 + seed2;
                }
                if (seed2 > 1)
                {
                    remain2 = seed2 - 1;
                    seed2 = 1;
                    new_seed2 = new_seed2 + 1;
                    add_player1(pl_1, remain2);
                    
                    while (remain2 != 0)
                    {
                        if (remain2 < 1)
                        {
                            break;
                        }
                        else if (remain2 >= 1)
                        {
                            add_player2(pl_2, remain2);
                        }
                        
                        if (remain2 < 1)
                        {
                            break;
                        }
                        else if (remain2 >= 1)
                        {
                            remain2 = remain2 - 1;
                            new_seed2 = new_seed2 + 1;
                            add_player1(pl_1, remain2);
                        }
                    }
                }
                for (int i = n2; i < 8; i++)
                {
                    cout << endl;
                    cout << "           Player 1" << endl << endl;
                    cout << "    --1--2--3--4--5--6--7-" << endl;
                    cout << "    ----------------------" << endl;
                    cout << "       |"<<a1<< "|" << a2 << "|" << a3 << "|" << a4 << "|" << a5<< "|" << a6 << "|" << a7 << "|" << endl;
                    switch (i)
                    {
                        case 0:
                            cout <<  sav_2 << " ----------------------  " << sav_1<< endl;
                            cout << "       |"<<b7<< "|" << b6 << "|" << b5 << "|" << b4 << "|" << b3 << "|" << b2 << "|" << pl_2[0] << "|" << endl;
                            break;
                        case 1:
                            cout <<  sav_2 << " ----------------------  " << sav_1<< endl;
                            cout << "       |"<<b7<< "|" << b6 << "|" << b5 << "|" << b4 << "|" << b3 << "|" << pl_2[1] << "|" << pl_2[0] << "|" << endl;
                            break;
                        case 2:
                            cout <<  sav_2 << " ----------------------  " << sav_1<< endl;
                            cout << "       |"<<b7<< "|" << b6 << "|" << b5 << "|" << b4 << "|" << pl_2[2] << "|" << pl_2[1] << "|" << pl_2[0] << "|" << endl;
                            break;
                        case 3:
                            cout <<  sav_2 << " ----------------------  " << sav_1<< endl;
                            cout << "       |"<<b7<< "|" << b6 << "|" << b5 << "|" << pl_2[3] << "|" << pl_2[2] << "|" << pl_2[1] << "|" << pl_2[0] << "|" << endl;
                            break;
                        case 4:
                            cout <<  sav_2 << " ----------------------  " << sav_1<< endl;
                            cout << "       |"<<b7<< "|" << b6 << "|" << pl_2[4] << "|" << pl_2[3] << "|" << pl_2[2] << "|" << pl_2[1] << "|" << pl_2[0] << "|" << endl;
                            break;
                        case 5:
                            cout <<  sav_2 << " ----------------------  " << sav_1<< endl;
                            cout << "       |"<<b7<< "|" << pl_2[5] << "|" << pl_2[4] << "|" << pl_2[3] << "|" << pl_2[2] << "|" << pl_2[1] << "|" << pl_2[0] << "|" << endl;
                            break;
                        case 6:
                            cout <<  sav_2 << " ----------------------  " << sav_1<< endl;
                            cout << "       |"<<pl_2[6]<< "|" << pl_2[5] << "|" << pl_2[4] << "|" << pl_2[3] << "|" << pl_2[2] << "|" << pl_2[1] << "|" << pl_2[0] << "|" << endl;
                            break;
                        case 7:
                            cout <<  new_seed2 << " ----------------------  " << sav_1<< endl;
                            cout << "       |"<<pl_2[6]<< "|" << pl_2[5] << "|" << pl_2[4] << "|" << pl_2[3] << "|" << pl_2[2] << "|" << pl_2[1] << "|" << pl_2[0] << "|" << endl;
                            break;
                    }
                    cout << "    ----------------------" << endl;
                    cout << "    --7--6--5--4--3--2--1-" << endl << endl;
                    cout << "           Player 2" << endl << endl;
                }
                
                for (int i = n1; i < 8; i++)
                {
                    cout << "           Player 1" << endl << endl;
                    cout << "    --1--2--3--4--5--6--7-" << endl;
                    cout << "    ----------------------" << endl;
                    switch (i)
                    {
                        case 0:
                            cout << "       |"<<pl_1[0]<< "|" << a2 << "|" << a3 << "|" << a4 << "|" << a5 << "|" << a6 << "|" << a7 << "|" << endl;
                            cout <<  new_seed2 << " ----------------------  " << sav_1<< endl;
                            // cin.get();
                            break;
                        case 1:
                            cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << a3 << "|" << a4 << "|" << a5 << "|" << a6 << "|" << a7 << "|" << endl;
                            cout <<  new_seed2 << " ----------------------  " << sav_1<< endl;
                            // cin.get();
                            break;
                        case 2:
                            cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << pl_1[2] << "|" << a4 << "|" << a5 << "|" << a6 << "|" << a7 << "|" << endl;
                            cout <<  new_seed2 << " ----------------------  " << sav_1<< endl;
                            //cin.get();
                            break;
                        case 3:
                            cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << pl_1[2] << "|" << pl_1[3] << "|" << a5 << "|" << a6 << "|" << a7 << "|" << endl;
                            cout <<  new_seed2 << " ----------------------  " << sav_1<< endl;
                            //cin.get();
                            break;
                        case 4:
                            cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << pl_1[2] << "|" << pl_1[3] << "|" << pl_1[4] << "|" << a6 << "|" << a7 << "|" << endl;
                            cout <<  new_seed2 << " ----------------------  " << sav_1<< endl;
                            //cin.get();
                            break;
                        case 5:
                            cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << pl_1[2] << "|" << pl_1[3] << "|" << pl_1[4] << "|" << pl_1[5] << "|" << a7 << "|" << endl;
                            cout <<  new_seed2 << " ----------------------  " << sav_1<< endl;
                            //cin.get();
                            break;
                        case 6:
                            cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << pl_1[2] << "|" << pl_1[3] << "|" << pl_1[4] << "|" << pl_1[5] << "|" << pl_1[6] << "|" << endl;
                            cout <<  new_seed2 << " ----------------------  " << sav_1<< endl;
                            //cin.get();
                            break;
                        case 7:
                            cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << pl_1[2] << "|" << pl_1[3] << "|" << pl_1[4] << "|" << pl_1[5] << "|" << pl_1[6] << "|" << endl;
                            cout <<  new_seed2 << " ----------------------  " << new_seed1<< endl;
                            //cin.get();
                            break;
                    }
                    cout << "       |"<<pl_2[7]<< "|" << pl_2[6] << "|" << pl_2[5] << "|" << pl_2[4] << "|" << pl_2[3] << "|" << pl_2[2] << "|" << pl_2[1] << "|" << endl;
                    cout << "    ----------------------" << endl;
                    cout << "    --7--6--5--4--3--2--1-" << endl << endl;
                    cout << "           Player 2" << endl << endl;
                    
                }
                cout << endl<< endl<< "Final Output " << endl;
                
                cout << endl;
                cout << "           Player 1" << endl << endl;
                cout << "    --1--2--3--4--5--6--7-" << endl;
                cout << "    ----------------------" << endl;
                cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << pl_1[2] << "|" << pl_1[3] << "|" << pl_1[4] << "|" << pl_1[5] << "|" << pl_1[6] << "|" << endl;
                cout <<  new_seed2 << " ----------------------  " << new_seed1<< endl;
                cout << "       |"<<pl_2[6]<< "|" << pl_2[5] << "|" << pl_2[4] << "|" << pl_2[3] << "|" << pl_2[2] << "|" << pl_2[1] << "|" << pl_2[0] << "|" << endl;
                cout << "    ----------------------" << endl;
                cout << "    --7--6--5--4--3--2--1-" << endl << endl;
                cout << "           Player 2" << endl << endl;
                
                sav_1 = new_seed1;
                sav_2 = new_seed2;
                
                if (a1 == 0 && a2 == 0 && a3 == 0 && a4 == 0 && a5 == 0 && a6 == 0 && a7 == 0)
                {
                    cout << "Player 1: All houses are empty, Skip your turn" << endl;
                }
                else
                {
                    cout << endl;
                    cout << "Player 1 \n Please choose your location (1 to 7) => ";
                    cin >> n1;
                    /*
                     while(!(cin >> n1))
                     {
                     cin.clear();
                     cin.ignore(numeric_limits<streamsize>::max(), '\n');
                     cout << "You entered wrong input";
                     }
                     */
                    while (n1 <1 || n1 > 7)
                        
                    {
                        cout << "You entered wrong input";
                        cout << endl;
                        
                        cout << "\nPlayer 1 \n Please choose your location (1 to 7) => ";
                        cin >> n1;
                        
                    }
                    while (pl_1[n1-1] == 0)
                    {
                        cout << "No seed at location " << n1 <<" Please select different input" << endl;
                        cout << "Player 1" << endl;
                        cin >> n1;
                    }
                    
                    player1 (pl_1, n1, seed1);
                    
                    if (seed1 == 1)
                    {
                        new_seed1 = new_seed1 + seed1;
                    }
                    
                    else if (seed1 > 1)
                    {
                        remain1 = seed1 - 1;
                        seed1 = 1;
                        new_seed1 = new_seed1 + 1;
                        add_player2(pl_2, remain1);
                        
                        while (remain1 != 0)
                        {
                            if(remain1 < 1)
                            {
                                break;
                            }
                            else if (remain1 > 1)
                            {
                                add_player1(pl_1, remain1);
                            }
                            
                            if (remain1 < 1)
                            {
                                break;
                            }
                            else if (remain1 >= 1)
                            {
                                remain1 = remain1 - 1;
                                new_seed1 = new_seed1 + 1;
                                add_player2(pl_2, remain1);
                            }
                        }
                        
                    }
                    for (int i = n1; i < 8; i++)
                    {
                        cout << "           Player 1" << endl << endl;
                        cout << "    --1--2--3--4--5--6--7-" << endl;
                        cout << "    ----------------------" << endl;
                        switch (i)
                        {
                            case 0:
                                cout << "       |"<<pl_1[0]<< "|" << a2 << "|" << a3 << "|" << a4 << "|" << a5 << "|" << a6 << "|" << a7 << "|" << endl;
                                cout <<  sav_2 << " ----------------------  " << sav_1<< endl;
                                // cin.get();
                                break;
                            case 1:
                                cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << a3 << "|" << a4 << "|" << a5 << "|" << a6 << "|" << a7 << "|" << endl;
                                cout <<  sav_2 << " ----------------------  " << sav_1<< endl;
                                // cin.get();
                                break;
                            case 2:
                                cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << pl_1[2] << "|" << a4 << "|" << a5 << "|" << a6 << "|" << a7 << "|" << endl;
                                cout <<  sav_2 << " ----------------------  " << sav_1<< endl;
                                //cin.get();
                                break;
                            case 3:
                                cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << pl_1[2] << "|" << pl_1[3] << "|" << a5 << "|" << a6 << "|" << a7 << "|" << endl;
                                cout <<  sav_2 << " ----------------------  " << sav_1<< endl;
                                //cin.get();
                                break;
                            case 4:
                                cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << pl_1[2] << "|" << pl_1[3] << "|" << pl_1[4] << "|" << a6 << "|" << a7 << "|" << endl;
                                cout <<  sav_2 << " ----------------------  " << sav_1<< endl;
                                //cin.get();
                                break;
                            case 5:
                                cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << pl_1[2] << "|" << pl_1[3] << "|" << pl_1[4] << "|" << pl_1[5] << "|" << a7 << "|" << endl;
                                cout <<  sav_2 << " ----------------------  " << sav_1<< endl;
                                //cin.get();
                                break;
                            case 6:
                                cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << pl_1[2] << "|" << pl_1[3] << "|" << pl_1[4] << "|" << pl_1[5] << "|" << pl_1[6] << "|" << endl;
                                cout <<  sav_2 << " ----------------------  " << sav_1<< endl;
                                //cin.get();
                                break;
                            case 7:
                                cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << pl_1[2] << "|" << pl_1[3] << "|" << pl_1[4] << "|" << pl_1[5] << "|" << pl_1[6] << "|" << endl;
                                cout <<  sav_2 << " ----------------------  " << new_seed1<< endl;
                                //cin.get();
                                break;
                        }
                        cout << "       |"<<b7<< "|" << b6 << "|" << b5 << "|" << b4 << "|" << b3 << "|" << b2 << "|" << b1 << "|" << endl;
                        cout << "    ----------------------" << endl;
                        cout << "    --7--6--5--4--3--2--1-" << endl << endl;
                        cout << "           Player 2" << endl << endl;
                        
                    }
                    for (int i = n2; i < 8; i++)
                    {
                        cout << endl;
                        cout << "           Player 1" << endl << endl;
                        cout << "    --1--2--3--4--5--6--7-" << endl;
                        cout << "    ----------------------" << endl;
                        cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << pl_1[2] << "|" << pl_1[3] << "|" << pl_1[4] << "|" << pl_1[5] << "|" << pl_1[6] << "|" << endl;
                        switch (i)
                        {
                            case 0:
                                cout <<  sav_2 << " ----------------------  " << new_seed1<< endl;
                                cout << "       |"<<b7<< "|" << b6 << "|" << b5 << "|" << b4 << "|" << b3 << "|" << b2 << "|" << pl_2[0] << "|" << endl;
                                break;
                            case 1:
                                cout <<  sav_2 << " ----------------------  " << new_seed1<< endl;
                                cout << "       |"<<b7<< "|" << b6 << "|" << b5 << "|" << b4 << "|" << b3 << "|" << pl_2[1] << "|" << pl_2[0] << "|" << endl;
                                break;
                            case 2:
                                cout <<  sav_2 << " ----------------------  " << new_seed1<< endl;
                                cout << "       |"<<b7<< "|" << b6 << "|" << b5 << "|" << b4 << "|" << pl_2[2] << "|" << pl_2[1] << "|" << pl_2[0] << "|" << endl;
                                break;
                            case 3:
                                cout <<  sav_2 << " ----------------------  " << new_seed1<< endl;
                                cout << "       |"<<b7<< "|" << b6 << "|" << b5 << "|" << pl_2[3] << "|" << pl_2[2] << "|" << pl_2[1] << "|" << pl_2[0] << "|" << endl;
                                break;
                            case 4:
                                cout <<  sav_2 << " ----------------------  " << new_seed1<< endl;
                                cout << "       |"<<b7<< "|" << b6 << "|" << pl_2[4] << "|" << pl_2[3] << "|" << pl_2[2] << "|" << pl_2[1] << "|" << pl_2[0] << "|" << endl;
                                break;
                            case 5:
                                cout <<  sav_2 << " ----------------------  " << new_seed1<< endl;
                                cout << "       |"<<b7<< "|" << pl_2[5] << "|" << pl_2[4] << "|" << pl_2[3] << "|" << pl_2[2] << "|" << pl_2[1] << "|" << pl_2[0] << "|" << endl;
                                break;
                            case 6:
                                cout <<  sav_2 << " ----------------------  " << new_seed1<< endl;
                                cout << "       |"<<pl_2[6]<< "|" << pl_2[5] << "|" << pl_2[4] << "|" << pl_2[3] << "|" << pl_2[2] << "|" << pl_2[1] << "|" << pl_2[0] << "|" << endl;
                                break;
                            case 7:
                                cout <<  new_seed2 << " ----------------------  " << new_seed1<< endl;
                                cout << "       |"<<pl_2[6]<< "|" << pl_2[5] << "|" << pl_2[4] << "|" << pl_2[3] << "|" << pl_2[2] << "|" << pl_2[1] << "|" << pl_2[0] << "|" << endl;
                                break;
                        }
                        cout << "    ----------------------" << endl;
                        cout << "    --7--6--5--4--3--2--1-" << endl << endl;
                        cout << "           Player 2" << endl << endl;
                    }
                    
                }
                cout << endl<< endl<< "Final Output " << endl;
                
                cout << endl;
                cout << "           Player 1" << endl << endl;
                cout << "    --1--2--3--4--5--6--7-" << endl;
                cout << "    ----------------------" << endl;
                cout << "       |"<<pl_1[0]<< "|" << pl_1[1] << "|" << pl_1[2] << "|" << pl_1[3] << "|" << pl_1[4] << "|" << pl_1[5] << "|" << pl_1[6] << "|" << endl;
                cout <<  new_seed2 << " ----------------------  " << new_seed1<< endl;
                cout << "       |"<<pl_2[6]<< "|" << pl_2[5] << "|" << pl_2[4] << "|" << pl_2[3] << "|" << pl_2[2] << "|" << pl_2[1] << "|" << pl_2[0] << "|" << endl;
                cout << "    ----------------------" << endl;
                cout << "    --7--6--5--4--3--2--1-" << endl << endl;
                cout << "           Player 2" << endl << endl;
                
                sav_1 = new_seed1;
                sav_2 = new_seed2;
                a1 = pl_1[0];
                a2 = pl_1[1];
                a3 = pl_1[2];
                a4 = pl_1[3];
                a5 = pl_1[4];
                a6 = pl_1[5];
                a7 = pl_1[6];
                
                b1 = pl_2[0];
                b2 = pl_2[1];
                b3 = pl_2[2];
                b4 = pl_2[3];
                b5 = pl_2[4];
                b6 = pl_2[5];

            }
            // THIS IS TO CHECK MAIN WHILE LOOP. IF ALL ZERO GAME FINISH
            a1 = pl_1[0];
            a2 = pl_1[1];
            a3 = pl_1[2];
            a4 = pl_1[3];
            a5 = pl_1[4];
            a6 = pl_1[5];
            a7 = pl_1[6];
            
            b1 = pl_2[0];
            b2 = pl_2[1];
            b3 = pl_2[2];
            b4 = pl_2[3];
            b5 = pl_2[4];
            b6 = pl_2[5];
            b7 = pl_2[6];
            
            
            
        }
    }
    
    // DECLARING THE WINIER DEPENDING ON NUMBER OF SEEDS IN STACK HOUSE OF PLAYER
    cout << endl <<"Program completed" << endl;
    if (new_seed1 > new_seed2)
        cout << "Winner is Player 1: Congratulation !" << endl;
    else if (new_seed2 > new_seed1)
        cout << "Winner is Player 2: Congratulation !" << endl;
    
    
    
    return 0;
    
}

// INITALY ADDING SEED ON PLAYER TURN
void player1(int array1[], int num1, int &pseed1)

{
    switch (num1)
    
    {
            
        case 1:
            pseed1 = array1[0];
            array1[0] = 0;
            for (int i = 1; i < 7; i++)
            
            {
                array1[i] = array1[i]+1;
            }
            pseed1 = pseed1 - 6;
            break;
            
        case 2:
            pseed1 = array1[1];
            array1[1] = 0;
            for (int i = 2; i < 7; i++)
                
            {
                array1[i] = array1[i]+1;
            }
            pseed1 = pseed1 - 5;
            break;
            
        case 3:
            pseed1 = array1[2];
            array1[2] = 0;
            for (int i = 3; i < 7; i++)
                
            {
                array1[i] = array1[i]+1;
            }
            
            pseed1 = pseed1 - 4;
            break;
            
        case 4:
            pseed1 = array1[3];
            array1[3] = 0;
            for (int i = 4; i < 7; i++)
                
            {
                array1[i] = array1[i] +1;
            }
            
            pseed1 = pseed1 - 3;
            break;
            
        case 5:
            pseed1 = array1[4];
            array1[4] = 0;
            for (int i = 5; i < 7; i++)
                
            {
                array1[i] = array1[i]+1;
            }
            
            pseed1 = pseed1 -2 ;
            break;
            
        case 6:
            pseed1 = array1[5];
            array1[5] = 0;
            for (int i = 6; i < 7; i++)
                
            {
                array1[i] = array1[i] + 1;
            }
            
            pseed1 = pseed1 - 1;
            break;
            
        case 7:
            pseed1 = array1[6];
            array1[6] = 0;
            break;
            
    }
    

}
// TO COME BACK TO PLAYER ONE HOUSE IF SEED ARE REMAINED
void add_player1 (int array_1[], int &num_1)
{
    int i = 0;
    int no_1 = 0;
    
    no_1 = num_1;
    
    while (no_1 != 0)
    {
        array_1[i] = array_1[i] + 1;
        i++;
        no_1--;
    }
    
    num_1 = num_1 - 7;
}

// INITINALLING ADDING SEEDS ON PLAYER 2 TURN
void player2 (int array2[], int num2, int &pseed2)
{
  
    switch (num2)
    {
        case 1:
            pseed2 = array2[0];
            array2[0] = 0;
            for (int i = 1; i<7; i++)
            {
                array2[i] = array2[i]+1;
            }
            pseed2 = pseed2 - 6;
            break;
            
        case 2:
            pseed2 = array2[1];
            array2[1] = 0;
            for (int i = 2; i<7; i++)
            {
                array2[i] = array2[i]+1;
            }
            pseed2 = pseed2 - 5;
            break;
            
        case 3:
            pseed2 = array2[2];
            array2[2] = 0;
            for (int i = 3; i<7; i++)
            {
                array2[i] = array2[i]+1;
            }
            pseed2 = pseed2 - 4;
            break;
            
        case 4:
            pseed2 = array2[3];
            array2[3] = 0;
            for (int i = 4; i<7; i++)
            {
                array2[i] = array2[i]+1;
            }
            pseed2 = pseed2 - 3;
            break;
            
        case 5:
            pseed2 = array2[4];
            array2[4] = 0;
            for (int i = 5; i<7; i++)
            {
                array2[i] = array2[i]+1;
            }
            pseed2 = pseed2 - 2;
            break;
            
        case 6:
            pseed2 = array2[5];
            array2[5] = 0;
            for (int i = 6; i<7; i++)
            {
                array2[i] = array2[i]+1;
            }
            pseed2 = pseed2 -1;
            break;
            
        case 7:
            pseed2 = array2[6];
            array2[6] = 0;
            break;
    }
    
    
}
// COME BACK TO ADD SEEDS IN PLAYER 2 HOUSE IF SEEDS ARE REMAINED.
void add_player2 (int array_2[], int &num_2)
{
    int i = 0;
    int no_2 = 0;
    
    no_2 = num_2;
    
    while (no_2 != 0)
    {
            array_2[i] = array_2[i] + 1;
            i++;
            no_2--;
        
    }
    num_2 = num_2 - 7;
    
}



