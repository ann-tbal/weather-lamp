#include "jsonparse.h"

/**
 * @brief Get the int value from json object
 * 
 * @param fp 
 * @param fpname 
 * @param param 
 * @param expected_length 
 * @return value,
 */
void get_value_from_json(FILE *fp, char *fpname, const char *param, char *value) {
    // walks through line by line
    char buffer[MAX_LINE_LEN];
    // walks through word by word
    char *token;
    char delimeters[] = "\":{},";
    // checks if value has been found
    int found = 0;
    fp = fopen(fpname, "r");
    if (fp) {
        while (fgets(buffer, MAX_LINE_LEN, fp) && found == 0) {
            token = strtok(buffer, delimeters);
            while( token != NULL && found == 0) {
                token = strtok(NULL, delimeters);
                if (strcmp(param, token) == 0) {
                    // read the next value
                    token = strtok(NULL, delimeters);
                    found = 1;
                    strcpy(value, token);
                }
            }
        }
    }
}