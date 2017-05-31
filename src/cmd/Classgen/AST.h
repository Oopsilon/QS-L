/* Oopsilon
 * Classgen: Oops class generator.
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

#include <list>
#include <string>

struct Field
{
    std::string * type;
    std::string * name;

    std::string generate () const;
};

struct Class
{
    std::string * name;
    std::string * superName;
    std::list<Field> * fields;

    std::string generate_field_info ();

    void generate ();
};