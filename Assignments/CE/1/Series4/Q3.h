#ifndef QUERA_Q3_H
#define QUERA_Q3_H

#endif //QUERA_Q3_H

#include <stdbool.h>
#include <stdio.h>

/**
 * Listens to the conversation and counts the points of each person. See Return value for more information
 * Positive numbers mean that elliot has won. Negative numbers mean that kidnapper has won
 * @param elliot Elliot points
 * @param kidnapper Kidnapper points
 * @param elliot_talking True if elliot is talking; This argument is necessary because in case that elliot is speaking and we see anything
 * but 'b', we have to terminate the recursion
 * @return A number that it's abstract value is the total words spoken; This number is positive if elliot have won; Otherwise it's negative
 */
int listen(int elliot, int kidnapper, bool elliot_talking) {
    if (elliot >= kidnapper) // Elliot won
        return elliot + kidnapper;
    char word = getchar(); // read next word
	// check the end. For example aabaaaac must return 5. NO; Because elliot was talking and we heard a 'a'
    if (elliot_talking && word != 'b') {
        if (elliot >= kidnapper) // Elliot won! Return positive number
            return elliot + kidnapper + 1; // + 1 is because we have already read a char
        // Kidnapper won! Return negative value
        return -(elliot + kidnapper + 1);
    }
	 // whatever the case is, b must add one to elliot
    if (word == 'b')
        elliot++;
    // if elliot is not speaking
    if (word == 'a') // kidnapper is speaking
        kidnapper++;
    return listen(elliot, kidnapper, word == 'b');
}

int main() {
    int result = listen(0, 1, false);
    if (result > 0)
        printf("%d. YES", result);
    else
        printf("%d. NO", -result);
    return 0;
}
