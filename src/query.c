#include "query.h"

static FILE *fp;
static char *file_name = "response.txt";


/**
 * @brief Handles entire query process
 * 
 */
void query() {
    USER user;
    CITY city;
    QUERY query;
    query.user = &user;
    query.city = &city;

    query = temp_init_query(query);
    query = set_query_URL(query);
    printf("%s", query.request_url);
    send_query_request(fp, fpname, query);
}

/**
 * @brief Temporary query init so I don't have to keep entering the city.
 * 
 * @param query 
 * @return QUERY 
 */
QUERY temp_init_query(QUERY query) {
    strcpy(query.user->app_id, temp_APPID);
    strcpy(query.city->city_name, temp_CITY);
    query.user->app_id_len = strlen(query.user->app_id) + 1;
    query.city->city_name_len = strlen(query.city->city_name) + 1;
    return query;
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
QUERY set_query_URL(QUERY query) {
    strcpy(query.request_url, url);// set base url
    strcat(query.request_url, "q="); // add city parameter to the url
    strncat(query.request_url, query.city->city_name, query.city->city_name_len-1);
    strcat(query.request_url, "&appid="); // add the app id to the url
    strncat(query.request_url, query.user->app_id, strlen(query.request_url) + strlen(query.user->app_id));
    return query;
}
 
static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
  size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
  return written;
}

/**
 * @brief Creates a query requests, and creates a file that stores the resonse from the query
 * 
 */
void send_query_request(FILE *fp, char *fpname, QUERY query) {
    fp = fopen(fpname, "wb");
    if (fp != NULL) {
        CURL *curl;
        CURLcode res;

        curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, query.request_url);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
            curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");
            res = curl_easy_perform(curl);
            if(res != CURLE_OK) {
                fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
            }
        } else {
            printf("Curl init failed.");
        }
        curl_easy_cleanup(curl);
    } else {
        printf("File open not opened.");
    }
    fclose(fp);
}

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
void convert_to_celsius(int temp) {
    temp = temp - 273.15;
}

