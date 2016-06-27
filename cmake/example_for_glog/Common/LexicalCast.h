#ifndef __LEXICAL_CAST_H__
#define __LEXICAL_CAST_H__

#include "Logger.h"
#ifndef Q_MOC_RUN
#include "boost/lexical_cast.hpp"
#endif
#include <cassert>

namespace Tn
{
    template<typename Target, typename Source>
    Target lexical_cast(const Source &arg)
    {
        try
        {
            Target target = boost::lexical_cast<Target>(arg);
            return target;
        }
        catch (boost::bad_lexical_cast)
        {
            LOG(ERROR) << "Bad lexical cast.";
            return Target();
        }
        catch (...)
        {
            assert(false);
            return Target();
        }
    }
}

#endif // __LEXICAL_CAST_H__
