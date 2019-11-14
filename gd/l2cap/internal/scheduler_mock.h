/*
 * Copyright 2019 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include "l2cap/internal/scheduler.h"

#include <gmock/gmock.h>

// Unit test interfaces
namespace bluetooth {
namespace l2cap {
namespace internal {
namespace testing {

class MockScheduler : public Scheduler {
 public:
  MOCK_METHOD(void, AttachChannel,
              (Cid cid, UpperQueueDownEnd* channel_down_end, Cid remote_cid,
               std::shared_ptr<classic::internal::DynamicChannelImpl> channel),
              (override));
  MOCK_METHOD(void, DetachChannel, (Cid cid), (override));
  MOCK_METHOD(void, NotifyPacketsReady, (Cid cid, int number_packet), (override));
};

}  // namespace testing
}  // namespace internal
}  // namespace l2cap
}  // namespace bluetooth
