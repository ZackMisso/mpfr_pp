#include <iostream>
#include <vector>
#include "real.h"

bool initTest()
{
    real one = 1;
    real two = 2.f;
    real three = 3.0;
    real four = "4.0";

    std::string five_s = "5.0";
    real five = five_s;

    int one_i = 1;
    int two_i = 2;
    int three_i = 3;
    int four_i = 4;
    int five_i = 5;

    if (one == one_i &&
        two == two_i &&
        three == three_i &&
        four == four_i &&
        five == five_i)
    {
        return true;
    }

    return false;
}

bool addTest()
{
    int one = 1;
    float two = 2.f;
    double three = 3.0;
    std::string four = "4.0";
    long five = 5u;

    real val = "0";

    val += one;
    val = val + one;
    val += two;
    val = val + two;
    val += three;
    val = val + three;
    val += four;
    val = val + four;
    val += five;
    val = val + five;

    int answer = 2*(1+2+3+4+5);

    if (val == answer) return true;

    return false;
}

bool subTest()
{
    real val = 2*(1+2+3+4+5);

    float one = 1.f;
    int two = 2;
    long three = 3u;
    double four = 4.0;
    std::string five = "05.00";

    val -= one;
    val = val - one;
    val -= two;
    val = val - two;
    val -= three;
    val = val - three;
    val -= four;
    val = val - four;
    val -= five;
    val = val - five;

    if (val == "0.0") return true;

    return false;
}

bool mulTest()
{
    long answer = 1*1*2*2*3*3*4*4*5*5;

    std::string one = "01.00";
    double two = 2.0;
    int three = 3;
    long four = 4u;
    float five = 5.f;

    real val = 1.f;

    val *= one;
    val = val * one;
    val *= two;
    val = val * two;
    val *= three;
    val = val * three;
    val *= four;
    val = val * four;
    val *= five;
    val = val * five;

    if (val == answer) return true;

    return false;
}

bool divTest()
{
    real val = 1.0*1.0*2.0*2.0*3.0*3.0*4.0*4.0*5.0*5.0;
    // val.text("woop");
    // std::cout << "true val" << std::endl;
    // std::cout << 1.0*1.0*2.0*2.0*3.0*3.0*4.0*4.0*5.0*5.0 << std::endl;

    double one = 1.0;
    std::string two = "002.000";
    long three = 3u;
    float four = 4.f;
    int five = 5;

    val /= one;
    // val.text("one 1");
    val = val / one;
    // val.text("one 2");
    val /= two;
    // val.text("two 1");
    val = val / two;
    // val.text("two 2");
    val /= three;
    // val.text("three 1");
    val = val / three;
    // val.text("three 2");
    val /= four;
    // val.text("four 1");
    val = val / four;
    // val.text("four 2");
    val /= five;
    // val.text("five 1");
    val = val / five;
    // val.text("five 2");

    // val.text("woop");

    if (val == 1) return true;

    return false;
}

bool test()
{
    if (!initTest()) {
        std::cout << "Failed Init Test" << std::endl;
        return false;
    }
    if (!addTest()) {
        std::cout << "Failed Add Test" << std::endl;
        return false;
    }
    if (!subTest()) {
        std::cout << "Failed Sub Test" << std::endl;
        return false;
    }
    if (!mulTest()) {
        std::cout << "Failed Mul Test" << std::endl;
        return false;
    }
    if (!divTest()) {
        std::cout << "Failed Div Test" << std::endl;
        return false;
    }

    return true;
}

int main(int argc, char* argv[])
{
    bool pass = test();
    if (pass) std::cout << "All Tests Passed" << std::endl;

    // test();
    // std::cout << "Hello World" << std::endl;
    //
    // std::vector<real> vec = std::vector<real>();
    //
    // int t = 5;
    // real val;
    // val = t;
    // std::cout << "who" << std::endl;
    // // val.test = 5;
    // std::cout << "whop" << std::endl;
    // vec.push_back(val);
    // std::cout << "huh" << std::endl;
    // double tmp = vec[0];
    // // double tmp = val;
    // std::cout << "plop" << std::endl;
    //
    // std::cout << "TMP: " << tmp << std::endl;
    // t = 500;
    // vec[0] = t;
    // tmp = vec[0];
    // std::cout << "TMP: " << tmp << std::endl;
    // TODO: fix errors

    // TODO
    return 0;
}
