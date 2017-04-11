//
//  main.c
//  Text_Editor
//
//  Created by 张狼 on 2017/4/11.
//  Copyright © 2017年 张狼. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>
#include <termios.h>

void enableRawMode(){
    struct termios raw;
    tcgetattr(STDIN_FILENO, &raw);
    
    raw.c_lflag &= ~(ECHO);
    
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    enableRawMode();
    
    char c;
    while(read(STDIN_FILENO, &c, 1) == 1 && c != 'q');
    
    return 0;
}
