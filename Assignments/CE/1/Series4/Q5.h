#ifndef QUERA_Q5_H
#define QUERA_Q5_H

#endif //QUERA_Q5_H

#include <stdlib.h>
#include <stdio.h>

/**
 * So how we are going to use a stack-like recursive function to solve this question?
 * Before going with stack, lemme explain what are we going to do if C had a stack datatype
 * The algorithm is to keep adding read numbers to stack while the read number is bigger than the top of stack
 * While adding numbers to top of stack, we print the last number that was at top of stack (this is legit the next number which is smaller than read number)
 * If the read number is equal to top of stack, we do not add it to stack; We only print it and get the next value
 * Now what if read number is less than top element in stack? We have to keep removing numbers from stack until we reach a number either equal or less than read number
 * If the number we reach after popping the elements is equal to read number, then just print it and do not add the number to stack
 * If the number we reach after popping the elements is less than read number, print the top of stack and then add the read number to stack
 * So how to convert this to a recursive function?
 * I tried to explain exactly in the function itself.
 * At very first add -1 to stack. Because all of the inputs are positive, so thus -1 is bigger than all of them
 * @param top The element at top of stack (same as stack.peek())
 * @return If the return value is 0, it means that all of the recursion calls must be canceled. If the return value is non zero it means that we should
 * cancel recursions until we reach a recursion that the 'before' is less than or equal to returned value
 */
int stack(int top) {
    while (1) {
        int read_number;
        scanf("%d", &read_number); // read the number
        if (read_number == 0) // kill switch of the recursion
            return 0; // all of the upper recursion must also exit when zero is returned
        if (top < read_number) { // the number is bigger than top of stack; Insert it into stack
            printf("%d\n", top); // print the top of stack before inserting read_number
            while (1) {
                /**
                 * The recursion call below is just like inserting (pushing) an element into stack
                 * Inserting into stack continues until... (read the comments on if statements)
                 */
                read_number = stack(read_number);
                if (read_number == 0) // we read the kill switch. In this case terminate everything
                    return 0;
                /**
                 * We have popped the stack until we have reached a number equal to top of stack
                 * No need to add this into stack; Just print the top of stack and get the next number
                 * Note that we have to continue to the very outer loop (just below the function definition)
                 */
                if (read_number == top) {
                    printf("%d\n", top);
                    /**
                     * break this loop because we don't want to add to stack;
                     * Please note that this is the only way this loop is going to be broken (all the other cases are return)
                     */
                    break;
                }
                /**
                 * We have popped the stack until we have reached a point that top of stack is less than the read_number
                 * So the read_number MUST be added to stack. Also before that we have to print the top of stack
                 */
                else if (read_number > top) {
                    printf("%d\n", top);
                    /**
                     * Continue the loop; Here it means that we are going to add read_number to top of stack again
                     * (because the recursive function gets called again)
                     */
                } else {
                    /**
                     * If the number is still smaller than top of stack, we have to pop the stack and more
                     * Returning here means same as popping the stack
                     */
                    return read_number;
                }
            }
        }
        /**
         * The number is equal to top value in stack; Just print it, and don't add anything to stack
         * Just print the number and get the next number
         */
        else if (read_number == top) {
            printf("%d\n", top);
            // Continue that outer loop
        }else {
            /**
             * If we reach here, it means that top of stack (before) is bigger than read_number
             * We have to pop the stack (go back in recursion) to find a 'before' which is less or equal to read_number
             */
            return read_number;
        }
    }
}

int main() {
    stack(-1);
    return 0;
}