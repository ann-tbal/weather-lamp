#include "setup.h"
#include "secret.h"

/**
 * @brief Handles entire query process
 * 
 */
void query();

/**
 * @brief Temporary query init so I don't have to keep entering the city.
 * 
 * @param query 
 * @return QUERY 
 */
QUERY temp_init_query(QUERY);

/**
 * @brief Initializes query. Asks for the city name and app id. 
 * 
 */
void init_query(QUERY);

/**
 * @brief Create a query URL by appending city_name and app id to the request url
 * 
 */
QUERY set_query_URL(QUERY);

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
int convert_to_celsius(int);


/**
 * @brief Utility function for writing data to some file pointed by ptr
 * 
 * @param ptr 
 * @param size 
 * @param nmemb 
 * @param stream 
 * @return size_t 
 */
static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream);

