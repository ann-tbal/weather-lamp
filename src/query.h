#include "setup.h"
#include "secret.h"
#include <curl/curl.h>
#include "jsonparse.h"

static const char *temp_param = "temp";
static char *url = "http://api.openweathermap.org/data/2.5/weather?";
static char *fpname = "response.txt";

typedef struct {
    char request_url[MIN_QUERY_STR_LEN + MAX_CITY_NAME_LEN + MAX_APP_ID_LEN];
    USER *user;
    CITY *city; 
} QUERY;

/**
 * @brief Handles entire query process
 * 
 */
void query();

/**
 * @brief Initializes query. Sets the city name and app id
 * 
 * @param query 
 * @return QUERY object with appid and location set
 */
QUERY init_query(QUERY);

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

int read_file_for_temp(FILE *fp, char *fpname);
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
size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream);



