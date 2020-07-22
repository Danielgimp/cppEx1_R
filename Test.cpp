/**
 * AUTHORS: rinat oz
 *
 * Date: 2020-03
 */
#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;

//test if words:

TEST_CASE("Test replacement of p and b") {
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    CHECK(find(text, "HaPpi") == string("Happi"));
    CHECK(find(text, "HAPpI") == string("Happi"));
    CHECK(find(text, "haPpI") == string("Happi"));
    CHECK(find(text, "HAppI") == string("Happi"));
}

TEST_CASE("Test for smile") {
    string text = "smile AAA BBB CCC DDD";
    CHECK(find(text, "zmile") == string("smile"));
    CHECK(find(text, "SMILE") == string("smile"));
    CHECK(find(text, "Smile") == string("smile"));
    CHECK(find(text, "SMail") == string("smile"));
    CHECK(find(text, "SMAil") == string("smile"));
    CHECK(find(text, "SMAIl") == string("smile"));
    CHECK(find(text, "ZMILE") == string("smile"));
    CHECK(find(text, "ZmILE") == string("smile"));
    CHECK(find(text, "ZmiLE") == string("smile"));
    CHECK(find(text, "ZmilE") == string("smile"));
    CHECK(find(text, "Zmile") == string("smile"));
    CHECK(find(text, "zmiLe") == string("smile"));
    CHECK(find(text, "zmyLe") == string("smile"));
    CHECK(find(text, "zmYLe") == string("smile"));

}

TEST_CASE("Test for apple") {
    string text = "apple AAA BBB CCC DDD EEE bed boy";
    CHECK(find(text, "aplle") == string("apple"));
    CHECK(find(text, "APLLE") == string("apple"));
    CHECK(find(text, "Aplle") == string("apple"));
    CHECK(find(text, "APlle") == string("apple"));
    CHECK(find(text, "APLLe") == string("apple"));
    CHECK(find(text, "APLle") == string("apple"));
    CHECK(find(text, "APlLe") == string("apple"));
    CHECK(find(text, "AFFLE") == string("apple"));
    CHECK(find(text, "AFfLe") == string("apple"));
    CHECK(find(text, "Affple") == string("apple"));
    CHECK(find(text, "Abble") == string("apple"));
    CHECK(find(text, "apble") == string("apple"));
    CHECK(find(text, "APBLE") == string("apple"));
}

TEST_CASE("Test for java") {
    string text = " AAA BBB java DDD";
    CHECK(find(text, "java") == string("java"));
    CHECK(find(text, "Java") == string("java"));
    CHECK(find(text, "JAva") == string("java"));
    CHECK(find(text, "JAVa") == string("java"));
    CHECK(find(text, "JAVA") == string("java"));
    CHECK(find(text, "javA") == string("java"));
    CHECK(find(text, "jaVA") == string("java"));
    CHECK(find(text, "jAVA") == string("java"));
}

TEST_CASE("Test for you") {
    string text = " AAA YOU aRe stupid";
    CHECK(find(text, "you") == string("YOU"));
    CHECK(find(text, "YOU") == string("YOU"));
    CHECK(find(text, "You") == string("YOU"));
    CHECK(find(text, "YOu") == string("YOU"));
    CHECK(find(text, "YOU") == string("YOU"));
    CHECK(find(text, "Iou") == string("YOU"));
    CHECK(find(text, "IOU") == string("YOU"));
    CHECK(find(text, "IoU") == string("YOU"));
    CHECK(find(text, "Ioo") == string("YOU"));
    CHECK(find(text, "IoO") == string("YOU"));
    CHECK(find(text, "IOO") == string("YOU"));
    CHECK(find(text, "iOO") == string("YOU"));
    CHECK(find(text, "iOo") == string("YOU"));
    CHECK(find(text, "iOo") == string("YOU"));
    CHECK(find(text, "yUU") == string("YOU"));
    CHECK(find(text, "YUU") == string("YOU"));
    CHECK(find(text, "YUu") == string("YOU"));
}

TEST_CASE("Test for are") {
    string text = " AAA YOU are stupid";
    CHECK(find(text, "Are") == string("are"));
    CHECK(find(text, "ARe") == string("are"));
    CHECK(find(text, "ARE") == string("are"));
    CHECK(find(text, "ArE") == string("are"));
    CHECK(find(text, "aRE") == string("are"));
    CHECK(find(text, "aRe") == string("are"));
    CHECK(find(text, "arE") == string("are"));
    CHECK(find(text, "are") == string("are"));
}

TEST_CASE("Test replacement of b and f and p") {
    string text = "practice makes perfect";
    CHECK(find(text, "practice") == string("practice"));
    CHECK(find(text, "fractice") == string("practice"));
    CHECK(find(text, "bractice") == string("practice"));
    CHECK(find(text, "perpect") == string("perfect"));
    CHECK(find(text, "perfect") == string("perfect"));
    CHECK(find(text, "perbect") == string("perfect"));
    CHECK(find(text, "ferfect") == string("perfect"));
    CHECK(find(text, "ferpect") == string("perfect"));
    CHECK(find(text, "ferbect") == string("perfect"));
    CHECK(find(text, "berbect") == string("perfect"));
    CHECK(find(text, "berpect") == string("perfect"));
    CHECK(find(text, "berfect") == string("perfect"));
}

TEST_CASE("Test replacement of c and k") {
    string text = "cupkaces made of chokclate";
    CHECK(find(text, "CupCaKes") == string("cupkaces"));
    CHECK(find(text, "CUPKACES") == string("cupkaces"));
    CHECK(find(text, "khocklate") == string("chokclate"));
    CHECK(find(text, "CHokKlate") == string("chokclate"));
    CHECK(find(text, "CUPKACES") != string("Cupkaces"));
    CHECK(find(text, "khocklate") != string("chokclats"));
}

TEST_CASE("Test replacement of d and t") {
    string text = "the database is shutdown";
    CHECK(find(text, "the") == string("the"));
    CHECK(find(text, "dhe") == string("the"));
    CHECK(find(text, "database") == string("database"));
    CHECK(find(text, "tatabase") == string("database"));
    CHECK(find(text, "tadabase") == string("database"));
    CHECK(find(text, "dadabase") == string("database"));
    CHECK(find(text, "shutdown") == string("shutdown"));
    CHECK(find(text, "shuttown") == string("shutdown"));
    CHECK(find(text, "shuddown") == string("shutdown"));
    CHECK(find(text, "shudtown") == string("shutdown"));

}

TEST_CASE("Test replacement of i and y") {
    string text = " everything you can imagine is real";
    CHECK(find(text, "imagine") == string("imagine "));
    CHECK(find(text, "ymagine") == string("imagine "));
    CHECK(find(text, "imagyne") == string("imagine "));
    CHECK(find(text, "ymagyne") == string("imagine"));
    CHECK(find(text, "everything") == string("everything"));
    CHECK(find(text, "everithing") == string("everything"));
    CHECK(find(text, "everythyng") == string("everything"));
    CHECK(find(text, "everithyng") == string("everything"));
    CHECK(find(text, "is") == string("is"));
    CHECK(find(text, "ys") == string("is"));
    CHECK(find(text, " you") == string("you"));
    CHECK(find(text, " iou") == string("you"));
}
