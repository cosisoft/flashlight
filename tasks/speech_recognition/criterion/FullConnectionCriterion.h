/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <flashlight/flashlight.h>
#include "CriterionUtils.h"
#include "Defines.h"

namespace fl {
namespace task {
namespace asr {

class FullConnectionCriterion : public fl::BinaryModule {
 public:
  explicit FullConnectionCriterion(
      int N,
      lib::CriterionScaleMode scalemode = fl::lib::CriterionScaleMode::NONE);

  fl::Variable forward(const fl::Variable& input, const fl::Variable& target)
      override;

  std::string prettyString() const override;

 private:
  friend class AutoSegmentationCriterion;
  FullConnectionCriterion() = default;

  int N_;
  lib::CriterionScaleMode scaleMode_;

  FL_SAVE_LOAD_WITH_BASE(
      fl::BinaryModule,
      fl::serializeAs<int64_t>(N_),
      scaleMode_)
};

typedef FullConnectionCriterion FCCLoss;
} // namespace asr
} // namespace task
} // namespace fl

CEREAL_REGISTER_TYPE(fl::task::asr::FullConnectionCriterion)