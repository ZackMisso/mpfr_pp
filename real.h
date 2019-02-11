// The below code is authored by Zackary Misso
// It is free to use as long as credit is given for its use

#include <mpfr.h>
#include <stdio.h>
#include <string>

namespace mpfr_pp
{

#define REAL_PRECISION 512

static void mpfr_from_str(const std::string str, mpfr_t& result)
{
    mpfr_init2(result, REAL_PRECISION);
    mpfr_set_str(result, str.c_str(), /*base*/10, MPFR_RNDN);
}

static void mpfr_from_str(const char* str, mpfr_t& result)
{
    mpfr_init2(result, REAL_PRECISION);
    mpfr_set_str(result, str, /*base*/10, MPFR_RNDN);
}

struct real
{
protected:
    mpfr_t m_val;

    void text(std::string message, const mpfr_t& val) const
    {
        std::cout << message << std::endl;
        mpfr_out_str (stdout, 10, 0, val, MPFR_RNDD);
        std::cout << std::endl;
    }

public:
    void text(std::string message) const
    {
        text(message, m_val);
    }

    real()
    {
        mpfr_init2(m_val, REAL_PRECISION);
    }

    real(const real& val)
    {
        mpfr_init2(m_val, REAL_PRECISION);
        mpfr_set(m_val, val.m_val, MPFR_RNDN);
    }

    real(const long double& val)
    {
        mpfr_init2(m_val, REAL_PRECISION);
        mpfr_set_ld(m_val, val, MPFR_RNDN);
    }

    real(const double& val)
    {
        mpfr_init2(m_val, REAL_PRECISION);
        mpfr_set_d(m_val, val, MPFR_RNDN);
    }

    real(const float& val)
    {
        mpfr_init2(m_val, REAL_PRECISION);
        mpfr_set_flt(m_val, val, MPFR_RNDN);
    }

    real(const unsigned long& val)
    {
        mpfr_init2(m_val, REAL_PRECISION);
        mpfr_set_ui(m_val, val, MPFR_RNDN);
    }

    real(const long& val)
    {
        mpfr_init2(m_val, REAL_PRECISION);
        mpfr_set_si(m_val, val, MPFR_RNDN);
    }

    real(const unsigned int& val)
    {
        mpfr_init2(m_val, REAL_PRECISION);
        mpfr_set_ui(m_val, val, MPFR_RNDN);
    }

    real(const int& val)
    {
        mpfr_init2(m_val, REAL_PRECISION);
        mpfr_set_si(m_val, val, MPFR_RNDN);
    }

    real(std::string val)
    {
        mpfr_init2(m_val, REAL_PRECISION);
        mpfr_set_str(m_val, val.c_str(), /*base*/10, MPFR_RNDN);
    }

    real(const char* val)
    {
        mpfr_init2(m_val, REAL_PRECISION);
        mpfr_set_str(m_val, val, /*base*/10, MPFR_RNDN);
    }

    ~real()
    {
        mpfr_clear(m_val);
    }

    // operators
    void operator++()
    {
        mpfr_t one;
        mpfr_from_str("1.0", one);
        mpfr_add(m_val, m_val, one, MPFR_RNDN);
        mpfr_clear(one);
    }

    void operator--()
    {
        mpfr_t one;
        mpfr_from_str("1.0", one);
        mpfr_sub(m_val, m_val, one, MPFR_RNDN);
        mpfr_clear(one);
    }

    real operator-() const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_d(tmp, -1.0, MPFR_RNDN);
        mpfr_mul(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }

    // supported operations with:
    // real
    // long double
    // double
    // float
    // unsigned long
    // long
    // unsigned int
    // int
    // string

    real operator+(const real& other) const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_add(tmp, other.m_val, m_val, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator+(const long double& other) const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ld(tmp, other, MPFR_RNDN);
        mpfr_add(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator+(const double& other) const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_d(tmp, other, MPFR_RNDN);
        mpfr_add(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator+(const float& other) const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_flt(tmp, other, MPFR_RNDN);
        mpfr_add(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator+(const unsigned long& other) const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, other, MPFR_RNDN);
        mpfr_add(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator+(const long& other) const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_si(tmp, other, MPFR_RNDN);
        mpfr_add(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator+(const unsigned int& other) const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, (unsigned long)other, MPFR_RNDN);
        mpfr_add(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator+(const int& other) const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, (long)other, MPFR_RNDN);
        mpfr_add(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator+(const std::string& other) const
    {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        mpfr_add(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator+(const char* other) const
    {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        mpfr_add(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }

    real operator-(const real& other) const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_sub(tmp, m_val, other.m_val, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator-(const long double& other) const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ld(tmp, other, MPFR_RNDN);
        mpfr_sub(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator-(const double& other) const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_d(tmp, other, MPFR_RNDN);
        mpfr_sub(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator-(const float& other) const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_flt(tmp, other, MPFR_RNDN);
        mpfr_sub(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator-(const unsigned long& other) const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, other, MPFR_RNDN);
        mpfr_sub(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator-(const long& other) const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_si(tmp, other, MPFR_RNDN);
        mpfr_sub(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator-(const unsigned int& other) const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, (unsigned long)other, MPFR_RNDN);
        mpfr_sub(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator-(const int& other) const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, (long)other, MPFR_RNDN);
        mpfr_sub(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator-(const std::string& other) const
    {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        mpfr_sub(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator-(const char* other) const
    {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        mpfr_sub(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator*(const real& other) const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_mul(tmp, m_val, other.m_val, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator*(const long double& other) const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ld(tmp, other, MPFR_RNDN);
        mpfr_mul(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator*(const double& other) const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_d(tmp, other, MPFR_RNDN);
        mpfr_mul(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator*(const float& other) const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_flt(tmp, other, MPFR_RNDN);
        mpfr_mul(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator*(const unsigned long& other) const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, other, MPFR_RNDN);
        mpfr_mul(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator*(const long& other) const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_si(tmp, other, MPFR_RNDN);
        mpfr_mul(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator*(const unsigned int& other) const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, (unsigned long)other, MPFR_RNDN);
        mpfr_mul(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator*(const int& other) const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, (long)other, MPFR_RNDN);
        mpfr_mul(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator*(const std::string& other) const
    {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        mpfr_mul(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator*(const char* other) const
    {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        mpfr_mul(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }

    real operator/(const real& other) const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_div(tmp, m_val, other.m_val, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator/(const long double& other) const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ld(tmp, other, MPFR_RNDN);
        mpfr_div(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator/(const double& other) const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_d(tmp, other, MPFR_RNDN);
        mpfr_div(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator/(const float& other) const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_flt(tmp, other, MPFR_RNDN);
        mpfr_div(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator/(const unsigned long& other) const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, other, MPFR_RNDN);
        mpfr_div(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator/(const long& other) const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_si(tmp, other, MPFR_RNDN);
        mpfr_div(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator/(const unsigned int& other) const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, (unsigned long)other, MPFR_RNDN);
        mpfr_div(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator/(const int& other) const
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, (long)other, MPFR_RNDN);
        mpfr_div(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator/(const std::string& other) const
    {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        mpfr_div(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator/(const char* other) const
    {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        mpfr_div(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }

    real& operator=(const real& other)
    {
        mpfr_set(m_val, other.m_val, MPFR_RNDN);
        return *this;
    }
    real& operator=(const long double& other)
    {
        mpfr_set_ld(m_val, other, MPFR_RNDN);
        return *this;
    }
    real& operator=(const double& other)
    {
        mpfr_set_d(m_val, other, MPFR_RNDN);
        return *this;
    }
    real& operator=(const float& other)
    {
        mpfr_set_flt(m_val, other, MPFR_RNDN);
        return *this;
    }
    real& operator=(const unsigned long& other)
    {
        mpfr_set_ui(m_val, other, MPFR_RNDN);
        return *this;
    }
    real& operator=(const long& other)
    {
        mpfr_set_si(m_val, other, MPFR_RNDN);
        return *this;
    }
    real& operator=(const unsigned int& other)
    {
        mpfr_set_ui(m_val, other, MPFR_RNDN);
        return *this;
    }
    real& operator=(const int& other)
    {
        mpfr_set_ui(m_val, other, MPFR_RNDN);
        return *this;
    }
    real& operator=(const std::string& other)
    {
        mpfr_set_str(m_val, other.c_str(), /*base*/10, MPFR_RNDN);
        return *this;
    }
    real& operator=(const char* other)
    {
        mpfr_set_str(m_val, other, /*base*/10, MPFR_RNDN);
        return *this;
    }

    void operator+=(const real& other)
    {
        mpfr_add(m_val, m_val, other.m_val, MPFR_RNDN);
    }
    void operator+=(const long double& other)
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ld(tmp, other, MPFR_RNDN);
        mpfr_add(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator+=(const double& other)
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_d(tmp, other, MPFR_RNDN);
        mpfr_add(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator+=(const float& other)
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_flt(tmp, other, MPFR_RNDN);
        mpfr_add(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator+=(const unsigned long& other)
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, other, MPFR_RNDN);
        mpfr_add(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator+=(const long& other)
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_si(tmp, other, MPFR_RNDN);
        mpfr_add(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator+=(const unsigned int& other)
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, other, MPFR_RNDN);
        mpfr_add(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator+=(const int& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, other, MPFR_RNDN);
        mpfr_add(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator+=(const std::string& other)
    {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        mpfr_add(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator+=(const char* other)
    {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        mpfr_add(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }

    void operator-=(const real& other)
    {
        mpfr_sub(m_val, m_val, other.m_val, MPFR_RNDN);
    }
    void operator-=(const long double& other)
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ld(tmp, other, MPFR_RNDN);
        mpfr_sub(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator-=(const double& other)
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_d(tmp, other, MPFR_RNDN);
        mpfr_sub(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator-=(const float& other)
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_flt(tmp, other, MPFR_RNDN);
        mpfr_sub(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator-=(const unsigned long& other)
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, other, MPFR_RNDN);
        mpfr_sub(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator-=(const long& other)
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_si(tmp, other, MPFR_RNDN);
        mpfr_sub(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator-=(const unsigned int& other)
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, other, MPFR_RNDN);
        mpfr_sub(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator-=(const int& other)
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, other, MPFR_RNDN);
        mpfr_sub(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator-=(const std::string& other)
    {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        mpfr_sub(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator-=(const char* other)
    {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        mpfr_sub(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }

    void operator*=(const real& other)
    {
        mpfr_mul(m_val, m_val, other.m_val, MPFR_RNDN);
    }
    void operator*=(const long double& other)
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ld(tmp, other, MPFR_RNDN);
        mpfr_mul(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator*=(const double& other)
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_d(tmp, other, MPFR_RNDN);
        mpfr_mul(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator*=(const float& other)
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_flt(tmp, other, MPFR_RNDN);
        mpfr_mul(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator*=(const unsigned long& other)
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, other, MPFR_RNDN);
        mpfr_mul(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator*=(const long& other)
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_si(tmp, other, MPFR_RNDN);
        mpfr_mul(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator*=(const unsigned int& other)
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, other, MPFR_RNDN);
        mpfr_mul(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator*=(const int& other)
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, other, MPFR_RNDN);
        mpfr_mul(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator*=(const std::string& other)
    {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        mpfr_mul(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator*=(const char* other)
    {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        mpfr_mul(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }

    void operator/=(const real& other)
    {
        mpfr_div(m_val, m_val, other.m_val, MPFR_RNDN);
    }
    void operator/=(const long double& other)
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ld(tmp, other, MPFR_RNDN);
        mpfr_div(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator/=(const double& other)
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_d(tmp, other, MPFR_RNDN);
        mpfr_div(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator/=(const float& other)
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_flt(tmp, other, MPFR_RNDN);
        mpfr_div(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator/=(const unsigned long& other)
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, other, MPFR_RNDN);
        mpfr_div(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator/=(const long& other)
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_si(tmp, other, MPFR_RNDN);
        mpfr_div(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator/=(const unsigned int& other)
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, other, MPFR_RNDN);
        mpfr_div(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator/=(const int& other)
    {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, other, MPFR_RNDN);
        mpfr_div(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator/=(const std::string& other)
    {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        mpfr_div(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator/=(const char* other)
    {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        mpfr_div(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }

    bool operator==(const real& other) const
    {
        int compare = mpfr_cmp(m_val, other.m_val);
        return compare == 0;
    }
    bool operator==(const long double& other) const
    {
        int compare = mpfr_cmp_ld(m_val, other);
        return compare == 0;
    }
    bool operator==(const double& other) const
    {
        int compare = mpfr_cmp_d(m_val, other);
        return compare == 0;
    }
    bool operator==(const float& other) const
    {
        int compare = mpfr_cmp_d(m_val, (double)other);
        return compare == 0;
    }
    bool operator==(const unsigned long& other) const
    {
        int compare = mpfr_cmp_ui(m_val, other);
        return compare == 0;
    }
    bool operator==(const long& other) const
    {
        int compare = mpfr_cmp_si(m_val, other);
        return compare == 0;
    }
    bool operator==(const unsigned int& other) const
    {
        int compare = mpfr_cmp_ui(m_val, other);
        return compare == 0;
    }
    bool operator==(const int& other) const
    {
        int compare = mpfr_cmp_si(m_val, other);
        return compare == 0;
    }
    bool operator==(const std::string& other) const
    {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        int compare = mpfr_cmp(m_val, tmp);
        mpfr_clear(tmp);
        return compare == 0;
    }
    bool operator==(const char* other) const
    {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        int compare = mpfr_cmp(m_val, tmp);
        mpfr_clear(tmp);
        return compare == 0;
    }

    bool operator!=(const real& other) const
    {
        int compare = mpfr_cmp(m_val, other.m_val);
        return compare != 0;
    }
    bool operator!=(const long double& other) const
    {
        int compare = mpfr_cmp_ld(m_val, other);
        return compare != 0;
    }
    bool operator!=(const double& other) const
    {
        int compare = mpfr_cmp_d(m_val, other);
        return compare != 0;
    }
    bool operator!=(const float& other) const
    {
        int compare = mpfr_cmp_d(m_val, (double)other);
        return compare != 0;
    }
    bool operator!=(const unsigned long& other) const
    {
        int compare = mpfr_cmp_ui(m_val, other);
        return compare != 0;
    }
    bool operator!=(const long& other) const
    {
        int compare = mpfr_cmp_si(m_val, other);
        return compare != 0;
    }
    bool operator!=(const unsigned int& other) const
    {
        int compare = mpfr_cmp_ui(m_val, other);
        return compare != 0;
    }
    bool operator!=(const int& other) const
    {
        int compare = mpfr_cmp_si(m_val, other);
        return compare != 0;
    }
    bool operator!=(const std::string& other) const
    {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        int compare = mpfr_cmp(m_val, tmp);
        mpfr_clear(tmp);
        return compare != 0;
    }
    bool operator!=(const char* other) const
    {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        int compare = mpfr_cmp(m_val, tmp);
        mpfr_clear(tmp);
        return compare != 0;
    }

    bool operator<(const real& other) const
    {
        int compare = mpfr_cmp(m_val, other.m_val);
        return compare < 0;
    }
    bool operator<(const long double& other) const
    {
        int compare = mpfr_cmp_ld(m_val, other);
        return compare < 0;
    }
    bool operator<(const double& other) const
    {
        int compare = mpfr_cmp_d(m_val, other);
        return compare < 0;
    }
    bool operator<(const float& other) const
    {
        int compare = mpfr_cmp_d(m_val, (double)other);
        return compare < 0;
    }
    bool operator<(const unsigned long& other) const
    {
        int compare = mpfr_cmp_ui(m_val, other);
        return compare < 0;
    }
    bool operator<(const long& other) const
    {
        int compare = mpfr_cmp_si(m_val, other);
        return compare < 0;
    }
    bool operator<(const unsigned int& other) const
    {
        int compare = mpfr_cmp_ui(m_val, other);
        return compare < 0;
    }
    bool operator<(const int& other) const
    {
        int compare = mpfr_cmp_si(m_val, other);
        return compare < 0;
    }
    bool operator<(const std::string& other) const
    {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        int compare = mpfr_cmp(m_val, tmp);
        mpfr_clear(tmp);
        return compare < 0;
    }
    bool operator<(const char* other) const
    {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        int compare = mpfr_cmp(m_val, tmp);
        mpfr_clear(tmp);
        return compare < 0;
    }

    bool operator<=(const real& other) const
    {
        int compare = mpfr_cmp(m_val, other.m_val);
        return compare <= 0;
    }
    bool operator<=(const long double& other) const
    {
        int compare = mpfr_cmp_ld(m_val, other);
        return compare <= 0;
    }
    bool operator<=(const double& other) const
    {
        int compare = mpfr_cmp_d(m_val, other);
        return compare <= 0;
    }
    bool operator<=(const float& other) const
    {
        int compare = mpfr_cmp_d(m_val, (double)other);
        return compare <= 0;
    }
    bool operator<=(const unsigned long& other) const
    {
        int compare = mpfr_cmp_ui(m_val, other);
        return compare <= 0;
    }
    bool operator<=(const long& other) const
    {
        int compare = mpfr_cmp_si(m_val, other);
        return compare <= 0;
    }
    bool operator<=(const unsigned int& other) const
    {
        int compare = mpfr_cmp_ui(m_val, other);
        return compare <= 0;
    }
    bool operator<=(const int& other) const
    {
        int compare = mpfr_cmp_si(m_val, other);
        return compare <= 0;
    }
    bool operator<=(const std::string& other) const
    {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        int compare = mpfr_cmp(m_val, tmp);
        mpfr_clear(tmp);
        return compare <= 0;
    }
    bool operator<=(const char* other) const
    {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        int compare = mpfr_cmp(m_val, tmp);
        mpfr_clear(tmp);
        return compare <= 0;
    }

    bool operator>(const real& other) const
    {
        int compare = mpfr_cmp(m_val, other.m_val);
        return compare > 0;
    }
    bool operator>(const long double& other) const
    {
        int compare = mpfr_cmp_ld(m_val, other);
        return compare > 0;
    }
    bool operator>(const double& other) const
    {
        int compare = mpfr_cmp_d(m_val, other);
        return compare > 0;
    }
    bool operator>(const float& other) const
    {
        int compare = mpfr_cmp_d(m_val, (double)other);
        return compare > 0;
    }
    bool operator>(const unsigned long& other) const
    {
        int compare = mpfr_cmp_ui(m_val, other);
        return compare > 0;
    }
    bool operator>(const long& other) const
    {
        int compare = mpfr_cmp_si(m_val, other);
        return compare > 0;
    }
    bool operator>(const unsigned int& other) const
    {
        int compare = mpfr_cmp_ui(m_val, other);
        return compare > 0;
    }
    bool operator>(const int& other) const
    {
        int compare = mpfr_cmp_si(m_val, other);
        return compare > 0;
    }
    bool operator>(const std::string& other) const
    {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        int compare = mpfr_cmp(m_val, tmp);
        mpfr_clear(tmp);
        return compare > 0;
    }
    bool operator>(const char* other) const
    {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        int compare = mpfr_cmp(m_val, tmp);
        mpfr_clear(tmp);
        return compare > 0;
    }

    bool operator>=(const real& other) const
    {
        int compare = mpfr_cmp(m_val, other.m_val);
        return compare >= 0;
    }
    bool operator>=(const long double& other) const
    {
        int compare = mpfr_cmp_ld(m_val, other);
        return compare >= 0;
    }
    bool operator>=(const double& other) const
    {
        int compare = mpfr_cmp_d(m_val, other);
        return compare >= 0;
    }
    bool operator>=(const float& other) const
    {
        int compare = mpfr_cmp_d(m_val, (double)other);
        return compare >= 0;
    }
    bool operator>=(const unsigned long& other) const
    {
        int compare = mpfr_cmp_ui(m_val, other);
        return compare >= 0;
    }
    bool operator>=(const long& other) const
    {
        int compare = mpfr_cmp_si(m_val, other);
        return compare >= 0;
    }
    bool operator>=(const unsigned int& other) const
    {
        int compare = mpfr_cmp_ui(m_val, other);
        return compare >= 0;
    }
    bool operator>=(const int& other) const
    {
        int compare = mpfr_cmp_si(m_val, other);
        return compare >= 0;
    }
    bool operator>=(const std::string& other) const
    {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        int compare = mpfr_cmp(m_val, tmp);
        mpfr_clear(tmp);
        return compare >= 0;
    }
    bool operator>=(const char* other) const
    {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        int compare = mpfr_cmp(m_val, tmp);
        mpfr_clear(tmp);
        return compare >= 0;
    }

    explicit operator long double() const
    {
        return mpfr_get_ld(m_val, MPFR_RNDN);
    }
    explicit operator double() const
    {
        return mpfr_get_d(m_val, MPFR_RNDN);
    }
    explicit operator float() const
    {
        return mpfr_get_flt(m_val, MPFR_RNDN);
    }
    explicit operator unsigned long() const
    {
        return mpfr_get_ui(m_val, MPFR_RNDN);
    }
    explicit operator long() const
    {
        return mpfr_get_si(m_val, MPFR_RNDN);
    }
    explicit operator unsigned int() const
    {
        return (unsigned int)mpfr_get_ui(m_val, MPFR_RNDN);
    }
    explicit operator int() const
    {
        return (int)mpfr_get_si(m_val, MPFR_RNDN);
    }

    // friend methods
    // friend real operator+(const real& one, const real& two);
    // friend real operator+(const real& one, const long double& two);
    // friend real operator+(const long double& two, const real& one);
    // friend real operator+(const real& one, const double& two);
    // friend real operator+(const double& two, const real& one);
    // friend real operator+(const real& one, const float& two);
    // friend real operator+(const float& two, const real& one);
    // friend real operator+(const real& one, const unsigned long& two);
    // friend real operator+(const unsigned long& two, const real& one);
    // friend real operator+(const real& one, const long& two);
    // friend real operator+(const long& two, const real& one);
    // friend real operator+(const real& one, const unsigned int& two);
    // friend real operator+(const unsigned int& two, const real& one);
    // friend real operator+(const real& one, const int& two);
    // friend real operator+(const int& two, const real& one);
    // friend real operator+(const real& one, const std::string& two);
    // friend real operator+(const std::string& two, const real& one);
    //
    // friend real operator-(const real& one, const real& two);
    // friend real operator-(const real& one, const long double& two);
    // friend real operator-(const long double& two, const real& one);
    // friend real operator-(const real& one, const double& two);
    // friend real operator-(const double& two, const real& one);
    // friend real operator-(const real& one, const float& two);
    // friend real operator-(const float& two, const real& one);
    // friend real operator-(const real& one, const unsigned long& two);
    // friend real operator-(const unsigned long& two, const real& one);
    // friend real operator-(const real& one, const long& two);
    // friend real operator-(const long& two, const real& one);
    // friend real operator-(const real& one, const unsigned int& two);
    // friend real operator-(const unsigned int& two, const real& one);
    // friend real operator-(const real& one, const int& two);
    // friend real operator-(const int& two, const real& one);
    // friend real operator-(const real& one, const std::string& two);
    // friend real operator-(const std::string& two, const real& one);
    //
    // friend real operator*(const real& one, const real& two);
    // friend real operator*(const real& one, const long double& two);
    // friend real operator*(const long double& two, const real& one);
    // friend real operator*(const real& one, const double& two);
    // friend real operator*(const double& two, const real& one);
    // friend real operator*(const real& one, const float& two);
    // friend real operator*(const float& two, const real& one);
    // friend real operator*(const real& one, const unsigned long& two);
    // friend real operator*(const unsigned long& two, const real& one);
    // friend real operator*(const real& one, const long& two);
    // friend real operator*(const long& two, const real& one);
    // friend real operator*(const real& one, const unsigned int& two);
    // friend real operator*(const unsigned int& two, const real& one);
    // friend real operator*(const real& one, const int& two);
    // friend real operator*(const int& two, const real& one);
    // friend real operator*(const real& one, const std::string& two);
    // friend real operator*(const std::string& two, const real& one);
    //
    // friend real operator/(const real& one, const real& two);
    // friend real operator/(const real& one, const long double& two);
    // friend real operator/(const long double& two, const real& one);
    // friend real operator/(const real& one, const double& two);
    // friend real operator/(const double& two, const real& one);
    // friend real operator/(const real& one, const float& two);
    // friend real operator/(const float& two, const real& one);
    // friend real operator/(const real& one, const unsigned long& two);
    // friend real operator/(const unsigned long& two, const real& one);
    // friend real operator/(const real& one, const long& two);
    // friend real operator/(const long& two, const real& one);
    // friend real operator/(const real& one, const unsigned int& two);
    // friend real operator/(const unsigned int& two, const real& one);
    // friend real operator/(const real& one, const int& two);
    // friend real operator/(const int& two, const real& one);
    // friend real operator/(const real& one, const std::string& two);
    // friend real operator/(const std::string& two, const real& one);
};

// supported operations with:
// real
// long double
// double
// float
// unsigned long
// long
// unsigned int
// int
// string

// real operator+(const real& one, const real& two)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_add(tmp, one.m_val, two.m_val, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator+(const real& one, const long double& two)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_ld(tmp, two, MPFR_RNDN);
//     mpfr_add(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator+(const long double& two, const real& one)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_ld(tmp, two, MPFR_RNDN);
//     mpfr_add(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator+(const real& one, const double& two)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_d(tmp, two, MPFR_RNDN);
//     mpfr_add(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator+(const double& two, const real& one)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_d(tmp, two, MPFR_RNDN);
//     mpfr_add(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator+(const real& one, const float& two)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_flt(tmp, two, MPFR_RNDN);
//     mpfr_add(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator+(const float& two, const real& one)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_flt(tmp, two, MPFR_RNDN);
//     mpfr_add(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator+(const real& one, const unsigned long& two)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_ui(tmp, two, MPFR_RNDN);
//     mpfr_add(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator+(const unsigned long& two, const real& one)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_ui(tmp, two, MPFR_RNDN);
//     mpfr_add(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator+(const real& one, const long& two)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_si(tmp, two, MPFR_RNDN);
//     mpfr_add(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator+(const long& two, const real& one)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_si(tmp, two, MPFR_RNDN);
//     mpfr_add(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator+(const real& one, const unsigned int& two)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_ui(tmp, (unsigned long)two, MPFR_RNDN);
//     mpfr_add(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator+(const unsigned int& two, const real& one)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_ui(tmp, (unsigned long)two, MPFR_RNDN);
//     mpfr_add(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator+(const real& one, const int& two)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_si(tmp, (long)two, MPFR_RNDN);
//     mpfr_add(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator+(const int& two, const real& one)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_si(tmp, (long)two, MPFR_RNDN);
//     mpfr_add(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator+(const real& one, const std::string& two)
// {
//     mpfr_t tmp;
//     mpfr_from_str(two, tmp);
//     mpfr_add(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator+(const std::string& two, const real& one)
// {
//     mpfr_t tmp;
//     mpfr_from_str(two, tmp);
//     mpfr_add(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// ///////
//
// real operator-(const real& one, const real& two)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_sub(tmp, one.m_val, two.m_val, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator-(const real& one, const long double& two)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_ld(tmp, two, MPFR_RNDN);
//     mpfr_sub(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator-(const long double& two, const real& one)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_ld(tmp, two, MPFR_RNDN);
//     mpfr_sub(tmp, tmp, one.m_val, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator-(const real& one, const double& two)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_d(tmp, two, MPFR_RNDN);
//     mpfr_sub(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator-(const double& two, const real& one)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_d(tmp, two, MPFR_RNDN);
//     mpfr_sub(tmp, tmp, one.m_val, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator-(const real& one, const float& two)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_flt(tmp, two, MPFR_RNDN);
//     mpfr_sub(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator-(const float& two, const real& one)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_flt(tmp, two, MPFR_RNDN);
//     mpfr_sub(tmp, tmp, one.m_val, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator-(const real& one, const unsigned long& two)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_ui(tmp, two, MPFR_RNDN);
//     mpfr_sub(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator-(const unsigned long& two, const real& one)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_ui(tmp, two, MPFR_RNDN);
//     mpfr_sub(tmp, tmp, one.m_val, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator-(const real& one, const long& two)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_si(tmp, two, MPFR_RNDN);
//     mpfr_sub(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator-(const long& two, const real& one)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_si(tmp, two, MPFR_RNDN);
//     mpfr_sub(tmp, tmp, one.m_val, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator-(const real& one, const unsigned int& two)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_ui(tmp, (unsigned long)two, MPFR_RNDN);
//     mpfr_sub(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator-(const unsigned int& two, const real& one)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_ui(tmp, (unsigned long)two, MPFR_RNDN);
//     mpfr_sub(tmp, tmp, one.m_val, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator-(const real& one, const int& two)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_si(tmp, (long)two, MPFR_RNDN);
//     mpfr_sub(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator-(const int& two, const real& one)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_si(tmp, (long)two, MPFR_RNDN);
//     mpfr_sub(tmp, tmp, one.m_val, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator-(const real& one, const std::string& two)
// {
//     mpfr_t tmp;
//     mpfr_from_str(two, tmp);
//     mpfr_sub(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator-(const std::string& two, const real& one)
// {
//     mpfr_t tmp;
//     mpfr_from_str(two, tmp);
//     mpfr_sub(tmp, tmp, one.m_val, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// ///////
//
// real operator*(const real& one, const real& two)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_mul(tmp, one.m_val, two.m_val, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator*(const real& one, const long double& two)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_ld(tmp, two, MPFR_RNDN);
//     mpfr_mul(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator*(const long double& two, const real& one)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_ld(tmp, two, MPFR_RNDN);
//     mpfr_mul(tmp, tmp, one.m_val, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator*(const real& one, const double& two)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_d(tmp, two, MPFR_RNDN);
//     mpfr_mul(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator*(const double& two, const real& one)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_d(tmp, two, MPFR_RNDN);
//     mpfr_mul(tmp, tmp, one.m_val, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator*(const real& one, const float& two)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_flt(tmp, two, MPFR_RNDN);
//     mpfr_mul(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator*(const float& two, const real& one)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_flt(tmp, two, MPFR_RNDN);
//     mpfr_mul(tmp, tmp, one.m_val, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator*(const real& one, const unsigned long& two)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_ui(tmp, two, MPFR_RNDN);
//     mpfr_mul(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator*(const unsigned long& two, const real& one)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_ui(tmp, two, MPFR_RNDN);
//     mpfr_mul(tmp, tmp, one.m_val, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator*(const real& one, const long& two)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_si(tmp, two, MPFR_RNDN);
//     mpfr_mul(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator*(const long& two, const real& one)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_si(tmp, two, MPFR_RNDN);
//     mpfr_mul(tmp, tmp, one.m_val, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator*(const real& one, const unsigned int& two)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_ui(tmp, (unsigned long)two, MPFR_RNDN);
//     mpfr_mul(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator*(const unsigned int& two, const real& one)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_ui(tmp, (unsigned long)two, MPFR_RNDN);
//     mpfr_mul(tmp, tmp, one.m_val, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator*(const real& one, const int& two)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_si(tmp, (long)two, MPFR_RNDN);
//     mpfr_mul(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator*(const int& two, const real& one)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_si(tmp, (long)two, MPFR_RNDN);
//     mpfr_mul(tmp, tmp, one.m_val, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator*(const real& one, const std::string& two)
// {
//     mpfr_t tmp;
//     mpfr_from_str(two, tmp);
//     mpfr_mul(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator*(const std::string& two, const real& one)
// {
//     mpfr_t tmp;
//     mpfr_from_str(two, tmp);
//     mpfr_mul(tmp, tmp, one.m_val, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// ///////
//
// real operator/(const real& one, const real& two)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_div(tmp, one.m_val, two.m_val, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator/(const real& one, const long double& two)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_ld(tmp, two, MPFR_RNDN);
//     mpfr_div(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator/(const long double& two, const real& one)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_ld(tmp, two, MPFR_RNDN);
//     mpfr_div(tmp, tmp, one.m_val, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator/(const real& one, const double& two)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_d(tmp, two, MPFR_RNDN);
//     mpfr_div(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator/(const double& two, const real& one)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_d(tmp, two, MPFR_RNDN);
//     mpfr_div(tmp, tmp, one.m_val, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator/(const real& one, const float& two)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_flt(tmp, two, MPFR_RNDN);
//     mpfr_div(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator/(const float& two, const real& one)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_flt(tmp, two, MPFR_RNDN);
//     mpfr_div(tmp, tmp, one.m_val, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator/(const real& one, const unsigned long& two)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_ui(tmp, two, MPFR_RNDN);
//     mpfr_div(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator/(const unsigned long& two, const real& one)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_ui(tmp, two, MPFR_RNDN);
//     mpfr_div(tmp, tmp, one.m_val, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator/(const real& one, const long& two)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_si(tmp, two, MPFR_RNDN);
//     mpfr_div(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator/(const long& two, const real& one)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_si(tmp, two, MPFR_RNDN);
//     mpfr_div(tmp, tmp, one.m_val, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator/(const real& one, const unsigned int& two)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_ui(tmp, (unsigned long)two, MPFR_RNDN);
//     mpfr_div(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator/(const unsigned int& two, const real& one)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_ui(tmp, (unsigned long)two, MPFR_RNDN);
//     mpfr_div(tmp, tmp, one.m_val, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator/(const real& one, const int& two)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_si(tmp, (long)two, MPFR_RNDN);
//     mpfr_div(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator/(const int& two, const real& one)
// {
//     mpfr_t tmp;
//     mpfr_init2(tmp, REAL_PRECISION);
//     mpfr_set_si(tmp, (long)two, MPFR_RNDN);
//     mpfr_div(tmp, tmp, one.m_val, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator/(const real& one, const std::string& two)
// {
//     mpfr_t tmp;
//     mpfr_from_str(two, tmp);
//     mpfr_div(tmp, one.m_val, tmp, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }
//
// real operator/(const std::string& two, const real& one)
// {
//     mpfr_t tmp;
//     mpfr_from_str(two, tmp);
//     mpfr_div(tmp, tmp, one.m_val, MPFR_RNDN);
//
//     real val;
//     mpfr_set(val.m_val, tmp, MPFR_RNDN);
//
//     mpfr_clear(tmp);
//
//     return val;
// }

}
