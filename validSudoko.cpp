//https://www.codingninjas.com/codestudio/guided-paths/competitive-programming/content/148627/offering/1792826?leftPanelTab=1
//approch on new copy
bool isvalid(int matrix[9][9], int x, int row, int col)
{
    //check row
    for(int i = 0; i < 9; i++)
    {
        if(matrix[i][col] == x) return false;
    }
    //check col
     for(int i = 0; i < 9; i++)
    {
        if(matrix[row][i] == x) return false;
    }
    //check 3*3 matrix
     for(int i = 0; i < 9; i++)
    {
        if(matrix[3*(row/3) + i/3][3*(col/3) + i/3] == x) return false;
    }
    return true;
}
bool isItSudoku(int matrix[9][9]) {
    //traverse the whole matrix
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            //check the empty box
            if(matrix[i][j] == 0)
            {
                //start trying out all the possibilites
                for(int k = 1; k <= 9; k++)
                {
                    if(isvalid(matrix, k, i, j))
                    {
                        matrix[i][j] = k;
                        //continue checking for the next empty block if not possible then backtrack
                        bool ispossible = isItSudoku(matrix);
                        if(ispossible) return true; 
                        else
                        {
                            //backtrack
                            matrix[i][j] = 0;
                        }
                    }
                }
                //all of the numbers are tried but no one leads to valid sudoko
                return false;
            }
        }
    }
    return true;
}
