# Snake-Game

My first attempt at building a game for Fun in C++. 

The following video helped me with this attempt, 
https://www.youtube.com/watch?v=PSoLD9mVXTA&list=PLRJuRxIsYMUX3iSmvyWPdKFaCooL455YQ&index=14

I made further tweaks based on the suggestions given in the comments section of the above video. The following summarizes those with code snippets, 

1. To avoid flickering cursor in the .exe file, 

    void ShowConsoleCursor(bool showFlag)
    {
        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(out, &cursorInfo);
        cursorInfo.bVisible = showFlag; // set the cursor visibility
        SetConsoleCursorInfo(out, &cursorInfo);
    }
    
2. To better smoothness of output screen

    ![image](https://user-images.githubusercontent.com/82727990/170605478-0a64b7fe-cb5d-4875-876d-5e3c20cedfbf.png)

3. #include<ctime>
    srand(time(0)); // For different starting location for the fruit on each startup



