/****************************************************************************
**
** http://www.qxorm.com/
** http://sourceforge.net/projects/qxorm/
** Original file by Lionel Marty
**
** This file is part of the QxOrm library
**
** This software is provided 'as-is', without any express or implied
** warranty. In no event will the authors be held liable for any
** damages arising from the use of this software.
**
** GNU Lesser General Public License Usage
** This file must be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file 'license.lgpl.txt' included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** If you have questions regarding the use of this file, please contact :
** contact@qxorm.com
**
****************************************************************************/

#ifndef _QX_QT_META_OBJECT_H_
#define _QX_QT_META_OBJECT_H_

#ifdef _MSC_VER
#pragma once
#endif

/*!
 * \file qt_meta_object.h
 * \author Lionel Marty
 * \ingroup QxTraits
 * \brief qx::trait::qt_meta_object<T>::get() : if T is based on QObject class, then return QMetaObject instance of Qt introspection engine, else return NULL
 */

#include <boost/type_traits/is_base_of.hpp>

#include <QtCore/qmetaobject.h>
#include <QtCore/qmetatype.h>

namespace qx {
namespace trait {

/*!
 * \ingroup QxTraits
 * \brief qx::trait::qt_meta_object<T>::get() : if T is based on QObject class, then return QMetaObject instance of Qt introspection engine, else return NULL
 */
template <typename T>
class qt_meta_object
{

public:

   enum { is_valid = (boost::is_base_of<QObject, T>::value) };

   static const QMetaObject * get()
   { return qtMetaObject<qt_meta_object<T>::is_valid, 0>::get(); }

private:

   template <bool isQObject /* = false */, int dummy>
   struct qtMetaObject
   { static inline const QMetaObject * get() { return NULL; } };

   template <int dummy>
   struct qtMetaObject<true, dummy>
   { static inline const QMetaObject * get() { return (& T::staticMetaObject); } };

};

} // namespace trait
} // namespace qx

#endif // _QX_QT_META_OBJECT_H_
