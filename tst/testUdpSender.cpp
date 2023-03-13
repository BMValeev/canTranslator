#include "../src/udpSender.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(testUdpSender)
{
        udpSender* obj;
        obj = new udpSender("255.255.255.255","1001");
        BOOST_REQUIRE_EQUAL(obj->getAddress(),"255.255.255.255");
        BOOST_REQUIRE_EQUAL(obj->getPort(),"1001");
}


