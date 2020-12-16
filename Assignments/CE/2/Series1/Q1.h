int main() {
    int balance, code;
    float tax;
    if (balance < 100) {
        if (code == 1) {
            tax = 0.05f;
        } else {
            tax = 0.1f;
        }
        /**
         * Also could have used
         * tax = code == 1 ? 0.05f : 0.1f;
         * or
         * tax = code ? 0.05f : 0.1f;
         */
    } else { // balance >= 100
        if (code == 2 || balance < 200) {
            tax = 0.2f;
        } else { // balance >= 200 && code != 2
            tax = 0.25f;
        }
    }
    return 0;
}