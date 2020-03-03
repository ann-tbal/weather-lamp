#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>


typedef struct {
    char *file_name;
    char *app_id;
} USER;

typedef struct {
    char *city_name;
    int temp;
} CITY; 

typedef struct {
    char *query_str;
    char *param; 
    USER user;
    CITY city; 
} QUERY;