#include "query.h"

/**
 * @brief Handles entire query process
 * 
 */
void query() {

    USER user;
    CITY city;
    QUERY query;
    query.user = &user
    query.city = &city;
    init_query(query);
    create_query_URL(query, query.city->city_name, query.user->app_id);

}

/**
 * @brief Initializes query. Asks for the city name and app id. 
 * 
 */
void init_query(QUERY query) {

    char *temp;

    // request app id
    temp = malloc(sizeof(char)*(MAX_APP_ID_LEN));
    if (temp != NULL) {
        printf("APP ID: ");
        fgets(temp, MAX_APP_ID_LEN, stdin);
        (query.user)->app_id_len = strlen(temp); // get size of app_id
        strcpy(query.user->app_id, temp); // set user app id

    } else {
        printf("Failed to allocate memory while requesting app ID");
    }
    free(temp);
    
    // request name of city to query 
    temp = malloc(sizeof(char)*(MAX_CITY_NAME_LEN));
    if (temp != NULL) {
        printf("CITY TO QUERY: ");
        fgets(temp, MAX_CITY_NAME_LEN, stdin);
        query.city->city_name_len = strlen(temp); // get size of city
        strcpy(query.city->city_name, temp); // set city to query 
    } else {
        printf("Failed to allocate memory while requesting city");
    }
    free(temp);
}

/**
 * @brief Create a query URL by appending city_name and app id to the request url
 * 
 */
void create_query_URL(QUERY query, char *city_name, char *app_id) {
    // set base URL
    strcpy(query.request_url, url);

    // add the city and app id parameters to the request URL
    strcat(query.request_url, "q=");
    strncat(query.request_url, city_name, city_name_len-1);
    strcat(query.request_url, "&appid=");
    strncat(query.request_url, app_id, app_id_len);
    printf("%sad", query.request_url);
}

/**
 * @brief Creates a query requests, and creates a file that stores the resonse from the query
 * 
 */
void send_query_request(char *request_url) {

}


/**
 * @brief Get the temp object
 * 
 * @return int 
 */
int get_temp(int kelvin_temp);

/**
 * @brief Return kelvin temperature to celsius temperature
 * 
 */
void convert_to_celsius(int temp) {
    temp = temp - 273.15;
}