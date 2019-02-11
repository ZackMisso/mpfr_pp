// The below code is authored by Zackary Misso
// It is free to use as long as credit is given for its use

#include <mpfr.h>
#include <stdio.h>
#include <string>

namespace mpfr_pp
{

#define REAL_PRECISION 512

struct real
{
protected:
    mpfr_t m_val;

    void mpfr_from_str(const std::string str, mpfr_t& result) const
    {
        mpfr_init2(result, REAL_PRECISION);
        mpfr_set_str(result, str.c_str(), /*base*/10, MPFR_RNDN);
    }

    void mpfr_from_str(const char* str, mpfr_t& result) const
    {
        mpfr_init2(result, REAL_PRECISION);
        mpfr_set_str(result, str, /*base*/10, MPFR_RNDN);
    }

    void text(std::string message, const mpfr_t& val) const
    {
        std::cout << message << std::endl;
        mpfr_out_str (stdout, 10, 0, val, MPFR_RNDD);
        std::cout << std::endl;
    }

public:

    void text(std::string message)
    {
        text(message, m_val);
    }

    real() {
        mpfr_init2(m_val, REAL_PRECISION);
    }

    real(const real& val) {
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

    ~real() {
        mpfr_clear(m_val);
    }

    // operators
    void operator++() {
        mpfr_t one;
        mpfr_from_str("1.0", one);
        mpfr_add(m_val, m_val, one, MPFR_RNDN);
        mpfr_clear(one);
    }

    void operator--() {
        mpfr_t one;
        mpfr_from_str("1.0", one);
        mpfr_sub(m_val, m_val, one, MPFR_RNDN);
        mpfr_clear(one);
    }

    real operator+(const real& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_add(tmp, other.m_val, m_val, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator+(const long double& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ld(tmp, other, MPFR_RNDN);
        mpfr_add(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator+(const double& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_d(tmp, other, MPFR_RNDN);
        mpfr_add(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator+(const float& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_flt(tmp, other, MPFR_RNDN);
        mpfr_add(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator+(const unsigned long& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, other, MPFR_RNDN);
        mpfr_add(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator+(const long& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_si(tmp, other, MPFR_RNDN);
        mpfr_add(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator+(const unsigned int& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, (unsigned long)other, MPFR_RNDN);
        mpfr_add(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator+(const int& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, (long)other, MPFR_RNDN);
        mpfr_add(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator+(const std::string& other) {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        mpfr_add(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator+(const char* other) {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        mpfr_add(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }

    real operator-(const real& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_sub(tmp, m_val, other.m_val, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator-(const long double& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ld(tmp, other, MPFR_RNDN);
        mpfr_sub(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator-(const double& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_d(tmp, other, MPFR_RNDN);
        mpfr_sub(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator-(const float& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_flt(tmp, other, MPFR_RNDN);
        mpfr_sub(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator-(const unsigned long& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, other, MPFR_RNDN);
        mpfr_sub(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator-(const long& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_si(tmp, other, MPFR_RNDN);
        mpfr_sub(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator-(const unsigned int& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, (unsigned long)other, MPFR_RNDN);
        mpfr_sub(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator-(const int& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, (long)other, MPFR_RNDN);
        mpfr_sub(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator-(const std::string& other) {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        mpfr_sub(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator-(const char* other) {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        mpfr_sub(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }

    real operator*(const real& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_mul(tmp, m_val, other.m_val, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator*(const long double& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ld(tmp, other, MPFR_RNDN);
        mpfr_mul(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator*(const double& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_d(tmp, other, MPFR_RNDN);
        mpfr_mul(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator*(const float& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_flt(tmp, other, MPFR_RNDN);
        mpfr_mul(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator*(const unsigned long& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, other, MPFR_RNDN);
        mpfr_mul(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator*(const long& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_si(tmp, other, MPFR_RNDN);
        mpfr_mul(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator*(const unsigned int& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, (unsigned long)other, MPFR_RNDN);
        mpfr_mul(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator*(const int& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, (long)other, MPFR_RNDN);
        mpfr_mul(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator*(const std::string& other) {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        mpfr_mul(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator*(const char* other) {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        mpfr_mul(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }

    real operator/(const real& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_div(tmp, m_val, other.m_val, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator/(const long double& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ld(tmp, other, MPFR_RNDN);
        mpfr_div(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator/(const double& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_d(tmp, other, MPFR_RNDN);
        mpfr_div(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator/(const float& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_flt(tmp, other, MPFR_RNDN);
        mpfr_div(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator/(const unsigned long& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, other, MPFR_RNDN);
        mpfr_div(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator/(const long& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_si(tmp, other, MPFR_RNDN);
        mpfr_div(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator/(const unsigned int& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, (unsigned long)other, MPFR_RNDN);
        mpfr_div(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator/(const int& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, (long)other, MPFR_RNDN);
        mpfr_div(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator/(const std::string& other) {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        mpfr_div(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }
    real operator/(const char* other) {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        mpfr_div(tmp, m_val, tmp, MPFR_RNDN);

        real val;
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }

    real& operator=(const real& other) {
        mpfr_set(m_val, other.m_val, MPFR_RNDN);
        return *this;
    }
    real& operator=(const long double& other) {
        mpfr_set_ld(m_val, other, MPFR_RNDN);
        return *this;
    }
    real& operator=(const double& other) {
        mpfr_set_d(m_val, other, MPFR_RNDN);
        return *this;
    }
    real& operator=(const float& other) {
        mpfr_set_flt(m_val, other, MPFR_RNDN);
        return *this;
    }
    real& operator=(const unsigned long& other) {
        mpfr_set_ui(m_val, other, MPFR_RNDN);
        return *this;
    }
    real& operator=(const long& other) {
        mpfr_set_si(m_val, other, MPFR_RNDN);
        return *this;
    }
    real& operator=(const unsigned int& other) {
        mpfr_set_ui(m_val, other, MPFR_RNDN);
        return *this;
    }
    real& operator=(const int& other) {
        mpfr_set_ui(m_val, other, MPFR_RNDN);
        return *this;
    }
    real& operator=(const std::string& other) {
        mpfr_set_str(m_val, other.c_str(), /*base*/10, MPFR_RNDN);
        return *this;
    }
    real& operator=(const char* other) {
        mpfr_set_str(m_val, other, /*base*/10, MPFR_RNDN);
        return *this;
    }

    void operator+=(const real& other) {
        mpfr_add(m_val, m_val, other.m_val, MPFR_RNDN);
    }
    void operator+=(const long double& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ld(tmp, other, MPFR_RNDN);
        mpfr_add(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator+=(const double& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_d(tmp, other, MPFR_RNDN);
        mpfr_add(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator+=(const float& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_flt(tmp, other, MPFR_RNDN);
        mpfr_add(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator+=(const unsigned long& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, other, MPFR_RNDN);
        mpfr_add(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator+=(const long& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_si(tmp, other, MPFR_RNDN);
        mpfr_add(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator+=(const unsigned int& other) {
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
    void operator+=(const std::string& other) {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        mpfr_add(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator+=(const char* other) {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        mpfr_add(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }

    void operator-=(const real& other) {
        mpfr_sub(m_val, m_val, other.m_val, MPFR_RNDN);
    }
    void operator-=(const long double& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ld(tmp, other, MPFR_RNDN);
        mpfr_sub(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator-=(const double& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_d(tmp, other, MPFR_RNDN);
        mpfr_sub(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator-=(const float& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_flt(tmp, other, MPFR_RNDN);
        mpfr_sub(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator-=(const unsigned long& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, other, MPFR_RNDN);
        mpfr_sub(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator-=(const long& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_si(tmp, other, MPFR_RNDN);
        mpfr_sub(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator-=(const unsigned int& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, other, MPFR_RNDN);
        mpfr_sub(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator-=(const int& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, other, MPFR_RNDN);
        mpfr_sub(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator-=(const std::string& other) {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        mpfr_sub(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator-=(const char* other) {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        mpfr_sub(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }

    void operator*=(const real& other) {
        mpfr_mul(m_val, m_val, other.m_val, MPFR_RNDN);
    }
    void operator*=(const long double& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ld(tmp, other, MPFR_RNDN);
        mpfr_mul(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator*=(const double& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_d(tmp, other, MPFR_RNDN);
        mpfr_mul(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator*=(const float& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_flt(tmp, other, MPFR_RNDN);
        mpfr_mul(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator*=(const unsigned long& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, other, MPFR_RNDN);
        mpfr_mul(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator*=(const long& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_si(tmp, other, MPFR_RNDN);
        mpfr_mul(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator*=(const unsigned int& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, other, MPFR_RNDN);
        mpfr_mul(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator*=(const int& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, other, MPFR_RNDN);
        mpfr_mul(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator*=(const std::string& other) {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        mpfr_mul(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator*=(const char* other) {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        mpfr_mul(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }

    void operator/=(const real& other) {
        mpfr_div(m_val, m_val, other.m_val, MPFR_RNDN);
    }
    void operator/=(const long double& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ld(tmp, other, MPFR_RNDN);
        mpfr_div(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator/=(const double& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_d(tmp, other, MPFR_RNDN);
        mpfr_div(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator/=(const float& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_flt(tmp, other, MPFR_RNDN);
        mpfr_div(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator/=(const unsigned long& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, other, MPFR_RNDN);
        mpfr_div(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator/=(const long& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_si(tmp, other, MPFR_RNDN);
        mpfr_div(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator/=(const unsigned int& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, other, MPFR_RNDN);
        mpfr_div(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator/=(const int& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_set_ui(tmp, other, MPFR_RNDN);
        mpfr_div(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator/=(const std::string& other) {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        mpfr_div(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }
    void operator/=(const char* other) {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        mpfr_div(m_val, m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);
    }

    bool operator==(const real& other) {
        int compare = mpfr_cmp(m_val, other.m_val);
        return compare == 0;
    }
    bool operator==(const long double& other) {
        int compare = mpfr_cmp_ld(m_val, other);
        return compare == 0;
    }
    bool operator==(const double& other) {
        int compare = mpfr_cmp_d(m_val, other);
        return compare == 0;
    }
    bool operator==(const float& other) {
        int compare = mpfr_cmp_d(m_val, (double)other);
        return compare == 0;
    }
    bool operator==(const unsigned long& other) {
        int compare = mpfr_cmp_ui(m_val, other);
        return compare == 0;
    }
    bool operator==(const long& other) {
        int compare = mpfr_cmp_si(m_val, other);
        return compare == 0;
    }
    bool operator==(const unsigned int& other) {
        int compare = mpfr_cmp_ui(m_val, other);
        return compare == 0;
    }
    bool operator==(const int& other) {
        int compare = mpfr_cmp_si(m_val, other);
        return compare == 0;
    }
    bool operator==(const std::string& other) {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        int compare = mpfr_cmp(m_val, tmp);
        mpfr_clear(tmp);
        return compare == 0;
    }
    bool operator==(const char* other) {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        int compare = mpfr_cmp(m_val, tmp);
        mpfr_clear(tmp);
        return compare == 0;
    }

    bool operator!=(const real& other) {
        int compare = mpfr_cmp(m_val, other.m_val);
        return compare != 0;
    }
    bool operator!=(const long double& other) {
        int compare = mpfr_cmp_ld(m_val, other);
        return compare != 0;
    }
    bool operator!=(const double& other) {
        int compare = mpfr_cmp_d(m_val, other);
        return compare != 0;
    }
    bool operator!=(const float& other) {
        int compare = mpfr_cmp_d(m_val, (double)other);
        return compare != 0;
    }
    bool operator!=(const unsigned long& other) {
        int compare = mpfr_cmp_ui(m_val, other);
        return compare != 0;
    }
    bool operator!=(const long& other) {
        int compare = mpfr_cmp_si(m_val, other);
        return compare != 0;
    }
    bool operator!=(const unsigned int& other) {
        int compare = mpfr_cmp_ui(m_val, other);
        return compare != 0;
    }
    bool operator!=(const int& other) {
        int compare = mpfr_cmp_si(m_val, other);
        return compare != 0;
    }
    bool operator!=(const std::string& other) {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        int compare = mpfr_cmp(m_val, tmp);
        mpfr_clear(tmp);
        return compare != 0;
    }
    bool operator!=(const char* other) {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        int compare = mpfr_cmp(m_val, tmp);
        mpfr_clear(tmp);
        return compare != 0;
    }

    bool operator<(const real& other) {
        int compare = mpfr_cmp(m_val, other.m_val);
        return compare < 0;
    }
    bool operator<(const long double& other) {
        int compare = mpfr_cmp_ld(m_val, other);
        return compare < 0;
    }
    bool operator<(const double& other) {
        int compare = mpfr_cmp_d(m_val, other);
        return compare < 0;
    }
    bool operator<(const float& other) {
        int compare = mpfr_cmp_d(m_val, (double)other);
        return compare < 0;
    }
    bool operator<(const unsigned long& other) {
        int compare = mpfr_cmp_ui(m_val, other);
        return compare < 0;
    }
    bool operator<(const long& other) {
        int compare = mpfr_cmp_si(m_val, other);
        return compare < 0;
    }
    bool operator<(const unsigned int& other) {
        int compare = mpfr_cmp_ui(m_val, other);
        return compare < 0;
    }
    bool operator<(const int& other) {
        int compare = mpfr_cmp_si(m_val, other);
        return compare < 0;
    }
    bool operator<(const std::string& other) {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        int compare = mpfr_cmp(m_val, tmp);
        mpfr_clear(tmp);
        return compare < 0;
    }
    bool operator<(const char* other) {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        int compare = mpfr_cmp(m_val, tmp);
        mpfr_clear(tmp);
        return compare < 0;
    }

    bool operator<=(const real& other) {
        int compare = mpfr_cmp(m_val, other.m_val);
        return compare <= 0;
    }
    bool operator<=(const long double& other) {
        int compare = mpfr_cmp_ld(m_val, other);
        return compare <= 0;
    }
    bool operator<=(const double& other) {
        int compare = mpfr_cmp_d(m_val, other);
        return compare <= 0;
    }
    bool operator<=(const float& other) {
        int compare = mpfr_cmp_d(m_val, (double)other);
        return compare <= 0;
    }
    bool operator<=(const unsigned long& other) {
        int compare = mpfr_cmp_ui(m_val, other);
        return compare <= 0;
    }
    bool operator<=(const long& other) {
        int compare = mpfr_cmp_si(m_val, other);
        return compare <= 0;
    }
    bool operator<=(const unsigned int& other) {
        int compare = mpfr_cmp_ui(m_val, other);
        return compare <= 0;
    }
    bool operator<=(const int& other) {
        int compare = mpfr_cmp_si(m_val, other);
        return compare <= 0;
    }
    bool operator<=(const std::string& other) {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        int compare = mpfr_cmp(m_val, tmp);
        mpfr_clear(tmp);
        return compare <= 0;
    }
    bool operator<=(const char* other) {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        int compare = mpfr_cmp(m_val, tmp);
        mpfr_clear(tmp);
        return compare <= 0;
    }

    bool operator>(const real& other) {
        int compare = mpfr_cmp(m_val, other.m_val);
        return compare > 0;
    }
    bool operator>(const long double& other) {
        int compare = mpfr_cmp_ld(m_val, other);
        return compare > 0;
    }
    bool operator>(const double& other) {
        int compare = mpfr_cmp_d(m_val, other);
        return compare > 0;
    }
    bool operator>(const float& other) {
        int compare = mpfr_cmp_d(m_val, (double)other);
        return compare > 0;
    }
    bool operator>(const unsigned long& other) {
        int compare = mpfr_cmp_ui(m_val, other);
        return compare > 0;
    }
    bool operator>(const long& other) {
        int compare = mpfr_cmp_si(m_val, other);
        return compare > 0;
    }
    bool operator>(const unsigned int& other) {
        int compare = mpfr_cmp_ui(m_val, other);
        return compare > 0;
    }
    bool operator>(const int& other) {
        int compare = mpfr_cmp_si(m_val, other);
        return compare > 0;
    }
    bool operator>(const std::string& other) {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        int compare = mpfr_cmp(m_val, tmp);
        mpfr_clear(tmp);
        return compare > 0;
    }
    bool operator>(const char* other) {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        int compare = mpfr_cmp(m_val, tmp);
        mpfr_clear(tmp);
        return compare > 0;
    }

    bool operator>=(const real& other) {
        int compare = mpfr_cmp(m_val, other.m_val);
        return compare >= 0;
    }
    bool operator>=(const long double& other) {
        int compare = mpfr_cmp_ld(m_val, other);
        return compare >= 0;
    }
    bool operator>=(const double& other) {
        int compare = mpfr_cmp_d(m_val, other);
        return compare >= 0;
    }
    bool operator>=(const float& other) {
        int compare = mpfr_cmp_d(m_val, (double)other);
        return compare >= 0;
    }
    bool operator>=(const unsigned long& other) {
        int compare = mpfr_cmp_ui(m_val, other);
        return compare >= 0;
    }
    bool operator>=(const long& other) {
        int compare = mpfr_cmp_si(m_val, other);
        return compare >= 0;
    }
    bool operator>=(const unsigned int& other) {
        int compare = mpfr_cmp_ui(m_val, other);
        return compare >= 0;
    }
    bool operator>=(const int& other) {
        int compare = mpfr_cmp_si(m_val, other);
        return compare >= 0;
    }
    bool operator>=(const std::string& other) {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        int compare = mpfr_cmp(m_val, tmp);
        mpfr_clear(tmp);
        return compare >= 0;
    }
    bool operator>=(const char* other) {
        mpfr_t tmp;
        mpfr_from_str(other, tmp);
        int compare = mpfr_cmp(m_val, tmp);
        mpfr_clear(tmp);
        return compare >= 0;
    }

    operator long double() const {
        return mpfr_get_ld(m_val, MPFR_RNDN);
    }
    operator double() const {
        return mpfr_get_d(m_val, MPFR_RNDN);
    }
    operator float() const {
        return mpfr_get_flt(m_val, MPFR_RNDN);
    }
    operator unsigned long() const {
        return mpfr_get_ui(m_val, MPFR_RNDN);
    }
    operator long() const {
        return mpfr_get_si(m_val, MPFR_RNDN);
    }
    operator unsigned int() const {
        return (unsigned int)mpfr_get_ui(m_val, MPFR_RNDN);
    }
    operator int() const {
        return (int)mpfr_get_si(m_val, MPFR_RNDN);
    }
};

}
