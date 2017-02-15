/**

Copyright (c) 2016, Hanselmann Fabian, Heller Florian, Heizmann Heinrich, Kübler Marcel, Mehlhaus Jonas, Meißner Pascal, Qattan Mohamad, Reckling Reno, Stroh Daniel
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#pragma once

#include <boost/shared_ptr.hpp>
#include <Eigen/Geometry>
#include "common_type/Tracks.hpp"
#include "common_type/Object.hpp"
#include "Heuristic.hpp"

namespace ISM {

  /**
   * DirectionOrientationRelationHeuristic class. Extention of DirectionRelationHeuristic. Adds a constraint on orientations in object estimation pairs to it. DirectionRelationHeuristic just compares vectors between positions in those estimations. Needed for the example scene where objects rotate around a central object. In it, not the direction vector but just the orientations of the rotating objects towards the central object change.
   */
    class DirectionOrientationRelationHeuristic: public Heuristic {
        public:
            DirectionOrientationRelationHeuristic(const double pStaticBreakRatio, const double pTogetherRatio, const double pMaxAngleDeviation);

	    virtual void applyHeuristic(const TracksPtr& tracks);

        private:
      
            double mStaticBreakRatio, mTogetherRatio, mMaxAngleDeviation;
    };
}
