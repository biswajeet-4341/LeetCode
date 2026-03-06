bool checkOnesSegment(char* s) {
    int i = 0;

    while (i < strlen(s)) {
        if (s[i] == '0') {
            while (i < strlen(s) && s[i] == '0') {
                i++;
            }
            bool retn = (i >= strlen(s)) ? true : (s[i] == '1') ? false : true;
            return retn;
        }

        i++;
    }

    return true;
}