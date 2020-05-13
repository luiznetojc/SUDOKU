#include <iostream>
#include <algorithm>
#include <sstream>
#define SIZE 9

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
bool possible(int y,int x,int n,short h[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        if(h[y][i] == n){
            std::cout << n <<  "line teste";
            return false;
        }

    }
    for (int i = 0; i < SIZE; i++)
    {
        if(h[i][x] == n){
            std::cout << "colum teste";
            return false;
        }

    }
    int xi = (x / 3)*3;

    int yi = (y / 3)*3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (h[yi+i][xi+j]== n){
                std::cout << "square teste";
                return false;
            }
            
        }
        
    }
     std::cout << "deu true\n";
    return true;
}
void solve(short m[SIZE][SIZE])
{
    for (short y = 0; y < SIZE; y++)
    {
        for (short x = 0; x < SIZE; x++)
        {
            if(m[y][x] == 0)
            {
                std::cout << x << y << "\n";
                for (int n = 1; n < 10; n++)
                {
                     bool valid = true;
                     valid = possible(y,x,n,m);
                    if(valid)
                    {
                        m[y][x] = n;
                        solve(m);
                        m[y][x] = 0;
                    }
                }
                return;
            
            }
        }
    
    }
    print(m);

}
       

int main()
{
   short b[SIZE][SIZE];
    while(!std::cin.eof()) //read input
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                std::cin >> b[i][j];         
            }
        }
    std::cout << "Board: \n";
    print( b );
    std::cout << "solve: \n" ;
    solve( b );
    }
}