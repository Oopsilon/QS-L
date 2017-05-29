/* Oopsilon
 * Object Memory: Object factory.
 *
 *      Copyright Notice
 *
 * Copyright (c) 2017 D. Mackay. All rights reserved.
 *
 * This file and its contents are supplied under the terms of the Peer
 * Production Licence as found in the Oopsilon project's source repository,
 * and David Mackay is the sole copyright holder.
 *
 *      End Copyright Notice
 */

#pragma once

#include "Oops/Hierarchy.h"

struct ObjectFactory
{
    symbolOop newSymbol (std::string text);
    template <class T> typename objVecOop<T>::type newObjVec ();
    template <class T>
    typename objVecOop<T>::type newObjVec (std::vector<T> contents);
    objVecOop<symbolOop>::type
    newSymVec (const std::vector<std::string> contents);
};