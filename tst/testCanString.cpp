//
// Created by eleps on 13.03.2023.
//

#include "src/canString.h"
#include <boost/test/unit_test.hpp>
// (1970-01-01 05:36:04.885558)  can0  1E0007F6   [8]  15 FF FF FF FF FF FF FF   '........'
// (1970-01-01 05:36:04.206865)  can0  704   [1]  7F                        '.'
// (1970-01-01 05:36:04.215653)  can0  701   [1]  7F                        '.'
// (1970-01-01 05:36:04.216128)  can0  707   [1]  7F                        '.'
BOOST_AUTO_TEST_CASE(testCanString)
{
    canString* obj;
    obj = new canString(" (1970-01-01 05:36:04.885558)  can0  1E0007F6   [8]  15 FF FF FF FF FF FF FF   '........'");
    BOOST_REQUIRE_EQUAL(obj->isCorrect(),true);
    BOOST_REQUIRE_EQUAL(obj->getAddress(),"0x07");
    delete obj;
    obj = new canString(" (1970-01-01 05:36:04.206865)  can0  704   [1]  7F                        '.'");
    BOOST_REQUIRE_EQUAL(obj->isCorrect(),true);
    BOOST_REQUIRE_EQUAL(obj->getAddress(),"0x04");
    delete obj;
    obj = new canString(" (1970-01-01 05:36:04.206865)  can0  70w   [1]  7F                        '.'");
    BOOST_REQUIRE_EQUAL(obj->isCorrect(),false);
}


