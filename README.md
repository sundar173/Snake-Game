# Snake-Game

My first attempt at building a game for Fun in C++. 

The following video helped me with this attempt, 
https://www.youtube.com/watch?v=PSoLD9mVXTA&list=PLRJuRxIsYMUX3iSmvyWPdKFaCooL455YQ&index=14

I made further tweaks based on the suggestions given in the comments section of the above video. The following summarizes those with code snippets, 

1. To avoid flickering cursor in the .exe file, 

// To avoid flickering cursor
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

2. To better smoothness of output screen
![image](https://user-images.githubusercontent.com/82727990/170604956-fb8a38ea-bfaf-415b-8c9c-d165041c3c9e.png)

3. // For different starting location for the fruit on each startup
	#include<ctime>
	srand(time(0)); 
	
4. To restart the game, 
	
![image](https://user-images.githubusercontent.com/82727990/170605004-51cfc59a-9f78-49c2-82cc-d0ce985bc77a.png)

	
5. For using arrow keys for Controls:

	#define KEY_UP 72
	#define KEY_DOWN 80
	#define KEY_LEFT 75
	#define KEY_RIGHT 77
	
Currently not used because it jumps too fast![image](https://user-images.githubusercontent.com/82727990/170604924-1c5155a2-6da4-4590-9cb9-2b4b84356dba.png)
