#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource()
{}
IMateriaSource::IMateriaSource(const IMateriaSource &msource)
{
    (void) msource;
}
IMateriaSource &IMateriaSource::operator=(const IMateriaSource &msource)
{
    (void) msource;
    return *this;
}
IMateriaSource::~IMateriaSource()
{}
