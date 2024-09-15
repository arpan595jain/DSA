int strStr(char* haystack, char* needle) {
     for(int l = 0, r = strlen(needle); r <= strlen(haystack); l++, r++){
        char temp = haystack[r];
        haystack[r] = '\0';
        if (strstr( haystack+l, needle )){
