#include "vipuser_common.h"

#include <sys/time.h>
#include <random>

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

    std::mt19937 g1 (seed1); // mt19937 is a standard mersenne_twister_engine
    uint32_t u32Random = g1();
    std::cout << "A time seed produced: " << u32Random << std::endl;

    std::mt19937_64 g2 (seed1);
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