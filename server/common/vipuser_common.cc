#include "vipuser_common.h"

#include <sys/time.h>
#include <random>
#include <sstream>
#include <iomanip>
#include <chrono>

#include "boost/uuid/uuid.hpp"
#include "boost/uuid/uuid_io.hpp"
#include "boost/uuid/uuid_generators.hpp"

// using namespace vipuser;

uint64_t getCurrentTimeMills() {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    return tp.tv_sec * 1000 + tp.tv_usec / 1000; 
}

uint64_t genRandom() {
    // obtain a seed from the system clock:
    unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();

    // 32 bit
    // std::mt19937 g1(seed1); // mt19937 is a standard mersenne_twister_engine
    // uint32_t u32Random = g1();
    // std::cout << "A time seed produced: " << u32Random << std::endl;

    std::mt19937_64 g2(seed1);
    uint64_t u64Random = g2();
    return u64Random;
}

std::string generateUuid()
{
//    boost::uuids::uuid uuid = boost::uuids::random_generator()();
    boost::uuids::random_generator gen;
    boost::uuids::uuid uuid = gen();
    return boost::uuids::to_string(uuid);
}


std::string toHex(void *const data, const size_t dataLength)
{
    unsigned char     *byteData = reinterpret_cast<unsigned char*>(data);
    std::stringstream hexStringStream;
    
    hexStringStream << std::hex << std::setfill('0');
    for(size_t index = 0; index < dataLength; ++index)
        hexStringStream << std::setw(2) << static_cast<int>(byteData[index]);
    return hexStringStream.str();
}


size_t fromHex(const std::string &in, void *const data)
{
    size_t          length    = in.length();
    unsigned char   *byteData = reinterpret_cast<unsigned char*>(data);
    
    size_t dataIndex = 0;
    std::stringstream hexStringStream; hexStringStream >> std::hex;
    for(size_t strIndex = 0; strIndex < length; ++dataIndex)
    {
        // Read out and convert the string two characters at a time
        const char tmpStr[3] = { in[strIndex++], in[strIndex++], 0 };

        // Reset and fill the string stream
        hexStringStream.clear();
        hexStringStream.str(tmpStr);

        // Do the conversion
        int tmpValue = 0;
        hexStringStream >> tmpValue;
        byteData[dataIndex] = static_cast<unsigned char>(tmpValue);
    }
    return dataIndex;
}