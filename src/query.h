#include "setup.h"
<<<<<<< HEAD
#include <curl/curl.h>

// CURL *curl_easy_init();
// CURLcode curl_easy_setopt(CURL*, CURLoption, parameter);
// CURLcode curl_easy_perform(CURL *);
// void curl_easy_cleanup(CURL *);
=======
#include "secret.h"
>>>>>>> temperature

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
<<<<<<< HEAD
void set_query_URL(QUERY);
=======
QUERY set_query_URL(QUERY);
>>>>>>> temperature

/**
 * @brief Creates a query requests, and creates a file that stores the resonse from the query
 * 
 */
void send_query_request(FILE*, char*, QUERY);
<<<<<<< HEAD


/**
 * @brief Get the temp object from the file 
=======

/**
 * @brief read file <fp> for the temperature value 
>>>>>>> temperature
 * 
 * @return temperature (in degrees celsius)
 */
<<<<<<< HEAD
void read_file_for_temp();
=======
int read_file_for_temp(FILE *fp);
>>>>>>> temperature

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
static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)

/**
 * @brief libcurl prototype for write function callback
 * @return size_t 
 */
static size_t write_callback(void *, size_t, size_t, FILE *);

