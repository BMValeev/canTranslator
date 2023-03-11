#include "../src/udpSender.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(testUdpSender)
        {
        udpSender* obj;
        BOOST_CHECK_NO_THROW(obj = new udpSender());
        BOOST_CHECK_NO_THROW(delete obj);
        BOOST_CHECK_NO_THROW(obj = new udpSender("255.255.255.255","1001"));
        BOOST_CHECK__THROW(obj = new udpSender("255.255.255.255","1001"));

        BOOST_CHECK_THROW(mainApp->sFindElement("v4l2src"),std::logic_error);
        BOOST_CHECK_THROW(mainApp->sFindElement("h264parse"),std::logic_error);
        BOOST_CHECK_NO_THROW(mainApp->sFindElement("pipeline"));
        BOOST_CHECK_NO_THROW(mainApp->sFindElement("imxv4l2videosrc"));
        BOOST_CHECK_NO_THROW(mainApp->sFindElement("queue"));
        BOOST_CHECK_NO_THROW(mainApp->sFindElement("capsfilter"));
        BOOST_CHECK_NO_THROW(mainApp->sFindElement("tee"));
        }

#endif
