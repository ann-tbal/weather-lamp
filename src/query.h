#include "setup.h"

/**
 * @brief Handles entire query process
 * 
 */
void query();

/**
 * @brief Initializes query. Asks for the city name and app id. 
 * 
 */
void init_query(QUERY);

/**
 * @brief Create a query URL by appending city_name and app id to the request url
 * 
 */
void set_query_URL(QUERY, char*, char*);

/**
 * @brief Creates a query requests, and creates a file that stores the resonse from the query
 * 
 */
void send_query_request();


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
void convert_to_celsius(int);

