/*
 * XPathWrapper.h
 *
 *  Created on: June 7, 2012
 *      Author: wdxu
 */

#ifndef XPATHWRAPPER_H
#define XPATHWRAPPER_H

#include <QXmlQuery>

namespace Tn
{

//! Wrapper for QXmlQuery.

class XPathWrapper
{
public:
    //! Constructor.
    XPathWrapper(const std::string &xmlFile);

    //! Destructor.
    ~XPathWrapper();

    //! Check validity of XML.
    /*!
     * \return True if XML is valid.
     */
    bool isValid();

    //! Evaluate absolute path expression.
    /*!
     * \param path path expression.
     * \return Atomic value of an attribute, or concatenation of text of an element.
     */
    std::string evaluatePath(const std::string &path);

    //! Set relative path.  Use with evaluateRelativePath.
    /*!
     * \param pathPrefix prefix of relative path.
     * \return Previous prefix of relative path.
     */
    std::string setRelativePathPrefix(const std::string &pathPrefix);

    //! Evaluate relative path expression.
    /*!
     * \param path path expression relative to pathPrefix set by setRelativePathPrefix.
     * \return Atomic value of an attribute, or concatenation of text of an element.
     */
    std::string evaluateRelativePath(const std::string &path);

private:
    bool mValid;                //! Validity of XML.
    QXmlQuery mQuery;           //! QXmlQuery instance.
    std::string mPathPrefix;    //! Prefix of relative path.
};

}

#endif // XPATHWRAPPER_H
