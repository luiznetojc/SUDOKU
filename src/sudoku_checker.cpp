#include <iostream>
#include <algorithm>
#include <sstream>

#define EMPTY short(0)
#define SIZE 9
void printr( short b[SIZE][SIZE][2],int n ) 
{
    //these (for's) below make a good print of the SUDOKU table;
    for (int i = 0; i < SIZE; ++i)
    {
       for (int m = 0; m < 3; ++m)
       {
            for (int j = 0; j < 9; ++j)
            {
                std::cout << "[";
                for(int k = 0; k < 3;++k)
                {    
                    std::cout<<b[i][j][n]<<" ";
                    j++;
                }
                j--;   
                std::cout << "]" <<"  ";  
            }
            std::cout << std::endl;
            i++;
       }
       i--;
       std::cout<<std::endl;
    }

}
void print( short b[SIZE][SIZE] ) 
{
    //these (for's) below make a good print of the SUDOKU table;
    for (int i = 0; i < SIZE; ++i)
    {
       for (int m = 0; m < 3; ++m)
       {
            for (int j = 0; j < 9; ++j)
            {
                std::cout << "[";
                for(int k = 0; k < 3;++k)
                {    
                    std::cout<<b[i][j]<<" ";
                    j++;
                }
                j--;   
                std::cout << "]" <<"  ";  
            }
            std::cout << std::endl;
            i++;
       }
       i--;
       std::cout<<std::endl;
    }

}
bool verifyline(short b[SIZE][SIZE],int lin)        //verify one line in the sudoku
{
    int k[SIZE] = {0};      // auxiliary array to mark presence or not of a number in line
    
    for (int i = 0; i < SIZE; ++i)      // mark in array auxiliary
    {
        k[b[lin][i]-1]++;
    }

    for (int i = 0; i < SIZE; ++i)      // verify array if all numbers are located
    {
        if(k[i] != 1)return false;
    }
    return true;
}
bool verifycolumn(short b[SIZE][SIZE],int col)      //verify one column in the sudoku
{
   
    int k[SIZE] = {0};      // auxiliary array to mark presence or not of a number in line
    for (int i = 0; i < SIZE; ++i)      // mark in array auxiliary
    
    {
        k[b[i][col]-1]++;
    }

    for (int i = 0; i < SIZE; ++i)       // verify array if all numbers are located
    {
        if(k[i] != 1)return false;
    }
    return true;
}
bool verifysquare(short b[SIZE][SIZE])
{
    int aux[SIZE] = {0};
    int x,y;
    x = y = 0; //vars aux to manipulate on squares
    for (int i = 0; i < 3; ++i) // 3 times in line of squares
    {
        for (int n = 0; n < 3; ++n) // 3 times in columns os squares
        {
            for (int j = 0; j < 3; ++j) // 3 times lines
            {
                for (int k = 0; k < 3; ++k) // 3 times colunms
                {

                    aux[b[x][y]-1]++; // incremment in array aux
                    
                    y++;
                }
               
                y = y - 3; //restart y
                x++;
            }
            
            x = x - 3; //restart x
            
            for (int f = 0; f < SIZE; ++f) // verify array if all numbers are located
            {   
                if(aux[f] != 1)
                    return false;  
                    aux[f] = 0; // clean array
            }

            y = y + 3; //next square 
        }
    y = 0; //clean y to verify squares below
    x = x + 3; // go to squares below 
    }
    return true;
}
bool is_valid( short b[SIZE][SIZE] )
{
    
    for (int i = 0; i < SIZE; ++i)
    {
        if(verifyline(b,i) == false) return false;
        
        else if(verifycolumn(b,i) == false) return false;

    }
        if(verifysquare(b) == false) return false;
    return true;
}


int main(void)
{
    short board[SIZE][SIZE][2]={
         1, 3, 4, 6, 7, 8, 5, 9, 2,
         6, 7, 2, 1, 9, 5, 3, 4, 8,
         5, 9, 8, 3, 4, 2, 1, 6, 7,
         8, 5, 9, 7, 6, 1, 4, 2, 3,
         4, 2, 6, 8, 5, 3, 9, 7, 1,
         7, 1, 3, 4, 2, 9, 8, 5, 6,
         9, 6, 1, 5, 3, 7, 2, 8, 4,
         2, 8, 7, 9, 1, 4, 6, 3, 5,
         3, 4, 5, 2, 8, 6, 7, 1, 9, 
         1, 6, 2, 8, 5, 7, 4, 9, 3,
         5, 3, 4, 1, 2, 9, 6, 7, 8,
         7, 8, 9, 6, 4, 3, 5, 2, 1,
         4, 7, 5, 3, 1, 2, 9, 8, 6,
         9, 1, 3, 5, 8, 6, 7, 4, 2,
         6, 2, 8, 7, 9, 4, 1, 3, 5,
         3, 5, 6, 4, 7, 8, 2, 1, 9,
         2, 4, 1, 9, 3, 5, 8, 6, 7,
         8, 9, 7, 2, 6, 1, 3, 5, 4 };

    short board2[SIZE][SIZE]={
        { 1, 6, 2, 8, 5, 7, 4, 9, 3 },
        { 5, 3, 4, 1, 2, 9, 6, 7, 8 },
        { 7, 8, 9, 6, 4, 3, 5, 2, 1 },
        { 4, 7, 5, 3, 1, 2, 9, 8, 6 },
        { 9, 1, 3, 5, 8, 6, 7, 4, 2 },
        { 6, 2, 8, 7, 9, 4, 1, 3, 5 },
        { 3, 5, 6, 4, 7, 8, 2, 1, 9 },
        { 2, 4, 1, 9, 3, 5, 8, 6, 7 },
        { 8, 9, 7, 2, 6, 1, 3, 5, 4 } };

    short board3[SIZE][SIZE]={
        { 5, 3, 4, 6, 7, 8, 9, 1, 2 },
        { 6, 7, 2, 1, 9, 5, 3, 4, 8 },
        { 1, 9, 8, 3, 4, 2, 5, 6, 7 },
        { 8, 5, 9, 7, 6, 1, 4, 2, 3 },
        { 4, 2, 6, 8, 5, 3, 7, 9, 1 },
        { 7, 1, 3, 9, 2, 4, 8, 5, 6 },
        { 9, 6, 1, 5, 3, 7, 2, 8, 4 },
        { 2, 8, 7, 4, 1, 9, 6, 3, 5 },
        { 3, 4, 5, 2, 8, 6, 1, 7, 9 } };

    short board4[SIZE][SIZE]={
        { 6, 2, 1, 9, 5, 7, 3, 4, 8 },
        { 2, 7, 4, 1, 9, 8, 6, 3, 5 },
        { 1, 8, 3, 4, 2, 9, 5, 6, 7 },
        { 8, 9, 7, 6, 1, 5, 4, 2, 3 },
        { 4, 6, 8, 5, 3, 2, 7, 9, 1 },
        { 5, 4, 6, 7, 8, 3, 9, 1, 2 },
        { 7, 3, 9, 2, 4, 1, 8, 5, 6 },
        { 9, 1, 5, 3, 7, 6, 2, 8, 4 },
        { 3, 5, 2, 8, 6, 4, 1, 7, 9 } };


    // Problem
    short board5[SIZE][SIZE]={
        { 6, 2, 1, 9, 5, 7, 3, 4, 8 },
        { 2, 7, 4, 1, 9, 8, 6, 3, 5 },
        { 1, 8, 3, 4, 2, 9, 5, 6, 7 },
        { 8, 9, 7, 6, 1, 5, 4, 2, 3 },
        { 4, 6, 8, 5, 3, 2, 5, 9, 1 },
        { 5, 4, 6, 7, 8, 3, 9, 1, 2 },
        { 7, 3, 9, 2, 4, 1, 8, 5, 6 },
        { 9, 3, 5, 3, 7, 6, 2, 8, 4 },
        { 3, 5, 2, 8, 6, 4, 1, 7, 9 } };

    // Problem
    short board6[SIZE][SIZE]={
        { 6, 2, 1, 9, 5, 7, 3, 4, 8 },
        { 2, 7, 4, 1, 9, 8, 6, 3, 5 },
        { 1, 8, 3, 4, 2, 19, 5, 6, 7 },
        { 8, 9, 7, 6, 1, 5, 4, 2, 3 },
        { 4, 6, 8, 5, 3, 2, 7, 9, 1 },
        { 5, 4, 6, 7, 8, 3, 9, 1, 2 },
        { 7, -3, 9, 2, 4, 1, 8, 5, 6 },
        { 9, 1, 5, 3, 7, 6, 2, 8, 4 },
        { 3, 5, 2, 8, 6, 4, 1, 7, 9 } };

    // Problem
    short board7[SIZE][SIZE]={
        { 6, 2, 1, 9, 5, 7, 3, 4, 8 },
        { 2, 7, 4, 1, 9, 8, 6, 3, 5 },
        { 1, 8, 3, 4, 2, 9, 5, 6, 7 },
        { 8, 9, 7, 6, 1, 5, 4, 2, 3 },
        { 4, 6, 8, 5, 3, 2, 7, 9, 1 },
        { 5, 4, 6, 7, 8, 3, 9, 1, 2 },
        { 7, 3, 9, 2, 4, 1, 0, 5, 6 },
        { 9, 1, 5, 3, 7, 6, 2, 8, 4 },
        { 3, 5, 2, 8, 6, 4, 1, 7, 9 } };

    // Problem
    short board8[SIZE][SIZE]={
        { 6, 2, 1, 9, 5, 7, 3, 4, 8 },
        { 2, 7, 4, 1, 9, 8, 6, 3, 5 },
        { 1, 8, 3, 4, 2, 9, 5, 6, 7 },
        { 8, 9, 7, 3, 1, 5, 4, 2, 3 },
        { 4, 6, 8, 5, 3, 2, 7, 9, 1 },
        { 5, 4, 6, 7, 8, 6, 9, 1, 2 },
        { 7, 3, 9, 2, 4, 1, 8, 5, 6 },
        { 9, 1, 5, 3, 7, 6, 2, 8, 4 },
        { 3, 5, 2, 8, 6, 4, 1, 7, 9 } };

    std::cout << "Board: \n";
    for (int i = 0; i < 2; ++i)
    {
    printr( board,2);
   // std::cout << "Is valid? " << std::boolalpha << is_valid( board ) << std::endl;
    std::cout << "\n";
    }
    //std::cout << "Board: \n";
    //print( board );
    //std::cout << "Is valid? " << std::boolalpha << is_valid( board2 ) << std::endl;
    //std::cout << "\n";


    std::cout << "Board: \n";
    print( board3 );
    std::cout << "Is valid? " << std::boolalpha << is_valid( board3 ) << std::endl;
    std::cout << "\n";


    std::cout << "Board: \n";
    print( board4 );
    std::cout << "Is valid? " << std::boolalpha << is_valid( board4 ) << std::endl;
    std::cout << "\n";


    std::cout << "Board: \n";
    print( board5 );
    std::cout << "Is valid? " << std::boolalpha << is_valid( board5 ) << std::endl;
    std::cout << "\n";


    std::cout << "Board: \n";
    print( board6 );
    std::cout << "Is valid? " << std::boolalpha << is_valid( board6 ) << std::endl;
    std::cout << "\n";


    std::cout << "Board: \n";
    print( board7 );
    std::cout << "Is valid? " << std::boolalpha << is_valid( board7 ) << std::endl;
    std::cout << "\n";


    std::cout << "Board: \n";
    print( board8 );
    std::cout << "Is valid? " << std::boolalpha << is_valid( board8 ) << std::endl;
    std::cout << "\n";

    /* TODO: Make the code below work, instead of the ugly code above.

    int n_boards{8}; // Number of boards...
    for ( int i{0}; i < n_boards ; ++i )
    {
        std::cout << "Board #" << (i+1) << ": \n";
        print( boards[i] );
        std::cout << "Is valid? " << std::boolalpha << is_valid( board[i] ) << std::endl;
        std::cout << "\n";
    }

    */

    return 0;
}
