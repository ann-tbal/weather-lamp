#include "query.h"

/**
 * @brief Handles entire query process
 * 
 */
void query() {
    init_query();
}

/**
 * @brief Initializes query. Asks for the city name and app id. 
 * 
 */
void init_query() {
    //initialize empty query, user, and city
    USER user;
    CITY city;
    QUERY query;
    query.user = user;
    query.city = city;

    // ask for app id, and city name
    printf("APP ID: ");
    scanf("%lf", ((query.user).app_id));

    printf("CITY TO QUERY: ");
    scanf("%s", ((query.city).city_name));

    //printf("%s %s", query.user->app_id, query.user.city_name);
}

/**
 * @brief Create a query URL by appending city_name and app id to the request url
 * 
 */
char *create_query_URL(QUERY);

/**
 * @brief Creates a query requests, and creates a file that stores the resonse from the query
 * 
 */
void send_query_request(FILE);


/**
 * @brief Get the temp object
 * 
 * @return int 
 */
int get_temp(int);

/**
 * @brief Return kelvin temperature to celsius temperature
 * 
 */
void convert_to_celsius(int temp) {
    temp = temp - 273.15;
}