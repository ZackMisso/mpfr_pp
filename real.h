// The below code is authored by Zackary Misso
// It is free to use as long as credit is given for its use

#include <mpfr.h>
#include <string>

#define REAL_PRECISION 512

struct real
{
protected:
    mpfr_t m_val;

    void mpfr_from_str(std::string str, mpfr_t& result)
    {
        mpfr_init2(result, REAL_PRECISION);
        mpfr_set_str(result, str.c_str(), 10, MPFR_RNDN);
    }

public:

    real()
    {
        mpfr_init2(m_val, REAL_PRECISION);
    }

    ~real()
    {
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
        mpfr_init2(val.m_val, REAL_PRECISION);
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
        mpfr_init2(val.m_val, REAL_PRECISION);
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
        mpfr_init2(val.m_val, REAL_PRECISION);
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
        mpfr_init2(val.m_val, REAL_PRECISION);
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
        mpfr_init2(val.m_val, REAL_PRECISION);
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
        mpfr_init2(val.m_val, REAL_PRECISION);
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
        mpfr_init2(val.m_val, REAL_PRECISION);
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
        mpfr_init2(val.m_val, REAL_PRECISION);
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }

    real operator-(const real& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_sub(tmp, m_val, other.m_val, MPFR_RNDN);

        real val;
        mpfr_init2(val.m_val, REAL_PRECISION);
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
        mpfr_init2(val.m_val, REAL_PRECISION);
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
        mpfr_init2(val.m_val, REAL_PRECISION);
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
        mpfr_init2(val.m_val, REAL_PRECISION);
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
        mpfr_init2(val.m_val, REAL_PRECISION);
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
        mpfr_init2(val.m_val, REAL_PRECISION);
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
        mpfr_init2(val.m_val, REAL_PRECISION);
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
        mpfr_init2(val.m_val, REAL_PRECISION);
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }

    real operator*(const real& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_mul(tmp, m_val, other.m_val, MPFR_RNDN);

        real val;
        mpfr_init2(val.m_val, REAL_PRECISION);
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
        mpfr_init2(val.m_val, REAL_PRECISION);
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
        mpfr_init2(val.m_val, REAL_PRECISION);
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
        mpfr_init2(val.m_val, REAL_PRECISION);
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
        mpfr_init2(val.m_val, REAL_PRECISION);
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
        mpfr_init2(val.m_val, REAL_PRECISION);
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
        mpfr_init2(val.m_val, REAL_PRECISION);
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
        mpfr_init2(val.m_val, REAL_PRECISION);
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
    }

    real operator/(const real& other) {
        mpfr_t tmp;
        mpfr_init2(tmp, REAL_PRECISION);
        mpfr_div(tmp, m_val, other.m_val, MPFR_RNDN);

        real val;
        mpfr_init2(val.m_val, REAL_PRECISION);
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
        mpfr_init2(val.m_val, REAL_PRECISION);
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
        mpfr_init2(val.m_val, REAL_PRECISION);
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
        mpfr_init2(val.m_val, REAL_PRECISION);
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
        mpfr_init2(val.m_val, REAL_PRECISION);
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
        mpfr_init2(val.m_val, REAL_PRECISION);
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
        mpfr_init2(val.m_val, REAL_PRECISION);
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
        mpfr_init2(val.m_val, REAL_PRECISION);
        mpfr_set(val.m_val, tmp, MPFR_RNDN);

        mpfr_clear(tmp);

        return val;
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
