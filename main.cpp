#include <iostream>
#include<conio.h>
#include<windows.h>
#include<ctime>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

char outputbuf[800];
using namespace std;
bool gameOver;
const int height = 20, width = 40;
int x, y, FruitX, FruitY, score, snakeTailLength;
int x_prev[100], y_prev[100];

enum snakeMove {stop = 0, left, right, up, down};
snakeMove state;

void Setup()
{
    // std::cout.rdbuf()->pubsetbuf(outputbuf, sizeof(outputbuf));
    // ios::sync_with_stdio(true);     
    
    gameOver = false;
    // snakeTailLength = 1;
    state = snakeMove::stop;
    x = width/2;
    y = height/2;
    srand(time(0)); // For different starting location for the fruit on each startup
    FruitX = rand()%width;
    FruitY = rand()%height;
    score = 0;
    
}


void Input()
{
    if(_kbhit())
    {
        switch (_getch())
        {
            case 'a'://KEY_LEFT:
            state = snakeMove::left;
            break;

            case 'd'://KEY_RIGHT:
            state = snakeMove::right;
            break;
            
            case 'w'://KEY_UP:
            state = snakeMove::up;
            break;

            case 's'://KEY_DOWN:
            state = snakeMove::down;
            break;

            case 'x':
            gameOver = true;
            break;
        }
    }
    // else // Continuous flow stop --> If uncommented will kill the code (i.e Thinks it hasn't moved and would mean hitting itself)
    //     state = snakeMove::stop;
}

void Draw()
{
    system("cls");

    for(int i=0;i<width+2;i++) // Top boundary
        cout<<"#";
    cout<<'\n';

    for(int i=0;i<height;i++)
    {
        for(int j = 0;j<width;j++)
        {
            if(j == 0) // Left Boundary
                cout<<"#";
            if(i ==y && j ==x) // Snake Head
                cout<<"O";
            else if(i==FruitY && j ==FruitX) // Fruit location
                cout<<"F";
            else // Snake Tails
            {
                bool wasPrinted = false;
                for(int k = 0;k<snakeTailLength;k++)
                {
                    if(x_prev[k] == j && y_prev[k] == i)
                        {
                            wasPrinted = true;
                            cout<<"o";
                        }  
                }
                if(!wasPrinted)
                    cout<<" ";
            }
            if(j == width-1) // Right boundary
                cout<<"#";
        }
        cout<<'\n';
        
    }
    for(int i=0;i<width+2;i++) // Bottom boundary
        cout<<"#";  
    cout<<'\n';
    cout<<"Score:"<<score<<endl;
}

void Logic()
{
    int temp1_x, temp2_x, temp1_y, temp2_y;
    temp1_x = x_prev[0];
    temp1_y = y_prev[0];
    x_prev[0] = x;
    y_prev[0] = y;  


    for(int i=1;i<snakeTailLength;i++)
    {   
        // if( i ==1 )
        // {
        //     x_prev[i] = temp1_x;
        //     y_prev[i] = temp1_y;
        // }
        // else
        // {
        //     x_prev[i] = x_prev[i-1];
        //     y_prev[i] = y_prev[i-1];
        // }
        temp2_x = x_prev[i];
        temp2_y = y_prev[i];
        x_prev[i] = temp1_x;
        y_prev[i] = temp1_y;
        temp1_x = temp2_x;
        temp1_y = temp2_y;
    }

// The following switch statement's position here(after above logic) affects how we track the tails above
    switch (state)
    {
        case snakeMove::left:
        x--;
        break;

        case snakeMove::right:
        x++;
        break;

        case snakeMove::up:
        y--;
        break;
    
        case snakeMove::down:
        y++;
        break;

        case snakeMove::stop:
        break;
    }

    // To stop the game if the Snake Head hits the boundary

    /*if(x<=0 || x>=width-1 || y<0 || y>=height)
    {
        cout<<"Oops! Game Over"<<'\n';
        gameOver = true;
    }*/

    // To pass the snake through the boundary and bring it in through the other end
    if(x<0)    x = width-1;
    else if(x>width-1) x = 0;
    
    if(y<0) y = height-1;
    else if(y>=height)  y = 0;

    // Game over if Snake head hits its body part

    for(int i = 0; i<snakeTailLength;i++)
    {
        if(x_prev[i]==x && y_prev[i] ==y)
        {
            cout<<"Oops! You bit yourself"<<'\n';
            gameOver = true;
        }
           
    }
    // To update score, snakeTailLength if fruit is eaten, Also update the next fruit position
    if(x == FruitX && y == FruitY)
    {
        snakeTailLength++;
        score +=10;
        FruitX = rand()%width;
        FruitY = rand()%height;
    } 

}

// To avoid flickering cursor
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

// Main run file
int main()
{
    Setup();
    ShowConsoleCursor(false);
    while(!gameOver)
    {
        
        Draw();
        Input();
        Logic();
        // Sleep(10);
    }

    // For Enabling Game restart

    // cout<<"Game Over!"<<endl;
    // cout<<"Press 'r' + Enter to restart the game, Press 'x' + Enter to quit the game"<<flush;
    // cout<<endl;
    // string userCommand;
    // cin>>userCommand;
    // if(userCommand == "r")
    //     main();
return 0;
}
