#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include <math.h>

void reverse(char* str, int len) 
{ 
    int i = 0, j = len - 1, temp; 
    while (i < j) { 
        temp = str[i]; 
        str[i] = str[j]; 
        str[j] = temp; 
        i++; 
        j--; 
    } 
} 

// Converts a given integer x to string str[]. 
// d is the number of digits required in the output. 
// If d is more than the number of digits in x, 
// then 0s are added at the beginning. 
int intToStr(int x, char str[], int d) 
{ 
    int i = 0; 
    while (x) { 
        str[i++] = (x % 10) + '0'; 
        x = x / 10; 
    } 

    // If number of digits required is more, then 
    // add 0s at the beginning 
    while (i < d) 
        str[i++] = '0'; 

    reverse(str, i); 
    str[i] = '\0'; 
    return i; 
}

void ftoa(float n, char* res, int afterpoint) 
{ 
    // Extract integer part 
    int ipart = (int)n; 

    // Extract floating part 
    float fpart = n - (float)ipart; 

    // convert integer part to string 
    int i = intToStr(ipart, res, 0); 

    // check for display option after point 
    if (afterpoint != 0) { 
        res[i] = '.'; // add dot 

        // Get the value of fraction part upto given no. 
        // of points after dot. The third parameter 
        // is needed to handle cases like 233.007 
        fpart = fpart * pow(10, afterpoint); 

        intToStr((int)fpart, res + i + 1, afterpoint); 
    } 
}

int main() {
    InitWindow(400, 300, "Calculator");
    SetTargetFPS(60);
    
    char displayText[256] = "";
    float firstNumber = 0;
    float secondNumber = 0;
    float finalNumber = 0;
    char operator = 0;
    bool enteringsecondnumber = false;
    while (!WindowShouldClose()) {

        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawText(displayText, 25, 25, 25, BLACK);


            if (GuiButton((Rectangle){50, 50, 50, 25}, "1")) {
                strcat(displayText, "1"); 
            } 
            if (GuiButton((Rectangle){100, 50, 50, 25}, "2")) {
                strcat(displayText, "2"); 
            } 
            if (GuiButton((Rectangle){150, 50, 50, 25}, "3")) { 
                strcat(displayText, "3"); 
            }      
            if (GuiButton((Rectangle){50, 75, 50, 25}, "4")) {
                strcat(displayText, "4"); 
            }
            if (GuiButton((Rectangle){100, 75, 50, 25}, "5")) {
                strcat(displayText, "5"); 
            }
            if (GuiButton((Rectangle){150, 75, 50, 25}, "6")) {
                strcat(displayText, "6"); 
            }
            if (GuiButton((Rectangle){50, 100, 50, 25}, "7")) {
                strcat(displayText, "7"); 
            }
            if (GuiButton((Rectangle){100, 100, 50, 25}, "8")) {
                strcat(displayText, "8"); 
            }
            if (GuiButton((Rectangle){150, 100, 50, 25}, "9")) {
                strcat(displayText, "9"); 
            }
            if (GuiButton((Rectangle){50, 125, 50, 25}, "0")) {
                strcat(displayText, "0"); 
            }
            if (GuiButton((Rectangle){100, 125, 50, 25}, ".")) {
                strcat(displayText, "."); 
            }
            if (GuiButton((Rectangle){150, 125, 50, 25}, "=")) {
                secondNumber = atof(displayText);
                displayText[0] = '\0';
                switch (operator) {
                    case '+':
                        finalNumber = firstNumber + secondNumber;
                        break;
                    case '-': 
                        finalNumber = firstNumber - secondNumber;
                        break;
                    case '*':
                        finalNumber = firstNumber * secondNumber;
                        break;
                    case '/':
                        finalNumber = (secondNumber != 0) ? firstNumber / secondNumber : 0; 
                        break;
                }
                ftoa(finalNumber, displayText, 3);
            }
            if (GuiButton((Rectangle){200, 50, 50, 25}, "+")) {
                firstNumber = atof(displayText);
                displayText[0] = '\0';
                operator = '+';
                enteringsecondnumber = true;
            }
            if (GuiButton((Rectangle){200, 75, 50, 25}, "-")) {
                firstNumber = atof(displayText);
                displayText[0] = '\0';
                operator = '-';
                enteringsecondnumber = true;
            }
            if (GuiButton((Rectangle){200, 100, 50, 25}, "*")) {
                firstNumber = atof(displayText);
                displayText[0] = '\0';
                operator = '*';
                enteringsecondnumber = true;
            }
            if (GuiButton((Rectangle){200, 125, 50, 25}, "/")) {
                firstNumber = atof(displayText);
                displayText[0] = '\0';
                operator = '/';
                enteringsecondnumber = true;
            }
            if (GuiButton((Rectangle){250, 50, 50, 25}, "C")) {
                displayText[0] = '\0';
            }
            if (GuiButton((Rectangle){250, 75, 50, 25}, "AC")) {
                displayText[0] = '\0';
                firstNumber = 0;
                secondNumber = 0;
                enteringsecondnumber = false;
                operator = 0;
            }
            if (GuiButton((Rectangle){250, 100, 50, 25}, "Quit")) {
                displayText[0] = '\0';
                firstNumber = 0;
                secondNumber = 0;
                enteringsecondnumber = false;
                operator = 0;
                exit(0);
            }
        EndDrawing();

    }

    CloseWindow();
    return 0;
}
