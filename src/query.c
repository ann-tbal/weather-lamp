#include "query.h"
/**
 * @brief basic plan:
    - create query string 
        - request city
        - check if valid city
    - HTTP get from url and send info to file
    - read info from file
 * 
 */



void create_query_string() {
    CITY city;

    // get city 
    printf("\nEnter city name: ");
    fgets(city.name, MAX_CITY_LEN, stdin);
    printf("\nObtaining local temperature in %s\n", city.name);

    return;
}



