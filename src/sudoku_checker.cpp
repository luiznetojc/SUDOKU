#include <iostream>
#include <algorithm>
#include <sstream>

#define EMPTY short(0)
#define SIZE 9

bool auxverify(int aux[]) //verify array aux
{
    for (int f = 0; f < SIZE; ++f) // verify array if all numbers are located
            {   
                if(aux[f] != 1)
                    return false;  
                    aux[f] = 0; // clean array
            }
    return true;
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
                for(int k = 0; k < 3; ++k)
                {    
                    std::cout << b[i][j] <<" ";
                    j++;
                }
                j--;   
                std::cout << "]" <<"  ";  
            }
            std::cout << std::endl;
            i++;
       }
       i--;
       std::cout << std::endl;
    }

}

bool verifyline(short b[SIZE][SIZE],int lin) //verify one line in the sudoku
{
    int aux[SIZE] = {0};      // auxiliary array to mark presence or not of a number in line
    
    for (int i = 0; i < SIZE; ++i)      // mark in array auxiliary
    {
        aux[b[lin][i]-1]++;
    }

    return(auxverify(aux));
}

bool verifycolumn(short b[SIZE][SIZE],int col) //verify one column in the sudoku
{
   
    int aux[SIZE] = {0};      // auxiliary array to mark presence or not of a number in line
    for (int i = 0; i < SIZE; ++i)      // mark in array auxiliary
    
    {
        aux[b[i][col]-1]++;
    }

    return(auxverify(aux));
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
               
                y -= 3; //restart y
                x++;
            }
            
            x -= 3; //restart x
            
            return(auxverify(aux));

            y += 3; //next square 
        }
    y = 0; //clean y to verify squares below

    x += 3; // go to squares below 
    }
    return true;
}

bool is_valid( short b[SIZE][SIZE] ) //Test is valid sudoku table
{
    
    for (int i = 0; i < SIZE; ++i)
    {
        if(!verifyline(b,i)) return false;
        
        else if(!verifycolumn(b,i)) return false;

    }
        if(!verifysquare(b)) return false;
    return true;
}


int main(void)
{
    short board[SIZE][SIZE];
    while(!std::cin.eof()) //read input
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                std::cin >> board[i][j];         
            }
        }
    std::cout << "Board: \n";
    print( board );
    std::cout << "Is valid? " << std::boolalpha << is_valid( board ) << std::endl;
    std::cout << "\n";


  }  

    return 0;
}
