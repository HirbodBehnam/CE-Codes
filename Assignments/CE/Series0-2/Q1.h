#include <stdio.h>

int main() {
    float a = 1, b = 2, c = 3, X = 4, Y = 5;
    if(a == b && a == 0){
        puts("Line does not exist!");
    }else{
        if(a * X + b * Y + c == 0){
            puts("The point is on the line.");
        }else{
            if(b == 0){ // vertical line
                if(X > -c / a){
                    puts("Point at right of line.");
                }else{
                    puts("Point at left of line.");
                }
            }else{
                if(a * X + b * Y + c > 0){
                    puts("Point at top of line.");
                }else{
                    puts("Point at bottom of line.");
                }
            }
        }
    }
    return 0;
}