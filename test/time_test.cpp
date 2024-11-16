#include "../shannan_fano/coding.h"
#include <time.h>
#include <exception>

int main () {
    time_t end_time = time(NULL);
    time_t start_time = time(&start_time);

    try {
        sfcoding* coding = new sfcoding("../index.htm");
        sfcoding_result* result = coding->encode();
        end_time = time(&end_time);
    } catch (std::exception_ptr e) {
        std::cout << "Error Occoured During Compression" << std::endl;
        std::cout << std::endl;
    }

    std::cout << start_time << std::endl;
    std::cout << end_time << std::endl;

    return 0;
}