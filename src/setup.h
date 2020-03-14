#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_APP_ID_LEN 40
#define MAX_CITY_NAME_LEN 20
#define MAX_FILE_NAME_LEN 20
#define MAX_VALUE_LEN 20
#define MIN_QUERY_STR_LEN 50

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    char app_id[MAX_APP_ID_LEN];
    int app_id_len; 
} USER;

typedef struct {
    char city_name[MAX_CITY_NAME_LEN];
    int city_name_len;
    int temp;
} CITY; 

