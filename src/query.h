#include "setup.h"
#include <curl/curl.h>

// CURL *curl_easy_init();
// CURLcode curl_easy_setopt(CURL*, CURLoption, parameter);
// CURLcode curl_easy_perform(CURL *);
// void curl_easy_cleanup(CURL *);

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
 * @brief Get the temp object from the file 
 * 
 * @return int 
 */
void read_file_for_temp();

/**
 * @brief Return kelvin temperature to celsius temperature
 * 
 */
void convert_to_celsius(int);

/**
 * @brief libcurl prototype for write function callback
 * @return size_t 
 */
static size_t write_callback(void *, size_t, size_t, FILE *);

