/*
 * XPathWrapper.cpp
 *
 *  Created on: June 7, 2012
 *      Author: wdxu
 */

#include "XPathWrapper.h"

#include <QXmlResultItems>
#include <QDir>

namespace Tn
{

XPathWrapper::XPathWrapper(const std::string &xmlFile)
{
    mValid = mQuery.setFocus(QUrl(xmlFile.c_str()));
}

XPathWrapper::~XPathWrapper()
{

}

bool XPathWrapper::isValid()
{
    return mValid;
}

std::string XPathWrapper::evaluatePath(const std::string &path)
{
    std::string result;

    if (mValid)
    {
        mQuery.setQuery(path.c_str());
        if (mQuery.isValid())
        {
            QXmlResultItems items;
            mQuery.evaluateTo(&items);

            QXmlItem item = items.next();
            if (item.isAtomicValue())
            {
                result = item.toAtomicValue().toString().toStdString();
            }
            else if (item.isNode())
            {
                QXmlNodeModelIndex index = item.toNodeModelIndex();
                const QAbstractXmlNodeModel *model = index.model();
                if (model)
                    result = model->stringValue(index).toStdString();
                if (result.empty())
                    result = model->typedValue(index).toString().toStdString();
            }
        }
    }

    return result;
}

std::string XPathWrapper::setRelativePathPrefix(const std::string &pathPrefix)
{
    std::string prevPrefix = mPathPrefix;
    mPathPrefix = pathPrefix;
    return prevPrefix;
}

std::string XPathWrapper::evaluateRelativePath(const std::string &path)
{
    return this->evaluatePath(mPathPrefix + path);
}

}
