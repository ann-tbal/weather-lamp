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
void set_query_URL(QUERY);

/**
 * @brief Creates a query requests, and creates a file that stores the resonse from the query
 * 
 */
void send_query_request(FILE*, char*, QUERY);


/**
 * @brief read file <fp> for the temperature value 
 * 
 * @return temperature (in degrees celsius)
 */
int read_file_for_temp(FILE *fp);

/**
 * @brief Return kelvin temperature to celsius temperature
 * 
 */
void convert_to_celsius(int);

void temp_init_query(QUERY);

