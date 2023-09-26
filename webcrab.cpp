// webcrab.cpp: 定义应用程序的入口点。
//

#include "webcrab.h"

#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"
//#include <string_view>
#include <format>

//g++ -std=c++20 -o crab crab.cpp -lssl -lcrypto -pthread
int main()
{
    // Set download file path
    std::string download_file_name = "RADStudio_29.0.50031.5296.exe";
    // Start downloading file
    std::string get_url = "/releases/studio/Beta/Yukon/RADStudio_29.0.50031.5296.exe";
    std::ofstream ofs(download_file_name, std::ios::binary);
    httplib::Client cli("http://altd.embarcadero.com");
    auto download_res = cli.Get(get_url.c_str(), [&](const char* data, size_t data_length) {
        //std::string_view view(data, data_length);
        //ofs << view;
        ofs.write((char*)data, data_length);
        return true;
        }, (httplib::Progress)[](uint64_t len, uint64_t total) {
            // printf("%lld / %lld bytes => %d%% complete\n", len, total, (int)(len*100/total));
            std::cout << std::format("{} / {} bytes => {}% complete\n", len, total, (int)(len * 100 / total));
            return true;
            });
    if (download_res) {
        std::cout << "download_res status ==== " << download_res->status << std::endl;
    }
    ofs.close();
	return 0;
}
