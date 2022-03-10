#include "conf.h"
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) 
{
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int main(void) 
{
    CURL *curl;
    FILE *fp;
    CURLcode res;
    char outfilename[FILENAME_MAX] = FILE_TO_SAVE;
    curl = curl_easy_init();
    if (curl) {
        fp = fopen(outfilename,"wb");
        curl_easy_setopt(curl, CURLOPT_URL, URL_DOWNLOAD);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        /* always cleanup */
        curl_easy_cleanup(curl);
        fclose(fp);
    }
    return 0;
}
