#include "query.h"

/**
 * @brief Handles entire query process
 * 
 */
void query() {

    enum query_flags query_flag;
    USER user;
    CITY city;
    QUERY query;
    query.user = &user;
    query.city = &city;

    /**
     * @brief uncomment this to set a dynamic (unchanging?) app_id and city. 
     just got tired ot having to re-enter it. each and every tiem
     * 
     */
    strcpy(query.user->app_id, myappid);
    strcpy(query.city->city_name, mycity);
    set_query_URL(query);
    send_query_request(fp, file_name, query);
    // if (query_flag.FILE_WRITE_SUCCESS >= 0) {
    //     read_file_for_temp();
    // }

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
void set_query_URL(QUERY query) {
    // set base URL
    strcpy(query.request_url, url);

    // add the city and app id parameters to the request URL
    strcat(query.request_url, "q=");
    strncat(query.request_url, query.city->city_name, query.city->city_name_len -1 );
    strcat(query.request_url, "&appid=");
    strncat(query.request_url, query.user->app_id, strlen(query.request_url) + strlen(query.user->app_id));
    strcat(query.request_url, "\n");
    printf("%s", query.request_url);
}

/**
 * @brief Creates a query to the OpenWeatherMap API and stores Json data in a file 
 * 
 */
void send_query_request(FILE *fp, char *file_name, QUERY query) {
    fp = fopen(file_name, "w");
    if (fp == NULL) {
        printf("Could not open file.");
    } 
    else {
        CURL *curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, query.request_url);
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)fp);
 
            CURLcode res = curl_easy_perform(curl);
            if (res != CURLE_OK) {
                printf("Curl_easy_perform: failed");
            }
            /* Always clean up. */ 
            curl_easy_cleanup(curl);
        }
    }
    fclose(fp);
}

/**
 * @brief extract the temp from the file  
 * 
 * @return temperature (in degrees celsius)
 */
void read_file_for_temp();

/**
 * @brief Return kelvin temperature to celsius temperature
 * 
 */
void convert_to_celsius(int temp) {
    temp = temp - 273.15;
}

static size_t write_callback(void *contents, size_t size, size_t nitems, FILE *file) {
    return fwrite(contents, size, nitems, file);
}