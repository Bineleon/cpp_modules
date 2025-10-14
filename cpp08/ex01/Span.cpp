#include "Span.hpp"

Span::Span(void)
{
    // std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int N): _N(N)
{
    // std::cout << "Span default constructor called" << std::endl;
}

Span::Span(const Span& src)
{
    // std::cout << "Span copy constructor called" << std::endl;
    *this = src;
}

Span& Span::operator=(const Span& rhs)
{
    // std::cout << "Span copy assignment operator called" << std::endl;
    _v = rhs._v;
	_N = rhs._N;
    return *this;
}

Span::~Span(void)
{
    // std::cout << "Span destructor called" << std::endl;
}

void Span::addNumber(int nb)
{
    if (nb > INT_MAX || nb < INT_MIN)
        throw IntLimitsException();
	if (_v.size() < _N )
		_v.push_back(nb);
	else
		throw ContainerIsFullException();
}

long long Span::shortestSpan() const
{
    if (_v.size() < 2)
        throw TooFewElementsException();

    long long span;
    long long minSpan = INT_MAX;
    std::vector<int> sortedV = _v;
    std::sort(sortedV.begin(), sortedV.end());
    for (unsigned long i = 0; i < sortedV.size() - 1; ++i)
    {
        span = sortedV[i + 1] - sortedV[i];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

long long Span::longestSpan() const
{
    if (_v.size() < 2)
        throw TooFewElementsException();

    std::vector<int> sortedV = _v;
    std::sort(sortedV.begin(), sortedV.end());
    long long maxSpan = sortedV.back() - sortedV.front();

    return maxSpan;
}

int Span::size() const
{
    return _v.size();
}

std::vector<int> Span::getV() const
{
    return _v;
}
