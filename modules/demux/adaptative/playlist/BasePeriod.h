/*
 * Period.h
 *****************************************************************************
 * Copyright (C) 2010 - 2011 Klagenfurt University
 *
 * Created on: Aug 10, 2010
 * Authors: Christopher Mueller <christopher.mueller@itec.uni-klu.ac.at>
 *          Christian Timmerer  <christian.timmerer@itec.uni-klu.ac.at>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/
#ifndef BASEPERIOD_H_
#define BASEPERIOD_H_

#include <vector>
#include <string>

#include "BaseAdaptationSet.h"
#include "SegmentInformation.hpp"
#include "../tools/Properties.hpp"
#include "../StreamsType.hpp"

namespace adaptative
{
    namespace playlist
    {
        class BasePeriod : public SegmentInformation
        {
            public:
                BasePeriod(AbstractPlaylist *);
                virtual ~BasePeriod ();

                const std::vector<BaseAdaptationSet *>& getAdaptationSets   () const;
                const std::vector<BaseAdaptationSet *>  getAdaptationSets   (StreamType) const;
                BaseAdaptationSet *                 getAdaptationSet    (StreamType) const;
                void                                addAdaptationSet    (BaseAdaptationSet *AdaptationSet);
                std::vector<std::string>            toString            (int = 0) const;

                virtual mtime_t getPeriodStart() const; /* reimpl */

                Property<mtime_t> duration;
                Property<mtime_t> startTime;

            private:
                std::vector<BaseAdaptationSet *>    adaptationSets;
        };
    }
}

#endif /* BASEPERIOD_H_ */