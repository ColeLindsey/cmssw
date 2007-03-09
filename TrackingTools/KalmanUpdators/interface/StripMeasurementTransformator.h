#ifndef CD_StripMeasurementTransformator_H_
#define CD_StripMeasurementTransformator_H_

#include "DataFormats/CLHEP/interface/AlgebraicObjects.h"
#include "TrackingTools/TransientTrackingRecHit/interface/TransientTrackingRecHit.h"
#include "Geometry/CommonTopologies/interface/StripTopology.h"
#include "TrackingTools/TrajectoryState/interface/TrajectoryStateOnSurface.h"

/** Helper class for accessing the RecHit and the TrajectoryState parameters
 *  and errors in the measurement frame.
 */


class StripMeasurementTransformator {

private:

  typedef TrajectoryStateOnSurface TSOS;
  typedef AlgebraicSymMatrix ASM;
  typedef AlgebraicMatrix AM;
  typedef AlgebraicVector AV;

public:

  StripMeasurementTransformator(const TSOS& aTsos, const TransientTrackingRecHit& aHit);
  
  ~StripMeasurementTransformator() {}

  AV hitParameters() const;
  AV trajectoryParameters() const;
  AV projectedTrajectoryParameters() const;
  ASM hitError() const;
  ASM trajectoryError() const;
  ASM projectedTrajectoryError() const;
  AM projectionMatrix() const;

  const TransientTrackingRecHit& hit() const {return theRecHit;}
  const TSOS& state() const {return theState;}
  const StripTopology* topology() const {return theTopology;}

private:

  const TransientTrackingRecHit& theRecHit;
  TSOS theState;
  const StripTopology* theTopology;

  void init();
};

#endif //CD_StripMeasurementTransformator_H_
